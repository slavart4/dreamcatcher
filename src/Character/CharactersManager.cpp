#include "CharactersManager.h"
#include "Factory/CharacterCreator.h"
#include "Factory/EnemyCreator.h"

CharactersManager::CharactersManager() {
    DataIO dataIo("../assets/settings/characters.json");
    nlohmann::json data = dataIo.read()["characters"];

    for(auto& character : data) {
        if(character["type"] == "main") {
            addCharacter(m_characterCreator.createCharacter(character));
        }
        if(character["type"] == "enemy") {
            addCharacter(m_enemyCreator.createCharacter(character));
        }
    }
}