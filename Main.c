#include "Menu.h"

#include "Enemies.h"

int main(void)

{

    InitWindow(0, 0, "Super Mango");

    ToggleFullscreen();

    InitAudioDevice();

    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    Image icon = LoadImage("resources/icon.png");

    SetWindowIcon(icon);

    Menu menu;

    Levels* level_1 = Levels_Create(1);

    Levels* level_2 = Levels_Create(2);

    Player player;

    Enemies enemies;

    Menu_Initialize(&menu);

    Player_init(&player);

    Enemies_init(&enemies);

    while (menu.init)

        Menu_InitAnimation(&menu);

    PlayMusicStream(level_1->level1_music);

    PlayMusicStream(level_2->level2_music);

    PlayMusicStream(menu.menu_music);

    PlayMusicStream(menu.ending_music);

    while (!menu.exit_game)

    {

        BeginDrawing();

        if (!menu.start_game)

        {

            if (!menu.keybindings)

                Menu_Draw(&menu);

            else

                Menu_DrawKeybindings(&menu);

            Menu_CheckButton(&menu);

            Player_set_pos1(&player);

            Menu_ResetLvl(&menu, level_1, level_2);

            Enemies_reset_enemies(&enemies);

            Menu_SetAudioVolume(&menu);

            Levels_SetAudioVolume(level_1);

            Levels_SetAudioVolume(level_2);

            Player_set_audio_volume(&player);

        }

        if (menu.start_game && !level_2->completed)

        {

            BeginMode2D(player.camera);

            ClearBackground(SKYBLUE);

            if (!level_1->completed)

                Levels_Draw(level_1, &player);

            if (level_1->completed)

            {

                Levels_Draw(level_2, &player);

                Levels_DrawSaw(level_2);

            }

            Player_draw_ui(&player);

            if (!menu.pause_)

            {

                Player_check_input(&player);

                Player_manage_input(&player);

                if (!level_1->completed)

                {

                    Enemies_manage_birds(&enemies);

                    Enemies_manage_flames1(&enemies);

                    Levels_CheckCollisions(level_1, &player, &player.animations, &enemies);

                    if (player.death)

                    {

                        Levels_ManageDeath(level_1, &player, &enemies);

                        if (player.lives <= 0)

                        {

                            Menu_ResetLvl(&menu, level_1, level_2);

                            level_1->completed = false;

                            Player_set_pos1(&player);

                            Enemies_reset_enemies(&enemies);

                            Levels_ResetMusic(level_1);

                        }

                    }

                }

                if (level_1->completed)

                {

                    Enemies_manage_spiders(&enemies);

                    Levels_ManageSaw(level_2);

                    Enemies_manage_flames2(&enemies);

                    Levels_CheckCollisions(level_2, &player, &player.animations, &enemies);

                    if (player.death)

                    {

                        Levels_ManageDeath(level_2, &player, &enemies);

                        if (player.lives <= 0)

                        {

                            Menu_ResetLvl(&menu, level_1, level_2);

                            level_1->completed = false;

                            Player_set_pos1(&player);

                            Levels_ResetMusic(level_2);

                            Levels_ResetMusic(level_1);

                        }

                    }

                }

            }

            Menu_Pause(&menu);

            Menu_PauseDraw(&menu, &player, level_1, level_2);

            EndMode2D();

        }

        if (level_2->completed)

            Menu_Ending(&menu, level_1, level_2);

        EndDrawing();

    }

    Levels_Free(level_1);

    Levels_Free(level_2);

    UnloadImage(icon);

    CloseAudioDevice();

    CloseWindow();

    return 0;

}
