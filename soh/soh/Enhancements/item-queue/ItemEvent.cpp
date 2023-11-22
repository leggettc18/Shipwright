#include "ItemEvent.h"

#include "soh/OTRGlobals.h"
#include "soh/Enhancements/game-interactor/GameInteractor.h"
#include "soh/Enhancements/item-tables/ItemTableManager.h"


ItemEvent::ItemEvent() : mGiEntry(GET_ITEM_NONE), mMethod(ItemObtainMethod::DROP), mItemGetUIFlags(ItemGet_None), mFlagType(FLAG_NONE), mFlag(0) {}

bool ItemEvent::HasEntry(const GetItemEntry& giEntry) const {
    if (giEntry.modIndex == mGiEntry.modIndex) {
        return giEntry.getItemId == mGiEntry.getItemId;
    }
    return false;
}

GetItemEntry* ItemEvent::RetrieveGetItemEntry() {
    return &mGiEntry;
}

void ItemEvent::SetFlag() const {
    GameInteractor::RawAction::SetFlag(mFlagType, mFlag);
}

ItemEvent::ItemEvent(const GetItemEntry& giEntry, const ItemObtainMethod method, const uint8_t itemGetUIFlags, const FlagType flagType, const int16_t flag)
    : mGiEntry(giEntry), mMethod(method), mItemGetUIFlags(itemGetUIFlags), mFlagType(flagType), mFlag(flag) {}
