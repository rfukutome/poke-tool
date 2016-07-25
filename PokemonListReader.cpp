#include <iostream>
#include <fstream>
#include <string>

#include "PokemonListReader.h"


using namespace std;


PokemonListReader::PokemonListReader()
{
    pokeList.clear();
    numberPokeList.clear();
}

void PokemonListReader::addPokemonData(std::string argNumber, std::string argName, std::string argType, std::string argType2) 
{
    PokemonData pokemonData = { argNumber, argName, argType, argType2 };
    pokeList.insert(pair<string, PokemonData>(argName, pokemonData));
    numberPokeList.insert(pair<string, PokemonData>(argNumber, pokemonData));
}

PokemonData PokemonListReader::findPokemonByName(std::string argPokemonName) 
{
    auto it = pokeList.find(argPokemonName);
    if (it != pokeList.end()) {
        return (it->second);
    }

}

PokemonData PokemonListReader::findPokemonByNumber(std::string argPokemonNumber) {
    auto it = numberPokeList.find(argPokemonNumber);
    if (it != numberPokeList.end()) {
        return (it->second);
    }
}