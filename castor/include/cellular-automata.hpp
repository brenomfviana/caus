/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_CELLULAR_AUTOMATA_HPP__
#define __CASTOR_CELLULAR_AUTOMATA_HPP__

#include <string>

class CellularAutomata {
  private:
    size_t b; //< Birth rule
    size_t s; //< Survive rule

  public:
    CellularAutomata(std::string rules) {
      //
    }
};

#endif /* __CASTOR_CELLULAR_AUTOMATA_HPP__ */
