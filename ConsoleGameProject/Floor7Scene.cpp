#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor7Scene.h"
#include "EndScene.h"


namespace Floor7 {
	// Map Data
	const wchar_t* floor7Map[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	};
	const int mapHeight = sizeof(floor7Map) / sizeof(floor7Map[0]);


	// Start
	void Initalize() {

	}

	// Update
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::END_SCENE;
			End::Initalize();
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor7Map[i], FG_GRAY | FOREGROUND_INTENSITY);
		}
	}
}