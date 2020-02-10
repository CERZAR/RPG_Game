// Copyright 2019 CERZAR
#include "../Headers/Object.h"

Object::Object(ResourcesContainer *res) { this->resContainter = res; }

Object::~Object() {}

void Object::render(sf::RenderTarget *target) { target->draw(this->sprite); }
