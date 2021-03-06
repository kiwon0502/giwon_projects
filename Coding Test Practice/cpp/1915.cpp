#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int arr[1010][1010];
int dp[1010][1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin>>s;
        for (int j = 0; j < m; j++) {
            arr[i][j+1] = s[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1) dp[i][j] = arr[i][j];
            else if (arr[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout<<(ans * ans);

    return 0;
}