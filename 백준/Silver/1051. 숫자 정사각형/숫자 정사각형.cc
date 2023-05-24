#include <iostream>
#include <cmath>
using namespace std;

int num_r[51][51] = {0};
int w = 0;
int N;
int M;
int result = 1;
// c: 정사각형 한 변의 길이
int width()
{

    for (int i = 0; i < N; i++)
    { // x좌표 (초기값기준)
        for (int j = 0; j < M; j++)
        { // y좌표 (초기값기준)
            for (int k = 1; k < min(N, M); k++)
            {
                if ((i + k < N && j + k < M) &&
                    (num_r[i][j] == num_r[i][j + k]) &&
                    (num_r[i + k][j] == num_r[i + k][j + k]) &&
                    (num_r[i][j] == num_r[i + k][j + k]))
                {

                    result = max(result, k + 1);
                }
            }
        }
    }
    return result * result;
}

int main(void)
{
    // 꼭짓점에 있는 숫자가 모두 같은 정사각형 중에 크기가 제일 큰거!

    int num[51];

    int num_temp[51];
    cin >> N >> M;

    // 둘 중 더 작은 숫자가 만들 수 있는 정사각형의 최대 크기가 될 것
    int mi = min(N, M); // 3, 5 입력하면 3

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++)
            num_r[i][j] = input[j] - '0';
    }

    int result_width = 0; // 최대 정사각형의 크기

    result_width = width();

    cout << result_width << endl;
    return 0;
}
