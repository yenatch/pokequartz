#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;

static void sub_80CCB00(struct Sprite* sprite);

// slice (the cutting animation showing as a yellow line drawn diagonally)
// Used in Cut, Fury Cutter, Aerial Ace, and Air Cutter.

void sub_80CC914(struct Sprite* sprite)
{
    sprite->pos1.x = GetBankPosition(gAnimBankTarget, 0);
    sprite->pos1.y = GetBankPosition(gAnimBankTarget, 1);
    if (GetBankSide(gAnimBankTarget) == 0)
        sprite->pos1.y += 8;

    sprite->callback = sub_80CCB00;
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->pos1.x += gBattleAnimArgs[0];
    }
    else
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->hFlip = 1;
    }

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[1] -= 0x400;
    sprite->data[2] += 0x400;
    sprite->data[5] = gBattleAnimArgs[2];
    if (sprite->data[5] == 1)
        sprite->data[1] = -sprite->data[1];
}

void sub_80CC9BC(struct Sprite* sprite)
{
    u8 a;
    u8 b;
    switch (gBattleAnimArgs[3])
    {
    case 1:
        a = GetBankPosition(gAnimBankTarget ^ 2, 0);
        b = GetBankPosition(gAnimBankTarget ^ 2, 1);
        break;
    case 2:
        a = GetBankPosition(gAnimBankTarget, 0);
        b = GetBankPosition(gAnimBankTarget, 1);
        if (IsAnimBankSpriteVisible(gAnimBankTarget ^ 2))
        {
            a = (GetBankPosition(gAnimBankTarget ^ 2, 0) + a) / 2;
            b = (GetBankPosition(gAnimBankTarget ^ 2, 1) + b) / 2;
        }
        break;
    case 0:
    default:
        a = GetBankPosition(gAnimBankTarget, 0);
        b = GetBankPosition(gAnimBankTarget, 1);
        break;
    }

    sprite->pos1.x = a;
    sprite->pos1.y = b;
    if (GetBankSide(gAnimBankTarget) == 0)
        sprite->pos1.y += 8;

    sprite->callback = sub_80CCB00;
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->pos1.x += gBattleAnimArgs[0];
    }
    else
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        sprite->hFlip = 1;
    }

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[1] -= 0x400;
    sprite->data[2] += 0x400;
    sprite->data[5] = gBattleAnimArgs[2];
    if (sprite->data[5] == 1)
        sprite->data[1] = -sprite->data[1];
}

void sub_80CCB00(struct Sprite* sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    if (sprite->data[5] == 0)
        sprite->data[1] += 0x18;
    else
        sprite->data[1] -= 0x18;

    sprite->data[2] -= 0x18;
    sprite->pos2.x = sprite->data[3] >> 8;
    sprite->pos2.y = sprite->data[4] >> 8;
    sprite->data[0]++;
    if (sprite->data[0] == 20)
    {
        StoreSpriteCallbackInData(sprite, DestroyAnimSprite);
        sprite->data[0] = 3;
        sprite->callback = sub_80782D8;
    }
}
