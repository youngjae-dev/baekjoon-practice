#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<vector<int>> rgbCost(N + 1, vector<int>(3)); // 1~N번 집, 열: 0=R, 1=G, 2=B

	// rgbCost[i][j] = i번 집을 j색(R,G,B)으로 칠하는 비용
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> rgbCost[i][j];
		}
	}

	// dp[i][j] = 1~i번 집을 칠했을 때, i번 집을 j색으로 칠하는 최소 누적 비용
	vector<vector<int>> dp(N + 1, vector<int>(3, 0));

	for (int i = 1; i <= N; ++i) {
		dp[i][0] = rgbCost[i][0] + min(dp[i - 1][1], dp[i - 1][2]); // R: 이전 집이 G,B인 경우 중 최소
		dp[i][1] = rgbCost[i][1] + min(dp[i - 1][0], dp[i - 1][2]); // G: 이전 집이 R,B인 경우 중 최소
		dp[i][2] = rgbCost[i][2] + min(dp[i - 1][0], dp[i - 1][1]); // B: 이전 집이 R,G인 경우 중 최소
	}

	// N번째 집을 R, G, B로 칠했을 때의 최소 비용 중 최솟값 출력
	cout << min({ dp[N][0], dp[N][1], dp[N][2] });
}