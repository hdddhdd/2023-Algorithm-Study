#include <iostream>
#include <string>
using namespace std;
int strike = 0;
int ball = 0;
int result[1000] = {0};
// a는 입력값, b는 비교값(123~987)
int check(string a, int k)
{
    string b = to_string(k);
    // cout << "b: " << b << endl;
    //  strike 판단

    for (int i = 0; i < 3; i++)
    {
        if (a[i] == b[i])
        {
            strike = strike + 1;

            // cout << "strike: " << strike << endl;
        }
    }

    // ball 판단

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                if (a[i] == b[j])
                {
                    ball = ball + 1;
                }
            }
        }
    }

    // cout << "strike: " << strike << endl;
    // cout << "ball: " << ball << endl;

    return 0;
}
int main()
{

    int N;
    cin >> N;

    string ans[100];
    int s[100];
    int b[100];

    for (int i = 0; i < N; i++)
    {
        cin >> ans[i];
        cin >> s[i];
        cin >> b[i];
    }

    string jj;
    for (int i = 0; i < N; i++)
    {
        for (int j = 123; j <= 987; j++)
        {
            jj = to_string(j);

            // 0포함되는 경우 제외 (두 자리 같은 경우도 제외)

            // npos랑 같지 않다면 찾는 문자 =0이 존재하는거 (같아야 0 없는 경우임.)
            // 0없으면서 같은 것도 없는 경우
            if ((jj.find("0") == string::npos) && (jj[0] != jj[1] && jj[0] != jj[2] && jj[1] != jj[2]))
            {
                // cout << "j: " << j <<endl;
                check(ans[i], j);
                if (strike == s[i] && ball == b[i])
                { // result [ 100] = N이되면 걔만 카운트하는게 나을지도?
                    result[j]++;
                }
                strike = 0;
                ball = 0;
            }
        }
    }
    int cnt = 0;

    for (int i = 0; i < 1000; i++)
    {
        // cout<<result[i] <<endl;
        if (result[i] == N)
        {
            // cout << "i: " << i << endl;
            //  cout << "result[i]: " << result[i] << endl;
            cnt = cnt + 1;
        }
    }

    // cout << result[324] << " " <<result[328] << endl;

    cout << cnt << endl;
    return 0;
}
