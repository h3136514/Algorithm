#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i;
	string s1;
	cin >> s1;
	for (i = 0; i < s1.size(); i++)
		s1[i] -= 32;

	cout << s1 << endl;
	return 0;
}