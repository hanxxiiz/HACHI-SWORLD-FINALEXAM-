#include "Animation.h"

void Animations_init(Animations* anim)
{
    /* Load textures */
    anim->w_key = LoadTexture("resources/graphics/menu/w.png");
    anim->s_key = LoadTexture("resources/graphics/menu/s.png");
    anim->a_key = LoadTexture("resources/graphics/menu/a.png");
    anim->d_key = LoadTexture("resources/graphics/menu/d.png");
    anim->space_key = LoadTexture("resources/graphics/menu/space.png");
    anim->q_key = LoadTexture("resources/graphics/menu/q.png");
    anim->bird = LoadTexture("resources/graphics/characters/bird.png");
    anim->spider = LoadTexture("resources/graphics/characters/spider.png");
    anim->flame = LoadTexture("resources/graphics/characters/flame.png");
    anim->player_idle = LoadTexture("resources/graphics/characters/player_idle.png");
    anim->player_run = LoadTexture("resources/graphics/characters/player_move.png");
    anim->player_jump = LoadTexture("resources/graphics/characters/player_jump.png");

    /* Initialize rectangles */
    anim->key_regular_src = (Rectangle){ 0, 0, 32, 32 };
    anim->key_w_disp = (Rectangle){ 680, 510, 64, 64 };
    anim->key_s_disp = (Rectangle){ 680, 570, 64, 64 };
    anim->key_a_disp = (Rectangle){ 600, 570, 64, 64 };
    anim->key_d_disp = (Rectangle){ 760, 570, 64, 64 };
    anim->key_q_disp = (Rectangle){ 980, 530, 64, 64 };
    anim->key_space_src = (Rectangle){ 0, 0, 64, 32 };
    anim->key_space_disp = (Rectangle){ 1180, 530, 128, 64 };
    anim->bird1_src_right = (Rectangle){ 0, 0, 48, 48 };
    anim->bird2_src_right = (Rectangle){ 0, 0, 48, 48 };
    anim->bird3_src_right = (Rectangle){ 0, 0, 48, 48 };
    anim->spider1_src_right = (Rectangle){ 0, 0, 64, 48 };
    anim->spider2_src_right = (Rectangle){ 0, 0, 64, 48 };
    anim->spider3_src_right = (Rectangle){ 0, 0, 64, 48 };
    anim->spider5_src_right = (Rectangle){ 0, 0, 64, 48 };
    anim->spider4_src_right = (Rectangle){ 0, 0, 64, 48 };
    anim->flame_src = (Rectangle){ 0, 0, 48, 48 };
    anim->bird1_src_left = (Rectangle){ 0, 0, -48, 48 };
    anim->bird2_src_left = (Rectangle){ 0, 0, -48, 48 };
    anim->bird3_src_left = (Rectangle){ 0, 0, -48, 48 };
    anim->spider1_src_left = (Rectangle){ 0, 0, -64, 48 };
    anim->spider2_src_left = (Rectangle){ 0, 0, -64, 48 };
    anim->spider3_src_left = (Rectangle){ 0, 0, -64, 48 };
    anim->spider4_src_left = (Rectangle){ 0, 0, -64, 48 };
    anim->spider5_src_left = (Rectangle){ 0, 0, -64, 48 };
    anim->player_src_left = (Rectangle){ 0, 0, -48, 48 };
    anim->player_src_right = (Rectangle){ 0, 0, 48, 48 };
    anim->flame_disp1_1 = (Rectangle){ 5810, 1100, 192, 192 };
    anim->flame_disp1_2 = (Rectangle){ 6060, 1100, 192, 192 };
    anim->flame_disp2_1 = (Rectangle){ 1000, 1100, 192, 192 };
    anim->flame_disp2_2 = (Rectangle){ 1650, 1100, 192, 192 };
    anim->flame_disp2_3 = (Rectangle){ 4200, 1100, 192, 192 };
    anim->bird1_disp = (Rectangle){ 2200, 50, 192, 192 };
    anim->bird2_disp = (Rectangle){ 4600, 345, 192, 192 };
    anim->bird3_disp = (Rectangle){ 4300, 600, 192, 192 };
    anim->spider1_disp = (Rectangle){ 2460, 450, 256, 192 };
    anim->spider2_disp = (Rectangle){ 4800, 704, 256, 192 };
    anim->spider3_disp = (Rectangle){ 6250, 704, 256, 192 };
    anim->spider4_disp = (Rectangle){ 2980, 190, 256, 192 };
    anim->spider5_disp = (Rectangle){ 3260, 450, 256, 192 };
    anim->player_disp = (Rectangle){ 50, 704, 192, 192 };

    /* Initialize vectors */
    anim->flame_origin = (Vector2){ 96, 96 };
    anim->origin = (Vector2){ 0, 0 };

    /* Initialize other values */
    anim->flame_rotation = 0;

    /* Initialize timers */
    anim->timer1 = 0;
    anim->timer2 = 0;
    anim->timer3 = 0;
    anim->timer4 = 0;
    anim->timer5 = 0;
    anim->timer6 = 0;
    anim->timer7 = 0;
    anim->timer8 = 0;
    anim->timer9 = 0;
    anim->timer10 = 0;
    anim->timer11 = 0;
    anim->timer12 = 0;
    anim->timer13 = 0;
    anim->timer14 = 0;
    anim->timer15 = 0;
    anim->timer16 = 0;
    anim->timer17 = 0;
    anim->timer18 = 0;
    anim->timer19 = 0;
    anim->timer20 = 0;
    anim->timer21 = 0;
    anim->timer22 = 0;
    anim->timer23 = 0;
    anim->timer24 = 0;
}

