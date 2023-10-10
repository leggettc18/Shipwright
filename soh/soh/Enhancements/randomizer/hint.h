#pragma once

#include "3drando/text.hpp"
#include "randomizerTypes.h"

class RandoHint {
    public:
    RandoHint();
    RandoHint(Text text_);
    RandoHint(Text text_, RandomizerCheck hintedLocation_, HintType hintType_, Text hintedRegion_);
    const Text& GetText() const;
    RandomizerCheck GetHintedLocation();
    void SetHintedLocation (RandomizerCheck location);
    HintType GetHintType();
    void SetHintType (HintType type);
    std::string GetHintedRegion();
    void SetHintedRegion (Text region);
    bool IsAddedToPool();
    void AddToPool();

    private:
    Text text;
    RandomizerCheck hintedLocation;
    HintType hintType;
    Text hintedRegion;
    bool addedToPool;
};