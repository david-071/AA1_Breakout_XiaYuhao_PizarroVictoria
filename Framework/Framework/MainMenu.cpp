#include "MenuScene.h"

void MenuScene::Update()
{
	if (GetAsyncKeyState('2') != 0) {
		nextScene = "Ranking"; //Selects the next scene 
		finished = true; //Indicates that this scene is finished
	}
	else if (GetAsyncKeyState('1') != 0) {
		nextScene = "Gameplay";
		finished = true;

	}
	else if (GetAsyncKeyState('3') != 0)
	{
		nextScene = "Credits";
		finished = true;
	}
	else if (GetAsyncKeyState('0') != 0) {
		nextScene = "Exit";
		finished = true;
	}
}

void MenuScene::Render()
{
	ConsoleSetColor(GREEN, BLACK);
	std::cout << "                                                                                                                                                                                 \n";
	std::cout << "                                 ***** **        ***** ***       ***** **            **             *****                       * ***         ***** *    **     ****           * \n";
	std::cout << "                              ******  ***     ******  * **    ******  **** *      *****          ******                       *  ****      ******  *  *****    *  *************  \n";
	std::cout << "                             **   *  * **    **   *  *  **   **   *  * ****      *  ***         **   *  *    **              *  *  ***    **   *  *     ***** *     *********    \n";
	std::cout << "                            *    *  *  **   *    *  *   **  *    *  *   **          ***        *    *  *   **** *           *  **   ***  *    *  **     * **  *     *  *         \n";
	std::cout << "                                *  *   *        *  *    *       *  *               *  **           *  *     ****           *  ***    ***     *  ***     *      **  *  **         \n";
	std::cout << "                               ** **  *        ** **   *       ** **               *  **          ** **    * **           **   **     **    **   **     *         *  ***         \n";
	std::cout << "                               ** ** *         ** **  *        ** **              *    **         ** **   *               **   **     **    **   **     *        **   **         \n";
	std::cout << "                               ** ***          ** ****         ** ******          *    **         ** *****                **   **     **    **   **     *        **   **         \n";
	std::cout << "                               ** ** ***       ** **  ***      ** *****          *      **        ** ** ***               **   **     **    **   **     *        **   **         \n";
	std::cout << "                               ** **   ***     ** **    **     ** **             *********        ** **   ***             **   **     **    **   **     *        **   **         \n";
	std::cout << "                               *  **     **    *  **    **     *  **            *        **       *  **    ***             **  **     **     **  **     *         **  **         \n";
	std::cout << "                                  *      **       *     **        *             *        **          *       ***            ** *      *       ** *      *          ** *      *   \n";
	std::cout << "                              ****     ***    ****      ***   ****         *   *****      **     ****         ***            ***     *         ***      *           ***     *    \n";
	std::cout << "                             *  ********     *  ****    **   *  ***********   *   ****    ** *  *  *****        ***  *        *******           ********             *******     \n";
	std::cout << "                            *     ****      *    **     *   *     ******     *     **      **  *    ***           ***           ***               ****                 ***       \n";
	std::cout << "                            *               *               *                *                 *                                                                                 \n";
	std::cout << "                             **              **              **               **                **                                                                               \n";
	std::cout << "\n";
	ConsoleSetColor(BLUE, BLACK);
	std::cout << "															Press...\n\n";
	std::cout << "  1- Play\n";
	std::cout << "  2- Ranking\n";
	std::cout << "  3- Credits\n";
	ConsoleSetColor(RED, BLACK);
	std::cout << "  0- Exit\n";
	ConsoleSetColor(WHITE, BLACK);

}
