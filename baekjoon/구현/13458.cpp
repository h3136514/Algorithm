#include <iostream>
#include <vector>

using namespace std;
int N, B, C;
long long sum;
vector<int> V;

// 시험 감독
int main(){
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
    cin >> B >> C;

    for(int i = 0; i < N; i++){
        if(V[i] <= B){
            sum++;
            continue;
        }

        sum++;
        V[i] -= B;
        sum += V[i]/C;

        if( V[i]%C != 0)
            sum++;
    }

    cout << sum << "\n";

    return 0;
}