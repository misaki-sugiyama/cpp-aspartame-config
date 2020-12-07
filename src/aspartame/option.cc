#include "aspartame/option.h"

#include "sugiyama/pimpl-inl.h"

#include <string>

namespace aspartame {

  template <typename Type>
  struct Opt<Type>::Impl {
    Impl(const Type& value) : m_default(value), m_data(value) {}
    const Type m_default;
    Type m_data;
  };

  template <typename Type>
  Opt<Type>::Opt(OptionRegistry& REG, const char* name, const Type& value, const char* desc) :
    pimpl(value)
  {
    REG.add(name, desc, *this);
  }

  template <typename Type>
  void Opt<Type>::reset() {
    pimpl->m_data = pimpl->m_default;
  }


}

template class aspartame::Opt<int64_t>;
SUGIYAMA_PIMPL_INST(aspartame::Opt<int64_t>::Impl);

template class aspartame::Opt<double>;
SUGIYAMA_PIMPL_INST(aspartame::Opt<double>::Impl);
