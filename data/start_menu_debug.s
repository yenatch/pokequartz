	.if DEBUG

#include "constants/moves.h"
	.include "include/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

Str_839BD90:: @ 0x839BD90
	.string "ジュンイチ$"

Str_839BD96:: @ 0x839BD96
	.string "ダイゴロウ$"

Str_839BD9C:: @ 0x839BD9C
	.string "テツジ$"

Str_839BDA0:: @ 0x839BDA0
	.string "バレンシア$"

Str_839BDA6:: @ 0x839BDA6
	.string "ハルコマチ$"

Str_839BDAC:: @ 0x839BDAC
	.string "RAYMOND$"

Str_839BDB4:: @ 0x839BDB4
	.string "TIFFANY$"

Str_839BDBC:: @ 0x839BDBC
	.string "くまxちえ$"

	.align 2
gUnknown_Debug_839BDC4:: @ 0x839BDC4
	.4byte Str_839BD90, 0x0
	.4byte Str_839BD96, 0x0
	.4byte Str_839BDA0, 0x1
	.4byte Str_839BDA6, 0x1
	.4byte Str_839BDAC, 0x80
	.4byte Str_839BDB4, 0x81
	.4byte Str_839BD9C, 0x0
	.4byte Str_839BDBC, 0x1

Str_839BE04:: @ 0x839BE04
	.string "ID$"

Str_839BE07:: @ 0x839BE07
	.string "X$"

Str_839BE09:: @ 0x839BE09
	.string " Y$"

Str_839BE0C:: @ 0x839BE0C
	.string " H$"

Str_839BE0F:: @ 0x839BE0F
	.string "HP$"

Str_839BE12:: @ 0x839BE12
	.string "PAR$"

Str_839BE16:: @ 0x839BE16
	.string "SLP$"

Str_839BE1A:: @ 0x839BE1A
	.string "PSN$"

Str_839BE1E:: @ 0x839BE1E
	.string "ウマイ$"

	.align 2
gUnknown_Debug_839BE24:: @ 0x839BE24
	.4byte Str_839BE0F, DebugMenu_8077434+1
	.4byte Str_839BE12, DebugMenu_8077434+1
	.4byte Str_839BE16, DebugMenu_8077434+1
	.4byte Str_839BE1A, DebugMenu_8077434+1
	.4byte Str_839BE1E, DebugMenu_8077434+1

Str_839BE4C:: @ 0x839BE4C
	.string "OFF$"

Str_839BE50:: @ 0x839BE50
	.string "ON$"

Str_839BE53:: @ 0x839BE53
	.string "BG0\n"
	.string "BG1\n"
	.string "BG2\n"
	.string "BG3\n"
	.string "$"

Str_839BE64:: @ 0x839BE64
	.string "ON$"

Str_839BE67:: @ 0x839BE67
	.string "OFF$"

Str_839BE6B:: @ 0x839BE6B
	.string "さいせんかのうトレーナー:{STR_VAR_1}\n"
	.string "さいせんじょうたいトレーナー:{STR_VAR_2}$"

Str_839BE8D:: @ 0x839BE8D
	.string "いる$"

Str_839BE90:: @ 0x839BE90
	.string "いない$"

Str_839BE94:: @ 0x839BE94
	.string "Max num of steps$"

Str_839BEA5:: @ 0x839BEA5
	.string "Clear num of steps$"

Str_839BEB8:: @ 0x839BEB8
	.string "See trainers$"

Str_839BEC5:: @ 0x839BEC5
	.string "Flag all clear$"

Str_839BED4:: @ 0x839BED4
	.string "Flag all set$"

	.align 2
gUnknown_Debug_839BEE4:: @ 0x839BEE4
	.4byte Str_839BEB8, DebugMenu_8077974+1
	.4byte Str_839BE94, DebugMenu_8077A20+1
	.4byte Str_839BEA5, DebugMenu_8077A40+1
	.4byte Str_839BED4, DebugMenu_8077934+1
	.4byte Str_839BEC5, DebugMenu_8077954+1

Str_839BF0C:: @ 0x839BF0C
	.string "のこり　{STR_VAR_1}ほ$"

Str_839BF14:: @ 0x839BF14
	.string "{STR_VAR_1}\n"
	.string "のこり　{STR_VAR_2}ほ$"

Str_839BF1F:: @ 0x839BF1F
	.string "めのまえには\n"
	.string "キューブが　ありません！$"

