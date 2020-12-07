// Single option classes
#pragma once

#include "aspartame/interface-option.h"
#include "aspartame/registry.h"

namespace aspartame {

  // Scalar options
  template <typename Type>
  struct Opt : IOptScalar {
  public:
    Opt(OptionRegistry& REG, const char* name, const Type& value, const char* desc="");

    virtual void reset();
    virtual const char* getStr() const {return 0;}
    virtual void setStr(const char* input) {}

    operator Type();
    operator Type() const;
    Type& operator=(const Type& rhs);
    Type& operator=(Type&& rhs);

    virtual ~Opt() = default;
  private:
    struct Impl;
    sugiyama::PImpl<Impl> pimpl;
  };

}

