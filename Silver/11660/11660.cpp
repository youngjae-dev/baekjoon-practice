#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N; cin >> N >> M;
	vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));

	// 1-based 벡터를 사용해 표 갱신
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			long long tmp; cin >> tmp;

			// 누적합 직사각형 갱신
			// dp[i][j] = (1,1)부터 (i,j)까지의 합
			// 현재 값 + 위쪽 영역(dp[i-1][j]) + 왼쪽 영역(dp[i][j-1]) - 겹치는 영역(dp[i-1][j-1])
			dp[i][j] = tmp + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	while (M--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 직사각형 구간합 계산
		// (x1,y1)~(x2,y2) = 전체(x2,y2) - 위쪽 영역(x1-1,y2) - 왼쪽 영역(x2,y1-1) + 두 번 빠진 영역(x1-1,y1-1)
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}
}