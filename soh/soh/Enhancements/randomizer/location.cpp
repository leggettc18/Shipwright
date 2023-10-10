#include "location.h"
#include "3drando/hint_list.hpp"

RandomizerCheck Rando::Location::GetRandomizerCheck() const {
    return rc;
}

Rando::SpoilerCollectionCheck Rando::Location::GetCollectionCheck() const {
    return collectionCheck;
}

SpoilerCollectionCheckGroup Rando::Location::GetCollectionCheckGroup() const {
    return collectionCheckGroup;
}

SceneID Rando::Location::GetScene() const {
    return (SceneID)scene;
}

uint8_t Rando::Location::GetFlag() const {
    return flag;
}

RandomizerHintTextKey Rando::Location::GetHintKey() const {
    return hintKey;
}

HintText* Rando::Location::GetHint() {
    return &hintTable[hintKey];
}

const std::string& Rando::Location::GetName() const {
    return spoilerName;
}

const std::string& Rando::Location::GetShortName() const {
    return shortName;
}

Rando::LocationType Rando::Location::GetLocationType() const {
    return locationType;
}

bool Rando::Location::IsCategory(Category category) const {
    return std::any_of(categories.begin(), categories.end(), [category](auto entry) { return entry == category; });
}

bool Rando::Location::IsDungeon() const {
    return (locationType != LocationType::GSToken &&
            (scene < SCENE_GANON_SONOGO || (scene > SCENE_TAKARAYA && scene < SCENE_GANON_FINAL))) ||
           (locationType == LocationType::GSToken && scene < SCENE_GANON);
}

bool Rando::Location::IsOverworld() const {
    return !IsDungeon();
}

bool Rando::Location::IsShop() const {
    return (scene >= SCENE_SHOP1 && scene <= SCENE_NIGHT_SHOP);
}

uint32_t Rando::Location::Getuint32_t() const {
    return hintKey;
}

const HintText& Rando::Location::GetHint() const {
    return Hint(hintKey);
}

RandomizerGet Rando::Location::GetVanillaItem() const {
    return vanillaItem;
}

Rando::Location Rando::Location::Base(RandomizerCheck rc, RandomizerCheckQuest quest_, RandomizerCheckType checkType_,
                                      RandomizerCheckArea area_, ActorID actorId_, uint8_t scene_, int32_t actorParams_,
                                      uint8_t flag_, std::string&& shortName_, std::string&& spoilerName_,
                                      const RandomizerHintTextKey hintKey, const RandomizerGet vanillaItem,
                                      std::vector<Category>&& categories, SpoilerCollectionCheck collectionCheck,
                                      SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::Base, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    collectionCheck, collectionCheckGroup);
}

Rando::Location Rando::Location::Chest(RandomizerCheck rc, RandomizerCheckQuest quest_, RandomizerCheckType checkType_,
                                       RandomizerCheckArea area_, ActorID actorId_, uint8_t scene_,
                                       int32_t actorParams_, uint8_t flag_, std::string&& shortName_,
                                       std::string&& spoilerName_, const RandomizerHintTextKey hintKey,
                                       const RandomizerGet vanillaItem, std::vector<Category>&& categories,
                                       SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::Chest, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_CHEST, scene_, flag_),
                    collectionCheckGroup);
}

Rando::Location Rando::Location::Chest(RandomizerCheck rc, RandomizerCheckQuest quest_, RandomizerCheckType checkType_,
                                       RandomizerCheckArea area_, ActorID actorId_, uint8_t scene_,
                                       int32_t actorParams_, uint8_t flag_, std::string&& shortName_,
                                       std::string&& spoilerName_, const RandomizerHintTextKey hintKey,
                                       const RandomizerGet vanillaItem, std::vector<Category>&& categories,
                                       SpoilerCollectionCheck collectionCheck,
                                       SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::Chest, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    collectionCheck, collectionCheckGroup);
}

Rando::Location Rando::Location::Collectable(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                             RandomizerCheckType checkType_, RandomizerCheckArea area_,
                                             ActorID actorId_, uint8_t scene_, int32_t actorParams_, uint8_t flag_,
                                             std::string&& shortName_, std::string&& spoilerName_,
                                             const RandomizerHintTextKey hintKey, const RandomizerGet vanillaItem,
                                             std::vector<Category>&& categories,
                                             SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::Collectable, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_COLLECTABLE, scene_, flag_),
                    collectionCheckGroup);
}

