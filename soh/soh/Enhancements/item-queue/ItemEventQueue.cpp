#include "ItemEventQueue.h"

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
