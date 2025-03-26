#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor4Scene.h"
#include "Floor5Scene.h"
#include "Time.h"
#include "Player.h"

namespace Floor4 {
	// Map Data
	const wchar_t* floor4StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                    Current Floor : 4                       ",
	L"                 포기는 배추 셀 떄나 쓰는 것                   ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                        G ▓",
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
	L"▓                 G                                        ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor4StaticMap) / sizeof(floor4StaticMap[0]);


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
			PlayerMove(floor4StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor4StaticMap);

		// scene change
		if (floor4StaticMap[g_Player.Y][g_Player.X] == 'G') {
			Game::g_SceneCurrent = Game::FLOOR5_SCENE;
			Floor5::Initalize();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR5_SCENE;
			Floor5::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor4StaticMap[i], FG_YELLOW);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}
}