#include <iostream>
#include <string>
using namespace std;

// ROT13
int main()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c >= 'a' && c <= 'z')
		{
			if (c - 'a' < 13)
			{
				c += 13;
			}
			else
			{
				c -= 13;
			}
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c - 'A' < 13)
			{
				c += 13;
			}
			else 
			{
				c -= 13;
			}
		}
		s[i] = c;
	}
	cout << s << '\n';

	return 0;
}