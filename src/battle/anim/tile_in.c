#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;

// tile_in (flips a white tile from the scene into facing the player.)
// Used in Conversion.

void sub_80CE09C(struct Sprite* sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->pos1.x = GetBankPosition(gAnimBankAttacker, 0) + gBattleAnimArgs[0];
        sprite->pos1.y = GetBankPosition(gAnimBankAttacker, 1) + gBattleAnimArgs[1];
        if (IsContest())
            sprite->pos1.y += 10;
        sprite->data[0]++;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyAnimSprite(sprite);
}

void sub_80CE108(u8 taskId)
{
    if (gTasks[taskId].data[2] == 1)
    {
        gBattleAnimArgs[7] = 0xFFFF;
        gTasks[taskId].data[2]++;
    }
    else if (gTasks[taskId].data[2] == 2)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        if (++gTasks[taskId].data[0] == 4)
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1]++;
            REG_BLDALPHA = (gTasks[taskId].data[1] << 8) | (16 - gTasks[taskId].data[1]);
            if (gTasks[taskId].data[1] == 16)
                gTasks[taskId].data[2]++;
        }
    }
}
