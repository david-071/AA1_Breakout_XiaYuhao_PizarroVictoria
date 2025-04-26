#include "PlayerStats.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

PlayerStats::PlayerStats() {
	vidas = 3;
	puntuacion = 0;
	bloquesSinPala = 0;
}

void PlayerStats::sumarPuntuacion() {
	puntuacion += 10 + 5 * bloquesSinPala;
}

void PlayerStats::guardarPuntuacion(const std::string& nombreArchivo) {
	std::string nombreJugador;

	std::cout << "Introduce tu nombre: ";
	std::getline(std::cin, nombreJugador);

	std::vector<PlayerStats> top;
	std::ifstream archivoLectura(nombreArchivo, std::ios::binary);
	if (archivoLectura.is_open()) {
		while (archivoLectura.is_open()) {
			PlayerStats pj;
			size_t length;
			if (!archivoLectura.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

			pj.nombre.resize(length);
			archivoLectura.read(&pj.nombre[0], length);

			archivoLectura.read(reinterpret_cast<char*>(&pj.puntuacion), sizeof(pj.puntuacion));
			top.push_back(pj);
		}
		archivoLectura.close();
	}

	PlayerStats playerStats;
	playerStats.nombre = nombreJugador;
	playerStats.puntuacion = puntuacion;

	top.push_back(playerStats);

	std::sort(top.begin(), top.end(), [](const PlayerStats& a, const PlayerStats& b) {
		return a.puntuacion > b.puntuacion;
	});

	if (top.size() > 5) {
		top.resize(5);
	}

	std::ofstream archivoEscritura(nombreArchivo, std::ios::binary | std::ios::trunc);
	if (archivoEscritura.is_open()) {
		for (const PlayerStats& pj : top) {
			uint32_t length = pj.nombre.size();
			archivoEscritura.write(reinterpret_cast<const char*>(&length), sizeof(length));
			archivoEscritura.write(pj.nombre.c_str(), length);
			archivoEscritura.write(reinterpret_cast<const char*>(&pj.puntuacion), sizeof(pj.puntuacion));
		}
		archivoEscritura.close();
	}
}