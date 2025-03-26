#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Floor1Scene.h" // �� ������ ���
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

    // ��ġ ����
    int GetPosX() const;
    int GetPosY() const;

    // ü�� ����
    int GetHp() const;
    void Damaged(int damage);

    // ������
    void PlayerMove(int direction);
    void PlayerJump();
    void ApplyGravity();

    // �浹 ����
    bool CanMove(int x, int y) const;
};

#endif
