/*
  This file is part of CAUS.

  Copyright (c) 2019 by Breno Viana

  CAUS is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CAUS_SIMULATOR_HPP__
#define __CAUS_SIMULATOR_HPP__

#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <unistd.h>
#include <vector>
#include "cellular-automata.hpp"
#include "printer.hpp"
#include "world.hpp"

/*!
 * This class represents a Cellular Automata Simulator.
 */
class Simulator {
  private:
    std::shared_ptr<World> world; //< World
    std::unique_ptr<CellularAutomata> ca; //< Cellular Automata
    size_t max; //< Maximum number of generations
    std::vector<World> history; //< Evolution history

  public:
    /*!
     * Simulator constructor.
     *
     * \param max_ Maximum number of generations.
     * \param world_ World.
     * \param ca_ Cellular Automata.
     */
    Simulator(size_t max_, std::shared_ptr<World> world_,
      std::unique_ptr<CellularAutomata> ca_);

    /*!
     * Get the world.
     *
     * \return World.
     */
    World get_world();

    /*!
     * Get the simulation history.
     *
     * \return List of worlds.
     */
    std::vector<World> get_history();

    /*!
     * Run simulation.
     */
    void run();

    /*!
     * Check if the simulation reaches stability.
     *
     * \return True if the simulation reaches stability and false otherwise.
     */
    bool is_stable();

    /*!
     * Generate a random world.
     *
     * \param world_ World.
     */
    static void generate_world(std::shared_ptr<World> world_);
};

#endif /* __CAUS_SIMULATOR_HPP__ */
