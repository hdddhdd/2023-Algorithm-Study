#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 배열로 했더니 시간 초과나서
// 벡터로 바꾸고 정렬한 뒤에 하기
// 필요없는 경우 버리기 위해 break; 사용할 수 있는
// while 문 사용
vector<int> a2;

int main(void)
{
    int T = 0;
    cin >> T;
    int a;
    for (int i = 0; i < T; i++)
    {
        cin >> a;
        a2.push_back(a);
    }
    sort(a2.begin(), a2.end());

    int x = 0;
    cin >> x;
    int cnt = 0;
    int left = 0;
    int right = T - 1;
    int sum = 0;
    while (1)
    {
        // 1 2 3 5 7 9 10 11 12
        if (left >=right)
            break;
        sum = a2[left] + a2[right];
        if (sum == x)
        {
            cnt++;
            left++;
            right--;
        }
        else if (sum > x)
        {
            right--;
        }
        else if (sum < x)
        {
            left++;
        }
    }

    cout << cnt << endl;

    return 0;
}