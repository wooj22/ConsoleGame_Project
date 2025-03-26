#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "Floor1Scene.h"
#include "Floor2Scene.h"
#include "EndScene.h"

namespace Floor1 {

	/*--------- Map Data ---------*/
	const wchar_t* floor1StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                    Current Floor : 1                       ",
	L"                  이 정도는 거뜬하겠지?                       ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                              ▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                     ▓▓▓▓▓▓▓▓▓▓▓▓         ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                           ▓▓▓▓▓▓▓▓▓▓▓▓                   ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                 ▓▓▓▓▓▓▓▓▓▓▓▓                             ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓         ▓▓▓▓▓▓▓▓▓▓▓▓                                     ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓                                               ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓            ▓▓▓▓▓▓▓▓▓▓▓▓                                  ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                       ▓▓▓▓▓▓▓▓▓▓▓▓                       ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                   ▓▓▓▓▓▓▓▓▓▓▓▓           ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                              ▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                     ▓▓▓▓▓▓▓▓▓▓▓▓         ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                              ▓▓▓▓▓▓▓▓▓▓▓▓                ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ▓▓▓▓▓▓▓▓▓▓▓▓                        ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓              ▓▓▓▓▓▓▓▓▓▓▓▓                                ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓        ▓▓▓▓▓▓▓▓▓▓▓▓                                      ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor1StaticMap) / sizeof(floor1StaticMap[0]);

	/*--------- Player ---------*/
	COORD g_Player = { 3, 57 };
	bool isJumping = false;
	float playerVelocityY = 0.0f;
	float gravity = 300.0f; // 중력
	float jumpPower = -6.0f; // 점프 속도

	// Move
	void PlayerMove()
	{
		// 임시 좌표
		int nextX = g_Player.X;
		int nextY = g_Player.Y;

		// 입력 처리
		if (Input::IsKeyDown(VK_LEFT) && floor1StaticMap[g_Player.Y][g_Player.X - 1] != L'▓') {
			nextX--;
		}
		if (Input::IsKeyDown(VK_RIGHT) && floor1StaticMap[g_Player.Y][g_Player.X + 1] != L'▓') {
			nextX++;
		}

		// 경계 검사 (콘솔 창 크기 기준)
		if (nextY < 0) nextY = 0;

		// 최종 위치 업데이트
		g_Player.X = nextX;
	}

	// Jump
	void PlayerJump() {
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
			if (floor1StaticMap[(int)nextY + 1][g_Player.X] == L'▓')
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

	/*--------- Floor1 Game -------------*/
	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update
	void Update() {
		// input & play controll
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 0.1f) {
			PlayerMove();
			Time::Initialize();
		}
		PlayerJump();

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR2_SCENE;
			Floor2::Initalize();
		}
	}

	// Render
	void Render() {
		// map
        for (int i = 0; i < mapHeight; i++)
        {
            ConsoleRenderer::ScreenDrawStringW(0, i, floor1StaticMap[i], FG_GRAY | FOREGROUND_INTENSITY);
        }

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}
}

