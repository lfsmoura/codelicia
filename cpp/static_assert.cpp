#include <iostream>

using namespace std;

template <typename T>
class Number {
  T number_;
public:
  Number(T number) : number_(number) {
    // flags a compilation error if experession is false
    static_assert(std::is_arithmetic<T>::value, "type must be a number"); 
  }
};

class B {

};

int main()
{
  double d;
  int i;
  B b;
  
  Number<double> cd(d); // OK, d is a floating-point number 
  Number<int> ci(i);    // OK, i is Integral
  //Number<B> cb(b);    // Not OK, b is a class 
}
