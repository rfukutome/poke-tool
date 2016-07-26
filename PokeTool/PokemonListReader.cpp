#include <iostream>
#include <fstream>
#include <string>

#include "PokemonListReader.h"


using namespace std;


PokemonListReader::PokemonListReader()
{
    pokeList.clear();
    numberPokeList.clear();
    weaknessList.clear();
    populateWeaknessList();
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

void PokemonListReader::getWeakness(int* pokeWeakness, std::string pokeType, std::string pokeType2) {
    
}

void PokemonListReader::populateWeaknessList() {
//                             NOR FIR WAT ELE GRA ICE FGT POI GND FLY PSY BUG RCK GST DRA DRK STL FRY        
    PokemonWeakness normal = {  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1};
    PokemonWeakness fire =   {  1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness water = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness electric = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness grass = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness ice = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness fighting = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness poison = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness ground = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness flying = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness psychic = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness bug = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness rock = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness ghost = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness dragon = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness dark = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness steel = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
    PokemonWeakness fairy = { 1, .5,  2,  1, .5,  1,  2,  1,  2,  1,  1, .5,  2,  0,  1,  1,  1,  1 };
}