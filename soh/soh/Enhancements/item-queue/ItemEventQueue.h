#ifndef ITEMEVENTQUEUE_H
#define ITEMEVENTQUEUE_H

#include "ItemEvent.h"

#ifdef __cplusplus

#include <deque>

#include "soh/Enhancements/item-tables/ItemTableTypes.h"

extern "C" {
#endif
    const GetItemEntry* ItemEventQueue_FrontGIEntry();
    uint8_t ItemEventQueue_FrontHasFlags(uint8_t itemGetUIFlags);
    void ItemEventQueue_PopFront();
    void ItemEventQueue_AddItem(GetItemEntry giEntry, ItemObtainMethod method, FlagType flagType, int16_t flag);
#ifdef __cplusplus
}

class ItemEventQueue {
public:
    ItemEventQueue() = default;

    void AddItemEvent(const GetItemEntry& giEntry, ItemObtainMethod method, uint8_t itemGetUIFlags, FlagType flagType, int16_t flag);
    const ItemEvent& Front() const;
    void PopFront();
    bool Empty() const;
private:
    std::deque<ItemEvent> mQueue;
};


#endif
#endif //ITEMEVENTQUEUE_H
