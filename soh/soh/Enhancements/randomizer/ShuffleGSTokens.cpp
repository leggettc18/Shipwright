#include "soh/ActorDB.h"
#include "soh/Enhancements/randomizer/randomizerTypes.h"
#include "soh/OTRGlobals.h"
#include "soh/ObjectExtension/ObjectExtension.h"
#include "draw.h"

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
    GSActor(SceneID scene, LinkAge age, int room, RandomizerInf flag, RandomizerCheck check, Vec3s pos, Vec3s rot, s16 params)
      : mScene(scene), mAge(age), mRoom(room), mFlag(flag), mCheck(check) {
        mActorEntry = { ACTOR_EN_SW, pos, rot, params };
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

#define NUM_CUSTOM_GS_ACTORS 5

std::array<GSActor, NUM_CUSTOM_GS_ACTORS> customGSActors = {
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 0, RAND_INF_KF_CGS_LINKS_HOUSE_CHILD, RC_KF_CGS_LINKS_HOUSE_CHILD, {-160, 40, 1214}, {0, 0, 0}, 0xAD00),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_ADULT, 0, RAND_INF_KF_CGS_LINKS_HOUSE_ADULT, RC_KF_CGS_LINKS_HOUSE_ADULT, {-160, 40, 1214}, {0, 0, 0}, 0xAD00),
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, 1, RAND_INF_KF_CGS_BEHIND_DEKU_TREE_CHILD, RC_KF_CGS_BEHIND_DEKU_TREE_CHILD, { 4855, -154, -2182 }, {0, 0, 0}, 0xAD00),
  GSActor(SCENE_KAKARIKO_VILLAGE, LINK_AGE_ADULT, 0, RAND_INF_KAK_CGS_WINDMILL_ALCOVE, RC_KAK_CGS_WINDMILL_ALCOVE, {1297, 902, 631}, {0, 0, 0}, 0xB100),
  GSActor(SCENE_OUTSIDE_GANONS_CASTLE, LINK_AGE_ADULT, 0, RAND_INF_OGC_CGS_BEHIND_OBELISK, RC_OGC_CGS_BEHIND_OBELISK, {3008, 1400, 515}, {0, 0, 0}, 0x8F00)
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
