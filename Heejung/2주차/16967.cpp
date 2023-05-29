#include <iostream>
using namespace std;
int B[601][601];
int main()
{
    // 입력받기
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    
    for (int i = 1; i <= h + x; i++)
    {
        for (int j = 1; j <= w + y; j++)
        {
            cin >> B[i][j];
        }
    }

    //기존 배열에 복원
    for (int i=x+1; i<=h; i++)
    {
        for (int j = y+1; j <=w; j++){
            B[i][j] = B[i][j] - B[i-x][j-y];
        }
    }

    

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
