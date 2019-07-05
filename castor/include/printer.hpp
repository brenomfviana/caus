/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_PRINTER_HPP__
#define __CASTOR_PRINTER_HPP__

#include <iostream>
#include "world.hpp"

namespace printer {
  /*!
   * Print the world
   *
   * \param world_
   *     World
   */
  void print(World* world_);
}

#endif /* __CASTOR_PRINTER_HPP__ */
