#include <iostream>

int main() {
  int i = 0;

  while (i < 5) {
    std::cout << i << std::endl
    i++; // Error 1: Missing semicolon
  }

  for (int j = 0; j < 3; j++) {
    std::cout << j << std::endl;
  j = 10; // Error 2: modifying loop counter inside loop
  }

  do {
    std::cout << "This will run once." << std::endl;
  } while (false);

  return 0;
}
