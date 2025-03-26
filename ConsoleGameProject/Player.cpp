#include "Player.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"

COORD g_Player = { 3, 57 };
bool isJumping = false;
float playerVelocityY = 0.0f;
float gravity = 300.0f; // 중력
float jumpPower = -6.0f; // 점프 속도

// Move
void PlayerMove(const wchar_t** map)
{
	// 임시 좌표
	int nextX = g_Player.X;
	int nextY = g_Player.Y;

	// 입력 처리
	if (Input::IsKeyDown(VK_LEFT) && map[g_Player.Y][g_Player.X - 1] != L'▓') {
		nextX--;
	}
	if (Input::IsKeyDown(VK_RIGHT) && map[g_Player.Y][g_Player.X + 1] != L'▓') {
		nextX++;
	}

	// 경계 검사 (콘솔 창 크기 기준)
	if (nextY < 0) nextY = 0;

	// 최종 위치 업데이트
	g_Player.X = nextX;
}

// Jump
void PlayerJump(const wchar_t** map) {
	float deltaTime = Time::GetElapsedTime();

	// 점프
	if (Input::IsKeyPressed(VK_UP) && !isJumping)
	{
		isJumping = true;
		playerVelocityY = jumpPower;
	}

	// 중력 적용
	if (isJumping)
	{
		playerVelocityY += gravity * deltaTime;
		float nextY = g_Player.Y + playerVelocityY * deltaTime;

		// 바닥 충돌
		if (map[(int)nextY + 1][g_Player.X] == L'▓')
		{
			isJumping = false;
			playerVelocityY = 0;
			g_Player.Y = (int)nextY;
		}
		// 아래로 떨어지기
		else
		{
			g_Player.Y = (int)nextY;
		}
	}
}