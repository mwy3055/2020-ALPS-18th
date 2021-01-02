
#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[11][100001];
int dp[11][100001]; //dp[i][j] = i��° ����Ʈ��, j��° ���� �Ծ�����, �������� �ִ밪
 
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //���� ����
    for (int i = 1; i <= m; i++){
        dp[i][n] = arr[i][n];

        cout << dp[i][n] << '\n';
    }

    //������ ���� 
    for (int j = n-1; j >= 1; j--)
    {
        for(int i = 1; i <= m; i++){
            int max_cnt = -1;
            for(int k = 1; k <= m; k++){
                if (k == i) max_cnt = max(max_cnt, (dp[i][j+1])/2);
                //������ ���� ����Ʈ�� ������ ��
                else max_cnt = max(max_cnt, dp[k][j+1]);
                //������ �ٸ� ����Ʈ�� ������ �� 
            }
            dp[i][j] = max_cnt + arr[i][j];
        }
    }

    int max_result = -1;

    //ó�� ���ÿ� ���� ��� �� �ִ��� ��� 
    for(int i = 1; i <= m; i++){
        cout << dp[i][1] << '\n';
        max_result = max(max_result, dp[i][1]);
    }

    cout << max_result << '\n';

    return 0;
}
