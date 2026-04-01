#include "soh/OTRGlobals.h"
#include "soh/ObjectExtension/ObjectExtension.h"

extern "C" {
#include "variables.h"
#include "z64.h"
  extern PlayState* gPlayState;
  Actor* Actor_SpawnEntry(ActorContext* actorCtx, ActorEntry* actorEntry, PlayState* play);
}


class GSActor {
  public:
    GSActor(SceneID scene, LinkAge age, RandomizerInf flag, RandomizerCheck check, Vec3s pos, Vec3s rot, s16 params)
      : mScene(scene), mAge(age), mFlag(flag), mCheck(check) {
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
    RandomizerInf mFlag;
    RandomizerCheck mCheck;
    ActorEntry mActorEntry;
};

#define NUM_CUSTOM_GS_ACTORS 1

std::array<GSActor, NUM_CUSTOM_GS_ACTORS> customGSActors = {
  GSActor(SCENE_KOKIRI_FOREST, LINK_AGE_CHILD, RAND_INF_CGS_KF_LINKS_HOUSE, RC_CGS_KF_LINKS_HOUSE, {-160, 40, 1214}, {0, 0, 0}, 0xAD00),
};

void SpawnCustomGSActors() {
  ActorContext* actorCtx = &gPlayState->actorCtx;
  for (GSActor& gsActor : customGSActors) {
    if (gPlayState->sceneNum == gsActor.GetScene() && gSaveContext.linkAge == gsActor.GetAge()) {
      Actor* actor = Actor_SpawnEntry(actorCtx, gsActor.GetActorEntryPtr(), gPlayState);
      ObjectExtension::GetInstance().Set<CheckIdentity>(actor, std::move(gsActor.GetIdentity()));
    }
  }
}

void RegisterGSHooks() {
  COND_HOOK(OnSceneSpawnActors, IS_RANDO, SpawnCustomGSActors);
}

static RegisterShipInitFunc initFunc(RegisterGSHooks, { "IS_RANDO" });
