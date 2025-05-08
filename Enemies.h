#pragma once
#include "Animation.h"

typedef struct Enemies
{
    Animations animations;
    Rectangle
        spider1_coll,
        spider2_coll,
        spider3_coll,
        spider4_coll,
        spider5_coll,
        bird1_coll,
        bird2_coll,
        bird3_coll,
        flame1_coll,
        flame2_coll,
        flame3_coll,
        flame4_coll,
        flame5_coll;
    Vector2
        spider1_speed,
        spider2_speed,
        spider3_speed,
        spider4_speed,
        spider5_speed,
        bird_speed,
        bird2_speed,
        bird3_speed;
    int gravity;
    int flame_speed;
    int spider1_gravity;
    int spider2_gravity;
    bool bird_go_right;
    bool bird2_go_right;
    bool bird3_go_right;
    bool bird_go_up;
    bool bird2_go_up;
    bool bird3_go_up;
    bool spider1_go_right;
    bool spider2_go_right;
    bool spider3_go_right;
    bool spider4_go_right;
    bool spider5_go_right;
    bool spider1_go_up;
    bool spider2_go_up;
    bool spider3_go_up;
    bool spider4_go_up;
    bool spider5_go_up;
} Enemies;

void Enemies_init(Enemies* enemies);
void Enemies_manage_flames1(Enemies* enemies);
void Enemies_manage_flames2(Enemies* enemies);
void Enemies_manage_birds(Enemies* enemies);
void Enemies_manage_spiders(Enemies* enemies);
void Enemies_reset_enemies(Enemies* enemies);