#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 정렬 기준:
// 1. 종료 시간이 빠른 순
// 2. 종료 시간이 같다면 시작 시간이 빠른 순
struct Comp {
	bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
		if (lhs.second == rhs.second) return lhs.first < rhs.first;
		return lhs.second < rhs.second;
	}
};

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v;

	// N개의 회의의 시작/종료 시간 입력
	while (N--) {
		int startTime, endTime;
		cin >> startTime >> endTime;
		v.push_back({ startTime, endTime });
	}

	// 회의들을 종료 시간이 빠른 순으로 정렬
	sort(v.begin(), v.end(), Comp());

	vector<pair<int, int>> result;
	result.push_back(v[0]);  // 첫 번째 회의는 무조건 선택

	// 각 회의가 직전 선택된 회의와 겹치지 않으면 선택
	for (int i = 1; i < v.size(); ++i) {
		if (result.back().second <= v[i].first) {
			result.push_back(v[i]);
		}
	}

	cout << result.size();  // 선택된 회의의 수 출력
}
