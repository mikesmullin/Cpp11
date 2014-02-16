class Vector {
private:
  double* elem; // elem points to an array of sz doubles
  int sz;
public:
  Vector(int s)
    :elem{new double[s]}, sz{s} // constructor: acquire resources
  {
    for (int i=0; i!=s; ++i) elem[i]=0; // initialize elements
  }
  ~Vector() { delete[] elem; } // destructor: release resources
  double& operator[](int i);
  int size() const;
};

void fct(int n)
{
  Vector v(n);
  // ... use v ...
  {
    Vector v2(2*n);
    // ... use v and v2 ...
  } // v2 is destroyed here
  // ... use v ...
} // v is destroyed here

int main() {
  fct(3);
}
