#include "aspartame/registry.h"
#include "aspartame/exception-registry.h"
#include "aspartame/interface-option.h"

#include "sugiyama/pimpl-inl.h"

#include <map>
#include <string>
#include <stdexcept> // for std::out_of_range

namespace aspartame {

  struct OptionRegistry::Impl {
    std::map<std::string, OptionType, std::less<>> mOpt;
    std::map<std::string, std::string, std::less<>> mDesc;
    std::map<std::string, IOptScalar*, std::less<>> mOptScalar;
  };

  OptionRegistry::OptionRegistry() = default;
  OptionRegistry::~OptionRegistry() = default;
  OptionRegistry::OptionRegistry(OptionRegistry&& rhs) noexcept = default;
  OptionRegistry& OptionRegistry::operator=(OptionRegistry&& rhs) noexcept = default;


  void OptionRegistry::add(const char* name, const char* desc, IOptScalar& opt) {
    if (!has(name)) {
      pimpl->mOpt.emplace(name, OptionType::scalar);
      pimpl->mDesc.emplace(name, desc);
      pimpl->mOptScalar.emplace(name, &opt);
    } else {
      throw ExceptionRegistryAddDup(name);
    }
  }

  bool OptionRegistry::has(const char* name) {
    return pimpl->mOpt.count(name) > 0;
  }

  size_t OptionRegistry::size() {
    return pimpl->mOpt.size();
  }

  const char* OptionRegistry::getDesc(const char* name) {
    try {
      return pimpl->mDesc.at(name).c_str();
    } catch(const std::out_of_range& e) {
      throw ExceptionRegistryOutOfRange(e.what());
    }
  }

}

SUGIYAMA_PIMPL_INST(aspartame::OptionRegistry::Impl);
