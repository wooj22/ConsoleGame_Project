#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor6Scene.h"
#include "Floor7Scene.h"


namespace Floor6 {
	// Map Data
	const wchar_t* floor6StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	};
	const int mapHeight = sizeof(floor6StaticMap) / sizeof(floor6StaticMap[0]);


	// Start
	void Initalize() {

	}

	// Update
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR7_SCENE;
			Floor7::Initalize();
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor6StaticMap[i], FG_GRAY | FOREGROUND_INTENSITY);
		}
	}
}