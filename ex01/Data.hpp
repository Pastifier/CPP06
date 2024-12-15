#pragma once

#include <string>

class Data {
public:
  Data();
  ~Data();
  Data(Data const &other);
  Data &operator=(Data const &rhs);

  std::string const &getWhatever() const;

private:
  std::string _whatever;
};
