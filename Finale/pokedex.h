#ifndef POKEDEX_H
#define POKEDEX_H

class Pokedex{
	public:
		//Constructor
		Pokedex();
		
		//Destructor
		~Pokedex();
		
		//Accessor Functions
		int login(int, int);	//The two int values are x and y coordinates for freedom of placement of the login box.
};

#endif
