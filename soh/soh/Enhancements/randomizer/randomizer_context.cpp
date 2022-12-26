#include "randomizer_context.h"
#include "randomizer_static_data.h"

uint8_t RandomizerContext::GetSilverRupeeIndex(RandomizerGet silverRupeeRGID) {
    uint8_t index = -1;
    if (silverRupeeRGID > RG_SILVER_RUPEE_LAST && silverRupeeRGID <= RG_SILVER_RUPEE_POUCH_LAST) {
        index = silverRupeeRGID - RG_SILVER_RUPEE_POUCH_FIRST;
    } else if (silverRupeeRGID >= RG_SILVER_RUPEE_FIRST) {
        index = silverRupeeRGID - RG_SILVER_RUPEE_FIRST;
    }
    return index;
}

RandomizerContext::RandomizerContext() {
}

void RandomizerContext::ParseMasterQuestDungeonsSpoiler(json jsonContext) {
    json mqDungeonsJson = jsonContext["masterQuestDungeons"];

    this->masterQuestDungeons.clear();

    for (auto it = mqDungeonsJson.begin(); it != mqDungeonsJson.end(); it++) {
        this->masterQuestDungeons.emplace(spoilerFileDungeonToScene.at(it.value()));
    }

    InitSilverRupeeTotals();
}

void RandomizerContext::InitSilverRupeeTotals() {
    for (uint16_t rgid = RG_SILVER_RUPEE_FIRST; rgid <= RG_SILVER_RUPEE_LAST; rgid++) {
        int index = rgid - RG_SILVER_RUPEE_FIRST;
        switch (rgid) {
            case RG_ICE_CAVERN_SPINNING_BLADES_SILVER_RUPEE:
            case RG_ICE_CAVERN_SLIDING_SILVER_RUPEE:
                if (!IsDungeonMasterQuest(SCENE_ICE_DOUKUTO)) {
                    SilverRupeeTotals[index] = 5;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
                break;
            case RG_BOTTOM_OF_THE_WELL_SILVER_RUPEE:
                if (!IsDungeonMasterQuest(SCENE_HAKADANCH)) {
                    SilverRupeeTotals[index] = 5;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
                break;
            case RG_GERUDO_TRAINING_GROUNDS_BOULDER_SILVER_RUPEE:
            case RG_SHADOW_SCYTHE_SILVER_RUPEE:
            case RG_SHADOW_OUTSIDE_SPIKE_RAIN_SILVER_RUPEE:
            case RG_FIRE_TRIAL_SILVER_RUPEE:
                SilverRupeeTotals[index] = 5;
                break;
            case RG_GERUDO_TRAINING_GROUNDS_LAVA_SILVER_RUPEE:
                if (IsDungeonMasterQuest(SCENE_MEN)) {
                    SilverRupeeTotals[index] = 6;
                } else {
                    SilverRupeeTotals[index] = 5;
                }
                break;
            case RG_GERUDO_TRAINING_GROUNDS_TOILET_SILVER_RUPEE:
                if (IsDungeonMasterQuest(SCENE_MEN)) {
                    SilverRupeeTotals[index] = 3;
                } else {
                    SilverRupeeTotals[index] = 5;
                }
                break;
            case RG_SPIRIT_CHILD_BLOCK_PUSH_SILVER_RUPEE:
            case RG_SPIRIT_BOULDER_SILVER_RUPEE:
                if (!IsDungeonMasterQuest(SCENE_JYASINZOU)) {
                    SilverRupeeTotals[index] = 5;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
                break;
            case RG_SHADOW_INVISIBLE_SPIKES_SILVER_RUPEE:
                if (IsDungeonMasterQuest(SCENE_HAKADAN)) {
                    SilverRupeeTotals[index] = 10;
                } else {
                    SilverRupeeTotals[index] = 5;
                }
                break;
            case RG_FOREST_TRIAL_SILVER_RUPEE:
            case RG_SPIRIT_TRIAL_SILVER_RUPEE:
            case RG_LIGHT_TRIAL_SILVER_RUPEE:
                if (!IsDungeonMasterQuest(SCENE_GANONTIKA)) {
                    SilverRupeeTotals[index] = 5;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
                break;
            case RG_DODONGOS_CAVERN_MQ_SILVER_RUPEE:
                if (IsDungeonMasterQuest(SCENE_DDAN)) {
                    SilverRupeeTotals[index] = 5;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
                break;
            case RG_SPIRIT_MQ_LOBBY_SILVER_RUPEE:
                if (IsDungeonMasterQuest(SCENE_JYASINZOU)) {
                    SilverRupeeTotals[index] = 5;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
            case RG_SHADOW_MQ_INVISIBLE_SCYTHE_SILVER_RUPEE:
                if (IsDungeonMasterQuest(SCENE_HAKADAN)) {
                    SilverRupeeTotals[index] = 10;
                } else {
                    SilverRupeeTotals[index] = 0;
                }
        }
    }
}

bool RandomizerContext::IsDungeonMasterQuest(SceneID dungeon) {
    return this->masterQuestDungeons.contains(dungeon);
}

void RandomizerContext::SetDungeonMasterQuest(SceneID dungeon) {
    if (dungeonScenes.contains(dungeon)) {
        this->masterQuestDungeons.emplace(dungeon);
    }
}

void RandomizerContext::ClearMasterQuestDungeons() {
    this->masterQuestDungeons.clear();
}

u8 RandomizerContext::MasterQuestDungeonsCount() {
    return this->masterQuestDungeons.size();
}

bool RandomizerContext::IsSilverRupeePuzzleComplete(RandomizerGet silverRupeeRGID) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return false;
    }
    return this->SilverRupeeCounts[index] == this->SilverRupeeTotals[index];
}

uint8_t RandomizerContext::GetSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return 0;
    }
    return this->SilverRupeeCounts[index];
}

uint8_t RandomizerContext::SetSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID, uint8_t count) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return 0;
    }
    this->SilverRupeeCounts[index] = count;
    return this->SilverRupeeCounts[index];
}

uint8_t RandomizerContext::IncrementSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return 0;
    }
    return ++this->SilverRupeeCounts[index];
}

uint8_t RandomizerContext::DecrementSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return 0;
    }
    return --this->SilverRupeeCounts[index];
}

void RandomizerContext::CompleteSilverRupeePuzzle(RandomizerGet silverRupeeRGID) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return;
    }
    this->SilverRupeeCounts[index] = this->SilverRupeeTotals[index];
}

uint8_t RandomizerContext::GetSilverRupeePuzzleTotal(RandomizerGet silverRupeeRGID) {
    uint8_t index = GetSilverRupeeIndex(silverRupeeRGID);
    if (index < 0) {
        return 0;
    }
    return this->SilverRupeeTotals[index];
}
