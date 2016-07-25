#pragma once

#include <map>
#include <iostream>
#include <string>

//Making data as struct for future expansion
struct PokemonData {
    std::string basicAttributes[4];
};

enum Attributes {
    POKEMON_NUMBER, //0
    POKEMON_NAME,
    POKEMON_TYPE1,
    POKEMON_TYPE2
};

class PokemonListReader
{
private:    
    std::map<std::string, PokemonData> pokeList;
    std::map<std::string, PokemonData> numberPokeList;

public:
    PokemonListReader();
    PokemonData findPokemonByName(std::string argPokemonName);
    PokemonData findPokemonByNumber(std::string argPokemonNumber);
    void addPokemonData(std::string argNumber, std::string argName, std::string argType, std::string argType2);
};

