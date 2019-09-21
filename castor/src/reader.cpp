/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "reader.hpp"

void reader::read(std::shared_ptr<World> world, const char key_,
  const std::string path_) {
    // Auxiliary variables
    std::string line;
    std::ifstream file;
    // Read file
    file.open(path_);
    if (file.is_open()) {
      size_t i = 0;
      size_t j = 0;
      while (getline(file, line)) {
        // Check each char
        for(char& c : line) {
          // If the char is equal to the key, so the cell is alive
          if (c == key_) {
            world->set_alive(i, j);
          }
          // Next char
          j++;
        }
        // Next line
        j = 0;
        i++;
      }
      file.close();
    }
  }
