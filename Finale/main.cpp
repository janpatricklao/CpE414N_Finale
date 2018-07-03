#include <iostream>
#include "gotoxy.h"
#include "pokedex.h"

using namespace std;

int main(int argc, char** argv) {
	Pokedex pokedex;
	gotoxy(41,0);	cout<<"Pokedex v0.0.1";
	pokedex.login(32,2);
	return 0;
}
