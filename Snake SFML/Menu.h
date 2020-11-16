#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Menu
{
public:
	float retrazo_clase;
	Menu(int resolucion_x, int resolucion_y, string titulo);

	
	void Dibujar();
	void GameLoop();
	void Eventos();
	float ObtenerRetrazo(float numero);



private:
	int fps = 60;
	RenderWindow* eleccion;
	
	Texture* txt1;
	Texture* txt2;
	Texture* txt3;
	Texture* txt4;
	Texture* txt5;

	Sprite* fondo;
	Sprite* facil;
	Sprite* normal;
	Sprite* dificil;
	Sprite* gradual;

	Font* fuente;
	Text* menu;
	Text* dificultad;

	Event* evento;
	
};

