#include "Enemies.h"

void Enemies_init(Enemies* enemies)
{
    /* Initialize animations */
    Animations_init(&enemies->animations);

    /* Initialize rectangles */
    enemies->spider1_coll = (Rectangle){ 0, 0, 100, 40 };
    enemies->spider2_coll = (Rectangle){ 0, 0, 100, 40 };
    enemies->spider3_coll = (Rectangle){ 0, 0, 100, 40 };
    enemies->spider4_coll = (Rectangle){ 0, 0, 100, 40 };
    enemies->spider5_coll = (Rectangle){ 0, 0, 100, 40 };
    enemies->bird1_coll = (Rectangle){ 0, 0, 60, 44 };
    enemies->bird2_coll = (Rectangle){ 0, 0, 60, 44 };
    enemies->bird3_coll = (Rectangle){ 0, 0, 60, 44 };
    enemies->flame1_coll = (Rectangle){ 0, 0, 56, 60 };
    enemies->flame2_coll = (Rectangle){ 0, 0, 56, 60 };
    enemies->flame3_coll = (Rectangle){ 0, 0, 56, 60 };
    enemies->flame4_coll = (Rectangle){ 0, 0, 56, 60 };
    enemies->flame5_coll = (Rectangle){ 0, 0, 56, 60 };

    /* Initialize vectors */
    enemies->spider1_speed = (Vector2){ 8, 22 };
    enemies->spider2_speed = (Vector2){ 8, 22 };
    enemies->spider3_speed = (Vector2){ 8, 22 };
    enemies->spider4_speed = (Vector2){ 8, 22 };
    enemies->spider5_speed = (Vector2){ 8, 22 };
    enemies->bird_speed = (Vector2){ 10, 4 };
    enemies->bird2_speed = (Vector2){ 10, 4 };
    enemies->bird3_speed = (Vector2){ 10, 4 };

    /* Initialize other values */
    enemies->gravity = 0;
    enemies->flame_speed = 40;
    enemies->spider1_gravity = 0;
    enemies->spider2_gravity = 0;
    enemies->bird_go_right = false;
    enemies->bird2_go_right = false;
    enemies->bird3_go_right = false;
    enemies->bird_go_up = true;
    enemies->bird2_go_up = true;
    enemies->bird3_go_up = true;
    enemies->spider1_go_right = false;
    enemies->spider2_go_right = false;
    enemies->spider3_go_right = false;
    enemies->spider4_go_right = false;
    enemies->spider5_go_right = false;
    enemies->spider1_go_up = true;
    enemies->spider2_go_up = true;
    enemies->spider3_go_up = true;
    enemies->spider4_go_up = true;
    enemies->spider5_go_up = true;
}

void Enemies_manage_flames1(Enemies* enemies)
{
    Animations_flame_anim1(&enemies->animations);
    enemies->animations.flame_disp1_1.y -= (enemies->flame_speed - enemies->gravity);
    enemies->animations.flame_disp1_2.y -= (enemies->flame_speed - enemies->gravity);
    enemies->gravity++;
    if (enemies->animations.flame_disp1_1.y == 1100)
    {
        enemies->animations.flame_rotation = 0;
        enemies->gravity = 0;
    }
    if (enemies->gravity >= 30 && enemies->gravity < 50)
        enemies->animations.flame_rotation += 9;
}

void Enemies_manage_flames2(Enemies* enemies)
{
    Animations_flame_anim2(&enemies->animations);
    enemies->animations.flame_disp2_1.y -= (enemies->flame_speed - enemies->gravity);
    enemies->animations.flame_disp2_2.y -= (enemies->flame_speed - enemies->gravity);
    enemies->animations.flame_disp2_3.y -= (enemies->flame_speed - enemies->gravity);
    enemies->gravity++;
    if (enemies->animations.flame_disp2_3.y == 1100)
    {
        enemies->animations.flame_rotation = 0;
        enemies->gravity = 0;
    }
    if (enemies->gravity >= 30 && enemies->gravity < 50)
        enemies->animations.flame_rotation += 9;
}

