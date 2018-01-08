#include "global.h"
#include "graphics.h"
#include "mail_data.h"
#include "constants/species.h"
#include "sprite.h"

#define POKE_ICON_BASE_PAL_TAG 56000

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

const u8 * const gMonIconTable[] =
{
    gMonIcon_Pokemon_000,
    gMonIcon_Chapebaya,
    gMonIcon_Denpecha,
    gMonIcon_Denfrota,
    gMonIcon_Coalchu,
    gMonIcon_Rallama,
    gMonIcon_Roellama,
    gMonIcon_Todad,
    gMonIcon_Shroad,
    gMonIcon_Bultoad,
    gMonIcon_Larvet,
    gMonIcon_Morfade,
    gMonIcon_Eyefly,
    gMonIcon_Drosofly,
    gMonIcon_Metagaster,
    gMonIcon_Phylafly,
    gMonIcon_Ornlil,
    gMonIcon_Wasoo,
    gMonIcon_Volateo,
    gMonIcon_Batoka,
    gMonIcon_Mouspid,
    gMonIcon_Turkur,
    gMonIcon_Peakur,
    gMonIcon_Chuk_Txu,
    gMonIcon_Leeckey,
    gMonIcon_Covolts,
    gMonIcon_Lucivots,
    gMonIcon_Nole,
    gMonIcon_Groundoe,
    gMonIcon_Urtiga,
    gMonIcon_Urtigere,
    gMonIcon_Venogena,
    gMonIcon_Urtigo,
    gMonIcon_Urtigoro,
    gMonIcon_Venogeno,
    gMonIcon_Amairi,
    gMonIcon_Ograiri,
    gMonIcon_Hormig,
    gMonIcon_Llamose,
    gMonIcon_Fatte,
    gMonIcon_Glotten,
    gMonIcon_Stulo,
    gMonIcon_Fungio,
    gMonIcon_Semilleto,
    gMonIcon_Flocepan,
    gMonIcon_Arquidea,
    gMonIcon_Streek,
    gMonIcon_Loggre,
    gMonIcon_Capritle,
    gMonIcon_Deeretle,
    gMonIcon_Armorito,
    gMonIcon_Armorazo,
    gMonIcon_Ankori,
    gMonIcon_Fureep,
    gMonIcon_Pulsul,
    gMonIcon_Koropul,
    gMonIcon_Darkoon,
    gMonIcon_Huntoon,
    gMonIcon_Tikika,
    gMonIcon_Tikiriki,
    gMonIcon_Poocher,
    gMonIcon_Wappy,
    gMonIcon_Riwoof,
    gMonIcon_Ivoro,
    gMonIcon_Dreamo,
    gMonIcon_Mammare,
    gMonIcon_Kango,
    gMonIcon_Kinboxo,
    gMonIcon_Punchzo,
    gMonIcon_Fentee,
    gMonIcon_Helento,
    gMonIcon_Felechoe,
    gMonIcon_Pikish,
    gMonIcon_Lionegosh,
    gMonIcon_Jonic,
    gMonIcon_Doric,
    gMonIcon_Corint,
    gMonIcon_Flachow,
    gMonIcon_Furning,
    gMonIcon_Crabix,
    gMonIcon_Dzoibix,
    gMonIcon_Spingen,
    gMonIcon_Duosgen,
    gMonIcon_Blahdalah,
    gMonIcon_Bubel,
    gMonIcon_Scentbird,
    gMonIcon_Norion,
    gMonIcon_Phantan,
    gMonIcon_Salama,
    gMonIcon_Mantiga,
    gMonIcon_Gallum,
    gMonIcon_Airdiv,
    gMonIcon_Gappy,
    gMonIcon_Ninnin,
    gMonIcon_Surhorn,
    gMonIcon_Shega,
    gMonIcon_Zeeco,
    gMonIcon_Psirilla,
    gMonIcon_Mechcrab,
    gMonIcon_Bobcrab,
    gMonIcon_Spiki,
    gMonIcon_Eliko,
    gMonIcon_Sespiral,
    gMonIcon_Dendriral,
    gMonIcon_Vugoo,
    gMonIcon_Monkoodu,
    gMonIcon_Klevalt,
    gMonIcon_Klesung,
    gMonIcon_Sikedonke,
    gMonIcon_Powergas,
    gMonIcon_Pasqall,
    gMonIcon_Rocorrodo,
    gMonIcon_Cornodro,
    gMonIcon_Karidari,
    gMonIcon_Captrunke,
    gMonIcon_Bankedon,
    gMonIcon_Plures,
    gMonIcon_Dracoon,
    gMonIcon_Piscy,
    gMonIcon_Dolphe,
    gMonIcon_Prawby,
    gMonIcon_Prawking,
    gMonIcon_Bethin,
    gMonIcon_Beetespuk,
    gMonIcon_Saximau,
    gMonIcon_Ektron,
    gMonIcon_Garsoom,
    gMonIcon_Tejemeje,
    gMonIcon_Furran,
    gMonIcon_Thundish,
    gMonIcon_Thundran,
    gMonIcon_Shacker,
    gMonIcon_Eyendy,
    gMonIcon_Cwabay,
    gMonIcon_Wetway,
    gMonIcon_Joylway,
    gMonIcon_Heatway,
    gMonIcon_Arbeluc,
    gMonIcon_Spiraulix,
    gMonIcon_Messaurix,
    gMonIcon_Fishix,
    gMonIcon_Cefasokix,
    gMonIcon_Beakodoron,
    gMonIcon_Boultan,
    gMonIcon_Bereuga,
    gMonIcon_Emethe,
    gMonIcon_Paratiki,
    gMonIcon_Mithedaon,
    gMonIcon_Whirldraon,
    gMonIcon_Migthdra,
    gMonIcon_Zengredse,
    gMonIcon_Wiami,
    gMonIcon_Potac,
    gMonIcon_Tubirato,
    gMonIcon_Ogritato,
    gMonIcon_Lavlon,
    gMonIcon_Magbol,
    gMonIcon_Canlava,
    gMonIcon_Shelldan,
    gMonIcon_Licka,
    gMonIcon_Tongrito,
    gMonIcon_Furbee,
    gMonIcon_Morkibia,
    gMonIcon_Kiwirawa,
    gMonIcon_Kiawariwa,
    gMonIcon_Bzby,
    gMonIcon_Kwimbee,
    gMonIcon_Verpillar,
    gMonIcon_Triworn,
    gMonIcon_Tostol,
    gMonIcon_Eloru,
    gMonIcon_Aenguile,
    gMonIcon_Gusvolts,
    gMonIcon_Airi,
    gMonIcon_Fookid,
    gMonIcon_Madnut,
    gMonIcon_Woodird,
    gMonIcon_Freion,
    gMonIcon_Coronneo,
    gMonIcon_Teamon,
    gMonIcon_Grasspark,
    gMonIcon_Sooregat,
    gMonIcon_Frucpao,
    gMonIcon_Beavon,
    gMonIcon_Umbeavella,
    gMonIcon_Coccnuto,
    gMonIcon_Pitdog,
    gMonIcon_Sproof,
    gMonIcon_Peatoof,
    gMonIcon_Ividigi,
    gMonIcon_Bongon,
    gMonIcon_Thinkower,
    gMonIcon_Flathinker,
    gMonIcon_Taermity,
    gMonIcon_Racevish,
    gMonIcon_Loddish,
    gMonIcon_Blosway,
    gMonIcon_Indinny,
    gMonIcon_Tankoo,
    gMonIcon_Craprax,
    gMonIcon_Magiken,
    gMonIcon_Cornscript,
    gMonIcon_Medrake,
    gMonIcon_Zhipo,
    gMonIcon_Moroberry,
    gMonIcon_Boongory,
    gMonIcon_Bludlop,
    gMonIcon_Vamkiri,
    gMonIcon_Shelcual,
    gMonIcon_Grecodale,
    gMonIcon_Alligrale,
    gMonIcon_Bellyo,
    gMonIcon_Drilluk,
    gMonIcon_Sangai,
    gMonIcon_Betal,
    gMonIcon_Deemp,
    gMonIcon_Trufkip,
    gMonIcon_Trufalo,
    gMonIcon_Burnco,
    gMonIcon_Flameco,
    gMonIcon_Hurgoose,
    gMonIcon_Donigoni,
    gMonIcon_Flysh,
    gMonIcon_Trodic,
    gMonIcon_Tidalo,
    gMonIcon_Polbear,
    gMonIcon_Arbatross,
    gMonIcon_Sneetchy,
    gMonIcon_Garedar,
    gMonIcon_Farizard,
    gMonIcon_Dralula,
    gMonIcon_Bernardog,
    gMonIcon_Rescudog,
    gMonIcon_Emrev,
    gMonIcon_Grazilla,
    gMonIcon_Ninjice,
    gMonIcon_Aztakle,
    gMonIcon_Chinnakle,
    gMonIcon_Jarximaux,
    gMonIcon_Etod,
    gMonIcon_Tarsony,
    gMonIcon_Gurtan,
    gMonIcon_Conqari,
    gMonIcon_Titatoad,
    gMonIcon_Titafrota,
    gMonIcon_Titallama,
    gMonIcon_Crogronk,
    gMonIcon_Skankrin,
    gMonIcon_Baestalix,
    gMonIcon_Vivaczo,
    gMonIcon_Shaddire,
    gMonIcon_Mothatura,
    gMonIcon_Pokemon_252,
    gMonIcon_Pokemon_253,
    gMonIcon_Pokemon_254,
    gMonIcon_Pokemon_255,
    gMonIcon_Pokemon_256,
    gMonIcon_Pokemon_257,
    gMonIcon_Pokemon_258,
    gMonIcon_Pokemon_259,
    gMonIcon_Pokemon_260,
    gMonIcon_Pokemon_261,
    gMonIcon_Pokemon_262,
    gMonIcon_Pokemon_263,
    gMonIcon_Pokemon_264,
    gMonIcon_Pokemon_265,
    gMonIcon_Pokemon_266,
    gMonIcon_Pokemon_267,
    gMonIcon_Pokemon_268,
    gMonIcon_Pokemon_269,
    gMonIcon_Pokemon_270,
    gMonIcon_Pokemon_271,
    gMonIcon_Pokemon_272,
    gMonIcon_Pokemon_273,
    gMonIcon_Pokemon_274,
    gMonIcon_Pokemon_275,
    gMonIcon_Pokemon_276,
    gMonIcon_Seegg,
    gMonIcon_Flowaby,
    gMonIcon_Jardino,
    gMonIcon_Firegg,
    gMonIcon_Embaby,
    gMonIcon_Tyradino,
    gMonIcon_Aquegg,
    gMonIcon_Ornaby,
    gMonIcon_Oceadino,
    gMonIcon_Sever,
    gMonIcon_Ayewiraz,
    gMonIcon_Squirriti,
    gMonIcon_Acornel,
    gMonIcon_Larvly,
    gMonIcon_Cricoon,
    gMonIcon_Cricrit,
    gMonIcon_Composcoon,
    gMonIcon_Flynfly,
    gMonIcon_Weedo,
    gMonIcon_Flosea,
    gMonIcon_Weedalgu,
    gMonIcon_Cactino,
    gMonIcon_Cacutu,
    gMonIcon_Dessertea,
    gMonIcon_Gustano,
    gMonIcon_Duostano,
    gMonIcon_Phico,
    gMonIcon_Reabari,
    gMonIcon_Ruycantor,
    gMonIcon_Strawbaya,
    gMonIcon_Dendrock,
    gMonIcon_Bounny,
    gMonIcon_Bolichano,
    gMonIcon_Pelichen,
    gMonIcon_Hovebug,
    gMonIcon_Planebug,
    gMonIcon_Colossio,
    gMonIcon_Descomune,
    gMonIcon_Babos,
    gMonIcon_Osoe,
    gMonIcon_Mimikat,
    gMonIcon_Goduck,
    gMonIcon_Dukamid,
    gMonIcon_Deprip,
    gMonIcon_Coalchar,
    gMonIcon_Fatube,
    gMonIcon_Soie,
    gMonIcon_Corongori,
    gMonIcon_Tincrab,
    gMonIcon_Searoket,
    gMonIcon_Helixet,
    gMonIcon_Icish,
    gMonIcon_Freech,
    gMonIcon_Awhol,
    gMonIcon_Whola,
    gMonIcon_Progon,
    gMonIcon_Rubygon,
    gMonIcon_Saphiregon,
    gMonIcon_Energiz,
    gMonIcon_Musclelc,
    gMonIcon_Plug_Oink,
    gMonIcon_Spig,
    gMonIcon_Llamayama,
    gMonIcon_Chimneyama,
    gMonIcon_Coldchick,
    gMonIcon_Freezock,
    gMonIcon_Cottoster,
    gMonIcon_Apinep,
    gMonIcon_Pinark,
    gMonIcon_Spinwing,
    gMonIcon_Bobeguin,
    gMonIcon_Clostar,
    gMonIcon_Stargo,
    gMonIcon_Beavy,
    gMonIcon_Tigat,
    gMonIcon_Tigator,
    gMonIcon_Amede,
    gMonIcon_Amedi,
    gMonIcon_Hooley,
    gMonIcon_Mindum,
    gMonIcon_Minadoom,
    gMonIcon_Jackan,
    gMonIcon_Lotbird,
    gMonIcon_Boguon,
    gMonIcon_Guinette,
    gMonIcon_Woopet,
    gMonIcon_Fairoot,
    gMonIcon_Ronslept,
    gMonIcon_Leirao,
    gMonIcon_Dorliron,
    gMonIcon_Simpleon,
    gMonIcon_Dobleon,
    gMonIcon_Liofang,
    gMonIcon_Tynigon,
    gMonIcon_Balagon,
    gMonIcon_Iguagon,
    gMonIcon_Berchi,
    gMonIcon_Mejiyonson,
    gMonIcon_Loapa,
    gMonIcon_Agoir,
    gMonIcon_Catalon,
    gMonIcon_Mazalon,
    gMonIcon_Onike,
    gMonIcon_Copycatte,
    gMonIcon_Monkoor,
    gMonIcon_Opail,
    gMonIcon_Hompalon,
    gMonIcon_Gemmal,
    gMonIcon_Kotokabe,
    gMonIcon_Armay,
    gMonIcon_Armstorm,
    gMonIcon_Torido,
    gMonIcon_Dotori,
    gMonIcon_Enyendrode,
    gMonIcon_Mongostre,
    gMonIcon_Hamet,
    gMonIcon_Ratelo,
    gMonIcon_Psimouse,
    gMonIcon_Dristal,
    gMonIcon_Feegon,
    gMonIcon_Drahago,
    gMonIcon_Tenry,
    gMonIcon_Wrestoro,
    gMonIcon_Wrestmilk,
    gMonIcon_Molebas,
    gMonIcon_Dugobas,
    gMonIcon_Lapibas,
    gMonIcon_Kaomare,
    gMonIcon_Kaosune,
    gMonIcon_Peezgal,
    gMonIcon_Ordkip,
    gMonIcon_Tanord,
    gMonIcon_Karendi,
    gMonIcon_Garotao,
    gMonIcon_Gritespec,

    gMonIcon_Egg,

/*
    gMonIcon_UnownB,
    gMonIcon_UnownC,
    gMonIcon_UnownD,
    gMonIcon_UnownE,
    gMonIcon_UnownF,
    gMonIcon_UnownG,
    gMonIcon_UnownH,
    gMonIcon_UnownI,
    gMonIcon_UnownJ,
    gMonIcon_UnownK,
    gMonIcon_UnownL,
    gMonIcon_UnownM,
    gMonIcon_UnownN,
    gMonIcon_UnownO,
    gMonIcon_UnownP,
    gMonIcon_UnownQ,
    gMonIcon_UnownR,
    gMonIcon_UnownS,
    gMonIcon_UnownT,
    gMonIcon_UnownU,
    gMonIcon_UnownV,
    gMonIcon_UnownW,
    gMonIcon_UnownX,
    gMonIcon_UnownY,
    gMonIcon_UnownZ,
    gMonIcon_UnownExclamationMark,
    gMonIcon_UnownQuestionMark,
*/

};

