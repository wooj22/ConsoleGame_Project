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
	// �� �ʱ�ȭ
	Scene g_SceneCurrent = Game::MENU_SCENE;

	// Start : ���� ����
	void Initalize() {
		Menu::Initalize();
	}

	// Update : SceneCurrent�� ���� Update()ȣ��
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
			printf("������� �ȵǴµ�\n");
			break;
		}
	}

	// Render : SceneCurrent�� ���� Render()ȣ��  
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
			printf("������� �ȵǴµ�\n");
			break;
		}

		ConsoleRenderer::ScreenFlipping();
	}
}

// Main : ���� ����
// [Spacebar]�� ������ ���� ��ȯ�մϴ�.
// ���� ���ᰡ ������ �����ϼ���
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