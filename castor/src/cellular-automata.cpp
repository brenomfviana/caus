/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "cellular-automata.hpp"

CellularAutomata::CellularAutomata(std::string rules_) {
  // Get rules
  std::stringstream ss(rules_);
  std::string token;
  std::vector<std::string> rs;
  while (std::getline(ss, token, '/')) {
    rs.push_back(token);
  }
  // Set rules
  std::string a = rs[0].substr(1);
  for(char& c : a) {
    this->br.push_back((size_t) (c - 48));
  }
  a = rs[1].substr(1);
  for(char& c : a) {
    this->sr.push_back((size_t) (c - 48));
  }
}

void CellularAutomata::apply_ca(World* world_) {
  for (size_t i = 0; i < world_->get_width(); i++) {
    for (size_t j = 0; j < world_->get_height(); j++) {
      // Check if the cell is alive
      if (world_->is_alive(i, j)) {
        size_t nn = world_->get_no_neighbours(i, j);
        bool kill = true;
        for (size_t n : sr) { if (n == nn) { kill = false; } }
        if (kill) { world_->set_dead(i, j); }
      } else {
        size_t nn = world_->get_no_neighbours(i, j);
        for (size_t n : br) { if (n == nn) { world_->set_alive(i, j); } }
      }
    }
  }
}