const u8 gMonIconPaletteIndices[] =
{
    0, // ??????????
    1, // Bulbasaur
    1, // Ivysaur
    1, // Venusaur
    0, // Charmander
    0, // Charmeleon
    0, // Charizard
    0, // Squirtle
    2, // Wartortle
    2, // Blastoise
    1, // Caterpie
    1, // Metapod
    0, // Butterfree
    1, // Weedle
    2, // Kakuna
    2, // Beedrill
    0, // Pidgey
    0, // Pidgeotto
    0, // Pidgeot
    2, // Rattata
    1, // Raticate
    0, // Spearow
    0, // Fearow
    2, // Ekans
    2, // Arbok
    2, // Pikachu
    0, // Raichu
    2, // Sandshrew
    2, // Sandslash
    2, // Nidoran♀
    2, // Nidorina
    2, // Nidoqueen
    2, // Nidoran♂
    2, // Nidorino
    2, // Nidoking
    0, // Clefairy
    0, // Clefable
    2, // Vulpix
    1, // Ninetales
    0, // Jigglypuff
    0, // Wigglytuff
    2, // Zubat
    2, // Golbat
    1, // Oddish
    0, // Gloom
    0, // Vileplume
    0, // Paras
    0, // Parasect
    0, // Venonat
    2, // Venomoth
    2, // Diglett
    2, // Dugtrio
    1, // Meowth
    1, // Persian
    1, // Psyduck
    2, // Golduck
    1, // Mankey
    2, // Primeape
    0, // Growlithe
    0, // Arcanine
    0, // Poliwag
    0, // Poliwhirl
    0, // Poliwrath
    2, // Abra
    2, // Kadabra
    2, // Alakazam
    0, // Machop
    2, // Machoke
    0, // Machamp
    1, // Bellsprout
    1, // Weepinbell
    1, // Victreebel
    2, // Tentacool
    2, // Tentacruel
    1, // Geodude
    1, // Graveler
    1, // Golem
    0, // Ponyta
    0, // Rapidash
    0, // Slowpoke
    0, // Slowbro
    0, // Magnemite
    0, // Magneton
    1, // Farfetch'd
    2, // Doduo
    2, // Dodrio
    2, // Seel
    2, // Dewgong
    2, // Grimer
    2, // Muk
    2, // Shellder
    2, // Cloyster
    2, // Gastly
    2, // Haunter
    2, // Gengar
    2, // Onix
    2, // Drowzee
    1, // Hypno
    2, // Krabby
    2, // Kingler
    0, // Voltorb
    0, // Electrode
    0, // Exeggcute
    1, // Exeggutor
    1, // Cubone
    1, // Marowak
    2, // Hitmonlee
    2, // Hitmonchan
    1, // Lickitung
    2, // Koffing
    2, // Weezing
    1, // Rhyhorn
    1, // Rhydon
    0, // Chansey
    0, // Tangela
    1, // Kangaskhan
    0, // Horsea
    0, // Seadra
    0, // Goldeen
    0, // Seaking
    2, // Staryu
    2, // Starmie
    0, // Mr. mime
    1, // Scyther
    2, // Jynx
    1, // Electabuzz
    0, // Magmar
    2, // Pinsir
    2, // Tauros
    0, // Magikarp
    0, // Gyarados
    2, // Lapras
    2, // Ditto
    2, // Eevee
    0, // Vaporeon
    0, // Jolteon
    0, // Flareon
    0, // Porygon
    0, // Omanyte
    0, // Omastar
    2, // Kabuto
    2, // Kabutops
    0, // Aerodactyl
    1, // Snorlax
    0, // Articuno
    0, // Zapdos
    0, // Moltres
    0, // Dratini
    0, // Dragonair
    2, // Dragonite
    2, // Mewtwo
    0, // Mew
    1, // Chikorita
    1, // Bayleef
    1, // Meganium
    1, // Cyndaquil
    1, // Quilava
    1, // Typhlosion
    2, // Totodile
    2, // Croconaw
    2, // Feraligatr
    2, // Sentret
    2, // Furret
    2, // Hoothoot
    2, // Noctowl
    0, // Ledyba
    0, // Ledian
    1, // Spinarak
    0, // Ariados
    2, // Crobat
    2, // Chinchou
    0, // Lanturn
    0, // Pichu
    0, // Cleffa
    1, // Igglybuff
    2, // Togepi
    2, // Togetic
    0, // Natu
    0, // Xatu
    2, // Mareep
    0, // Flaaffy
    0, // Ampharos
    1, // Bellossom
    2, // Marill
    2, // Azumarill
    1, // Sudowoodo
    1, // Politoed
    1, // Hoppip
    1, // Skiploom
    2, // Jumpluff
    2, // Aipom
    1, // Sunkern
    1, // Sunflora
    1, // Yanma
    0, // Wooper
    0, // Quagsire
    2, // Espeon
    2, // Umbreon
    2, // Murkrow
    0, // Slowking
    0, // Misdreavus
    0, // Unown A
    0, // Wobbuffet
    1, // Girafarig
    0, // Pineco
    2, // Forretress
    2, // Dunsparce
    2, // Gligar
    0, // Steelix
    0, // Snubbull
    2, // Granbull
    0, // Qwilfish
    0, // Scizor
    1, // Shuckle
    2, // Heracross
    0, // Sneasel
    0, // Teddiursa
    2, // Ursaring
    0, // Slugma
    0, // Magcargo
    2, // Swinub
    2, // Piloswine
    0, // Corsola
    0, // Remoraid
    0, // Octillery
    0, // Delibird
    2, // Mantine
    0, // Skarmory
    0, // Houndour
    0, // Houndoom
    0, // Kingdra
    0, // Phanpy
    0, // Donphan
    0, // Porygon2
    2, // Stantler
    1, // Smeargle
    2, // Tyrogue
    2, // Hitmontop
    1, // Smoochum
    1, // Elekid
    1, // Magby
    1, // Miltank
    1, // Blissey
    0, // Raikou
    2, // Entei
    0, // Suicune
    1, // Larvitar
    0, // Pupitar
    1, // Tyranitar
    0, // Lugia
    1, // Ho-Oh
    1, // Celebi
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    0, // ?
    1, // Treecko
    0, // Grovyle
    1, // Sceptile
    0, // Torchic
    0, // Combusken
    0, // Blaziken
    0, // Mudkip
    0, // Marshtomp
    0, // Swampert
    2, // Poochyena
    2, // Mightyena
    2, // Zigzagoon
    2, // Linoone
    0, // Wurmple
    2, // Silcoon
    0, // Beautifly
    2, // Cascoon
    1, // Dustox
    1, // Lotad
    1, // Lombre
    1, // Ludicolo
    1, // Seedot
    1, // Nuzleaf
    0, // Shiftry
    1, // Nincada
    1, // Ninjask
    1, // Shedinja
    2, // Taillow
    2, // Swellow
    1, // Shroomish
    1, // Breloom
    1, // Spinda
    0, // Wingull
    0, // Pelipper
    2, // Surskit
    0, // Masquerain
    2, // Wailmer
    0, // Wailord
    0, // Skitty
    2, // Delcatty
    1, // Kecleon
    1, // Baltoy
    0, // Claydol
    0, // Nosepass
    1, // Torkoal
    2, // Sableye
    0, // Barboach
    0, // Whiscash
    0, // Luvdisc
    0, // Corphish
    0, // Crawdaunt
    2, // Feebas
    0, // Milotic
    0, // Carvanha
    0, // Sharpedo
    1, // Trapinch
    1, // Vibrava
    1, // Flygon
    2, // Makuhita
    1, // Hariyama
    1, // Electrike
    0, // Manectric
    1, // Numel
    0, // Camerupt
    2, // Spheal
    2, // Sealeo
    0, // Walrein
    1, // Cacnea
    1, // Cacturne
    2, // Snorunt
    0, // Glalie
    1, // Lunatone
    0, // Solrock
    2, // Azurill
    0, // Spoink
    2, // Grumpig
    0, // Plusle
    0, // Minun
    2, // Mawile
    0, // Meditite
    0, // Medicham
    0, // Swablu
    0, // Altaria
    0, // Wynaut
    0, // Duskull
    0, // Dusclops
    0, // Roselia
    2, // Slakoth
    2, // Vigoroth
    1, // Slaking
    1, // Gulpin
    2, // Swalot
    1, // Tropius
    0, // Whismur
    2, // Loudred
    2, // Exploud
    0, // Clamperl
    0, // Huntail
    0, // Gorebyss
    0, // Absol
    0, // Shuppet
    0, // Banette
    2, // Seviper
    0, // Zangoose
    1, // Relicanth
    2, // Aron
    2, // Lairon
    2, // Aggron
    0, // Castform
    0, // Volbeat
    2, // Illumise
    2, // Lileep
    0, // Cradily
    0, // Anorith
    0, // Armaldo
    1, // Ralts
    1, // Kirlia
    1, // Gardevoir
    2, // Bagon
    2, // Shelgon
    0, // Salamence
    0, // Beldum
    0, // Metang
    0, // Metagross
    2, // Regirock
    2, // Regice
    2, // Registeel
    2, // Kyogre
    0, // Groudon
    1, // Rayquaza
    0, // Latias
    2, // Latios
    0, // Jirachi
    0, // Deoxys
    0, // Chimecho
    1, // Egg
    0, // Unown B
    0, // Unown C
    0, // Unown D
    0, // Unown E
    0, // Unown F
    0, // Unown G
    0, // Unown H
    0, // Unown I
    0, // Unown J
    0, // Unown K
    0, // Unown L
    0, // Unown M
    0, // Unown N
    0, // Unown O
    0, // Unown P
    0, // Unown Q
    0, // Unown R
    0, // Unown S
    0, // Unown T
    0, // Unown U
    0, // Unown V
    0, // Unown W
    0, // Unown X
    0, // Unown Y
    0, // Unown Z
    0, // Unown Exclamation Mark
    0, // Unown Question Mark
};

