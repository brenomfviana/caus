/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef _CASTOR_UTILS_HPP_
#define _CASTOR_UTILS_HPP_

#include <fstream>
#include <iostream>

namespace utils {
  /*!
   * \brief Read world population
   *
   * \param width
   *     World width
   * \param height
   *     World height
   * \param ppath
   *     Path file of world population
   */
  bool** read_population(const size_t width, const size_t height,
    const char key, const std::string ppath) {
      // Create world
      bool** world = new bool *[height];
      for (size_t i = 0; i < height; i++) {
        world[i] = new bool[width];
      }
      for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
          world[i][j] = false;
        }
      }
      // Read file
      std::string line;
      std::ifstream population;
      population.open(ppath);
      if (population.is_open()) {
        size_t i = 0, j = 0;
        while (getline(population, line)) {
          for(char& c : line) {
            if (c == key) {
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

#endif /* _CASTOR_UTILS_HPP_ */
