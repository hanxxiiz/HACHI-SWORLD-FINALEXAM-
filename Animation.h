#pragma once
#include "raylib.h"

typedef struct Animations
{
    Texture2D
        w_key,
        s_key,
        a_key,
        d_key,
        space_key,
        q_key,
        bird,
        spider,
        flame,
        player_idle,
        player_run,
        player_jump;
    Rectangle
        key_regular_src,
        key_w_disp,
        key_s_disp,
        key_a_disp,
        key_d_disp,
        key_q_disp,
        key_space_src,
        key_space_disp,
        bird1_src_right,
        bird2_src_right,
        bird3_src_right,
        spider1_src_right,
        spider2_src_right,
        spider3_src_right,
        spider5_src_right,
        spider4_src_right,
        flame_src,
        bird1_src_left,
        bird2_src_left,
        bird3_src_left,
        spider1_src_left,
        spider2_src_left,
        spider3_src_left,
        spider4_src_left,
        spider5_src_left,
        player_src_left,
        player_src_right,
        flame_disp1_1,
        flame_disp1_2,
        flame_disp2_1,
        flame_disp2_2,
        flame_disp2_3,
        bird1_disp,
        bird2_disp,
        bird3_disp,
        spider1_disp,
        spider2_disp,
        spider3_disp,
        spider4_disp,
        spider5_disp,
        player_disp;
    Vector2
        flame_origin,
        origin;
    int flame_rotation;
    int timer1;
    int timer2;
    int timer3;
    int timer4;
    int timer5;
    int timer6;
    int timer7;
    int timer8;
    int timer9;
    int timer10;
    int timer11;
    int timer12;
    int timer13;
    int timer14;
    int timer15;
    int timer16;
    int timer17;
    int timer18;
    int timer19;
    int timer20;
    int timer21;
    int timer22;
    int timer23;
    int timer24;
} Animations;

void Animations_init(Animations* anim);
void Animations_keybindings(Animations* anim);
void Animations_idle_left(Animations* anim);
void Animations_idle_right(Animations* anim);
void Animations_run_left(Animations* anim);
void Animations_run_right(Animations* anim);
void Animations_jump_left(Animations* anim);
void Animations_jump_right(Animations* anim);
void Animations_flame_anim1(Animations* anim);
void Animations_flame_anim2(Animations* anim);
void Animations_spider1_anim_left(Animations* anim);
void Animations_bird1_anim_left(Animations* anim);
void Animations_spider1_anim_right(Animations* anim);
void Animations_bird1_anim_right(Animations* anim);
void Animations_spider2_anim_left(Animations* anim);
void Animations_bird2_anim_left(Animations* anim);
void Animations_spider2_anim_right(Animations* anim);
void Animations_bird2_anim_right(Animations* anim);
void Animations_spider3_anim_left(Animations* anim);
void Animations_bird3_anim_left(Animations* anim);
void Animations_spider3_anim_right(Animations* anim);
void Animations_bird3_anim_right(Animations* anim);
void Animations_spider4_anim_right(Animations* anim);
void Animations_spider5_anim_right(Animations* anim);
void Animations_spider4_anim_left(Animations* anim);
void Animations_spider5_anim_left(Animations* anim);