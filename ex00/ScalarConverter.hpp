#include <string>

class ScalarConverter {
public:
  static void convert(std::string const &rep);

private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &rhs);
};
