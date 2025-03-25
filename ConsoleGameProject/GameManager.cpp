#include <stdio.h>
#include <windows.h>
#include "ConsoleRenderer.h"
#include "Input.h"
#include "GameManager.h"
#include "MenuScene.h"
#include "Floor1Scene.h"
#include "Floor2Scene.h"
#include "Floor3Scene.h"
#include "Floor4Scene.h"
#include "Floor5Scene.h"
#include "Floor6Scene.h"
#include "Floor7Scene.h"
#include "EndScene.h"

namespace Game {
	// 씬 초기화
	Scene g_SceneCurrent = Game::MENU_SCENE;

	// Start : 게임 시작
	void Initalize() {
		Menu::Initalize();
	}

	// Update : SceneCurrent에 따라 Update()호출
	void Update() {
		// key input
		Input::Update();

		// update
		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Update();
			break;
		case Game::FLOOR1_SCENE:
			Floor1::Update();
			break;
		case Game::FLOOR2_SCENE:
			Floor2::Update();
			break;
		case Game::FLOOR3_SCENE:
			Floor3::Update();
			break;
		case Game::FLOOR4_SCENE:
			Floor4::Update();
			break;
		case Game::FLOOR5_SCENE:
			Floor5::Update();
			break;
		case Game::FLOOR6_SCENE:
			Floor6::Update();
			break;
		case Game::FLOOR7_SCENE:
			Floor7::Update();
			break;
		case Game::END_SCENE:
			End::Update();
			break;
		default:
			printf("여기오면 안되는데\n");
			break;
		}
	}

	// Render : SceneCurrent에 따라 Render()호출  
	void Render() {
		ConsoleRenderer::ScreenClear();

		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Render();
			break;
		case Game::FLOOR1_SCENE:
			Floor1::Render();
			break;
		case Game::FLOOR2_SCENE:
			Floor2::Render();
			break;
		case Game::FLOOR3_SCENE:
			Floor3::Render();
			break;
		case Game::FLOOR4_SCENE:
			Floor4::Render();
			break;
		case Game::FLOOR5_SCENE:
			Floor5::Render();
			break;
		case Game::FLOOR6_SCENE:
			Floor6::Render();
			break;
		case Game::FLOOR7_SCENE:
			Floor7::Render();
			break;
		case Game::END_SCENE:
			End::Render();
			break;
		default:
			printf("여기오면 안되는데\n");
			break;
		}

		ConsoleRenderer::ScreenFlipping();
	}
}

// Main : 게임 진행
// [Spacebar]를 누르면 씬을 전환합니다.
// 루프 종료가 없으니 주의하세요
int main() {
	ConsoleRenderer::ScreenInit();
	Game::Initalize();

	while (true)
	{
		Game::Update();
		Game::Render();
	}

	ConsoleRenderer::ScreenRelease();
	return 0;
}