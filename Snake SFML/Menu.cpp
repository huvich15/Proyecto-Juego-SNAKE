#include "Menu.h"


Menu::Menu(int resolucion_x, int resolucion_y, string titulo) { // constructor
	retrazo_clase = this->retrazo_clase; // incializamos varialbles publicas
	eleccion = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo); //creamos la ventana grafica 
	eleccion->setFramerateLimit(60); // para la ventana grafica no tenga lag o trabones 

	txt1 = new Texture;
	txt2 = new Texture;
	txt3 = new Texture;
	txt4 = new Texture;
	txt5 = new Texture;
	txt1->loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/fondo.png");
	txt2->loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/facil.png");
	txt3->loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/normal.png");
	txt4->loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/dificil.png");
	txt5->loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/gradual.png");

	//Provar metodo
	fondo = new Sprite(*txt1);
	facil = new Sprite(*txt2);
	normal = new Sprite(*txt3);
	dificil = new Sprite(*txt4);
	gradual = new Sprite(*txt5);
	//Ajustar la imagen de fondo al tamano de la ventana 
	fondo->setScale(float(resolucion_x) / fondo->getTexture()->getSize().x, float(resolucion_y) / fondo->getTexture()->getSize().y); //reduicir la imagen al tamano de la ventana grafica
	facil->setPosition(100, 100);
	normal->setPosition(100, 185);
	dificil->setPosition(100, 270);
	gradual->setPosition(100, 350);

	//Se carga el tipo de letra para el texto
	fuente = new Font;
	fuente->loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Letras/Drops.ttf");
	
	//Se crea un texto
	menu = new Text;
	menu->setFont(*fuente);
	menu->setCharacterSize(40);
	menu->setFillColor(Color::White);
	menu->setPosition(180, 0);
	menu->setString("Proyecto SNAKE...\n\tDificultad");
	dificultad = new Text;
	dificultad->setFont(*fuente);
	dificultad->setCharacterSize(30);
	dificultad->setFillColor(Color::White);
	dificultad->setPosition(170, 100);
	dificultad->setString("<-FACIL\n\n\n<-NORMAL\n\n\n<-DIFICIL\n\n\n<-PROGRESIVO");

	evento = new Event;

	GameLoop();
}

void Menu::Dibujar(){
	eleccion->clear();
	eleccion->draw(*fondo);
	eleccion->draw(*menu);
	eleccion->draw(*dificultad);
	eleccion->draw(*facil);
	eleccion->draw(*normal);
	eleccion->draw(*dificil);
	eleccion->draw(*gradual);

	eleccion->display();
}

void Menu::GameLoop() { //para mostrar en pantalla simepre las imagenes y la funciones de las teclas 
	while (eleccion->isOpen()){
		Eventos();
		Dibujar();
	}
}

void Menu::Eventos() {
	while (eleccion->pollEvent(*evento)) {
		switch (evento->type)
		{
		case Event::Closed:
			eleccion->close();
			exit(0);
			break;
		case Event::KeyPressed:
			if (Keyboard::isKeyPressed(Keyboard::F)) {
				//retrazo_clase = 1;
				//ObtenerRetrazo(retrazo_clase);
				eleccion->close();
			}
			if (Keyboard::isKeyPressed(Keyboard::N)) {
				//retrazo_clase = 2;
				//ObtenerRetrazo(retrazo_clase);
				eleccion->close();
			}
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				//retrazo_clase = 3;
				//ObtenerRetrazo(retrazo_clase);
				eleccion->close();
			}
			if (Keyboard::isKeyPressed(Keyboard::P)) {
				//retrazo_clase = 4;
				//ObtenerRetrazo(retrazo_clase);
				eleccion->close();
			}
			break;
		}
	}
}
float Menu::ObtenerRetrazo(float numero) {
	if (Keyboard::isKeyPressed(Keyboard::F)) {
		retrazo_clase = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::N)) {
		retrazo_clase = 2;
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		retrazo_clase = 3;
	}
	if (Keyboard::isKeyPressed(Keyboard::P)) {
		retrazo_clase = 4;
	}
	return retrazo_clase;
}