const struct SpritePalette gMonIconPaletteTable[] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },

// There are only 3 actual palettes. The following are unused
// and don't point to valid data.
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

static const struct OamData sMonIconOamData =
{
    .size = 2,
    .priority = 1,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

const u16 sSpriteImageSizes[3][4] =
{
    // square
    {
         0x20, // 1×1
         0x80, // 2×2
        0x200, // 4×4
        0x800, // 8×8
    },

    // horizontal rectangle
    {
         0x40, // 2×1
         0x80, // 4×1
        0x100, // 4×2
        0x400, // 8×4
    },

    // vertical rectangle
    {
         0x40, // 1×2
         0x80, // 1×4
        0x100, // 2×4
        0x400, // 4×8
    },
};

u16 GetUnownLetterByPersonality(u32);
const u8 *GetMonIconPtr(u16, u32 personality);
u8 UpdateMonIconFrame(struct Sprite *);
u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
void sub_809D7E8(struct Sprite *);

// duplicate of sub_809D3A4
u8 unref_sub_809D26C(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = gMonIconTable[species],
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtr(species, personality),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (species > SPECIES_EGG)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 sub_809D3A4(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = gMonIconTable[species],
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 mon_icon_convert_unown_species_id(u16 species, u32 personality)
{
    u16 result;

    if (species == SPECIES_UNOWN)
    {
        u16 letter = GetUnownLetterByPersonality(personality);
        if (letter == 0)
            letter = SPECIES_UNOWN;
        else
            letter += (SPECIES_UNOWN_B - 1);
        result = letter;
    }
    else
    {
        if (species > SPECIES_EGG)
            result = 260;
        else
            result = species;
    }

    return result;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    return (((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 0x3)) % 0x1C;
}

u16 sub_809D4A8(u16 species)
{
    u16 value;

    if (MailSpeciesToSpecies(species, &value) == SPECIES_UNOWN)
    {
        if (value == 0)
            value += SPECIES_UNOWN;
        else
            value += (SPECIES_UNOWN_B - 1);
        return value;
    }
    else
    {
        return mon_icon_convert_unown_species_id(species, 0);
    }
}

const u8 *GetMonIconPtr(u16 species, u32 personality)
{
    u16 convertedSpecies = mon_icon_convert_unown_species_id(species, personality);
    return gMonIconTable[convertedSpecies];
}

void sub_809D510(struct Sprite *sprite)
{
    sub_809D7E8(sprite);
}

void sub_809D51C(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > SPECIES_EGG)
        species = 260;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void sub_809D580(u16 species)
{
    u8 palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

// unused
void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < 6; i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > SPECIES_EGG)
        species = 260;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void sub_809D608(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void sub_809D62C(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

// TODO: try to find a way to avoid using asm statement
u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP,
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            {
                register u8 duration asm("r0") = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration;
                sprite->animDelayCounter = duration;
            }
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = 0xFFFF,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

void sub_809D7E8(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void sub_809D824(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
