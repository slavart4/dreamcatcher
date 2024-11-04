#include "Director.h"

void Director::constructMenuScene(Builder &builder, nlohmann::json& data) {
    builder.setId(data);
    builder.setType(data);
    builder.setOptions(data);
    builder.setOptionsButtons(data);
    builder.setText(data);
    builder.createScene();
    builder.setPictures(data);
}
