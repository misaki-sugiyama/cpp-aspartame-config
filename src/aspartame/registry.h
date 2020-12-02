// Config registry
#pragma once
#include "sugiyama/pimpl.h"

namespace aspartame {

  class OptBase; // forward decleration

  enum class OptionType { scalar, array, map };

  class OptionRegistry {
  public:
    void add(const char* name, OptBase* opt);

    bool has(const char* name);

  private:
    class Impl;
    sugiyama::PImpl<Impl> pimpl;
  };


  // Forward-declared Option base class
  class IOpt;

}
