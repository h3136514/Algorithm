#include <iostream>
#include <vector>

using namespace std;

// 카드 색칠
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> v(N);
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    
    // 1. 이미 칠해진 카드들이 유효한지 확인
    for(int i = 0; i < N - 1; i++){
        if(v[i] != 0 && v[i] == v[i + 1]){
            cout << "-1\n";
            return 0;
        }
    }
    
    // 2. 칠해지지 않은 카드를 순회하면서 색칠
    for(int i = 0; i < N; i++){
        if(v[i] == 0){  // 칠해지지 않은 카드
            // 사용할 수 없는 색을 체크
            bool forbidden[4] = {false, false, false, false};
            
            // 이전 카드의 색
            if(i > 0 && v[i - 1] != 0){
                forbidden[v[i - 1]] = true;
            }
            
            // 다음 카드의 색
            if(i < N - 1 && v[i + 1] != 0){
                forbidden[v[i + 1]] = true;
            }
            
            // 사용 가능한 색 중 하나 선택
            for(int color = 1; color <= 3; color++){
                if(!forbidden[color]){
                    v[i] = color;
                    break;
                }
            }
        }
    }
    
    // 3. 최종 검증 (혹시 모를 경우를 대비)
    for(int i = 0; i < N - 1; i++){
        if(v[i] == v[i + 1]){
            cout << "-1\n";
            return 0;
        }
    }
    
    // 4. 결과 출력
    for(int i = 0; i < N; i++){
        cout << v[i];
        if(i < N - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}