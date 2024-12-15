#include "Data.hpp"

Data::Data() : _whatever("Whatever") {}
Data::~Data() {}

Data::Data(Data const &other) : _whatever(other.getWhatever()) {}

std::string const &Data::getWhatever() const { return this->_whatever; }

Data &Data::operator=(Data const &rhs) {
  if (this != &rhs)
    _whatever = rhs.getWhatever();
  return *this;
}
