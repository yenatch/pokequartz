#include "global.h"
#include "task.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "sound.h"

struct MultichoiceListStruct
{
    struct MenuAction *list;
    u8 count;
};

extern const struct MultichoiceListStruct gMultichoiceLists[];

extern u16 gScriptResult;

void DrawMultichoiceMenu(u8, u8, u8, struct MenuAction *list, u8, u8);
void sub_80B53B4(u8, u8, u8, struct MenuAction *list, u8);
void sub_80B52B4(u8);
void sub_80B5230(u8, u8, u8, u8, u8, u8);
void task_yes_no_maybe(u8);
void sub_80B5684(u8);

bool8 sub_80B5054(u8 left, u8 top, u8 var3, u8 var4)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        DrawMultichoiceMenu(left, top, gMultichoiceLists[var3].count, gMultichoiceLists[var3].list, var4, 0);
        return TRUE;
    }
}

bool8 sub_80B50B0(u8 left, u8 top, u8 var3, u8 var4, u8 var5)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        DrawMultichoiceMenu(left, top, gMultichoiceLists[var3].count, gMultichoiceLists[var3].list, var4, var5);
        return TRUE;
    }
}

u16 GetStringWidthInTilesForScriptMenu(u8 *str)
{
    // each tile on screen is 8x8, so it needs the number of tiles and not pixels, hence the division by 8.
    return (GetStringWidthGivenWindowConfig((struct WindowConfig *)&gWindowConfig_81E6CE4, str) + 7) / 8;
}

void DrawMultichoiceMenu(u8 left, u8 top, u8 count, struct MenuAction *list, u8 var4, u8 cursorPos)
{
    u16 width = GetStringWidthInTilesForScriptMenu(list[0].text);
    u16 newWidth;
    u8 i;
    u8 right;
    u8 bottom;

    for(i = 1; i < count; i++)
    {
        newWidth = GetStringWidthInTilesForScriptMenu(list[i].text);
        if(width < newWidth)
            width = newWidth;
    }

    right = width;
    right = (right + left) + 1;

    if(right > 29)
    {
        left = left + (29 - right);
        right = 29;
    }

    bottom = top + (2 * count + 1);

    MenuDrawTextWindow(left, top, right, bottom);
    PrintMenuItems(left + 1, top + 1, count, list);
    InitMenu(0, left + 1, top + 1, count, cursorPos, right - left - 1);
    sub_80B5230(left, top, right, bottom, var4, count);
}

void sub_80B5230(u8 left, u8 top, u8 right, u8 bottom, u8 unkVar, u8 count)
{
    u8 taskId = CreateTask(sub_80B52B4, 80);

    gTasks[taskId].data[0] = left;
    gTasks[taskId].data[1] = top;
    gTasks[taskId].data[2] = right;
    gTasks[taskId].data[3] = bottom;
    gTasks[taskId].data[4] = unkVar;

    if(count > 3)
        gTasks[taskId].data[5] = TRUE;
    else
        gTasks[taskId].data[5] = FALSE;
}

