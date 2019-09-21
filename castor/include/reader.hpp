/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_READER_HPP__
#define __CASTOR_READER_HPP__

#include <fstream>
#include <memory>
#include "world.hpp"

namespace reader {
  /*!
   * Read the world.
   *
   * \param world_ World.
   * \param key_ Cell key.
   * \param path_ Path file of world population.
   *
   * \return World.
   */
  void read(std::shared_ptr<World> world, const char key_,
    const std::string path_);
}

#endif /* __CASTOR_READER_HPP__ */
