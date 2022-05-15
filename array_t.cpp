#include "array_t.h"

int main() {
  std::vector<int> a0 = {1,2,3,4,5,6};
  array_t arr;
  int n = arr.s(a0,1);
  std::cout << "the nums is "<< n << std::endl;

  std::vector<int> a1 = {1,2,2,2,2,6};  
  int n1 = arr.s1(a1,1);
  std::cout << "the nums is "<< n1 << std::endl;

  std::vector<int> a2 = {-2,-1,0,1,3};
  std::vector<int> v2 = arr.s2(a2);
  std::cout << "this array is: " << std::endl;
  for(std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
      std::cout << *it <<std::endl;
  }

  std::vector<int> a3 = {1,2,3,4,5,6,7,8,9};
  int n2 = arr.s3(a3,10);
  std::cout << "this nums is " << n2 << std::endl;
  return 0;
}
