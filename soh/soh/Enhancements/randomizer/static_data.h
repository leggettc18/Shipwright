#pragma once

#include <array>
#include "randomizerTypes.h"
#include "item.h"
#include "location.h"
/**
 * @brief Singleton for storing and accessing static Randomizer-related data
 * 
 * The StaticData class is a class for storing and accessing static Randomizer-related data.
 * Static Data, in this context, refers to data that is the same for every single randomizer seed,
 * i.e. the item and location tables. This class is intended to be used as a Singleton.
 */
class StaticData {
    private:
      static std::array<RandoItem, RG_MAX> itemTable;
      static std::array<Rando::Location, RC_MAX> locationTable;

    public:
      static void InitItemTable();
      static void InitLocationTable();
      static RandoItem& RetrieveItem(const RandomizerGet rgid);
      static RandoItem& ItemFromGIID(const int giid);
      static std::array<RandoItem, RG_MAX>& GetItemTable();
      StaticData();
      ~StaticData();

};