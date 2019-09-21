/*
  This file is part of CASTOR.

  Copyright (c) 2019 by Breno Viana

  CASTOR is a free software; you can redistribute it and/or modify it under the
  terms of the MIT License.
*/

#include "utils.hpp"

bool utils::is_number(const std::string& s_) {
  return !s_.empty() && std::find_if(s_.begin(),
   s_.end(), [](char c) { return !std::isdigit(c); }) == s_.end();
}
