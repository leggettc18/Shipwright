#include "ItemEvent.h"

ItemEvent::ItemEvent() : mItemId(GI_NONE), mMethod(ItemObtainMethod::DROP), mItemGetUIFlags(ItemGet_None), mQuantity(0) {}

ItemEvent::ItemEvent(GetItemID itemId, const ItemObtainMethod method, const uint8_t itemGetUIFlags, const uint32_t quantity)
    : mItemId(itemId), mMethod(method), mItemGetUIFlags(itemGetUIFlags), mQuantity(quantity) {}

ItemEvent::ItemEvent(RandomizerGet rgId, const ItemObtainMethod method, const uint8_t itemGetUIFlags, const uint32_t quantity)
    : mItemId(rgId), mMethod(method), mItemGetUIFlags(itemGetUIFlags), mQuantity(quantity) {}