
#include "../Headers/textDisplay.h"

textDisplay::textDisplay(const std::string &text, const std::string &font_path,
                         int size, float lifetime) {
    this->startTime = static_cast<float>(clock());
    this->isExist = true;
    this->font.loadFromFile("../Resources/" + font_path + ".ttf");

    this->lifetime = lifetime;
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setCharacterSize(size);
}

textDisplay::~textDisplay()
= default;

void textDisplay::render(sf::RenderTarget *target) {
    target->draw(this->text);
}
