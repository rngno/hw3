#include "stack.h"
#include <iostream>

int main(){
  Stack<int> tester;
  cout << "Empty: " << tester.empty() << endl;
  cout << "Pushing back: " << endl;
  tester.push(1);
  cout << "Top(): " << tester.top() << endl;
  cout << "Size: " << tester.size() << endl;
  cout << "Pop: " << endl;
  tester.pop();
}
