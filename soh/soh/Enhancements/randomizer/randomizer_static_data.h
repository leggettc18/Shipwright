#include <unordered_map>
#include <unordered_set>
#include <string>
#include "z64.h"

static const std::unordered_set<SceneID> dungeonScenes = {
        SCENE_YDAN, SCENE_DDAN, SCENE_BDAN, SCENE_BMORI1, SCENE_HIDAN,
        SCENE_MIZUSIN, SCENE_JYASINZOU, SCENE_HAKADAN, SCENE_HAKADANCH,
        SCENE_ICE_DOUKUTO, SCENE_MEN, SCENE_GANONTIKA
    };

static const std::unordered_map<std::string, SceneID> spoilerFileDungeonToScene = {
    { "Deku Tree", SCENE_YDAN },
    { "Dodongo's Cavern", SCENE_DDAN },
    { "Jabu Jabu's Belly", SCENE_BDAN },
    { "Forest Temple", SCENE_BMORI1 },
    { "Fire Temple", SCENE_HIDAN },
    { "Water Temple", SCENE_MIZUSIN },
    { "Spirit Temple", SCENE_JYASINZOU },
    { "Shadow Temple", SCENE_HAKADAN },
    { "Bottom of the Well", SCENE_HAKADANCH },
    { "Ice Cavern", SCENE_ICE_DOUKUTO },
    { "Gerudo Training Grounds", SCENE_MEN },
    { "Ganon's Castle", SCENE_GANONTIKA }
};