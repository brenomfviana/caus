/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_PRINTER_HPP__
#define __CASTOR_PRINTER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "world.hpp"

namespace printer {
  /*!
   * Reset the terminal.
   */
  void reset();

  /*!
   * Clear the terminal.
   */
  void clear();

  /*!
   * Print simulator header.
   *
   * \param rules_ Cellular automata rules.
   * \param i_ Simulation iteration.
   */
  void header(const std::string rules_, int i_);

  /*!
   * Print the world.
   *
   * \param rules_ Cellular automata rules.
   * \param i_ Simulation iteration.
   * \param world_ World.
   */
  void print(std::string rules_, int i_, const World& world_);

  /*!
   * Write the simulation history in a file.
   *
   * \param history_ Simulation history.
   * \param filename_ Filename.
   */
  void write(const std::vector<World>& history_, std::string filename_);
}

#endif /* __CASTOR_PRINTER_HPP__ */
