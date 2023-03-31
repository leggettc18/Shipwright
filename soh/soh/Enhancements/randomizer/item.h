#pragma once

#include <string>
#include <variant>

#include "3drando/text.hpp"
#include "3drando/settings.hpp"
#include "3drando/hint_list.hpp"
#include "randomizerTypes.h"
#include "soh/Enhancements/item-tables/ItemTableTypes.h"

union ItemOverride_Value;

enum ItemType {
    ITEMTYPE_ITEM,
    ITEMTYPE_MAP,
    ITEMTYPE_COMPASS,
    ITEMTYPE_BOSSKEY,
    ITEMTYPE_SMALLKEY,
    ITEMTYPE_TOKEN,
    ITEMTYPE_FORTRESS_SMALLKEY,
    ITEMTYPE_EVENT,
    ITEMTYPE_DROP,
    ITEMTYPE_REFILL,
    ITEMTYPE_SONG,
    ITEMTYPE_SHOP,
    ITEMTYPE_DUNGEONREWARD
};

class RandoItem {
  public:
    RandoItem() = default;
    RandoItem(RandomizerGet randomizerGet_, Text name_, ItemType type_, int getItemId_, bool advancement_, bool* logicVar_,
         uint32_t hintKey_, int itemId_, int field_, int textId_, int objectId_, int modIndex_, int gid_, GetItemCategory category_, uint16_t price_ = 0);
    RandoItem(RandomizerGet randomizerGet_, Text name_, ItemType type_, int getItemId_, bool advancement_,
              uint8_t* logicVar_, uint32_t hintKey_, int itemId_, int field_, int textId, int objectId_, int modIndex_,
              int gid_, GetItemCategory category_, uint16_t price_ = 0);
    ~RandoItem();

    void ApplyEffect();
    void UndoEffect();

    ItemOverride_Value Value() const;

    const Text& GetName() const {
        return name;
    }

    bool IsAdvancement() const {
        return advancement;
    }

    int GetItemID() const {
        return getItemId;
    }

    ItemType GetItemType() const {
        return type;
    }

    RandomizerGet GetRandomizerGet() {
        return randomizerGet;
    }

    uint16_t GetPrice() const {
        return price;
    }

    void SetPrice(uint16_t price_) {
        price = price_;
    }

    void SetAsPlaythrough() {
        playthrough = true;
    }

    bool IsPlaythrough() const {
        return playthrough;
    }

    bool IsBottleItem() const {
        return getItemId == 0x0F ||                      // Empty Bottle
               getItemId == 0X14 ||                      // Bottle with Milk
               (getItemId >= 0x8C && getItemId <= 0x94); // Rest of bottled contents
    }

    bool IsMajorItem() const {
        using namespace Settings;
        if (type == ITEMTYPE_TOKEN) {
            return Bridge.Is(RAINBOWBRIDGE_TOKENS) || LACSCondition == LACSCONDITION_TOKENS;
        }

        if (type == ITEMTYPE_DROP || type == ITEMTYPE_EVENT || type == ITEMTYPE_SHOP || type == ITEMTYPE_MAP ||
            type == ITEMTYPE_COMPASS) {
            return false;
        }

        if (type == ITEMTYPE_DUNGEONREWARD && (ShuffleRewards.Is(REWARDSHUFFLE_END_OF_DUNGEON))) {
            return false;
        }

        if ((randomizerGet == RG_BOMBCHU_5 || randomizerGet == RG_BOMBCHU_10 || randomizerGet == RG_BOMBCHU_20) &&
            !BombchusInLogic) {
            return false;
        }

        if (hintKey == RG_HEART_CONTAINER || hintKey == RG_PIECE_OF_HEART || hintKey == RG_TREASURE_GAME_HEART) {
            return false;
        }

        if (type == ITEMTYPE_SMALLKEY && (Keysanity.Is(KEYSANITY_VANILLA) || Keysanity.Is(KEYSANITY_OWN_DUNGEON))) {
            return false;
        }

        if (type == ITEMTYPE_FORTRESS_SMALLKEY && GerudoKeys.Is(GERUDOKEYS_VANILLA)) {
            return false;
        }

        if ((type == ITEMTYPE_BOSSKEY && getItemId != 0xAD) &&
            (BossKeysanity.Is(BOSSKEYSANITY_VANILLA) || BossKeysanity.Is(BOSSKEYSANITY_OWN_DUNGEON))) {
            return false;
        }
        // Ganons Castle Boss Key
        if (getItemId == 0xAD &&
            (GanonsBossKey.Is(GANONSBOSSKEY_VANILLA) || GanonsBossKey.Is(GANONSBOSSKEY_OWN_DUNGEON))) {
            return false;
        }

        if (randomizerGet == RG_GREG_RUPEE) {
            return Bridge.Is(RAINBOWBRIDGE_GREG);
        }

        return IsAdvancement();
    }

    const uint32_t GetHintKey() const {
        return hintKey;
    }

    const HintText& GetHint() const {
        return Hint(hintKey);
    }

    bool operator==(const RandoItem& right) const {
        return type == right.GetItemType() && getItemId == right.GetItemID();
    }

    bool operator!=(const RandoItem& right) const {
        return !operator==(right);
    }

  private:
    RandomizerGet randomizerGet;
    Text name;
    ItemType type;
    int getItemId;
    bool advancement;
    std::variant<bool*, uint8_t*> logicVar;
    uint32_t hintKey;
    int itemId;
    int field;
    int textId;
    int objectId;
    int modIndex;
    int gid;
    bool collectable;
    GetItemCategory category;
    uint16_t price;
    bool playthrough = false;
};
