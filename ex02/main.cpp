#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  std::srand(std::time(NULL));
  short jmp = std::rand() % 3;
  switch (jmp) {
  case 0:
    return new A();
  case 1:
    return new B();
  case 2:
    return new C();
  default:
    return NULL;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
  } catch (std::exception &e) {
  }
}

int main(void) {
  Base *p;

  srand(time(NULL));
  p = generate();
  identify(p);
  identify(*p);
  delete p;
}
