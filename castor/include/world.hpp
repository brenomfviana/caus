/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef _CASTOR_WORLD_HPP_
#define _CASTOR_WORLD_HPP_

#include <iostream>

/*!
 * \brief This class represents the world
 */
class World {
  private:
    bool** world; //< World
    size_t width; //< World width
    size_t height; //< World height

  public:
    /*!
     * \brief World constructor
     *
     * \param width
     *     World width
     * \param height
     *     World height
     * \param w
     *     World population
     */
    World(const size_t width, const size_t height, bool** w);

    /*!
     * \brief World destructor
     */
    ~World();

    /*!
     * \brief Return world width
     *
     * \return
     *     World width
     */
    size_t get_width();

    /*!
     * \brief Return world height
     *
     * \return
     *     World height
     */
    size_t get_height();

    /*!
     * \brief Check if the cell is alive
     *
     * \param i
     *     Row
     * \param j
     *     Col
     *
     * \return
     *     True if the cell is alive and false otherwise
     */
    bool is_alive(const size_t i, const size_t j);

    /*!
     * \brief Set a cell as alive
     *
     * \param i
     *     Row
     * \param j
     *     Col
     */
    void set_alive(const size_t i, const size_t j);

    /*!
     * \brief Set a cell as dead
     *
     * \param i
     *     Row
     * \param j
     *     Col
     */
    void set_dead(const size_t i, const size_t j);
};

#endif /* _CASTOR_WORLD_HPP_ */
