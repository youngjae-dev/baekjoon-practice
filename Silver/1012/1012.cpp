#include<iostream>
#include<vector>
using namespace std;

// 상하좌우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

// DFS를 통해 연결된 배추 덩어리 수 구하기
void dfs(int y, int x, vector<vector<int>>& v) {

	// 이미 방문헀거나 배추가 없는 경우
	if (v[y][x] == 0) {
		return;
	}
	else {

		// 방문 처리
		v[y][x] = 0;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// vector out of range 에러 예외처리
			if (nx < 0 || ny < 0 || ny >= v.size() || nx >= v[0].size()) continue;

			// 인접한 배추들 방문
			dfs(ny, nx, v);
		}
	}
}

int main() {
	int T; cin >> T;

	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;

		// N행 M열 농장
		vector<vector<int>> farm(N, vector<int>(M, 0));
		int count = 0;

		while (K--) {
			int x, y;
			cin >> y >> x;
			farm[y][x] = 1;
			
		}

		// 농장 전체 순회하면서 배추 덩어리 찾기
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (farm[i][j] == 1) {
					++count;
					dfs(i, j, farm);
				}
			}
		}
		cout << count << '\n';
	}
}