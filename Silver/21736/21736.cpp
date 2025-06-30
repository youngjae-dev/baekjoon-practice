#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 이동 방향 : 상, 하, 좌, 우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
	int N, M; // N x M 크기의 대학 캠퍼스
	cin >> N >> M;

	vector<vector<char>>campus(N, vector<char>(M, ' ')); // N x M 크기의 벡터를 ' '로 초기화

	int startPlace_X = 0, startPlace_Y = 0; // 도연이의 시작 위치

	// 공간입력
	// O : 빈 공간 | X : 벽 | I : 도연이 | P : 사람
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				startPlace_X = i;
				startPlace_Y = j;
			}
		}
	}
	int meetCount = 0; // 만난 사람의 수

	queue<pair<int, int>> L;
	L.push({ startPlace_X, startPlace_Y });

	// BFS 탐색 시작
	while (!L.empty()) {
		// 탐색 시작 위치 갱신
		int x = L.front().first; int y = L.front().second; L.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위 밖으로 나간 좌표는 무시
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			// 도연이가 사람을 만난 경우
			if (campus[nx][ny] == 'P') {
				campus[nx][ny] = 'I'; // 도연이가 지나간 자리 마킹
				L.push({ nx,ny });
				++meetCount;
			}

			// 사람이 있지는 않지만, 이동 가능
			else if (campus[nx][ny] == 'O') {
				campus[nx][ny] = 'I'; // 도연이가 지나간 자리 마킹
				L.push({ nx,ny });
			}
		}
	}

	// 못 만났을 경우 TT 출력
	if (meetCount == 0) {
		cout << "TT";
	}

	// 만난 경우 만난 사람의 수 출력
	else {
		cout << meetCount;
	}
}