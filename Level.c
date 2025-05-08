#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "raylib.h"  
#include "Player.h" 
#include "Enemies.h" 
#include "Level.h"

Levels* Levels_Create(int id)
{
    Levels* levels = (Levels*)malloc(sizeof(Levels));
    if (!levels) return NULL;

    levels->id = id;
    levels->start_level = false;
    levels->start_play = false;
    levels->swap = false;
    levels->completed = false;
    levels->restart = false;
    levels->saw_go_left = false;
    levels->saw4_init = false;
    levels->saw5_init = false;
    levels->saw6_init = false;
    levels->saw3_go_up = false;
    levels->saw4_go_up = false;
    levels->saw5_go_up = false;
    levels->saw6_go_up = false;
    levels->got_hit = false;
    levels->game_over = false;
    levels->saw_rotation = 0;

    if (id == 1)
    {
        char levelOne_map[MAP_ROWS][MAP_COLS + 1] = {
        "                                                                                                                                   ",
        "                          o o o o o                                                                                                ",
        "                                                                                                                                   ",
        "                                                                                                                    oo             ",
        "                  oo                                                                                               2113            ",
        "                2111377777777777777777772113                                                                       4005            ",
        "                40005                   4005                                               oooo                 oo 4005            ",
        "                40005                   4005211113             oooooo      89a                                 21134005            ",
        "              oo40021113                4005400005             89999a                                          40054005            ",
        "             21111340005       o        4005400005                                                          oo 40054005            ",
        "             40000540005                4005400005   o                              211377777777772113     211340054005            ",
        "             40000540005      bcd       4005400005  89a               89a           4005          4005     400540054005            ",
        "             40000540005                4005400005       bcd    o                 oo4005          4005     400540054005            ",
        "11111111111111111111111113        8a   21111111113           8889a                2111113        21111111111111111111111111111111  ",
        "00000000000000000000000005 8a          40000000005                                4000005        400000000000000000000000000000000 ",
        "00000000000000000000000005             40000000005                                4000005        400000000000000000000000000000000 ",
        "00000000000000000000000005             40000000005                                4000005        400000000000000000000000000000000 "
        };

        char levelOne_background[MAP_ROWS][MAP_COLS + 1] = {
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   "
        };

    }
    else if (id == 2)
    {

        char levelTwo_map[MAP_ROWS][MAP_COLS + 1] = {
            "                                                                                                                                  ",
            "                                                                                                                                  ",
            "                                                                                                                                  ",
            "                                              oooo                                                                                ",
            "                                                                              o  o  o  o             o                 o          ",
            "                         o                   211113                         211111111111113       2111113                         ",
            "                                             400005                         400000000000005       4000005             bcd         ",
            "                 o                      oooo 400005 oooo     89a            400000000000005       4000005                         ",
            "                    o         o              400005                         400000000000005       4000005211113   89a     89a     ",
            "                                       211113400005211113               2113400000000000005       4000005400005                   ",
            "              bcd  89a  bcd  89a       400005400005400005               4005400000000000005       4000005400005                   ",
            "                                       400005400005400005               400540000000o0o0o05       40o0o05400005                   ",
            "                                       400005400005400005               4005400000000000005       4000005400005                   ",
            "111111111113                      21111111111111111111111            1111111111111111111111       1111111111111111                ",
            "000000000005                      40000000000000000000000            0000000000000000000000       0000000000000000                ",
            "000000000005666666666666666666666640000000000000000000000666666666666000000000000000000000066666660000000000000000                ",
            "000000000005                      40000000000000000000000            0000000000000000000000       0000000000000000                "
        };
        char levelTwo_background[MAP_ROWS][MAP_COLS + 1] = {
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                    00                                                                                                             ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   ",
        "                                                                                                                                   "
        };

        return levels;
    }
}

void Levels_Free(Levels* levels)
{
    if (!levels) return;

    // Free allocated maps
    if (levels->map) {
        for (int i = 0; i < levels->map_rows; i++) {
            if (levels->map[i]) {
                free(levels->map[i]);
            }
        }
        free(levels->map);
    }

    if (levels->map_background) {
        for (int i = 0; i < levels->map_bg_rows; i++) {
            if (levels->map_background[i]) {
                free(levels->map_background[i]);
            }
        }
        free(levels->map_background);
    }

    free(levels);
}

void Levels_SetAudioVolume(Levels* levels)
{
    SetMusicVolume(levels->level1_music, levels->level1_volume);
    SetMusicVolume(levels->level2_music, levels->level2_volume);
    SetSoundVolume(levels->coin_sound, levels->coin_volume);
    SetSoundVolume(levels->life_up_sound, levels->life_up_volume);
}

