#include "Pokewrite.h"
#include <string>
#include <iostream>
#include <fstream>
#include <mainwindow.h>

using namespace std;

Pokewrite::Pokewrite()
{
}

Pokewrite::~Pokewrite()
{
}

void Pokewrite::fillList(){

}

void Pokewrite::pokeBeginning(){
	cout << "Please specify what you would like to do: " << endl;
	cout << "1: Add pokemon" << endl;
	cout << "2: Search pokemon" << endl;
	cout << "3: Quit" << endl;
	cin >> option;

	switch (option){
	case 1:
		createPokemon();
		break;
	case 2:
		do{
			cout << "\nSearch a pokemon (type quit to return to menu)?" << endl;
			cin >> pokeID;
			callPokemon(pokeID);
		} while (pokeID != "quit");
		pokeID = "null";
		option = 0;
		pokeBeginning();
	case 3:
		break;
	}
}

void Pokewrite::createPokemon()
{
	ofstream pokemon("pokemon.txt", ofstream::app);
	int number;
	string name;
	string type;
	string type2;
	if (pokemon.is_open()){
		while (cin >> number >> name >> type >> type2){
			pokemon << number << ' ' << name << ' ' << type << ' ' << type2 << endl;
			cout << "Press Ctrl + Z to quit adding pokemon." << endl;
		}
	}
}

void Pokewrite::callPokemon(int id)
{
	//ifstream pokemon("pokemon.txt");
	//int number;
	//string name;
	//string type;
	//string type2;
	//double weak[18];
	//double weak2[18];
	//while (pokemon >> number >> name >> type >> type2)
	//	if (id == number){
	//		cout << " | " << number << " | " << name << " | " << type << " | " << type2 << endl;
	//		findType(type, weak);
	//		findType(type2, weak2);
	//		double weakness[18] = { weak[0] * weak2[0], weak[1] * weak2[1], weak[2] * weak2[2], weak[3] * weak2[3], weak[4] * weak2[4], weak[5] * weak2[5], weak[6] * weak2[6], weak[7] * weak2[7], weak[8] * weak2[8], weak[9] * weak2[9], weak[10] * weak2[10], weak[11] * weak2[11], weak[12] * weak2[12], weak[13] * weak2[13], weak[14] * weak2[14], weak[15] * weak2[15], weak[16] * weak2[16], weak[17] * weak2[17] };

	//		cout << "Weakness:"<< " | Normal x" << weakness[0] << " | " << " | Fighting x" << weakness[1] << " | " << " | Flying x" << weakness[2] << " | " << " | Poison x" << weakness[3] << " | " << " | Ground x" << weakness[4] << " | " << " | Rock x" << weakness[5] << " | " << endl;
	//		cout << " | Bug x" << weakness[6] << " | " << " | Ghost x" << weakness[7] << " | " << " | Steel x" << weakness[8] << " | " << " | Fire x" << weakness[9] << " | " << " | Water x" << weakness[10] << " | " << " | Grass x" << weakness[11] << " | " << endl;
	//		cout << " | Electric x" << weakness[12] << " | " << " | Psychic x" << weakness[13] << " | " << " | Ice x" << weakness[14] << " | " << " | Dragon x" << weakness[15] << " | " << " | Dark x" << weakness[16] << " | " << " | Fairy x" << weakness[17] << " | " << endl;
	//		break;
	//	}
}

