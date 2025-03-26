#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor7Scene.h"
#include "EndScene.h"
#include "Time.h"
#include "Player.h"

namespace Floor7 {
	// Map Data
	const wchar_t* floor7StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓   G                                                      ▓",
	L"▓                   Current Floor : 7                      ▓",
	L"▓                     이건 나도 못함                       ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓   ▓           ▓         ▓                                ▓",
	L"▓                                                          ▓",
	L"▓                                ▓                         ▓",
	L"▓                                                          ▓",
	L"▓                                     ▓     ▓   ▓          ▓",
	L"▓                                                          ▓",
	L"▓                                                   ▓      ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                   ▓                                      ▓",
	L"▓               ▓                                          ▓",
	L"▓            ▓          ▓                        ▓         ▓",
	L"▓                                            ▓             ▓",
	L"▓         ▓                               ▓                ▓",
	L"▓                             ▓                            ▓",
	L"▓      ▓                                                   ▓",
	L"▓                                  ▓                       ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓   ▓                                                      ▓",
	L"▓             ▓                                            ▓",
	L"▓                          ▓                               ▓",
	L"▓                                      ▓                   ▓",
	L"▓                                                 ▓        ▓",
	L"▓                                                      ▓   ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                            ▓             ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                         ▓                ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                    ▓                     ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                         ▓                                ▓",
	L"▓                              ▓                           ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                         ▓                                ▓",
	L"▓                                                          ▓",
	L"▓                              ▓                           ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                          ▓                               ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor7StaticMap) / sizeof(floor7StaticMap[0]);


	// Start
	void Initalize() {
		Time::Initialize();
		g_Player = { 3, 57 };
	}

	// Update
	void Update() {
		// input & play controll
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 0.1f) {
			PlayerMove(floor7StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor7StaticMap);

		// scene change
		if (floor7StaticMap[g_Player.Y][g_Player.X] == 'G') {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor7StaticMap[i], FG_RED);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_YELLOW);
	}
}