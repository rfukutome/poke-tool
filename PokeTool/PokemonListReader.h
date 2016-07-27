#pragma once

#include <map>
#include <iostream>
#include <string>

//Making data as struct for future expansion
struct PokemonData {
    std::string basicAttributes[4];
};

struct PokemonWeakness {
    float weakness[18];
};
enum Attributes {
    POKEMON_NUMBER, //0
    POKEMON_NAME,
    POKEMON_TYPE1,
    POKEMON_TYPE2
};

enum Typing {
    NORMAL,   //0
    FIRE,     //1
    WATER,    //2
    ELECTRIC, //3
    GRASS,    //4
    ICE,      //5
    FIGHTING, //6
    POISON,   //7
    GROUND,   //8
    FLYING,   //9
    PSYCHIC,  //10
    BUG,      //11
    ROCK,     //12
    GHOST,    //13
    DRAGON,   //14
    DARK,     //15
    STEEL,    //16
    FAIRY     //17
};

class PokemonListReader
{
private:
    std::map<std::string, PokemonData> pokeList;
    std::map<std::string, PokemonData> numberPokeList;
    std::map<std::string, PokemonWeakness> weaknessList;

    void populateWeaknessList();

public:
    PokemonListReader();
    PokemonData findPokemonByName(std::string argPokemonName);
    PokemonData findPokemonByNumber(std::string argPokemonNumber);
    void getWeakness(float* pokeWeakness, std::string pokeType, std::string pokeType2);
    void addPokemonData(std::string argNumber, std::string argName, std::string argType, std::string argType2);
};