void Pokewrite::callPokemon(string id)
{
	ifstream pokemon("pokemon.txt");
	int number;
	string name;
	string type;
	string type2;
	double weak[18];
	double weak2[18];
	while (pokemon >> number >> name >> type >> type2)
		if (id == name){
			cout << " | " << number << " | " << name << " | " << type << " | " << type2 << endl;
			findType(type, weak);
			findType(type2, weak2);
			double weakness[18] = { weak[0] * weak2[0], weak[1] * weak2[1], weak[2] * weak2[2], weak[3] * weak2[3], weak[4] * weak2[4], weak[5] * weak2[5], weak[6] * weak2[6], weak[7] * weak2[7], weak[8] * weak2[8], weak[9] * weak2[9], weak[10] * weak2[10], weak[11] * weak2[11], weak[12] * weak2[12], weak[13] * weak2[13], weak[14] * weak2[14], weak[15] * weak2[15], weak[16] * weak2[16], weak[17] * weak2[17] };
		
			cout << "Weakness:\n" << " | Normal x" << weakness[0] << " | " << " | Fighting x" << weakness[1] << " | " << " | Flying x" << weakness[2] << " | " << " | Poison x" << weakness[3] << " | " << " | Ground x" << weakness[4] << " | " << " | Rock x" << weakness[5] << " | " << endl;
			cout << " | Bug x" << weakness[6] << " | " << " | Ghost x" << weakness[7] << " | " << " | Steel x" << weakness[8] << " | " << " | Fire x" << weakness[9] << " | " << " | Water x" << weakness[10] << " | " << " | Grass x" << weakness[11] << " | " << endl;
			cout << " | Electric x" << weakness[12] << " | " << " | Psychic x" << weakness[13] << " | " << " | Ice x" << weakness[14] << " | " << " | Dragon x" << weakness[15] << " | " << " | Dark x" << weakness[16] << " | " << " | Fairy x" << weakness[17] << " | " << endl;

			break;
		}
}

void Pokewrite::findType(string type, double* ptr){
	
	if (type == "Normal"){
		double weakness[18] = { 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Fighting"){
		double weakness[18] = {1, 1, 2, 1, 1, .5, .5, 1, 1, 1, 1, 1, 1, 2, 1, 1, .5, 2};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Flying"){
		double weakness[18] = {1, .5, 1, 1, 0, 2, .5, 1, 1, 1, 1, .5, 2, 1, 2, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Poison"){
		double weakness[18] = {1, .5, 1, .5, 2, 1, .5, 1, 1 ,1, 1, .5, 1, 2, 1, 1, 1, .5};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Ground"){
		double weakness[18] = {1, 1, 1, .5, 1, .5, 1, 1, 1, 1, 2, 2, 0, 1, 2, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Rock"){
		double weakness[18] = {.5, 2, .5, .5, 2, 1, 1, 1, 2, .5, 2, 2, 1, 1, 1, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Bug"){
		double weakness[18] = {1, .5, 2, 1, .5, 2, 1, 1, 1, 2, 1, .5, 1, 1, 1, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Ghost"){
		double weakness[18] = {0, 0, 1, .5, 1, 1, .5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Steel"){
		double weakness[18] = {.5, 2, .5, 0, 2, .5, .5, 1, .5, 2, 1, .5, 1, .5, .5, .5, 1, .5};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Fire"){
		double weakness[18] = {1, 1, 1, 1, 2, 2, .5, 1, .5, .5, 2, .5, 1, 1, .5, 1, 1, .5};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Water"){
		double weakness[18] = {1, 1, 1, 1, 1, 1, 1, 1, .5, .5, .5, 2, 2, 1, .5, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Grass"){
		double weakness[18] = {1, 1, 2, 2, .5, 1, 2, 1, 1, 2, .5, .5, .5, 1, 2, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Electric"){
		double weakness[18] = {1, 1, .5, 1, 2, 1, 1, 1, .5, 1, 1, 1, .5, 1, 1, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Psychic"){
		double weakness[18] = {1, .5, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, .5, 1, 1, 2, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Ice"){
		double weakness[18] = {1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, .5, 1, 1, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Dragon"){
		double weakness[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, .5, .5, .5, .5, 1, 2, 2, 1, 2};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Dark"){
		double weakness[18] = {1, 2, 1, 1, 1, 1, 2, .5, 1, 1, 1, 1, 1, 0, 1, 1, .5, 2};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else if (type == "Fairy"){
		double weakness[18] = {1, .5, 1, 2, 1, 1, .5, 1, 2, 1, 1, 1, 1, 1, 1, 0, .5, 1};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
	else{
		int weakness[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for (int i = 0; i < 18; i++){
			ptr[i] = weakness[i];
		}
	}
}
