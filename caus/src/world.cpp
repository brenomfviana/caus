/*
  This file is part of CAUS.

  Copyright (c) 2019 by Breno Viana

  CAUS is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "world.hpp"

World::World(const size_t width_, const size_t height_) :
  width(width_), height(height_) {
    // Create world
    this->world = new bool *[this->height];
    for (size_t i = 0; i < this->height; i++) {
      this->world[i] = new bool[this->width];
      for (size_t j = 0; j < this->width; j++) {
        this->world[i][j] = false;
      }
    }
  }

World::World(const World& world_) {
  this->width = world_.width;
  this->height = world_.height;
  this->world = new bool *[this->height];
  for (size_t i = 0; i < this->height; i++) {
    this->world[i] = new bool[this->width];
    for (size_t j = 0; j < this->width; j++) {
      this->world[i][j] = world_.world[i][j];
    }
  }
}

World::~World() {
  for (size_t i = 0; i < this->height; i++) {
    delete [] this->world[i];
  }
  delete [] this->world;
}

const size_t World::get_width() const {
  return this->width;
}

const size_t World::get_height() const {
  return this->height;
}

const bool World::is_alive(const size_t i_, const size_t j_) const {
  return this->world[i_][j_];
}

void World::set_alive(const size_t i_, const size_t j_) {
  this->world[i_][j_] = true;
}

void World::set_dead(const size_t i_, const size_t j_) {
  this->world[i_][j_] = false;
}


#include <iostream>
const size_t World::get_no_neighbors(const size_t i_, const size_t j_) const {
  size_t counter = 0;
  std::vector<int> dirs({ -1, 0, 1 });
  for (int i : dirs) {
    for (int j : dirs) {
      // Check if it is not the cell itself
      if ((i == 0 && j != 0) || (i != 0 && j == 0) || (i != 0 && j != 0)) {
        // Check if is not the same cell and matrix boundaries
        if (((int) i_ + i) >= 0 && ((int) j_ + j) >= 0 &&
          ((int) i_ + i) < this->height && ((int) j_ + j) < this->width) {
            if (this->world[i_ + i][j_ + j]) {
              counter++;
            }
        }
      }
    }
  }
  return counter;
}

const bool World::operator==(const World& world_) const {
  if (this->width != world_.width) {
    return false;
  }
  if (this->height != world_.height) {
    return false;
  }
  for (size_t i = 0; i < this->height; i++) {
    for (size_t j = 0; j < this->width; j++) {
      if (this->world[i][j] != world_.world[i][j]) {
        return false;
      }
    }
  }
  return true;
}

const bool World::operator!=(const World& world_) const {
  return !(*this == world_);
}
