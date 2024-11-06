#ifndef DREAMCATCHER_CHARACTERSMANAGER_H
#define DREAMCATCHER_CHARACTERSMANAGER_H

#include <unordered_map>
#include "Character.h"
#include "Factory/CharacterCreator.h"
#include "Factory/EnemyCreator.h"
#include "FightManager.h"

class CharactersManager {
public:
    static CharactersManager *GetInstance();

    std::shared_ptr<Character> character(uint8_t id) { return m_characters.at(id); }
    std::shared_ptr<Character> mainCharacter() { return m_mainCharacter; }

    void setMainCharacter(uint8_t id) { m_mainCharacter = m_characters.at(id); }
    AttackResult attack(uint8_t defender);
private:
    void addCharacter(const std::shared_ptr<Character>& character) { m_characters[character->id()] = character; }

    std::unordered_map<uint8_t, std::shared_ptr<Character>> m_characters;
    std::shared_ptr<Character> m_mainCharacter;

    CharacterCreator m_characterCreator;
    EnemyCreator     m_enemyCreator;
    FightManager     m_fightManager;
// Singleton stuff
public:
    CharactersManager(CharactersManager &other) = delete;
    void operator=(const CharactersManager&) = delete;
private:
    CharactersManager();
    static CharactersManager* chars_singleton_;
};


#endif //DREAMCATCHER_CHARACTERSMANAGER_H