void Enemies_manage_birds(Enemies* enemies)
{
    enemies->animations.bird1_disp.x -= enemies->bird_speed.x;
    enemies->animations.bird1_disp.y += enemies->bird_speed.y;
    enemies->animations.bird2_disp.x -= enemies->bird2_speed.x;
    enemies->animations.bird2_disp.y += enemies->bird2_speed.y;
    enemies->animations.bird3_disp.x -= enemies->bird3_speed.x;
    enemies->animations.bird3_disp.y += enemies->bird3_speed.y;

    // Bird 1
    if (enemies->animations.bird1_disp.x == 2200)
    {
        enemies->bird_go_right = false;
        enemies->bird_speed.x = -enemies->bird_speed.x;
    }
    if (enemies->animations.bird1_disp.x == 1550)
    {
        enemies->bird_go_right = true;
        enemies->bird_speed.x = -enemies->bird_speed.x;
    }
    if (enemies->animations.bird1_disp.y == 70)
    {
        enemies->bird_go_up = true;
        enemies->bird_speed.y = -enemies->bird_speed.y;
    }
    if (enemies->animations.bird1_disp.y == 30)
    {
        enemies->bird_go_up = false;
        enemies->bird_speed.y = -enemies->bird_speed.y;
    }
    if (enemies->bird_go_right)
        Animations_bird1_anim_right(&enemies->animations);
    else
        Animations_bird1_anim_left(&enemies->animations);

    // Bird 2
    if (enemies->animations.bird2_disp.x == 4600)
    {
        enemies->bird2_go_right = false;
        enemies->bird2_speed.x = -enemies->bird2_speed.x;
    }
    if (enemies->animations.bird2_disp.x == 3700)
    {
        enemies->bird2_go_right = true;
        enemies->bird2_speed.x = -enemies->bird2_speed.x;
    }
    if (enemies->animations.bird2_disp.y == 365)
    {
        enemies->bird2_go_up = true;
        enemies->bird2_speed.y = -enemies->bird2_speed.y;
    }
    if (enemies->animations.bird2_disp.y == 325)
    {
        enemies->bird2_go_up = false;
        enemies->bird2_speed.y = -enemies->bird2_speed.y;
    }
    if (enemies->bird2_go_right)
        Animations_bird2_anim_right(&enemies->animations);
    else
        Animations_bird2_anim_left(&enemies->animations);

    // Bird 3
    if (enemies->animations.bird3_disp.x == 4300)
    {
        enemies->bird3_go_right = false;
        enemies->bird3_speed.x = -enemies->bird3_speed.x;
    }
    if (enemies->animations.bird3_disp.x == 3800)
    {
        enemies->bird3_go_right = true;
        enemies->bird3_speed.x = -enemies->bird3_speed.x;
    }
    if (enemies->animations.bird3_disp.y == 620)
    {
        enemies->bird3_go_up = true;
        enemies->bird3_speed.y = -enemies->bird3_speed.y;
    }
    if (enemies->animations.bird3_disp.y == 580)
    {
        enemies->bird3_go_up = false;
        enemies->bird3_speed.y = -enemies->bird3_speed.y;
    }
    if (enemies->bird3_go_right)
        Animations_bird3_anim_right(&enemies->animations);
    else
        Animations_bird3_anim_left(&enemies->animations);
}

