// Base classes for single options
#pragma once

#include <CorradeStlForwardString.h>

namespace aspartame {

  // Basic interface for all options
  struct IOpt {
    virtual bool isChanged() const { return m_changed; }
    virtual void reset() = 0;
  protected:
    bool m_changed {false};
  };

  struct IOptScalar : public IOpt {
    virtual std::string getStr() const = 0;
    virtual void setStr(const std::string& input) = 0;
    virtual void setStr(const char* input) = 0;
  };


}

