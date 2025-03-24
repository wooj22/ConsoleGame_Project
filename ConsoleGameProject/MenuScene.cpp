#include <stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace Menu {
	// Start
	void Initalize() {

	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::PLAY_SCENE;
			Play::Initalize();
		}
	}

	// Render
	void Render() {
		ConsoleRenderer::ScreenDrawString(0, 0, "MENU SCENE  [Spacebar]", FG_YELLOW);
	}
}
