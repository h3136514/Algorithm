#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, i, a, b;
	cin >> t;

	for (i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}