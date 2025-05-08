#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, num, startNum, endNum, mid;
long long sum, half, tmpSum;
vector<int> server;

// 서버실
int main(){
    cin >> N;
    
    for(int i = 0; i < N*N; i++){
        cin >> num;
        sum += num;
        server.push_back(num);
    }
    half = (sum % 2 == 0) ? sum/2 : sum/2 + 1;

    sort(server.begin(), server.end());

    sum = 0;
    endNum = server[N*N -1];
    while(startNum < endNum){
        mid = (startNum + endNum) / 2;

        for(int i = 0; i < server.size(); i++){
            if(server[i] >= mid)
                tmpSum += mid;
            else
                tmpSum += server[i];
        }

        if(tmpSum >= half){
            endNum = mid;
        }else{
            startNum = mid + 1;
        }

        tmpSum = 0;
    }

    cout << endNum << "\n";

    return 0;
}