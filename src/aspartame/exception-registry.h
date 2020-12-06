// exceptions during option registry usage
#pragma once
#include "sugiyama/exception.h"

namespace aspartame {

  class ExceptionRegistryAddDup : public sugiyama::exception {
  public:
    using exception::exception;
  };
  class ExceptionRegistryOutOfRange : public sugiyama::exception {
  public:
    using exception::exception;
  };

}
