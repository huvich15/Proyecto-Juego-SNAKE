#include <SFML/Graphics.hpp> //Libreria grafica de SFML
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Menu.h"

using namespace std;
using namespace sf;

int puntos; //cuando come las frutas 
int juego = 0; //Valor que nos servira para ver cuando el usuario pierda
int A = 40, H = 30; //Nuemreo de cuadros en la ventana  40x30 pixel
int tamano = 16;   //tamano del cuadrado 16X16 // tamano del cesped
int w = tamano * A; // anchura de la ventana // recorrera 640 casillas 
int h = tamano * H; // altura de la ventana // 
int direccion, numero = 10;  //dir= direccion del snake // numero= con la cantidad de circulos que empieza el snake 
int fruta_aleatoria;
//eleccion de dificultad
int eleccion_retrazo; // darle velocidad o quitarle al snake

struct Snake
{
	int x, y;
}snake[1200]; // longitud maxima del snake es de 1200 // array para almacenar la ubicacion de cada parte del snake ya sea en x op en y 
struct Fruta        //ubicacion de las frutas del snake
{
	int x, y;
}fruta;
struct Muro1
{
	int x, y;
}muro1;
struct Muro2
{
	int x, y;
}muro2;
struct Muro3
{
	int x, y;
}muro3;
struct Muro4
{
	int x, y;
}muro4;
struct Muro5
{
	int x, y;
}muro5;
void Mover();
void MuroLadrillo();
void MuroLadrilloUno();
void MuroColumna();
void MuroColumnaUno();
void MuroPared();
void Mover()     // Funcion para mover el snake
{
	for (int i = numero; i > 0; --i){
		snake[i].x = snake[i - 1].x;    // Esta parte es para el movimineto del snake en X
		snake[i].y = snake[i - 1].y;	// Esta parte es para el movimineto del snake en Y
	}            

	if (direccion == 0) snake[0].y += 1;	// abajo	//
	if (direccion == 1) snake[0].x -= 1;	// izquierda	// Cambio de direccion de la cabeza del snake
	if (direccion == 2) snake[0].x += 1;	// derecha	//
	if (direccion == 3) snake[0].y -= 1;	// arriba	//

	if ((snake[0].x == fruta.x) && (snake[0].y == fruta.y)) // cuando el snake come una fruta
	{
		puntos = numero;   // aca se actualizan los puntos o las frutas comidas
		if (fruta_aleatoria == 0) { numero++; }          // aumenta su tamano en 1 cuadrados
		if (fruta_aleatoria == 1) { numero++; numero++; numero++; }  // aumenta su tamano en 3 cuadrados
		if (fruta_aleatoria == 2) { numero++; numero++; }  // aumenta su tamano en 2 cuadrados
		if (fruta_aleatoria == 3) { numero--; }  // decrece su tamano en 1 cuadrados
		if (fruta_aleatoria == 4) { numero--; numero--; numero--; numero--; numero--; }  // decrece su tamano en 5 cuadrados
		fruta_aleatoria = rand() % 5; //Se genera numeros aleatorios de 0 a 4
		fruta.x = rand() % A; // genera una nueva coordenada para la fruta en X
		fruta.y = rand() % H; // genera una nueva coordenada para la fruta en Y
	}
	
	if (snake[0].x > A) snake[0].x = 0; if (snake[0].x < 0) snake[0].x = A; //Para los limites del la ventana si sale de ventana por la derecha que reinice por al izquierda y viseversa
	if (snake[0].y > H) snake[0].y = 0; if (snake[0].y < 0) snake[0].y = H; //Para los limites del la ventana si sale de ventana por arriba que reinice por abajo y viseversa

	for (int i = 1; i < numero; i++) {
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) { juego = 1; numero = i; } // cuando se toca a si mismo el snake // pierde y obtiene los datos finales 
		
		if (eleccion_retrazo == 2) {
			if (snake[0].x == muro1.x && snake[0].y == muro1.y) { juego = 1; numero = i; } //Cuando el snake toca alguna parte de ladrillo - columna - pared
			if (snake[0].x == muro4.x && snake[0].y == muro4.y) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == muro2.y) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 1)) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 2)) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 3)) { juego = 1; numero = i; }
		}
		if (eleccion_retrazo == 3) {
			if (snake[0].x == muro1.x && snake[0].y == muro1.y) { juego = 1; numero = i; } //Cuando el snake toca alguna parte de ladrillo - columna - pared //Tope ladrio 1
			if (snake[0].x == muro4.x && snake[0].y == muro4.y) { juego = 1; numero = i; } //tope ladrillo 2
			if (snake[0].x == muro2.x && snake[0].y == muro2.y) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 1)) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 2)) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 3)) { juego = 1; numero = i; } //tope columna 1
			if (snake[0].x == muro5.x && snake[0].y == muro5.y) { juego = 1; numero = i; }
			if (snake[0].x == muro5.x && snake[0].y == (muro5.y + 1)) { juego = 1; numero = i; }
			if (snake[0].x == muro5.x && snake[0].y == (muro5.y + 2)) { juego = 1; numero = i; }
			if (snake[0].x == muro5.x && snake[0].y == (muro5.y + 3)) { juego = 1; numero = i; } //tope columna 2
			if (snake[0].x == muro3.x && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 1) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 2) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 3) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 4) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 5) && snake[0].y == muro3.y) { juego = 1; numero = i; } //Tope pared 1
		}
		if (eleccion_retrazo == 4) {
			if (snake[0].x == muro1.x && snake[0].y == muro1.y) { juego = 1; numero = i; } //Cuando el snake toca alguna parte de ladrillo - columna - pared //Tope ladrio 1
			if (snake[0].x == muro4.x && snake[0].y == muro4.y) { juego = 1; numero = i; } //tope ladrillo 2
			if (snake[0].x == muro2.x && snake[0].y == muro2.y) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 1)) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 2)) { juego = 1; numero = i; }
			if (snake[0].x == muro2.x && snake[0].y == (muro2.y + 3)) { juego = 1; numero = i; } //tope columna 1
			if (snake[0].x == muro5.x && snake[0].y == muro5.y) { juego = 1; numero = i; }
			if (snake[0].x == muro5.x && snake[0].y == (muro5.y + 1)) { juego = 1; numero = i; }
			if (snake[0].x == muro5.x && snake[0].y == (muro5.y + 2)) { juego = 1; numero = i; }
			if (snake[0].x == muro5.x && snake[0].y == (muro5.y + 3)) { juego = 1; numero = i; } //tope columna 2
			if (snake[0].x == muro3.x && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 1) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 2) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 3) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 4) && snake[0].y == muro3.y) { juego = 1; numero = i; }
			if (snake[0].x == (muro3.x + 5) && snake[0].y == muro3.y) { juego = 1; numero = i; } //Tope pared 1
		}
	}
	if (numero <= 0) { juego = 1; } //si los puntos llegan a 0 pierde
}
void MuroLadrillo() {
	muro1.x = rand() % A; 
	muro1.y = rand() % H; 
}
void MuroLadrilloUno() {
	muro4.x = rand() % A;
	muro4.y = rand() % H;
}
void MuroColumna() {
	muro2.x = rand() % A; 
	muro2.y = rand() % H; 
}
void MuroColumnaUno() {
	muro5.x = rand() % A;
	muro5.y = rand() % H;
}
void MuroPared() {
	muro3.x = rand() % A; 
	muro3.y = rand() % H; 
}

