#include "RankingScene.h"
#include "PlayerStats.h"
#include <fstream>
//RankingScene::RankingScene() {
//
//}
void RankingScene::Update()
{
	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void RankingScene::MostrarRanking(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (archivo.is_open()) {
        int posicion = 1;
        while (archivo.is_open()) {
            PlayerStats playerstats;
            size_t length;
            if (!archivo.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

            playerstats.nombre.resize(length);
            archivo.read(&playerstats.nombre[0], length);

            archivo.read(reinterpret_cast<char*>(&playerstats.puntuacion), sizeof(playerstats.puntuacion));

            std::cout << posicion << ". " << playerstats.nombre << " - " << playerstats.puntuacion << std::endl;
            posicion++;
        }
        archivo.close();
    }
    else {
        std::cout << "No se pudo abrir el archivo de puntuaciones." << std::endl;
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
    /*MostrarRanking("ranking.bin");*/
}
