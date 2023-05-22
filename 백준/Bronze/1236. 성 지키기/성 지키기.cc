#include <iostream>
using namespace std;

int main(void)
{
    int N; // 세로 - row
    int M; // 가로 - col
    string str[100];
    int check[100];
    int row[100];
    int col[100];
    int idx = 0;
    int cnt_row = 0;
    int cnt_col = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    // 행기준
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (str[i][j] == 'X')
            {
                // X가 하나라도 있으면 그 행 or 열 제거
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (row[i] == 0)
        {
            cnt_row++;
        }
    }
    for (int i = 0; i < M; i++)
    {
        if (col[i] == 0)
        {
            cnt_col++;
        }
    }

    // printf("cnt_row: %d, cnt_col: %d\n", cnt_row, cnt_col);

    if (cnt_row >= cnt_col)
    {
        cout << cnt_row << endl;
    }
    else
    {
        cout << cnt_col << endl;
    }

    // 열기준

    return 0;
}