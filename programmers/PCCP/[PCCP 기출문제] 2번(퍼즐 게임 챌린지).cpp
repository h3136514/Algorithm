#include <string>
#include <vector>

#define INF 987654321
using namespace std;
int answer = INF;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int n = diffs.size();
    
    int s = 1, e = INF;
    while(s <= e){
        int mid = (s+e)/2;
        long long sum = 0;
        sum = times[0];
        for(int i = 1; i < n; i++){
            if(diffs[i] <= mid )
                sum += times[i];
            else{
                sum += (times[i] + times[i-1])*(diffs[i]-mid);
                sum += times[i];
            }
        }
        
        if(sum <= limit){
            answer = min(answer, mid);
            e = mid - 1;
        }else
            s = mid + 1;
    }
    
    return answer;
}