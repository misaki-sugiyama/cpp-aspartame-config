#include "aspartame/registry.h"
#include "aspartame/interface-option.h"

#include "sugiyama/pimpl-inl.h"

#include <map>
#include <string>

namespace aspartame {

  struct OptionRegistry::Impl {
    std::map<std::string, OptionType> mOpt;
    std::map<std::string, IOptScalar*> mOptScalar;
  };

  OptionRegistry::OptionRegistry() = default;
  SUGIYAMA_RO5_DEF(OptionRegistry, OptionRegistry);

  void OptionRegistry::add(const char* name, IOptScalar* opt) {
    // TODO: need some exceptions here
    pimpl->mOpt.emplace
  }

}

SUGIYAMA_PIMPL_INST(aspartame::OptionRegistry::Impl);