Str_839BF33:: @ 0x839BF33
	.string "ほすうをのこり1にする$"

Str_839BF3F:: @ 0x839BF3F
	.string "ボールをのこり1にする$"

Str_839BF4B:: @ 0x839BF4B
	.string "キューブおきば$"

Str_839BF53:: @ 0x839BF53
	.string "ボールをのこり30に$"

Str_839BF5E:: @ 0x839BF5E
	.string "ほすうをのこり500に$"

	.align 2
gUnknown_Debug_839BF6C:: @ 0x839BF6C
	.4byte Str_839BF4B, DebugMenu_8077B00+1
	.4byte Str_839BF5E, DebugMenu_8077ACC+1
	.4byte Str_839BF33, DebugMenu_8077AE8+1
	.4byte Str_839BF53, DebugMenu_8077A9C+1
	.4byte Str_839BF3F, DebugMenu_8077AB4+1

gUnknown_Debug_839BF94:: @ 0x839BF94
	.4byte gMoveNames + 13 * MOVE_CUT, DebugMenu_8077BB4+1
	.4byte gMoveNames + 13 * MOVE_FLASH, DebugMenu_8077BC0+1
	.4byte gMoveNames + 13 * MOVE_ROCK_SMASH, DebugMenu_8077BCC+1
	.4byte gMoveNames + 13 * MOVE_STRENGTH, DebugMenu_8077BD8+1
	.4byte gMoveNames + 13 * MOVE_SURF, debug_sub_80B0770+1
	.4byte gMoveNames + 13 * MOVE_FLY, debug_sub_80B07B0+1
	.4byte gMoveNames + 13 * MOVE_WATERFALL, DebugMenu_8077BE4+1
	.4byte gMoveNames + 13 * MOVE_DIVE, debug_sub_80B0800+1
	.4byte gMoveNames + 13 * MOVE_SECRET_POWER, DebugMenu_8077BF4+1

Str_839BFDC:: @ 0x839BFDC
	.string "　じかん　ふん　びょう$"

gUnknown_Debug_839BFE8::
	.byte 0x63, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00

Str_839C008: @ 0x839C008
gDebug0x839C008::
	.string "Which item?$"

Str_839C014:: @ 0x839C014
	.string "How　many？$"

Str_839C01E:: @ 0x839C01E
	.string "にがおえ　ばんごう\n"
	.string "ポケモンナンバー\n"
	.string "ポケモンめい\n"
	.string "ブリーダーめい\n"
	.string "しゅるい\n"
	.string "こせいらんすう$"

Str_839C04D:: @ 0x839C04D
	.string "データなし$"

Str_839C053:: @ 0x839C053
	.string "Miracle Island emerged\n"
	.string "Random numbers:{STR_VAR_1}$"

Str_839C07C:: @ 0x839C07C
	.string "{STR_VAR_1}:{STR_VAR_2}\n"
	.string "{STR_VAR_3}$"

Str_839C085:: @ 0x839C085
	.string "みしよう　データ$"

Str_839C08E:: @ 0x839C08E
	.string "Confirmation$"

Str_839C09B:: @ 0x839C09B
	.string "Max-1 set$"

Str_839C0A5:: @ 0x839C0A5
	.string "Zero clear$"

Str_839C0B0:: @ 0x839C0B0
	.string "レポート$"

Str_839C0B5:: @ 0x839C0B5
    .string "クリア　じかん$"

Str_839C0BD:: @ 0x839C0BD
	.string "りゅうこう　さくせい$"

Str_839C0C8:: @ 0x839C0C8
	.string "きのみを　うえたかいすう$"

Str_839C0D5:: @ 0x839C0D5
	.string "じてんしゃこうかん$"

Str_839C0DF:: @ 0x839C0DF
	.string "ほすう$"

Str_839C0E3:: @ 0x839C0E3
	.string "インタビュー$"

Str_839C0EA:: @ 0x839C0EA
	.string "バトル$"

Str_839C0EE:: @ 0x839C0EE
	.string "やせいバトル$"

Str_839C0F5:: @ 0x839C0F5
	.string "トレーナーバトル$"

Str_839C0FE:: @ 0x839C0FE
	.string "でんどういり$"

Str_839C105:: @ 0x839C105
	.string "ポケモンほかく$"

Str_839C10D:: @ 0x839C10D
	.string "つった　かいすう$"

