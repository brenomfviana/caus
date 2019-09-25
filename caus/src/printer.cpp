/*
  This file is part of CAUS.

  Copyright (c) 2019 by Breno Viana

  CAUS is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "printer.hpp"

void printer::clear() {
  std::cout << "\033[1;1H" << '\n';
}

void printer::reset() {
  std::cout << "\033[2J" << '\n';
}

void printer::header(std::string rulestring_, int i_) {
  std::cout << "CAUS v1.0" << '\n';
  std::cout << "- STRING RULE: " << rulestring_ << '\n';
  std::cout << "- Generation: " << i_ << '\n';
  std::cout << '\n';
}

void printer::print(std::string rulestring_, int i_, const World& world_) {
  // Print CAUS headerif(
  header(rulestring_, i_);
  // Print world
  for (size_t i = 0; i < world_.get_height(); i++) {
    for (size_t j = 0; j < world_.get_width(); j++) {
      if (world_.is_alive(i, j)) {
        std::cout << "*";
      } else {
        std::cout << ".";
      }
    }
    std::cout << "\n";
  }
}

void printer::write(const std::vector<World>& history_, std::string filename_) {
  // Create the history file
  std::ofstream history;
  history.open(filename_);
  // Write history
  history << "[Cellular Automata Simulation]" << '\n';
  history << filename_ << '\n';
  history << '\n';
  int i = 0;
  for (World w : history_) {
    // Print world
    history << "- Generation: " << ++i << '\n';
    for (size_t i = 0; i < w.get_height(); i++) {
      for (size_t j = 0; j < w.get_width(); j++) {
        if (w.is_alive(i, j)) {
          history << "*";
        } else {
          history << ".";
        }
      }
      history << "\n";
    }
    history << "\n";
  }
  // Close the file
  history.close();
}
