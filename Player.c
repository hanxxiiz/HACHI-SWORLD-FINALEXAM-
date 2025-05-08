#include "Player.h"

void Player_init(Player* player)
{
    /* Initialize animations */
    Animations_init(&player->animations);

    /* Load sounds */
    player->death_sound = LoadSound("resources/audio/sound/death.wav");
    player->hit_sound = LoadSound("resources/audio/sound/hit.wav");
    player->jump_sound = LoadSound("resources/audio/sound/jump.wav");

    /* Load textures */
    player->heart = LoadTexture("resources/graphics/UI/heart.png");
    player->lives_ = LoadTexture("resources/graphics/UI/lives_count.png");

    /* Load font */
    player->font = LoadFont("resources/graphics/fonts/font.ttf");

    /* Initialize rectangles */
    player->lives_src = (Rectangle){ 0, 0, 48, 48 };
    player->heart_src = (Rectangle){ 0, 0, 19, 18 };
    player->lives_disp = (Rectangle){ 0, 0, 144, 144 };
    player->heart1_disp = (Rectangle){ 0, 0, 48, 48 };
    player->heart2_disp = (Rectangle){ 0, 0, 48, 48 };
    player->heart3_disp = (Rectangle){ 0, 0, 48, 48 };
    player->coll = (Rectangle){ 0, 0, 66, 52 };
    player->foot_coll = (Rectangle){ 0, 0, 0, 0 };

    /* Initialize color */
    player->transparent = (Color){ 0, 0, 0, 0 };

    /* Initialize vectors */
    player->score_pos = (Vector2){ 0, 0 };
    player->lives_pos = (Vector2){ 0, 0 };
    player->heart1_pos = (Vector2){ 0, 0 };
    player->heart2_pos = (Vector2){ 0, 0 };
    player->heart3_pos = (Vector2){ 0, 0 };
    player->speed = (Vector2){ 8, 24.5 };
    player->origin = (Vector2){ 0, 0 };

    /* Initialize camera */
    player->camera = (Camera2D){
        (Vector2) {
         player->animations.player_disp.x, 650
        },
        (Vector2) {
            player->animations.player_disp.x, 580
        },
        0,
        1
    };

    /* Initialize other values */
    player->gravity = 0;
    player->move_right = false;
    player->move_left = false;
    player->sprint = false;
    player->jump = false;
    player->turned_right = true;
    player->turned_left = false;
    player->going_up = false;
    player->jump_break = false;
    player->move_camera = false;
    player->idle_right_anim = false;
    player->idle_left_anim = false;
    player->run_right_anim = false;
    player->run_left_anim = false;
    player->jump_right_anim = false;
    player->jump_left_anim = false;
    player->hp = 3;
    player->lives = 3;
    player->score = 0;
    player->one_up = false;
    player->increment = 1;
    player->death = false;
    player->hit_timer = 0;
    player->hit_duration = 200000;
    player->jump_volume = 0.06f;
    player->death_volume = 0.08f;
    player->hit_volume = 0.06f;
    player->play_jump_sound = false;
}

void Player_set_audio_volume(Player* player)
{
    SetSoundVolume(player->jump_sound, player->jump_volume);
    SetSoundVolume(player->hit_sound, player->hit_volume);
    SetSoundVolume(player->death_sound, player->death_volume);
}

void Player_draw_ui(Player* player)
{
    player->score_pos = GetScreenToWorld2D((Vector2) { 1500, 40 }, player->camera);
    player->lives_pos = GetScreenToWorld2D((Vector2) { 280, -12 }, player->camera);
    player->heart1_pos = GetScreenToWorld2D((Vector2) { 50, 40 }, player->camera);
    player->heart2_pos = GetScreenToWorld2D((Vector2) { 110, 40 }, player->camera);
    player->heart3_pos = GetScreenToWorld2D((Vector2) { 170, 40 }, player->camera);

    player->lives_disp.x = player->lives_pos.x;
    player->lives_disp.y = player->lives_pos.y;
    player->heart1_disp.x = player->heart1_pos.x;
    player->heart1_disp.y = player->heart1_pos.y;
    player->heart2_disp.x = player->heart2_pos.x;
    player->heart2_disp.y = player->heart2_pos.y;
    player->heart3_disp.x = player->heart3_pos.x;
    player->heart3_disp.y = player->heart3_pos.y;

    if (player->hp == 3)
    {
        DrawTexturePro(player->heart, player->heart_src, player->heart3_disp, player->origin, 0, RAYWHITE);
        DrawTexturePro(player->heart, player->heart_src, player->heart2_disp, player->origin, 0, RAYWHITE);
        DrawTexturePro(player->heart, player->heart_src, player->heart1_disp, player->origin, 0, RAYWHITE);
    }
    if (player->hp == 2)
    {
        DrawTexturePro(player->heart, player->heart_src, player->heart2_disp, player->origin, 0, RAYWHITE);
        DrawTexturePro(player->heart, player->heart_src, player->heart1_disp, player->origin, 0, RAYWHITE);
    }
    if (player->hp == 1)
        DrawTexturePro(player->heart, player->heart_src, player->heart1_disp, player->origin, 0, RAYWHITE);

    DrawTexturePro(player->lives_, player->lives_src, player->lives_disp, player->origin, 0, RAYWHITE);
    DrawTextEx(player->font, TextFormat("x%d", (int)player->lives), (Vector2) { player->lives_pos.x + 120, player->lives_pos.y + 62 }, 40, 5, WHITE);
    DrawTextEx(player->font, TextFormat("Score: %d", player->score), player->score_pos, 40, 5, WHITE);
}

