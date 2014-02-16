#include <iostream>
//typedef int Record;

int count_x(char* p, char x) {
  // count the number of occurrences of x in p[]
  // p is assumed to point to a zero-terminated array of char (or to nothing)
  if (p==nullptr) return 0;
  int count = 0;
  for (; *p!=0; ++p) {
    if (*p==x)
      ++count;
  }
  return count;
}

int main() {
  double* pd = nullptr;
  //Link<Record>* lst = nullptr; // pointer to a Link to a Record
  //int x = nullptr; // error: nullptr is a pointer not an integer

  char s[] = "Hello0";
  std::cout << count_x(s, 'l');
}
