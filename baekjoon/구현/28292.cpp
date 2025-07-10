#include <iostream>

using namespace std;
int N;

int main() {
	cin >> N;
	if (N < 3)
        cout << 1 << "\n";
	else if (N < 6)
        cout << 2 << "\n";
	else
        cout << 3 << "\n";

    return 0;
}