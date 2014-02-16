// HEADER
double sqrt(double); // the square root function takes a double and returns a double

class Vector {
public:
  Vector(int s);
  double& operator[](int i);
  int size();
private:
  double* elem; // elem points to an array of sz doubles
  int sz;
};


// -------------------------------------------

// BODY

double sqrt(double d) { // definition of sqrt
  // ... algorithm as found in math textbook ...
}

Vector::Vector(int s) // definition of the constructor
  :elem{new double[s]}, sz{s} // initialize members
{
}

double& Vector::operator[](int i) // definition of subscripting
{
  return elem[i];
}

int Vector::size() // definition of size()
{
  return sz;
}

int main() {
  Vector v(3);
}
