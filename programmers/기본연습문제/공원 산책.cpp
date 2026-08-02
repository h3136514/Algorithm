#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int W, H, Sx, Sy;
int offer_X[4] = {1, -1, 0, 0};
int offer_Y[4] = {0, 0, -1, 1};

bool check(int x, int y){
    return x >= 0 && x < W && y >= 0 && y < H; 
}

vector<int> solution(vector<string> park, vector<string> routes) {
    W = park[0].size();
    H = park.size();
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(park[i][j] == 'S'){
                Sx = j;
                Sy = i;
                break;
            }   
        }
    }
    
    for(int i = 0; i < routes.size(); i++){
        int r = 0;
        if(routes[i][0] == 'E')
            r = 0;
        else if(routes[i][0] == 'W')
            r =1;
        else if(routes[i][0] == 'N')
            r =2;
        else
            r = 3;
        
        int d = routes[i][2] -'0';
        int ix = Sx, iy = Sy;
        bool checkMove = true;
        if(r < 2){
            for(int j = 0; j < d; j++){
                ix += offer_X[r];
                if(!check(ix, iy) || park[iy][ix] == 'X'){
                    checkMove = false;
                    break;
                }
            }
        }else{
            for(int j = 0; j < d; j++){
                iy += offer_Y[r];
                if(!check(ix, iy) || park[iy][ix] == 'X'){
                    checkMove = false;
                    break;
                }
            }
        }
        
        if(checkMove)
            Sx = ix, Sy = iy;
    }
    
    answer.push_back(Sy);
    answer.push_back(Sx);
    
    return answer;
}