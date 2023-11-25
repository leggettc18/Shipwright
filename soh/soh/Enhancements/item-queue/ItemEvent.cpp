#include "ItemEvent.h"

#include "soh/OTRGlobals.h"
#include "soh/Enhancements/game-interactor/GameInteractor.h"
#include "soh/Enhancements/item-tables/ItemTableManager.h"


ItemEvent::ItemEvent() : mGiEntry(GET_ITEM_NONE), mMethod(OBTAIN_FROM_DROP), mItemGetUIFlags(ItemGet_None), mFlagType(FLAG_NONE), mFlag(0) {}

const GetItemEntry* ItemEvent::RetrieveGetItemEntry() const {
    return &mGiEntry;
}

void ItemEvent::SetFlag() const {
    GameInteractor::RawAction::SetFlag(mFlagType, mFlag);
}

ItemEvent::ItemEvent(const GetItemEntry& giEntry, const ItemObtainMethod method, const uint8_t itemGetUIFlags, const FlagType flagType, const int16_t flag)
    : mGiEntry(giEntry), mMethod(method), mItemGetUIFlags(itemGetUIFlags), mFlagType(flagType), mFlag(flag) {}

bool ItemEvent::HasFlags(const uint8_t itemGetUIFlags) const {
    return (mItemGetUIFlags & itemGetUIFlags) > 0;
}