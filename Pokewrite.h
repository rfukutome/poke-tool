#include "mainwindow.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Pokewrite
{

public:
	Pokewrite();
	~Pokewrite();

	//This function will create and save a pokemon to a file
	void createPokemon();

	void pokeBeginning();

	//This function will call a pokemon from a saved file.
	void callPokemon(int id);

	//Overloading the function to accept multiple types.
	void callPokemon(string id);

	//Function will find a type and output it's weaknesses
	void findType(string type, double* ptr);

    void fillList();
private:
	string pokeID;
	int option;
	int indicator;
};

