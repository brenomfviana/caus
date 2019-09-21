/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#ifndef __CASTOR_UTILS_HPP__
#define __CASTOR_UTILS_HPP__

#include <algorithm>
#include <string>

namespace utils {
  /*!
   * Check if a string is a number.
   *
   * \param s_ A string.
   */
   bool is_number(const std::string& s_);
}

#endif /* __CASTOR_UTILS_HPP__ */
