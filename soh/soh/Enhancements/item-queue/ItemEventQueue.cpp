#include "ItemEventQueue.h"

#include "soh/OTRGlobals.h"

extern "C" const GetItemEntry* ItemEventQueue_FrontGIEntry() {
    if (OTRGlobals::Instance->gItemEventQueue->Empty()) {
        return nullptr;
    }
    return OTRGlobals::Instance->gItemEventQueue->Front().RetrieveGetItemEntry();
}

extern "C" uint8_t ItemEventQueue_FrontHasFlags(const uint8_t itemGetUIFlags) {
    if (!OTRGlobals::Instance->gItemEventQueue->Empty() &&
        OTRGlobals::Instance->gItemEventQueue->Front().HasFlags(itemGetUIFlags)) {
        return 1;
    }
    return 0;
}

extern "C" void ItemEventQueue_PopFront() {
    OTRGlobals::Instance->gItemEventQueue->PopFront();
}

extern "C" void ItemEventQueue_AddItem(GetItemEntry giEntry, ItemObtainMethod method, FlagType flagType, int16_t flag) {
    // TODO: Set different ItemGetUIFlags according to settings.
    OTRGlobals::Instance->gItemEventQueue->AddItemEvent(giEntry, method, ItemGet_FullAnimation, flagType, flag);
}

bool ItemEventQueue::Empty() const {
    return mQueue.empty();
}

void ItemEventQueue::AddItemEvent(const GetItemEntry& giEntry, ItemObtainMethod method, uint8_t itemGetUIFlags, FlagType flagType, int16_t flag) {
    mQueue.emplace_back(giEntry, method, itemGetUIFlags, flagType, flag);
}

const ItemEvent& ItemEventQueue::Front() const {
    return mQueue.front();
}

void ItemEventQueue::PopFront() {
    mQueue.front().SetFlag();
    mQueue.pop_front();
}
