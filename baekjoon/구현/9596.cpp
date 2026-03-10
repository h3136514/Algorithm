#include <iostream> 
using namespace std; 

// 돌 게임 2
int main() {
	int N; 
	cin >> N; 

	if (N % 2 == 1) { 
		cout << "CY";
	} 
	
	else {
		cout << "SK"; 
	} 

	return 0;
}