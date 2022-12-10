#include <iostream>
#include "wlhash.h"

int main(int argc, char* argv[]) {

  if (argc == 1) {std::cout << "Please provide adjacency matrix." << std::endl;}
  else if (argc == 2) {
    std::cout << wlhash(fromstr(argv[1]), 3) << std::endl;
  } else if (argc == 3) {
    int iterations = atoi(argv[2]);
    std::cout << wlhash(fromstr(argv[1]), iterations) << std::endl;
  }
  return 0;
}
