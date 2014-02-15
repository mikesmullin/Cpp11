#include <iostream>

bool accept() {
  std::cout << "Do you want to proceed (y or n)?\n"; // ask question
  char answer = 0;
  std::cin >> answer; // read answer
  if (answer == 'y') return true;
  return false;
}

int main() {
  if (accept()) {
    std::cout << "woo";
  }
  else {
    std::cout << "boo";
  }
}
