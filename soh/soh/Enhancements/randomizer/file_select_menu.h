#pragma once

#include "variables.h"

#ifdef __cplusplus
extern "C" {
#endif
const char* Randomizer_GetFSSettingName(uint8_t optionIndex, uint8_t language);
const char* Randomizer_GetFSSettingChoiceName(uint8_t optionIndex, uint8_t choiceIndex, uint8_t language);
uint8_t Randomizer_GetFSSettingOptionsAmount(uint8_t optionIndex);

/**
 * @brief Call this sometime before the setting choices are displayed.
 * 
 * The purpose of this function is to populate the Previous Seeds list with the current
 * contents of the Randomizer folder, and eventually to add user-defined presets to the
 * Presets list.
 */
void Randomizer_PopulateChoices();
#ifdef __cplusplus
};
#endif