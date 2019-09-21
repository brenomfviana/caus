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
#include "printer.hpp"
#include "reader.hpp"
#include "simulator.hpp"

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc <= 1) {
    std::cout << "CASTOR: Please enter the world file!\n";
  } else {
    // Reset terminal screen
    printer::reset();
    // Get and load the world description file
    std::string file(argv[1]);
    YAML::Node node = YAML::LoadFile(file);
    // Create world
    std::shared_ptr<World> world = std::make_shared<World>(
      node["width"].as<size_t>(), node["height"].as<size_t>());
    // Get world description file path
    std::string path = file.substr(0, file.find_last_of('/')) + '/' +
      node["data"].as<std::string>();
    // Populate the world
    reader::read(world, node["key"].as<char>(), path);
    // Create cellular automata
    std::unique_ptr<CellularAutomata> ca =
      std::make_unique<CellularAutomata>(node["rulestring"].as<std::string>());
    // Create simulator
    Simulator s(node["generations"].as<size_t>(), world, std::move(ca));
    // Run simulation
    s.run();
  }
  return EXIT_SUCCESS;
}
