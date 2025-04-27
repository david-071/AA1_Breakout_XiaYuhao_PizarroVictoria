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
    std::ifstream archivoLectura(nombreArchivo, std::ios::binary);
    if (!archivoLectura.is_open()) {
        std::cout << "No se pudo abrir el archivo de ranking." << std::endl;
        return;
    }

    std::vector<PlayerStats> top;

    while (archivoLectura.peek() != EOF) {
        PlayerStats playerStats;
        size_t length;

        if (!archivoLectura.read(reinterpret_cast<char*>(&length), sizeof(length))) {
            break;
        }

        if (length == 0 || length > 100) {
            std::cout << "Error leyendo nombre, archivo corrupto o mal formado." << std::endl;
            break;
        }

        playerStats.nombre.resize(length);

        if (!archivoLectura.read(&playerStats.nombre[0], length)) {
            std::cout << "Error leyendo nombre, archivo corrupto." << std::endl;
            break;
        }

        if (!archivoLectura.read(reinterpret_cast<char*>(&playerStats.puntuacion), sizeof(playerStats.puntuacion))) {
            std::cout << "Error leyendo puntuacion, archivo corrupto." << std::endl;
            break;
        }

        top.push_back(playerStats);
    }

    archivoLectura.close();

    // Mostrar el ranking en consola
    int posicion = 1;
    for (const PlayerStats& playerStats : top) {
        std::cout << posicion << ". " << playerStats.nombre << " - " << playerStats.puntuacion << " puntos" << std::endl;
        ++posicion;
    }
    std::cout << "=======================" << std::endl;
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
    std::cout << std::endl;
    MostrarRanking("ranking.bin");
}
