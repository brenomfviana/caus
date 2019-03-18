/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef _CASTOR_WORLD_HPP_
#define _CASTOR_WORLD_HPP_

#include <iostream>

class World {
  private:
    bool **world; //< World
    size_t width; //< World width
    size_t height; //< World height

  public:
    /*!
     * \brief World constructor
     */
    World(const size_t width, const size_t height);

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
     * \brief Set a cell as alive
     *
     * \param i
     *     Row
     * \param j
     *     Col
     */
    void set_alive(size_t i, size_t j);

    /*!
     * \brief Set a cell as dead
     *
     * \param i
     *     Row
     * \param j
     *     Col
     */
    void set_dead(size_t i, size_t j);
};

#endif /* _CASTOR_WORLD_HPP_ */
