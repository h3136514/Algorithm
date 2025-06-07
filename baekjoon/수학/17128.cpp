// 누적합
#include <iostream>
#include <vector>

using namespace std;
int N, Q, num[200001], commd, result;
vector<int> v, q;

// 소가 정보섬에 올라온 이유
int main(){
    cin >> N >> Q;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    v.resize(N);
    q.resize(Q);
    for(int i = 0; i < Q; i++){
        cin >> q[i];
    }

    for(int i = 0; i < N; i++){
        int idx2 = (i + 1)%N, idx3 = (i + 2)%N, idx4 = (i+3)%N;
        int sum = num[i] * num[idx2] * num[idx3] * num[idx4];

        v[i] = sum;
        //cout << i << ", " << idx2 << ", " << idx3 << ", " << idx4 << "\n";
        result += sum;
    }

    for(int i = 0; i < Q; i++){
        commd = q[i] - 1;
        for(int j = 0; j < 4; j++){
            int idx = (commd - j) < 0 ? N + (commd - j) : (commd - j);
            v[idx] *= -1;
            result += 2*v[idx];
        }

        cout << result << "\n";
    }

    return 0;
}