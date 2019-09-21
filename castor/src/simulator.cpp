/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "simulator.hpp"

Simulator::Simulator(size_t max_, std::shared_ptr<World> world_,
  std::unique_ptr<CellularAutomata> ca_)
    : max(max_), world(world_), ca(std::move(ca_)) { /* empty */ }

World Simulator::get_world() {
  return *this->world;
}

void Simulator::run() {
  // Apply CA rules
  size_t i = 0;
  printer::clear();
  std::cout << "Generation: " << i << '\n';
  this->history.push_back(World(*this->world));
  printer::print(*this->world);
  while (i < this->max && !this->is_stable()) {
    printer::clear();
    std::cout << "Generation: " << ++i << '\n' << std::flush;
    this->ca->apply_ca(this->world);
    printer::print(*this->world);
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
