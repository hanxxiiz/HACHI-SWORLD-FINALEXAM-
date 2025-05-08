#include "Menu.h"
#include <stdio.h>

void Menu_SetAudioVolume(Menu * menu) {
    SetMusicVolume(menu->menu_music, menu->menu_volume);
    SetMusicVolume(menu->ending_music, menu->ending_volume);
    SetSoundVolume(menu->button_sound, menu->button_volume);
}

void Menu_InitAnimation(Menu * menu) {
    if (menu->state == 0) {
        menu->framesCounter++;
        if (menu->framesCounter == 120) {
            menu->state = 1;
            menu->framesCounter = 0;
        }
    }
    else if (menu->state == 1) {
        menu->topSideRecWidth += 4;
        menu->leftSideRecHeight += 4;
        if (menu->topSideRecWidth == 256)
            menu->state = 2;
    }
    else if (menu->state == 2) {
        menu->bottomSideRecWidth += 4;
        menu->rightSideRecHeight += 4;
        if (menu->bottomSideRecWidth == 256)
            menu->state = 3;
    }
    else if (menu->state == 3) {
        menu->framesCounter++;
        if (menu->framesCounter / 12) {
            menu->lettersCount++;
            menu->framesCounter = 0;
        }

        if (menu->lettersCount >= 10) {
            menu->alpha -= 0.02f;
            if (menu->alpha <= 0.0f) {
                menu->alpha = 0.0f;
                menu->state = 4;
            }
        }
    }
    else if (menu->state == 4)
        menu->init = false;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (menu->state == 0) {
        if ((menu->framesCounter / 15) % 2)
            DrawRectangle(menu->logoPositionX, menu->logoPositionY, 16, 16, BLACK);
    }
    else if (menu->state == 1) {
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, menu->topSideRecWidth, 16, BLACK);
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, 16, menu->leftSideRecHeight, BLACK);
    }
    else if (menu->state == 2) {
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, menu->topSideRecWidth, 16, BLACK);
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, 16, menu->leftSideRecHeight, BLACK);
        DrawRectangle(menu->logoPositionX + 240, menu->logoPositionY, 16, menu->rightSideRecHeight, BLACK);
        DrawRectangle(menu->logoPositionX, menu->logoPositionY + 240, menu->bottomSideRecWidth, 16, BLACK);
    }
    else if (menu->state == 3) {
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, menu->topSideRecWidth, 16, Fade(BLACK, menu->alpha));
        DrawRectangle(menu->logoPositionX, menu->logoPositionY + 16, 16, menu->leftSideRecHeight - 32, Fade(BLACK, menu->alpha));
        DrawRectangle(menu->logoPositionX + 240, menu->logoPositionY + 16, 16, menu->rightSideRecHeight - 32, Fade(BLACK, menu->alpha));
        DrawRectangle(menu->logoPositionX, menu->logoPositionY + 240, menu->bottomSideRecWidth, 16, Fade(BLACK, menu->alpha));
        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(RAYWHITE, menu->alpha));
        DrawText(TextSubtext("raylib", 0, menu->lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(BLACK, menu->alpha));
    }
    EndDrawing();
}

void Menu_Draw(Menu * menu) {
    UpdateMusicStream(menu->menu_music);
    menu->mouse_pos = GetMousePosition();

    ClearBackground(SKYBLUE);
    DrawTexturePro(menu->menu_background1, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->menu_background2, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->logo, menu->logo_src, menu->logo_disp, menu->origin, 0, RAYWHITE);
    DrawRectangleRounded(menu->start_button, 0.3, 0, RAYWHITE);
    DrawRectangleRounded(menu->keybindings_button, 0.3, 0, RAYWHITE);
    DrawRectangleRounded(menu->exit_button, 0.3, 0, RAYWHITE);
    DrawRectangleRoundedLines(menu->start_button, 0.3, 0, 6, BLACK);
    DrawRectangleRoundedLines(menu->keybindings_button, 0.3, 0, 6, BLACK);
    DrawRectangleRoundedLines(menu->exit_button, 0.3, 0, 6, BLACK);
    DrawTextEx(menu->font, "Start game", menu->start_game_pos, 50, 5, BLACK);
    DrawTextEx(menu->font, "keybindings", menu->keybindings_pos, 50, 5, BLACK);
    DrawTextEx(menu->font, "Exit game", menu->exit_pos, 50, 5, BLACK);
}

