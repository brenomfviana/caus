/*
  This file is part of CAUS.

  Copyright (c) 2019 by Breno Viana

  CAUS is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CAUS_WORLD_HPP__
#define __CAUS_WORLD_HPP__

#include <vector>

/*!
 * This class represents a cellular world.
 */
class World {
  private:
    bool** world; //< World
    size_t width; //< World width
    size_t height; //< World height

  public:
    /*!
     * World constructor.
     *
     * \param width_ World width.
     * \param height_ World height.
     */
    World(const size_t width_, const size_t height_);

    /*!
     * World copy constructor.
     *
     * \param world_ World.
     */
    World(const World& world_);

    /*!
     * World destructor.
     */
    ~World();

    /*!
     * Return world width.
     *
     * \return World width.
     */
    const size_t get_width() const;

    /*!
     * Return world height.
     *
     * \return World height.
     */
    const size_t get_height() const;

    /*!
     * Check if the cell is alive.
     *
     * \param i_ Row.
     * \param j_ Column.
     *
     * \return True if the cell is alive and false otherwise.
     */
    const bool is_alive(const size_t i_, const size_t j_) const;

    /*!
     * Set a cell as alive.
     *
     * \param i_ Row.
     * \param j_ Column.
     */
    void set_alive(const size_t i_, const size_t j_);

    /*!
     * Set a cell as dead.
     *
     * \param i_ Row.
     * \param j_ Column.
     */
    void set_dead(const size_t i_, const size_t j_);

    /*!
     * Get number of alive neighbors.
     *
     * \param i_ Row.
     * \param j_ Column.
     *
     * \return The number of alive neighbors.
     */
    const size_t get_no_neighbors(const size_t i_, const size_t j_) const;

    /*!
     * Equality operator.
     *
     * \param world_ A world.
     *
     * \return True if the worlds are the same and false otherwise.
     */
    const bool operator==(const World& world_) const;

    /*!
     * Difference operator.
     *
     * \param world_ A world.
     *
     * \return True if the worlds are not the same and false otherwise.
     */
    const bool operator!=(const World& world_) const;
};

#endif /* __CAUS_WORLD_HPP__ */
