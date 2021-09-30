#include "LinkedList.hxx"
#include <cassert>
#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <string>
#include <sstream>


int main(int argc, char *argv[]) {

  LinkedList<int>s1;
   s1.sort_insert(546);
   s1.sort_insert(0);
   s1.sort_insert(45);
   s1.sort_insert(8);
   s1.sort_insert(7);
   s1.sort_insert(6222);
   s1.sort_insert(23);
   s1.sort_insert(11);
   s1.sort_insert(15251521);
   s1.sort_insert(122);
   s1.sort_insert(33);
   s1.sort_insert(6222);
   s1.sort_insert(0);

   for(auto a : s1){
      std::cout<<a<<" ";
   }
  return 0;
}