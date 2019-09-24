/*
  This file is part of CAUS.

  Copyright (c) 2019 by Breno Viana

  CAUS is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "simulator.hpp"

Simulator::Simulator(size_t max_, std::shared_ptr<World> world_,
  std::unique_ptr<CellularAutomata> ca_)
    : max(max_), world(world_), ca(std::move(ca_)) { /* empty */ }

World Simulator::get_world() {
  return *this->world;
}

std::vector<World> Simulator::get_history() {
  return this->history;
}

void Simulator::run() {
  // Apply CA rules
  size_t i = 0;
  printer::clear();
  this->history.push_back(World(*this->world));
  printer::print(this->ca->get_rulestring(), ++i, *this->world);
  while (i < this->max && !this->is_stable()) {
    printer::clear();
    this->ca->apply_ca(this->world);
    printer::print(this->ca->get_rulestring(), ++i, *this->world);
    std::cout << '\n';
    this->history.push_back(World(*this->world));
    usleep(500000);
  }
}

bool Simulator::is_stable() {
  size_t hsize = this->history.size();
  if (hsize > 1) {
    return (this->history[hsize - 1] == this->history[hsize - 2]);
  }
  return false;
}

void Simulator::generate_world(std::shared_ptr<World> world_) {
  // Seed
  std::random_device seed;
  // Random number generator
  std::mt19937 gen = std::mt19937(seed());
  // Set distribuition
  std::uniform_int_distribution<> dis(0, 1);
  // Build world
  for (size_t i = 0; i < world_->get_height(); i++) {
    for (size_t j = 0; j < world_->get_width(); j++) {
      if (dis(gen) % 2 == 0) {
        world_->set_alive(i, j);
      }
    }
  }
}
