#ifndef ITEMEVENTQUEUE_H
#define ITEMEVENTQUEUE_H
#include "ItemEvent.h"

#include <deque>

#include "soh/Enhancements/item-tables/ItemTableTypes.h"


class ItemEventQueue {
public:
    ItemEventQueue();

    void AddItemEvent(const GetItemEntry& giEntry, ItemObtainMethod method, uint8_t itemGetUIFlags, FlagType flagType, int16_t flag);
    const ItemEvent& Front() const;
    void PopFront();
private:
    std::deque<ItemEvent> mQueue;
};



#endif //ITEMEVENTQUEUE_H
