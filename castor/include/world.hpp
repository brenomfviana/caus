/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_WORLD_HPP__
#define __CASTOR_WORLD_HPP__

#include <iostream>

/*!
 * This class represents a cellular world
 */
class World {
  private:
    bool** world; //< World
    size_t width; //< World width
    size_t height; //< World height

  public:
    /*!
     * World constructor
     *
     * \param width_
     *     World width
     * \param height_
     *     World height
     * \param w_
     *     World population
     */
    World(const size_t width_, const size_t height_, bool** w_);

    /*!
     * World destructor
     */
    ~World();

    /*!
     * Return world width
     *
     * \return
     *     World width
     */
    size_t get_width();

    /*!
     * Return world height
     *
     * \return
     *     World height
     */
    size_t get_height();

    /*!
     * Check if the cell is alive
     *
     * \param i_
     *     Row
     * \param j_
     *     Column
     *
     * \return
     *     True if the cell is alive and false otherwise
     */
    bool is_alive(const size_t i_, const size_t j_);

    /*!
     * Set a cell as alive
     *
     * \param i_
     *     Row
     * \param j_
     *     Column
     */
    void set_alive(const size_t i_, const size_t j_);

    /*!
     * Set a cell as dead
     *
     * \param i_
     *     Row
     * \param j_
     *     Column
     */
    void set_dead(const size_t i_, const size_t j_);

    /*!
     * Get number of alive neighbours
     *
     * \param i_
     *     Row
     * \param j_
     *     Column
     *
     * \return
     *     The number of alive neighbours
     */
    size_t get_no_neighbours(const size_t i_, const size_t j_);
};

#endif /* __CASTOR_WORLD_HPP__ */
