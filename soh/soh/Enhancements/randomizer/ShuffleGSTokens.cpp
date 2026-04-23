#include "soh/ActorDB.h"
#include "soh/Enhancements/randomizer/randomizerTypes.h"
#include "soh/OTRGlobals.h"
#include "soh/ObjectExtension/ObjectExtension.h"
#include "draw.h"
#include "z64scene.h"

extern "C" {
#include "variables.h"
#include "z64.h"
#include "overlays/actors/ovl_En_Si/z_en_si.h"
#include "overlays/actors/ovl_En_Sw/z_en_sw.h"
  extern PlayState* gPlayState;
  Actor* Actor_SpawnEntry(ActorContext* actorCtx, ActorEntry* actorEntry, PlayState* play);
  s32 Object_Spawn(ObjectContext* objectCtx, s16 objectId);
  ActorDBEntry* ActorDB_Retrieve(const int id);
}


class GSActor {
  public:
    GSActor(SceneID scene, LinkAge age, int room, RandomizerInf flag, RandomizerCheck check, Vec3s pos, int params)
      : mScene(scene), mAge(age), mRoom(room), mFlag(flag), mCheck(check) {
        mActorEntry = { ACTOR_EN_SW, pos, {0, 0, 0}, static_cast<int16_t>(params) };
      }

    ActorEntry* GetActorEntryPtr() {
      return &mActorEntry;
    }

    SceneID GetScene() {
      return mScene;
    }

    LinkAge GetAge() {
      return mAge;
    }

    int GetRoom() {
      return mRoom;
    }

    RandomizerCheck GetCheck() {
      return mCheck;
    }

    RandomizerInf GetFlag() {
      return mFlag;
    }

    CheckIdentity GetIdentity() {
      return CheckIdentity{ mFlag, mCheck };
    }

  private:
    SceneID mScene;
    LinkAge mAge;
    int mRoom;
    RandomizerInf mFlag;
    RandomizerCheck mCheck;
    ActorEntry mActorEntry;
};

#define NUM_CUSTOM_GS_ACTORS 100

// Gold Skulltula Spawn Params
#define GS_NIGHT 0xA000 // Spawn Gold Skulltula only at Night
#define GS_ALWAYS 0x8000 // Spawn Gold Skulltula Always

#define GS_DT 0x0100 // Deku Tree
#define GS_DC 0x0200 // Dodongo's Cavern
#define GS_JABU 0x0300 // Inside Jabu Jabu's Belly
#define GS_FOREST 0x0400 // Forest Temple
#define GS_FIRE 0x0500 // Fire Temple
#define GS_WATER 0x0600 // Water Temple
#define GS_SPIRIT 0x0700 // Spirit Temple
#define GS_SHADOW 0x0800 // Shadow Temple
#define GS_BOTW 0x0900 // Bottom of the Well
#define GS_IC 0x0A00 // Ice Cavern
#define GS_HF 0x0B00 // Hyrule Field
#define GS_LLR 0x0C00 // Lon Lon Ranch
#define GS_KF 0x0D00 // Kokiri Forest
#define GS_LW 0x0E00 // Lost Woods and Sacred Forest Meadow
#define GS_HC 0x0F00 // Castle Town and Ganon's Castle
#define GS_DM 0x1000 // Death Mountain Trail, Goron City, Death Mountain Crater
#define GS_KAK 0x1100 // Kakariko Village and Graveyard
#define GS_ZR 0x1200 // Zora's River, Domain, and Fountain
#define GS_LH 0x1300 // Lake Hylia
#define GS_GV 0x1400 // Gerudo Valley
#define GS_GF 0x1500 // Gerudo Fortress
#define GS_DS 0x1600 // Desert Colossus, Haunted Wasteland

