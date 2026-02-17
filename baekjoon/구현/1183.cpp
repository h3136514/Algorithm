#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, A, B;
vector<int> v;

// 약속
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++){
		cin >> A >> B;
		v.push_back(B - A);
	}

	sort(v.begin(), v.end());
	if (N % 2 == 0){
		int mid = N / 2 - 1;
		cout << v[mid+1] - v[mid] + 1 << "\n";
	}else{
		cout << 1 << "\n";
	}
	return 0;
}