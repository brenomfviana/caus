/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_SIMULATOR_HPP__
#define __CASTOR_SIMULATOR_HPP__

#include <string>
#include "world.hpp"

/*!
 * This class represents a cellular life simulator
 */
class Simulator {
  private:
    World* world; //< World

  public:
    /*!
     * Simulator constructor
     *
     * \param world_
     *     World
     */
    Simulator(World* world_);

    /*!
     * Get the world
     *
     * \return
     *     World
     */
    World get_world();

    /*!
     * Run simulation
     */
    void run();
};

#endif /* __CASTOR_SIMULATOR_HPP__ */
