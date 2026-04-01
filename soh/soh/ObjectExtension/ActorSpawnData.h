#ifndef ACTOR_SPAWN_DATA_H
#define ACTOR_SPAWN_DATA_H

#ifdef __cplusplus
extern "C" {
#endif
#include "z64actor.h"


int16_t GetActorSpawnData(const Actor* actor);
void SetActorSpawnData(const Actor* actor, int16_t params);

#ifdef __cplusplus
}
#endif
#endif // ACTOR_SPAWN_DATA_H
