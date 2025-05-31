// 큰수
#include <iostream>
#include <string>

using namespace std;
int N;
long long sum, temp, pre, flow;
string c;

// 부호
int main() {
	for (int k = 0; k < 3; k++) {
		sum = 0, flow = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			pre = sum;
			sum = sum + temp;
			if (temp > 0 && pre > 0 && sum < 0) flow++;
			if (temp < 0 && pre < 0 && sum > 0) flow--;
		}

		if (flow == 0) {
			if (sum == 0)
                cout << "0\n";
			else{
                c = (sum > 0 ? '+' : '-');
                cout << c + "\n";
            } 
                
		}
		else {
            c = (flow > 0 ? '+' : '-');
			cout << c + "\n";
		}
	}
}