#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class textDisplay {
protected:
    // Variables
    float startTime;
    float lifetime;
public:
    // Variables
    sf::Font font;
    sf::Text text;
    bool isExist;

    // Functions
    textDisplay(const std::string &text, const std::string &font_path, int size,
                float lifetime);

    virtual ~textDisplay();

    virtual void update() = 0;

    void render(sf::RenderTarget *target);
};

#endif //TEXT_H
