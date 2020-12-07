// Config registry
#pragma once
#include "sugiyama/pimpl.h"

#include <cstddef> // for size_t

namespace aspartame {

  // forward decleration of base classes
  struct IOptScalar;

  enum class OptionType { scalar, array, map };

  struct OptionRegistry {
    void add(const char* name, const char* desc, IOptScalar& opt);
    bool has(const char* name);
    size_t size();

    const char* getDesc(const char* name);

    OptionRegistry();
    ~OptionRegistry();
    OptionRegistry(OptionRegistry&& rhs) noexcept;
    OptionRegistry& operator=(OptionRegistry&& rhs) noexcept;
    // No copy for registry class
    OptionRegistry(const OptionRegistry& rhs) = delete;
    OptionRegistry& operator=(const OptionRegistry& rhs) = delete;
  private:
    struct Impl;
    sugiyama::PImpl<Impl> pimpl;
  };

}
