#pragma once
#include <stdlib.h>

#include <stdbool.h>

#include <math.h>

#include "raylib.h"  

#include "Player.h" 

#include "Enemies.h" 

#define MAP_ROWS 17
#define MAP_COLS 131

typedef struct Levels {

    Font font;

    Color color;

    Sound life_up_sound;

    Sound coin_sound;

    Music level1_music;

    Music level2_music;

    Texture2D sky_background1;

    Texture2D sky_background2;

    Texture2D castle_background;

    Texture2D coin;

    Texture2D saw;

    Texture2D spike;

    Texture2D star;

    Texture2D bridge;

    Texture2D platform_left;

    Texture2D platform_mid;

    Texture2D platform_right;

    Texture2D platform_spike_left;

    Texture2D platform_spike_mid;

    Texture2D platform_spike_right;

    Texture2D rock_topleft;

    Texture2D rock_topmid;

    Texture2D rock_topright;

    Texture2D rock_midleft;

    Texture2D rock_center;

    Texture2D rock_midright;

    Texture2D brick_topleft;

    Texture2D brick_topmid;

    Texture2D brick_topright;

    Texture2D brick_midleft;

    Texture2D brick_center;

    Texture2D brick_midright;

    Rectangle background_src;

    Rectangle background_disp1_1;

    Rectangle background_disp1_2;

    Rectangle background_disp1_3;

    Rectangle background_disp1_4;

    Rectangle background_disp1_5;

    Rectangle background_disp2_1;

    Rectangle background_disp2_2;

    Rectangle background_disp2_3;

    Rectangle background_disp2_4;

    Rectangle background_disp2_5;

    Rectangle background_disp3_1;

    Rectangle background_disp3_2;

    Rectangle background_disp3_3;

    Rectangle background_disp3_4;

    Rectangle background_disp3_5;

    Rectangle saw_src;

    Rectangle saw_disp1;

    Rectangle saw_disp2;

    Rectangle saw_disp3;

    Rectangle saw_disp4;

    Rectangle saw_disp5;

    Rectangle saw_disp6;

    Rectangle star_src;

    Rectangle star_disp1;

    Rectangle star_disp2;

    Rectangle coin_src;

    Rectangle coin_disp;

    Rectangle tile_src;

    Rectangle tile_disp;

    Vector2 game_over_pos;

    Vector2 level_init_pos;

    Vector2 saw_origin;

    Vector2 origin;

    int id;

    float radius;

    bool start_level;

    bool start_play;

    bool swap;

    bool completed;

    bool restart;

    float saw_speed;

    float saw_rotation;

    bool saw_go_left;

    bool saw4_init;

    bool saw5_init;

    bool saw6_init;

    bool saw3_go_up;

    bool saw4_go_up;

    bool saw5_go_up;

    bool saw6_go_up;

    float life_up_volume;

    float coin_volume;

    float level1_volume;

    float level2_volume;

    bool got_hit;

    int damage_timer;

    bool game_over;

    char** map;

    char** map_background;

    int map_rows;

    int map_cols;

    int map_bg_rows;

    int map_bg_cols;

} Levels;


Levels* Levels_Create(int id);

void Levels_Free(Levels* levels);

void Levels_SetAudioVolume(Levels* levels);

void Levels_LevelInit(Levels* levels);

void Levels_DrawTiles(Levels* levels);

void Levels_Draw(Levels* levels, Player* player);

void Levels_ManageTiles(Levels* levels, int i, int j);

void Levels_CheckCollisions(Levels* levels, Player* player, Animations* animations, Enemies* enemies);

void Levels_ManageCollisions(Levels* levels, Player* player, Animations* animations, Enemies* enemies, int i, int j);

void Levels_ManageSaw(Levels* levels);

void Levels_DrawSaw(Levels* levels);

void Levels_GameOverScreen(Levels* levels, Player* player);

void Levels_ManageDeath(Levels* levels, Player* player, Enemies* enemies);

void Levels_ResetMusic(Levels* levels);

bool Levels_CheckCollisionRecsOr(Rectangle rec1, Rectangle rec2, Vector2 origin);
