#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<vector<int>> sticker(2, vector<int>(N, 0));

		// 각 스티커의 점수 갱신
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> sticker[i][j];
			}
		}

		// 다이나믹 프로그래밍
		vector<vector<int>>dp(3, vector<int>(N, 0));
		// dp[0][i] : i번째 열에서 스티커를 고르지 않았을 때의 최대 점수
		// dp[1][i] : i번째 열에서 위쪽 스티커를 고른 경우의 최대 점수
		// dp[2][i] : i번째 열에서 아래쪽 스티커를 고른 경우의 최대 점수

		// 베이스 케이스 (0번째 열)
		dp[0][0] = 0;              // 아무 것도 고르지 않음 -> 점수 0
		dp[1][0] = sticker[0][0];  // 위쪽 스티커 선택
		dp[2][0] = sticker[1][0];  // 아래쪽 스티커 선택

		for (int i = 1; i < N; ++i) {
			// i번째 열에서 선택하지 않는 경우 -> 이전 열의 어떤 상태든 가능
			dp[0][i] = max({ dp[0][i - 1], dp[1][i - 1], dp[2][i - 1] });

			// i번째 열에서 위쪽 스티커를 고르면 -> 이전 열은 아래쪽 or 선택X
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + sticker[0][i];

			// i번째 열에서 아래쪽 스티커를 고르면 -> 이전 열은 위쪽 or 선택X
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + sticker[1][i];
		}
	}
}