#pragma once

//Una nueva clase en la que creamos y ponemos las vidas del jugador
class PlayerStats {
protected:
	int vidas;
	int puntuacion;
	int bloquesSinPala;
	int bloquesTotales;
public:
	PlayerStats();	//Ahi ponemos que vidas sea 3
	int getVidas() { return vidas; }	//Devuelve cuantas vidas tiene el jugador
	void menosVida() { vidas--; }		//Restar vidas
	int getPuntuacion() { return puntuacion; }	//Devuelve la puntuacion del jugador
	void sumarPuntuacion();
	void masBloques() { bloquesSinPala++; }
	void tocaPala() { bloquesSinPala = 0; }
	void masBloquesTotales() { bloquesTotales++; }
	int getBloquesRotos() { return bloquesTotales; }
};