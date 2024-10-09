#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INF 987654321
using namespace std;
int Q, N, M, v, u, w, id, revenue, dest, command, dp[2001], isValid[30001];
vector<pair<int, int>> V[2001];
priority_queue<pair<int, int>> q;
priority_queue<pair<int, pair<int, int>>> product;  // 최적의 여행 상품 순서
map<int, pair<int,int>> m;  // 여행 상품들
/*
void printDp(){
    for(int i = 0; i < N; i++){
        cout << dp[i] << " ";
    }
}

void printMap(){
    cout << "------------" << "\n ";
    for(auto p : m){
        cout << p.first << " " <<p.second.first << " " <<p.second.second <<"\n" ;
    }
    cout << "------------" << "\n ";
}
*/
// 초기화
void init(){
    for(int i = 0; i < N; i++){
        dp[i] = INF;
    }
}

// 다익스트라 (출발점 부터 모든 도시의 최단경로를 파악)
void dijsktra(int start){
    q.push({0, start});  //시작 점 삽입
    dp[start] = 0;

    while(!q.empty()){
        int currentCost = -q.top().first;
        int currentX = q.top().second;
        q.pop();

        if(dp[currentX] < currentCost)
            continue;

        for(int i = 0; i < V[currentX].size(); i++){
            int ix = V[currentX][i].first;
            int icost = currentCost + V[currentX][i].second;

            if(dp[ix] > icost){
                dp[ix] = icost;
                q.push({-icost, ix});
            }
        }
    }
}

// 코드트리 투어
int main(){
    cin >> Q;
    while(Q--){
        cin >> command;

        if(command == 100){ // 랜드 건설
            cin >> N >> M;
            for(int i= 0; i < M; i++){
                cin >> v >> u >> w;
                if(u==v)    // 싸이클 방지
                    continue;

                V[v].push_back({u, w});
                V[u].push_back({v, w});
            }

            init();
            dijsktra(0);
        }else if(command == 200){   // 여행 상품 생성
            cin >> id >> revenue >> dest;
            
            m[id] = {revenue, dest};
            isValid[id] = 1; // 상품 등록 완료

            if(dp[dest] > revenue) // 판매 불가
                continue;
            
            product.push({(revenue - dp[dest]), {-id, dest}});    // 판매 가능 상품 등록
        }else if(command == 300){ // 여행 상품 취소
            cin >> id;

            m.erase(id);
            isValid[id] = 0; // 상품 등록 취소

        }else if(command == 400) {  // 최적의 여행 상품 판매
            bool isBe = false;
            while(!product.empty()){
                id = -product.top().second.first;
                product.pop();

                if(isValid[id]){
                    cout << id <<"\n";
                    m.erase(id);
                    isValid[id] = 0;

                    isBe = true;
                    break;
                }
            }

            if(!isBe)
                cout << -1 <<"\n";
        }else if(command == 500){
            cin >> u;
            init();
            dijsktra(u);

            while(!product.empty())
                product.pop();

            for(auto p : m){
                id = p.first;
                revenue = p.second.first;
                dest = p.second.second;

                if(dp[dest] > revenue) // 판매 불가
                    continue;

                product.push({(revenue - dp[dest]), {-id, dest}});    // 판매 가능 상품 재등록
            }
        }
    }

    return 0;
}