void Levels_LevelInit(Levels* levels)
{
    while (!levels->start_level)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(levels->font, TextFormat("Level %d", levels->id), levels->level_init_pos, 50, 5, levels->color);
        if (levels->color.a < 255 && !levels->swap)
        {
            if (levels->color.a + 2 > 255)
                levels->color.a--;
            levels->color.a += 2;
        }
        if (levels->color.a == 255)
            levels->swap = true;
        if (levels->swap)
        {
            if (levels->color.a - 2 < 0)
                levels->color.a++;
            levels->color.a -= 2;
        }
        if (levels->color.a == 0)
        {
            levels->swap = false;
            levels->start_level = true;
        }
        EndDrawing();
    }
}

void Levels_Draw(Levels* levels, Player* player)
{
    Levels_LevelInit(levels);
    if (levels->id == 1)
    {
        UpdateMusicStream(levels->level1_music);
        DrawTexturePro(levels->sky_background1, levels->background_src, levels->background_disp1_1, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background1, levels->background_src, levels->background_disp1_2, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background1, levels->background_src, levels->background_disp1_3, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background1, levels->background_src, levels->background_disp1_4, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background1, levels->background_src, levels->background_disp1_5, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background2, levels->background_src, levels->background_disp2_1, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background2, levels->background_src, levels->background_disp2_2, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background2, levels->background_src, levels->background_disp2_3, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background2, levels->background_src, levels->background_disp2_4, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->sky_background2, levels->background_src, levels->background_disp2_5, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->star, levels->star_src, levels->star_disp1, levels->origin, 0, RAYWHITE);
    }
    else if (levels->id == 2)
    {
        UpdateMusicStream(levels->level2_music);
        DrawTexturePro(levels->castle_background, levels->background_src, levels->background_disp3_1, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->castle_background, levels->background_src, levels->background_disp3_2, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->castle_background, levels->background_src, levels->background_disp3_3, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->castle_background, levels->background_src, levels->background_disp3_4, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->castle_background, levels->background_src, levels->background_disp3_5, levels->origin, 0, RAYWHITE);
        DrawTexturePro(levels->star, levels->star_src, levels->star_disp2, levels->origin, 0, RAYWHITE);
    }
    Levels_DrawTiles(levels);
}

void Levels_DrawTiles(Levels* levels)
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            levels->coin_disp.x = j * levels->coin_disp.width;
            levels->coin_disp.y = i * levels->coin_disp.height;
            levels->tile_disp.x = j * levels->tile_disp.width;
            levels->tile_disp.y = i * levels->tile_disp.height;
            Levels_ManageTiles(levels, i, j);
        }
    }
}

