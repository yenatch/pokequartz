#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;

extern u8 gBankSpriteIds[];

// unused_7

void sub_80CF374(struct Sprite* sprite)
{
    s16 temp;
    gSprites[sprite->data[2]].pos2.x += sprite->data[1];
    temp = sprite->data[1];
    sprite->data[1] = -temp;
    if (sprite->data[0] == 0)
    {
        gSprites[sprite->data[2]].pos2.x = 0;
        move_anim_8074EE0(sprite);
    }

    sprite->data[0]--;
}

void sub_80CF3C4(struct Sprite* sprite)
{
    u8 a;
    sprite->pos1.x = GetBankPosition(gAnimBankAttacker, 2);
    sprite->pos1.y = GetBankPosition(gAnimBankAttacker, 3);
    a = gBankSpriteIds[gAnimBankTarget];
    if (GetBankSide(gAnimBankAttacker) != 0)
    {
        sprite->pos1.x -= gBattleAnimArgs[0];
    }
    else
    {
        sprite->pos1.x += gBattleAnimArgs[0];
    }

    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = a;
    sprite->callback = sub_80CF374;
    sprite->invisible = 1;
}
