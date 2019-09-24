/*
  This file is part of CAUS.

  Copyright (c) 2019 by Breno Viana

  CAUS is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include <string>
#include <fstream>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "printer.hpp"
#include "reader.hpp"
#include "simulator.hpp"
#include "utils.hpp"

int main(int argc, char* argv[]) {
  // Check arguments
  if (argc <= 1) {
    std::cout << "CAUS: Please enter the world file!\n";
  } else {
    // Check random flag
    if (std::string(argv[1]).compare("-rand") == 0) {
      // Check arguments
      if (argc <= 5) {
        std::cout << "CAUS: Please enter the world dimensions, the " <<
          " rule string and the number of generations!\n";
          std::cout << "   Format: ./caus -r <width> <height> " <<
            "<string_rule> <max_number_of_generations>\n";
          std::cout << "   Example: ./caus -r 20 20 B3/S23 20\n";
      } else {
        if (!utils::is_number(argv[2]) || !utils::is_number(argv[2])) {
          std::cout << "CAUS: Invalid dimensions!\n";
        } else {
          // Reset terminal screen
          printer::reset();
          // Create world
          std::shared_ptr<World> world = std::make_shared<World>(
            std::stoi(argv[2]), std::stoi(argv[3]));
          // Create cellular automata
          std::unique_ptr<CellularAutomata> ca =
            std::make_unique<CellularAutomata>(std::string(argv[4]));
          // Populate world with random values
          Simulator::generate_world(world);
          // Create simulator
          Simulator s(std::stoi(argv[5]), world, std::move(ca));
          // Run simulation
          s.run();
          // Print history
          std::string rules(argv[4]);
          rules = rules.substr(0, rules.find_last_of('/')) +
            rules.substr(rules.find_last_of('/') + 1,
              rules.length());
          std::cout << rules << '\n';
          std::string filename = "caus-history-" + std::string(argv[2]) + "-" +
            std::string(argv[3]) + "-" + rules + "-" +
              std::string(argv[5]) + ".txt";
          std::cout << filename << '\n';
          printer::write(s.get_history(), filename);
        }
      }
    } else {
      try {
        // Get and load the world description file
        std::string file(argv[1]);
        YAML::Node node = YAML::LoadFile(file);
        // Reset terminal screen
        printer::reset();
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
          std::make_unique<CellularAutomata>
            (node["rules"].as<std::string>());
        // Create simulator
        Simulator s(node["generations"].as<size_t>(), world, std::move(ca));
        // Run simulation
        s.run();
      } catch (YAML::BadFile& e) {
        std::cout << "The selected file is invalid." << '\n';
      }
    }
  }
  return EXIT_SUCCESS;
}
