/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "world.hpp"

World::World(const size_t width_, const size_t height_, bool** w_) {
  this->width = width_;
  this->height = height_;
  this->world = new bool *[this->height];
  for (size_t i = 0; i < this->height; i++) {
    this->world[i] = new bool[this->width];
  }
  // Set the population
  for (size_t i = 0; i < this->height; i++) {
    for (size_t j = 0; j < this->width; j++) {
      this->world[i][j] = w_[i][j];
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

bool World::is_alive(const size_t i_, const size_t j_) {
  return this->world[i_][j_];
}

void World::set_alive(const size_t i_, const size_t j_) {
  this->world[i_][j_] = true;
}

void World::set_dead(const size_t i_, const size_t j_) {
  this->world[i_][j_] = false;
}
