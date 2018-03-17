#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"
#include "scanline_effect.h"

void sub_80DF81C(struct Sprite *sprite);
void sub_80DFBD8(struct Sprite *sprite);

void sub_80DF9F4(u8 taskId);

void sub_80DFAB0(struct Task *task);

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;
extern u8 gBankAttacker;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG2_X;
extern u16 gUnknown_03000730[];
extern u8 gBankSpriteIds[];

// Outrage

void sub_80DF5A0(struct Sprite *sprite)
{
    sprite->pos1.x = GetBankPosition(gAnimBankAttacker, 2);
    sprite->pos1.y = GetBankPosition(gAnimBankAttacker, 3);
    if (GetBankSide(gAnimBankAttacker))
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
        gBattleAnimArgs[4] = -gBattleAnimArgs[4];
    }
    else
        sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[3] = gBattleAnimArgs[4];
    sprite->data[5] = gBattleAnimArgs[5];
    sprite->invisible = 1;
    StoreSpriteCallbackInData(sprite, move_anim_8074EE0);
    sprite->callback = sub_8078504;
}

// part of Dragon Breath

void sub_80DF63C(struct Sprite *sprite)
{
    sub_8078650(sprite);
    sprite->data[2] = GetBankPosition(gAnimBankTarget, 2);
    sprite->data[4] = GetBankPosition(gAnimBankTarget, 3);
    if (GetBankSide(gAnimBankAttacker))
    {
        sprite->pos1.x -= gBattleAnimArgs[1];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] -= gBattleAnimArgs[2];
        sprite->data[4] += gBattleAnimArgs[3];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
        sprite->data[2] += gBattleAnimArgs[2];
        sprite->data[4] += gBattleAnimArgs[3];
        StartSpriteAnim(sprite, 1);
    }
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->callback = StartTranslateAnimSpriteByDeltas;
    StoreSpriteCallbackInData(sprite, move_anim_8074EE0);
}

// Dragon Rage

void sub_80DF6F0(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->pos1.x = GetBankPosition(gAnimBankAttacker, 0);
        sprite->pos1.y = GetBankPosition(gAnimBankAttacker, 1);
    }
    else
    {
        sprite->pos1.x = GetBankPosition(gAnimBankTarget, 0);
        sprite->pos1.y = GetBankPosition(gAnimBankTarget, 1);
    }
    sub_807867C(sprite, gBattleAnimArgs[1]);
    sprite->pos1.y += gBattleAnimArgs[2];
    sprite->callback = sub_8078600;
    StoreSpriteCallbackInData(sprite, move_anim_8074EE0);
}

// Dragon Breath init

void sub_80DF760(struct Sprite *sprite)
{
    if (GetBankSide(gAnimBankAttacker))
        StartSpriteAffineAnim(sprite, 1);
    sub_80DF63C(sprite);
}

//next 2 tasks might be Dragon Dance orbs?

void sub_80DF78C(struct Sprite *sprite)
{
    u16 r5;
    u16 r0;
    sprite->pos1.x = GetBankPosition(gAnimBankAttacker, 2);
    sprite->pos1.y = GetBankPosition(gAnimBankAttacker, 3);
    sprite->data[4] = 0;
    sprite->data[5] = 1;
    sprite->data[6] = gBattleAnimArgs[0];
    r5 = sub_807A100(gBankAttacker, 0);
    r0 = sub_807A100(gBankAttacker, 1);
    if (r5 > r0)
        sprite->data[7] = r5 / 2;
    else
        sprite->data[7] = r0 / 2;
    sprite->pos2.x = Cos(sprite->data[6], sprite->data[7]);
    sprite->pos2.y = Sin(sprite->data[6], sprite->data[7]);
    sprite->callback = sub_80DF81C;
}

