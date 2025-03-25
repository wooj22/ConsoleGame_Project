#pragma once

namespace Game {
	// enum으로 Scene 관리
	enum Scene {
		MENU_SCENE,
		FLOOR1_SCENE,
		FLOOR2_SCENE,
		FLOOR3_SCENE,
		FLOOR4_SCENE,
		FLOOR5_SCENE,
		FLOOR6_SCENE,
		FLOOR7_SCENE,
		END_SCENE
	};

	extern Scene g_SceneCurrent;
	//Scene g_SceneNext;
}
