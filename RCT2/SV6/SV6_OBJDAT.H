#ifndef SV6_OBJDAT_H
#define SV6_OBJDAT_H

//#include "sv6.h"

typedef struct
{
    DWORD flags;
    char  filename[8];
    DWORD checksum;
} SV6_OBJDAT_HEADER;

/*
    a four byte checksum.
    128 entries for the rides
    252 entries for the small scenery
    128 entries for the large scenery
    128 entries for the walls
    32 entries for the banners
    16 entries for the paths
    15 entries for the path bits
    19 entries for the scenery sets
    1 entry for the park entrance
    1 entry for the water
    1 entry for the "stex" dat file to use
*/

#define SV6_OBJDAT_NUMENTRIES_RIDES 128
#define SV6_OBJDAT_NUMENTRIES_SMALLSCENERY 252
#define SV6_OBJDAT_NUMENTRIES_LARGESCENERY 128
#define SV6_OBJDAT_NUMENTRIES_WALLS 128
#define SV6_OBJDAT_NUMENTRIES_BANNERS 32
#define SV6_OBJDAT_NUMENTRIES_PATHS 16
#define SV6_OBJDAT_NUMENTRIES_PATHUTILITIES 15
#define SV6_OBJDAT_NUMENTRIES_GROUPS 19
#define SV6_OBJDAT_NUMENTRIES_ENTRANCE 1
#define SV6_OBJDAT_NUMENTRIES_PALETTE 1
#define SV6_OBJDAT_NUMENTRIES_SCENARIOTEXT 1
#define SV6_OBJDAT_NUMENTRIES_ALL                                                                                              \
    SV6_OBJDAT_NUMENTRIES_RIDES                                                                                                \
    +SV6_OBJDAT_NUMENTRIES_SMALLSCENERY + SV6_OBJDAT_NUMENTRIES_LARGESCENERY + SV6_OBJDAT_NUMENTRIES_WALLS +                   \
        SV6_OBJDAT_NUMENTRIES_BANNERS + SV6_OBJDAT_NUMENTRIES_PATHS + SV6_OBJDAT_NUMENTRIES_PATHUTILITIES +                    \
        SV6_OBJDAT_NUMENTRIES_GROUPS + SV6_OBJDAT_NUMENTRIES_ENTRANCE + SV6_OBJDAT_NUMENTRIES_PALETTE +                        \
        SV6_OBJDAT_NUMENTRIES_SCENARIOTEXT

#define SV6_OBJDAT_ABBV_RIDES "R"
#define SV6_OBJDAT_ABBV_SMALLSCENERY "SS"
#define SV6_OBJDAT_ABBV_LARGESCENERY "LS"
#define SV6_OBJDAT_ABBV_WALLS "W"
#define SV6_OBJDAT_ABBV_BANNERS "B"
#define SV6_OBJDAT_ABBV_PATHS "P"
#define SV6_OBJDAT_ABBV_PATHUTILITIES "PU"
#define SV6_OBJDAT_ABBV_GROUPS "G"
#define SV6_OBJDAT_ABBV_ENTRANCE "E"
#define SV6_OBJDAT_ABBV_PALETTE "P"
#define SV6_OBJDAT_ABBV_SCENARIOTEXT "ST"
#define SV6_OBJDAT_ABBV_EMPTY "NA"

enum
{
    DAT_TABLE_ENTRY__RIDES = 0,
    DAT_TABLE_ENTRY__SMALLSCENERY,
    DAT_TABLE_ENTRY__LARGESCENERY,
    DAT_TABLE_ENTRY__WALLS,
    DAT_TABLE_ENTRY__BANNERS,
    DAT_TABLE_ENTRY__PATHS,
    DAT_TABLE_ENTRY__PATHUTILITIES,
    DAT_TABLE_ENTRY__GROUPS,
    DAT_TABLE_ENTRY__ENTRANCE,
    DAT_TABLE_ENTRY__PALETTE,
    DAT_TABLE_ENTRY__SCENARIOTEXT,
    DAT_TABLE_ENTRY__NUM_ENTRIES
};

typedef struct
{
    union {
        struct
        {
            SV6_OBJDAT_HEADER
            rides[SV6_OBJDAT_NUMENTRIES_RIDES], smallScenery[SV6_OBJDAT_NUMENTRIES_SMALLSCENERY],
                largeScenery[SV6_OBJDAT_NUMENTRIES_LARGESCENERY], walls[SV6_OBJDAT_NUMENTRIES_WALLS],
                banners[SV6_OBJDAT_NUMENTRIES_BANNERS], paths[SV6_OBJDAT_NUMENTRIES_PATHS],
                pathUtilities[SV6_OBJDAT_NUMENTRIES_PATHUTILITIES], groups[SV6_OBJDAT_NUMENTRIES_GROUPS],
                entrance[SV6_OBJDAT_NUMENTRIES_ENTRANCE], palette[SV6_OBJDAT_NUMENTRIES_PALETTE],
                scenarioText[SV6_OBJDAT_NUMENTRIES_SCENARIOTEXT];
        };
        SV6_OBJDAT_HEADER
        items[SV6_OBJDAT_NUMENTRIES_ALL];
    };
} SV6_OBJDAT_HEADER_BLOCK;

typedef struct
{
    union {
        struct
        {
            SV6_OBJDAT_HEADER
            rides[SV6_OBJDAT_NUMENTRIES_RIDES], smallScenery[SV6_OBJDAT_NUMENTRIES_SMALLSCENERY],
                largeScenery[SV6_OBJDAT_NUMENTRIES_LARGESCENERY], walls[SV6_OBJDAT_NUMENTRIES_WALLS],
                banners[SV6_OBJDAT_NUMENTRIES_BANNERS], paths[SV6_OBJDAT_NUMENTRIES_PATHS],
                pathUtilities[SV6_OBJDAT_NUMENTRIES_PATHUTILITIES], groups[SV6_OBJDAT_NUMENTRIES_GROUPS],
                entrance[SV6_OBJDAT_NUMENTRIES_ENTRANCE], palette[SV6_OBJDAT_NUMENTRIES_PALETTE],
                scenarioText[SV6_OBJDAT_NUMENTRIES_SCENARIOTEXT];
        };
        SV6_OBJDAT_HEADER objs[SV6_OBJDAT_NUMENTRIES_ALL];
    };
} SV6_OBJDAT_HEADER_BLOCK_ALT;

typedef enum { USED, UNUSED } TYPE_USAGEFLAG;

typedef struct
{
    TYPE_USAGEFLAG
    usedFlag;
    char objName[9];
} SV6_OBJDAT_STRINGTABLE_ENTRY, SV6_OBJDAT_STRINGTABLE[SV6_OBJDAT_NUMENTRIES_ALL];

typedef enum {
    QUEUE,
    PATH,
    EMPTYENTRY,
    PATHADD,
    PA_VANDALIZED

} PATHTYPE;

typedef struct
{
    BYTE  pathType;
    DWORD mapIndex;
    char  filename[9];
} SV6_PATH_RCT1_TO_RCT2_MAPSTRUCT;

#ifndef OBJ_FIX

SV6_OBJDAT_HEADER_BLOCK RCT1emulationTable;
SV6_OBJDAT_HEADER       redWater;

InitObjects();

#endif // OBJ_FIX

#endif // SV6_OBJDAT_H
