#include "PlayerStats.h"

PlayerStats::PlayerStats() {
	vidas = 3;
	puntuacion = 0;
	bloquesSinPala = 0;
}

void PlayerStats::sumarPuntuacion() {
	puntuacion += 10 + 5 * bloquesSinPala;
}