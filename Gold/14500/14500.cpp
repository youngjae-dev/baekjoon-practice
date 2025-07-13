#include<iostream>
#include<vector>
using namespace std;

// 상하좌우 방향
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 테트로미노로 만들 수 있는 최대 합 저장
int max_num = 0;

// DFS로 가능한 모든 테트로미노 모양 탐색 (T자 제외)
void DFS(int x, int y, int depth, int sum, const vector<vector<int>>& paper, vector<vector<bool>>& visited) {
	if (depth == 4) {
		max_num = max(max_num, sum);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 유효 범위 및 방문 여부 확인
		if (nx < 0 || ny < 0 || nx >= paper.size() || ny >= paper[0].size()) continue;
		if (visited[nx][ny]) continue;

		visited[nx][ny] = true;
		DFS(nx, ny, depth + 1, sum + paper[nx][ny], paper, visited);
		visited[nx][ny] = false; // 백트래킹
	}
}

// DFS로 만들 수 없는 T자 모양 (ㅗ, ㅜ, ㅓ, ㅏ) 예외 처리
void Tshape(int x, int y, const vector<vector<int>>& paper) {
	for (int i = 0; i < 4; ++i) {
		int sum = paper[x][y]; // 중심 칸 포함
		bool isValid = true;

		for (int j = 0; j < 4; ++j) {
			if (j == i) continue; // 4방향 중 하나 제외 → T자 형태

			int nx = x + dx[j];
			int ny = y + dy[j];

			// 범위 벗어나면 해당 T자 모양은 무효
			if (nx < 0 || ny < 0 || nx >= paper.size() || ny >= paper[0].size()) {
				isValid = false;
				break;
			}
			sum += paper[nx][ny];
		}
		if (isValid) max_num = max(max_num, sum);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> paper(N, vector<int>(M));

	// 입력 받기
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> paper[i][j];

	vector<vector<bool>> visited(N, vector<bool>(M, false));

	// 모든 칸에서 DFS 및 T자 탐색 수행
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visited[i][j] = true;
			DFS(i, j, 1, paper[i][j], paper, visited);
			visited[i][j] = false; // 백트래킹
			Tshape(i, j, paper);
		}
	}

	cout << max_num;
}