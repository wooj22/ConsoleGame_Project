#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor2Scene.h"
#include "Floor3Scene.h"
#include "Time.h"
#include "Player.h"


namespace Floor2 {
	// Map Data
	const wchar_t* floor2StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                    Current Floor : 2                       ",
	L"                    아직 거뜬하다~~~~                         ",
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
	L"▓             G                                            ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor2StaticMap) / sizeof(floor2StaticMap[0]);


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
			PlayerMove(floor2StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor2StaticMap);

		// scene change
		if (floor2StaticMap[g_Player.Y][g_Player.X] == 'G') {
			Game::g_SceneCurrent = Game::FLOOR3_SCENE;
			Floor3::Initalize();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR3_SCENE;
			Floor3::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor2StaticMap[i], FG_YELLOW);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}
}