void Enemies_manage_spiders(Enemies* enemies)
{
    enemies->animations.spider1_disp.x += enemies->spider1_speed.x;
    enemies->animations.spider2_disp.x += enemies->spider2_speed.x;
    enemies->animations.spider3_disp.x += enemies->spider3_speed.x;
    enemies->animations.spider4_disp.x += enemies->spider4_speed.x;
    enemies->animations.spider5_disp.x += enemies->spider5_speed.x;

    enemies->animations.spider2_disp.y -= (enemies->spider2_speed.y - enemies->spider2_gravity);
    enemies->spider2_gravity++;
    if (enemies->spider2_gravity == 2 * enemies->spider2_speed.y + 1)
        enemies->spider2_gravity = 0;

    // Spider 1
    if (enemies->animations.spider1_disp.x == 2460)
    {
        enemies->spider1_go_right = true;
        enemies->spider1_speed.x = -enemies->spider1_speed.x;
    }
    if (enemies->animations.spider1_disp.x == 2700)
    {
        enemies->spider1_go_right = false;
        enemies->spider1_speed.x = -enemies->spider1_speed.x;
    }
    if (enemies->spider1_go_right)
        Animations_spider1_anim_right(&enemies->animations);
    else
        Animations_spider1_anim_left(&enemies->animations);

    // Spider 2
    if (enemies->animations.spider2_disp.x == 4800)
    {
        enemies->spider2_go_right = true;
        enemies->spider2_speed.x = -enemies->spider2_speed.x;
    }
    if (enemies->animations.spider2_disp.x == 5600)
    {
        enemies->spider2_go_right = false;
        enemies->spider2_speed.x = -enemies->spider2_speed.x;
    }
    if (enemies->spider2_go_right)
        Animations_spider2_anim_right(&enemies->animations);
    else
        Animations_spider2_anim_left(&enemies->animations);

    // Spider 3
    if (enemies->animations.spider3_disp.x == 6250)
    {
        enemies->spider3_go_right = true;
        enemies->spider3_speed.x = -enemies->spider3_speed.x;
    }
    if (enemies->animations.spider3_disp.x == 6890)
    {
        enemies->spider3_go_right = false;
        enemies->spider3_speed.x = -enemies->spider3_speed.x;
    }
    if (enemies->spider3_go_right)
        Animations_spider3_anim_right(&enemies->animations);
    else
        Animations_spider3_anim_left(&enemies->animations);

    // Spider 4
    if (enemies->animations.spider4_disp.x == 2820)
    {
        enemies->spider4_go_right = true;
        enemies->spider4_speed.x = -enemies->spider4_speed.x;
    }
    if (enemies->animations.spider4_disp.x == 3060)
    {
        enemies->spider4_go_right = false;
        enemies->spider4_speed.x = -enemies->spider4_speed.x;
    }
    if (enemies->spider4_go_right)
        Animations_spider4_anim_right(&enemies->animations);
    else
        Animations_spider4_anim_left(&enemies->animations);

    // Spider 5
    if (enemies->animations.spider5_disp.x == 3180)
    {
        enemies->spider5_go_right = true;
        enemies->spider5_speed.x = -enemies->spider5_speed.x;
    }
    if (enemies->animations.spider5_disp.x == 3420)
    {
        enemies->spider5_go_right = false;
        enemies->spider5_speed.x = -enemies->spider5_speed.x;
    }
    if (enemies->spider5_go_right)
        Animations_spider5_anim_right(&enemies->animations);
    else
        Animations_spider5_anim_left(&enemies->animations);
}

void Enemies_reset_enemies(Enemies* enemies)
{
    enemies->animations.flame_disp1_1.y = 1100;
    enemies->animations.flame_disp1_2.y = 1100;
    enemies->animations.flame_disp2_1.y = 1100;
    enemies->animations.flame_disp2_2.y = 1100;
    enemies->animations.flame_disp2_3.y = 1100;
    enemies->animations.bird1_disp.x = 2200;
    enemies->animations.bird1_disp.y = 50;
    enemies->animations.bird2_disp.x = 4600;
    enemies->animations.bird2_disp.y = 345;
    enemies->animations.bird3_disp.x = 4300;
    enemies->animations.bird3_disp.y = 600;
    enemies->gravity = 0;
    enemies->animations.flame_rotation = 0;
    enemies->bird3_go_up = true;
    enemies->bird2_go_up = true;
    enemies->bird_go_up = true;
    enemies->bird3_go_right = false;
    enemies->bird2_go_right = false;
    enemies->bird_go_right = false;
    enemies->bird_speed = (Vector2){ 10, 4 };
    enemies->bird2_speed = (Vector2){ 10, 4 };
    enemies->bird3_speed = (Vector2){ 10, 4 };
}
