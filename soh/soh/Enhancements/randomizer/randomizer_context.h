#pragma once

#include <array>
#include <string>
#include <unordered_set>
#include <nlohmann/json.hpp>

#include "randomizerTypes.h"

using json = nlohmann::json;

// Forward Declarations to avoid duplicate definition issues
enum SceneID : int;

class RandomizerContext {
  private:
    std::unordered_set<SceneID> masterQuestDungeons;
    std::array<uint8_t, (RG_SILVER_RUPEE_LAST - RG_SILVER_RUPEE_FIRST)> SilverRupeeCounts;
    std::array<uint8_t, (RG_SILVER_RUPEE_LAST - RG_SILVER_RUPEE_FIRST)> SilverRupeeTotals;
    static uint8_t GetSilverRupeeIndex(RandomizerGet silverRupeeRGID);
    
  public:
    RandomizerContext();
    void ParseMasterQuestDungeonsSpoiler(json jsonContext);

    /// <summary>
    ///     Initializes the Silver Rupee Totals array based on which Dungeons
    ///     have been designated as Master Quest. Requires the masterQuestDungeons
    ///     set to have already been populated with the desired data from a spoiler
    ///     or save file.
    /// </summary>
    void InitSilverRupeeTotals();

    /// <summary>
    ///     Checks if the given Scene ID corresponds to a Master Quest Dungeon.
    /// </summary>
    /// <param name="dungeonSceneID">A SceneID corresponding to a dungeon.</param>
    /// <returns>
    ///     True if the dungeon is a master quest dungeon, or false if the sceneID does
    ///     not correspond to a dungeon, or the dungeon it corresponds to is not a master
    ///     quest dungeon.
    /// </returns>
    bool IsDungeonMasterQuest(SceneID dungeon);

    /// <summary>
    ///     Adds the given Scene ID to the masterQuestDungeons set if it corresponds
    ///     to a dungeon.
    /// </summary>
    /// <param name="dungeon">A SceneID corresponding to a dungeon.</param>
    void SetDungeonMasterQuest(SceneID dungeon);

    /// <summary>
    ///     Clears the list of Master Quest Dungeons. Intended for use by the SaveManager,
    ///     should probably not be called during normal gameplay.
    /// </summary>
    void ClearMasterQuestDungeons();

    /// <summary>
    ///     Gets the number of dungeons that are designated as Master Quest.
    /// </summary>
    /// <returns>The number of dungeons designated as Master Quest.</returns>
    uint8_t MasterQuestDungeonsCount();

    /// <summary>
    /// For a given Silver Rupee RandomizerGet value, return whether or not the
    /// Silver Rupee Puzzle is complete. A Silver Rupee Puzzle is complete when the
    /// number of Silver Rupees collected matches the number of Silver Rupees in the
    /// Puzzle.
    /// </summary>
    /// <param name="silverRupeeRGID">
    ///     The RandomizerGet value corresponding to a Silver Rupee puzzle.
    ///     Can be the SILVER_RUPEE or SILVER_RUPEE_POUCH variant.
    /// </param>
    /// <returns>
    ///     True or False depending on whether or not the right amount of Silver Rupees has
    ///     been collected.
    /// </returns>
    bool IsSilverRupeePuzzleComplete(RandomizerGet silverRupeeRGID);

    /// <summary>
    ///     Gets the amount of Silver Rupees collected for the given Silver Rupee Puzzle's
    ///     RandomizerGet value.
    /// </summary>
    /// <param name="silverRupeeRGID">
    ///     The RandomizerGet value corresponding to a Silver Rupee puzzle.
    ///     Can be the SILVER_RUPEE or SILVER_RUPEE_POUCH variant.
    /// </param>
    /// <returns>The count of Silver Rupees collected for the given puzzle.</returns>
    uint8_t GetSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID);

    /// <summary>
    ///     Sets the amount of Silver Rupees collected for the given Silver Rupee Puzzle's
    ///     RandomizerGet value.
    /// 
    ///     Intended to be called by the SaveManager and SaveEditor, should probably not
    ///     be used during normal gameplay.
    /// </summary>
    /// <param name="silverRupeeRGID"></param>
    /// <returns>The new count of Silver Rupees collected for the given Puzzle.</returns>
    uint8_t SetSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID, uint8_t count);

    /// <summary>
    ///     Increments the Silver Rupee count for the given Silver Rupee Puzzle by one.
    /// </summary>
    /// <param name="silverRupeeRGID">
    ///     The RandomizerGet value corresponding to a Silver Rupee puzzle.
    ///     Can be the SILVER_RUPEE or SILVER_RUPEE_POUCH variant.
    /// </param>
    /// <returns>The new count of Silver Rupees Collected.</returns>
    uint8_t IncrementSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID);

    /// <summary>
    ///     Decrements the Silver Rupee count for the given Silver Rupee Puzzle by one.
    ///     This should probably not be called during normal gameplay, but it can be used
    ///     for i.e. the Save Editor.
    /// </summary>
    /// <param name="silverRupeeRGID">
    ///     The RandomizerGet value corresponding to a Silver Rupee puzzle.
    ///     Can be the SILVER_RUPEE or SILVER_RUPEE_POUCH variant.
    /// </param>
    /// <returns>The new count of Silver Rupees Collected.</returns>
    uint8_t DecrementSilverRupeePuzzleCount(RandomizerGet silverRupeeRGID);

    /// <summary>
    ///     Sets the Silver Rupee count for a given Silver Rupee Puzzle to the puzzle's
    ///     total number of Silver Rupees, thus completing the puzzle. Will be called
    ///     when a Silver Rupee Pouch is collected.
    /// </summary>
    /// <param name="silverRupeeRGID">
    ///     The RandomizerGet value corresponding to a Silver Rupee puzzle.
    ///     Can be the SILVER_RUPEE or SILVER_RUPEE_POUCH variant.
    /// </param>
    void CompleteSilverRupeePuzzle(RandomizerGet silverRupeeRGID);

    /// <summary>
    ///     Gets the Total number of Silver Rupees for a given Silver Rupee Puzzle.
    /// </summary>
    /// <param name="silverRupeeRGID">
    ///     The RandomizerGet value corresponding to a Silver Rupee puzzle.
    ///     Can be the SILVER_RUPEE or SILVER_RUPEE_POUCH variant.
    /// </param>
    /// <returns>The total number of Silver Rupees for that Puzzle.</returns>
    uint8_t GetSilverRupeePuzzleTotal(RandomizerGet silverRupeeRGID);

};