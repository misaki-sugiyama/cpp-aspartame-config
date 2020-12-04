// Config registry
#pragma once
#include "sugiyama/pimpl.h"
#include "sugiyama/ro5.h"

namespace aspartame {

  // forward decleration of base classes
  struct IOptScalar;

  enum class OptionType { scalar, array, map };

  struct OptionRegistry {
    OptionRegistry();

    void add(const char* name, IOptScalar* opt);
    bool has(const char* name);

    SUGIYAMA_RO5_DEC(OptionRegistry);
  private:
    struct Impl;
    sugiyama::PImpl<Impl> pimpl;
  };

}
