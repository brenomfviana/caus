/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "printer.hpp"

void printer::print(World* world_) {
  for (size_t i = 0; i < world_->get_height(); i++) {
    for (size_t j = 0; j < world_->get_width(); j++) {
      if (world_->is_alive(i, j)) {
        std::cout << "*";
      } else {
        std::cout << ".";
      }
    }
    std::cout << "\n";
  }
}