void Menu_DrawKeybindings(Menu * menu) {
    UpdateMusicStream(menu->menu_music);
    menu->mouse_pos = GetMousePosition();

    ClearBackground(SKYBLUE);
    DrawTexturePro(menu->menu_background1, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->menu_background2, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->logo, menu->logo_src, menu->logo_disp, menu->origin, 0, RAYWHITE);
    DrawRectangleRounded(menu->return_button, 0.3, 0, RAYWHITE);
    DrawRectangleRoundedLines(menu->return_button, 0.3, 0, 6, BLACK);
    DrawRectangleRounded(menu->keybindings_background, 0.3, 0, RAYWHITE);
    DrawRectangleRoundedLines(menu->keybindings_background, 0.3, 0, 6, BLACK);

    Animations_keybindings(&menu->animations);
    DrawTextEx(menu->font, "Return to menu", menu->return_pos, 50, 5, BLACK);
    DrawTextEx(menu->font, "movement", menu->movement_pos, 30, 3, BLACK);
    DrawTextEx(menu->font, "sprint", menu->sprint_pos, 30, 3, BLACK);
    DrawTextEx(menu->font, "jump", menu->jump_pos, 30, 3, BLACK);
}

void Menu_CheckButton(Menu * menu) {
    if (!menu->keybindings) {
        if (CheckCollisionPointRec(menu->mouse_pos, menu->start_button)) {
            if (menu->play_button_sound)
                PlaySound(menu->button_sound);
            menu->play_button_sound = false;
            DrawRectangleRounded(menu->start_button, 0.3, 0, GRAY);
            DrawTextEx(menu->font, "Start game", menu->start_game_pos, 50, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                menu->start_game = true;
        }
        else if (CheckCollisionPointRec(menu->mouse_pos, menu->keybindings_button)) {
            if (menu->play_button_sound)
                PlaySound(menu->button_sound);
            menu->play_button_sound = false;
            DrawRectangleRounded(menu->keybindings_button, 0.3, 0, GRAY);
            DrawTextEx(menu->font, "Keybindings", menu->keybindings_pos, 50, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                menu->keybindings = true;
        }
        else if (CheckCollisionPointRec(menu->mouse_pos, menu->exit_button)) {
            if (menu->play_button_sound)
                PlaySound(menu->button_sound);
            menu->play_button_sound = false;
            DrawRectangleRounded(menu->exit_button, 0.3, 0, GRAY);
            DrawTextEx(menu->font, "Exit game", menu->exit_pos, 50, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                menu->exit_game = true;
        }
        else
            menu->play_button_sound = true;
    }
    if (menu->keybindings) {
        if (CheckCollisionPointRec(menu->mouse_pos, menu->return_button)) {
            if (menu->play_button_sound)
                PlaySound(menu->button_sound);
            menu->play_button_sound = false;
            DrawRectangleRounded(menu->return_button, 0.3, 0, GRAY);
            DrawTextEx(menu->font, "Return to menu", menu->return_pos, 50, 5, BLACK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                menu->keybindings = false;
        }
        else
            menu->play_button_sound = true;
    }
}

void Menu_Pause(Menu * menu) {
    if (IsKeyPressed(KEY_ESCAPE))
        menu->pause_ = !menu->pause_;
}

void Menu_PauseDraw(Menu * menu, Player * player, Levels * level_1, Levels * level_2) {
    menu->mouse_pos = GetMousePosition();
    if (menu->pause_) {
        menu->pause_pos = GetScreenToWorld2D((Vector2) { 300, 400 }, player->camera);
        menu->pause_pos2 = GetScreenToWorld2D((Vector2) { 380, 700 }, player->camera);
        DrawTextEx(menu->font, "PAUSED", menu->pause_pos, 300, 15, BLACK);
        DrawTextEx(menu->font, "Press Q to leave to menu", menu->pause_pos2, 50, 15, BLACK);
        if (IsKeyPressed(KEY_Q)) {
            menu->start_game = false;
            menu->pause_ = false;
            StopMusicStream(level_1->level1_music);
            StopMusicStream(level_2->level2_music);
            StopMusicStream(menu->menu_music);
            StopMusicStream(menu->ending_music);
            PlayMusicStream(level_1->level1_music);
            PlayMusicStream(level_2->level2_music);
            PlayMusicStream(menu->menu_music);
            PlayMusicStream(menu->ending_music);
        }
    }
}

void Menu_Ending(Menu * menu, Levels * level_1, Levels * level_2) {
    UpdateMusicStream(menu->ending_music);
    ClearBackground(RAYWHITE);
    DrawTextureRec(menu->ending_background, menu->ending_, (Vector2) { 0, 0 }, menu->color);
    if (menu->color.a < 255)
        menu->color.a++;
    if (menu->color.a == 255) {
        DrawTextEx(menu->font, "Thank you for playing", menu->ending_pos1, 120, 10, BLACK);
        DrawTextEx(menu->font, "Press Escape to return to menu", menu->ending_pos2, 60, 10, BLACK);
        if (IsKeyPressed(KEY_ESCAPE)) {
            StopMusicStream(level_1->level1_music);
            StopMusicStream(level_2->level2_music);
            StopMusicStream(menu->menu_music);
            StopMusicStream(menu->ending_music);
            PlayMusicStream(level_1->level1_music);
            PlayMusicStream(level_2->level2_music);
            PlayMusicStream(menu->menu_music);
            PlayMusicStream(menu->ending_music);
            menu->start_game = false;
            level_1->completed = false;
            level_2->completed = false;
        }
    }
}

void Menu_ResetLvl(Menu * menu, Levels * level_1, Levels * level_2) {
    menu->color.a = 0;
    level_1->completed = false;
    level_1->start_level = false;
    level_2->start_level = false;

    // Reset level maps - leaving these empty as requested
    if (level_1->id == 1) {
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

    if (level_2->id == 2) {
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

    }
}

void Menu_Initialize(Menu * menu) {
    // Load resources
    menu->font = LoadFont("resources/fonts/alagard.png");
    menu->color = WHITE;
    menu->menu_music = LoadMusicStream("resources/audio/menu_music.mp3");
    menu->ending_music = LoadMusicStream("resources/audio/ending_music.mp3");
    menu->button_sound = LoadSound("resources/audio/button_sound.wav");
    menu->ending_background = LoadTexture("resources/textures/ending_background.png");
    menu->menu_background1 = LoadTexture("resources/textures/menu_background1.png");
    menu->menu_background2 = LoadTexture("resources/textures/menu_background2.png");
    menu->logo = LoadTexture("resources/textures/logo.png");

    // Initialize rendering rectangles
    menu->background_src = (Rectangle){ 0, 0, menu->menu_background1.width, menu->menu_background1.height };
    menu->background_disp = (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() };
    menu->logo_src = (Rectangle){ 0, 0, menu->logo.width, menu->logo.height };
    menu->logo_disp = (Rectangle){ GetScreenWidth() / 2 - menu->logo.width / 2, 50, menu->logo.width, menu->logo.height };
    menu->ending_ = (Rectangle){ 0, 0, menu->ending_background.width, menu->ending_background.height };

    // Initialize buttons
    menu->start_button = (Rectangle){ GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 50, 300, 75 };
    menu->keybindings_button = (Rectangle){ GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 50, 300, 75 };
    menu->exit_button = (Rectangle){ GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 150, 300, 75 };
    menu->return_button = (Rectangle){ GetScreenWidth() / 2 - 150, GetScreenHeight() - 100, 300, 75 };
    menu->keybindings_background = (Rectangle){ GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 200, 500, 350 };

    menu->start_game_pos = (Vector2){ GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 - 40 };
    menu->keybindings_pos = (Vector2){ GetScreenWidth() / 2 - 120, GetScreenHeight() / 2 + 60 };
    menu->exit_pos = (Vector2){ GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 160 };
    menu->return_pos = (Vector2){ GetScreenWidth() / 2 - 140, GetScreenHeight() - 90 };
    menu->ending_pos1 = (Vector2){ GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 150 };
    menu->ending_pos2 = (Vector2){ GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 + 50 };
    menu->movement_pos = (Vector2){ GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 150 };
    menu->sprint_pos = (Vector2){ GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 50 };
    menu->jump_pos = (Vector2){ GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 + 50 };

    menu->origin = (Vector2){ 0, 0 };
    menu->logoPositionX = GetScreenWidth() / 2 - 128;
    menu->logoPositionY = GetScreenHeight() / 2 - 128;
    menu->framesCounter = 0;
    menu->lettersCount = 0;
    menu->topSideRecWidth = 0;
    menu->leftSideRecHeight = 0;
    menu->bottomSideRecWidth = 0;
    menu->rightSideRecHeight = 0;
    menu->state = 0;
    menu->alpha = 1.0f;
    menu->keybindings = false;
    menu->start_game = false;
    menu->exit_game = false;
    menu->init = true;
    menu->pause_ = false;
    menu->play_button_sound = true;
    menu->menu_volume = 0.5f;
    menu->ending_volume = 0.5f;
    menu->button_volume = 0.5f;

    PlayMusicStream(menu->menu_music);
}