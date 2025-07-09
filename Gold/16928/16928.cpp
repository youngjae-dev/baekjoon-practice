#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> jump(N + M); // 사다리와 뱀 정보를 저장 (출발 , 도착)
	vector<int> map(101);               // 각 칸까지 도달하는 데 필요한 주사위 횟수
	vector<int> visited(101, false);    // 방문 여부 체크 (중복 방문 방지)

	// 사다리와 뱀 정보 입력 받기
	for (int i = 0; i < N + M; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		jump[i] = { tmp1,tmp2 };
	}

	// 1부터 BFS 시작
	queue<int> q;
	visited[1] = true;
	map[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int curr = q.front(); q.pop();

		// 도착 지점(100)에 도달했으면 종료
		if (curr == 100) break;

		// 주사위(1~6) 굴린 후 이동
		for (int i = 1; i <= 6; ++i) {
			int move = curr + i;

			// 이동한 칸에 사다리 또는 뱀이 있을 경우, 해당 위치로 즉시 이동
			for (int j = 0; j < jump.size(); ++j) {
				if (move == jump[j].first) {
					move = jump[j].second;
					break;
				}
			}

			// 100 이내이며 아직 방문하지 않은 칸일 경우
			if (move <= 100 && !visited[move]) {
				visited[move] = true;
				map[move] = map[curr] + 1; // 현재까지 굴린 횟수 + 1
				q.push(move);
			}
		}
	}

	// 목표 지점(100)에 도달 시 주사위 굴린 회수
	cout << map[100];
}