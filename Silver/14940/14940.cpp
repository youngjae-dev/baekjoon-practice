#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 상하좌우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 목표 지점에서 시작하는 BFS
void BFS(const vector<vector<int>>& field, pair<int,int> goal, vector<vector<int>>& result) {
	int col = field.size();    // 세로
	int row = field[0].size(); // 가로

	vector<vector<bool>>visited(col, vector<bool>(row, false));

	queue<pair<int, int>> L;
	visited[goal.first][goal.second] = true;
	result[goal.first][goal.second] = 0;
	L.push(goal);

	// BFS 시작
	while (!L.empty()) {
		pair<int, int> curr = L.front(); L.pop();
		int x = curr.first;
		int y = curr.second;

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위를 벗어난 경우
			if (nx<0 || ny<0 || nx>=col || ny>=row) continue;

			// 방문했거나 이동 불가한 땅
			if (visited[nx][ny] || field[nx][ny] == 0) continue;
			
			visited[nx][ny] = true;
			result[nx][ny] = result[x][y] + 1;
			L.push({ nx,ny });
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>>field(N, vector<int>(M, 0));   // N x M 크기의 지도
	vector<vector<int>>result(N, vector<int>(M, -1));
	pair<int, int> goal;
	
	// 지도 입력
	// 0 : 벽
	// 1 : 길
	// 2 : 목표 지점
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> field[i][j];

			// 목표지점 별도 저장
			if (field[i][j] == 2) {
				goal.first = i;
				goal.second = j;
			}

			// 갈 수 없는 땅 별도 저장
			else if (field[i][j] == 0) {
				result[i][j] = 0;
			}
		}
	}

	// BFS 수행
	BFS(field, goal, result);

	// 최단 거리 결과 출력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}