#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

// 상하좌우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	int N; cin >> N;
	vector<vector<int>> field(N, vector<int>(N, 0)); // N x N 크기의 2차원 지도
	vector<vector<bool>> visited(N, vector<bool>(N, false)); // 집의 방문 여부
	vector<int> connectedComponent; // 연결요소(단지별 요소)

	for (int i = 0; i < N; ++i) {
		string str; cin >> str; // 공백 없이 입력되므로 문자열 입력
		for (int j = 0; j < str.length(); ++j) {
			field[i][j] = str[j] - '0';
		}
	}

	// 모든 좌표로부터 BFS 수행
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			// 집이 존재하고 방문되지 않은 경우
			if(visited[i][j] == false && field[i][j] == 1){

				visited[i][j] = true; // 방문 마킹

				int count = 1; // 한 단지의 집 개수

				// BFS 시작
				queue<pair<int, int>> L;
				L.push({ i,j });
				while (!L.empty()) {
					int x = L.front().first;
					int y = L.front().second;
					L.pop();

					// 상하좌우로 탐색
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						// 유효하지 않은 탐색 범위
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

						// 유효한 집을 찾은 경우 count 증가 후 queue에 push
						if (visited[nx][ny] == false && field[nx][ny] == 1) {
							visited[nx][ny] = true;
							++count;
							L.push({ nx,ny });
						}
					}
				}
				// 한 연결요소(단지)를 찾은 후 벡터에 push
				connectedComponent.push_back(count);
			}
		}
	}
	
	// 연결 요소 개수 출력(단지 수)
	cout << connectedComponent.size() << '\n';

	// 오름차순 정렬 후 출력
	sort(connectedComponent.begin(), connectedComponent.end());
	for (int i = 0; i < connectedComponent.size(); ++i) {
		cout << connectedComponent[i] << '\n';
	}
}