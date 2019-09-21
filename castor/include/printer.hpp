/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_PRINTER_HPP__
#define __CASTOR_PRINTER_HPP__

#include <iostream>
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
   * Print the world.
   *
   * \param world_ World.
   */
  void print(const World& world_);

  /*!
   * Print the simulation history in a file.
   *
   * \param history_ Simulation history.
   */
  void print(const std::vector<World>& history_);
}

#endif /* __CASTOR_PRINTER_HPP__ */
