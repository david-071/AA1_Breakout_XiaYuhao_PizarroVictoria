#include "CreditsScene.h"

void CreditsScene::Update()
{
	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void CreditsScene::Render()
{
	ConsoleSetColor(BLUE, BLACK);
	std::cout << "        ***** **                                                                                                                   \n";
	std::cout << "     ******  ****                                                                                                                  \n";
	std::cout << "    **   *  *  ***                                                                                                                 \n";
	std::cout << "   *    *  *    ***                                                                                                                \n";
	std::cout << "       *  *      ** ***  ****       ****                  ***  ****                                   ****       **   ****         \n";
	std::cout << "      ** **      **  **** **** *   * ***  *     ****       **** **** *    ****    *** **** ****      * ***  *     **    ***  *     \n";
	std::cout << "      ** **      **   **   ****   *   ****     *  ***  *    **   ****    * ***  *  *** **** ***  *  *   ****      **     ****      \n";
	std::cout << "    **** **      *    **         **    **     *    ****     **          *   ****    **  **** ****  **    **       **      **       \n";
	std::cout << "   * *** **     *     **         **    **    **     **      **         **    **     **   **   **   **    **       **      **       \n";
	std::cout << "      ** *******      **         **    **    **     **      **         **    **     **   **   **   **    **       **      **       \n";
	std::cout << "      ** ******       **         **    **    **     **      **         **    **     **   **   **   **    **       **      **       \n";
	std::cout << "      ** **           **         **    **    **     **      **         **    **     **   **   **   **    **       **      **       \n";
	std::cout << "      ** **           ***         ******     **     **      ***        **    **     **   **   **    ******         *********       \n";
	std::cout << "      ** **            ***         ****       ********       ***        ***** **    ***  ***  ***    ****            **** ***      \n";
	std::cout << " **   ** **                                     *** ***                  ***   **    ***  ***  ***                         ***     \n";
	std::cout << "***   *  *                                           ***                                                            *****   ***    \n";
	std::cout << " ***    *                                      ****   ***                                                         ********  **     \n";
	std::cout << "  ******                                     *******  **                                                         *      ****       \n";
	std::cout << "    ***                                     *     ****                                                                             \n";
	std::cout << "\n\n";
	std::cout << "***                                                                                                                                \n";
	std::cout << " ***                                                                     *                                                         \n";
	std::cout << "  **                                                                    ***                                                        \n";
	std::cout << "  **                                                                     *                                                         \n";
	std::cout << "  **    **   ****                                ****          ****                                      ****       ****           \n";
	std::cout << "  **     **    ***  *    ***        ****        * ***  *      * ***  * ***        ***    ***  ****      * **** *   * ***  *        \n";
	std::cout << "  **     **     ****    * ***      *  ***  *   *   ****      *   ****   ***      * ***    **** **** *  **  ****   *   ****         \n";
	std::cout << "  **     **      **    *   ***    *    ****   **    **      **    **     **     *   ***    **   ****  ****       **    **          \n";
	std::cout << "  **     **      **   **    ***  **     **    **    **      **    **     **    **    ***   **    **     ***      **    **          \n";
	std::cout << "  **     **      **   ********   **     **    **    **      **    **     **    ********    **    **       ***    **    **          \n";
	std::cout << "  **     **      **   *******    **     **    **    **      **    **     **    *******     **    **         ***  **    **          \n";
	std::cout << "  **     **      **   **         **     **    **    **      **    **     **    **          **    **    ****  **  **    **          \n";
	std::cout << "  **      ******* **  ****    *  **     **     ******       *******      **    ****    *   **    **   * **** *    ******           \n";
	std::cout << "  *** *    *****   **  *******    ********      ****        ******       *** *  *******    ***   ***     ****      ****            \n";
	std::cout << "   ***                  *****       *** ***                 **            ***    *****      ***   ***                              \n";
	std::cout << "                                         ***                **                                                                     \n";
	std::cout << "                                   ****   ***               **                                                                     \n";
	std::cout << "                                 *******  **                 **                                                                    \n";
	std::cout << "                                *     ****                                                                                         \n";
	std::cout << "\n\n";
	std::cout << "En memoria por todos los ; que nos hemos olvidado, el igual cuando queriamos comparar dos cosas y el ahorro de 300 lineas si hubieramos pensado antes de ponernos a teclear\n";
	std::cout << "Hecho por Yuhao Xia y Victoria Pizarro\n";
	std::cout << "Press R to go back to the menu;";
}
