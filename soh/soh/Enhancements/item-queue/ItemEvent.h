#ifndef ITEMEVENT_H
#define ITEMEVENT_H

#include <cstdint>
#include <variant>

#include "z64player.h"
#include "soh/Enhancements/item-tables/ItemTableTypes.h"
#include "soh/Enhancements/randomizer/randomizerTypes.h"

enum class ItemObtainMethod {
    DROP, /** For items dropped from pots, enemies, etc. */
    CHEST, /** For items obtained from chests */
    FREESTANDING, /** For freestanding items (i.e. ITEM00 instances) */
    NPC, /** For items obtained by talking to NPCs */
    SKULLTULA, /** For items obtained from dead Golden Skulltulas */
    GIFT_FROM_SAGES, /** For items obtained out of thin air */
    OTHER_PLAYERS /** For items obtained from other players, such as in a multiworld run */
};

/**
 * @brief Flags describing how the item give event should be displayed in-game. These can be combined with
 * `|`, for instance `ItemGet_MessageBox | ItemGet_OverHead` will show the item over the player's head and display a
 * text box in-game. Some of these will override others, for instance `ItemGet_FullAnimation` will cause
 * `ItemGet_MessageBox` and `ItemGet_OverHead` to have no effect.
 */
enum ItemGetUIFlags {
    ItemGet_None = 0, /** Display no feedback about collected item on the game screen (info can still be seen in message logs) */
    ItemGet_OverlayText = 1, /** Display overlay text about the collected item. */
    ItemGet_MessageBox = 1 << 1, /** Display a message box in-game for the obtained item. */
    ItemGet_OverHead = 1 << 2, /** Display the item over the player's head. */
    ItemGet_FullAnimation = 1 << 3, /** Play the full item get animation. */
};

class ItemEvent {
public:
    ItemEvent();
    ItemEvent(const GetItemEntry& giEntry, ItemObtainMethod method, uint8_t itemGetUIFlags, FlagType flagType, int16_t flag);
    bool HasEntry(const GetItemEntry& giEntry) const;
    GetItemEntry* RetrieveGetItemEntry();
    void SetFlag() const;

private:
    GetItemEntry mGiEntry;
    ItemObtainMethod mMethod;
    uint8_t mItemGetUIFlags;
    FlagType mFlagType;
    int16_t mFlag;
};



#endif //ITEMEVENT_H
