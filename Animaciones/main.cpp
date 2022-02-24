#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;


float animacion_rapida_suave(float p, float q, float t) {
	cout << "En animacion parab rap suave..." << p << " " << q << " " << t << endl;
	float dif = q-p;
	float r = -dif*t*t + 2*dif*t + p;
	return r; 
}
int main(int argc, char *argv[]){
	
	float xmax = 640, ymax=480;
	RenderWindow w(VideoMode(xmax,ymax),"Ejemplo de SFML");
	
	float radio = ymax/13;
	CircleShape c1(50);	
	c1.setFillColor(Color(100, 250, 50));
	
	float t=0;
	float origen1=0, destino1=xmax-2*radio;
	float posicion1, y1 = radio;
	
	float salto_tiempo = 0.001;
	float temp;
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		//Calculamos siguiente posicion de la figura
		posicion1 = animacion_rapida_suave(origen1, destino1, t);
		t += salto_tiempo;
		cout << fabs(destino1-origen1) <<endl;
		
		if(t>=1) {
			t=0;
			cout << "Rebote..." << endl;
			temp = origen1;
			origen1 = destino1;
			destino1 = temp;
			posicion1 = origen1;
		};
		//Posicionamos las figuras
		c1.setPosition(posicion1, y1);
		//Dibujamos todo
		w.clear(Color(255,255,255,255));
		w.draw(c1);
		w.display();
	}
	return 0;
}

