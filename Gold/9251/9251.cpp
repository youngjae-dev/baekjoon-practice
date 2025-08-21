#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// LCS(Longest Common Subsequence, 최장 공통 부분 수열)을 구하는 함수
int LCS(const string& A, const string& B) {
	int A_size = A.length();
	int B_size = B.length();
	vector<vector<int>>dp(A_size + 1, vector<int>(B_size + 1, 0));

	// dp[i][j] = A의 앞 i글자와 B의 앞 j글자의 LCS
	for (int i = 1; i <= A_size; ++i) {
		for (int j = 1; j <= B_size; ++j) {
			// 문자가 같을 경우 : 수열 길이 + 1
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			// 문자가 다를 경우 : 최대 수열 길이 유지
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	// 전체 문자열 A,B의 LCS 길이 반환
	return dp[A_size][B_size];
}

int main() {
	string A, B;
	cin >> A >> B;
	cout << LCS(A, B);
}