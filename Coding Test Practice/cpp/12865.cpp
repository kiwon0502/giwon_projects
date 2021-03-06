#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int N, K;
int weight[MAX], value[MAX];
int dp[MAX][100010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> weight[i] >> value[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= weight[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}
