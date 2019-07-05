/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "simulator.hpp"

Simulator::Simulator(World* world_) : world(world_) { /* empty */ }

World Simulator::get_world() {
  return *this->world;
}

void Simulator::run() {
  // Create CA
  // Apply CA rules
}
