#ifndef TEXTDISPALY_H
#define TEXTDISPALY_H

#include "textDisplay.h"

class CollisionText : public textDisplay {
private:
  int transparency;

public:
  sf::Color color;

  CollisionText(std::string text, std::string font_path, int size,
                float lifetime);

  virtual ~CollisionText();

  void update();
};

#endif // TEXTDISPALY_H
