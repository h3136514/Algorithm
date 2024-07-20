#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
unordered_map<string, int> generesMap;    // 장르별 고유한 인덱스 매핑
unordered_map<int, int> playsMap; //장르(고유한 인덱스)별 총 재생 횟수 매핑
priority_queue<pair<int, int>> q[101];  // 각 장르별 재생 횟수 높은 순으로 정렬
priority_queue<pair<int, int>> music;  //장르별 총 재생 횟수 저장 

// 총 재생 횟수가 가장 많은 순서대로 각 장르별 2곡씩 선정해서 플레이리스트 만들어서 반환(O(NlogN))
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < genres.size(); i++){
        // 장르 매핑이 등록 안되어 있으면 등록(장르별 첫번째로 나온 음악의 인덱스)
        if(generesMap.find(genres[i]) == generesMap.end()){
            generesMap[genres[i]] = i;
        }

        //장르(고유한 인덱스)별 총 재생 횟수 저장
        if(playsMap.find(generesMap[genres[i]]) == playsMap.end())
            playsMap[generesMap[genres[i]]] = plays[i];
        else
            playsMap[generesMap[genres[i]]] += plays[i];
        
        q[generesMap[genres[i]]].push({plays[i], - i}); 
        
    }
    
    // 각 장르별 총 재생 수 저장
    for(auto itr = playsMap.begin(); itr != playsMap.end(); itr++){
        int musicGenereIdx = itr->first;
        int musicPlays = itr->second; 
        music.push({musicPlays, - musicGenereIdx}); //총 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래이므로 -i로 저장(우선순위큐가 내림차순이므로)
    }
    
    // 각 장르별 상위 2개(최대)를 대입
    while(!music.empty()){
        int idx = - music.top().second;
        
        if(q[idx].size() >= 2){
            for(int i = 0; i < 2; i++){
                answer.push_back(- q[idx].top().second);
                q[idx].pop();
            }   
        }else
            answer.push_back(- q[idx].top().second);

        music.pop();
    }
    
    return answer;
}


#include <iostream>
void print(vector<int> vec)
{
    cout << vec[0];
  for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
  cout << endl;
}

int main()
{
    print(solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500})); //출력값 :  1 0 0 1
    return 0;

}

// 우선순위 큐 사용(X), 정렬(sort())메소드 사용 
/*
#include <algorithm>

bool compareGenre(pair<string, int> a, pair<string, int> b) {
  return a.second > b.second;
}

bool compareSong(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  unordered_map<string, vector<pair<int, int>>> genres_dict;
  unordered_map<string, int> play_dict;

  // 장르별 총 재생 횟수와 각 곡의 재생 횟수 저장
  for (int i = 0; i < genres.size(); ++i) {
    genres_dict[genres[i]].push_back({i, plays[i]});
    play_dict[genres[i]] += plays[i];
  }

  // 총 재생 횟수가 많은 장르순으로 정렬
  vector<pair<string, int>> sorted_genres(play_dict.begin(), play_dict.end());
  sort(sorted_genres.begin(), sorted_genres.end(), compareGenre);

  // 각 장르 내에서 노래를 재생 횟수 순으로 정렬해 최대 2곡 까지 선택
  for (auto& genre : sorted_genres) {
    auto& songs = genres_dict[genre.first];
    sort(songs.begin(), songs.end(), compareSong);

    for (int i = 0; i < min(2, (int)songs.size()); ++i) {
      answer.push_back(songs[i].first);
    }
  }

  return answer;
}
*/

