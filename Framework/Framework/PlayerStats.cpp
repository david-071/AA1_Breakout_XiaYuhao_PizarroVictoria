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
		while (archivoLectura.peek() != EOF) {
			PlayerStats playerStats;
			size_t length;

			if (!archivoLectura.read(reinterpret_cast<char*>(&length), sizeof(length))) break;

			if (length > 0 && length < 100) { // Evitamos números absurdos
				playerStats.nombre.resize(length);
				if (!archivoLectura.read(&playerStats.nombre[0], length)) break;
				if (!archivoLectura.read(reinterpret_cast<char*>(&playerStats.puntuacion), sizeof(playerStats.puntuacion))) break;
				top.push_back(playerStats);
			}
			else {
				break; // Archivo corrupto o datos inválidos
			}
		}
		archivoLectura.close();
	}

	// Agregar nueva puntuación
	PlayerStats playerStats;
	playerStats.nombre = nombreJugador;
	playerStats.puntuacion = puntuacion;
	top.push_back(playerStats);

	// Ordenar de mayor a menor puntuación
	std::sort(top.begin(), top.end(), [](const PlayerStats& a, const PlayerStats& b) {
		return a.puntuacion > b.puntuacion;
	});

	bool maxPlayer = (top.size() > 5);

	if (top.size() > 5) {
		top.resize(5);
	}

	if (maxPlayer) {
		top.resize(5); // Dejamos solo los mejores 5
	}

	// Guardar el archivo
	std::ofstream archivoEscritura;
	if (maxPlayer) {
		// Si hay más de 5, reescribir (truncar) los mejores 5
		archivoEscritura.open(nombreArchivo, std::ios::binary | std::ios::trunc);
	}
	else {
		// Si hay menos de 5, simplemente añadir
		archivoEscritura.open(nombreArchivo, std::ios::binary | std::ios::app);
	}

	if (archivoEscritura.is_open()) {
		if (maxPlayer) {
			// Al truncar, grabamos todos de nuevo
			for (const PlayerStats& pj : top) {
				size_t length = pj.nombre.size();
				archivoEscritura.write(reinterpret_cast<const char*>(&length), sizeof(length));
				archivoEscritura.write(pj.nombre.c_str(), length);
				archivoEscritura.write(reinterpret_cast<const char*>(&pj.puntuacion), sizeof(pj.puntuacion));
			}
		}
		else {
			// Si estamos en modo append, solo escribimos el nuevo
			size_t length = playerStats.nombre.size();
			archivoEscritura.write(reinterpret_cast<const char*>(&length), sizeof(length));
			archivoEscritura.write(playerStats.nombre.c_str(), length);
			archivoEscritura.write(reinterpret_cast<const char*>(&playerStats.puntuacion), sizeof(playerStats.puntuacion));
		}
		archivoEscritura.close();
	}
}