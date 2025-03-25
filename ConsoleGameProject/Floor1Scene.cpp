#include <stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "Floor1Scene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace Menu {
    // Map
    const char* menuMap[] = {
    "############################################################", 
    "                                                            ",
    "                                                            ",
    "   TTTTT  OOO  W   W  EEEEE  RRRR      OOO   FFFFF   77777  ",
    "     T   O   O W   W  E      R   R    O   O  F       7   7  ",
    "     T   O   O W W W  EEEE   RRRR     O   O  FFFF        7  ",
    "     T   O   O WW WW  E      R  R     O   O  F           7  ",
    "     T    OOO  W   W  EEEEE  R   R     OOO   F           7  ",
    "                                                            ",
    "                                                            ",
    "                                                            ",
    "############################################################",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                     >> Game Start                        #",
    "#                     >> How to Play?                      #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "#                                                          #",
    "############################################################"
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
            ConsoleRenderer::ScreenDrawString(0, i, menuMap[i], FG_YELLOW);
        }
	}
}
