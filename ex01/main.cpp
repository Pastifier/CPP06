#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void) {
  Data *pdat = new Data();

  uintptr_t raw = Serializer::serialize(pdat);

  std::cout << ((raw == (uintptr_t)pdat) ? "Success" : "Fail.") << "\n";

  Data *pdat2 = Serializer::deserialize(raw);

  std::cout << ((pdat->getWhatever() == pdat2->getWhatever()) ? "Success"
                                                              : "Fail.")
            << std::endl;
  delete pdat;
}