std::vector<GSActor> customGSActors = {
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 0, RAND_INF_KF_CGS_LINKS_HOUSE_CHILD, RC_KF_CGS_LINKS_HOUSE_CHILD, {-160, 40, 1214}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_ADULT, 0, RAND_INF_KF_CGS_LINKS_HOUSE_ADULT, RC_KF_CGS_LINKS_HOUSE_ADULT, {-160, 40, 1214}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 1, RAND_INF_KF_CGS_BEHIND_DEKU_TREE_CHILD, RC_KF_CGS_BEHIND_DEKU_TREE_CHILD, { 4855, -154, -2182 }, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_ADULT, 1, RAND_INF_KF_CGS_BEHIND_DEKU_TREE_ADULT, RC_KF_CGS_BEHIND_DEKU_TREE_ADULT, { 4855, -154, -2182 }, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 2, RAND_INF_KF_CGS_BOULDER_MAZE, RC_KF_CGS_BOULDER_MAZE, {-233, 280, 2335}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 0, RAND_INF_KF_CGS_BEAN_ALCOVE, RC_KF_CGS_BEAN_ALCOVE, { 1305, 300, -480 }, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 0, RAND_INF_KF_CGS_BEHIND_SHOP_CHILD, RC_KF_CGS_BEHIND_SHOP_CHILD, {657, 200, -659}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_ADULT, 0, RAND_INF_KF_CGS_BEHIND_SHOP_ADULT, RC_KF_CGS_BEHIND_SHOP_ADULT, {657, 200, -659}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 0, RAND_INF_KF_CGS_CLIFF_NEAR_LW_CHILD, RC_KF_CGS_CLIFF_NEAR_LW_CHILD, {-702, 320, -1138}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_ADULT, 0, RAND_INF_KF_CGS_CLIFF_NEAR_LW_ADULT, RC_KF_CGS_CLIFF_NEAR_LW_ADULT, {-702, 320, -1138}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 0, RAND_INF_KF_CGS_WATERFALL_CHILD, RC_KF_CGS_WATERFALL_CHILD, {400, 250, -512}, GS_NIGHT | GS_KF),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_ADULT, 0, RAND_INF_KF_CGS_WATERFALL_ADULT, RC_KF_CGS_WATERFALL_ADULT, {400, 250, -512}, GS_NIGHT | GS_KF),
  GSActor(SCENE_LOST_WOODS, LINK_AGE_CHILD, 5, RAND_INF_LW_CGS_ON_TREE_NEAR_BRIDGE_CHILD, RC_LW_CGS_ON_TREE_NEAR_BRIDGE_CHILD, {-1290, -20, 1460}, GS_NIGHT | GS_LW),
  GSActor(SCENE_LOST_WOODS, LINK_AGE_ADULT, 5, RAND_INF_LW_CGS_ON_TREE_NEAR_BRIDGE_ADULT, RC_LW_CGS_ON_TREE_NEAR_BRIDGE_ADULT, {-1290, -20, 1460}, GS_NIGHT | GS_LW),
  GSActor(SCENE_LOST_WOODS, LINK_AGE_CHILD, 1, RAND_INF_LW_CGS_NEAR_MEMORY_GAME_CHILD, RC_LW_CGS_NEAR_MEMORY_GAME_CHILD, {1250, -180, 569}, GS_NIGHT | GS_LW),
  GSActor(SCENE_LOST_WOODS, LINK_AGE_ADULT, 1, RAND_INF_LW_CGS_NEAR_MEMORY_GAME_ADULT, RC_LW_CGS_NEAR_MEMORY_GAME_ADULT, {1250, -180, 569}, GS_NIGHT | GS_LW),
  GSActor(SCENE_SACRED_FOREST_MEADOW, LINK_AGE_CHILD, 0, RAND_INF_SFM_CGS_UNDER_TEMPLE_STAIRCASE_CHILD, RC_SFM_CGS_UNDER_TEMPLE_STAIRCASE_CHILD, {-8, 600, -3072}, GS_NIGHT | GS_LW),
  GSActor(SCENE_SACRED_FOREST_MEADOW, LINK_AGE_ADULT, 0, RAND_INF_SFM_CGS_UNDER_TEMPLE_STAIRCASE_ADULT, RC_SFM_CGS_UNDER_TEMPLE_STAIRCASE_ADULT, {-8, 600, -3072}, GS_NIGHT | GS_LW),
  GSActor(SCENE_GROTTOS, LINK_AGE_CHILD, 7, RAND_INF_SFM_CGS_WOLFOS_GROTTO_CHILD, RC_SFM_CGS_WOLFOS_GROTTO_CHILD, {1319, -118, 633}, GS_NIGHT | GS_LW),
  GSActor(SCENE_GROTTOS, LINK_AGE_ADULT, 7, RAND_INF_SFM_CGS_WOLFOS_GROTTO_ADULT, RC_SFM_CGS_WOLFOS_GROTTO_ADULT, {1319, -118, 633}, GS_NIGHT | GS_LW),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_CHILD, 0, RAND_INF_HF_CGS_BEHIND_LLR_CHILD, RC_HF_CGS_BEHIND_LLR_CHILD, {-3876, 186, 7860}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_BEHIND_LLR_ADULT, RC_HF_CGS_BEHIND_LLR_ADULT, {-3876, 186, 7860}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_CHILD, 0, RAND_INF_HF_CGS_NEAR_NORTHWEST_WATERFALL_CHILD, RC_HF_CGS_NEAR_NORTHWEST_WATERFALL_CHILD, {-2877, 1, -667}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_NEAR_NORTHWEST_WATERFALL_ADULT, RC_HF_CGS_NEAR_NORTHWEST_WATERFALL_ADULT, {-2877, 221, -667}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_BENEATH_SILVER_ROCK, RC_HF_CGS_BENEATH_SILVER_ROCK, {676, -150, 8248}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_CHILD, 0, RAND_INF_HF_CGS_CLIFF_NEAR_GV_CHILD, RC_HF_CGS_CLIFF_NEAR_GV_CHILD, {-7068, -280, 7675}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_CLIFF_NEAR_GV_ADULT, RC_HF_CGS_CLIFF_NEAR_GV_ADULT, {-7068, -280, 7675}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_CHILD, 0, RAND_INF_HF_CGS_LEDGE_ACROSS_FROM_GV_CHILD, RC_HF_CGS_LEDGE_ACROSS_FROM_GV_CHILD, {-5256, -184, 11137}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_LEDGE_ACROSS_FROM_GV_ADULT, RC_HF_CGS_LEDGE_ACROSS_FROM_GV_ADULT, {-5256, -184, 11137}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_CHILD, 0, RAND_INF_HF_CGS_NEAR_LAKE_HYLIA_CHILD, RC_HF_CGS_NEAR_LAKE_HYLIA_CHILD, {-5070, -500, 13507}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_NEAR_LAKE_HYLIA_ADULT, RC_HF_CGS_NEAR_LAKE_HYLIA_ADULT, {-5070, -500, 13507}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_CHILD, 0, RAND_INF_HF_CGS_POND_CHILD, RC_HF_CGS_POND_CHILD, {5463, 284, 4820}, GS_NIGHT | GS_HF),
  GSActor(SCENE_HYRULE_FIELD, LINK_AGE_ADULT, 0, RAND_INF_HF_CGS_POND_ADULT, RC_HF_CGS_POND_ADULT, {5463, 284, 4820}, GS_NIGHT | GS_HF),
  GSActor(SCENE_KAKARIKO_VILLAGE, LINK_AGE_ADULT, 0, RAND_INF_KAK_CGS_WINDMILL_ALCOVE, RC_KAK_CGS_WINDMILL_ALCOVE, {1297, 902, 631}, GS_NIGHT | GS_KAK),
  GSActor(SCENE_OUTSIDE_GANONS_CASTLE, LINK_AGE_ADULT, 0, RAND_INF_OGC_CGS_BEHIND_OBELISK, RC_OGC_CGS_BEHIND_OBELISK, {3008, 1400, 515}, GS_NIGHT | GS_HC)
};

