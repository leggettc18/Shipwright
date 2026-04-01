#include "ActorSpawnData.h"
#include "soh/ObjectExtension/ObjectExtension.h"
#include "soh/Enhancements/game-interactor/GameInteractor.h"
#include "soh/ShipInit.hpp"

struct ActorSpawnParams {
  int16_t params;
};

static ObjectExtension::Register<ActorSpawnParams> ActorSpawnDataRegister;

int16_t GetActorSpawnData(const Actor* actor) {
  ActorSpawnParams* data = ObjectExtension::GetInstance().Get<ActorSpawnParams>(actor);
  if (data == nullptr) {
    return -1;
  }
  return data->params;
}

void SetActorSpawnData(const Actor* actor, int16_t params) {
  ObjectExtension::GetInstance().Set<ActorSpawnParams>(actor, { params });
}

void RegisterActorSpawnDataHooks() {
  COND_HOOK(OnActorSpawn, true, [](void* refActor) {
        Actor* actor = (Actor*) refActor;
        // #region SOH [ObjectExtension] ActorSpawnData tracking
        SetActorSpawnData(actor, actor->params);
        // #endregion
      });
}

static RegisterShipInitFunc initFunc(RegisterActorSpawnDataHooks);