void Animations_keybindings(Animations* anim)
{
    if (anim->timer5 % 50 == 0)
    {
        anim->key_regular_src.x += 32;
        anim->key_space_src.x += 64;
    }
    DrawTexturePro(anim->w_key, anim->key_regular_src, anim->key_w_disp, anim->origin, 0, RAYWHITE);
    DrawTexturePro(anim->s_key, anim->key_regular_src, anim->key_s_disp, anim->origin, 0, RAYWHITE);
    DrawTexturePro(anim->a_key, anim->key_regular_src, anim->key_a_disp, anim->origin, 0, RAYWHITE);
    DrawTexturePro(anim->d_key, anim->key_regular_src, anim->key_d_disp, anim->origin, 0, RAYWHITE);
    DrawTexturePro(anim->space_key, anim->key_space_src, anim->key_space_disp, anim->origin, 0, RAYWHITE);
    DrawTexturePro(anim->q_key, anim->key_regular_src, anim->key_q_disp, anim->origin, 0, RAYWHITE);
    anim->timer5++;
    if (anim->timer5 == 50)
        anim->timer5 = 0;
}

void Animations_idle_left(Animations* anim)
{
    if (anim->timer1 % 6 == 0)
        anim->player_src_left.x += 48;
    DrawTexturePro(anim->player_idle, anim->player_src_left, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer1++;
    if (anim->timer1 == 30)
        anim->timer1 = 0;
}

void Animations_idle_right(Animations* anim)
{
    if (anim->timer2 % 6 == 0)
        anim->player_src_right.x += 48;
    DrawTexturePro(anim->player_idle, anim->player_src_right, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer2++;
    if (anim->timer2 == 30)
        anim->timer2 = 0;
}

void Animations_run_left(Animations* anim)
{
    if (anim->timer3 % 6 == 0)
        anim->player_src_left.x += 48;
    DrawTexturePro(anim->player_run, anim->player_src_left, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer3++;
    if (anim->timer3 == 30)
        anim->timer3 = 0;
}

void Animations_run_right(Animations* anim)
{
    if (anim->timer4 % 6 == 0)
        anim->player_src_right.x += 48;
    DrawTexturePro(anim->player_run, anim->player_src_right, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer4++;
    if (anim->timer4 == 30)
        anim->timer4 = 0;
}

void Animations_jump_left(Animations* anim)
{
    DrawTexturePro(anim->player_jump, anim->player_src_left, anim->player_disp, anim->origin, 0, RAYWHITE);
}

void Animations_jump_right(Animations* anim)
{
    DrawTexturePro(anim->player_jump, anim->player_src_right, anim->player_disp, anim->origin, 0, RAYWHITE);
}

void Animations_flame_anim1(Animations* anim)
{
    if (anim->timer24 % 10 == 0)
        anim->flame_src.x += 48;
    DrawTexturePro(anim->flame, anim->flame_src, anim->flame_disp1_1, anim->flame_origin, anim->flame_rotation, RAYWHITE);
    DrawTexturePro(anim->flame, anim->flame_src, anim->flame_disp1_2, anim->flame_origin, anim->flame_rotation, RAYWHITE);
    anim->timer24++;
    if (anim->timer24 == 30)
        anim->timer24 = 0;
}

void Animations_flame_anim2(Animations* anim)
{
    if (anim->timer23 % 10 == 0)
        anim->flame_src.x += 48;
    DrawTexturePro(anim->flame, anim->flame_src, anim->flame_disp2_1, anim->flame_origin, anim->flame_rotation, RAYWHITE);
    DrawTexturePro(anim->flame, anim->flame_src, anim->flame_disp2_2, anim->flame_origin, anim->flame_rotation, RAYWHITE);
    DrawTexturePro(anim->flame, anim->flame_src, anim->flame_disp2_3, anim->flame_origin, anim->flame_rotation, RAYWHITE);
    anim->timer23++;
    if (anim->timer23 == 30)
        anim->timer23 = 0;
}

void Animations_spider1_anim_left(Animations* anim)
{
    if (anim->timer7 % 10 == 0)
        anim->spider1_src_left.x += 64;
    DrawTexturePro(anim->spider, anim->spider1_src_left, anim->spider1_disp, anim->origin, 0, RAYWHITE);
    anim->timer7++;
    if (anim->timer7 == 40)
        anim->timer7 = 0;
}

void Animations_bird1_anim_left(Animations* anim)
{
    if (anim->timer8 % 10 == 0)
        anim->bird1_src_left.x += 48;
    DrawTexturePro(anim->bird, anim->bird1_src_left, anim->bird1_disp, anim->origin, 0, RAYWHITE);
    anim->timer8++;
    if (anim->timer8 == 40)
        anim->timer8 = 0;
}

void Animations_spider1_anim_right(Animations* anim)
{
    if (anim->timer9 % 10 == 0)
        anim->spider1_src_right.x += 64;
    DrawTexturePro(anim->spider, anim->spider1_src_right, anim->spider1_disp, anim->origin, 0, RAYWHITE);
    anim->timer9++;
    if (anim->timer9 == 40)
        anim->timer9 = 0;
}

void Animations_bird1_anim_right(Animations* anim)
{
    if (anim->timer10 % 10 == 0)
        anim->bird1_src_right.x += 48;
    DrawTexturePro(anim->bird, anim->bird1_src_right, anim->bird1_disp, anim->origin, 0, RAYWHITE);
    anim->timer10++;
    if (anim->timer10 == 40)
        anim->timer10 = 0;
}

void Animations_spider2_anim_left(Animations* anim)
{
    if (anim->timer11 % 10 == 0)
        anim->spider2_src_left.x += 64;
    DrawTexturePro(anim->spider, anim->spider2_src_left, anim->spider2_disp, anim->origin, 0, RAYWHITE);
    anim->timer11++;
    if (anim->timer11 == 40)
        anim->timer11 = 0;
}

void Animations_bird2_anim_left(Animations* anim)
{
    if (anim->timer12 % 10 == 0)
        anim->bird2_src_left.x += 48;
    DrawTexturePro(anim->bird, anim->bird2_src_left, anim->bird2_disp, anim->origin, 0, RAYWHITE);
    anim->timer12++;
    if (anim->timer12 == 40)
        anim->timer12 = 0;
}

void Animations_spider2_anim_right(Animations* anim)
{
    if (anim->timer13 % 10 == 0)
        anim->spider2_src_right.x += 64;
    DrawTexturePro(anim->spider, anim->spider2_src_right, anim->spider2_disp, anim->origin, 0, RAYWHITE);
    anim->timer13++;
    if (anim->timer13 == 40)
        anim->timer13 = 0;
}

void Animations_bird2_anim_right(Animations* anim)
{
    if (anim->timer14 % 10 == 0)
        anim->bird2_src_right.x += 48;
    DrawTexturePro(anim->bird, anim->bird2_src_right, anim->bird2_disp, anim->origin, 0, RAYWHITE);
    anim->timer14++;
    if (anim->timer14 == 40)
        anim->timer14 = 0;
}

void Animations_spider3_anim_left(Animations* anim)
{
    if (anim->timer15 % 10 == 0)
        anim->spider3_src_left.x += 64;
    DrawTexturePro(anim->spider, anim->spider3_src_left, anim->spider3_disp, anim->origin, 0, RAYWHITE);
    anim->timer15++;
    if (anim->timer15 == 40)
        anim->timer15 = 0;
}

void Animations_bird3_anim_left(Animations* anim)
{
    if (anim->timer16 % 10 == 0)
        anim->bird3_src_left.x += 48;
    DrawTexturePro(anim->bird, anim->bird3_src_left, anim->bird3_disp, anim->origin, 0, RAYWHITE);
    anim->timer16++;
    if (anim->timer16 == 40)
        anim->timer16 = 0;
}

void Animations_spider3_anim_right(Animations* anim)
{
    if (anim->timer17 % 10 == 0)
        anim->spider3_src_right.x += 64;
    DrawTexturePro(anim->spider, anim->spider3_src_right, anim->spider3_disp, anim->origin, 0, RAYWHITE);
    anim->timer17++;
    if (anim->timer17 == 40)
        anim->timer17 = 0;
}

void Animations_bird3_anim_right(Animations* anim)
{
    if (anim->timer18 % 10 == 0)
        anim->bird3_src_right.x += 48;
    DrawTexturePro(anim->bird, anim->bird3_src_right, anim->bird3_disp, anim->origin, 0, RAYWHITE);
    anim->timer18++;
    if (anim->timer18 == 40)
        anim->timer18 = 0;
}

void Animations_spider4_anim_right(Animations* anim)
{
    if (anim->timer19 % 10 == 0)
        anim->spider4_src_right.x += 64;
    DrawTexturePro(anim->spider, anim->spider4_src_right, anim->spider4_disp, anim->origin, 0, RAYWHITE);
    anim->timer19++;
    if (anim->timer19 == 40)
        anim->timer19 = 0;
}

void Animations_spider5_anim_right(Animations* anim)
{
    if (anim->timer20 % 10 == 0)
        anim->spider5_src_right.x += 64;
    DrawTexturePro(anim->spider, anim->spider5_src_right, anim->spider5_disp, anim->origin, 0, RAYWHITE);
    anim->timer20++;
    if (anim->timer20 == 40)
        anim->timer20 = 0;
}

void Animations_spider4_anim_left(Animations* anim)
{
    if (anim->timer21 % 10 == 0)
        anim->spider4_src_right.x += 64;  /* Note: This uses spider4_src_right but draws spider4_src_left */
    DrawTexturePro(anim->spider, anim->spider4_src_left, anim->spider4_disp, anim->origin, 0, RAYWHITE);
    anim->timer21++;
    if (anim->timer21 == 40)
        anim->timer21 = 0;
}

void Animations_spider5_anim_left(Animations* anim)
{
    if (anim->timer22 % 10 == 0)
        anim->spider5_src_right.x += 64;  /* Note: This uses spider5_src_right but draws spider5_src_left */
    DrawTexturePro(anim->spider, anim->spider5_src_left, anim->spider5_disp, anim->origin, 0, RAYWHITE);
    anim->timer22++;
    if (anim->timer22 == 40)
        anim->timer22 = 0;
}