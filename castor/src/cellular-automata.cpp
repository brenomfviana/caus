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

const size_t** CellularAutomata::get_neighborhood(const World& world_) const {
  size_t** wn = new size_t *[world_.get_height()];
  for (size_t i = 0; i < world_.get_height(); i++) {
    wn[i] = new size_t[world_.get_width()];
  }
  // Get the number of neighbours of each cell
  for (size_t i = 0; i < world_.get_height(); i++) {
    for (size_t j = 0; j < world_.get_width(); j++) {
      wn[i][j] = world_.get_no_neighbours(i, j);
    }
  }
  return (const size_t**) wn;
}

void CellularAutomata::birth_rule(const size_t** wn_,
  std::shared_ptr<World> world_) const {
    for (size_t i = 0; i < world_->get_width(); i++) {
      for (size_t j = 0; j < world_->get_height(); j++) {
        // Check if the cell is not alive
        if (!world_->is_alive(i, j)) {
          size_t nn = wn_[i][j];
          for (size_t n : br) { if (n == nn) { world_->set_alive(i, j); } }
        }
      }
    }
  }

void CellularAutomata::death_rule(const size_t** wn_,
  std::shared_ptr<World> world_) const {
    for (size_t i = 0; i < world_->get_width(); i++) {
      for (size_t j = 0; j < world_->get_height(); j++) {
        // Check if the cell is alive
        if (world_->is_alive(i, j)) {
          size_t nn = wn_[i][j];
          bool die = true;
          for (size_t n : sr) { if (n == nn) { die = false; } }
          if (die) { world_->set_dead(i, j); }
        }
      }
    }
  }

void CellularAutomata::apply_ca(std::shared_ptr<World> world_) const {
  const size_t** wn = get_neighborhood(*world_);
  this->birth_rule(wn, world_);
  this->death_rule(wn, world_);
}