void sub_80B52B4(u8 taskId)
{
    s8 var;

    if(!gPaletteFade.active)
    {
        if(!gTasks[taskId].data[5])
            var = ProcessMenuInputNoWrap();
        else
            var = ProcessMenuInput();

        if(var != -2)
        {
            if(var == -1)
            {
                if(!gTasks[taskId].data[4])
                {
                    PlaySE(5);
                    gScriptResult = 127;
                }
                else
                {
                    return;
                }
            }
            else
            {
                gScriptResult = var;
            }
            sub_8072DEC();
            MenuZeroFillWindowRect(gTasks[taskId].data[0], gTasks[taskId].data[1], gTasks[taskId].data[2], gTasks[taskId].data[3]);
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
    }
}

bool8 Multichoice(u8 var1, u8 var2, u8 var3, u8 var4)
{
    if(FuncIsActiveTask(sub_80B52B4) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        sub_80B53B4(var1, var2, gMultichoiceLists[var3].count, gMultichoiceLists[var3].list, var4);
        return TRUE;
    }
}

void sub_80B53B4(u8 left, u8 top, u8 count, struct MenuAction *list, u8 var4)
{
    u16 width = GetStringWidthInTilesForScriptMenu(list[0].text);
    u16 newWidth;
    u8 i;
    u8 right;
    u8 bottom;

    for(i = 1; i < count; i++)
    {
        newWidth = GetStringWidthInTilesForScriptMenu(list[i].text);
        if(width < newWidth)
            width = newWidth;
    }

    right = width;
    right = (right + left) + 2;
    bottom = top + (2 * count + 1);

    PrintMenuItems(left, top, count, list);
    InitMenu(0, left, top, count, 0, right - left - 1);
    sub_80B5230(left, top, right, bottom, var4, count);
}

bool8 yes_no_box(u8 var1, u8 var2)
{
    u8 taskId;

    if(FuncIsActiveTask(task_yes_no_maybe) == 1)
        return FALSE;
    else
    {
        gScriptResult = 0xFF;
        DisplayYesNoMenu(var1, var2, 1);
        taskId = CreateTask(task_yes_no_maybe, 0x50);
        gTasks[taskId].data[0] = var1;
        gTasks[taskId].data[1] = var2;
        return TRUE;
    }
}

// unused
bool8 IsScriptActive(void)
{
    if(gScriptResult == 0xFF)
        return FALSE;
    else
        return TRUE;
}

void task_yes_no_maybe(u8 taskId)
{
    u8 left, top;

    if (gTasks[taskId].data[2] < 5)
    {
        gTasks[taskId].data[2]++;
        return;
    }

    switch (ProcessMenuInputNoWrap())
    {
    case -2:
        return;
    case -1:
    case 1:
        PlaySE(5);
        gScriptResult = 0;
        break;
    case 0:
        gScriptResult = 1;
        break;
    }

    left = gTasks[taskId].data[0];
    top = gTasks[taskId].data[1];

    MenuZeroFillWindowRect(left, top, left + 6, top + 5);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 sub_80B5578(u8 left, u8 top, u8 multichoiceId, u8 a4, u8 columnCount)
{
    u8 bottom = 0;

    if (FuncIsActiveTask(sub_80B5684) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 width;

        gScriptResult = 255;

        sub_807274C(left, top, gMultichoiceLists[multichoiceId].count, 0, gMultichoiceLists[multichoiceId].list, columnCount, 0);

        taskId = CreateTask(sub_80B5684, 80);

        if (!((gMultichoiceLists[multichoiceId].count >> 1) < columnCount || (gMultichoiceLists[multichoiceId].count & 1))
         || columnCount == 1 || gMultichoiceLists[multichoiceId].count == columnCount)
        {
            bottom = (2 * (gMultichoiceLists[multichoiceId].count / columnCount)) + 1 + top;
        }
        else
        {
            bottom = (2 * (gMultichoiceLists[multichoiceId].count / columnCount)) + 3 + top;
        }

        width = sub_807288C(columnCount);
        gTasks[taskId].data[0] = left;
        gTasks[taskId].data[1] = top;
        gTasks[taskId].data[2] = width + left + 2;
        gTasks[taskId].data[3] = bottom;
        gTasks[taskId].data[4] = a4;
        return TRUE;
    }
}

void sub_80B5684(u8 taskId)
{
    s8 var = sub_80727CC();

    if (var != -2)
    {
        if (var == -1)
        {
            if (!gTasks[taskId].data[4])
            {
                PlaySE(5);
                gScriptResult = 127;
            }
            else
            {
                return;
            }
        }
        else
        {
            gScriptResult = var;
        }
        sub_8072DEC();
        MenuZeroFillWindowRect(gTasks[taskId].data[0], gTasks[taskId].data[1], gTasks[taskId].data[2], gTasks[taskId].data[3]);
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}