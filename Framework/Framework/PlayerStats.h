#pragma once

//Una nueva clase en la que creamos y ponemos las vidas del jugador
class PlayerStats {
protected:
	int vidas;
public:
	PlayerStats();	//Ahi ponemos que vidas sea 3
	int getVidas() { return vidas; }	//Comprobar cuantas vidas tiene
	void menosVida() { vidas--; }		//Restar vidas
};