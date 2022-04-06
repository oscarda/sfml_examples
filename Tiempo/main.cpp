#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


int main(int argc, char *argv[]){

	Clock cuenta_atras;
	Time tiempo_pasado;
	int segundos = 0;
	while(true) {

		tiempo_pasado = cuenta_atras.getElapsedTime();
		segundos = tiempo_pasado.asSeconds();
		cout << segundos/60 << ":" <<segundos%60 <<endl; 
	}
	return 0;
}