Str_839C116:: @ 0x839C116
	.string "タマゴかえった$"

Str_839C11E:: @ 0x839C11E
	.string "しんかした$"

Str_839C124:: @ 0x839C124
	.string "ポケセン　かいふく$"

Str_839C12E:: @ 0x839C12E
	.string "じたく　かいふく$"

Str_839C137:: @ 0x839C137
	.string "サファリ　りよう$"

Str_839C140:: @ 0x839C140
	.string "ひでん:いあいぎり$"

Str_839C14A:: @ 0x839C14A
	.string "ひでん:いわくだき$"

Str_839C154:: @ 0x839C154
	.string "きち　ひっこし$"

Str_839C15C:: @ 0x839C15C
	.string "つうしんこうかん$"

Str_839C165:: @ 0x839C165
	.string "つうしんたいせん$"

Str_839C16E:: @ 0x839C16E
	.string "つうしん　かち$"

Str_839C176:: @ 0x839C176
	.string "つうしん　まけ$"

Str_839C17E:: @ 0x839C17E
	.string "つうしん　ひきわけ$"

Str_839C188:: @ 0x839C188
	.string "わざ:はねる$"

Str_839C18F:: @ 0x839C18F
	.string "わざ:わるあがき$"

Str_839C198:: @ 0x839C198
	.string "スロットおおあたりかいすう$"

Str_839C1A6:: @ 0x839C1A6
	.string "ルーレット　れんしょう$"

Str_839C1B2:: @ 0x839C1B2
	.string "バトルタワー$"

Str_839C1B9:: @ 0x839C1B9
	.string "バトルタワーかち$"

Str_839C1C2:: @ 0x839C1C2
	.string "バトルタワーれんしょう$"

Str_839C1CE:: @ 0x839C1CE
	.string "ポロックさくせい$"

Str_839C1D7:: @ 0x839C1D7
	.string "つうしんでポロックつくった$"

Str_839C1E5:: @ 0x839C1E5
	.string "つうしんコンテストかち$"

Str_839C1F1:: @ 0x839C1F1
	.string "CPUコンテストさんか$"

Str_839C1FD:: @ 0x839C1FD
	.string "CPUコンテストかち$"

Str_839C208:: @ 0x839C208
	.string "かいもの$"

Str_839C20D:: @ 0x839C20D
	.string "ダウジングマシン$"

Str_839C216:: @ 0x839C216
	.string "あめふり$"

Str_839C21B:: @ 0x839C21B
	.string "ずかんをみた$"

Str_839C222:: @ 0x839C222
	.string "リボン　もらった$"

Str_839C22B:: @ 0x839C22B
	.string "だんさ　とびおり$"

Str_839C234:: @ 0x839C234
	.string "TVを　みた$"

Str_839C23B:: @ 0x839C23B
	.string "とけいを　みた$"

Str_839C243:: @ 0x839C243
	.string "くじが　あたった$"

Str_839C24C:: @ 0x839C24C
	.string "ポケモンあずけた$"

Str_839C255:: @ 0x839C255
	.string "ロープウェイりよう$"

Str_839C25F:: @ 0x839C25F
	.string "おんせん　はいった$"

	.align 2
