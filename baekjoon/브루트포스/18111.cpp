#include <iostream>

using namespace std;
int N, M, B, CNT = 987654321, H, land[501][501];

// 마인크래프트
int main(){
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> land[i][j];
        }
    }

    // 높이를 천천히 올라가며 최소시간과 가장 높은 높이를 확인
    for(int h = 0; h <= 256; h++){
        int build = 0;
        int remove = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int height = land[i][j] - h;
                if(height > 0)
                    remove += height;
                else if(height < 0)
                    build -= height;
            }
        }

        // 지울 블록의 개수 + 처음에 가지고 있던 인벤토리 블록의 개수 >= 채울 블록 개수(갱산가능 조건)
        if(remove + B >= build){
            int cnt = remove * 2 + build;
            if(CNT >= cnt){
                CNT = cnt;
                H = h;
            }
        }    
    }

    cout << CNT << " " << H << "\n";

    return 0;
}