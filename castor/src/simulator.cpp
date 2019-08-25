/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "simulator.hpp"

Simulator::Simulator(World* world_, CellularAutomata* ca_, size_t max_) :
  world(world_), ca(ca_), max(max_) { /* empty */ }

World Simulator::get_world() {
  return *this->world;
}

void Simulator::run() {
  // Apply CA rules
  size_t i = 0;
  std::cout << "Generation: " << i << '\n';
  printer::print(this->world);
  while (i < this->max) {
    std::cout << "Generation: " << ++i << '\n' << std::flush;
    this->ca->apply_ca(this->world);
    printer::print(this->world);
    std::cout << '\n';
    usleep(500000);
  }
}
