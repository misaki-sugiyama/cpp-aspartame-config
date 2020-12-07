// Interfaces for single options
#pragma once

namespace aspartame {

  // Basic interface for all options
  struct IOpt {
    virtual bool isChanged() const { return m_changed; }
    virtual void reset() = 0;

    IOpt() = default;
    virtual ~IOpt() = default;
    // No copy or move for options
    IOpt(IOpt&& rhs) noexcept = delete;
    virtual IOpt& operator=(IOpt&& rhs) noexcept = delete;
    IOpt(const IOpt& rhs) = delete;
    virtual IOpt& operator=(const IOpt& rhs) = delete;
  protected:
    bool m_changed {false};
  };

  struct IOptScalar : public IOpt {
    using IOpt::IOpt;
    virtual ~IOptScalar() = default;
    virtual const char* getStr() const = 0;
    virtual void setStr(const char* input) = 0;
  };

}

