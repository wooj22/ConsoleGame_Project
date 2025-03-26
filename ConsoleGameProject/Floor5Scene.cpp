#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor5Scene.h"
#include "Floor6Scene.h"
#include "Time.h"
#include "Player.h"

namespace Floor5 {
	// Map Data
	const wchar_t* floor5StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                   Current Floor : 5                      ▓",
	L"▓                        화이팅 ><                         ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                        G ▓",
	L"▓                                              ▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                         ▓▓               ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                 ▓▓▓▓▓                    ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                            ▓▓                            ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ▓▓▓                                 ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                        ▓▓▓▓▓▓                            ▓",
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
	L"▓                                           ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                     ▓▓▓                  ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                              ▓▓▓▓▓                       ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ▓▓▓                                 ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓              ▓▓▓                                         ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓        ▓▓▓▓▓                                             ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
	const int mapHeight = sizeof(floor5StaticMap) / sizeof(floor5StaticMap[0]);


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
			PlayerMove(floor5StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor5StaticMap);

		// scene change
		if (floor5StaticMap[g_Player.Y][g_Player.X] == 'G') {
			Game::g_SceneCurrent = Game::FLOOR6_SCENE;
			Floor6::Initalize();
		}

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR6_SCENE;
			Floor6::Initalize();
		}
	}

	// Render
	void Render() {
		// map
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor5StaticMap[i], FG_GREEN);
		}

		// player
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_RED);
	}
}