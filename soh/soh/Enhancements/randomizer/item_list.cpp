#include "static_data.h"
#include "3drando/logic.hpp"
#include "z64object.h"
#include "soh/Enhancements/custom-message/CustomMessageTypes.h"

void StaticData::InitItemTable() {
    itemTable[RG_NONE] =
        RandoItem(RG_NONE, Text{ "No Item", "Rien", "Kein Artikel" }, ITEMTYPE_EVENT, GI_RUPEE_GREEN, false,
                  &Logic::noVariable, RG_NONE, ITEM_NONE, 0, 0, 0, 0, 0, ITEM_CATEGORY_JUNK, MOD_NONE);
    itemTable[RG_KOKIRI_SWORD] =
        RandoItem(RG_KOKIRI_SWORD, Text{ "Kokiri Sword", "Épée Kokiri", "Kokiri-Schwert" }, ITEMTYPE_ITEM,
                  GI_SWORD_KOKIRI, true, &Logic::KokiriSword, RG_KOKIRI_SWORD, ITEM_SWORD_KOKIRI, OBJECT_GI_SWORD_1,
                  GID_SWORD_KOKIRI, 0xA4, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE, GI_SWORD_KNIFE);
    itemTable[RG_GIANTS_KNIFE] =
        RandoItem(RG_GIANTS_KNIFE, Text{ "Giant's Knife", "Lame des Géants", "Messer des Riesen" }, ITEMTYPE_ITEM,
                  GI_SWORD_KNIFE, true, &Logic::KokiriSword, RG_GIANTS_KNIFE, ITEM_SWORD_KNIFE, OBJECT_GI_LONGSWORD,
                  GID_SWORD_BGS, 0x4B, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BIGGORON_SWORD] =
        RandoItem(RG_BIGGORON_SWORD, Text{ "Biggoron's Sword", "Épée de Biggoron", "Biggoron-Schwert" }, ITEMTYPE_ITEM,
                  GI_SWORD_BGS, true, &Logic::BiggoronSword, RG_BIGGORON_SWORD, ITEM_SWORD_BGS, OBJECT_GI_LONGSWORD,
                  GID_SWORD_BGS, 0x0C, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_DEKU_SHIELD] =
        RandoItem(RG_DEKU_SHIELD, Text{ "Deku Shield", "Bouclier Mojo", "Deku-Schild" }, ITEMTYPE_ITEM, GI_SHIELD_DEKU,
                  false, &Logic::noVariable, RG_DEKU_SHIELD, ITEM_SHIELD_DEKU, OBJECT_GI_SHIELD_1, GID_SHIELD_DEKU,
                  0x4C, 0xA0, CHEST_ANIM_SHORT, ITEM_CATEGORY_LESSER, MOD_NONE);
    itemTable[RG_HYLIAN_SHIELD] =
        RandoItem(RG_HYLIAN_SHIELD, Text{ "Hylian Shield", "Bouclier Hylien", "Hylia-Schild" }, ITEMTYPE_ITEM,
                  GI_SHIELD_HYLIAN, false, &Logic::noVariable, RG_HYLIAN_SHIELD, ITEM_SHIELD_HYLIAN, OBJECT_GI_SHIELD_2,
                  GID_SHIELD_HYLIAN, 0x4D, 0xA0, CHEST_ANIM_SHORT, ITEM_CATEGORY_LESSER, MOD_NONE);
    itemTable[RG_MIRROR_SHIELD] =
        RandoItem(RG_MIRROR_SHIELD, Text{ "Mirror Shield", "Bouclier Miroir", "Spiegel-Schild" }, ITEMTYPE_ITEM,
                  GI_SHIELD_MIRROR, true, &Logic::MirrorShield, RG_MIRROR_SHIELD, ITEM_SHIELD_MIRROR,
                  OBJECT_GI_SHIELD_3, GID_SHIELD_MIRROR, 0x4E, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_GORON_TUNIC] =
        RandoItem(RG_GORON_TUNIC, Text{ "Goron Tunic", "Tunique Goron", "Goronen-Tunika" }, ITEMTYPE_ITEM,
                  GI_TUNIC_GORON, true, &Logic::GoronTunic, RG_GORON_TUNIC, ITEM_TUNIC_GORON, OBJECT_GI_CLOTHES,
                  GID_TUNIC_GORON, 0x50, 0xA0, CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_NONE);
    itemTable[RG_ZORA_TUNIC] =
        RandoItem(RG_ZORA_TUNIC, Text{ "Zora Tunic", "Tunique Zora", "Zora-Tunika" }, ITEMTYPE_ITEM, GI_TUNIC_ZORA,
                  true, &Logic::ZoraTunic, RG_ZORA_TUNIC, ITEM_TUNIC_ZORA, OBJECT_GI_CLOTHES, GID_TUNIC_ZORA, 0x51,
                  0xA0, CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_NONE);
    itemTable[RG_IRON_BOOTS] =
        RandoItem(RG_IRON_BOOTS, Text{ "Iron Boots", "Bottes de plomb", "Eisenstiefel" }, ITEMTYPE_ITEM, GI_BOOTS_IRON,
                  true, &Logic::IronBoots, RG_IRON_BOOTS, ITEM_BOOTS_IRON, OBJECT_GI_BOOTS_2, GID_BOOTS_IRON, 0x53,
                  0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_HOVER_BOOTS] =
        RandoItem(RG_HOVER_BOOTS, Text{ "Hover Boots", "Bottes de airs", "Gleitstiefel" }, ITEMTYPE_ITEM,
                  GI_BOOTS_HOVER, true, &Logic::HoverBoots, RG_HOVER_BOOTS, ITEM_BOOTS_HOVER, OBJECT_GI_HOVERBOOTS,
                  GID_BOOTS_HOVER, 0x54, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BOOMERANG] =
        RandoItem(RG_BOOMERANG, Text{ "Boomerang", "Boomerang", "Bumerang" }, ITEMTYPE_ITEM, GI_BOOMERANG, true,
                  &Logic::Boomerang, RG_BOOMERANG, ITEM_BOOMERANG, OBJECT_GI_BOOMERANG, GID_BOOMERANG, 0x35, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_LENS_OF_TRUTH] =
        RandoItem(RG_LENS_OF_TRUTH, Text{ "Lens of Truth", "Monocle de Vérité", "Auge der Wahrheit" }, ITEMTYPE_ITEM,
                  GI_LENS, true, &Logic::LensOfTruth, RG_LENS_OF_TRUTH, ITEM_LENS, OBJECT_GI_GLASSES, GID_LENS, 0x39,
                  0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_MEGATON_HAMMER] =
        RandoItem(RG_MEGATON_HAMMER, Text{ "Megaton Hammer", "Masse des Titans", "Stahlhammer" }, ITEMTYPE_ITEM,
                  GI_HAMMER, true, &Logic::Hammer, RG_MEGATON_HAMMER, ITEM_HAMMER, OBJECT_GI_HAMMER, GID_HAMMER, 0x38,
                  0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_STONE_OF_AGONY] =
        RandoItem(RG_STONE_OF_AGONY, Text{ "Stone of Agony", "Pierre de Souffrance", "Stein der Qualen" },
                  ITEMTYPE_ITEM, GI_STONE_OF_AGONY, true, &Logic::ShardOfAgony, RG_STONE_OF_AGONY, ITEM_STONE_OF_AGONY,
                  OBJECT_GI_MAP, GID_STONE_OF_AGONY, 0x68, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_DINS_FIRE] =
        RandoItem(RG_DINS_FIRE, Text{ "Din's Fire", "Feu de Din", "Dins Feuerinferno" }, ITEMTYPE_ITEM, GI_DINS_FIRE,
                  true, &Logic::DinsFire, RG_DINS_FIRE, ITEM_DINS_FIRE, OBJECT_GI_GODDESS, GID_DINS_FIRE, 0xAD, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_FARORES_WIND] =
        RandoItem(RG_FARORES_WIND, Text{ "Farore's Wind", "Vent de Farore", "Farores Donnersturm" }, ITEMTYPE_ITEM,
                  GI_FARORES_WIND, true, &Logic::FaroresWind, RG_FARORES_WIND, ITEM_FARORES_WIND, OBJECT_GI_GODDESS,
                  GID_FARORES_WIND, 0xAE, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_NAYRUS_LOVE] =
        RandoItem(RG_NAYRUS_LOVE, Text{ "Nayru's Love", "Amour de Nayru", "Nayrus Umarmung" }, ITEMTYPE_ITEM,
                  GI_NAYRUS_LOVE, true, &Logic::NayrusLove, RG_NAYRUS_LOVE, ITEM_NAYRUS_LOVE, OBJECT_GI_GODDESS,
                  GID_NAYRUS_LOVE, 0xAF, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_FIRE_ARROWS] =
        RandoItem(RG_FIRE_ARROWS, Text{ "Fire Arrow", "Flèche de Feu", "Feuerpfeile" }, ITEMTYPE_ITEM, GI_ARROW_FIRE,
                  true, &Logic::FireArrows, RG_FIRE_ARROWS, ITEM_ARROW_FIRE, OBJECT_GI_M_ARROW, GID_ARROW_FIRE, 0x70,
                  0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_ICE_ARROWS] =
        RandoItem(RG_ICE_ARROWS, Text{ "Ice Arrow", "Flèche de Glace", "Eispfeil" }, ITEMTYPE_ITEM, GI_ARROW_ICE, true,
                  &Logic::IceArrows, RG_ICE_ARROWS, ITEM_ARROW_ICE, OBJECT_GI_M_ARROW, GID_ARROW_ICE, 0x71, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_LIGHT_ARROWS] =
        RandoItem(RG_LIGHT_ARROWS, Text{ "Light Arrow", "Flèche de Lumière", "Lichtpfeil" }, ITEMTYPE_ITEM,
                  GI_ARROW_LIGHT, true, &Logic::LightArrows, RG_LIGHT_ARROWS, ITEM_ARROW_LIGHT, OBJECT_GI_M_ARROW,
                  GID_ARROW_LIGHT, 0x72, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_GERUDO_MEMBERSHIP_CARD] =
        RandoItem(RG_GERUDO_MEMBERSHIP_CARD, Text{ "Gerudo Membership Card", "Carte Gerudo", "Gerudo Karte" },
                  ITEMTYPE_ITEM, GI_GERUDO_CARD, true, &Logic::GerudoToken, RG_GERUDO_MEMBERSHIP_CARD, ITEM_GERUDO_CARD,
                  OBJECT_GI_GERUDO, GID_GERUDO_CARD, 0x7B, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_MAGIC_BEAN] =
        RandoItem(RG_MAGIC_BEAN, Text{ "Magic Bean", "Haricots Magiques", "Wundererbse" }, ITEMTYPE_ITEM, GI_BEAN, true,
                  &Logic::MagicBean, RG_MAGIC_BEAN, ITEM_BEAN, OBJECT_GI_BEAN, GID_BEAN, 0x48, 0x80, CHEST_ANIM_SHORT,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_MAGIC_BEAN_PACK] =
        RandoItem(RG_MAGIC_BEAN_PACK, Text{ "Magic Bean Pack", "Paquet de Haricots Magiques", "Wundererbsen-Packung" },
                  ITEMTYPE_ITEM, RG_MAGIC_BEAN_PACK, true, &Logic::MagicBeanPack, RG_MAGIC_BEAN_PACK,
                  RG_MAGIC_BEAN_PACK, OBJECT_GI_BEAN, GID_BEAN, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_DOUBLE_DEFENSE] = 
        RandoItem(RG_DOUBLE_DEFENSE, Text{ "Double Defense", "Double Défence", "Doppelte Verteidigung" }, ITEMTYPE_ITEM,
                  RG_DOUBLE_DEFENSE, true, &Logic::DoubleDefense, RG_DOUBLE_DEFENSE, RG_DOUBLE_DEFENSE, 
                  OBJECT_GI_HEARTS,GID_HEART_CONTAINER, 0xE9, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, 
                  MOD_RANDOMIZER);
    // Trade Quest Items
    itemTable[RG_WEIRD_EGG] =
        RandoItem(RG_WEIRD_EGG, Text{ "Weird Egg", "Oeuf Curieux", "Seltsames Ei" }, ITEMTYPE_ITEM, GI_WEIRD_EGG, true,
                  &Logic::WeirdEgg, RG_WEIRD_EGG, ITEM_WEIRD_EGG, OBJECT_GI_EGG, GID_EGG, 0x9A, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_ZELDAS_LETTER] =
        RandoItem(RG_ZELDAS_LETTER, Text{ "Zelda's Letter", "Lettre de Zelda", "Zeldas Brief" }, ITEMTYPE_ITEM,
                  GI_LETTER_ZELDA, true, &Logic::ZeldasLetter, RG_ZELDAS_LETTER, ITEM_LETTER_ZELDA, OBJECT_GI_LETTER,
                  GID_LETTER_ZELDA, 0x69, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_POCKET_EGG] =
        RandoItem(RG_POCKET_EGG, Text{ "Pocket Egg", "Oeuf de poche", "Taschenei" }, ITEMTYPE_ITEM, GI_POCKET_EGG, true,
                  &Logic::PocketEgg, RG_POCKET_EGG, ITEM_POCKET_EGG, OBJECT_GI_EGG, GID_EGG, 0x01, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_COJIRO] = 
        RandoItem(RG_COJIRO, Text{ "Cojiro", "P'tit Poulet", "Cojiro" }, ITEMTYPE_ITEM, GI_COJIRO, true, &Logic::Cojiro,       
                  RG_COJIRO, ITEM_COJIRO, OBJECT_GI_NIWATORI, GID_COJIRO, 0x02, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_ODD_MUSHROOM] =
        RandoItem(RG_ODD_MUSHROOM, Text{ "Odd Mushroom", "Champigon Suspect", "Seltsamer Pilz" }, ITEMTYPE_ITEM,
                  GI_ODD_MUSHROOM, true, &Logic::OddMushroom, RG_ODD_MUSHROOM, ITEM_ODD_MUSHROOM, OBJECT_GI_MUSHROOM,
                  GID_ODD_MUSHROOM, 0x03, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_ODD_POTION] =
        RandoItem(RG_ODD_POTION, Text{ "Odd Potion", "Mixture Suspecte", "Seltsamer Trank" }, ITEMTYPE_ITEM,
                  GI_ODD_POTION, true, &Logic::OddPoultice, RG_ODD_POTION, ITEM_ODD_POTION, OBJECT_GI_POWDER,
                  GID_ODD_POTION, 0x04, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_POACHERS_SAW] =
        RandoItem(RG_POACHERS_SAW, Text{ "Poacher's Saw", "Scie du Chasseur", "Wilderer-Säge" }, ITEMTYPE_ITEM, GI_SAW,
                  true, &Logic::PoachersSaw, RG_POACHERS_SAW, ITEM_SAW, OBJECT_GI_SAW, GID_SAW, 0x05, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BROKEN_SWORD] = RandoItem(
        RG_BROKEN_SWORD, Text{ "Broken Goron's Sword", "Épée Brisée de Goron", "Schwert des gebrochenen Goronen" },
        ITEMTYPE_ITEM, GI_SWORD_BROKEN, true, &Logic::BrokenSword, RG_BROKEN_SWORD, ITEM_SWORD_BROKEN,
        OBJECT_GI_BROKENSWORD, GID_SWORD_BROKEN, 0x08, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_PRESCRIPTION] =
        RandoItem(RG_PRESCRIPTION, Text{ "Prescription", "Ordonnance", "Verschreibung" }, ITEMTYPE_ITEM,
                  GI_PRESCRIPTION, true, &Logic::Prescription, RG_PRESCRIPTION, ITEM_PRESCRIPTION,
                  OBJECT_GI_PRESCRIPTION, GID_PRESCRIPTION, 0x09, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_EYEBALL_FROG] =
        RandoItem(RG_EYEBALL_FROG, Text{ "Eyeball Frog", "Crapaud-qui-louche", "Augapfel-Frosch" }, ITEMTYPE_ITEM,
                  GI_FROG, true, &Logic::EyeballFrog, RG_EYEBALL_FROG, ITEM_FROG, OBJECT_GI_FROG, GID_FROG, 0x0D, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_EYEDROPS] =
        RandoItem(RG_EYEDROPS, Text{ "World's Finest Eyedrops", "Super Gouttes", "Supertropfen" }, ITEMTYPE_ITEM,
                  GI_EYEDROPS, true, &Logic::Eyedrops, RG_EYEDROPS, ITEM_EYEDROPS, OBJECT_GI_EYE_LOTION, GID_EYEDROPS,
                  0x0E, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_CLAIM_CHECK] =
        RandoItem(RG_CLAIM_CHECK, Text{ "Claim Check", "Certificat", "Quittung" }, ITEMTYPE_ITEM, GI_CLAIM_CHECK, true,
                  &Logic::ClaimCheck, RG_CLAIM_CHECK, ITEM_CLAIM_CHECK, OBJECT_GI_TICKETSTONE, GID_CLAIM_CHECK, 0x0A,
                  0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    // Skulltula Token
    itemTable[RG_GOLD_SKULLTULA_TOKEN] = 
        RandoItem(RG_GOLD_SKULLTULA_TOKEN,
                  Text{ "Gold Skulltula Token", "Symbole de Skulltula d'Or", "Goldenes Skulltula-Symbol" },
                  ITEMTYPE_TOKEN, GI_SKULL_TOKEN, true, &Logic::GoldSkulltulaTokens, RG_GOLD_SKULLTULA_TOKEN,
                  ITEM_SKULL_TOKEN, OBJECT_GI_SUTARU, GID_SKULL_TOKEN, 0xB4, 0x80, CHEST_ANIM_SHORT,
                  ITEM_CATEGORY_SKULLTULA_TOKEN, MOD_NONE);
    // Progressive Items
    itemTable[RG_PROGRESSIVE_HOOKSHOT] =
        RandoItem(RG_PROGRESSIVE_HOOKSHOT, Text{ "Progressive Hookshot", "Grappin (prog.)", "Progressiver Fanghaken" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_HOOKSHOT, true, &Logic::ProgressiveHookshot, RG_PROGRESSIVE_HOOKSHOT,
                  ITEM_HOOKSHOT, OBJECT_GI_HOOKSHOT, GID_HOOKSHOT, 0x36, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_STRENGTH] =
        RandoItem(RG_PROGRESSIVE_STRENGTH,
                  Text{ "Progressive Strength Upgrade", "Amélioration de Force (prog.)", "Progressives Kraft-Upgrade" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_STRENGTH, true, &Logic::ProgressiveStrength, RG_PROGRESSIVE_STRENGTH,
                  ITEM_BRACELET, OBJECT_GI_BRACELET, GID_BRACELET, 0x79, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_BOMB_BAG] =
        RandoItem(RG_PROGRESSIVE_BOMB_BAG,
                  Text{ "Progressive Bomb Bag", "Sac de Bombes (prog.)", "Progressive Bombentasche" }, ITEMTYPE_ITEM,
                  RG_PROGRESSIVE_BOMB_BAG, true, &Logic::ProgressiveBombBag, RG_PROGRESSIVE_BOMB_BAG, ITEM_BOMB_BAG_20,
                  OBJECT_GI_BOMBPOUCH, GID_BOMB_BAG_20, 0x58, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_BOW] =
        RandoItem(RG_PROGRESSIVE_BOW, Text{ "Progressive Bow", "Arc (prog.)", "Progressiver Bogen" }, ITEMTYPE_ITEM,
                  RG_PROGRESSIVE_BOW, true, &Logic::ProgressiveBow, RG_PROGRESSIVE_BOW, ITEM_BOW, OBJECT_GI_BOW,
                  GID_BOW, 0x31, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_SLINGSHOT] =
        RandoItem(RG_PROGRESSIVE_SLINGSHOT,
                  Text{ "Progressive Slingshot", "Lance-Pierre (prog.)", "Progressive Steinschleuder" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_SLINGSHOT, true, &Logic::ProgressiveBulletBag, RG_PROGRESSIVE_SLINGSHOT,
                  ITEM_SLINGSHOT, OBJECT_GI_PACHINKO, GID_SLINGSHOT, 0x30, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_WALLET] = 
        RandoItem(RG_PROGRESSIVE_WALLET, Text{ "Progressive Wallet", "Bourse (prog.)", "Progressive Brieftasche" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_WALLET, true, &Logic::ProgressiveWallet, RG_PROGRESSIVE_WALLET,
                  ITEM_WALLET_ADULT, OBJECT_GI_PURSE, GID_WALLET_ADULT, 0x5E, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_SCALE] =
        RandoItem(RG_PROGRESSIVE_SCALE, Text{ "Progressive Scale", "Écaille (prog.)", "Progressive Skala" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_SCALE, true, &Logic::ProgressiveScale, RG_PROGRESSIVE_SCALE,
                  ITEM_SCALE_SILVER, OBJECT_GI_SCALE, GID_SCALE_SILVER, 0xCD, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_NUT_UPGRADE] =
        RandoItem(RG_PROGRESSIVE_NUT_UPGRADE,
                  Text{ "Progressive Nut Capacity", "Capacité de Noix (prog.)", "Progressive Nusskapazität" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_NUT_UPGRADE, false, &Logic::noVariable, RG_PROGRESSIVE_NUT_UPGRADE, 
                  ITEM_NUT_UPGRADE_30, OBJECT_GI_NUTS, GID_NUTS, 0xA7, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_LESSER,         
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_STICK_UPGRADE] =
        RandoItem(RG_PROGRESSIVE_STICK_UPGRADE,
                  Text{ "Progressive Stick Capacity", "Capacité de Bâtons (prog.)", "Progressive Stick-Kapazität" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_STICK_UPGRADE, false, &Logic::noVariable, RG_PROGRESSIVE_STICK_UPGRADE,
                  ITEM_STICK_UPGRADE_20, OBJECT_GI_STICK, GID_STICK, 0x90, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_LESSER,         
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_BOMBCHUS] =
        RandoItem(RG_PROGRESSIVE_BOMBCHUS, Text{ "Progressive Bombchu", "Missiles (prog.)", "Progressive Kriechgrube" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_BOMBCHUS, true, &Logic::Bombchus, RG_PROGRESSIVE_BOMBCHUS,
                  ITEM_BOMBCHUS_20, OBJECT_GI_BOMB_2, GID_BOMBCHU, 0x33, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_JUNK,           
                  MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_MAGIC_METER] =
        RandoItem(RG_PROGRESSIVE_MAGIC_METER,
                  Text{ "Progressive Magic Meter", "Jauge de Magie (prog.)", "Progressives magisches Messgerät" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_MAGIC_METER, true, &Logic::ProgressiveMagic, RG_PROGRESSIVE_MAGIC_METER,
                  RG_MAGIC_SINGLE, OBJECT_GI_MAGICPOT, GID_MAGIC_SMALL, 0xE4, 0x80, CHEST_ANIM_LONG, 
                  ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_OCARINA] =
        RandoItem(RG_PROGRESSIVE_OCARINA, Text{ "Progressive Ocarina", "Ocarina (prog.)", "Progressive Okarina" },
                  ITEMTYPE_ITEM, RG_PROGRESSIVE_OCARINA, true, &Logic::ProgressiveOcarina, RG_PROGRESSIVE_OCARINA,
                  ITEM_OCARINA_FAIRY, OBJECT_GI_OCARINA_0, GID_OCARINA_FAIRY, 0x4A, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_PROGRESSIVE_GORONSWORD] =
        RandoItem(RG_PROGRESSIVE_GORONSWORD,
                  Text{ "Progressive Goron Sword", "Épée Goron (prog.)", "Progressives Goronenschwert" }, ITEMTYPE_ITEM,
                  RG_PROGRESSIVE_GORONSWORD, true, &Logic::ProgressiveGiantKnife, RG_PROGRESSIVE_GORONSWORD,
                  ITEM_SWORD_BGS, OBJECT_GI_LONGSWORD, GID_SWORD_BGS, 0x4B, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    // Bottles
    itemTable[RG_EMPTY_BOTTLE] =
        RandoItem(RG_EMPTY_BOTTLE, Text{ "Empty Bottle", "Bouteille Vide", "Leere Flasche" }, ITEMTYPE_ITEM,
                  GI_BOTTLE, true, &Logic::Bottles, RG_BOTTLE_WITH_MILK, ITEM_BOTTLE, OBJECT_GI_BOTTLE, GID_BOTTLE,
                  0x42, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BOTTLE_WITH_MILK] =
        RandoItem(RG_BOTTLE_WITH_MILK, Text{ "Bottle with Milk", "Bouteille avec du Lait", "Flasche mit Milch" },
                  ITEMTYPE_ITEM, GI_MILK_BOTTLE, true, &Logic::Bottles, RG_BOTTLE_WITH_MILK, ITEM_MILK_BOTTLE,
                  OBJECT_GI_MILK, GID_MILK, 0x98, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BOTTLE_WITH_RED_POTION] =
        RandoItem(RG_BOTTLE_WITH_RED_POTION,
                  Text{ "Bottle with Red Potion", "Bouteille avec une Potion Rouge", "Flasche mit rotem Elixier" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_RED_POTION, true, &Logic::Bottles, RG_BOTTLE_WITH_RED_POTION,
                  RG_BOTTLE_WITH_RED_POTION, OBJECT_GI_LIQUID, GID_POTION_RED, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_GREEN_POTION] =
        RandoItem(RG_BOTTLE_WITH_GREEN_POTION,
                  Text{ "Bottle with Green Potion", "Bouteille avec une Potion Verte", "Flasche mit grünem Elixier" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_GREEN_POTION, true, &Logic::Bottles, RG_BOTTLE_WITH_GREEN_POTION,
                  RG_BOTTLE_WITH_GREEN_POTION, OBJECT_GI_LIQUID, GID_POTION_GREEN, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_BLUE_POTION] =
        RandoItem(RG_BOTTLE_WITH_BLUE_POTION,
                  Text{ "Bottle with Blue Potion", "Bouteille avec une Potion Bleue", "Flasche mit blauem Elixier" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_BLUE_POTION, true, &Logic::Bottles, RG_BOTTLE_WITH_BLUE_POTION,
                  RG_BOTTLE_WITH_BLUE_POTION, OBJECT_GI_LIQUID, GID_POTION_BLUE, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_FAIRY] =
        RandoItem(RG_BOTTLE_WITH_FAIRY, Text{ "Bottle with Fairy", "Bouteille avec une Fée", "Flasche mit Fee"},
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_FAIRY, true, &Logic::Bottles, RG_BOTTLE_WITH_FAIRY,
                  RG_BOTTLE_WITH_FAIRY, OBJECT_GI_BOTTLE, GID_BOTTLE, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_FISH] =
        RandoItem(RG_BOTTLE_WITH_FISH, Text{ "Bottle with Fish", "Bouteille avec un Poisson", "Flasche mit Fisch" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_FISH, true, &Logic::Bottles, RG_BOTTLE_WITH_FISH, RG_BOTTLE_WITH_FISH,
                  OBJECT_GI_FISH, GID_FISH, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_BLUE_FIRE] =
        RandoItem(RG_BOTTLE_WITH_BLUE_FIRE,
                  Text{ "Bottle with Blue Fire", "Bouteille avec une Flamme Bleue", "Flasche mit blauem Feuer" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_BLUE_FIRE, true, &Logic::Bottles, RG_BOTTLE_WITH_BLUE_FIRE,
                  RG_BOTTLE_WITH_BLUE_FIRE, OBJECT_GI_FIRE, GID_BLUE_FIRE, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_BUGS] =
        RandoItem(RG_BOTTLE_WITH_BUGS, Text{ "Bottle with Bugs", "Bouteille avec des Insectes", "Flasche mit Wanzen" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_BUGS, true, &Logic::Bottles, RG_BOTTLE_WITH_BUGS, RG_BOTTLE_WITH_BUGS,
                  OBJECT_GI_INSECT, GID_BUG, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_BOTTLE_WITH_POE] =
        RandoItem(RG_BOTTLE_WITH_POE, Text{ "Bottle with Poe", "Bouteille avec un Esprit", "Flasche mit einem Geist" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_POE, true, &Logic::Bottles, RG_BOTTLE_WITH_POE, RG_BOTTLE_WITH_POE,
                  OBJECT_GI_GHOST, GID_POE, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR,
                  MOD_RANDOMIZER);
    itemTable[RG_RUTOS_LETTER] =
        RandoItem(RG_RUTOS_LETTER,
                  Text{ "Bottle with Ruto's Letter", "Bouteille avec la Lettre de Ruto", "Flasche mit Rutos Brief" },
                  ITEMTYPE_ITEM, GI_LETTER_RUTO, true, &Logic::RutosLetter, RG_RUTOS_LETTER, ITEM_LETTER_RUTO,
                  OBJECT_GI_BOTTLE_LETTER, GID_LETTER_RUTO, 0x99, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BOTTLE_WITH_BIG_POE] =
        RandoItem(RG_BOTTLE_WITH_BIG_POE, Text{ "Bottle with Big Poe", "Bouteille avec une Âme", "Flasche mit Seele" },
                  ITEMTYPE_ITEM, RG_BOTTLE_WITH_BIG_POE, true, &Logic::BottleWithBigPoe, RG_BOTTLE_WITH_BIG_POE,
                  RG_BOTTLE_WITH_BIG_POE, OBJECT_GI_GHOST, GID_BIG_POE, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_RANDOMIZER);
    // Songs
    itemTable[RG_ZELDAS_LULLABY] =
        RandoItem(RG_ZELDAS_LULLABY, Text{ "Zelda's Lullaby", "Berceuse de Zelda", "Zeldas Wiegenlied" }, ITEMTYPE_SONG,
                  RG_ZELDAS_LULLABY, true, &Logic::ZeldasLullaby, RG_ZELDAS_LULLABY, ITEM_SONG_LULLABY,
                  OBJECT_GI_MELODY, GID_SONG_ZELDA, 0xD4, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_EPONAS_SONG] =
        RandoItem(RG_EPONAS_SONG, Text{ "Epona's Song", "Chant d'Epona", "Eponas Lied" }, ITEMTYPE_SONG, RG_EPONAS_SONG,
                  true, &Logic::EponasSong, RG_EPONAS_SONG, ITEM_SONG_EPONA, OBJECT_GI_MELODY, GID_SONG_EPONA, 0xD2,
                  0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SARIAS_SONG] =
        RandoItem(RG_SARIAS_SONG, Text{ "Saria's Song", "Chant de Saria", "Sarias Lied" }, ITEMTYPE_SONG,
                  RG_SARIAS_SONG, true, &Logic::SariasSong, RG_SARIAS_SONG, ITEM_SONG_SARIA, OBJECT_GI_MELODY,
                  GID_SONG_SARIA, 0xD1, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SUNS_SONG] =
        RandoItem(RG_SUNS_SONG, Text{ "Sun's Song", "Chant du Soleil", "Das Lied der Sonne" }, ITEMTYPE_SONG,
                  RG_SUNS_SONG, true, &Logic::SunsSong, RG_SUNS_SONG, ITEM_SONG_SUN, OBJECT_GI_MELODY, GID_SONG_SUN,
                  0xD3, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SONG_OF_TIME] =
        RandoItem(RG_SONG_OF_TIME, Text{ "Song of Time", "Chant du Temps", "Das Lied der Zeit" }, ITEMTYPE_SONG,
                  RG_SONG_OF_TIME, true, &Logic::SongOfTime, RG_SONG_OF_TIME, ITEM_SONG_TIME, OBJECT_GI_MELODY,
                  GID_SONG_TIME, 0xD5, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SONG_OF_STORMS] =
        RandoItem(RG_SONG_OF_STORMS, Text{ "Song of Storms", "Chant des Tempêtes", "Lied der Stürme" }, ITEMTYPE_SONG,
                  RG_SONG_OF_STORMS, true, &Logic::SongOfStorms, RG_SONG_OF_STORMS, ITEM_SONG_STORMS, OBJECT_GI_MELODY,
                  GID_SONG_STORM, 0xD6, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_MINUET_OF_FOREST] =
        RandoItem(RG_MINUET_OF_FOREST, Text{ "Minuet of Forest", "Menuet des Bois", "Wald-Minuett", }, ITEMTYPE_SONG,
                  RG_MINUET_OF_FOREST, true, &Logic::MinuetOfForest, RG_MINUET_OF_FOREST, ITEM_SONG_MINUET,                    
                  OBJECT_GI_MELODY, GID_SONG_MINUET, 0x73, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_BOLERO_OF_FIRE] =
        RandoItem(RG_BOLERO_OF_FIRE, Text{ "Bolero of Fire", "Boléro du Feu", "Bolero des Feuers" }, ITEMTYPE_SONG,
                  RG_BOLERO_OF_FIRE, true, &Logic::BoleroOfFire, RG_BOLERO_OF_FIRE, ITEM_SONG_BOLERO, OBJECT_GI_MELODY,
                  GID_SONG_BOLERO, 0x74, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SERENADE_OF_WATER] =
        RandoItem(RG_SERENADE_OF_WATER, Text{ "Serenade of Water", "Sérénade de l'Eau", "Serenade des Wassers" },
                  ITEMTYPE_SONG, RG_SERENADE_OF_WATER, true, &Logic::SerenadeOfWater, RG_SERENADE_OF_WATER,
                  ITEM_SONG_SERENADE, OBJECT_GI_MELODY, GID_SONG_SERENADE, 0x75, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_NOCTURNE_OF_SHADOW] =
        RandoItem(RG_NOCTURNE_OF_SHADOW, Text{ "Nocturne of Shadow", "Nocturne de l'Ombre", "Nocturne der Schatten "},
                  ITEMTYPE_SONG, RG_NOCTURNE_OF_SHADOW, true, &Logic::NocturneOfShadow, RG_NOCTURNE_OF_SHADOW,
                  ITEM_SONG_NOCTURNE, OBJECT_GI_MELODY, GID_SONG_NOCTURNE, 0x77, 0x80, CHEST_ANIM_LONG, 
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_REQUIEM_OF_SPIRIT] =
        RandoItem(RG_REQUIEM_OF_SPIRIT, Text{ "Requiem of Spirit", "Requiem des Esprits", "Requiem des Geistes" },
                  ITEMTYPE_SONG, RG_REQUIEM_OF_SPIRIT, true, &Logic::RequiemOfSpirit, RG_REQUIEM_OF_SPIRIT,
                  ITEM_SONG_REQUIEM, OBJECT_GI_MELODY, GID_SONG_REQUIEM, 0x76, 0x80, CHEST_ANIM_LONG, 
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_PRELUDE_OF_LIGHT] =
        RandoItem(RG_PRELUDE_OF_LIGHT, Text{ "Prelude of Light", "Prélude de la Lumière", "Präludium des Lichts" },
                  ITEMTYPE_SONG, RG_PRELUDE_OF_LIGHT, true, &Logic::PreludeOfLight, RG_PRELUDE_OF_LIGHT,
                  ITEM_SONG_PRELUDE, OBJECT_GI_MELODY, GID_SONG_PRELUDE, 0x78, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    // Maps and Compasses
    itemTable[RG_DEKU_TREE_MAP] =
        RandoItem(RG_DEKU_TREE_MAP, Text{ "Great Deku Tree Map", "Carte de l'Arbre Mojo", "Karte des Deku-Baums" },
                  ITEMTYPE_MAP, RG_DEKU_TREE_MAP, false, &Logic::noVariable, RG_DEKU_TREE_MAP, RG_DEKU_TREE_MAP,                    
                  OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_DODONGOS_CAVERN_MAP] =
        RandoItem(RG_DODONGOS_CAVERN_MAP,
                  Text{ "Dodongo's Cavern Map", "Carte de la Caverne Dodongo", "Karte der Dodongo-Höhle" },
                  ITEMTYPE_MAP, RG_DODONGOS_CAVERN_MAP, false, &Logic::noVariable, RG_DODONGOS_CAVERN_MAP,
                  RG_DODONGOS_CAVERN_MAP, OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_JABU_JABUS_BELLY_MAP] =
        RandoItem(RG_JABU_JABUS_BELLY_MAP,
                  Text{ "Jabu-Jabu's Belly Map", "Carte du Ventre de Jabu-Jabu", "Karte des Jabu-Jabu-Bauchs" },
                  ITEMTYPE_MAP, RG_JABU_JABUS_BELLY_MAP, false, &Logic::noVariable, RG_JABU_JABUS_BELLY_MAP,
                  RG_JABU_JABUS_BELLY_MAP, OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_FOREST_TEMPLE_MAP] =
        RandoItem(RG_FOREST_TEMPLE_MAP, Text{ "Forest Temple Map", "Carte du Temple de la Forêt", "Waldtempel Karte" },
                  ITEMTYPE_MAP, RG_FOREST_TEMPLE_MAP, false, &Logic::noVariable, RG_FOREST_TEMPLE_MAP,
                  RG_FOREST_TEMPLE_MAP, OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_FIRE_TEMPLE_MAP] =
        RandoItem(RG_FIRE_TEMPLE_MAP, Text{ "Fire Temple Map", "Carte due Temple de Feu", "Feuertempel Karte" },
                  ITEMTYPE_MAP, RG_FIRE_TEMPLE_MAP, false, &Logic::noVariable, RG_FIRE_TEMPLE_MAP, RG_FIRE_TEMPLE_MAP,                  
                  OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_WATER_TEMPLE_MAP] =
        RandoItem(RG_WATER_TEMPLE_MAP, Text{ "Water Temple Map", "Carte du Temple de l'Eau", "Wassertempel-Karte" },
                  ITEMTYPE_MAP, RG_WATER_TEMPLE_MAP, false, &Logic::noVariable, RG_WATER_TEMPLE_MAP, RG_WATER_TEMPLE_MAP,                 
                  OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, 
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_SPIRIT_TEMPLE_MAP] =
        RandoItem(RG_SPIRIT_TEMPLE_MAP,
                  Text{ "Spirit Temple Map", "Carte due Temple de l'Esprit", "Geistertempel Karte"}, ITEMTYPE_MAP,
                  RG_SPIRIT_TEMPLE_MAP, false, &Logic::noVariable, RG_SPIRIT_TEMPLE_MAP, RG_SPIRIT_TEMPLE_MAP,
                  OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_SHADOW_TEMPLE_MAP] =
        RandoItem(RG_SHADOW_TEMPLE_MAP,
                  Text{ "Shadow Temple Map", "Carte du Temple de l'Ombre", "Karte des Schattentempels"}, ITEMTYPE_MAP,
                  RG_SHADOW_TEMPLE_MAP, false, &Logic::noVariable, RG_SHADOW_TEMPLE_MAP, RG_SHADOW_TEMPLE_MAP,
                  OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_BOTTOM_OF_THE_WELL_MAP] =
        RandoItem(RG_BOTTOM_OF_THE_WELL_MAP,
                  Text{ "Bottom of the Well Map", "Carte du Puits", "Boden des Brunnens Karte"}, ITEMTYPE_MAP,
                  RG_BOTTOM_OF_THE_WELL_MAP, false, &Logic::noVariable, RG_BOTTOM_OF_THE_WELL_MAP,
                  RG_BOTTOM_OF_THE_WELL_MAP, OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_ICE_CAVERN_MAP] =
        RandoItem(RG_ICE_CAVERN_MAP, Text{ "Ice Cavern Map", "Carte de la Caverne Polaire", "Eishöhle Karte" },
                  ITEMTYPE_MAP, RG_ICE_CAVERN_MAP, false, &Logic::noVariable, RG_ICE_CAVERN_MAP, RG_ICE_CAVERN_MAP,                    
                  OBJECT_GI_MAP, GID_DUNGEON_MAP, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_DEKU_TREE_COMPASS] =
        RandoItem(RG_DEKU_TREE_COMPASS,
                  Text{ "Great Deku Tree Compass", "Boussole de l'Arbre Mojo", "Kompass des Deku-Baums"},
                  ITEMTYPE_COMPASS, RG_DEKU_TREE_COMPASS, false, &Logic::noVariable, RG_DEKU_TREE_COMPASS,
                  RG_DEKU_TREE_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_DODONGOS_CAVERN_COMPASS] =
        RandoItem(RG_DODONGOS_CAVERN_COMPASS,
                  Text{ "Dodongo's Cavern Compass", "Boussole de la Caverne Dodongo", "Kompass der Dodongo-Höhle" },
                  ITEMTYPE_COMPASS, RG_DODONGOS_CAVERN_COMPASS, false, &Logic::noVariable, RG_DODONGOS_CAVERN_COMPASS,
                  RG_DODONGOS_CAVERN_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_JABU_JABUS_BELLY_COMPASS] =
        RandoItem(RG_JABU_JABUS_BELLY_COMPASS,
                  Text{ "Jabu-Jabu's Belly Compass", "Boussole du Ventre de Jabu-Jabu", "Kompass des Jabu-Jabu-Bauchs" },
                  ITEMTYPE_COMPASS, RG_JABU_JABUS_BELLY_COMPASS, false, &Logic::noVariable, RG_JABU_JABUS_BELLY_COMPASS,
                  RG_JABU_JABUS_BELLY_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_FOREST_TEMPLE_COMPASS] =
        RandoItem(RG_FOREST_TEMPLE_COMPASS,
                  Text{ "Forest Temple Compass", "Boussole du Temple de la Forêt", "Waldtempel-Kompass" },
                  ITEMTYPE_COMPASS, RG_FOREST_TEMPLE_COMPASS, false, &Logic::noVariable, RG_FOREST_TEMPLE_COMPASS,
                  RG_FOREST_TEMPLE_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_FIRE_TEMPLE_COMPASS] =
        RandoItem(RG_FIRE_TEMPLE_COMPASS,
                  Text{ "Fire Temple Compass", "Boussole du Temple du Feu", "Feuertempel-Kompass" }, ITEMTYPE_COMPASS,
                  RG_FIRE_TEMPLE_COMPASS, false, &Logic::noVariable, RG_FIRE_TEMPLE_COMPASS, RG_FIRE_TEMPLE_COMPASS,              
                  OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_WATER_TEMPLE_COMPASS] =
        RandoItem(RG_WATER_TEMPLE_COMPASS,
                  Text{ "Water Temple Compass", "Boussole du Temple de l'Eau", "Wassertempel-Kompass" },
                  ITEMTYPE_COMPASS, RG_WATER_TEMPLE_COMPASS, false, &Logic::noVariable, RG_WATER_TEMPLE_COMPASS, 
                  RG_WATER_TEMPLE_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_SPIRIT_TEMPLE_COMPASS] =
        RandoItem(RG_SPIRIT_TEMPLE_COMPASS,
                  Text{ "Spirit Temple Compass", "Boussole due Temple de l'Esprit", "Geistiger Tempelkompass" },
                  ITEMTYPE_COMPASS, RG_SPIRIT_TEMPLE_COMPASS, false, &Logic::noVariable, RG_SPIRIT_TEMPLE_COMPASS,
                  RG_SPIRIT_TEMPLE_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_SHADOW_TEMPLE_COMPASS] =
        RandoItem(RG_SHADOW_TEMPLE_COMPASS,
                  Text{ "Shadow Temple Compass", "Boussole du Temple de l'Ombre", "Kompass des Schattentempels" },
                  ITEMTYPE_COMPASS, RG_SHADOW_TEMPLE_COMPASS, false, &Logic::noVariable, RG_SHADOW_TEMPLE_COMPASS,
                  RG_SHADOW_TEMPLE_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_BOTTOM_OF_THE_WELL_COMPASS] =
        RandoItem(RG_BOTTOM_OF_THE_WELL_COMPASS,
                  Text{ "Bottom of the Well Compass", "Boussole du Puits", "Boden des Brunnenkompasses" },
                  ITEMTYPE_COMPASS, RG_BOTTOM_OF_THE_WELL_COMPASS, false, &Logic::noVariable,
                  RG_BOTTOM_OF_THE_WELL_COMPASS, RG_BOTTOM_OF_THE_WELL_COMPASS, OBJECT_GI_COMPASS, GID_COMPASS,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    itemTable[RG_ICE_CAVERN_COMPASS] =
        RandoItem(RG_ICE_CAVERN_COMPASS,
                  Text{ "Ice Cavern Compass", "Boussole de la Caverne Polaire", "Eishöhlenkompass"}, ITEMTYPE_COMPASS,
                  RG_ICE_CAVERN_COMPASS, false, &Logic::noVariable, RG_ICE_CAVERN_COMPASS, RG_ICE_CAVERN_COMPASS,               
                  OBJECT_GI_COMPASS, GID_COMPASS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_LESSER, MOD_RANDOMIZER);
    // Boss Keys
    itemTable[RG_FOREST_TEMPLE_BOSS_KEY] =
        RandoItem(RG_FOREST_TEMPLE_BOSS_KEY,
                  Text{ "Forest Temple Boss Key", "Clé d'Or du Temple de la Forêt", "Waldtempel-Boss-Schlüssel" },
                  ITEMTYPE_BOSSKEY, RG_FOREST_TEMPLE_BOSS_KEY, true, &Logic::BossKeyForestTemple,
                  RG_FOREST_TEMPLE_BOSS_KEY, RG_FOREST_TEMPLE_BOSS_KEY, OBJECT_GI_BOSSKEY, GID_KEY_BOSS,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_BOSS_KEY, MOD_RANDOMIZER);
    itemTable[RG_FIRE_TEMPLE_BOSS_KEY] =
        RandoItem(RG_FIRE_TEMPLE_BOSS_KEY,
                  Text{ "Fire Temple Boss Key", "Clé d'Or du Temple du Feu", "Feuertempel-Boss-Schlüssel" },
                  ITEMTYPE_BOSSKEY, RG_FIRE_TEMPLE_BOSS_KEY, true, &Logic::BossKeyFireTemple, RG_FIRE_TEMPLE_BOSS_KEY,
                  RG_FIRE_TEMPLE_BOSS_KEY, OBJECT_GI_BOSSKEY, GID_KEY_BOSS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_LONG, ITEM_CATEGORY_BOSS_KEY, MOD_RANDOMIZER);
    itemTable[RG_WATER_TEMPLE_BOSS_KEY] =
        RandoItem(RG_WATER_TEMPLE_BOSS_KEY,
                  Text{ "Water Temple Boss Key", "Clé d'Or du Temple de l'Eau", "Wassertempel-Boss-Schlüssel" },
                  ITEMTYPE_BOSSKEY, RG_WATER_TEMPLE_BOSS_KEY, true, &Logic::BossKeyWaterTemple,
                  RG_WATER_TEMPLE_BOSS_KEY, RG_WATER_TEMPLE_BOSS_KEY, OBJECT_GI_BOSSKEY, GID_KEY_BOSS,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_BOSS_KEY, MOD_RANDOMIZER);
    itemTable[RG_SPIRIT_TEMPLE_BOSS_KEY] =
        RandoItem(RG_SPIRIT_TEMPLE_BOSS_KEY,
                  Text{ "Spirit Temple Boss Key", "Clé d'Or du Temple de l'Esprit", "Geistertempel-Boss-Schlüssel" },
                  ITEMTYPE_BOSSKEY, RG_SPIRIT_TEMPLE_BOSS_KEY, true, &Logic::BossKeySpiritTemple,
                  RG_SPIRIT_TEMPLE_BOSS_KEY, RG_SPIRIT_TEMPLE_BOSS_KEY, OBJECT_GI_BOSSKEY, GID_KEY_BOSS,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_BOSS_KEY, MOD_RANDOMIZER);
    itemTable[RG_SHADOW_TEMPLE_BOSS_KEY] =
        RandoItem(RG_SHADOW_TEMPLE_BOSS_KEY,
                  Text{ "Shadow Temple Boss Key", "Clé d'Or du Temple de l'Ombre", 
                  "Schlüssel für den Boss des Schattentempels" }, ITEMTYPE_BOSSKEY, RG_SHADOW_TEMPLE_BOSS_KEY, true,
                  &Logic::BossKeyShadowTemple, RG_SHADOW_TEMPLE_BOSS_KEY, RG_SHADOW_TEMPLE_BOSS_KEY, OBJECT_GI_BOSSKEY,
                  GID_KEY_BOSS, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_BOSS_KEY,
                  MOD_RANDOMIZER);
    itemTable[RG_GANONS_CASTLE_BOSS_KEY] =
        RandoItem(RG_GANONS_CASTLE_BOSS_KEY,
                  Text{ "Ganon's Castle Boss Key", "Clé d'Or du Château de Ganon", "Ganons Schloss-Boss-Schlüssel" },
                  ITEMTYPE_BOSSKEY, RG_GANONS_CASTLE_BOSS_KEY, true, &Logic::BossKeyGanonsCastle,
                  RG_GANONS_CASTLE_BOSS_KEY, RG_GANONS_CASTLE_BOSS_KEY, OBJECT_GI_BOSSKEY, GID_KEY_BOSS,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_BOSS_KEY, MOD_RANDOMIZER);
    itemTable[RG_FOREST_TEMPLE_SMALL_KEY] =
        RandoItem(RG_FOREST_TEMPLE_SMALL_KEY,
                  Text{ "Forest Temple Small Key", "Petite Clé du Temple de la Forêt", "Waldtempel Kleiner Schlüssel" },
                  ITEMTYPE_SMALLKEY, RG_FOREST_TEMPLE_SMALL_KEY, true, &Logic::ForestTempleKeys,
                  RG_FOREST_TEMPLE_SMALL_KEY, RG_FOREST_TEMPLE_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_FIRE_TEMPLE_SMALL_KEY] =
        RandoItem(RG_FIRE_TEMPLE_SMALL_KEY,
                  Text{ "Fire Temple Small Key", "Petite Clé du Temple du Feu", "Feuertempel Kleiner Schlüssel" },
                  ITEMTYPE_SMALLKEY, RG_FIRE_TEMPLE_SMALL_KEY, true, &Logic::FireTempleKeys, RG_FIRE_TEMPLE_SMALL_KEY,
                  RG_FIRE_TEMPLE_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_WATER_TEMPLE_SMALL_KEY] =
        RandoItem(RG_WATER_TEMPLE_SMALL_KEY,
                  Text{ "Water Temple Small Key", "Petite Clé du Temple de l'Eau", "Wassertempel Kleiner Schlüssel" },
                  ITEMTYPE_SMALLKEY, RG_WATER_TEMPLE_SMALL_KEY, true, &Logic::WaterTempleKeys,
                  RG_WATER_TEMPLE_SMALL_KEY, RG_WATER_TEMPLE_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_SPIRIT_TEMPLE_SMALL_KEY] =
        RandoItem(RG_SPIRIT_TEMPLE_SMALL_KEY, 
                  Text{ "Spirit Temple Small Key", "Petite Clé du Temple de l'Esprit", "Geisttempel Kleiner Schlüssel" },
                  ITEMTYPE_SMALLKEY, RG_SPIRIT_TEMPLE_SMALL_KEY, true, &Logic::SpiritTempleKeys,
                  RG_SPIRIT_TEMPLE_SMALL_KEY, RG_SPIRIT_TEMPLE_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_SHADOW_TEMPLE_SMALL_KEY] =
        RandoItem(RG_SHADOW_TEMPLE_SMALL_KEY,
                  Text{ "Shadow Temple Small Key", "Petite Clé du Temple de l'Ombre",
                  "Schattentempel Kleiner Schlüssel" }, ITEMTYPE_SMALLKEY, RG_SHADOW_TEMPLE_SMALL_KEY, true,
                  &Logic::ShadowTempleKeys, RG_SHADOW_TEMPLE_SMALL_KEY, RG_SHADOW_TEMPLE_SMALL_KEY, OBJECT_GI_KEY, 
                  GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY,
                  MOD_RANDOMIZER);
    itemTable[RG_BOTTOM_OF_THE_WELL_SMALL_KEY] =
        RandoItem(RG_BOTTOM_OF_THE_WELL_SMALL_KEY,
                  Text{ "Bottom of the Well Small Key", "Petite Clé du Puits", "Boden des Brunnens Kleiner Schlüssel" },
                  ITEMTYPE_SMALLKEY, RG_BOTTOM_OF_THE_WELL_SMALL_KEY, true, &Logic::BottomOfTheWellKeys,
                  RG_BOTTOM_OF_THE_WELL_SMALL_KEY, RG_BOTTOM_OF_THE_WELL_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_GERUDO_TRAINING_GROUNDS_SMALL_KEY] = RandoItem(
        RG_GERUDO_TRAINING_GROUNDS_SMALL_KEY,
        Text{ "Training Grounds Small Key", "Petite Clé du Gymnase Gerudo", "Trainingsgelände Kleiner Schlüssel" },
        ITEMTYPE_SMALLKEY, RG_GERUDO_TRAINING_GROUNDS_SMALL_KEY, true, &Logic::GerudoTrainingGroundsKeys,
        RG_GERUDO_TRAINING_GROUNDS_SMALL_KEY, RG_GERUDO_TRAINING_GROUNDS_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL,
        TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_GERUDO_FORTRESS_SMALL_KEY] = RandoItem(
        RG_GERUDO_FORTRESS_SMALL_KEY,
        Text{ "Gerudo Fortress Small Key", "Petite Clé du Repaire des Voleurs", "Gerudo-Festung Kleiner Schlüssel" },
        ITEMTYPE_FORTRESS_SMALLKEY, RG_GERUDO_FORTRESS_SMALL_KEY, true, &Logic::GerudoFortressKeys,
        RG_GERUDO_FORTRESS_SMALL_KEY, RG_GERUDO_FORTRESS_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL,
        TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_GANONS_CASTLE_SMALL_KEY] = RandoItem(
        RG_GANONS_CASTLE_SMALL_KEY,
        Text{ "Ganon's Castle Small Key", "Petite Clé du Château de Ganon", "Ganons Schloss Kleiner Schlüssel" },
        ITEMTYPE_SMALLKEY, RG_GANONS_CASTLE_SMALL_KEY, true, &Logic::GanonsCastleKeys, RG_GANONS_CASTLE_SMALL_KEY,
        RG_GANONS_CASTLE_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT,
        ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_TREASURE_GAME_SMALL_KEY] = RandoItem(
        RG_TREASURE_GAME_SMALL_KEY,
        Text{ "Chest Game Small Key", "Petite Clé du jeu la Chasse-aux-Trésors", "Truhenspiel Kleiner Schlüssel" },
        ITEMTYPE_SMALLKEY, RG_TREASURE_GAME_SMALL_KEY, true, &Logic::TreasureGameKeys, RG_TREASURE_GAME_SMALL_KEY, 
        RG_TREASURE_GAME_SMALL_KEY, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT,
        ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    // Key Rings
    itemTable[RG_FOREST_TEMPLE_KEY_RING] =
        RandoItem(RG_FOREST_TEMPLE_KEY_RING,
                  Text{ "Forest Temple Key Ring", "Trousseau du Temple de la Forêt", "Waldtempel Schlüsselanhänger" },
                  ITEMTYPE_SMALLKEY, RG_FOREST_TEMPLE_KEY_RING, true, &Logic::ForestTempleKeys,
                  RG_FOREST_TEMPLE_KEY_RING, RG_FOREST_TEMPLE_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_FIRE_TEMPLE_KEY_RING] =
        RandoItem(RG_FIRE_TEMPLE_KEY_RING,
                  Text{ "Fire Temple Key Ring", "Trousseau du Temple du Feu", "Feuertempel Schlüsselanhänger" },
                  ITEMTYPE_SMALLKEY, RG_FIRE_TEMPLE_KEY_RING, true, &Logic::FireTempleKeys, RG_FIRE_TEMPLE_KEY_RING,
                  RG_FIRE_TEMPLE_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_WATER_TEMPLE_KEY_RING] =
        RandoItem(RG_WATER_TEMPLE_KEY_RING,
                  Text{ "Water Temple Key Ring", "Trousseau du Temple de l'Eau", "Wassertempel Schlüsselanhänger" },
                  ITEMTYPE_SMALLKEY, RG_WATER_TEMPLE_KEY_RING, true, &Logic::WaterTempleKeys, RG_WATER_TEMPLE_KEY_RING,
                  RG_WATER_TEMPLE_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80,
                  CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_SPIRIT_TEMPLE_KEY_RING] =
        RandoItem(RG_SPIRIT_TEMPLE_KEY_RING,
                  Text{ "Spirit Temple Key Ring", "Trousseau du Temple de l'Esprit", "Geisttempel Schlüsselanhänger" },
                  ITEMTYPE_SMALLKEY, RG_SPIRIT_TEMPLE_KEY_RING, true, &Logic::SpiritTempleKeys,
                  RG_SPIRIT_TEMPLE_KEY_RING, RG_SPIRIT_TEMPLE_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_SHADOW_TEMPLE_KEY_RING] = RandoItem(
        RG_SHADOW_TEMPLE_KEY_RING,
        Text{ "Shadow Temple Key Ring", "Trousseau du Temple de l'Ombre", "Schattentempel Schlüsselanhänger" },
        ITEMTYPE_SMALLKEY, RG_SHADOW_TEMPLE_KEY_RING, true, &Logic::ShadowTempleKeys, RG_SHADOW_TEMPLE_KEY_RING,
        RG_SHADOW_TEMPLE_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT,
        ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_BOTTOM_OF_THE_WELL_KEY_RING] =
        RandoItem(RG_BOTTOM_OF_THE_WELL_KEY_RING,
                  Text{ "Bottom of the Well Key Ring", "Trousseau du Puits", "Boden des Brunnens Schlüsselanhänger" },
                  ITEMTYPE_SMALLKEY, RG_BOTTOM_OF_THE_WELL_KEY_RING, true, &Logic::BottomOfTheWellKeys,
                  RG_BOTTOM_OF_THE_WELL_KEY_RING, RG_BOTTOM_OF_THE_WELL_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL,
                  TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_GERUDO_TRAINING_GROUNDS_KEY_RING] = RandoItem(
        RG_GERUDO_TRAINING_GROUNDS_KEY_RING,
        Text{ "Training Grounds Key Ring", "Trousseau du Gymnase Gerudo", "Trainingsgelände Schlüsselanhänger" },
        ITEMTYPE_SMALLKEY, RG_GERUDO_TRAINING_GROUNDS_KEY_RING, true, &Logic::GerudoTrainingGroundsKeys,
        RG_GERUDO_TRAINING_GROUNDS_KEY_RING, RG_GERUDO_TRAINING_GROUNDS_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL,
        TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_GERUDO_FORTRESS_KEY_RING] = RandoItem(
        RG_GERUDO_FORTRESS_KEY_RING,
        Text{ "Gerudo Fortress Key Ring", "Trousseau du Repaire des Voleurs", "Gerudo Festung Schlüsselanhänger" },
        ITEMTYPE_FORTRESS_SMALLKEY, RG_GERUDO_FORTRESS_KEY_RING, true, &Logic::GerudoFortressKeys,
        RG_GERUDO_FORTRESS_KEY_RING, RG_GERUDO_FORTRESS_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL,
        TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT, ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    itemTable[RG_GANONS_CASTLE_KEY_RING] = RandoItem(
        RG_GANONS_CASTLE_KEY_RING,
        Text{ "Ganon's Castle Key Ring", "Trousseau du Château de Ganon", "Ganons Schloss Schlüsselanhänger" },
        ITEMTYPE_SMALLKEY, RG_GANONS_CASTLE_KEY_RING, true, &Logic::GanonsCastleKeys, RG_GANONS_CASTLE_KEY_RING,
        RG_GANONS_CASTLE_KEY_RING, OBJECT_GI_KEY, GID_KEY_SMALL, TEXT_RANDOMIZER_CUSTOM_ITEM, 0x80, CHEST_ANIM_SHORT,
        ITEM_CATEGORY_SMALL_KEY, MOD_RANDOMIZER);
    // Dungeon Rewards
    itemTable[RG_KOKIRI_EMERALD] = RandoItem(
        RG_KOKIRI_EMERALD, Text{ "Kokiri's Emerald", "Émeraude Kokiri", "Kokiri-Smaragd" }, ITEMTYPE_DUNGEONREWARD,
        RG_KOKIRI_EMERALD, true, &Logic::KokiriEmerald, RG_KOKIRI_EMERALD, ITEM_KOKIRI_EMERALD, OBJECT_GI_JEWEL,
        GID_KOKIRI_EMERALD, 0x80, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_GORON_RUBY] =
        RandoItem(RG_GORON_RUBY, Text{ "Goron's Ruby", "Rubis Goron", "Goronen-Rubin" }, ITEMTYPE_DUNGEONREWARD,
                  RG_GORON_RUBY, true, &Logic::GoronRuby, RG_GORON_RUBY, ITEM_GORON_RUBY, OBJECT_GI_JEWEL,
                  GID_GORON_RUBY, 0x81, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_ZORA_SAPPHIRE] =
        RandoItem(RG_ZORA_SAPPHIRE, Text{ "Zora's Sapphire", "Saphir Zora", "Zora-Saphir" }, ITEMTYPE_DUNGEONREWARD,
                  RG_ZORA_SAPPHIRE, true, &Logic::ZoraSapphire, RG_ZORA_SAPPHIRE, ITEM_ZORA_SAPPHIRE, OBJECT_GI_JEWEL,
                  GID_ZORA_SAPPHIRE, 0x82, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_FOREST_MEDALLION] =
        RandoItem(RG_FOREST_MEDALLION, Text{ "Forest Medallion", "Médaillon de la Forêt", "Wald Medaillon" },
                  ITEMTYPE_DUNGEONREWARD, RG_FOREST_MEDALLION, true, &Logic::ForestMedallion, RG_FOREST_MEDALLION,
                  ITEM_MEDALLION_FOREST, OBJECT_GI_MEDAL, GID_MEDALLION_FOREST, 0x3E, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_FIRE_MEDALLION] = RandoItem(
        RG_FIRE_MEDALLION, Text{ "Fire Medallion", "Médaillon du Feu", "Feuer Medaillon" }, ITEMTYPE_DUNGEONREWARD,
        RG_FIRE_MEDALLION, true, &Logic::FireMedallion, RG_FIRE_MEDALLION, ITEM_MEDALLION_FIRE, OBJECT_GI_MEDAL,
        GID_MEDALLION_FIRE, 0x3C, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_WATER_MEDALLION] = RandoItem(
        RG_WATER_MEDALLION, Text{ "Water Medallion", "Médaillon de l'Eau", "Wasser Medaillon" }, ITEMTYPE_DUNGEONREWARD,
        RG_WATER_MEDALLION, true, &Logic::WaterMedallion, RG_WATER_MEDALLION, ITEM_MEDALLION_WATER, OBJECT_GI_MEDAL,
        GID_MEDALLION_WATER, 0x3D, 0x80, CHEST_ANIM_LONG, ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SPIRIT_MEDALLION] =
        RandoItem(RG_SPIRIT_MEDALLION, Text{ "Spirit Medallion", "Médaillon de l'Esprit", "Geist Medaillon" },
                  ITEMTYPE_DUNGEONREWARD, RG_SPIRIT_MEDALLION, true, &Logic::SpiritMedallion, RG_SPIRIT_MEDALLION,
                  ITEM_MEDALLION_SPIRIT, OBJECT_GI_MEDAL, GID_MEDALLION_SPIRIT, 0x3F, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_SHADOW_MEDALLION] =
        RandoItem(RG_SHADOW_MEDALLION, Text{ "Shadow Medallion", "Médaillon de l'Ombre", "Schatten Medaillon" },
                  ITEMTYPE_DUNGEONREWARD, RG_SHADOW_MEDALLION, true, &Logic::ShadowMedallion, RG_SHADOW_MEDALLION,
                  ITEM_MEDALLION_SHADOW, OBJECT_GI_MEDAL, GID_MEDALLION_SHADOW, 0x41, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
    itemTable[RG_LIGHT_MEDALLION] =
        RandoItem(RG_LIGHT_MEDALLION, Text{ "Light Medallion", "Médaillon de la Lumière", "Licht Medaillon" },
                  ITEMTYPE_DUNGEONREWARD, RG_LIGHT_MEDALLION, true, &Logic::LightMedallion, RG_LIGHT_MEDALLION,
                  ITEM_MEDALLION_LIGHT, OBJECT_GI_MEDAL, GID_MEDALLION_LIGHT, 0x40, 0x80, CHEST_ANIM_LONG,
                  ITEM_CATEGORY_MAJOR, MOD_NONE);
}