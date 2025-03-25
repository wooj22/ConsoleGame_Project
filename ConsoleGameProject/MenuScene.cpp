#include <stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "Floor1Scene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "MapData.h"

namespace Menu {
    // Map Data
	const wchar_t* menuMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"                                                            ",
	L"                                                            ",
	L"   TTTTT  OOO  W   W  EEEEE  RRRR      OOO   FFFFF   77777  ",
	L"     T   O   O W   W  E      R   R    O   O  F       7   7  ",
	L"     T   O   O W W W  EEEE   RRRR     O   O  FFFF        7  ",
	L"     T   O   O WW WW  E      R  R     O   O  F           7  ",
	L"     T    OOO  W   W  EEEEE  R   R     OOO   F           7  ",
	L"                                                            ",
	L"                                                            ",
	L"                                                            ",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓            ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄           ▓",
	L"▓            █░░░░░░░░▀█▄▀▄▀██████░▀█▄▀▄▀██████░           ▓",
	L"▓            ░░░░░░░░░░▀█▄█▄███▀░░░ ▀██▄█▄███▀░            ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                      ***************                     ▓",
	L"▓                                                          ▓",
	L"▓                   >>  Game Start                         ▓",
	L"▓                                                          ▓",
	L"▓                       How to Play?                       ▓",
	L"▓                                                          ▓",
	L"▓                      ***************                     ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓                                                          ▓",
	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓"
	};
    const int mapHeight = sizeof(menuMap) / sizeof(menuMap[0]);

	// Start
	void Initalize() {

	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::PLAY_SCENE;
			Floor1::Initalize();
		}
	}

	// Render
	void Render() {
        for (int i = 0; i < mapHeight; i++)
        {
            ConsoleRenderer::ScreenDrawStringW(0, i, menuMap[i], FG_YELLOW);
        }
	}
}