void SpawnCustomGSActors() {
  ActorContext* actorCtx = &gPlayState->actorCtx;
  for (GSActor& gsActor : customGSActors) {
    if (gPlayState->sceneNum == gsActor.GetScene() && gSaveContext.linkAge == gsActor.GetAge() && gPlayState->roomCtx.curRoom.num == gsActor.GetRoom()) {
      ActorDBEntry* dbEntry = ActorDB_Retrieve(ACTOR_EN_SW);
      Object_Spawn(&gPlayState->objectCtx, dbEntry->objectId);
      Actor* actor = Actor_SpawnEntry(actorCtx, gsActor.GetActorEntryPtr(), gPlayState);
      ObjectExtension::GetInstance().Set<CheckIdentity>(actor, std::move(gsActor.GetIdentity()));
    }
  }
}

void EnSi_DrawRandomizedItem(EnSi* enSi, PlayState* play) {
    GetItemEntry randoItem = enSi->sohGetItemEntry;
    if (CVarGetInteger(CVAR_RANDOMIZER_ENHANCEMENT("MysteriousShuffle"), 0)) {
        randoItem = GET_ITEM_MYSTERY;
    }
    func_8002ED80(&enSi->actor, play, 0);
    func_8002EBCC(&enSi->actor, play, 0);
    EnItem00_CustomItemsParticles(&enSi->actor, play, randoItem);
    GetItemEntry_Draw(play, randoItem);
}

