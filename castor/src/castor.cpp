/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include <iostream>
#include "yaml-cpp/yaml.h"
#include "world.hpp"

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc <= 1) {
    std::cout << "CASTOR: Please enter the world file!\n";
  } else {
    // Get file
    YAML::Node node = YAML::LoadFile(std::string(argv[1]));
    // Create world
    World world(node["width"].as<size_t>(), node["height"].as<size_t>());
    // Create CA
    // Apply CA rules
    // Save output?
  }
  return EXIT_SUCCESS;
}
