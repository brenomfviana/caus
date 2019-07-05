/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_UTILS_HPP__
#define __CASTOR_UTILS_HPP__

#include <fstream>

namespace utils {
  /*!
   * Read world population
   *
   * \param width_
   *     World width
   * \param height_
   *     World height
   * \param key_
   *     Cell key
   * \param ppath_
   *     Path file of world population
   */
  bool** read_population(const size_t width_, const size_t height_,
    const char key_, const std::string ppath_) {
      // Create world
      bool** world = new bool *[height_];
      for (size_t i = 0; i < height_; i++) {
        world[i] = new bool[width_];
      }
      for (size_t i = 0; i < height_; i++) {
        for (size_t j = 0; j < width_; j++) {
          world[i][j] = false;
        }
      }
      // Read file
      std::string line;
      std::ifstream population;
      population.open(ppath_);
      if (population.is_open()) {
        size_t i = 0, j = 0;
        while (getline(population, line)) {
          for(char& c : line) {
            if (c == key_) {
              world[i][j] = true;
            }
            j++;
          }
          j = 0;
          i++;
        }
        population.close();
      }
      return world;
  }
}

#endif /* __CASTOR_UTILS_HPP__ */
