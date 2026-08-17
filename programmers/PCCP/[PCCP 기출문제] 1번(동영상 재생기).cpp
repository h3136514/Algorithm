#include <string>
#include <vector>

using namespace std;

long long ConvertIntSecond(string str)
{
    int find = str.find(':');
    return  stoi(str.substr(0, find)) * 60 + stoi(str.substr(find + 1));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 시간을 초로 바꿈
    long long _len = ConvertIntSecond(video_len);
    long long _pos = ConvertIntSecond(pos);
    long long _op_start = ConvertIntSecond(op_start);
    long long _op_end = ConvertIntSecond(op_end);
    
    for(auto a : commands)
    {
    	// 현재 시간이 오프닝 중이라면 오프닝 끝으로 보냄
        if(_op_start <= _pos && _pos < _op_end ) _pos = _op_end; 
        
        if(a == "prev")
        {
            _pos -= 10;
          
            if(_pos < 0) _pos = 0;
        }  
        else 
        {
            _pos += 10;
            
            if(_len < _pos ) _pos = _len; 
        }
        
        // 현재 시간이 오프닝 중이라면 오프닝 끝으로 보냄
        if(_op_start <= _pos && _pos < _op_end ) _pos = _op_end;
    }
    
    // 분과 초로 다시 바꿔줌
    int m = _pos / 60; 
    int s = _pos % 60; 
    string _m = to_string(m);
    string _s = to_string(s);
    
    // 두자리 수로 만들어 answer에 삽입
    answer += m < 10 ? "0" + _m : _m;
    answer += ":";
    answer += s < 10 ? "0" + _s : _s;
    
    return answer;
}