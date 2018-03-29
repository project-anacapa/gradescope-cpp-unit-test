#include "arrayFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int sum(int a, int b) {
  return a+b;
}


int prod(int a, int b) {
  return a*b;
}

int pow(int a, int b) {
  return a^b; // wrong
}


int main() {

  
  ASSERT_EQUALS( 3, sum(1,2));
  ASSERT_EQUALS( 14, prod(7,2));
  ASSERT_EQUALS( 128, pow(2,7));

  return 0;
}
