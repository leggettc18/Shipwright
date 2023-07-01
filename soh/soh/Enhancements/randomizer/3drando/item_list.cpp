#include "item_list.hpp"

#include "logic.hpp"
#include <array>
#include "z64item.h"
#include "../randomizerTypes.h"

using namespace Logic;

static std::array<Item, KEY_ENUM_MAX> itemTable;

void ItemTable_Init() { // RandomizerGet                              English name                       French Spanish
                        // Item Type       getItemID       advancement    logic           hint key
    itemTable[NONE] = Item(RG_NONE, Text{ "No Item", "Rien", "Sin Objeto" }, ITEMTYPE_EVENT, GI_RUPEE_GREEN, false,
                           &noVariable, NONE);
    itemTable[KOKIRI_SWORD] = Item(RG_KOKIRI_SWORD, Text{ "Kokiri Sword", "Épée Kokiri", "Espada Kokiri" },
                                   ITEMTYPE_ITEM, GI_SWORD_KOKIRI, true, &KokiriSword, KOKIRI_SWORD);
    //[MASTER_SWORD]
    itemTable[GIANTS_KNIFE] = Item(RG_GIANTS_KNIFE, Text{ "Giant's Knife", "Lame des Géants", "Espada de Biggoron" },
                                   ITEMTYPE_ITEM, GI_SWORD_KNIFE, false, &noVariable, GIANTS_KNIFE);
    itemTable[BIGGORON_SWORD] =
        Item(RG_BIGGORON_SWORD, Text{ "Biggoron's Sword", "Épée de Biggoron", "Espada de Biggoron" }, ITEMTYPE_ITEM,
             GI_SWORD_BGS, true, &BiggoronSword, BIGGORON_SWORD);
    itemTable[DEKU_SHIELD] = Item(RG_DEKU_SHIELD, Text{ "Deku Shield", "Bouclier Mojo", "Escudo deku" }, ITEMTYPE_ITEM,
                                  GI_SHIELD_DEKU, false, &noVariable, DEKU_SHIELD);
    itemTable[HYLIAN_SHIELD] = Item(RG_HYLIAN_SHIELD, Text{ "Hylian Shield", "Bouclier Hylien", "Escudo hyliano" },
                                    ITEMTYPE_ITEM, GI_SHIELD_HYLIAN, false, &noVariable, HYLIAN_SHIELD);
    itemTable[MIRROR_SHIELD] = Item(RG_MIRROR_SHIELD, Text{ "Mirror Shield", "Bouclier Miroir", "Escudo espejo" },
                                    ITEMTYPE_ITEM, GI_SHIELD_MIRROR, true, &MirrorShield, MIRROR_SHIELD);
    itemTable[GORON_TUNIC] = Item(RG_GORON_TUNIC, Text{ "Goron Tunic", "Tunique Goron", "Sayo goron" }, ITEMTYPE_ITEM,
                                  GI_TUNIC_GORON, true, &GoronTunic, GORON_TUNIC);
    itemTable[ZORA_TUNIC] = Item(RG_ZORA_TUNIC, Text{ "Zora Tunic", "Tunique Zora", "Sayo zora" }, ITEMTYPE_ITEM,
                                 GI_TUNIC_ZORA, true, &ZoraTunic, ZORA_TUNIC);
    itemTable[IRON_BOOTS] = Item(RG_IRON_BOOTS, Text{ "Iron Boots", "Bottes de plomb", "Botas de hierro" },
                                 ITEMTYPE_ITEM, GI_BOOTS_IRON, true, &IronBoots, IRON_BOOTS);
    itemTable[HOVER_BOOTS] = Item(RG_HOVER_BOOTS, Text{ "Hover Boots", "Bottes des airs", "Botas voladoras" },
                                  ITEMTYPE_ITEM, GI_BOOTS_HOVER, true, &HoverBoots, HOVER_BOOTS);

    itemTable[BOOMERANG] = Item(RG_BOOMERANG, Text{ "Boomerang", "Boomerang", "Búmeran" }, ITEMTYPE_ITEM, GI_BOOMERANG,
                                true, &Boomerang, BOOMERANG);
    itemTable[LENS_OF_TRUTH] = Item(RG_LENS_OF_TRUTH, Text{ "Lens of Truth", "Monocle de Vérité", "Lupa de la Verdad" },
                                    ITEMTYPE_ITEM, GI_LENS, true, &LensOfTruth, LENS_OF_TRUTH);
    itemTable[MEGATON_HAMMER] =
        Item(RG_MEGATON_HAMMER, Text{ "Megaton Hammer", "Masse des Titans", "Martillo Megatón" }, ITEMTYPE_ITEM,
             GI_HAMMER, true, &Hammer, MEGATON_HAMMER);
    itemTable[STONE_OF_AGONY] =
        Item(RG_STONE_OF_AGONY, Text{ "Stone of Agony", "Pierre de Souffrance", "Piedra de la Agonía" }, ITEMTYPE_ITEM,
             GI_STONE_OF_AGONY, true, &ShardOfAgony, STONE_OF_AGONY);
    itemTable[DINS_FIRE] = Item(RG_DINS_FIRE, Text{ "Din's Fire", "Feu de Din", "Fuego de Din" }, ITEMTYPE_ITEM,
                                GI_DINS_FIRE, true, &DinsFire, DINS_FIRE);
    itemTable[FARORES_WIND] = Item(RG_FARORES_WIND, Text{ "Farore's Wind", "Vent de Farore", "Viento de Farore" },
                                   ITEMTYPE_ITEM, GI_FARORES_WIND, true, &FaroresWind, FARORES_WIND);
    itemTable[NAYRUS_LOVE] = Item(RG_NAYRUS_LOVE, Text{ "Nayru's Love", "Amour de Nayru", "Amor de Nayru" },
                                  ITEMTYPE_ITEM, GI_NAYRUS_LOVE, true, &NayrusLove, NAYRUS_LOVE);
    itemTable[FIRE_ARROWS] = Item(RG_FIRE_ARROWS, Text{ "Fire Arrow", "Flèche de Feu", "Flecha de fuego" },
                                  ITEMTYPE_ITEM, GI_ARROW_FIRE, true, &FireArrows, FIRE_ARROWS);
    itemTable[ICE_ARROWS] = Item(RG_ICE_ARROWS, Text{ "Ice Arrow", "Flèche de Glace", "Flecha de hielo" },
                                 ITEMTYPE_ITEM, GI_ARROW_ICE, true, &IceArrows, ICE_ARROWS);
    itemTable[LIGHT_ARROWS] = Item(RG_LIGHT_ARROWS, Text{ "Light Arrow", "Flèche de Lumière", "Flecha de luz" },
                                   ITEMTYPE_ITEM, GI_ARROW_LIGHT, true, &LightArrows, LIGHT_ARROWS);
    itemTable[GERUDO_MEMBERSHIP_CARD] =
        Item(RG_GERUDO_MEMBERSHIP_CARD, Text{ "Gerudo Membership Card", "Carte Gerudo", "Pase de socio gerudo" },
             ITEMTYPE_ITEM, GI_GERUDO_CARD, true, &GerudoToken, GERUDO_MEMBERSHIP_CARD);
    itemTable[MAGIC_BEAN] = Item(RG_MAGIC_BEAN, Text{ "Magic Bean", "Haricots Magiques", "Habichuelas mágicas" },
                                 ITEMTYPE_ITEM, GI_BEAN, true, &MagicBean, MAGIC_BEAN);
    itemTable[MAGIC_BEAN_PACK] = Item(
        RG_MAGIC_BEAN_PACK, Text{ "Magic Bean Pack", "Paquet de Haricots Magiques", "Lote de habichuelas mágicas" },
        ITEMTYPE_ITEM, 0xC9, true, &MagicBeanPack, MAGIC_BEAN_PACK);
    itemTable[DOUBLE_DEFENSE] =
        Item(RG_DOUBLE_DEFENSE, Text{ "Double Defense", "Double Défence", "Doble poder defensivo" }, ITEMTYPE_ITEM,
             0xB8, true, &DoubleDefense, DOUBLE_DEFENSE);

    itemTable[WEIRD_EGG] = Item(RG_WEIRD_EGG, Text{ "Weird Egg", "Oeuf Curieux", "Huevo extraño" }, ITEMTYPE_ITEM,
                                GI_WEIRD_EGG, true, &WeirdEgg, WEIRD_EGG);
    //  itemTable[CUCCO]                             = Item(RG_CUCCO,                             Text{"Cucco",
    //  "Cocotte",                          "Cuco"},                                    ITEMTYPE_ITEM,  GI_CUCCO, true,
    //  &Cucco,         CUCCO);
    itemTable[ZELDAS_LETTER] = Item(RG_ZELDAS_LETTER, Text{ "Zelda's Letter", "Lettre de Zelda", "Carta de Zelda" },
                                    ITEMTYPE_ITEM, GI_LETTER_ZELDA, true, &ZeldasLetter, ZELDAS_LETTER);
    //  itemTable[KEATON_MASK]                       = Item(RG_KEATON_MASK,                       Text{"Keaton Mask",
    //  "Masque du Renard",                 "Careta de Keaton"},                        ITEMTYPE_ITEM,  GI_MASK_KEATON,
    //  true,       &KeatonMask,    KEATON_MASK); itemTable[SKULL_MASK]                        = Item(RG_SKULL_MASK,
    //  Text{"Skull Mask",                      "Masque de Mort",                   "Máscara de calavera"},
    //  ITEMTYPE_ITEM,  GI_MASK_SKULL,     true,       &SkullMask,     SKULL_MASK); itemTable[SPOOKY_MASK] =
    //  Item(RG_SPOOKY_MASK,                       Text{"Spooky Mask",                     "Masque d'Effroi", "Máscara
    //  tenebrosa"},                       ITEMTYPE_ITEM,  GI_MASK_SPOOKY,    true,       &SpookyMask,    SPOOKY_MASK);
    //  itemTable[BUNNY_HOOD]                        = Item(RG_BUNNY_HOOD,                        Text{"Bunny Hood",
    //  "Masque du Lapin",                  "Capucha de conejo"},                       ITEMTYPE_ITEM,  GI_MASK_BUNNY,
    //  true,       &BunnyHood,     BUNNY_HOOD); itemTable[GORON_MASK]                        = Item(RG_GORON_MASK,
    //  Text{"Goron Mask",                      "Masque de Goron",                  "Máscara Goron"}, ITEMTYPE_ITEM,
    //  GI_MASK_GORON,     true,       &GoronMask,     GORON_MASK); itemTable[ZORA_MASK]                         =
    //  Item(RG_ZORA_MASK,                         Text{"Zora Mask",                       "Masque de Zora", "Máscara
    //  Zora"},                            ITEMTYPE_ITEM,  GI_MASK_ZORA,      true,       &ZoraMask,      ZORA_MASK);
    //  itemTable[GERUDO_MASK]                       = Item(RG_GERUDO_MASK,                       Text{"Gerudo Mask",
    //  "Masque de Gerudo",                 "Máscara Gerudo"},                          ITEMTYPE_ITEM,  GI_MASK_GERUDO,
    //  true,       &GerudoMask,    GERUDO_MASK); itemTable[MASK_OF_TRUTH]                     = Item(RG_MASK_OF_TRUTH,
    //  Text{"Mask of Truth",                   "Masque de Vérité",                 "Máscara de la Verdad"},
    //  ITEMTYPE_ITEM,  GI_MASK_MASK,      true,       &MaskofTruth,   MASK_OF_TRUTH);
    itemTable[POCKET_EGG] = Item(RG_POCKET_EGG, Text{ "Pocket Egg", "Oeuf de poche", "Huevo de bolsillo" },
                                 ITEMTYPE_ITEM, GI_POCKET_EGG, true, &PocketEgg, POCKET_EGG);
    //  itemTable[POCKET_CUCCO]                      = Item(RG_POCKET_CUCCO,                      Text{"Pocket Cucco",
    //  "Cocotte de poche",                 "Cuco de bolsillo"},                        ITEMTYPE_ITEM,  GI_POCKET_CUCCO,
    //  true,       &PocketCucco,   POCKET_CUCCO);
    itemTable[COJIRO] =
        Item(RG_COJIRO, Text{ "Cojiro", "P'tit Poulet", "Cojiro" }, ITEMTYPE_ITEM, GI_COJIRO, true, &Cojiro, COJIRO);
    itemTable[ODD_MUSHROOM] = Item(RG_ODD_MUSHROOM, Text{ "Odd Mushroom", "Champignon Suspect", "Champiñón extraño" },
                                   ITEMTYPE_ITEM, GI_ODD_MUSHROOM, true, &OddMushroom, ODD_MUSHROOM);
    itemTable[ODD_POTION] = Item(RG_ODD_POTION, Text{ "Odd Potion", "Mixture Suspecte", "Medicina rara" },
                                 ITEMTYPE_ITEM, GI_ODD_POTION, true, &OddPoultice, ODD_POTION);
    itemTable[POACHERS_SAW] = Item(RG_POACHERS_SAW, Text{ "Poacher's Saw", "Scie du Chasseur", "Sierra del furtivo" },
                                   ITEMTYPE_ITEM, GI_SAW, true, &PoachersSaw, POACHERS_SAW);
    itemTable[BROKEN_SWORD] =
        Item(RG_BROKEN_SWORD, Text{ "Broken Goron's Sword", "Épée Brisée de Goron", "Espada goron rota" },
             ITEMTYPE_ITEM, GI_SWORD_BROKEN, true, &BrokenSword, BROKEN_SWORD);
    itemTable[PRESCRIPTION] = Item(RG_PRESCRIPTION, Text{ "Prescription", "Ordonnance", "Receta" }, ITEMTYPE_ITEM,
                                   GI_PRESCRIPTION, true, &Prescription, PRESCRIPTION);
    itemTable[EYEBALL_FROG] =
        Item(RG_EYEBALL_FROG, Text{ "Eyeball Frog", "Crapaud-qui-louche", "Rana de ojos saltones" }, ITEMTYPE_ITEM,
             GI_FROG, true, &EyeballFrog, EYEBALL_FROG);
    itemTable[EYEDROPS] = Item(RG_EYEDROPS, Text{ "World's Finest Eyedrops", "Super Gouttes", "Supergotas oculares" },
                               ITEMTYPE_ITEM, GI_EYEDROPS, true, &Eyedrops, EYEDROPS);
    itemTable[CLAIM_CHECK] = Item(RG_CLAIM_CHECK, Text{ "Claim Check", "Certificat", "Recibo" }, ITEMTYPE_ITEM,
                                  GI_CLAIM_CHECK, true, &ClaimCheck, CLAIM_CHECK);

    itemTable[GOLD_SKULLTULA_TOKEN] =
        Item(RG_GOLD_SKULLTULA_TOKEN,
             Text{ "Gold Skulltula Token", "Symbole de Skulltula d'Or", "Símbolo de skulltula dorada" }, ITEMTYPE_TOKEN,
             GI_SKULL_TOKEN, true, &GoldSkulltulaTokens, GOLD_SKULLTULA_TOKEN);

    // Progression Items
    itemTable[PROGRESSIVE_HOOKSHOT] =
        Item(RG_PROGRESSIVE_HOOKSHOT, Text{ "Progressive Hookshot", "Grappin (prog.)", "Gancho progresivo" },
             ITEMTYPE_ITEM, 0x80, true, &ProgressiveHookshot, PROGRESSIVE_HOOKSHOT);
    itemTable[PROGRESSIVE_STRENGTH] =
        Item(RG_PROGRESSIVE_STRENGTH,
             Text{ "Progressive Strength Upgrade", "Amélioration de Force (prog.)", "Fuerza progresiva" },
             ITEMTYPE_ITEM, 0x81, true, &ProgressiveStrength, PROGRESSIVE_STRENGTH);
    itemTable[PROGRESSIVE_BOMB_BAG] = Item(
        RG_PROGRESSIVE_BOMB_BAG, Text{ "Progressive Bomb Bag", "Sac de Bombes (prog.)", "Saco de bombas progresivo" },
        ITEMTYPE_ITEM, 0x82, true, &ProgressiveBombBag, PROGRESSIVE_BOMB_BAG);
    itemTable[PROGRESSIVE_BOW] = Item(RG_PROGRESSIVE_BOW, Text{ "Progressive Bow", "Arc (prog.)", "Arco progresivo" },
                                      ITEMTYPE_ITEM, 0x83, true, &ProgressiveBow, PROGRESSIVE_BOW);
    itemTable[PROGRESSIVE_SLINGSHOT] =
        Item(RG_PROGRESSIVE_SLINGSHOT, Text{ "Progressive Slingshot", "Lance-Pierre (prog.)", "Resortera progresiva" },
             ITEMTYPE_ITEM, 0x84, true, &ProgressiveBulletBag, PROGRESSIVE_SLINGSHOT);
    itemTable[PROGRESSIVE_WALLET] =
        Item(RG_PROGRESSIVE_WALLET, Text{ "Progressive Wallet", "Bourse (prog.)", "Bolsa de rupias progresiva" },
             ITEMTYPE_ITEM, 0x85, true, &ProgressiveWallet, PROGRESSIVE_WALLET);
    itemTable[PROGRESSIVE_SCALE] =
        Item(RG_PROGRESSIVE_SCALE, Text{ "Progressive Scale", "Écaille (prog.)", "Escama progresiva" }, ITEMTYPE_ITEM,
             0x86, true, &ProgressiveScale, PROGRESSIVE_SCALE);
    itemTable[PROGRESSIVE_NUT_UPGRADE] =
        Item(RG_PROGRESSIVE_NUT_UPGRADE,
             Text{ "Progressive Nut Capacity", "Capacité de Noix (prog.)", "Capacidad de nueces deku progresiva" },
             ITEMTYPE_ITEM, 0x87, false, &noVariable, PROGRESSIVE_NUT_UPGRADE);
    itemTable[PROGRESSIVE_STICK_UPGRADE] =
        Item(RG_PROGRESSIVE_STICK_UPGRADE,
             Text{ "Progressive Stick Capacity", "Capacité de Bâtons (prog.)", "Capacidad de palos deku progresiva" },
             ITEMTYPE_ITEM, 0x88, false, &noVariable, PROGRESSIVE_STICK_UPGRADE);
    itemTable[PROGRESSIVE_BOMBCHUS] =
        Item(RG_PROGRESSIVE_BOMBCHUS, Text{ "Progressive Bombchu", "Missiles (prog.)", "Bombchus progresivos" },
             ITEMTYPE_ITEM, 0x89, true, &Bombchus, PROGRESSIVE_BOMBCHUS);
    itemTable[PROGRESSIVE_MAGIC_METER] =
        Item(RG_PROGRESSIVE_MAGIC_METER,
             Text{ "Progressive Magic Meter", "Jauge de Magie (prog.)", "Poder mágico progresivo" }, ITEMTYPE_ITEM,
             0x8A, true, &ProgressiveMagic, PROGRESSIVE_MAGIC_METER);
    itemTable[PROGRESSIVE_OCARINA] =
        Item(RG_PROGRESSIVE_OCARINA, Text{ "Progressive Ocarina", "Ocarina (prog.)", "Ocarina progresiva" },
             ITEMTYPE_ITEM, 0x8B, true, &ProgressiveOcarina, PROGRESSIVE_OCARINA);
    itemTable[PROGRESSIVE_GORONSWORD] = Item(
        RG_PROGRESSIVE_GORONSWORD, Text{ "Progressive Goron Sword", "Épée Goron (prog.)", "Espada Goron progresiva" },
        ITEMTYPE_ITEM, 0xD4, true, &ProgressiveGiantKnife, PROGRESSIVE_GORONSWORD);

    // Bottles
    itemTable[EMPTY_BOTTLE] = Item(RG_EMPTY_BOTTLE, Text{ "Empty Bottle", "Bouteille Vide", "Botella vacía" },
                                   ITEMTYPE_ITEM, 0x0F, true, &Bottles, EMPTY_BOTTLE);
    itemTable[BOTTLE_WITH_MILK] =
        Item(RG_BOTTLE_WITH_MILK, Text{ "Bottle with Milk", "Bouteille avec du Lait", "Botella de leche Lon Lon" },
             ITEMTYPE_ITEM, 0x14, true, &Bottles, BOTTLE_WITH_MILK);
    itemTable[BOTTLE_WITH_RED_POTION] =
        Item(RG_BOTTLE_WITH_RED_POTION,
             Text{ "Bottle with Red Potion", "Bouteille avec une Potion Rouge", "Botella de poción roja" },
             ITEMTYPE_ITEM, 0x8C, true, &Bottles, BOTTLE_WITH_RED_POTION);
    itemTable[BOTTLE_WITH_GREEN_POTION] =
        Item(RG_BOTTLE_WITH_GREEN_POTION,
             Text{ "Bottle with Green Potion", "Bouteille avec une Potion Verte", "Botella de poción verde" },
             ITEMTYPE_ITEM, 0x8D, true, &Bottles, BOTTLE_WITH_GREEN_POTION);
    itemTable[BOTTLE_WITH_BLUE_POTION] =
        Item(RG_BOTTLE_WITH_BLUE_POTION,
             Text{ "Bottle with Blue Potion", "Bouteille avec une Potion Bleue", "Botella de poción azul" },
             ITEMTYPE_ITEM, 0x8E, true, &Bottles, BOTTLE_WITH_BLUE_POTION);
    itemTable[BOTTLE_WITH_FAIRY] =
        Item(RG_BOTTLE_WITH_FAIRY, Text{ "Bottle with Fairy", "Bouteille avec une Fée", "Hada en una botella" },
             ITEMTYPE_ITEM, 0x8F, true, &Bottles, BOTTLE_WITH_FAIRY);
    itemTable[BOTTLE_WITH_FISH] =
        Item(RG_BOTTLE_WITH_FISH, Text{ "Bottle with Fish", "Bouteille avec un Poisson", "Pez en una botella" },
             ITEMTYPE_ITEM, 0x90, true, &Bottles, BOTTLE_WITH_FISH);
    itemTable[BOTTLE_WITH_BLUE_FIRE] =
        Item(RG_BOTTLE_WITH_BLUE_FIRE,
             Text{ "Bottle with Blue Fire", "Bouteille avec une Flamme Bleue", "Botella de fuego azul" }, ITEMTYPE_ITEM,
             0x91, true, &Bottles, BOTTLE_WITH_BLUE_FIRE);
    itemTable[BOTTLE_WITH_BUGS] =
        Item(RG_BOTTLE_WITH_BUGS, Text{ "Bottle with Bugs", "Bouteille avec des Insectes", "Insecto en una botella" },
             ITEMTYPE_ITEM, 0x92, true, &Bottles, BOTTLE_WITH_BUGS);
    itemTable[BOTTLE_WITH_POE] =
        Item(RG_BOTTLE_WITH_POE, Text{ "Bottle with Poe", "Bouteille avec un Esprit", "Poe en una botella" },
             ITEMTYPE_ITEM, 0x94, true, &Bottles, BOTTLE_WITH_POE);

    // Special bottles that can't immediately dump contents
    itemTable[RUTOS_LETTER] =
        Item(RG_RUTOS_LETTER, Text{ "Bottle with Ruto's Letter", "Bouteille avec la Lettre de Ruto", "Carta de Ruto" },
             ITEMTYPE_ITEM, 0x15, true, &RutosLetter, RUTOS_LETTER);
    itemTable[BOTTLE_WITH_BIG_POE] =
        Item(RG_BOTTLE_WITH_BIG_POE, Text{ "Bottle with Big Poe", "Bouteille avec une Âme", "Gran Poe en una botella" },
             ITEMTYPE_ITEM, 0x93, true, &BottleWithBigPoe, BOTTLE_WITH_BIG_POE);

    // Songs
    itemTable[ZELDAS_LULLABY] = Item(RG_ZELDAS_LULLABY, Text{ "Zelda's Lullaby", "Berceuse de Zelda", "Nana de Zelda" },
                                     ITEMTYPE_SONG, 0xC1, true, &ZeldasLullaby, ZELDAS_LULLABY);
    itemTable[EPONAS_SONG] = Item(RG_EPONAS_SONG, Text{ "Epona's Song", "Chant d'Épona", "Canción de Epona" },
                                  ITEMTYPE_SONG, 0xC2, true, &EponasSong, EPONAS_SONG);
    itemTable[SARIAS_SONG] = Item(RG_SARIAS_SONG, Text{ "Saria's Song", "Chant de Saria", "Canción de Saria" },
                                  ITEMTYPE_SONG, 0xC3, true, &SariasSong, SARIAS_SONG);
    itemTable[SUNS_SONG] = Item(RG_SUNS_SONG, Text{ "Sun's Song", "Chant du Soleil", "Canción del Sol" }, ITEMTYPE_SONG,
                                0xC4, true, &SunsSong, SUNS_SONG);
    itemTable[SONG_OF_TIME] = Item(RG_SONG_OF_TIME, Text{ "Song of Time", "Chant du Temps", "Canción del tiempo" },
                                   ITEMTYPE_SONG, 0xC5, true, &SongOfTime, SONG_OF_TIME);
    itemTable[SONG_OF_STORMS] =
        Item(RG_SONG_OF_STORMS, Text{ "Song of Storms", "Chant des Tempêtes", "Canción de la tormenta" }, ITEMTYPE_SONG,
             0xC6, true, &SongOfStorms, SONG_OF_STORMS);
    itemTable[MINUET_OF_FOREST] =
        Item(RG_MINUET_OF_FOREST, Text{ "Minuet of Forest", "Menuet des Bois", "Minueto del bosque" }, ITEMTYPE_SONG,
             0xBB, true, &MinuetOfForest, MINUET_OF_FOREST);
    itemTable[BOLERO_OF_FIRE] = Item(RG_BOLERO_OF_FIRE, Text{ "Bolero of Fire", "Boléro du Feu", "Bolero del fuego" },
                                     ITEMTYPE_SONG, 0xBC, true, &BoleroOfFire, BOLERO_OF_FIRE);
    itemTable[SERENADE_OF_WATER] =
        Item(RG_SERENADE_OF_WATER, Text{ "Serenade of Water", "Sérénade de l'Eau", "Serenata del agua" }, ITEMTYPE_SONG,
             0xBD, true, &SerenadeOfWater, SERENADE_OF_WATER);
    itemTable[REQUIEM_OF_SPIRIT] =
        Item(RG_REQUIEM_OF_SPIRIT, Text{ "Requiem of Spirit", "Requiem des Esprits", "Réquiem del espíritu" },
             ITEMTYPE_SONG, 0xBE, true, &RequiemOfSpirit, REQUIEM_OF_SPIRIT);
    itemTable[NOCTURNE_OF_SHADOW] =
        Item(RG_NOCTURNE_OF_SHADOW, Text{ "Nocturne of Shadow", "Nocturne de l'Ombre", "Nocturno de la sombra" },
             ITEMTYPE_SONG, 0xBF, true, &NocturneOfShadow, NOCTURNE_OF_SHADOW);
    itemTable[PRELUDE_OF_LIGHT] =
        Item(RG_PRELUDE_OF_LIGHT, Text{ "Prelude of Light", "Prélude de la Lumière", "Preludio de la luz" },
             ITEMTYPE_SONG, 0xC0, true, &PreludeOfLight, PRELUDE_OF_LIGHT);

    // Maps and Compasses
    itemTable[DEKU_TREE_MAP] =
        Item(RG_DEKU_TREE_MAP, Text{ "Great Deku Tree Map", "Carte de l'Arbre Mojo", "Mapa del Gran Árbol Deku" },
             ITEMTYPE_MAP, 0xA5, false, &noVariable, DEKU_TREE_MAP);
    itemTable[DODONGOS_CAVERN_MAP] =
        Item(RG_DODONGOS_CAVERN_MAP,
             Text{ "Dodongo's Cavern Map", "Carte de la Caverne Dodongo", "Mapa de la Cueva de los Dodongos" },
             ITEMTYPE_MAP, 0xA6, false, &noVariable, DODONGOS_CAVERN_MAP);
    itemTable[JABU_JABUS_BELLY_MAP] =
        Item(RG_JABU_JABUS_BELLY_MAP,
             Text{ "Jabu-Jabu's Belly Map", "Carte du Ventre de Jabu-Jabu", "Mapa de la tripa de Jabu-Jabu" },
             ITEMTYPE_MAP, 0xA7, false, &noVariable, JABU_JABUS_BELLY_MAP);
    itemTable[FOREST_TEMPLE_MAP] = Item(
        RG_FOREST_TEMPLE_MAP, Text{ "Forest Temple Map", "Carte du Temple de la Forêt", "Mapa del Templo del Bosque" },
        ITEMTYPE_MAP, 0xA8, false, &noVariable, FOREST_TEMPLE_MAP);
    itemTable[FIRE_TEMPLE_MAP] =
        Item(RG_FIRE_TEMPLE_MAP, Text{ "Fire Temple Map", "Carte du Temple du Feu", "Mapa del Templo del Fuego" },
             ITEMTYPE_MAP, 0xA9, false, &noVariable, FIRE_TEMPLE_MAP);
    itemTable[WATER_TEMPLE_MAP] =
        Item(RG_WATER_TEMPLE_MAP, Text{ "Water Temple Map", "Carte du Temple de l'Eau", "Mapa del Templo del Agua" },
             ITEMTYPE_MAP, 0xAA, false, &noVariable, WATER_TEMPLE_MAP);
    itemTable[SPIRIT_TEMPLE_MAP] =
        Item(RG_SPIRIT_TEMPLE_MAP,
             Text{ "Spirit Temple Map", "Carte du Temple de l'Esprit", "Mapa del Templo del Espíritu" }, ITEMTYPE_MAP,
             0xAB, false, &noVariable, SPIRIT_TEMPLE_MAP);
    itemTable[SHADOW_TEMPLE_MAP] = Item(
        RG_SHADOW_TEMPLE_MAP, Text{ "Shadow Temple Map", "Carte du Temple de l'Ombre", "Mapa del Templo de la Sombra" },
        ITEMTYPE_MAP, 0xAC, false, &noVariable, SHADOW_TEMPLE_MAP);
    itemTable[BOTTOM_OF_THE_WELL_MAP] =
        Item(RG_BOTTOM_OF_THE_WELL_MAP, Text{ "Bottom of the Well Map", "Carte du Puits", "Mapa del fondo del pozo" },
             ITEMTYPE_MAP, 0xAD, false, &noVariable, BOTTOM_OF_THE_WELL_MAP);
    itemTable[ICE_CAVERN_MAP] =
        Item(RG_ICE_CAVERN_MAP, Text{ "Ice Cavern Map", "Carte de la Caverne Polaire", "Mapa de la caverna de hielo" },
             ITEMTYPE_MAP, 0xAE, false, &noVariable, ICE_CAVERN_MAP);

    itemTable[DEKU_TREE_COMPASS] =
        Item(RG_DEKU_TREE_COMPASS,
             Text{ "Great Deku Tree Compass", "Boussole de l'Arbre Mojo", "Brújula del Gran Árbol Deku" },
             ITEMTYPE_COMPASS, 0x9B, false, &noVariable, DEKU_TREE_COMPASS);
    itemTable[DODONGOS_CAVERN_COMPASS] = Item(
        RG_DODONGOS_CAVERN_COMPASS,
        Text{ "Dodongo's Cavern Compass", "Boussole de la Caverne Dodongo", "Brújula de la Cueva de los Dodongos" },
        ITEMTYPE_COMPASS, 0x9C, false, &noVariable, DODONGOS_CAVERN_COMPASS);
    itemTable[JABU_JABUS_BELLY_COMPASS] =
        Item(RG_JABU_JABUS_BELLY_COMPASS,
             Text{ "Jabu-Jabu's Belly Compass", "Boussole du Ventre de Jabu-Jabu", "Brújula de la tripa de Jabu-Jabu" },
             ITEMTYPE_COMPASS, 0x9D, false, &noVariable, JABU_JABUS_BELLY_COMPASS);
    itemTable[FOREST_TEMPLE_COMPASS] =
        Item(RG_FOREST_TEMPLE_COMPASS,
             Text{ "Forest Temple Compass", "Boussole du Temple de la Forêt", "Brújula del Templo del Bosque" },
             ITEMTYPE_COMPASS, 0x9E, false, &noVariable, FOREST_TEMPLE_COMPASS);
    itemTable[FIRE_TEMPLE_COMPASS] =
        Item(RG_FIRE_TEMPLE_COMPASS,
             Text{ "Fire Temple Compass", "Boussole du Temple du Feu", "Brújula del Templo del Fuego" },
             ITEMTYPE_COMPASS, 0x9F, false, &noVariable, FIRE_TEMPLE_COMPASS);
    itemTable[WATER_TEMPLE_COMPASS] =
        Item(RG_WATER_TEMPLE_COMPASS,
             Text{ "Water Temple Compass", "Boussole du Temple de l'Eau", "Brújula del Templo del Agua" },
             ITEMTYPE_COMPASS, 0xA0, false, &noVariable, WATER_TEMPLE_COMPASS);
    itemTable[SPIRIT_TEMPLE_COMPASS] =
        Item(RG_SPIRIT_TEMPLE_COMPASS,
             Text{ "Spirit Temple Compass", "Boussole du Temple de l'Esprit", "Brújula del Templo del Espíritu" },
             ITEMTYPE_COMPASS, 0xA1, false, &noVariable, SPIRIT_TEMPLE_COMPASS);
    itemTable[SHADOW_TEMPLE_COMPASS] =
        Item(RG_SHADOW_TEMPLE_COMPASS,
             Text{ "Shadow Temple Compass", "Boussole du Temple de l'Ombre", "Brújula del Templo de las Sombras" },
             ITEMTYPE_COMPASS, 0xA2, false, &noVariable, SHADOW_TEMPLE_COMPASS);
    itemTable[BOTTOM_OF_THE_WELL_COMPASS] =
        Item(RG_BOTTOM_OF_THE_WELL_COMPASS,
             Text{ "Bottom of the Well Compass", "Boussole du Puits", "Brújula del fondo del pozo" }, ITEMTYPE_COMPASS,
             0xA3, false, &noVariable, BOTTOM_OF_THE_WELL_COMPASS);
    itemTable[ICE_CAVERN_COMPASS] =
        Item(RG_ICE_CAVERN_COMPASS,
             Text{ "Ice Cavern Compass", "Boussole de la Caverne Polaire", "Brújula de la caverna de hielo" },
             ITEMTYPE_COMPASS, 0xA4, false, &noVariable, ICE_CAVERN_COMPASS);

    // Boss Keys
    itemTable[FOREST_TEMPLE_BOSS_KEY] =
        Item(RG_FOREST_TEMPLE_BOSS_KEY,
             Text{ "Forest Temple Boss Key", "Clé d'Or du Temple de la Forêt", "Gran llave del Templo del Bosque" },
             ITEMTYPE_BOSSKEY, 0x95, true, &BossKeyForestTemple, FOREST_TEMPLE_BOSS_KEY);
    itemTable[FIRE_TEMPLE_BOSS_KEY] =
        Item(RG_FIRE_TEMPLE_BOSS_KEY,
             Text{ "Fire Temple Boss Key", "Clé d'Or du Temple du Feu", "Gran llave del Templo del Fuego" },
             ITEMTYPE_BOSSKEY, 0x96, true, &BossKeyFireTemple, FIRE_TEMPLE_BOSS_KEY);
    itemTable[WATER_TEMPLE_BOSS_KEY] =
        Item(RG_WATER_TEMPLE_BOSS_KEY,
             Text{ "Water Temple Boss Key", "Clé d'Or du Temple de l'Eau", "Gran llave del Templo del Agua" },
             ITEMTYPE_BOSSKEY, 0x97, true, &BossKeyWaterTemple, WATER_TEMPLE_BOSS_KEY);
    itemTable[SPIRIT_TEMPLE_BOSS_KEY] =
        Item(RG_SPIRIT_TEMPLE_BOSS_KEY,
             Text{ "Spirit Temple Boss Key", "Clé d'Or du Temple de l'Esprit", "Gran llave del Templo del Espíritu" },
             ITEMTYPE_BOSSKEY, 0x98, true, &BossKeySpiritTemple, SPIRIT_TEMPLE_BOSS_KEY);
    itemTable[SHADOW_TEMPLE_BOSS_KEY] =
        Item(RG_SHADOW_TEMPLE_BOSS_KEY,
             Text{ "Shadow Temple Boss Key", "Clé d'Or du Temple de l'Ombre", "Gran llave del Templo de las Sombras" },
             ITEMTYPE_BOSSKEY, 0x99, true, &BossKeyShadowTemple, SHADOW_TEMPLE_BOSS_KEY);
    itemTable[GANONS_CASTLE_BOSS_KEY] =
        Item(RG_GANONS_CASTLE_BOSS_KEY,
             Text{ "Ganon's Castle Boss Key", "Clé d'Or du Château de Ganon", "Gran llave del Castillo de Ganon" },
             ITEMTYPE_BOSSKEY, 0x9A, true, &BossKeyGanonsCastle, GANONS_CASTLE_BOSS_KEY);

    // Small Keys
    itemTable[FOREST_TEMPLE_SMALL_KEY] =
        Item(RG_FOREST_TEMPLE_SMALL_KEY,
             Text{ "Forest Temple Small Key", "Petite Clé du Temple de la Forêt", "Llave del Templo del Bosque" },
             ITEMTYPE_SMALLKEY, 0xAF, true, &ForestTempleKeys, FOREST_TEMPLE_SMALL_KEY);
    itemTable[FIRE_TEMPLE_SMALL_KEY] =
        Item(RG_FIRE_TEMPLE_SMALL_KEY,
             Text{ "Fire Temple Small Key", "Petite Clé du Temple du Feu", "Llave del Templo del Fuego" },
             ITEMTYPE_SMALLKEY, 0xB0, true, &FireTempleKeys, FIRE_TEMPLE_SMALL_KEY);
    itemTable[WATER_TEMPLE_SMALL_KEY] =
        Item(RG_WATER_TEMPLE_SMALL_KEY,
             Text{ "Water Temple Small Key", "Petite Clé du Temple de l'Eau", "Llave del Templo del Agua" },
             ITEMTYPE_SMALLKEY, 0xB1, true, &WaterTempleKeys, WATER_TEMPLE_SMALL_KEY);
    itemTable[SPIRIT_TEMPLE_SMALL_KEY] =
        Item(RG_SPIRIT_TEMPLE_SMALL_KEY,
             Text{ "Spirit Temple Small Key", "Petite Clé du Temple de l'Esprit", "Llave del Templo del Espíritu" },
             ITEMTYPE_SMALLKEY, 0xB2, true, &SpiritTempleKeys, SPIRIT_TEMPLE_SMALL_KEY);
    itemTable[SHADOW_TEMPLE_SMALL_KEY] =
        Item(RG_SHADOW_TEMPLE_SMALL_KEY,
             Text{ "Shadow Temple Small Key", "Petite Clé du Temple de l'Ombre", "Llave del Templo de las Sombras" },
             ITEMTYPE_SMALLKEY, 0xB3, true, &ShadowTempleKeys, SHADOW_TEMPLE_SMALL_KEY);
    itemTable[BOTTOM_OF_THE_WELL_SMALL_KEY] =
        Item(RG_BOTTOM_OF_THE_WELL_SMALL_KEY,
             Text{ "Bottom of the Well Small Key", "Petite Clé du Puits", "Llave del fondo del pozo" },
             ITEMTYPE_SMALLKEY, 0xB4, true, &BottomOfTheWellKeys, BOTTOM_OF_THE_WELL_SMALL_KEY);
    itemTable[GERUDO_TRAINING_GROUNDS_SMALL_KEY] =
        Item(RG_GERUDO_TRAINING_GROUNDS_SMALL_KEY,
             Text{ "Training Grounds Small Key", "Petite Clé du Gymnase Gerudo", "Llave del Centro de Instrucción" },
             ITEMTYPE_SMALLKEY, 0xB5, true, &GerudoTrainingGroundsKeys, GERUDO_TRAINING_GROUNDS_SMALL_KEY);
    itemTable[GERUDO_FORTRESS_SMALL_KEY] =
        Item(RG_GERUDO_FORTRESS_SMALL_KEY,
             Text{ "Gerudo Fortress Small Key", "Petite Clé du Repaire des Voleurs", "Llave de la Fortaleza Gerudo" },
             ITEMTYPE_FORTRESS_SMALLKEY, 0xB6, true, &GerudoFortressKeys, GERUDO_FORTRESS_SMALL_KEY);
    itemTable[GANONS_CASTLE_SMALL_KEY] =
        Item(RG_GANONS_CASTLE_SMALL_KEY,
             Text{ "Ganon's Castle Small Key", "Petite Clé du Château de Ganon", "Llave del Castillo de Ganon" },
             ITEMTYPE_SMALLKEY, 0xB7, true, &GanonsCastleKeys, GANONS_CASTLE_SMALL_KEY);
    itemTable[TREASURE_GAME_SMALL_KEY] =
        Item(RG_TREASURE_GAME_SMALL_KEY,
             Text{ "Chest Game Small Key", "Petite Clé du jeu la Chasse-aux-Trésors", "Llave del Cofre del Tesoro" },
             ITEMTYPE_ITEM, 0xDE, true, &TreasureGameKeys, TREASURE_GAME_SMALL_KEY);

    // Key Rings
    itemTable[FOREST_TEMPLE_KEY_RING] =
        Item(RG_FOREST_TEMPLE_KEY_RING,
             Text{ "Forest Temple Key Ring", "Trousseau du Temple de la Forêt", "Llavero del Templo del Bosque" },
             ITEMTYPE_SMALLKEY, 0xD5, true, &ForestTempleKeys, FOREST_TEMPLE_KEY_RING);
    itemTable[FIRE_TEMPLE_KEY_RING] =
        Item(RG_FIRE_TEMPLE_KEY_RING,
             Text{ "Fire Temple Key Ring", "Trousseau du Temple du Feu", "Llavero del Templo del Fuego" },
             ITEMTYPE_SMALLKEY, 0xD6, true, &FireTempleKeys, FIRE_TEMPLE_KEY_RING);
    itemTable[WATER_TEMPLE_KEY_RING] =
        Item(RG_WATER_TEMPLE_KEY_RING,
             Text{ "Water Temple Key Ring", "Trousseau du Temple de l'Eau", "Llavero del Templo del Agua" },
             ITEMTYPE_SMALLKEY, 0xD7, true, &WaterTempleKeys, WATER_TEMPLE_KEY_RING);
    itemTable[SPIRIT_TEMPLE_KEY_RING] =
        Item(RG_SPIRIT_TEMPLE_KEY_RING,
             Text{ "Spirit Temple Key Ring", "Trousseau du Temple de l'Esprit", "Llavero del Templo del Espíritu" },
             ITEMTYPE_SMALLKEY, 0xD8, true, &SpiritTempleKeys, SPIRIT_TEMPLE_KEY_RING);
    itemTable[SHADOW_TEMPLE_KEY_RING] =
        Item(RG_SHADOW_TEMPLE_KEY_RING,
             Text{ "Shadow Temple Key Ring", "Trousseau du Temple de l'Ombre", "Llavero del Templo de las Sombras" },
             ITEMTYPE_SMALLKEY, 0xD9, true, &ShadowTempleKeys, SHADOW_TEMPLE_KEY_RING);
    itemTable[BOTTOM_OF_THE_WELL_KEY_RING] =
        Item(RG_BOTTOM_OF_THE_WELL_KEY_RING,
             Text{ "Bottom of the Well Key Ring", "Trousseau du Puits", "Llavero del fondo del pozo" },
             ITEMTYPE_SMALLKEY, 0xDA, true, &BottomOfTheWellKeys, BOTTOM_OF_THE_WELL_KEY_RING);
    itemTable[GERUDO_TRAINING_GROUNDS_KEY_RING] =
        Item(RG_GERUDO_TRAINING_GROUNDS_KEY_RING,
             Text{ "Training Grounds Key Ring", "Trousseau du Gymnase Gerudo", "Llavero del Centro de Instrucción" },
             ITEMTYPE_SMALLKEY, 0xDB, true, &GerudoTrainingGroundsKeys, GERUDO_TRAINING_GROUNDS_KEY_RING);
    itemTable[GERUDO_FORTRESS_KEY_RING] =
        Item(RG_GERUDO_FORTRESS_KEY_RING,
             Text{ "Gerudo Fortress Key Ring", "Trousseau du Repaire des Voleurs", "Llavero de la Fortaleza Gerudo" },
             ITEMTYPE_FORTRESS_SMALLKEY, 0xDC, true, &GerudoFortressKeys, GERUDO_FORTRESS_KEY_RING);
    itemTable[GANONS_CASTLE_KEY_RING] =
        Item(RG_GANONS_CASTLE_KEY_RING,
             Text{ "Ganon's Castle Key Ring", "Trousseau du Château de Ganon", "Llavero del Castillo de Ganon" },
             ITEMTYPE_SMALLKEY, 0xDD, true, &GanonsCastleKeys, GANONS_CASTLE_KEY_RING);

    // Stones and Medallions
    itemTable[KOKIRI_EMERALD] =
        Item(RG_KOKIRI_EMERALD, Text{ "Kokiri's Emerald", "Émeraude Kokiri", "Esmeralda de los Kokiri" },
             ITEMTYPE_DUNGEONREWARD, 0xCB, true, &KokiriEmerald, KOKIRI_EMERALD);
    itemTable[GORON_RUBY] = Item(RG_GORON_RUBY, Text{ "Goron's Ruby", "Rubis Goron", "Rubí de los Goron" },
                                 ITEMTYPE_DUNGEONREWARD, 0xCC, true, &GoronRuby, GORON_RUBY);
    itemTable[ZORA_SAPPHIRE] = Item(RG_ZORA_SAPPHIRE, Text{ "Zora's Sapphire", "Saphir Zora", "Zafiro de los Zora" },
                                    ITEMTYPE_DUNGEONREWARD, 0xCD, true, &ZoraSapphire, ZORA_SAPPHIRE);
    itemTable[FOREST_MEDALLION] =
        Item(RG_FOREST_MEDALLION, Text{ "Forest Medallion", "Médaillon de la Forêt", "Medallón del Bosque" },
             ITEMTYPE_DUNGEONREWARD, 0xCE, true, &ForestMedallion, FOREST_MEDALLION);
    itemTable[FIRE_MEDALLION] =
        Item(RG_FIRE_MEDALLION, Text{ "Fire Medallion", "Médaillon du Feu", "Medallón del Fuego" },
             ITEMTYPE_DUNGEONREWARD, 0xCF, true, &FireMedallion, FIRE_MEDALLION);
    itemTable[WATER_MEDALLION] =
        Item(RG_WATER_MEDALLION, Text{ "Water Medallion", "Médaillon de l'Eau", "Medallón del Agua" },
             ITEMTYPE_DUNGEONREWARD, 0xD0, true, &WaterMedallion, WATER_MEDALLION);
    itemTable[SPIRIT_MEDALLION] =
        Item(RG_SPIRIT_MEDALLION, Text{ "Spirit Medallion", "Médaillon de l'Esprit", "Medallón del Espíritu" },
             ITEMTYPE_DUNGEONREWARD, 0xD1, true, &SpiritMedallion, SPIRIT_MEDALLION);
    itemTable[SHADOW_MEDALLION] =
        Item(RG_SHADOW_MEDALLION, Text{ "Shadow Medallion", "Médaillon de l'Ombre", "Medallón de la Sombra" },
             ITEMTYPE_DUNGEONREWARD, 0xD2, true, &ShadowMedallion, SHADOW_MEDALLION);
    itemTable[LIGHT_MEDALLION] =
        Item(RG_LIGHT_MEDALLION, Text{ "Light Medallion", "Médaillon de la Lumière", "Medallón de la Luz" },
             ITEMTYPE_DUNGEONREWARD, 0xD3, true, &LightMedallion, LIGHT_MEDALLION);

    // Generic Items
    itemTable[RECOVERY_HEART] = Item(RG_RECOVERY_HEART, Text{ "Recovery Heart", "Coeur de Vie", "Corazón" },
                                     ITEMTYPE_ITEM, GI_HEART, false, &noVariable, RECOVERY_HEART);
    itemTable[GREEN_RUPEE] = Item(RG_GREEN_RUPEE, Text{ "Green Rupee", "Rubis Vert", "Rupia verde" }, ITEMTYPE_ITEM,
                                  GI_RUPEE_GREEN, false, &noVariable, GREEN_RUPEE);
    itemTable[GREG_RUPEE] = Item(RG_GREG_RUPEE, Text{ "Greg the Green Rupee", "Rubis Greg", "Rupia Greg" },
                                 ITEMTYPE_ITEM, GI_RUPEE_GREEN, true, &Greg, GREG_RUPEE);
    itemTable[BLUE_RUPEE] = Item(RG_BLUE_RUPEE, Text{ "Blue Rupee", "Rubis Bleu", "Rupia azul" }, ITEMTYPE_ITEM,
                                 GI_RUPEE_BLUE, false, &noVariable, BLUE_RUPEE);
    itemTable[RED_RUPEE] = Item(RG_RED_RUPEE, Text{ "Red Rupee", "Rubis Rouge", "Rupia roja" }, ITEMTYPE_ITEM,
                                GI_RUPEE_RED, false, &noVariable, RED_RUPEE);
    itemTable[PURPLE_RUPEE] = Item(RG_PURPLE_RUPEE, Text{ "Purple Rupee", "Rubis Pourpre", "Rupia morada" },
                                   ITEMTYPE_ITEM, GI_RUPEE_PURPLE, false, &noVariable, PURPLE_RUPEE);
    itemTable[HUGE_RUPEE] = Item(RG_HUGE_RUPEE, Text{ "Huge Rupee", "Énorme Rubis", "Rupia gigante" }, ITEMTYPE_ITEM,
                                 GI_RUPEE_GOLD, false, &noVariable, HUGE_RUPEE);
    itemTable[PIECE_OF_HEART] = Item(RG_PIECE_OF_HEART, Text{ "Piece of Heart", "Quart de Coeur", "Pieza de corazón" },
                                     ITEMTYPE_ITEM, GI_HEART_PIECE, true, &PieceOfHeart, PIECE_OF_HEART);
    itemTable[HEART_CONTAINER] =
        Item(RG_HEART_CONTAINER, Text{ "Heart Container", "Réceptacle de Coeur", "Contenedor de corazón" },
             ITEMTYPE_ITEM, GI_HEART_CONTAINER_2, true, &HeartContainer, HEART_CONTAINER);
    itemTable[ICE_TRAP] = Item(RG_ICE_TRAP, Text{ "Ice Trap", "Piège de Glace", "Trampa de hielo" }, ITEMTYPE_ITEM,
                               GI_ICE_TRAP, false, &noVariable, ICE_TRAP);
    itemTable[MILK] =
        Item(RG_MILK, Text{ "Milk", "Lait", "Leche Lon Lon" }, ITEMTYPE_ITEM, GI_MILK, false, &noVariable, NONE);

    // Refills
    itemTable[BOMBS_5] = Item(RG_BOMBS_5, Text{ "Bombs (5)", "Bombes (5)", "Bombas (5)" }, ITEMTYPE_REFILL, GI_BOMBS_5,
                              false, &noVariable, BOMBS_5);
    itemTable[BOMBS_10] = Item(RG_BOMBS_10, Text{ "Bombs (10)", "Bombes (10)", "Bombas (10)" }, ITEMTYPE_REFILL,
                               GI_BOMBS_10, false, &noVariable, BOMBS_10);
    itemTable[BOMBS_20] = Item(RG_BOMBS_20, Text{ "Bombs (20)", "Bombes (20)", "Bombas (20)" }, ITEMTYPE_REFILL,
                               GI_BOMBS_20, false, &noVariable, BOMBS_20);
    itemTable[BOMBCHU_5] = Item(RG_BOMBCHU_5, Text{ "Bombchus (5)", "Missiles (5)", "Bombchus (5)" }, ITEMTYPE_REFILL,
                                GI_BOMBCHUS_5, true, &Bombchus5, BOMBCHU_5);
    itemTable[BOMBCHU_10] = Item(RG_BOMBCHU_10, Text{ "Bombchus (10)", "Missiles (10)", "Bombchus (10)" },
                                 ITEMTYPE_REFILL, GI_BOMBCHUS_10, true, &Bombchus10, BOMBCHU_10);
    itemTable[BOMBCHU_20] = Item(RG_BOMBCHU_20, Text{ "Bombchus (20)", "Missiles (20)", "Bombchus (20)" },
                                 ITEMTYPE_REFILL, GI_BOMBCHUS_20, true, &Bombchus20, BOMBCHU_20);
    itemTable[BOMBCHU_DROP] = Item(RG_BOMBCHU_DROP, Text{ "Bombchu Drop", "Drop Missiles", "Bombchus" }, ITEMTYPE_DROP,
                                   GI_BOMBCHUS_10, true, &BombchuDrop, NONE);
    itemTable[ARROWS_5] = Item(RG_ARROWS_5, Text{ "Arrows (5)", "Flèches (5)", "Flechas (5)" }, ITEMTYPE_REFILL,
                               GI_ARROWS_SMALL, false, &noVariable, ARROWS_5);
    itemTable[ARROWS_10] = Item(RG_ARROWS_10, Text{ "Arrows (10)", "Flèches (10)", "Flechas (10)" }, ITEMTYPE_REFILL,
                                GI_ARROWS_MEDIUM, false, &noVariable, ARROWS_10);
    itemTable[ARROWS_30] = Item(RG_ARROWS_30, Text{ "Arrows (30)", "Flèches (30)", "Flechas (30)" }, ITEMTYPE_REFILL,
                                GI_ARROWS_LARGE, false, &noVariable, ARROWS_30);
    itemTable[DEKU_NUTS_5] = Item(RG_DEKU_NUTS_5, Text{ "Deku Nuts (5)", "Noix Mojo (5)", "Nueces deku (5)" },
                                  ITEMTYPE_REFILL, GI_NUTS_5, false, &noVariable, DEKU_NUTS_5);
    itemTable[DEKU_NUTS_10] = Item(RG_DEKU_NUTS_10, Text{ "Deku Nuts (10)", "Noix Mojo (10)", "Nueces deku (10)" },
                                   ITEMTYPE_REFILL, GI_NUTS_10, false, &noVariable, DEKU_NUTS_10);
    itemTable[DEKU_SEEDS_30] =
        Item(RG_DEKU_SEEDS_30, Text{ "Deku Seeds (30)", "Graines Mojo (30)", "Semillas deku (30)" }, ITEMTYPE_REFILL,
             GI_SEEDS_30, false, &noVariable, DEKU_SEEDS_30);
    itemTable[DEKU_STICK_1] = Item(RG_DEKU_STICK_1, Text{ "Deku Stick (1)", "Bâton Mojo (1)", "Palo deku (1)" },
                                   ITEMTYPE_REFILL, GI_STICKS_1, false, &noVariable, DEKU_STICK_1);
    itemTable[RED_POTION_REFILL] =
        Item(RG_RED_POTION_REFILL, Text{ "Red Potion Refill", "Recharge de Potion Rouge", "Recarga de poción roja" },
             ITEMTYPE_REFILL, GI_POTION_RED, false, &noVariable, NONE);
    itemTable[GREEN_POTION_REFILL] = Item(
        RG_GREEN_POTION_REFILL, Text{ "Green Potion Refill", "Recharge de Potion Verte", "Recarga de poción verde" },
        ITEMTYPE_REFILL, GI_POTION_GREEN, false, &noVariable, NONE);
    itemTable[BLUE_POTION_REFILL] =
        Item(RG_BLUE_POTION_REFILL, Text{ "Blue Potion Refill", "Recharge de Potion Bleue", "Recarga de poción azul" },
             ITEMTYPE_REFILL, GI_POTION_BLUE, false, &noVariable, NONE);

    // Treasure Game
    itemTable[TREASURE_GAME_HEART] =
        Item(RG_TREASURE_GAME_HEART,
             Text{ "Piece of Heart (Treasure Chest Minigame)", "Quart de Coeur (Chasse-aux-Trésors)",
                   "Pieza de corazón (Cofre del Tesoro)" },
             ITEMTYPE_ITEM, GI_HEART_PIECE_WIN, true, &PieceOfHeart, TREASURE_GAME_HEART);
    itemTable[TREASURE_GAME_GREEN_RUPEE] =
        Item(RG_TREASURE_GAME_GREEN_RUPEE,
             Text{ "Green Rupee (Treasure Chest Minigame)", "Rubis Vert (Chasse-aux-Trésors)",
                   "Rupia Verde (Cofre del Tesoro)" },
             ITEMTYPE_ITEM, GI_RUPEE_GREEN_LOSE, false, &noVariable, TREASURE_GAME_GREEN_RUPEE);

    // Shop Items price
    itemTable[BUY_DEKU_NUT_5] =
        Item(RG_BUY_DEKU_NUT_5, Text{ "Buy Deku Nut (5)", "Acheter: Noix Mojo (5)", "Comprar nueces deku (5)" },
             ITEMTYPE_SHOP, 0x00, true, &Nuts, DEKU_NUTS_5, 15);
    itemTable[BUY_ARROWS_30] =
        Item(RG_BUY_ARROWS_30, Text{ "Buy Arrows (30)", "Acheter: Flèches (30)", "Comprar flechas (30)" },
             ITEMTYPE_SHOP, 0x01, true, &BuyArrow, ARROWS_30, 60);
    itemTable[BUY_ARROWS_50] =
        Item(RG_BUY_ARROWS_50, Text{ "Buy Arrows (50)", "Acheter: Flèches (50)", "Comprar flechas (50)" },
             ITEMTYPE_SHOP, 0x02, true, &BuyArrow, ARROWS_30, 90);
    itemTable[BUY_BOMBS_525] =
        Item(RG_BUY_BOMBS_525, Text{ "Buy Bombs (5) [25]", "Acheter: Bombes (5) [25]", "Comprar bombas (5) [25]" },
             ITEMTYPE_SHOP, 0x03, true, &BuyBomb, BOMBS_5, 25);
    itemTable[BUY_DEKU_NUT_10] =
        Item(RG_BUY_DEKU_NUT_10, Text{ "Buy Deku Nut (10)", "Acheter: Noix Mojo (10)", "Comprar Nueces deku (10)" },
             ITEMTYPE_SHOP, 0x04, true, &Nuts, DEKU_NUTS_10, 30);
    itemTable[BUY_DEKU_STICK_1] =
        Item(RG_BUY_DEKU_STICK_1, Text{ "Buy Deku Stick (1)", "Acheter: Bâton Mojo (1)", "Comprar palos deku (1)" },
             ITEMTYPE_SHOP, 0x05, true, &Sticks, DEKU_STICK_1, 10);
    itemTable[BUY_BOMBS_10] =
        Item(RG_BUY_BOMBS_10, Text{ "Buy Bombs (10)", "Acheter: Bombes (10)", "Comprar Bombas (10)" }, ITEMTYPE_SHOP,
             0x06, true, &BuyBomb, BOMBS_10, 50);
    itemTable[BUY_FISH] = Item(RG_BUY_FISH, Text{ "Buy Fish", "Acheter: Poisson", "Comprar pez" }, ITEMTYPE_SHOP, 0x07,
                               true, &FishAccess, BOTTLE_WITH_FISH, 200);
    itemTable[BUY_RED_POTION_30] = Item(
        RG_BUY_RED_POTION_30, Text{ "Buy Red Potion [30]", "Acheter: Potion Rouge [30]", "Comprar poción roja [30]" },
        ITEMTYPE_SHOP, 0x08, false, &noVariable, BOTTLE_WITH_RED_POTION, 30);
    itemTable[BUY_GREEN_POTION] =
        Item(RG_BUY_GREEN_POTION, Text{ "Buy Green Potion", "Acheter: Potion Verte", "Comprar poción verde" },
             ITEMTYPE_SHOP, 0x09, true, &BuyGPotion, BOTTLE_WITH_GREEN_POTION, 30);
    itemTable[BUY_BLUE_POTION] =
        Item(RG_BUY_BLUE_POTION, Text{ "Buy Blue Potion", "Acheter: Potion Bleue", "Comprar poción azul" },
             ITEMTYPE_SHOP, 0x0A, true, &BuyBPotion, BOTTLE_WITH_BLUE_POTION, 100);
    itemTable[BUY_HYLIAN_SHIELD] =
        Item(RG_BUY_HYLIAN_SHIELD, Text{ "Buy Hylian Shield", "Acheter: Bouclier Hylien", "Comprar escudo hyliano" },
             ITEMTYPE_SHOP, 0x0C, true, &HylianShield, HYLIAN_SHIELD, 80);
    itemTable[BUY_DEKU_SHIELD] =
        Item(RG_BUY_DEKU_SHIELD, Text{ "Buy Deku Shield", "Acheter: Bouclier Mojo", "Comprar escudo deku" },
             ITEMTYPE_SHOP, 0x0D, true, &DekuShield, DEKU_SHIELD, 40);
    itemTable[BUY_GORON_TUNIC] =
        Item(RG_BUY_GORON_TUNIC, Text{ "Buy Goron Tunic", "Acheter: Tunique Goron", "Comprar sayo goron" },
             ITEMTYPE_SHOP, 0x0E, true, &GoronTunic, GORON_TUNIC, 200);
    itemTable[BUY_ZORA_TUNIC] =
        Item(RG_BUY_ZORA_TUNIC, Text{ "Buy Zora Tunic", "Acheter: Tunique Zora", "Comprar sayo zora" }, ITEMTYPE_SHOP,
             0x0F, true, &ZoraTunic, ZORA_TUNIC, 300);
    itemTable[BUY_HEART] = Item(RG_BUY_HEART, Text{ "Buy Heart", "Acheter: Coeur de Vie", "Comprar corazón" },
                                ITEMTYPE_SHOP, 0x10, false, &noVariable, RECOVERY_HEART, 10);
    itemTable[BUY_BOMBCHU_10] =
        Item(RG_BUY_BOMBCHU_10, Text{ "Buy Bombchu (10)", "Acheter: Missiles (10)", "Comprar bombchus (10)" },
             ITEMTYPE_SHOP, 0x15, true, &BuyBombchus10, BOMBCHU_10, 99);
    itemTable[BUY_BOMBCHU_20] =
        Item(RG_BUY_BOMBCHU_20, Text{ "Buy Bombchu (20)", "Acheter: Missiles (20)", "Comprar bombchus (20)" },
             ITEMTYPE_SHOP, 0x16, true, &BuyBombchus20, BOMBCHU_20, 180);
    itemTable[BUY_DEKU_SEEDS_30] = Item(
        RG_BUY_DEKU_SEEDS_30, Text{ "Buy Deku Seeds (30)", "Acheter: Graines Mojo (30)", "Comprar semillas deku (30)" },
        ITEMTYPE_SHOP, 0x1D, true, &BuySeed, DEKU_SEEDS_30, 30);
    itemTable[SOLD_OUT] = Item(RG_SOLD_OUT, Text{ "Sold Out", "Rupture de stock", "Vendido" }, ITEMTYPE_SHOP, 0x26,
                               false, &noVariable, NONE, 0);
    itemTable[BUY_BLUE_FIRE] =
        Item(RG_BUY_BLUE_FIRE, Text{ "Buy Blue Fire", "Acheter: Flamme Bleue", "Comprar fuego azul" }, ITEMTYPE_SHOP,
             0x27, true, &BlueFireAccess, BOTTLE_WITH_BLUE_FIRE, 300);
    itemTable[BUY_BOTTLE_BUG] =
        Item(RG_BUY_BOTTLE_BUG, Text{ "Buy Bottle Bug", "Acheter: Insecte en bouteille", "Comprar bichos" },
             ITEMTYPE_SHOP, 0x28, true, &BugsAccess, BOTTLE_WITH_BUGS, 50);
    itemTable[BUY_POE] = Item(RG_BUY_POE, Text{ "Buy Poe", "Acheter: Esprit", "Comprar Poe" }, ITEMTYPE_SHOP, 0x2A,
                              false, &noVariable, BOTTLE_WITH_BIG_POE, 30);
    itemTable[BUY_FAIRYS_SPIRIT] =
        Item(RG_BUY_FAIRYS_SPIRIT, Text{ "Buy Fairy's Spirit", "Acheter: Esprit de Fée", "Comprar hada" },
             ITEMTYPE_SHOP, 0x2B, true, &FairyAccess, BOTTLE_WITH_FAIRY, 50);
    itemTable[BUY_ARROWS_10] =
        Item(RG_BUY_ARROWS_10, Text{ "Buy Arrows (10)", "Acheter: Flèches (10)", "Comprar flechas (10)" },
             ITEMTYPE_SHOP, 0x2C, true, &BuyArrow, ARROWS_10, 20);
    itemTable[BUY_BOMBS_20] =
        Item(RG_BUY_BOMBS_20, Text{ "Buy Bombs (20)", "Acheter: Bombes (20)", "Comprar bombas (20)" }, ITEMTYPE_SHOP,
             0x2D, true, &BuyBomb, BOMBS_20, 80);
    itemTable[BUY_BOMBS_30] =
        Item(RG_BUY_BOMBS_30, Text{ "Buy Bombs (30)", "Acheter: Bombes (30)", "Comprar bombas (30)" }, ITEMTYPE_SHOP,
             0x2E, true, &BuyBomb, BOMBS_20, 120);
    itemTable[BUY_BOMBS_535] =
        Item(RG_BUY_BOMBS_535, Text{ "Buy Bombs (5) [35]", "Acheter: Bombes (5) [35]", "Comprar bombas (5) [35]" },
             ITEMTYPE_SHOP, 0x2F, true, &BuyBomb, BOMBS_5, 35);
    itemTable[BUY_RED_POTION_40] = Item(
        RG_BUY_RED_POTION_40, Text{ "Buy Red Potion [40]", "Acheter: Potion Rouge [40]", "Comprar poción roja [40]" },
        ITEMTYPE_SHOP, 0x30, false, &noVariable, BOTTLE_WITH_RED_POTION, 40);
    itemTable[BUY_RED_POTION_50] = Item(
        RG_BUY_RED_POTION_50, Text{ "Buy Red Potion [50]", "Acheter: Potion Rouge [50]", "Comprar poción roja [50]" },
        ITEMTYPE_SHOP, 0x31, false, &noVariable, BOTTLE_WITH_RED_POTION, 50);

    itemTable[TRIFORCE] = Item(RG_TRIFORCE, Text{ "Triforce", "Triforce", "Trifuerza" }, ITEMTYPE_EVENT,
                               GI_RUPEE_RED_LOSE, false, &noVariable, NONE);
    itemTable[HINT] =
        Item(RG_HINT, Text{ "Hint", "Indice", "Pista" }, ITEMTYPE_EVENT, GI_RUPEE_BLUE_LOSE, false, &noVariable, NONE);

    //  itemTable[HOOKSHOT]                          = Item(RG_HOOKSHOT,                          Text{"Hookshot",
    //  "Grappin",                          "Gancho"},                                  ITEMTYPE_ITEM, 0x80, true,
    //  &ProgressiveHookshot, HOOKSHOT); itemTable[LONGSHOT]                          = Item(RG_LONGSHOT,
    //  Text{"Longshot",                        "Super-Grappin",                    "Supergancho"}, ITEMTYPE_ITEM, 0x80,
    //  true,  &ProgressiveHookshot, LONGSHOT); itemTable[FAIRY_OCARINA]                     = Item(RG_FAIRY_OCARINA,
    //  Text{"Fairy Ocarina",                   "Ocarina des fées",                 "Ocarina de las Hadas"},
    //  ITEMTYPE_ITEM, 0x8B, true,  &ProgressiveOcarina, FAIRY_OCARINA); itemTable[OCARINA_OF_TIME]                   =
    //  Item(RG_OCARINA_OF_TIME,                   Text{"Ocarina of Time",                 "Ocarina du Temps", "Ocarina
    //  del Tiempo"},                      ITEMTYPE_ITEM, 0x8B, true,  &ProgressiveOcarina, OCARINA_OF_TIME);
    //  itemTable[BOMB_BAG]                          = Item(RG_BOMB_BAG,                          Text{"Bomb Bag", "Sac
    //  de Bombes",                    "Saco de bombas"},                          ITEMTYPE_ITEM, 0x82, true,
    //  &ProgressiveBombBag, BOMB_BAG); itemTable[BIG_BOMB_BAG]                      = Item(RG_BIG_BOMB_BAG, Text{"Big
    //  Bomb Bag",                    "Grand Sac de Bombes",              "Saco de bombas grande"}, ITEMTYPE_ITEM, 0x82,
    //  true,  &ProgressiveBombBag, BIG_BOMB_BAG); itemTable[BIGGEST_BOMB_BAG]                  =
    //  Item(RG_BIGGEST_BOMB_BAG,                  Text{"Biggest Bomb Bag",                "Énorme Sac de Bombes", "Saco
    //  de bombas gigante"},                  ITEMTYPE_ITEM, 0x82, true,  &ProgressiveBombBag, BIGGEST_BOMB_BAG);
    //  itemTable[FAIRY_BOW]                         = Item(RG_FAIRY_BOW,                         Text{"Fairy Bow", "Arc
    //  des Fées",                     "Arco de las Hadas"},                       ITEMTYPE_ITEM, 0x83, true,
    //  &ProgressiveBow, FAIRY_BOW); itemTable[BIG_QUIVER]                        = Item(RG_BIG_QUIVER, Text{"Big
    //  Quiver",                      "Grand carquois",                   "Carcaj grande"}, ITEMTYPE_ITEM, 0x83, true,
    //  &ProgressiveBow, BIG_QUIVER); itemTable[BIGGEST_QUIVER]                    = Item(RG_BIGGEST_QUIVER,
    //  Text{"Biggest Quiver",                  "Énorme carquois",                  "Carcaj gigante"}, ITEMTYPE_ITEM,
    //  0x83, true,  &ProgressiveBow, BIGGEST_QUIVER); itemTable[FAIRY_SLINGSHOT]                   =
    //  Item(RG_FAIRY_SLINGSHOT,                   Text{"Fairy Slingshot",                 "Lance-Pierre des Fées",
    //  "Resortera de las hadas"},                  ITEMTYPE_ITEM, 0x84, true,  &ProgressiveBulletBag, FAIRY_SLINGSHOT);
    //  itemTable[BIG_BULLET_BAG]                    = Item(RG_BIG_BULLET_BAG,                    Text{"Big Deku Seed
    //  Bullet Bag",        "Grand sac de graines mojo",        "Bolsa de semillas deku grande"}, ITEMTYPE_ITEM, 0x84,
    //  true,  &ProgressiveBulletBag, BIG_BULLET_BAG); itemTable[BIGGEST_BULLET_BAD]                =
    //  Item(RG_BIGGEST_BULLET_BAD,                Text{"Biggest Deku Seed Bullet Bag",    "Énorme sac de graines mojo",
    //  "Bolsa de semillas deku gigante"},          ITEMTYPE_ITEM, 0x84, true,  &ProgressiveBulletBag,
    //  BIGGEST_BULLET_BAD); itemTable[GORONS_BRACELET]                   = Item(RG_GORONS_BRACELET, Text{"Goron's
    //  Bracelet",                "Bracelet Goron",                   "Brazalete de los Goron"}, ITEMTYPE_ITEM, 0x81,
    //  true,  &ProgressiveStrength, GORONS_BRACELET); itemTable[SILVER_GAUNTLETS]                  =
    //  Item(RG_SILVER_GAUNTLETS,                  Text{"Silver Gauntlets",                "Gantelets d'argent",
    //  "Guantes de plata"},                        ITEMTYPE_ITEM, 0x81, true,  &ProgressiveStrength, SILVER_GAUNTLETS);
    //  itemTable[GOLDEN_GAUNTLETS]                  = Item(RG_GOLDEN_GAUNTLETS,                  Text{"Golden
    //  Gauntlets",                "Gantelets d'or",                   "Guantes de oro"}, ITEMTYPE_ITEM, 0x81, true,
    //  &ProgressiveStrength, GOLDEN_GAUNTLETS); itemTable[SILVER_SCALE]                      = Item(RG_SILVER_SCALE,
    //  Text{"Silver Scale",                    "Écaille d'argent",                 "Escama de Plata"}, ITEMTYPE_ITEM,
    //  0x86, true,  &ProgressiveScale, SILVER_SCALE); itemTable[GOLDEN_SCALE]                      =
    //  Item(RG_GOLDEN_SCALE,                      Text{"Golden Scale",                    "Écaille d'or", "Escama de
    //  Oro"},                           ITEMTYPE_ITEM, 0x86, true,  &ProgressiveScale, GOLDEN_SCALE);
    //  itemTable[ADULT_WALLET]                      = Item(RG_ADULT_WALLET,                      Text{"Adult Wallet",
    //  "Grande Bourse",                  "Bolsa de adulto"},                         ITEMTYPE_ITEM, 0x85, true,
    //  &ProgressiveWallet, ADULT_WALLET); itemTable[GIANT_WALLET]                      = Item(RG_GIANT_WALLET,
    //  Text{"Giant Wallet",                    "Bourse de Géant",                  "Bolsa gigante"}, ITEMTYPE_ITEM,
    //  0x85, true,  &ProgressiveWallet, GIANT_WALLET); itemTable[TYCOON_WALLET]                     =
    //  Item(RG_TYCOON_WALLET,                     Text{"Tycoon Wallet",                   "Bourse de Magnat", "Bolsa de
    //  ricachón"},                       ITEMTYPE_ITEM, 0x85, true,  &ProgressiveWallet, TYCOON_WALLET);
    //  itemTable[DEKU_NUT_CAPACITY_30]              = Item(RG_DEKU_NUT_CAPACITY_30,              Text{"Deku Nut
    //  Capacity (30)",          "Capacité de noix Mojo (20)",       "Capacidad de nueces deku (40)"}, ITEMTYPE_ITEM,
    //  0x87, false, &noVariable, DEKU_NUT_CAPACITY_30); itemTable[DEKU_NUT_CAPACITY_40]              =
    //  Item(RG_DEKU_NUT_CAPACITY_40,              Text{"Deku Nut Capacity (40)",          "Capacité de noix Mojo (30)",
    //  "Capacidad de nueces deku (50)"},           ITEMTYPE_ITEM, 0x87, false, &noVariable, DEKU_NUT_CAPACITY_40);
    //  itemTable[DEKU_NUT_CAPACITY_20]              = Item(RG_DEKU_NUT_CAPACITY_20,              Text{"Deku Stick
    //  Capacity (20)",        "Capacité de Bâtons Mojo (20)",     "Capacidad de palos deku (20)"}, ITEMTYPE_ITEM, 0x88,
    //  false, &noVariable, DEKU_NUT_CAPACITY_20); itemTable[DEKU_NUT_CAPACITY_30]              =
    //  Item(RG_DEKU_NUT_CAPACITY_30,              Text{"Deku Nut Capacity (30)",          "Capacité de noix Mojo (20)",
    //  "Capacidad de nueces deku (40)"},           ITEMTYPE_ITEM, 0x88, false, &noVariable, DEKU_NUT_CAPACITY_30);
    //  itemTable[MAGIC_METER]                       = Item(RG_MAGIC_METER,                       Text{"Magic Meter",
    //  "Jauge de Magie",                   "Poder mágico"},                            ITEMTYPE_ITEM, 0x8A, true,
    //  &ProgressiveMagic, MAGIC_METER); itemTable[ENHANCED_MAGIC_METER]              = Item(RG_ENHANCED_MAGIC_METER,
    //  Text{"Enhanced Magic Meter",            "Jauge de Magie améliorée",         "Poder mágico mejorado"},
    //  ITEMTYPE_ITEM, 0x8A, true,  &ProgressiveMagic, ENHANCED_MAGIC_METER);
}

Item& ItemTable(const uint32_t itemKey) {
    return itemTable[itemKey];
}

Item& ItemFromGIID(const int giid) {
    uint32_t index = 0;
    while (index < KEY_ENUM_MAX) {
        if (itemTable[index].GetItemID() == giid) {
            return itemTable[index];
        }
        index++;
    }

    // there are vanilla items that don't exist in the item table we're reading from here
    // if we made it this far, it means we didn't find an item in the table
    // if we don't return anything, the game will crash, so, as a workaround, return greg
    return itemTable[GREEN_RUPEE];
}

// This function should only be used to place items containing hint text
// at gossip stone locations.
void NewItem(const uint32_t itemKey, const Item item) {
    if (itemKey <= BUY_RED_POTION_50) {
        printf("\x1b[25;0HWARNING: ATTEMPTED TO OVERWRITE ITEM %lu\n", itemKey);
        return;
    }

    itemTable[itemKey] = item;
}

std::array<Item, KEY_ENUM_MAX>* GetFullItemTable_() {
    return &itemTable;
}
