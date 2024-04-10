#pragma once

#include <array>
#include <unordered_map>
#include "randomizerTypes.h"
#include "item.h"
#include "location.h"

namespace Rando {
/**
 * @brief Singleton for storing and accessing static Randomizer-related data
 * 
 * The StaticData class is a class for storing and accessing static Randomizer-related data.
 * Static Data, in this context, refers to data that is the same for every single randomizer seed,
 * i.e. the item and location tables. This class is intended to be used as a Singleton.
 */
class StaticData {
    private:
      static std::array<Item, RG_MAX> itemTable;
      static std::array<Location, RC_MAX> locationTable;

    public:
      static void InitItemTable();
      static Item& RetrieveItem(const RandomizerGet rgid);
      static Item& ItemFromGIID(const int giid);
      static std::array<Item, RG_MAX>& GetItemTable();
      static void InitLocationTable();
      static Location* GetLocation(RandomizerCheck locKey);
      static std::array<Rando::Location, RC_MAX>& GetLocationTable();
      static std::vector<RandomizerCheck> overworldLocations;
      static std::vector<RandomizerCheck> dungeonRewardLocations;
      static std::vector<std::vector<RandomizerCheck>> shopLocationLists;
      static std::vector<RandomizerCheck> scrubLocations;
      static std::vector<RandomizerCheck> gossipStoneLocations;
      static std::vector<RandomizerCheck> staticHintLocations;
      static std::vector<RandomizerCheck> pondFishLocations;
      static std::vector<RandomizerCheck> overworldFishLocations;
      static std::array<std::pair<RandomizerCheck, RandomizerCheck>, 17> randomizerFishingPondFish;
      static std::unordered_map<int8_t, RandomizerCheck> randomizerGrottoFishMap;
      static std::vector<RandomizerHint> oldVerHintOrder;
      static uint16_t oldVerGossipStoneStart;
      static std::unordered_map<std::string, uint32_t> locationNameToEnum;
      static std::unordered_map<uint32_t, CustomMessage> hintNames;
      static std::unordered_map<std::string, uint32_t> hintNameToEnum;
      static std::unordered_map<uint32_t, CustomMessage> hintTypeNames;
      static std::unordered_map<std::string, uint32_t> hintTypeNameToEnum;
      static std::unordered_map<RandomizerCheck, RandomizerHint> gossipStoneCheckToHint;
      static std::unordered_map<uint32_t, RandomizerHintTextKey> areaNames;
      static std::unordered_map<std::string, uint32_t> areaNameToEnum;
      static std::unordered_map<uint32_t, RandomizerHintTextKey> trialNames;
      static std::unordered_map<std::string, uint32_t> trialNameToEnum;
      static std::unordered_map<RandomizerHint, StaticHintInfo> staticHintInfoMap;

      StaticData();
      ~StaticData();
};
}