#include "CharactersManager.h"

CharactersManager* CharactersManager::chars_singleton_= nullptr;

CharactersManager *CharactersManager::GetInstance() {
    if(chars_singleton_==nullptr){
        chars_singleton_ = new CharactersManager();
    }
    return chars_singleton_;
}

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

AttackResult CharactersManager::attack(uint8_t defender) {
    return m_fightManager.attack(m_mainCharacter, m_characters[defender]);
}