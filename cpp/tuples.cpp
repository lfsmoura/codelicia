// Copyright 2013 Leonardo Moura
#include <cmath>
#include <iostream>
#include <tuple>
#include <functional>

std::tuple<bool, double> real_sqrt(double x) {
  if (x < 0)
    return std::make_tuple(false, -1);
  else
    return std::make_tuple(true, sqrt(x));
}

// gcc version >= 4.7
template<typename T>
using function_result = std::tuple<bool, T>;

function_result<double> real_sqrt2(double x) {
  if (x < 0)
    return std::make_tuple(false, -1);
  else
    return std::make_tuple(true, sqrt(x));
}

int main() {
  // Tuples are just a ordered set of values of (possibly) different types
  std::tuple<bool, double> tuple {true, 2.0};

  // To get an element of a tuple just use std::get<n>
  // tuples are indexed from zero
  // unlike structs, they are not required to be stored in order
  std::cout << std::get<1>(tuple) << std::endl; // "2"
  std::cout << sqrt(-1) << std::endl; // "-nan"

  // One use of tuples is to return multiple values from functions
  // without using "output parameters" as in C#
  // note the "&&", that means the variable result is reference to a rvalue
  std::tuple<bool, double>&& result = real_sqrt(-2.0);
  if (std::get<0>(result))
    std::cout << std::get<1>(result) << std::endl;
  else
    std::cout << "negative value fed" << std::endl;

  // The standard library provides the function "tie" that
  // conveniently assigns a tuple to different variables
  bool sqrt_succeded;
  double sqrt_result;

  std::tie(sqrt_succeded, sqrt_result) = real_sqrt(2.0);

  // Some values on a tuple can be ignored with the tie function
  std::tie(std::ignore, sqrt_result) = real_sqrt(2.0);

  // the function "tuple_cat" concatenates two or more tuples into one
  std::tuple_cat(std::make_tuple(1,2), std::make_tuple(1,2,3));

  // We define a function result type that generalizes that notion of
  // functions that "fail"
  function_result<double>&& result2 = real_sqrt2(-2);
  if (std::get<0>(result2))
    std::cout << std::get<1>(result2) << std::endl;
  else
    std::cout << "negative value fed" << std::endl;
}