void Player_check_input(Player* player)
{
    if (IsKeyDown(KEY_A))
        player->move_left = true;
    if (IsKeyDown(KEY_D))
        player->move_right = true;
    if (IsKeyDown(KEY_Q))
        player->sprint = true;
    if (IsKeyPressed(KEY_SPACE) && !player->jump_break)
    {
        player->jump = true;
        player->play_jump_sound = true;
    }
    if (IsKeyUp(KEY_A))
        player->move_left = false;
    if (IsKeyUp(KEY_D))
        player->move_right = false;
    if (IsKeyUp(KEY_Q))
        player->sprint = false;
}

void Player_manage_input(Player* player)
{
    if (player->animations.player_disp.x > 548 && player->animations.player_disp.x < 6952)
    {
        player->move_camera = true;
        player->camera.target = (Vector2){ player->animations.player_disp.x - 500, 580 };
    }
    else
        player->move_camera = false;

    if ((!player->move_left && !player->move_right && !player->jump) || (player->move_left && player->move_right))
    {
        if (player->turned_right)
        {
            if (player->hit_timer < 0)
                Animations_idle_right(&player->animations);
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
                Animations_idle_right(&player->animations);
        }
        else if (player->turned_left)
        {
            if (player->hit_timer < 0)
                Animations_idle_left(&player->animations);
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
                Animations_idle_left(&player->animations);
        }
    }
    else if (player->move_left)
    {
        if (!player->jump)
        {
            if (player->hit_timer < 0)
                Animations_run_left(&player->animations);
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
                Animations_run_left(&player->animations);
        }
        if (player->coll.x > 0)
            player->animations.player_disp.x -= player->speed.x;
        player->turned_left = true;
        player->turned_right = false;
    }
    else if (player->move_right)
    {
        if (!player->jump)
        {
            if (player->hit_timer < 0)
                Animations_run_right(&player->animations);
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
                Animations_run_right(&player->animations);
        }
        if (player->coll.x < 8250)
            player->animations.player_disp.x += player->speed.x;
        player->turned_right = true;
        player->turned_left = false;
    }

    if (player->sprint && player->speed.x < 12)
        player->speed.x += 0.25f;
    if (!player->sprint && player->speed.x > 7)
        player->speed.x -= 0.25f;

    if (player->jump && player->turned_left)
    {
        if (player->play_jump_sound)
            PlaySound(player->jump_sound);
        if (player->hit_timer < 0)
            Animations_jump_left(&player->animations);
        else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
            Animations_jump_left(&player->animations);
        player->animations.player_disp.y -= (player->speed.y - player->gravity);
        if (player->gravity < 50)
            player->gravity++;
        if (player->gravity >= player->speed.y)
            player->going_up = false;
        else
            player->going_up = true;
        player->play_jump_sound = false;
    }

    if (player->jump && player->turned_right)
    {
        if (player->play_jump_sound)
            PlaySound(player->jump_sound);
        if (player->hit_timer < 0)
            Animations_jump_right(&player->animations);
        else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
            Animations_jump_right(&player->animations);
        player->animations.player_disp.y -= (player->speed.y - player->gravity);
        if (player->gravity < 49)
            player->gravity++;
        if (player->gravity >= player->speed.y)
            player->going_up = false;
        else
            player->going_up = true;
        player->play_jump_sound = false;
    }

    if (!player->going_up)
        player->jump_break = true;
}

void Player_set_pos1(Player* player)
{
    player->hit_timer = 0;
    player->hp = 3;
    player->score = 0;
    player->lives = 3;
    player->gravity = 0;
    player->jump = false;
    player->animations.player_disp = (Rectangle){ 50, 704, 192, 192 };
    player->camera.target = (Vector2){ player->animations.player_disp.x, 580 };
}

void Player_set_pos2(Player* player)
{
    player->hit_timer = 0;
    player->gravity = 0;
    player->jump = false;
    player->animations.player_disp = (Rectangle){ 50, 704, 192, 192 };
    player->camera.target = (Vector2){ player->animations.player_disp.x, 580 };
}

void Player_set_pos3(Player* player)
{
    player->hit_timer = 0;
    player->gravity = 0;
    player->hp = 3;
    player->jump = false;
    player->animations.player_disp = (Rectangle){ 50, 704, 192, 192 };
    player->camera.target = (Vector2){ player->animations.player_disp.x, 580 };
}