#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
vector<int> rock;

int solution(int distance, vector<int> rocks, int n) {
    rock = rocks;

    sort(rock.begin(), rock.end());

    
    int s = 0, e = distance;
    while(s <= e){
        int mid = (s+e)/2;
        int cnt = 0;
        int pre = 0;
        
        for(int i = 0; i < rock.size(); i++){
            if(rock[i] - pre < mid)
                cnt++;
            else
                pre = rock[i];   
        }
        if(distance - pre < mid){
            cnt++;
        }
        
        if(cnt <= n){   // 바위 사이 거리의 최솟값을 mid로 할 수 있을 경우
            answer = max(answer, mid);
            
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        
    }
    
    return answer;
}