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
#include "utils.hpp"
#include "world.hpp"

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc <= 1) {
    std::cout << "CASTOR: Please enter the world file!\n";
  } else {
    // Get file
    YAML::Node node = YAML::LoadFile(std::string(argv[1]));
    // Create world
    std::string file(argv[1]);
    file = file.substr(0, file.find_last_of('/')) + '/' +
      node["data"].as<std::string>();
    bool** w = utils::read_population(node["width"].as<size_t>(),
      node["height"].as<size_t>(), node["key"].as<char>(), file);
    World* world = new World(node["width"].as<size_t>(),
      node["height"].as<size_t>(), w);
    printer::print(world);
    // Create CA
    // Apply CA rules
    // Save output?
  }
  return EXIT_SUCCESS;
}