void Randomizer_OnSkullTokenActorInitHandler(void* actorRef) {
  RandomizerCheck rc = RC_UNKNOWN_CHECK;
  Actor* actor = static_cast<Actor*>(actorRef);
  EnSi* token = static_cast<EnSi*>(actorRef);
  rc = OTRGlobals::Instance->gRandomizer->GetCheckFromActor(actor->id, gPlayState->sceneNum, actor->params);
  if (rc != RC_UNKNOWN_CHECK) {
    token->sohGetItemEntry = Rando::Context::GetInstance()->GetFinalGIEntry(
        rc, true, (GetItemID)Rando::StaticData::GetLocation(rc)->GetVanillaItem());
    actor->draw = (ActorFunc)EnSi_DrawRandomizedItem;
  }
}

void RegisterGSHooks() {
  COND_HOOK(OnSceneSpawnActors, IS_RANDO, SpawnCustomGSActors);

  COND_VB_SHOULD(VB_TRANSFER_RANDO_IDENTITY_TO_TOKEN, IS_RANDO, {
      EnSw* skulltula = va_arg(args, EnSw*);
      EnSi* token = va_arg(args, EnSi*);
      if (ObjectExtension::GetInstance().Has<CheckIdentity>(skulltula)) {
        CheckIdentity identity = *(ObjectExtension::GetInstance().Get<CheckIdentity>(skulltula));
        token->sohGetItemEntry = Rando::Context::GetInstance()->GetFinalGIEntry(
            identity.randomizerCheck, true, (GetItemID)Rando::StaticData::GetLocation(identity.randomizerCheck)->GetVanillaItem());
        token->actor.draw = (ActorFunc)EnSi_DrawRandomizedItem;
        ObjectExtension::GetInstance().Set<CheckIdentity>(token, std::move(identity));
        ObjectExtension::GetInstance().Remove<CheckIdentity>(skulltula);
      }
  });

  COND_ID_HOOK(OnActorInit, ACTOR_EN_SI, IS_RANDO, Randomizer_OnSkullTokenActorInitHandler);

  COND_VB_SHOULD(VB_GIVE_ITEM_SKULL_TOKEN, IS_RANDO, {
    *should = OTRGlobals::Instance->gRandoContext->GetOption(RSK_SHUFFLE_TOKENS).Is(RO_TOKENSANITY_OFF);
  });

  COND_VB_SHOULD(VB_SET_GS_FLAG, IS_RANDO, {
      EnSi* token = va_arg(args, EnSi*);
      if (!(*should) && ObjectExtension::GetInstance().Has<CheckIdentity>(token)) {
          Flags_SetRandomizerInf(ObjectExtension::GetInstance().Get<CheckIdentity>(token)->randomizerInf);
      }
  });
}

static RegisterShipInitFunc initFunc(RegisterGSHooks, { "IS_RANDO" });
