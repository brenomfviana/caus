/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "world.hpp"

World::World(size_t width, size_t height) {
  this->width = width;
  this->height = height;
  this->world = new bool *[this->height];
  for (size_t i = 0; i < this->height; i++) {
    this->world[i] = new bool[this->width];
  }
  for (size_t i = 0; i < this->height; i++) {
    for (size_t j = 0; j < this->width; j++) {
      this->world[i][j] = false;
    }
  }
}

World::~World() {
  for (size_t i = 0; i < this->height; i++) {
    delete [] this->world[i];
  }
  delete [] this->world;
}

size_t World::get_width() {
  return this->width;
}

size_t World::get_height() {
  return this->height;
}

void World::set_alive(size_t i, size_t j) {
  this->world[i][j] = true;
}

void World::set_dead(size_t i, size_t j) {
  this->world[i][j] = false;
}
