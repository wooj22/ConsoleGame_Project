#pragma once
#include "Windows.h"

extern COORD g_Player;
extern bool isJumping;
extern float playerVelocityY;
extern float gravity;
extern float jumpPower;

void PlayerMove(const wchar_t** map);
void PlayerJump(const wchar_t** map);