gUnknown_Debug_839C26C:: @ 0x839C26C
	.4byte 0xFFFFFF, Str_839C0B0
	.4byte 0x3E73B3B, Str_839C0B5
	.4byte 0xFFFFFF, Str_839C0BD
	.4byte 0xFFFFFF, Str_839C0C8
	.4byte 0xFFFFFF, Str_839C0D5
	.4byte 0xFFFFFF, Str_839C0DF
	.4byte 0xFFFFFF, Str_839C0E3
	.4byte 0xFFFFFF, Str_839C0EA
	.4byte 0xFFFFFF, Str_839C0EE
	.4byte 0xFFFFFF, Str_839C0F5
	.4byte 0x3E7, Str_839C0FE
	.4byte 0xFFFFFF, Str_839C105
	.4byte 0xFFFFFF, Str_839C10D
	.4byte 0xFFFFFF, Str_839C116
	.4byte 0xFFFFFF, Str_839C11E
	.4byte 0xFFFFFF, Str_839C124
	.4byte 0xFFFFFF, Str_839C12E
	.4byte 0xFFFFFF, Str_839C137
	.4byte 0xFFFFFF, Str_839C140
	.4byte 0xFFFFFF, Str_839C14A
	.4byte 0xFFFFFF, Str_839C154
	.4byte 0xFFFFFF, Str_839C15C
	.4byte 0xFFFFFF, Str_839C165
	.4byte 0x270F, Str_839C16E
	.4byte 0x270F, Str_839C176
	.4byte 0x270F, Str_839C17E
	.4byte 0xFFFFFF, Str_839C188
	.4byte 0xFFFFFF, Str_839C18F
	.4byte 0xFFFFFF, Str_839C198
	.4byte 0xFFFFFF, Str_839C1A6
	.4byte 0xFFFFFF, Str_839C1B2
	.4byte 0x0, Str_839C1B9
	.4byte 0x0, Str_839C1C2
	.4byte 0xFFFFFF, Str_839C1CE
	.4byte 0xFFFFFF, Str_839C1D7
	.4byte 0xFFFFFF, Str_839C1E5
	.4byte 0xFFFFFF, Str_839C1F1
	.4byte 0xFFFFFF, Str_839C1FD
	.4byte 0xFFFFFF, Str_839C208
	.4byte 0xFFFFFF, Str_839C20D
	.4byte 0xFFFFFF, Str_839C216
	.4byte 0xFFFFFF, Str_839C21B
	.4byte 0xFFFFFF, Str_839C222
	.4byte 0xFFFFFF, Str_839C22B
	.4byte 0xFFFFFF, Str_839C234
	.4byte 0xFFFFFF, Str_839C23B
	.4byte 0xFFFFFF, Str_839C243
	.4byte 0xFFFFFF, Str_839C24C
	.4byte 0xFFFFFF, Str_839C255
	.4byte 0xFFFFFF, Str_839C25F

gUnknown_Debug_839C3FC:: @ 0x839C3FC
	.4byte Str_839C08E, DebugMenu_8078774+1
	.4byte Str_839C09B, DebugMenu_8078788+1
	.4byte Str_839C0A5, DebugMenu_807879C+1

Str_839C414:: @ 0x839C414
	.string "ATTR:{STR_VAR_1}　HEIGHT:{STR_VAR_3}\n"
	.string "CODE:{STR_VAR_2}$"

Str_839C42E:: @ 0x839C42E
	.string "レベル　　ステージ$"

Str_839C438:: @ 0x839C438
	.string "ポロック　グループ{STR_VAR_1}$"

gUnknown_Debug_839C444::
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00
	.byte 0x0c, 0x03, 0x03, 0x03, 0x03, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

Str_839C574:: @ 0x839C574
gDebug0x839C574::
	.string "write to flash$"

Str_839C583:: @ 0x839C583
	.string "read from flash$"

	.align 2
gUnknown_Debug_839C594:: @ 0x839C594
	.4byte gDebug0x839C574, DebugMenu_8078C80+1
	.4byte Str_839C583, DebugMenu_8078D30+1

Str_839C5A4:: @ 0x839C5A4
	.string "Press A, begin to write\n"
	.string "Press B, cancel$"

Str_839C5CC:: @ 0x839C5CC
	.string "かきこみ　せいこう$"

Str_839C5D6:: @ 0x839C5D6
	.string "よみこみせいこう$"

Str_839C5DF:: @ 0x839C5DF
	.string "かきこみ　しっぱい$"

Str_839C5E9:: @ 0x839C5E9
	.string "よみこみ　しっぱい$"

	.align 1
gUnknown_Debug_839C5F4::
	.byte 0x00, 0x00, 0xe7, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x09, 0x03, 0x00, 0x00

Str_839C60C:: @ 0x839C60C
gDebug0x839C60C::
	.string "Set FLASH ERR$"

Str_839C61A:: @ 0x839C61A
	.string "abcde;　abcde:　ABCDE;　ABCDE:\p"
	.string "Tableaux　des　verbes　du　2{SUPER_E}　groupe.\p"
	.string "La1{SUPER_RE}　chose　à apprendre　c’est　de　lire.\p"
	.string "Tableaux　des　verbes　du　1{SUPER_ER}　groupe.\p"
	.string "“あいうえおかきくけコさしすせそたちつてとな”\n"
	.string "<にぬネのはひふへほマみむめもやゆよらりるれろわャッ>\p"
	.string "をんゃゅょアイウエオカキクケサシスルレロワ,$"

	.endif
