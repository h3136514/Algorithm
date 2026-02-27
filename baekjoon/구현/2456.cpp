#include <iostream>
#include <vector>

using namespace std;

int score_sum[4];
int added_score[4][4]; // added_score[점수][학생]

// 나는 학급회장이다
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    while (N--)
    {
        for (int i = 1; i <= 3; i++)
        {
            int value;
            cin >> value;
            score_sum[i] += value;
            added_score[value][i] += 1;
        }
    }

    int max_index = 1;
    int max_score = score_sum[1];

    for (int i = 1; i <= 3; i++)
    {
        if (max_score < score_sum[i])
        {
            max_score = score_sum[i];
            max_index = i;
        }
        else if (max_score == score_sum[i])
        {
            max_index = i;
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        if (max_index == 0)
            break;
        if (max_index == i)
            continue;
        if (score_sum[i] == max_score)
        {
            if (added_score[3][i] > added_score[3][max_index])
            {
                max_index = i;
            }
            else if (added_score[3][i] == added_score[3][max_index])
            {
                if (added_score[2][i] > added_score[2][max_index])
                    max_index = i;
                else if (added_score[2][i] == added_score[2][max_index])
                    max_index = 0;
            }
        }
    }

    cout << max_index << " " << max_score << '\n';

    return 0;
}