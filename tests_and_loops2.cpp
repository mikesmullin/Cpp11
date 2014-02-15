#include <iostream>

bool accept2() {
  std::cout << "Do you want to proceed (y or n)?\n"; // ask question
  char answer = 0;
  std::cin >> answer; // read answer
  switch (answer) {
    case 'y':
      return true;
    case 'n':
      return false;
    default:
      std::cout << "I'll take that for a no.\n";
      return false;
  }
}

int main() {
  if (accept2()) {
    std::cout << "woo";
  }
  else {
    std::cout << "boo";
  }
}
