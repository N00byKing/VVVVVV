#pragma once

#define V6AP_NUM_CHECKS 20
#define V6AP_NUM_LOCKS 4

#define V6AP_ID_OFFSET 2515000

#define SET_PLAYER_POS(x,y) obj.entities[obj.getplayer()].xp = (x) * 8; \
                obj.entities[obj.getplayer()].yp = ((y) * 8) - obj.entities[obj.getplayer()].h; \
                obj.entities[obj.getplayer()].lerpoldxp = obj.entities[obj.getplayer()].xp; \
                obj.entities[obj.getplayer()].lerpoldyp = obj.entities[obj.getplayer()].yp; \

#define SET_PLAYER_POS_SAFE_ENTRANCE1 SET_PLAYER_POS(36,16)
#define SET_PLAYER_POS_SAFE_ENTRANCE2 SET_PLAYER_POS(36,20)
#define SET_PLAYER_POS_SAFE_ENTRANCE3 SET_PLAYER_POS(13,8)
#define SET_PLAYER_POS_SAFE_ENTRANCE4 SET_PLAYER_POS(35,11)
#define SET_PLAYER_POS_SAFE_EXIT1 SET_PLAYER_POS(1,14)
#define SET_PLAYER_POS_SAFE_EXIT2 SET_PLAYER_POS(1,18)
#define SET_PLAYER_POS_SAFE_EXIT3 SET_PLAYER_POS(8,6)
#define SET_PLAYER_POS_SAFE_EXIT4 SET_PLAYER_POS(2,9)

enum Areas {
    None, Laboratory, TheTower, SpaceStation2, WarpZone
};

void V6AP_Init(const char*, const char*, const char*);
void V6AP_Init(const char*);

// Sends LocationCheck for given index
void V6AP_SendItem(int);

// Local Trinket Amount
int V6AP_GetTrinkets();

// Print Next Message to Screen
void V6AP_PrintNext();

// Returns true if there is an item queued up
bool V6AP_ItemPending();
// Receive one item, if available
void V6AP_RecvClear();

// DeathLink functions
void V6AP_DeathLinkSend();
bool V6AP_DeathLinkPending();
void V6AP_DeathLinkClear();

// Differentiate locations and trinkets
const bool* V6AP_Locations();
const bool* V6AP_Trinkets();

// Called when Story completed, sends StatusUpdate
void V6AP_StoryComplete();

// For music rando
void V6AP_AdjustMusic(int*);

// Check if accessible under current MultiWorld ruleset, if not resets player position to safe value
// If Area Rando is on and the Room is available it will redirect the Room switch to the correct entrance
void V6AP_RoomAvailable(int*,int*);