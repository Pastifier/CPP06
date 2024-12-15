#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

#define PRINT(X) std::cout << X << std::endl
#define ERR(X) std::cerr << X << std::endl

static inline bool isPseudoLiteral(const std::string &rep) {
  return (rep == "nan" || rep == "nanf" || rep == "+inf" || rep == "-inf" ||
          rep == "+inff" || rep == "-inff");
}

static inline bool isInteger(const std::string &rep) {
  size_t i = 0;
  if (rep[i] == '-' || rep[i] == '+')
    i++;
  while (i < rep.size() && std::isdigit(rep[i]))
    i++;
  return i == rep.size();
}

static inline bool isFloat(const std::string &rep) {
  if (isPseudoLiteral(rep))
    return true;
  size_t i = 0;
  if (rep[i] == '-' || rep[i] == '+')
    i++;
  bool hasDecimal = false;
  while (i < rep.size() &&
         (std::isdigit(rep[i]) || (rep[i] == '.' && !hasDecimal))) {
    if (rep[i] == '.')
      hasDecimal = true;
    i++;
  }
  return i == rep.size() - 1 && rep[rep.size() - 1] == 'f';
}

static inline bool isDouble(const std::string &rep) {
  if (isPseudoLiteral(rep))
    return true;
  size_t i = 0;
  if (rep[i] == '-' || rep[i] == '+')
    i++;
  bool hasDecimal = false;
  while (i < rep.size() &&
         (std::isdigit(rep[i]) || (rep[i] == '.' && !hasDecimal))) {
    if (rep[i] == '.')
      hasDecimal = true;
    i++;
  }
  return i == rep.size();
}

static inline bool isNan(double d) { return d != d; }
static inline bool isInf(double d) { return d == HUGE_VAL || d == -HUGE_VAL; }

void ScalarConverter::convert(const std::string &rep) {
  if (rep.size() == 1 && !std::isdigit(rep[0])) {
    // Single character case
    char c = rep[0];
    PRINT("char: " << c);
    PRINT("int: " << static_cast<int>(c));
    PRINT("float: " << static_cast<float>(c) << ".0f");
    PRINT("double: " << static_cast<double>(c) << ".0");
    return;
  }

  if (isInteger(rep)) {
    long num = std::strtol(rep.c_str(), 0, 10);
    if (num < std::numeric_limits<int>::min() ||
        num > std::numeric_limits<int>::max()) {
      PRINT("char: impossible");
      PRINT("int: overflow occurred");
      PRINT("float: overflow occurred");
      PRINT("double: overflow occurred");
    } else {
      int n = static_cast<int>(num);
      if (std::isprint(n)) {
        PRINT("char: '" << static_cast<char>(n) << "'");
      } else {
        PRINT("char: Non displayable");
      }
      PRINT("int: " << n);
      PRINT("float: " << static_cast<float>(n) << ".0f");
      PRINT("double: " << static_cast<double>(n) << ".0");
    }
    return;
  }

  if (isFloat(rep)) {
    float f = std::strtof(rep.c_str(), 0);
    if (f == static_cast<float>(HUGE_VAL) ||
        f == static_cast<float>(-HUGE_VAL)) {
      PRINT("char: impossible");
      PRINT("int: impossible");
      PRINT("float: overflow occurred");
      PRINT("double: overflow occurred");
    } else {
      if (std::isprint(static_cast<int>(f))) {
        PRINT("char: '" << static_cast<char>(f) << "'");
      } else if (isNan(f) || isInf(f)) {
        PRINT("char: impossible");
      } else {
        PRINT("char: Non displayable");
      }
      if (isNan(f) || isInf(f)) {
        PRINT("int: impossible");
      } else {
        PRINT("int: " << static_cast<int>(f));
      }
      PRINT("float: " << f << (std::floor(f) == f ? ".0f" : "f"));
      PRINT(
          "double: " << static_cast<double>(f)
                     << (std::floor(f) == static_cast<double>(f) ? ".0" : ""));
    }
    return;
  }

  if (isDouble(rep)) {
    double d = std::strtod(rep.c_str(), 0);
    if (d == HUGE_VAL || d == -HUGE_VAL) {
      PRINT("char: impossible");
      PRINT("int: impossible");
      PRINT("float: overflow occurred");
      PRINT("double: overflow occurred");
    } else {
      if (std::isprint(static_cast<int>(d))) {
        PRINT("char: '" << static_cast<char>(d) << "'");
      } else if (isNan(d) || isInf(d)) {
        PRINT("char: impossible");
      } else {
        PRINT("char: Non displayable");
      }
      if (isNan(d) || isInf(d)) {
        PRINT("int: impossible");
      } else {
        PRINT("int: " << static_cast<int>(d));
      }
      PRINT("float: " << static_cast<float>(d)
                      << (std::floor(d) == d ? ".0f" : "f"));
      PRINT("double: " << d << (std::floor(d) == d ? ".0" : ""));
    }
    return;
  }

  PRINT("char: impossible");
  PRINT("int: impossible");
  PRINT("float: impossible");
  PRINT("double: impossible");
}
