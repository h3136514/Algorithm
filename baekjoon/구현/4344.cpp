#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int T;
double N, sum, result;
vector<int> v;

// 평균은 넘겠지
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        v.resize(N);

        sum = 0;
        for(int i = 0; i < N; i++){
            cin >> v[i];
            sum += v[i];
        }

        sum /= N;
        double cnt = 0;
        for(int i = 0; i < N; i++){
            if(v[i] > sum)
                cnt++;
        }
        result =round(cnt/N*100000)/1000.0;
        cout << fixed;
	    cout.precision(3);
        cout << result << "%\n"; 
        v.clear();
    }

    return 0;
}