#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

void PokemonListReader::getWeakness(float* pokeWeakness, std::string pokeType, std::string pokeType2) {
    float weakness1[18];
    float weakness2[18];

    auto it = weaknessList.find(pokeType);
    auto it2 = weaknessList.find(pokeType2);

    if (it != weaknessList.end() && (it2 != weaknessList.end() || pokeType2 == "None")) {
        memcpy(weakness1, it->second.weakness, sizeof(it->second.weakness));
        if (pokeType2 == "None") {
            for (int i = 0; i < 18; i++) {
                weakness2[i] = 1;
            }
        }
        else {
            memcpy(weakness2, it2->second.weakness, sizeof(it2->second.weakness));
        }
    }

    for (int i = 0; i < 18; i++) {
        pokeWeakness[i] = weakness1[i] * weakness2[i];
    }

}

void PokemonListReader::populateWeaknessList() {
    std::ifstream weakness("pokemon_weakness.csv");
    std::string type;
    float weaknesses[18];

    //skip the first line
    std::getline(weakness, type);

    while (weakness.good()) {
        string weakString;
        std::getline(weakness, weakString);
        stringstream weakStream(weakString);

        //Get the type
        getline(weakStream, type, ',');
        string weaknessNumber;
        for (int i = 0; i < 18; i++) {
            std::getline(weakStream, weaknessNumber, ',');
            weaknesses[i] = std::stof(weaknessNumber);
        }

        //Add the typing into the weakness map
        PokemonWeakness pokemonWeakness;
        memcpy(pokemonWeakness.weakness, weaknesses, sizeof weaknesses);
        weaknessList.insert(pair<string, PokemonWeakness>(type, pokemonWeakness));
    }
    
    return;
}