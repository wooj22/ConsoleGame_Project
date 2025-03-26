#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor3Scene.h"
#include "Floor4Scene.h"
#include "Time.h"
#include "Player.h"


namespace Floor3 {
	// Map Data
	const wchar_t* floor3StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                   Current Floor : 3                      ▓",
	L"▓                 설마 이걸 못하진 않겠진                  ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                        G ▓",
	L"▓                                         ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                  ▓▓                      ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                           ▓                              ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ▓▓                                  ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                 ▓▓▓                                      ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                        ▓                                 ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                ▓▓                        ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                      ▓▓▓                 ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                             ▓▓▓          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                           ▓▓▓            ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                     ▓▓▓                  ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                              ▓                           ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ▓▓▓                                 ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                ▓▓                        ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                       ▓▓                                 ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor3StaticMap) / sizeof(floor3StaticMap[0]);


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
			PlayerMove(floor3StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor3StaticMap);

		// scene change
		if (floor3StaticMap[g_Player.Y][g_Player.X] == 'G') {
			Game::g_SceneCurrent = Game::FLOOR4_SCENE;
			Floor4::Initalize();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR4_SCENE;
			Floor4::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor3StaticMap[i], FG_YELLOW);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}
}