#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;

static void sub_80CCF70(struct Sprite* sprite);
static void sub_80CD0CC(struct Sprite* sprite, int unk1, int unk2);

// bottle (shows a bottle swinging back and forth.)
// Used by Milk Drink.

void sub_80CCF04(struct Sprite* sprite)
{
    sprite->pos1.x = GetBankPosition(gAnimBankTarget, 2);
    sprite->pos1.y = GetBankPosition(gAnimBankTarget, 3) + 0xFFE8;
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[6] = 0;
    sprite->data[7] = 16;
    REG_BLDCNT = 0x3F40;
    REG_BLDALPHA = (sprite->data[7] << 8) | sprite->data[6];
    sprite->callback = sub_80CCF70;
}

void sub_80CCF70(struct Sprite* sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[2] > 0)
        {
            sprite->data[2] = 0;
            if (((++sprite->data[1]) & 1) != 0)
            {
                if (sprite->data[6] <= 15)
                    sprite->data[6]++;
            }
            else if (sprite->data[7] > 0)
                sprite->data[7]--;

            REG_BLDALPHA = (sprite->data[7] << 8) | sprite->data[6];
            if (sprite->data[6] == 16 && sprite->data[7] == 0)
            {
                sprite->data[1] = 0;
                sprite->data[0]++;
            }
        }
        break;
    case 1:
        if (++sprite->data[1] > 8)
        {
            sprite->data[1] = 0;
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 2:
        sub_80CD0CC(sprite, 16, 4);
        if (++sprite->data[1] > 2)
        {
            sprite->data[1] = 0;
            sprite->pos1.y++;
        }

        if (++sprite->data[2] <= 29)
            break;

        if (sprite->data[2] & 1)
        {
            if (sprite->data[6] > 0)
                sprite->data[6]--;
        }
        else if (sprite->data[7] <= 15)
        {
            sprite->data[7]++;
        }

        REG_BLDALPHA = (sprite->data[7] << 8) | sprite->data[6];
        if (sprite->data[6] == 0 && sprite->data[7] == 16)
        {
            sprite->data[1] = 0;
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->invisible = 1;
        sprite->data[0]++;
        break;
    case 4:
        REG_BLDCNT = 0;
        REG_BLDALPHA = 0;
        DestroyAnimSprite(sprite);
        break;
    }
}

void sub_80CD0CC(struct Sprite* sprite, int unk1, int unk2)
{
    if (sprite->data[3] <= 11)
        sprite->data[4] += 2;

    if ((u16)(sprite->data[3] - 0x12) <= 0x17)
        sprite->data[4] -= 2;

    if ((sprite->data[3]) > 0x2F)
        sprite->data[4] += 2;

    sprite->pos2.x = sprite->data[4] / 9;
    sprite->pos2.y = sprite->data[4] / 14;
    if (sprite->pos2.y < 0)
        sprite->pos2.y *= -1;

    sprite->data[3]++;
    if (sprite->data[3] > 0x3B)
        sprite->data[3] = 0;
}
