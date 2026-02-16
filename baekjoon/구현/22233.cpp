#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;
int N, M;
unordered_set<string> us;
string str, keyword;

// 가희와 키워드
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    while (N--)
    {
        cin >> keyword;
        us.insert(keyword);
    }

    while (M--)
    {
        cin >> str;
        stringstream ss(str);
        while (getline(ss, keyword, ','))
        {
            if (us.find(keyword) == us.end())
            {
                continue;
            }

            us.erase(keyword);
        }

        cout << us.size() << "\n";
    }
    return 0;
}