#include <iostream>
#include <cstdlib>

namespace myglobals {
  int cat;
  std::string dog = "bow wow";
}

int main(void) {

  std::cout << myglobals::dog << std::endl;

  return EXIT_SUCCESS;
}
