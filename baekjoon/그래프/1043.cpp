#include <iostream>
#include <vector>

using namespace std;
int N, M, mNum, num, factNum, parent[51], CNT;
vector<int> V[51];

int find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void union_s(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA < rootB)
        parent[rootB] = rootA;
    else
        parent[rootA] = rootB;
}

// 거짓말
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    cin >> factNum;
    for (int i = 0; i < factNum; i++) {
        cin >> num;
        parent[num] = 0;    // 아는사람은 부모가 0
    }

    for (int i = 1; i <= M; i++) {
        cin >> mNum;
        V[i].resize(mNum);

        cin >> num;
        V[i][0] = num;
        for (int j = 1; j < mNum; j++) {
            cin >> num;
            V[i][j] = num;
           union_s(V[i][j - 1], V[i][j]);   // 부모 연결
        }
    }
    
    CNT = M;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < V[i].size(); j++) {
            if (find(V[i][j]) == 0) {
                CNT--;
                break;
            }
        }
    }
   
    cout << CNT << "\n";

    return 0;
}