Rando::Location Rando::Location::Collectable(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                             RandomizerCheckType checkType_, RandomizerCheckArea area_,
                                             ActorID actorId_, uint8_t scene_, int32_t actorParams_, uint8_t flag_,
                                             std::string&& shortName_, std::string&& spoilerName_,
                                             const RandomizerHintTextKey hintKey, const RandomizerGet vanillaItem,
                                             std::vector<Category>&& categories, SpoilerCollectionCheck collectionCheck,
                                             SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::Collectable, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    collectionCheck, collectionCheckGroup);
}

Rando::Location Rando::Location::GSToken(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                         RandomizerCheckType checkType_, RandomizerCheckArea area_, ActorID actorId_,
                                         uint8_t scene_, int32_t actorParams_, uint8_t flag_, std::string&& shortName_,
                                         std::string&& spoilerName_, const RandomizerHintTextKey hintKey,
                                         std::vector<Category>&& categories,
                                         SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(
        rc, quest_, checkType_, area_, LocationType::GSToken, actorId_, scene_, actorParams_, flag_,
        std::move(shortName_), std::move(spoilerName_), hintKey, RG_GOLD_SKULLTULA_TOKEN, std::move(categories),
        SpoilerCollectionCheck(SpoilerCollectionCheckType::SPOILER_CHK_GOLD_SKULLTULA, scene_, flag_),
        collectionCheckGroup);
}

Rando::Location Rando::Location::GrottoScrub(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                             RandomizerCheckType checkType_, RandomizerCheckArea area_,
                                             ActorID actorId_, uint8_t scene_, int32_t actorParams_, uint8_t flag_,
                                             std::string&& shortName_, std::string&& spoilerName_,
                                             const RandomizerHintTextKey hintKey, const RandomizerGet vanillaItem,
                                             std::vector<Category>&& categories, SpoilerCollectionCheck collectionCheck,
                                             SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::GrottoScrub, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    collectionCheck, collectionCheckGroup);
}

Rando::Location Rando::Location::Delayed(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                         RandomizerCheckType checkType_, RandomizerCheckArea area_, ActorID actorId_,
                                         uint8_t scene_, int32_t actorParams_, uint8_t flag_, std::string&& shortName_,
                                         std::string&& spoilerName_, const RandomizerHintTextKey hintKey,
                                         const RandomizerGet vanillaItem, std::vector<Category>&& categories,
                                         SpoilerCollectionCheck collectionCheck,
                                         SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::Delayed, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    collectionCheck, collectionCheckGroup);
}

Rando::Location Rando::Location::Reward(RandomizerCheck rc, RandomizerCheckQuest quest_, RandomizerCheckType checkType_,
                                        RandomizerCheckArea area_, ActorID actorId_, uint8_t scene_,
                                        int32_t actorParams_, uint8_t flag_, std::string&& shortName_,
                                        std::string&& spoilerName_, const RandomizerHintTextKey hintKey,
                                        const RandomizerGet vanillaItem, std::vector<Category>&& categories,
                                        SpoilerCollectionCheck collectionCheck,
                                        SpoilerCollectionCheckGroup collectionCheckGroup) {
    return Location(rc, quest_, checkType_, area_, LocationType::TempleReward, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), hintKey, vanillaItem, std::move(categories),
                    collectionCheck, collectionCheckGroup);
}

Rando::Location Rando::Location::OtherHint(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                           RandomizerCheckType checkType_, RandomizerCheckArea area_, ActorID actorId_,
                                           uint8_t scene_, int32_t actorParams_, uint8_t flag_,
                                           std::string&& shortName_, std::string&& spoilerName_,
                                           std::vector<Category>&& categories) {
    return Location(rc, quest_, checkType_, area_, LocationType::OtherHint, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), RHT_NONE, RG_NONE, std::move(categories));
}

Rando::Location Rando::Location::HintStone(RandomizerCheck rc, RandomizerCheckQuest quest_,
                                           RandomizerCheckType checkType_, RandomizerCheckArea area_, ActorID actorId_,
                                           uint8_t scene_, int32_t actorParams_, uint8_t flag_,
                                           std::string&& shortName_, std::string&& spoilerName_,
                                           std::vector<Category>&& categories) {
    return Location(rc, quest_, checkType_, area_, LocationType::Base, actorId_, scene_, actorParams_, flag_,
                    std::move(shortName_), std::move(spoilerName_), RHT_NONE, RG_NONE, std::move(categories));
}