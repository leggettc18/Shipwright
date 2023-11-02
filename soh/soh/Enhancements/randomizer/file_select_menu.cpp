#include "file_select_menu.h"

#include "soh/OTRGlobals.h"
#include "randomizerTypes.h"

#include <array>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

typedef struct RandoFileSelectSetting {
    std::array<std::string, LANGUAGE_MAX> name;
    std::vector<std::array<std::string, LANGUAGE_MAX>> choices;
} RandoFileSelectSetting;

RandoFileSelectSetting RandoFileSelectOptions[4] = {
    {
        { "GENERATE FROM:", "GENERIEREN VON:", "GÉNÉRER À PARTIR DE:" },
        {
            { "Current Settings", "Aktuelle Einstellungen", "Réglages actuels" },
            { "Previous Seed", "Vorheriges Saatgut", "Graine précédente" },
            { "From Preset", "Von Voreinstellung", "De la présélection" }
        }
    },
    {
        { "OPEN SETTINGS:", "EINSTELLUNGEN ÖFFNEN:", "OUVRIR LES PARAMÈTRES" },
        {
            { "Open", "Öffnen Sie", "Ouvrir"},
            { "Generate", "Erzeugen", "Générer"}
        }
    },
    {
        { "SELECT SEED:", "SAATGUT AUSWÄHLEN:", "SELECTIONNER LA SEMENCE:"},
        {/*empty, populate with seeds present in Randomizer folder before displaying options*/}
    },
    {
        { "PRESET:", "PRESET:", "PRESET:"},
        {
            { "Default", "Standard", "Défaut" },
            { "Spock Race", "Spock-Rennen", "La course de Spock" },
            { "Spock Race - No Logic", "Spock-Rennen - Keine Logik", "Spock Race - Pas de logique" },
            { "S6 Tournament (Adapted)", "S6-Turnier (angepasst)", "S6 Tournoi (adapté)" },
            { "Hell Mode", "Höllenmodus", "Mode enfer" },
        }
    }
};

std::vector<std::filesystem::path> RandoFileSelectSpoilerFileNames = {};
std::vector<std::array<uint8_t, 5>> RandoFileHashes = {};

const char* Randomizer_GetFSSettingName(uint8_t optionIndex, uint8_t language) {
    return RandoFileSelectOptions[optionIndex].name[language].c_str();
}

const char* Randomizer_GetFSSettingChoiceName(uint8_t optionIndex, uint8_t choiceIndex, uint8_t language) {
    return RandoFileSelectOptions[optionIndex].choices[choiceIndex][language].c_str();
}

uint8_t Randomizer_GetFSSettingOptionsAmount(uint8_t optionIndex) {
    return RandoFileSelectOptions[optionIndex].choices.size();
}

bool CompareFileDates(std::filesystem::path file1, std::filesystem::path file2) {
    std::filesystem::file_time_type time1, time2;
    time1 = std::filesystem::last_write_time(file1);
    time2 = std::filesystem::last_write_time(file2);
    return time1 < time2;
}

std::string Sanitize(std::string stringValue) {
    // Add backslashes.
    for (auto i = stringValue.begin();;) {
        auto const pos =
            std::find_if(i, stringValue.end(), [](char const c) { return '\\' == c || '\'' == c || '"' == c; });
        if (pos == stringValue.end()) {
            break;
        }
        i = std::next(stringValue.insert(pos, '\\'), 2);
    }

    // Removes others.
    stringValue.erase(std::remove_if(stringValue.begin(), stringValue.end(),
                                     [](char const c) { return '\n' == c || '\r' == c || '\0' == c || '\x1A' == c; }),
                      stringValue.end());

    return stringValue;
}

void Randomizer_PopulateChoices() {
    RandoFileSelectSpoilerFileNames.clear();
    for (const auto& entry : std::filesystem::directory_iterator(LUS::Context::GetPathRelativeToAppBundle("Randomizer"))) {
        RandoFileSelectSpoilerFileNames.push_back(entry.path());
    }
    std::sort(RandoFileSelectSpoilerFileNames.begin(), RandoFileSelectSpoilerFileNames.end(), CompareFileDates);
    auto ctx = Rando::Context::GetInstance();
    int i = 0;
    for (auto& file : RandoFileSelectSpoilerFileNames) {
        std::filesystem::file_time_type time = std::filesystem::last_write_time(file);
        const std::time_t time_c = std::chrono::system_clock::to_time_t(std::chrono::clock_cast<std::chrono::system_clock>(time));
        std::stringstream fileDate;
        fileDate << std::put_time(std::localtime(&time_c), "%b %d, %Y");
        std::string date = fileDate.str();
        RandoFileSelectOptions[RFS_PREVIOUS_SEED].choices.push_back({ date, date, date });
        std::ifstream spoilerFileStream(Sanitize(file.string()));
        if (!spoilerFileStream) {
            return;
        }
        nlohmann::json spoilerFileJson;
        spoilerFileStream >> spoilerFileJson;
        ctx->ParseHashIconIndexesJson(spoilerFileJson);
        RandoFileHashes.push_back({});
        int j = 0;
        for (auto index : ctx->hashIconIndexes) {
            RandoFileHashes[i][j] = index;
            j++;
        }
        i++;
    }
}
