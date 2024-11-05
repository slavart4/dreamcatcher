#include "CharacterCreator.h"
#include "../Characters/MainCharacter.h"

std::shared_ptr<Character> CharacterCreator::createCharacter(nlohmann::json character) {
    uint8_t id = character["id"];
    std::string name = character["name"];
    std::string picture = character["picture"];
    uint8_t hp = character["stats"]["hp"];
    uint8_t attack = character["stats"]["attack"];
    uint8_t agility = character["stats"]["agility"];

    return std::make_shared<MainCharacter>(id, name, picture, hp, attack, agility);
}
