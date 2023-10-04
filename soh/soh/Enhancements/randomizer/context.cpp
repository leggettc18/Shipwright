#include "context.h"
#include "static_data.h"
#include "3drando/shops.hpp"
#include "3drando/dungeon.hpp"

#include <spdlog/spdlog.h>

namespace Rando {
std::weak_ptr<Context> Context::mContext;

std::shared_ptr<Context> Context::CreateInstance() {
    if (mContext.expired()) {
        auto instance = std::make_shared<Context>();
        mContext = instance;
        return instance;
    }
    return GetInstance();
}

std::shared_ptr<Context> Context::GetInstance() {
    return mContext.lock();
}

void Context::AddHint(RandomizerHintKey hintId, Text text) {
    hintTable[hintId] = RandoHint(text);
}

ItemLocation *Context::GetItemLocation(RandomizerCheck locKey) {
    return &(itemLocationTable[locKey]);
}

void Context::PlaceItemInLocation(RandomizerCheck locKey, RandomizerGet item, bool applyEffectImmediately,
                                  bool setHidden) {
    auto loc = GetItemLocation(locKey);
    SPDLOG_DEBUG("\n");
    SPDLOG_DEBUG(StaticData::RetrieveItem(item).GetName().GetEnglish());
    SPDLOG_DEBUG(" placed at ");
    SPDLOG_DEBUG(loc->GetName());
    SPDLOG_DEBUG("\n\n");

    if (applyEffectImmediately || Settings::Logic.Is(LOGIC_NONE) || Settings::Logic.Is(LOGIC_VANILLA)) {
        StaticData::RetrieveItem(item).ApplyEffect();
    }

    //TODO? Show Progress

    // If we're placing a non-shop item in a shop location, we want to record it for custom messages
    if (StaticData::RetrieveItem(item).GetItemType() != ITEMTYPE_SHOP &&
        StaticData::Location(locKey)->IsCategory(Category::cShop)) {
        int index = TransformShopIndex(GetShopIndex(locKey));
        NonShopItems[index].Name = StaticData::RetrieveItem(item).GetName();
        NonShopItems[index].Repurchaseable = StaticData::RetrieveItem(item).GetItemType() == ITEMTYPE_REFILL ||
                                             StaticData::RetrieveItem(item).GetHintKey() == RG_PROGRESSIVE_BOMBCHUS;
    }

    loc->SetPlacedItem(item);
    if (setHidden) {
        loc->SetHidden(true);
    }
}

void Context::AddLocation(RandomizerCheck loc, std::vector<RandomizerCheck>* destination) {
    destination->push_back(loc);
}

template<typename Container>
void Context::AddLocations(const Container& locations, std::vector<RandomizerCheck>* destination) {
    destination->insert(destination->end(), std::cbegin(locations), std::cend(locations));
}

void Context::GenerateLocationPool() {
    allLocations.clear();
    AddLocation(RC_LINKS_POCKET);
    AddLocations(overworldLocations);

    for (auto dungeon : Dungeon::dungeonList) {
        AddLocations(dungeon->GetDungeonLocations());
    }
}

std::vector<RandomizerCheck> Context::GetLocations(const std::vector<RandomizerCheck>& locationPool,
                                                   Category categoryInclude, Category categoryExclude) {
    std::vector<RandomizerCheck> locationsInCategory;
    for (RandomizerCheck locKey : locationPool) {
        if (StaticData::Location(locKey)->IsCategory(categoryInclude) &&
            !StaticData::Location(locKey)->IsCategory(categoryExclude)) {
            locationsInCategory.push_back(locKey);
        }
    }
    return locationsInCategory;
}

void Context::ItemReset() {
    for (RandomizerCheck il : allLocations) {
        GetItemLocation(il)->ResetVariables();
    }
}

void Context::LocationReset() {
    for (RandomizerCheck il : allLocations) {
        GetItemLocation(il)->RemoveFromPool();
    }

    //TODO: Dungeon Rewards and Hints
}

void Context::CreateItemOverrides() {
    SPDLOG_DEBUG("NOW CREATING OVERRIDES\n\n");
    for (RandomizerCheck locKey : allLocations) {
        auto loc = StaticData::Location(locKey);
        auto itemLoc = GetItemLocation(locKey);
        ItemOverride_Value val = StaticData::RetrieveItem(itemLoc->GetPlacedRandomizerGet()).Value();
        // If this is an ice trap, store the disguise model in iceTrapModels
        if (itemLoc->GetPlacedRandomizerGet() == RG_ICE_TRAP) {
            iceTrapModels[loc->GetRandomizerCheck()] = val.looksLikeItemId;
            // If this is ice trap is in a shop, change the name based on what the model will look like
            if (loc->IsCategory(Category::cShop)) {
                NonShopItems[TransformShopIndex(GetShopIndex(locKey))].Name = GetIceTrapName(val.looksLikeItemId);
            }
        }
        overrides.insert({
            .key = itemLoc->Key(),
            .value = val,
        });
        SPDLOG_DEBUG("\tScene: ");
        SPDLOG_DEBUG(std::to_string(itemLoc->Key().scene));
        SPDLOG_DEBUG("\tType: ");
        SPDLOG_DEBUG(std::to_string(itemLoc->Key().type));
        SPDLOG_DEBUG("\t");
        SPDLOG_DEBUG(loc->GetName());
        SPDLOG_DEBUG(": ");
        SPDLOG_DEBUG(loc->GetPlacedItemName().GetEnglish());
        SPDLOG_DEBUG("\n");
    }
    SPDLOG_DEBUG("Overrides Created: ");
    SPDLOG_DEBUG(std::to_string(overrides.size()));
}
}
