#include "global.h"
#include "rom_8077ABC.h"
#include "trig.h"
#include "battle_anim.h"
#include "sound.h"

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;

extern struct AffineAnimFrameCmd gUnknown_083D76F4;

static void sub_80D07AC(u8 taskId);

// splash (splash effect of hopping up and down)
// Used in Splash, Mud Sport, and Sketch.

void sub_80D074C(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    if (gBattleAnimArgs[1] == 0)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        u8 spriteId = GetAnimBankSpriteId(gBattleAnimArgs[0]);
        task->data[0] = spriteId;
        task->data[1] = 0;
        task->data[2] = gBattleAnimArgs[1];
        task->data[3] = 0;
        task->data[4] = 0;
        sub_80798F4(task, spriteId, &gUnknown_083D76F4);
        task->func = sub_80D07AC;
    }
}

void sub_80D07AC(u8 taskId)
{
    struct Task* task = &gTasks[taskId];
    switch (task->data[1])
    {
    case 0:
        sub_807992C(task);
        task->data[4] += 3;
        gSprites[task->data[0]].pos2.y += task->data[4];
        if (++task->data[3] > 7)
        {
            task->data[3] = 0;
            task->data[1]++;
        }
        break;
    case 1:
        sub_807992C(task);
        gSprites[task->data[0]].pos2.y += task->data[4];
        if (++task->data[3] > 7)
        {
            task->data[3] = 0;
            task->data[1]++;
        }
        break;
    case 2:
        if (task->data[4] != 0)
        {
            gSprites[task->data[0]].pos2.y -= 2;
            task->data[4] -= 2;
        }
        else
            task->data[1]++;
        break;
    case 3:
        if (!sub_807992C(task))
        {
            if (--task->data[2] == 0)
            {
                gSprites[task->data[0]].pos2.y = 0;
                DestroyAnimVisualTask(taskId);
            }
            else
            {
                sub_80798F4(task, task->data[0], &gUnknown_083D76F4);
                task->data[1] = 0;
            }
        }
        break;
    }
}
