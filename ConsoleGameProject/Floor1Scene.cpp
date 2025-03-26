#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"
#include "Floor1Scene.h"
#include "Floor2Scene.h"
#include "EndScene.h"
#include "Player.h"

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
			PlayerMove(floor1StaticMap);
			Time::Initialize();
		}
		PlayerJump(floor1StaticMap);

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

