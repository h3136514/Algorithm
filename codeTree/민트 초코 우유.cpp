#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
char board[51][51];
int N, T, holyBoard[51][51], visitied[51][51], holyVisitied[51][51];
bool likeBoard[51][51][3];
int totall[8];
int offer_X[4] = {0, 0, -1, 1};
int offer_Y[4] = {-1, 1, 0, 0};
vector<pair<int, int>> oneLike, twoLike, threeLike;
map<pair<int, int>, vector<pair<int, int>>> group;
queue<pair<int, int>> q;
priority_queue<pair<int, pair<int, int>>> present;
vector<pair<int, int>> v;

bool check(int x, int y){
    return x > 0 && x <= N && y > 0 && y <= N; 
}

bool checkLike(int x1, int y1, int x2, int y2){
    return (likeBoard[y1][x1][0] == likeBoard[y2][x2][0]) && (likeBoard[y1][x1][1] == likeBoard[y2][x2][1]) && (likeBoard[y1][x1][2] == likeBoard[y2][x2][2]);
}

void priHoly(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << holyBoard[i][j] << " ";
        }
        cout << "\n";
    }
}

void priLike(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(likeBoard[i][j][0] && likeBoard[i][j][1] && likeBoard[i][j][2])
               cout << "1 ";
            else if(likeBoard[i][j][0] && likeBoard[i][j][1]){
                cout << "2 ";
            }else if(likeBoard[i][j][0] && likeBoard[i][j][2]){
                cout << "3 ";
            }else if(likeBoard[i][j][1] && likeBoard[i][j][2]){
                cout << "4 ";
            }else if(likeBoard[i][j][2]){
                cout << "5 ";
            }else if(likeBoard[i][j][1]){
                cout << "6 ";
            }else
                cout << "7 ";
        }
        cout << "\n";
    }
}


void init(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            visitied[i][j] = 0;
            holyVisitied[i][j] = 0;
        }
    }

    for(int i = 1; i <= 7; i++)
        totall[i] = 0;
    
    group.clear();
    oneLike.clear();
    twoLike.clear();
    threeLike.clear();

    while(!present.empty())
        present.pop();
}

// 신암심 추가
void spreadHoly(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           holyBoard[i][j]++;
        }
    }
}

void bfs(int startX, int startY){
    v.clear();

    visitied[startY][startX] = 1;
    q.push({startX, startY});
    v.push_back({startX, startY});
   
    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && checkLike(startX, startY, ix, iy) && !visitied[iy][ix]){
                visitied[iy][ix] = 1;
                q.push({ix, iy});
                v.push_back({ix, iy});
            }
        }
    }
  

    // 대표자 선정
    for(int i = 0; i < v.size(); i++){
        int ix = v[i].first;
        int iy = v[i].second;
        int ih = holyBoard[iy][ix];

        present.push({ih, {-iy, -ix}});
    }

    int presentX = -present.top().second.second;
    int presentY = -present.top().second.first;
    present.pop();
    // 신앙심 넘기기
     holyBoard[presentY][presentX] += present.size();
    while(!present.empty()){
        int ix = -present.top().second.second;
        int iy = -present.top().second.first;
        present.pop();
        holyBoard[iy][ix]--;
    }

    // 그룹 추가
    int food = 0;
    for(int i = 0; i < 3; i++){
        if(likeBoard[startY][startX][i])
            food++;
    }

    if(food == 1){
        oneLike.push_back({presentX, presentY});
    }else if(food == 2){
        twoLike.push_back({presentX, presentY});
    }else{
        threeLike.push_back({presentX, presentY});
    }
}

// 그룹형성
void makeGroub(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(!visitied[i][j]){
                bfs(j, i);
            }
        }
    }
}

// 아침
void moning(){
    spreadHoly();
}

// 점심
void lunch(){
    makeGroub();
}

