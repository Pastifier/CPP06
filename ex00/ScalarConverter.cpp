#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

#define PRINT(X) std::cout << X << std::endl
#define ERR(X) std::cerr << X << std::endl

static inline bool checkCharValidity(std::string const &rep) {
  if (rep.length() != 3 ||
      (rep.length() == 3 && (rep[0] != '\'' || rep[rep.length() - 1] != '\'')))
    return false;
  return true;
}

static inline bool checkIntValidity(std::string const &rep) {
  int op = 0;
  int num = static_cast<int>(atoi(rep.c_str()));
  bool isSigned = ('-' == rep[0] || '+' == rep[0]) ? true : false;
  bool isNeg = ('-' == rep[0]) ? true : false;

  while (num) {
    ++op;
    num /= 10;
  }

  int length = rep.length();
  if (op != (length - isSigned) || op > 10 ||
      (op == 10 && isNeg && rep[length - 1] - '0' > 8) ||
      (op == 10 && !isNeg && rep[length - 1] - '0' > 7))
    return false;
  return true;
}

static inline bool checkSPFValidity(std::string const &rep) {
  if (rep[rep.length() - 1] != 'f')
    return false;
  return true;
}

static inline bool checkDPFValidity(std::string const &rep) { return true; }

void ScalarConverter::convert(std::string const &rep) {
  PRINT("char: " << static_cast<char>(atoi(rep.c_str())));
  PRINT("int: " << atoi(rep.c_str()));
  PRINT("float: " << static_cast<float>(atof(rep.c_str())));
  PRINT("double: " << atof(rep.c_str()));
}
