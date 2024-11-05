#ifndef DREAMCATCHER_CHARACTERSMANAGER_H
#define DREAMCATCHER_CHARACTERSMANAGER_H

#include <unordered_map>
#include "Character.h"
#include "Factory/CharacterCreator.h"
#include "Factory/EnemyCreator.h"

class CharactersManager {
public:
    CharactersManager();
    std::shared_ptr<Character> character(uint8_t id) { return m_characters.at(id); }
private:
    void addCharacter(std::shared_ptr<Character> character) { m_characters[character->id()] = character; }
    std::unordered_map<uint8_t, std::shared_ptr<Character>> m_characters;

    CharacterCreator m_characterCreator;
    EnemyCreator m_enemyCreator;
};


#endif //DREAMCATCHER_CHARACTERSMANAGER_H