// 전파 시작
void spread(int x, int y, int d, int sum){
    int ix = x;
    int iy = y;
    while(true){
        ix += offer_X[d];
        iy += offer_Y[d];
        if(!check(ix, iy))
            break;

        int ih = holyBoard[iy][ix];

        if(checkLike(x, y, ix, iy))
            continue;
        
        if(sum > ih){   // 강한 전파
            sum -= (ih+1);
            for(int i = 0; i < 3; i++){
                likeBoard[iy][ix][i] =likeBoard[y][x][i];
            }

            holyBoard[iy][ix]++;
        }else{  // 약한 전파
            holyBoard[iy][ix] += sum;
            sum = 0;

            for(int i = 0; i < 3; i++){
                if(likeBoard[iy][ix][i] || likeBoard[y][x][i])
                    likeBoard[iy][ix][i] = true;
            }

        }
        holyVisitied[iy][ix] = 1; // 전파당함

        if(sum <= 0)
            break;
        
    }
}

// 그룹에서 선텍
void choiceTarget(){
     //선택
    while(!present.empty()){
        int ix = -present.top().second.second;
        int iy = -present.top().second.first;
        int ih = present.top().first;
        present.pop();
        // 방어모드
        if(holyVisitied[iy][ix])
            continue;

        int d = holyBoard[iy][ix] % 4;
        int holySum = holyBoard[iy][ix] - 1;
        holyBoard[iy][ix] = 1;
       // cout << "퍼지기\n";
        //cout << ix << ", "<< iy << " " << d << holySum <<"\n";
        spread(ix, iy, d, holySum);
    }
}

// 단일 그룹 전파 
void oneSpread(){
    for(int i = 0; i < oneLike.size(); i++){
        int ix = oneLike[i].first;
        int iy = oneLike[i].second;
        int ih = holyBoard[iy][ix];

        present.push({ih, {-iy, -ix}});
    }

    choiceTarget();

}
 // 이중 그룹 전파 
void twoSpread(){
    for(int i = 0; i < twoLike.size(); i++){
        int ix = twoLike[i].first;
        int iy = twoLike[i].second;
        int ih = holyBoard[iy][ix];

        present.push({ih, {-iy, -ix}});
    }

    choiceTarget();
}

 // 심층 그룹 전파 
void threeSpread(){
    for(int i = 0; i < threeLike.size(); i++){
        int ix = threeLike[i].first;
        int iy = threeLike[i].second;
        int ih = holyBoard[iy][ix];

        present.push({ih, {-iy, -ix}});
    }

    choiceTarget();
}

// 계산
void cal(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(likeBoard[i][j][0] && likeBoard[i][j][1] && likeBoard[i][j][2])
                totall[1] += holyBoard[i][j];
            else if(likeBoard[i][j][0] && likeBoard[i][j][1]){
                totall[2] += holyBoard[i][j];
            }else if(likeBoard[i][j][0] && likeBoard[i][j][2]){
                totall[3] += holyBoard[i][j];
            }else if(likeBoard[i][j][1] && likeBoard[i][j][2]){
                totall[4] += holyBoard[i][j];
            }else if(likeBoard[i][j][2]){
                totall[5] += holyBoard[i][j];
            }else if(likeBoard[i][j][1]){
                totall[6] += holyBoard[i][j];
            }else
                totall[7] += holyBoard[i][j];
        }
    }
}

// 저녁
void dinner(){
    oneSpread();
    //cout <<"단일 완료\n";
    twoSpread();
    //cout <<"이중 완료\n";
    threeSpread();
   // cout <<"심층 완료\n";

    cal();

    for(int i = 1; i <= 7; i++){
        cout << totall[i] << " ";
    }
    cout << "\n";
}


int main(){
    cin >> N >> T;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           cin >> board[i][j];
           if(board[i][j] == 'T')
                likeBoard[i][j][0] = true;
            else if(board[i][j] == 'C')
                likeBoard[i][j][1] = true;
            else
                likeBoard[i][j][2] = true;
        }
    }

   for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
           cin >> holyBoard[i][j];
        }
    }

 
    while(T--){
        moning();
        //cout <<"아침완료\n";
        lunch();
        //cout <<"점심완료\n";
        dinner();
        //cout <<"저녁완료\n";

        //priHoly();
       //priLike();
        init();
    }
    return 0;
}

