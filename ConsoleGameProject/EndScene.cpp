#include <stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"

namespace End {
	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update 
	void Update() {
		// scene change
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 5.0) {
			Game::g_SceneCurrent = Game::MENU_SCENE;
			Menu::Initalize();
		}
	}

	// Render
	void Render() {
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE  5초뒤 MENU SCENE으로 이동합니다", FG_GRAY);
	}
}