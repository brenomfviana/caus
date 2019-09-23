/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_CELLULAR_AUTOMATA_HPP__
#define __CASTOR_CELLULAR_AUTOMATA_HPP__

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include "world.hpp"

/*!
 * This class represents a cellular automata.
 */
class CellularAutomata {
  private:
    std::string rules; //< Cellular automata rules
    std::vector<size_t> br; //< Birth rule
    std::vector<size_t> sr; //< Survive rule

    /*!
     * Create a matrix with the number of the neighbours of each cell and.
     * return it
     *
     * \param world_ World.
     */
    const size_t** get_neighborhood(const World& world_) const;

    /*!
     * Apply birth rule.
     *
     * \param wn_ Neighborhood.
     * \param world_ World.
     */
    void birth_rule(const size_t** wn_, std::shared_ptr<World> world_) const;

    /*!
     * Apply death rule.
     *
     * \param wn_ Neighborhood.
     * \param world_ World.
     */
    void death_rule(const size_t** wn_, std::shared_ptr<World> world_) const;

  public:
    /*!
     * Cellular Automata constructor.
     *
     * \param rules_ Cellular Automata rules (Format: "B/S").
     */
    CellularAutomata(std::string rules_);

    /*!
     * Apply cellular automata rules.
     *
     * \param world_ World.
     */
    void apply_ca(std::shared_ptr<World> world_) const;

    /*!
     * Apply cellular automata rules.
     *
     * \return A string that represents Cellular Automata rules.
     */
    const std::string get_rules() const;
};

#endif /* __CASTOR_CELLULAR_AUTOMATA_HPP__ */
