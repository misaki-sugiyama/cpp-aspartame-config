#include "aspartame/registry.h"
#include "aspartame/exception-registry.h"
#include "aspartame/interface-option.h"

#include "sugiyama/pimpl-inl.h"

#include <map>
#include <string>

namespace aspartame {

  struct OptionRegistry::Impl {
    std::map<std::string, OptionType, std::less<>> mOpt;
    std::map<std::string, IOptScalar*, std::less<>> mOptScalar;
  };

  OptionRegistry::OptionRegistry() = default;
  SUGIYAMA_RO5_DEF(OptionRegistry, OptionRegistry);

  bool OptionRegistry::has(const std::string& name) {
    return pimpl->mOpt.count(name) > 0;
  }

  void OptionRegistry::add(const std::string& name, IOptScalar& opt) {
    if (!has(name)) {
      pimpl->mOpt.emplace(name, OptionType::scalar);
      pimpl->mOptScalar.emplace(name, &opt);
    } else {
      throw ExceptionRegistryAddDup(name);
    }
  }

}

SUGIYAMA_PIMPL_INST(aspartame::OptionRegistry::Impl);
