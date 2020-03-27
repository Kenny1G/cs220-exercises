#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool has_dups(vector<char> vec) {
	
	return false;
}

int main() 
{
	vector <char> v;
	for ( char c = 'a'; c < 'i'; c++) v.push_back(c);
	v.insert(v.begin() + 2, 'f');
	for (char c: v) cout << c << " ";
	cout <<endl;
	cout << "does v have duplicates? " << has_dups(v) << endl;
	return 0;
}
