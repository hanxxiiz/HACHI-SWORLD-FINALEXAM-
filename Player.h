#pragma once
#include "Animation.h"

typedef struct Player
{
    Animations animations;
    Sound
        death_sound,
        hit_sound,
        jump_sound;
    Texture2D
        heart,
        lives_;
    Font
        font;
    Rectangle
        lives_src,
        heart_src,
        lives_disp,
        heart1_disp,
        heart2_disp,
        heart3_disp,
        coll,
        foot_coll;
    Color
        transparent;
    Vector2
        score_pos,
        lives_pos,
        heart1_pos,
        heart2_pos,
        heart3_pos,
        speed,
        origin;
    Camera2D
        camera;
    float gravity;
    bool move_right;
    bool move_left;
    bool sprint;
    bool jump;
    bool turned_right;
    bool turned_left;
    bool going_up;
    bool jump_break;
    bool move_camera;
    bool idle_right_anim;
    bool idle_left_anim;
    bool run_right_anim;
    bool run_left_anim;
    bool jump_right_anim;
    bool jump_left_anim;
    int hp;
    float lives;
    int score;
    bool one_up;
    int increment;
    bool death;
    int hit_timer;
    int hit_duration;
    float jump_volume;
    float death_volume;
    float hit_volume;
    bool play_jump_sound;
} Player;

void Player_init(Player* player);
void Player_set_audio_volume(Player* player);
void Player_draw_ui(Player* player);
void Player_check_input(Player* player);
void Player_manage_input(Player* player);
void Player_set_pos1(Player* player);
void Player_set_pos2(Player* player);
void Player_set_pos3(Player* player);