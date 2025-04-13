#include "RankingScene.h"
#include <fstream>
RankingScene::RankingScene() {

}
void RankingScene::Update()
{
	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void RankingScene::Render()
{
	std::cout << "    ____              __   _            \n";
	std::cout << "   / __ \____ _____  / /__(_)___  ____ _\n";
	std::cout << "  / /_/ / __ `/ __ \/ //_/ / __ \/ __ `/\n";
	std::cout << " / _, _/ /_/ / / / / ,< / / / / / /_/ / \n";
	std::cout << "/_/ |_|\__,_/_/ /_/_/|_/_/_/ /_/\__, /  \n";
	std::cout << "                               /____/   \n";
	std::cout << "Press R to go back to the menu;";
}
