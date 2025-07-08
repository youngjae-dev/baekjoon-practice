#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 상하좌우 방향 벡터
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// mode: 1 - 일반 시각, 2 - 적록색약 시각
// BFS 수행 후 연결 요소 개수를 반환하는 함수
int BFS(const vector<vector<char>>& grid, int mode) {
	int size = grid.size();
	vector<vector<bool>> visited(size, vector<bool>(size, false));
	int connectedComponent = 0;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (visited[i][j]) continue;

			char c = grid[i][j];
			queue<pair<int, int>> q;
			visited[i][j] = true;
			q.push({ i, j });

			// 새로운 연결 요소 탐색 시작
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				// 4방향 탐색
				for (int d = 0; d < 4; ++d) {
					int nx = x + dx[d];
					int ny = y + dy[d];

					// 유효 범위를 벗어나면 무시
					if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue;

					// 일반 시각일 경우: 정확히 같은 색만 인접
					if (mode == 1) {
						if (!visited[nx][ny] && grid[nx][ny] == c) {
							visited[nx][ny] = true;
							q.push({ nx, ny });
						}
					}

					// 적록색약 시각일 경우: R과 G는 같은 색으로 간주
					else {
						if (!visited[nx][ny]) {
							if (c == 'B' && grid[nx][ny] == 'B') {
								visited[nx][ny] = true;
								q.push({ nx, ny });
							}
							else if ((c == 'R' || c == 'G') && (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
								visited[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
				}
			}
			++connectedComponent;
		}
	}
	return connectedComponent;
}

int main() {
	int N;
	cin >> N;
	vector<vector<char>> grid(N, vector<char>(N));

	// 색상 정보 입력 받기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> grid[i][j];
		}
	}

	// 출력: 일반인 시각, 적록색약 시각
	cout << BFS(grid, 1) << ' ' << BFS(grid, 2);
}