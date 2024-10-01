#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, num, maxNum;
vector<vector<int>> block, tmp;

// 블록 옮기기
void move(vector<vector<int>> v, int r) {
    queue<int> q;  // 줄마다 옮길 불럭들을 저장
    int cnt = 0;
    if(r == 0) {    // 왼쪽 이동
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(v[i][j] != 0)
                    q.push(v[i][j]);
                v[i][j] = 0;
            }
            if(q.empty())
                continue;   
            
            if(q.size() == 1){
                v[i][0] = q.front();
                q.pop();
                continue;
            }
            cnt = 0;
            int a = q.front();
            int b;
            q.pop();
            while(!q.empty()){
                b = q.front();
                q.pop();

                if(a == 0){ // 앞에서 이미 합침
                    a = b;
                    v[i][cnt] = a;
                }else if(a == b) {  // 둘을 합침
                    v[i][cnt++] = a+b;
                    a = 0;
                }else if(a != b) { // 둘이 다름
                    v[i][cnt++] = a;
                    a = b;
                }
            }
            v[i][cnt] = a;
        }
    }else if(r == 1) {    // 오른쪽 이동
        for(int i = 0; i < N; i++) {
            for(int j = N-1; j >= 0; j--) {
                if(v[i][j] != 0)
                    q.push(v[i][j]);
                v[i][j] = 0;
            }
            if(q.empty())
                continue;   
            
            if(q.size() == 1){
                v[i][N-1] = q.front();
                q.pop();
                continue;
            }
            cnt = N-1;
            int a = q.front();
            int b;
            q.pop();
            while(!q.empty()){
                b = q.front();
                q.pop();

                if(a == 0){ // 앞에서 이미 합침
                    a = b;    
                }else if(a == b) {  // 둘을 합침
                    v[i][cnt--] = a+b;
                    a = 0;
                }else if(a != b) { // 둘이 다름
                     v[i][cnt--] = a;
                    a = b;
                }
                v[i][cnt] = a;
            }
        }
    }else if(r == 2) {    // 위쪽 이동
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(v[j][i] != 0)
                    q.push(v[j][i]);
                v[j][i] = 0;
            }
            if(q.empty())
                continue;   
            
            if(q.size() == 1){
                v[0][i] = q.front();
                q.pop();
                continue;
            }
            cnt = 0;
            int a = q.front();
            int b;
            q.pop();
            while(!q.empty()){
                b = q.front();
                q.pop();

                if(a == 0){ // 앞에서 이미 합침
                    a = b;    
                }else if(a == b) {  // 둘을 합침
                    v[cnt++][i] = a+b;
                    a = 0;
                }else if(a != b) { // 둘이 다름
                     v[cnt++][i] = a;
                    a = b;
                }
                v[cnt][i] = a;
            }
        }
    }else {    // 아래쪽 이동
        for(int i = 0; i < N; i++) {
            for(int j = N-1; j >= 0; j--) {
                if(v[j][i] != 0)
                    q.push(v[j][i]);
                v[j][i] = 0;
            }
            if(q.empty())
                continue;   
            
            if(q.size() == 1){
                v[N-1][i] = q.front();
                q.pop();
                continue;
            }
            cnt = N-1;
            int a = q.front();
            int b;
            q.pop();
            while(!q.empty()){
                b = q.front();
                q.pop();

                if(a == 0){ // 앞에서 이미 합침
                    a = b;    
                }else if(a == b) {  // 둘을 합침
                    v[cnt--][i] = a+b;
                    a = 0;
                }else if(a != b) { // 둘이 다름
                     v[cnt--][i] = a;
                    a = b;
                }
                v[cnt][i] = a;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            maxNum = max(maxNum, v[i][j]);
        }
    }

    tmp = v;   //바뀐 보드판 넘겨줌
}

// 게임(백트래킹)
void game(vector<vector<int>> v, int cnt) {
    if(cnt == 5) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        move(v, i);
        game(tmp, cnt + 1);
    }
}

// 2048 (Easy) 
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> n(0);
        for(int j = 0; j < N; j++) {
            cin >> num;
            n.push_back(num);
        }
        block.push_back(n);
    }

    game(block, 0);

    cout << maxNum << "\n";

    return 0;
}
