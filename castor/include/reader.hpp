/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_READER_HPP__
#define __CASTOR_READER_HPP__

#include <fstream>
#include "world.hpp"

namespace reader {
  /*!
   * Read the world
   *
   * \param width_
   *     World width
   * \param height_
   *     World height
   * \param key_
   *     Cell key
   * \param ppath_
   *     Path file of world population
   */
  World* read(const size_t width_, const size_t height_, const char key_,
    const std::string ppath_);
}

#endif /* __CASTOR_READER_HPP__ */