int main()
{
	srand(time(0));
	Font fuente; //Aqui se agrega un tipo de funte para las letras 
	fuente.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Letras/Drops.ttf"); //ubicacion de el tipo de fuente
	Text text; //Para manipular la fuente cargada y agregar texto
	text.setFont(fuente); // Se seleciona una fuente o tipo de letra 
	text.setCharacterSize(40); //Establece el tamano del caracter //en pixels, no en puntos

	RenderWindow ventana(VideoMode(w, h), "Proyecto SNAKE");  //se incicia ventana grafica 
	Texture t1, t2, t3,t4,t5,t6,t7,t8;
	t1.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/cesped.png"); //ubicacion de la imagen de cesped
	t2.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/snake.png"); //ubicacion de la imagen de snake
	t3.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/manzana.png"); //ubicacion de la imagen de la fruta
	t4.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/banana.png"); //ubicacion de la imagen de la fruta
	t5.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/fresa.png"); //ubicacion de la imagen de la fruta
	t6.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/pera.png"); //ubicacion de la imagen de la fruta
	t7.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/pina.png"); //ubicacion de la imagen de la fruta
	t8.loadFromFile("C:/Users/huvic/Desktop/Proyecto 2 Snake/Snake SFML verificado 36/Imagenes/pared.png"); //ubicacion de la imagen de pared
	Sprite sprite1(t1); //cesped//el sprite hace manipulable la imagen cargada 
	Sprite sprite2(t2); //snake
	Sprite sprite3(t3); //manzana
 	Sprite sprite4(t4); //banana
	Sprite sprite5(t5); //fresa
	Sprite sprite6(t6); //pera 
	Sprite sprite7(t7); //pina
	Sprite sprite8(t8); //pared

	Clock clock;
	Clock clock1;
	Time cambio_velocidad;
	
	//Velocidad del snake
	double temporizador = 0, retrazo = 0.3;
	//ubicacion de la primer fruta 
	fruta.x = 15;
	fruta.y = 10;
	
	//Inicializamoms clase menu *********************************CLASE**************
	Menu eleccion = Menu(w, h, "Proyecto SNAKE");
	eleccion_retrazo = eleccion.ObtenerRetrazo(0);
	if (eleccion_retrazo == 1) { retrazo = 0.3; } // facil
	if (eleccion_retrazo == 2) { retrazo = 0.07; MuroLadrillo(); MuroLadrilloUno(); MuroColumna(); } //normal
	if (eleccion_retrazo == 3) { retrazo = 0.03; MuroLadrillo(); MuroLadrilloUno(); MuroColumna(); MuroColumnaUno(); MuroPared(); } //dificil
	if (eleccion_retrazo == 4 && cambio_velocidad.asSeconds() > 10) { retrazo += 0.01; }
	if (eleccion_retrazo == 4) { MuroLadrillo(); MuroLadrilloUno(); MuroColumna(); MuroColumnaUno(); MuroPared(); }

	while (ventana.isOpen())   //Se inicia el modo grafico en una ventana  
	{
		float time = clock.getElapsedTime().asSeconds(); //se incia el conteo en segundos 
		clock.restart(); //se reinicia el reloj
		temporizador += time; // se le suma a la variable time cada vez que se reinicia el reloj 

		//Velocidad Progresiva
		cambio_velocidad = clock1.getElapsedTime();
		if (eleccion_retrazo == 4 && cambio_velocidad.asSeconds() > 10 && retrazo > 0.03) { // sirbe para el aumento de velocidad en la opciion PROGRESIBA 
			retrazo -= 0.04;
			clock1.restart();
		}
		cout << cambio_velocidad.asSeconds() << endl; //conteo del reloj en consola 

		//Acciones de las teclas o el mouse
		Event e;
		while (ventana.pollEvent(e))
		{
			if (e.type == Event::Closed)
				ventana.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) direccion = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) direccion = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up)) direccion = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) direccion = 0;
		if (temporizador > retrazo) { temporizador = 0; Mover(); } //En cada 0.02 segundos los valores de todo el snake y el alimento se obtienen 
																   
		//Dibujando en pantalla o lo que se estara mostrando 
		ventana.clear();

		for (int i = 0; i < A; i++)
			for (int j = 0; j < H; j++)
			{
				sprite1.setPosition(float(i * tamano), float(j * tamano)); ventana.draw(sprite1);
			} //se llena con la imagen de cesped toda la pantalla

		for (int i = 0; i < numero; i++)
		{
			sprite2.setPosition(float(snake[i].x * tamano), float(snake[i].y * tamano)); ventana.draw(sprite2);
		}//se inserta la imagen del snake

		//Codigo de la fruta sea aleatoria 
		//utilice un do while para que ingrese una unica vez y cuando cumpla la condicion rompa el ciclo y no dibuje cada una de las frutas y asi cada vez que ingrese
		do {
			if (fruta_aleatoria == 0) { sprite3.setPosition(float(fruta.x * tamano), float(fruta.y * tamano)); ventana.draw(sprite3); } //se crea la fruta manzana
			if (fruta_aleatoria == 1) { sprite4.setPosition(float(fruta.x * tamano), float(fruta.y * tamano)); ventana.draw(sprite4); } //se crea la fruta banana
			if (fruta_aleatoria == 2) { sprite5.setPosition(float(fruta.x * tamano), float(fruta.y * tamano)); ventana.draw(sprite5); } //se crea la fruta fresa
			if (fruta_aleatoria == 3) { sprite6.setPosition(float(fruta.x * tamano), float(fruta.y * tamano)); ventana.draw(sprite6); } //se crea la fruta pera 
			if (fruta_aleatoria == 4) { sprite7.setPosition(float(fruta.x * tamano), float(fruta.y * tamano)); ventana.draw(sprite7); } //se crea la fruta pina
		} while ((snake[0].x == fruta.x) && (snake[0].y == fruta.y)); // cuando imagen del snake toque la imagen de la fruta rompe el ciclo y reinicia

		if (eleccion_retrazo == 2) {
			sprite8.setPosition(float(muro1.x * tamano), float(muro1.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro4.x * tamano), float(muro4.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float(muro2.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 1) * tamano)); ventana.draw(sprite8); /// Para agregar un bloque mas sobre la vertica solo sumar 1 en y columna
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 2) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 3) * tamano)); ventana.draw(sprite8);
		}
		if (eleccion_retrazo == 3) {
			sprite8.setPosition(float(muro1.x * tamano), float(muro1.y * tamano)); ventana.draw(sprite8); // ladrillo 1
			sprite8.setPosition(float(muro4.x * tamano), float(muro4.y * tamano)); ventana.draw(sprite8); // ladrillo 2
			sprite8.setPosition(float(muro2.x * tamano), float(muro2.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 1) * tamano)); ventana.draw(sprite8); 
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 2) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 3) * tamano)); ventana.draw(sprite8); //columna 1
			sprite8.setPosition(float(muro5.x * tamano), float(muro5.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro5.x * tamano), float((muro5.y + 1) * tamano)); ventana.draw(sprite8); 
			sprite8.setPosition(float(muro5.x * tamano), float((muro5.y + 2) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro5.x * tamano), float((muro5.y + 3) * tamano)); ventana.draw(sprite8); //columna 2
			sprite8.setPosition(float(muro3.x * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 1) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 2) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 3) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 4) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 5) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8); //Pared 1
		}
		if (eleccion_retrazo == 4) {
			sprite8.setPosition(float(muro1.x * tamano), float(muro1.y * tamano)); ventana.draw(sprite8); // ladrillo 1
			sprite8.setPosition(float(muro4.x * tamano), float(muro4.y * tamano)); ventana.draw(sprite8); // ladrillo 2
			sprite8.setPosition(float(muro2.x * tamano), float(muro2.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 1) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 2) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro2.x * tamano), float((muro2.y + 3) * tamano)); ventana.draw(sprite8); //columna 1
			sprite8.setPosition(float(muro5.x * tamano), float(muro5.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro5.x * tamano), float((muro5.y + 1) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro5.x * tamano), float((muro5.y + 2) * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float(muro5.x * tamano), float((muro5.y + 3) * tamano)); ventana.draw(sprite8); //columna 2
			sprite8.setPosition(float(muro3.x * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 1) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 2) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 3) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 4) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8);
			sprite8.setPosition(float((muro3.x + 5) * tamano), float(muro3.y * tamano)); ventana.draw(sprite8); //Pared 1
		}

		text.setString("PUNTOS " + to_string(numero)); //para agregar cadena de texto en pantalla
		text.setPosition(250, 20); //Para establecer pocicion del texto
		Color color1(255, 255, 255, 150); //Se crea un color con opacidad o trnasparencia 
		text.setFillColor(color1);
		ventana.draw(text); //para dibujar en pantalla el texto

		if (juego) { // juego=1 ==> Juego terminado
			cout << "->->->->-> Fin Del Juego <-<-<-<-<- \n Tu Puntuacion Es  -> " << puntos << "\n";
			system("pause");
			ventana.close();
		}

		ventana.display();  // mostrara la imagen congelada al perder la partida 
	}
	return 0;
}

