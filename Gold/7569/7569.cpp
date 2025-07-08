#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 위, 아래, 앞, 뒤, 왼쪽, 오른쪽
int dz[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0,0,0,-1,1 };

int main() {
	int M, N, H;
	cin >> M >> N >> H; // M: 가로 칸 수, N: 세로 칸 수, H: 높이

	// 3차원 박스 : boxes[높이][세로][가로]
	vector<vector<vector<int>>> boxes(H, vector<vector<int>>(N, vector<int>(M, 0)));
	queue<pair<int, pair<int, int>>> tomato; // 익은 토마토 좌표를 담을 큐

	// 입력 받으며 익은 토마토는 큐에 삽입
	for (int z = 0; z < H; ++z) {
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < M; ++y) {
				cin >> boxes[z][x][y];
				if (boxes[z][x][y] == 1) {
					tomato.push({ z, {x, y} });
				}
			}
		}
	}

	// 모든 익은 토마토를 시작점으로 BFS 수행
	while (!tomato.empty()) {
		int z = tomato.front().first;
		int x = tomato.front().second.first;
		int y = tomato.front().second.second;
		tomato.pop();

		// 6방향(위, 아래, 앞, 뒤, 왼쪽, 오른쪽) 인접 칸 탐색
		for (int i = 0; i < 6; ++i) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 박스 범위 밖이면 무시
			if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;

			// 안 익은 토마토일 경우
			// 익은 날짜 = 이전 날짜 + 1
			if (boxes[nz][nx][ny] == 0) {
				boxes[nz][nx][ny] = boxes[z][x][y] + 1;
				tomato.push({ nz, {nx, ny} });
			}
		}
	}

	int date = 0;

	// 결과 처리
	for (int z = 0; z < H; ++z) {
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < M; ++y) {
				// 안 익은 토마토가 있을 경우 -1 출력 후 종료
				if (boxes[z][x][y] == 0) {
					cout << -1;
					return 0;
				}
				// 가장 늦게 익은 날짜를 저장
				date = max(date, boxes[z][x][y]);
			}
		}
	}

	// 첫날을 1로 시작했으므로, 최종 일수는 date - 1
	cout << date - 1 << '\n';
}
