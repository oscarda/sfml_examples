#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


int main(int argc, char *argv[]){
	int ancho_pantalla=200;
	RenderWindow w(VideoMode(200,ancho_pantalla),"Ejemplo de SFML");
	Texture t;
	Sprite s1, s2;
	float x=0, velocidad=.03;
	int ancho_imagen;
	
	t.loadFromFile("sfml.png");
	s1.setTexture(t);
	s2.setTexture(t);
	s1.setPosition(0, 0);
	ancho_imagen = s1.getGlobalBounds().width;
	cout << ancho_imagen<< endl;
	
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		//Actualizar posición
		x+=velocidad;
		if(x> ancho_pantalla)
		{
			x=ancho_pantalla-ancho_imagen;
		}
		s1.setPosition(x, 0);
		
		//Redibujar pantalla
		w.clear(Color(255,255,255,255));
		w.draw(s1);
		
		if (x>0)
		{
			s2.setPosition(x-ancho_imagen,0);
			w.draw(s2);			
		};
		
		w.display();
	}
	return 0;
}

