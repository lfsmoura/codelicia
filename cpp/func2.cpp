#include <iostream>
#include <vector>

using namespace std;

template <class T>
bool eqlZero(T x) {
  return x * x < 0.000000001;
}

class Function {
public:
  double operator ()(double x){
    return x * x - 1.0;
  }
};

template<int A0, int A1, int A2>
class Poly3 : public Function
{
public:
  double operator ()(double x) const {
    return A0 + x * (A1 + A2 * x);
  }
};

template <class T>
class Polynomial : public Function{
  vector<T> a;
public:
  Polynomial(vector<T> &coefficients) : a(coefficients) { }
  T operator ()(T x) const {
    T total = 0;
    for(int i=0; i < a.size(); ++i)
      total += a[i] * pow(x, i);
    return total;
  }
};

// finds one root between i and e
double root(Function* f, double i, double e) {
  int iterationsLeft = 10000;
  while(iterationsLeft--) {
    double x = (i+e) / 2.0;
    cout << x << endl;
    if(eqlZero((*f)(x))){
      return x;
    }else if((*f)(x) < 0) {
      i = x;
    }else {
      e = x;
    }
  }
}

int main()
{
  vector<double> a(3);
  a[0] = -1.0;
  a[1] = 0.0;
  a[2] = 1.0;
 
  Function* p = new Polynomial<double>(a);
 
  double result = root(p, -10.0, 10.0);
         
  cout << result;
 
	return 0;
} 
