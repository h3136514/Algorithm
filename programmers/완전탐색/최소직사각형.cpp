#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int bigN, smallM;

// 모든 명함의 가로 길이와 세로 길이를 나타내는 2차원 배열 sizes가 주어질 때 모든 명함을 수납할 수 있는 가장 작은 지갑을 만들 때, 지갑의 크기를 반환
int solution(vector<vector<int>> sizes) {
    for(int i = 0; i <sizes.size(); i++){
        sort(sizes[i].begin(), sizes[i].end());  // 오른차순 정렬
        smallM = max(smallM, sizes[i][0]); // 최소 필요 길이
        bigN = max(bigN, sizes[i][1]);  // 최대 필요 길이
    }
    
    int answer = smallM * bigN;
    
    return answer;
}

// 정렬없이
/*
int solution(vector<vector<int>> sizes)
{
    int answer=0;

    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }
    answer=w*h;

    return answer;
}
*/