#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor6Scene.h"
#include "Floor7Scene.h"
#include "Time.h"
#include "Player.h"

namespace Floor6 {
	// Map Data
	const wchar_t* floor6StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"                    Current Floor : 6                       ",
	L"                     한번에 깨면 인정                         ",
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
	L"▓               G                                          ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor6StaticMap) / sizeof(floor6StaticMap[0]);


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
			PlayerMove(floor6StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor6StaticMap);

		// scene change
		if (floor6StaticMap[g_Player.Y][g_Player.X] == 'G') {
			Game::g_SceneCurrent = Game::FLOOR7_SCENE;
			Floor7::Initalize();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR7_SCENE;
			Floor7::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor6StaticMap[i], FG_YELLOW);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}
}