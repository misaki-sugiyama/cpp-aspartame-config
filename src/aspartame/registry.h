// Config registry
#pragma once
#include "sugiyama/pimpl.h"
#include "sugiyama/ro5.h"

#include <CorradeStlForwardString.h>

namespace aspartame {

  // forward decleration of base classes
  struct IOptScalar;

  enum class OptionType { scalar, array, map };

  struct OptionRegistry {
    OptionRegistry();

    bool has(const std::string& name);
    void add(const std::string& name, IOptScalar& opt);

    SUGIYAMA_RO5_DEC(OptionRegistry);
  private:
    struct Impl;
    sugiyama::PImpl<Impl> pimpl;
  };

}
