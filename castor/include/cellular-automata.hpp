/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_CELLULAR_AUTOMATA_HPP__
#define __CASTOR_CELLULAR_AUTOMATA_HPP__

#include <string>
#include "world.hpp"

/*!
 * This class represents a cellular automata
 */
class CellularAutomata {
  private:
    size_t br; //< Birth rule
    size_t sr; //< Survive rule

    /*!
     * Apply birth rule
     *
     * \param world_
     *     World
     */
    void birth_rule(World* world_);

    /*!
     * Apply death rule
     *
     * \param world_
     *     World
     */
    void death_rule(World* world_);

  public:
    /*!
     * Cellular Automata constructor
     *
     * \param rules_
     *     Cellular Automata rules (Format: "B/S")
     */
    CellularAutomata(std::string rules_);

    /*!
     * Apply cellular automata rules
     *
     * \param world_
     *     World
     */
    void apply_ca(World* world_);
};

#endif /* __CASTOR_CELLULAR_AUTOMATA_HPP__ */
