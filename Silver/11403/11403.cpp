#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BFS 수행 함수
// startIndex : 시작 정점
// matrix : 입력 인접 행렬
// result : 도달 가능한 경로 기록
void BFS(int startIndex, const vector<vector<int>>& matrix, vector<vector<int>>& result) {
	int size = matrix.size();
	vector<bool> visited(size, false);

	queue<int> L;
	L.push(startIndex);

	while (!L.empty()) {
		int start = L.front(); L.pop();

		for (int i = 0; i < size; ++i) {
            // 경로가 존재하고 아직 방문하지 않은 정점이면
			if (matrix[start][i] == 1 && visited[i] == false) {
				L.push(i);
				visited[i] = true;
				result[startIndex][i] = 1; // 시작 정점 -> i 경로 존재
			}
		}
	}
}

int main() {
	int N; cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N, 0));
    vector<vector<int>> result(N, vector<int>(N, 0)); // result[i][j] = i->j 경로 존재 여부

    // 인접 행렬 입력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
	}

    // 각 정점에서 BFS 수행
	for (int i = 0; i < N; ++i) {
		BFS(i, matrix, result);
	}

    // 결과 출력
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}