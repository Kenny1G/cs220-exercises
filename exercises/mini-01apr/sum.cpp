#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

void sum(const vector<int>& vec, int& result ) {
  for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
	  result += *it;
  }
}

int main() {
  vector<int> v;
  for (int i = 0; i < 87; i = i + 2) {
    v.push_back(i);
  }
  int result = 0;
  sum (v, result);
  cout << "sum of all v's elements is: " << result << endl;
}
