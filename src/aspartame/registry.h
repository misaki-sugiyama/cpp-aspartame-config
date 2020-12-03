// Config registry
#pragma once
#include "sugiyama/pimpl.h"

namespace aspartame {

  // forward decleration of base classes
  struct IOptScalar;

  enum class OptionType { scalar, array, map, multimap };

  struct OptionRegistry {
    void add(const char* name, IOptScalar* opt);
    bool has(const char* name);

  private:
    class Impl;
    sugiyama::PImpl<Impl> pimpl;
  };

}
