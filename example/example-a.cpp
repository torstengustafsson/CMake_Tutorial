#include <iostream>
#include "header-b.hpp"

int main() {
  
  A a;
  B b(a);

  std::cout << "hello world!\n" << "b.xyz = " << b.x << " " << b.y << " " << b.z << "\n";
  int quit;
  std::cin >> quit;
}
