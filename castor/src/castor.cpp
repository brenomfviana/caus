/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include <string>
#include <fstream>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "reader.hpp"
#include "simulator.hpp"

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc <= 1) {
    std::cout << "CASTOR: Please enter the world file!\n";
  } else {
    // Get file
    std::string file(argv[1]);
    YAML::Node node = YAML::LoadFile(file);
    // Create world
    World* world = reader::read(node["width"].as<size_t>(),
      node["height"].as<size_t>(), node["key"].as<char>(),
      (file.substr(0, file.find_last_of('/')) + '/' +
        node["data"].as<std::string>()));
    // Create cellular automata
    CellularAutomata* ca =
      new CellularAutomata(node["rulestring"].as<std::string>());
    // Create simulator
    Simulator s(world, ca, node["generations"].as<size_t>());
    // Run simulation
    s.run();
  }
  return EXIT_SUCCESS;
}
