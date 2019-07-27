/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_SIMULATOR_HPP__
#define __CASTOR_SIMULATOR_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include "cellular-automata.hpp"
#include "printer.hpp"
#include "world.hpp"

/*!
 * This class represents a cellular life simulator
 */
class Simulator {
  private:
    World* world; //< World
    CellularAutomata* ca; //< Cellular automata
    size_t max; //< Maximum number of generations

  public:
    /*!
     * Simulator constructor
     *
     * \param world_
     *     World
     * \param ca_
     *     Cellular automata
     * \param max_
     *     Maximum number of generations
     */
    Simulator(World* world_, CellularAutomata* ca_, size_t max_);

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
