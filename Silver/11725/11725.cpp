#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	// 노드 개수
	int N; cin >> N;

	// 트리 구조를 저장할 인접 리스트
	vector<vector<int>> graph(N + 1);

	// 양방향 간선 입력
	for (int i = 1; i < N; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	vector<bool> visited(N + 1, false); // 방문 여부 체크
	vector<int> answer(N + 1);          // 각 노드의 부모 저장

	// BFS 시작
	queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int start = q.front();
		q.pop();

		for (int num : graph[start]) {
			if (!visited[num]) {
				visited[num] = true;
				answer[num] = start;
				q.push(num);
			}
		}
	}

	// 2번 노드부터 N번 노드까지의 부모 출력
	for (int i = 2; i <= N; ++i) {
		cout << answer[i] << '\n';
	}
}