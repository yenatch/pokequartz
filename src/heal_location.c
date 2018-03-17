#include "global.h"
#include "heal_location.h"
#include "constants/maps.h"

#define NUM_HEAL_LOCATIONS 22

static const struct HealLocation sHealLocations[] =
{
    {MAP_GROUP(LITTLEROOT_TOWN_BRENDANS_HOUSE_2F), MAP_NUM(LITTLEROOT_TOWN_BRENDANS_HOUSE_2F), 4, 2},
    {MAP_GROUP(LITTLEROOT_TOWN_MAYS_HOUSE_2F), MAP_NUM(LITTLEROOT_TOWN_MAYS_HOUSE_2F), 4, 2},
    {MAP_GROUP(PETALBURG_CITY), MAP_NUM(PETALBURG_CITY), 20, 17},
    {MAP_GROUP(SLATEPORT_CITY), MAP_NUM(SLATEPORT_CITY), 19, 20},
    {MAP_GROUP(MAUVILLE_CITY), MAP_NUM(MAUVILLE_CITY), 22, 6},
    {MAP_GROUP(RUSTBORO_CITY), MAP_NUM(RUSTBORO_CITY), 16, 39},
    {MAP_GROUP(FORTREE_CITY), MAP_NUM(FORTREE_CITY), 5, 7},
    {MAP_GROUP(LILYCOVE_CITY), MAP_NUM(LILYCOVE_CITY), 24, 15},
    {MAP_GROUP(MOSSDEEP_CITY), MAP_NUM(MOSSDEEP_CITY), 28, 17},
    {MAP_GROUP(SOOTOPOLIS_CITY), MAP_NUM(SOOTOPOLIS_CITY), 43, 32},
    {MAP_GROUP(EVER_GRANDE_CITY), MAP_NUM(EVER_GRANDE_CITY), 27, 49},
    {MAP_GROUP(LITTLEROOT_TOWN), MAP_NUM(LITTLEROOT_TOWN), 5, 9},
    {MAP_GROUP(LITTLEROOT_TOWN), MAP_NUM(LITTLEROOT_TOWN), 14, 9},
    {MAP_GROUP(OLDALE_TOWN), MAP_NUM(OLDALE_TOWN), 6, 17},
    {MAP_GROUP(DEWFORD_TOWN), MAP_NUM(DEWFORD_TOWN), 2, 11},
    {MAP_GROUP(LAVARIDGE_TOWN), MAP_NUM(LAVARIDGE_TOWN), 9, 7},
    {MAP_GROUP(FALLARBOR_TOWN), MAP_NUM(FALLARBOR_TOWN), 14, 8},
    {MAP_GROUP(VERDANTURF_TOWN), MAP_NUM(VERDANTURF_TOWN), 16, 4},
    {MAP_GROUP(PACIFIDLOG_TOWN), MAP_NUM(PACIFIDLOG_TOWN), 8, 16},
    {MAP_GROUP(EVER_GRANDE_CITY), MAP_NUM(EVER_GRANDE_CITY), 18, 6},
    {MAP_GROUP(BATTLE_TOWER_OUTSIDE), MAP_NUM(BATTLE_TOWER_OUTSIDE), 14, 9},
    {MAP_GROUP(SOUTHERN_ISLAND_EXTERIOR), MAP_NUM(SOUTHERN_ISLAND_EXTERIOR), 15, 20},
};

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum)
{
    u32 i;

    for (i = 0; i < NUM_HEAL_LOCATIONS; i++)
    {
        if (sHealLocations[i].group == mapGroup && sHealLocations[i].map == mapNum)
            return i + 1;
    }
    return 0;
}

const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum)
{
    u32 index = GetHealLocationIndexByMap(mapGroup, mapNum);

    if (index == 0)
        return NULL;
    else
        return &sHealLocations[index - 1];
}

const struct HealLocation *GetHealLocation(u32 index)
{
    if (index == 0)
        return NULL;
    else if (index > NUM_HEAL_LOCATIONS)
        return NULL;
    else
        return &sHealLocations[index - 1];
}