void Levels_ManageTiles(Levels* levels, int i, int j)
{
    switch (levels->map_background[i][j])
    {
    case '0':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_center, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_center, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;
    }

    switch (levels->map[i][j])
    {
    case '0':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_center, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_center, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '1':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_topmid, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_topmid, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '2':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_topleft, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_topleft, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '3':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_topright, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_topright, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '4':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_midleft, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_midleft, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '5':
        if (levels->id == 1)
            DrawTexturePro(levels->rock_midright, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        if (levels->id == 2)
            DrawTexturePro(levels->brick_midright, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '6':
        DrawTexturePro(levels->spike, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '7':
        DrawTexturePro(levels->bridge, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '8':
        DrawTexturePro(levels->platform_left, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case '9':
        DrawTexturePro(levels->platform_mid, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case 'a':
        DrawTexturePro(levels->platform_right, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case 'b':
        DrawTexturePro(levels->platform_spike_left, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case 'c':
        DrawTexturePro(levels->platform_spike_mid, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case 'd':
        DrawTexturePro(levels->platform_spike_right, levels->tile_src, levels->tile_disp, levels->origin, 0, RAYWHITE);
        break;

    case 'o':
        DrawTexturePro(levels->coin, levels->tile_src, levels->coin_disp, levels->origin, 0, RAYWHITE);
        break;
    }
}

void Levels_CheckCollisions(Levels* levels, Player* player, Animations* animations, Enemies* enemies)
{
    player->coll.x = animations->player_disp.x + 63;
    player->coll.y = animations->player_disp.y + 76;
    player->foot_coll = (Rectangle){ player->coll.x + 15, player->coll.y + 52, 36, 1 };

    enemies->flame1_coll.x = enemies->animations.flame_disp1_1.x + 68;
    enemies->flame1_coll.y = enemies->animations.flame_disp1_1.y + 68;
    enemies->flame2_coll.x = enemies->animations.flame_disp1_2.x + 68;
    enemies->flame2_coll.y = enemies->animations.flame_disp1_2.y + 68;
    enemies->flame3_coll.x = enemies->animations.flame_disp2_1.x + 68;
    enemies->flame3_coll.y = enemies->animations.flame_disp2_1.y + 68;
    enemies->flame4_coll.x = enemies->animations.flame_disp2_2.x + 68;
    enemies->flame4_coll.y = enemies->animations.flame_disp2_2.y + 68;
    enemies->flame5_coll.x = enemies->animations.flame_disp2_3.x + 68;
    enemies->flame5_coll.y = enemies->animations.flame_disp2_3.y + 68;

    enemies->bird1_coll.x = enemies->animations.bird1_disp.x + 64;
    enemies->bird1_coll.y = enemies->animations.bird1_disp.y + 68;
    enemies->bird2_coll.x = enemies->animations.bird2_disp.x + 64;
    enemies->bird2_coll.y = enemies->animations.bird2_disp.y + 68;
    enemies->bird3_coll.x = enemies->animations.bird3_disp.x + 64;
    enemies->bird3_coll.y = enemies->animations.bird3_disp.y + 68;

    enemies->spider1_coll.x = enemies->animations.spider1_disp.x + 76;
    enemies->spider1_coll.y = enemies->animations.spider1_disp.y + 88;
    enemies->spider2_coll.x = enemies->animations.spider2_disp.x + 76;
    enemies->spider2_coll.y = enemies->animations.spider2_disp.y + 88;
    enemies->spider3_coll.x = enemies->animations.spider3_disp.x + 76;
    enemies->spider3_coll.y = enemies->animations.spider3_disp.y + 88;
    enemies->spider4_coll.x = enemies->animations.spider4_disp.x + 76;
    enemies->spider4_coll.y = enemies->animations.spider4_disp.y + 88;
    enemies->spider5_coll.x = enemies->animations.spider5_disp.x + 76;
    enemies->spider5_coll.y = enemies->animations.spider5_disp.y + 88;

    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            levels->tile_disp = (Rectangle){ j * levels->tile_disp.width, i * levels->tile_disp.height, 64, 64 };
            levels->coin_disp = (Rectangle){ j * levels->coin_disp.width, i * levels->coin_disp.height, 64, 64 };
            Levels_ManageCollisions(levels, player, animations, enemies, i, j);
        }
    }
}

void Levels_ManageCollisions(Levels* levels, Player* player, Animations* animations, Enemies* enemies, int i, int j)
{
    if (CheckCollisionRecs(player->foot_coll, levels->tile_disp))
    {
        if ((levels->map[i][j] == '1' || (levels->map[i][j] == '2' || levels->map[i][j] == '3' ||
            levels->map[i][j] == '8' || levels->map[i][j] == '9' || levels->map[i][j] == 'a') &&
            player->foot_coll.y < levels->tile_disp.y + 30 || levels->map[i][j] == '7') && !player->going_up)
        {
            if (player->foot_coll.y > levels->tile_disp.y &&
                (player->foot_coll.x + player->foot_coll.width > levels->tile_disp.x + levels->tile_disp.width ||
                    player->foot_coll.x < levels->tile_disp.x))
                animations->player_disp.y -= (player->foot_coll.y - levels->tile_disp.y) / 2;
            else if (player->foot_coll.y > levels->tile_disp.y)
                animations->player_disp.y -= (player->foot_coll.y - levels->tile_disp.y);

            player->jump_break = false;
            player->jump = false;
            player->gravity = 0;
        }

        if ((levels->map[i][j] == ' ' || levels->map[i][j] == '0' ||
            (levels->map[i][j] == '2' || levels->map[i][j] == '3' || levels->map[i][j] == '8' ||
                levels->map[i][j] == '9' || levels->map[i][j] == 'a') && player->foot_coll.y >= levels->tile_disp.y ||
            levels->map[i][j] == '4' || levels->map[i][j] == '5') && !player->jump)
        {
            if ((player->foot_coll.x + player->foot_coll.width > levels->tile_disp.x + levels->tile_disp.width ||
                player->foot_coll.x < levels->tile_disp.x) && player->gravity < 5)
                player->gravity += 0.2;
            else
                player->gravity += 0.4;

            animations->player_disp.y += player->gravity;
        }

        if ((levels->map[i][j] == '4' || levels->map[i][j] == '5' ||
            levels->map[i][j] == '2' || levels->map[i][j] == '3') && player->foot_coll.y > 870)
            player->speed.x = 0;

        if (levels->map[i][j] == 'b' || levels->map[i][j] == 'c' ||
            levels->map[i][j] == 'd' || levels->map[i][j] == '6' || player->foot_coll.y >= 1030)
            player->death = true;
    }

    if (CheckCollisionRecs(player->coll, levels->coin_disp))
    {
        if (levels->map[i][j] == 'o')
        {
            PlaySound(levels->coin_sound);
            player->score += 1000;
            if (player->score % 20000 == 0)
            {
                PlaySound(levels->life_up_sound);
                player->lives++;
            }
            levels->map[i][j] = ' ';
        }
    }

    if (CheckCollisionRecs(player->coll, levels->star_disp1) && levels->id == 1)
    {
        levels->completed = true;
        Player_set_pos2(player);
        Enemies_reset_enemies(enemies);
    }

    if (CheckCollisionRecs(player->coll, levels->star_disp2) && levels->id == 2)
        levels->completed = true;

    if ((Levels_CheckCollisionRecsOr(player->coll, levels->saw_disp1, (Vector2) { 75, 75 }) ||
        Levels_CheckCollisionRecsOr(player->coll, levels->saw_disp2, (Vector2) { 75, 75 }) ||
        Levels_CheckCollisionRecsOr(player->coll, levels->saw_disp3, (Vector2) { 75, 75 }) ||
        Levels_CheckCollisionRecsOr(player->coll, levels->saw_disp4, (Vector2) { 75, 75 }) ||
        Levels_CheckCollisionRecsOr(player->coll, levels->saw_disp5, (Vector2) { 75, 75 }) ||
        Levels_CheckCollisionRecsOr(player->coll, levels->saw_disp6, (Vector2) { 75, 75 })) &&
        levels->id == 2 && player->hit_timer < 0)
    {
        PlaySound(player->hit_sound);
        player->hp--;
        player->hit_timer = player->hit_duration;
    }

    if ((Levels_CheckCollisionRecsOr(player->coll, enemies->flame1_coll, (Vector2) { 96, 96 }) ||
        Levels_CheckCollisionRecsOr(player->coll, enemies->flame2_coll, (Vector2) { 96, 96 }) ||
        CheckCollisionRecs(player->coll, enemies->bird1_coll) ||
        CheckCollisionRecs(player->coll, enemies->bird2_coll) ||
        CheckCollisionRecs(player->coll, enemies->bird3_coll)) &&
        levels->id == 1 && player->hit_timer < 0)
    {
        PlaySound(player->hit_sound);
        player->hp--;
        player->hit_timer = player->hit_duration;
    }

    if ((Levels_CheckCollisionRecsOr(player->coll, enemies->flame3_coll, (Vector2) { 96, 96 }) ||
        Levels_CheckCollisionRecsOr(player->coll, enemies->flame4_coll, (Vector2) { 96, 96 }) ||
        Levels_CheckCollisionRecsOr(player->coll, enemies->flame5_coll, (Vector2) { 96, 96 }) ||
        CheckCollisionRecs(player->coll, enemies->spider1_coll) ||
        CheckCollisionRecs(player->coll, enemies->spider2_coll) ||
        CheckCollisionRecs(player->coll, enemies->spider3_coll) ||
        CheckCollisionRecs(player->coll, enemies->spider4_coll) ||
        CheckCollisionRecs(player->coll, enemies->spider5_coll)) &&
        levels->id == 2 && player->hit_timer < 0)
    {
        PlaySound(player->hit_sound);
        player->hp--;
        player->hit_timer = player->hit_duration;
    }

    if (player->hp == 0)
        player->death = true;

    player->hit_timer--;
}

void Levels_ManageSaw(Levels* levels)
{
    levels->saw_rotation += 6;
    if (levels->saw_rotation == 360)
        levels->saw_rotation = 0;

    if (levels->saw_disp1.x < 3750 && !levels->saw_go_left)
        levels->saw_disp1.x += levels->saw_speed;
    if (levels->saw_disp1.x > 2400 && levels->saw_go_left)
        levels->saw_disp1.x -= levels->saw_speed;
    if (levels->saw_disp1.x == 3750)
        levels->saw_go_left = true;
    if (levels->saw_disp1.x == 2400)
        levels->saw_go_left = false;

    if (levels->saw_disp3.y < 300 && !levels->saw3_go_up)
        levels->saw_disp3.y += levels->saw_speed;
    if (levels->saw_disp3.y > 10 && levels->saw3_go_up)
        levels->saw_disp3.y -= levels->saw_speed;
    if (levels->saw_disp3.y == 300)
        levels->saw3_go_up = true;
    if (levels->saw_disp3.y == 10)
        levels->saw3_go_up = false;

    if (levels->saw_disp4.y < 300 && !levels->saw4_go_up)
        levels->saw_disp4.y += levels->saw_speed;
    if (levels->saw_disp4.y > 10 && levels->saw4_go_up)
        levels->saw_disp4.y -= levels->saw_speed;
    if (levels->saw_disp4.y == 300)
        levels->saw4_go_up = true;
    if (levels->saw_disp4.y == 10)
        levels->saw4_go_up = false;

    if (levels->saw_disp5.y < 300 && !levels->saw5_go_up)
        levels->saw_disp5.y += levels->saw_speed;
    if (levels->saw_disp5.y > 10 && levels->saw5_go_up)
        levels->saw_disp5.y -= levels->saw_speed;
    if (levels->saw_disp5.y == 300)
        levels->saw5_go_up = true;
    if (levels->saw_disp5.y == 10)
        levels->saw5_go_up = false;

    if (levels->saw_disp6.y < 300 && !levels->saw6_go_up)
        levels->saw_disp6.y += levels->saw_speed;
    if (levels->saw_disp6.y > 10 && levels->saw6_go_up)
        levels->saw_disp6.y -= levels->saw_speed;
    if (levels->saw_disp6.y == 300)
        levels->saw6_go_up = true;
    if (levels->saw_disp6.y == 10)
        levels->saw6_go_up = false;
}

void Levels_DrawSaw(Levels* levels)
{
    if (levels->id == 2)
    {
        DrawTexturePro(levels->saw, levels->saw_src, levels->saw_disp1, levels->saw_origin, levels->saw_rotation, RAYWHITE);
        DrawTexturePro(levels->saw, levels->saw_src, levels->saw_disp2, levels->saw_origin, levels->saw_rotation, RAYWHITE);
        DrawTexturePro(levels->saw, levels->saw_src, levels->saw_disp3, levels->saw_origin, levels->saw_rotation, RAYWHITE);
        DrawTexturePro(levels->saw, levels->saw_src, levels->saw_disp4, levels->saw_origin, levels->saw_rotation, RAYWHITE);
        DrawTexturePro(levels->saw, levels->saw_src, levels->saw_disp5, levels->saw_origin, levels->saw_rotation, RAYWHITE);
        DrawTexturePro(levels->saw, levels->saw_src, levels->saw_disp6, levels->saw_origin, levels->saw_rotation, RAYWHITE);
    }
}

void Levels_GameOverScreen(Levels* levels, Player* player)
{
    levels->completed = false;
    while (!levels->game_over)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(levels->font, "Game Over", levels->game_over_pos, 150, 10, levels->color);
        if (levels->color.a < 255 && !levels->swap)
        {
            if (levels->color.a + 2 > 255)
                levels->color.a--;
            levels->color.a += 2;
        }
        if (levels->color.a == 255)
            levels->swap = true;
        if (levels->swap)
        {
            if (levels->color.a - 2 < 0)
                levels->color.a++;
            levels->color.a -= 2;
        }
        if (levels->color.a == 0)
        {
            levels->swap = false;
            levels->game_over = true;
        }
        EndDrawing();
    }
}

void Levels_ManageDeath(Levels* levels, Player* player, Enemies* enemies)
{
    if (player->death)
    {
        levels->game_over = false;
        PlaySound(player->death_sound);
        player->lives--;
        if (player->lives <= 0)
            Levels_GameOverScreen(levels, player);
        Player_set_pos3(player); // Assuming this function exists in Player.c
        Enemies_reset_enemies(enemies);
        player->speed.x = 7;
        player->death = false;
    }
}

void Levels_ResetMusic(Levels* levels)
{
    StopMusicStream(levels->level1_music);
    StopMusicStream(levels->level2_music);
    PlayMusicStream(levels->level1_music);
    PlayMusicStream(levels->level2_music);
}

bool Levels_CheckCollisionRecsOr(Rectangle rec1, Rectangle rec2, Vector2 origin)
{
    return
        rec1.x + rec1.width > rec2.x - origin.x && rec1.x < rec2.x + rec2.width - 75 &&
        rec1.y + rec1.height > rec2.y - origin.y && rec1.y < rec2.y + rec2.height - 75;
}