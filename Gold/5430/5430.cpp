#include<iostream>
#include<deque>
#include<sstream>
#include<string>
using namespace std;

// 주어진 배열 문자열(str)을 ',' 기준으로 분리하여 정수 deque로 변환
deque<int> split(string str, char delimeter) {
	stringstream ss(str);
	string tmp;
	deque<int> result;
	while (getline(ss, tmp, delimeter)) {
		if (!tmp.empty()) result.push_back(stoi(tmp)); // 공백이 아닌 경우만 추가
	}
	return result;
}

int main() {
	int T; cin >> T;  // 테스트 케이스 수
	while (T--) {
		string cmd;     // 명령어 문자열 (예 : "RDD")
		int N;          // 배열 원소 개수
		string arr;     // 입력 배열 (예 : "[1,2,3]")

		cin >> cmd >> N >> arr;

		// 양쪽 대괄호 제거 (예: "[1,2,3]" -> "1,2,3")
		arr.erase(arr.begin());
		arr.pop_back();

		// 문자열 배열을 deque<int>로 변환
		deque<int> q = split(arr, ',');

		bool reverse = false;  // 현재 방향 (false : 정방향, true : 역방향)
		bool error = false;    // error 여부

		// 명령어 처리
		for (int i = 0; i < cmd.length(); ++i) {
			if (cmd[i] == 'R') {
				reverse = !reverse; // 방향 전환
			}
			else if (cmd[i] == 'D') {
				if (q.empty()) {    // 삭제할 원소가 없으면 error
					error = true;
					break;
				}
				if (reverse) q.pop_back();  // 역방향이면 뒤에서 제거
				else q.pop_front();         // 정방향이면 앞에서 제거
			}
		}

		// 에러 출력
		if (error) {
			cout << "error\n";
		}
		else {
			cout << '[';

			// 역방향 출력
			if (reverse) {
				for (auto it = q.rbegin(); it != q.rend(); ++it) {
					cout << *it;
					if (it + 1 != q.rend()) cout << ',';
				}
			}
			// 정방향 출력
			else {
				for (auto it = q.begin(); it != q.end(); ++it) {
					cout << *it;
					if (it + 1 != q.end()) cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}
