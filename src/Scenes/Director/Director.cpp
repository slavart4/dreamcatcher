#include "Director.h"

void Director::constructScene(Builder &builder, nlohmann::json& data) {
    builder.setId(data);
    builder.setType(data);
    builder.setOptions(data);
    builder.setOptionsButtons(data);
    builder.setTitle(data);
    builder.setCharacters(data);
    builder.createScene();
    builder.setTexts(data);
    builder.setPictures(data);
}
