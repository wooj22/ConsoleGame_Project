#include <stdio.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "Floor4Scene.h"
#include "Floor5Scene.h"


namespace Floor4 {
	// Map Data
	const wchar_t* floor4StaticMap[] = {

	L"▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓",
	};
	const int mapHeight = sizeof(floor4StaticMap) / sizeof(floor4StaticMap[0]);


	// Start
	void Initalize() {

	}

	// Update
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {
			Game::g_SceneCurrent = Game::FLOOR5_SCENE;
			Floor5::Initalize();
		}
	}

	// Render
	void Render() {
		for (int i = 0; i < mapHeight; i++)
		{
			ConsoleRenderer::ScreenDrawStringW(0, i, floor4StaticMap[i], FG_GRAY | FOREGROUND_INTENSITY);
		}
	}
}