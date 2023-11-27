#include <iostream>
#include <list>
#include "list.h"
using namespace std;


int main() {

  /*list<int> l{1,2,3,5};
  l.resize(10);
  //for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    //(*it) = 7;
  for(auto it = l.rbegin(); it != l.rend(); it++)
    cout<<*it<<" ";*/
  List<int> l1(3,2);
  List<int> l2(5,3);

  cout<<endl;
  for(List<int>::Iterator it = l1.Begin(); it != l1.End(); it++)
    (*it)=7;
  for(auto it = l2.Begin(); it != l2.End(); it++)
    cout<<*it<<" ";
}
