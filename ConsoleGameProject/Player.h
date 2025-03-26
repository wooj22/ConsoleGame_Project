#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Floor1Scene.h" // 맵 데이터 사용
#include "Input.h"

class Player {
private:
    int hp;
    int damage;
    int speed;
    int posX;
    int posY;
    float velocityY;
    bool isGrounded;

public:
    Player(int x, int y);

    // 위치 관련
    int GetPosX() const;
    int GetPosY() const;

    // 체력 관련
    int GetHp() const;
    void Damaged(int damage);

    // 움직임
    void PlayerMove(int direction);
    void PlayerJump();
    void ApplyGravity();

    // 충돌 감지
    bool CanMove(int x, int y) const;
};

#endif