void sub_80DF81C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[6] = (sprite->data[6] - sprite->data[5]) & 0xFF;
        sprite->pos2.x = Cos(sprite->data[6], sprite->data[7]);
        sprite->pos2.y = Sin(sprite->data[6], sprite->data[7]);
        if (++sprite->data[4] > 5)
        {
            sprite->data[4] = 0;
            if (sprite->data[5] <= 15 && ++sprite->data[5] > 15)
                sprite->data[5] = 16;
        }
        if (++sprite->data[3] > 0x3C)
        {
            sprite->data[3] = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->data[6] = (sprite->data[6] - sprite->data[5]) & 0xFF;
        if (sprite->data[7] <= 0x95 && (sprite->data[7] += 8) > 0x95)
            sprite->data[7] = 0x96;
        sprite->pos2.x = Cos(sprite->data[6], sprite->data[7]);
        sprite->pos2.y = Sin(sprite->data[6], sprite->data[7]);
        if (++sprite->data[4] > 5)
        {
            sprite->data[4] = 0;
            if (sprite->data[5] <= 15 && ++sprite->data[5] > 15)
                sprite->data[5] = 16;
        }
        if (++sprite->data[3] > 20)
            DestroyAnimSprite(sprite);
        break;
    }
}

// Dragon Dance scanline eff

void sub_80DF924(u8 taskId)
{
    struct ScanlineEffectParams sp;
    struct Task *task = &gTasks[taskId];
    u16 i;
    u8 r1;
    if (GetBankIdentity_permutated(gAnimBankAttacker) == 1)
    {
        sp.dmaDest = &REG_BG1HOFS;
        task->data[2] = gBattle_BG1_X;
    }
    else
    {
        sp.dmaDest = &REG_BG2HOFS;
        task->data[2] = gBattle_BG2_X;
    }
    sp.dmaControl = 0xA2600001;
    sp.initState = 1;
    sp.unused9 = 0;
    r1 = sub_8077FC0(gAnimBankAttacker);
    task->data[3] = r1 - 32;
    task->data[4] = r1 + 32;
    if (task->data[3] < 0)
        task->data[3] = 0;
    for(i = task->data[3];i <= task->data[4];i++)
    {
        gScanlineEffectRegBuffers[0][i] = task->data[2];
        gScanlineEffectRegBuffers[1][i] = task->data[2];
    }
    ScanlineEffect_SetParams(sp);
    task->func = sub_80DF9F4;
}

void sub_80DF9F4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        if (++task->data[7] > 1)
        {
            task->data[7] = 0;
            if (++task->data[6] == 3)
                task->data[0]++;
        }
        sub_80DFAB0(task);
        break;
    case 1:
        if (++task->data[1] > 0x3C)
            task->data[0]++;
        sub_80DFAB0(task);
        break;
    case 2:
        if (++task->data[7] > 1)
        {
            task->data[7] = 0;
            if (--task->data[6] == 0)
                task->data[0]++;
        }
        sub_80DFAB0(task);
        break;
    case 3:
        gScanlineEffect.state = 3;
        task->data[0]++;
        break;
    case 4:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_80DFAB0(struct Task *task)
{
    u16 r3 = task->data[5];
    u16 i;
    for (i = task->data[3]; i <= task->data[4]; i++)
    {
        gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = ((gSineTable[r3] * task->data[6]) >> 7) + task->data[2];
        r3 = (r3 + 8) & 0xFF;
    }
    task->data[5] = (task->data[5] + 9) & 0xFF;
}

// Overheat

void sub_80DFB28(struct Sprite *sprite)
{
    int r6 = (gBattleAnimArgs[2] * 3) / 5;
    int i;
    sprite->pos1.x = GetBankPosition(gAnimBankAttacker, 2);
    sprite->pos1.y = GetBankPosition(gAnimBankAttacker, 3) + gBattleAnimArgs[4];
    sprite->data[1] = Cos(gBattleAnimArgs[1], gBattleAnimArgs[2]);
    sprite->data[2] = Sin(gBattleAnimArgs[1], r6);
    sprite->pos1.x += sprite->data[1] * gBattleAnimArgs[0];
    sprite->pos1.y += sprite->data[2] * gBattleAnimArgs[0];
    sprite->data[3] = gBattleAnimArgs[3];
    sprite->callback = sub_80DFBD8;
    for (i = 0; i <= 6; i++)
        gUnknown_03000730[i] = sprite->data[i];
}

void sub_80DFBD8(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[1];
    sprite->data[5] += sprite->data[2];
    sprite->pos2.x = sprite->data[4] / 10;
    sprite->pos2.y = sprite->data[5] / 10;
    if (++sprite->data[0] > sprite->data[3])
        DestroyAnimSprite(sprite);
}
