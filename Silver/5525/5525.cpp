#include<iostream>
#include<string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M; // N : Pn에서 n, M : 문자열 S의 길이

	string str;
	cin >> str; // S 입력

	int count = 0;   // Pn 패턴 등장 횟수
	int pattern = 0; // 연속된 IOI 개수

	// str[i-1], str[i], str[i+1]을 기준으로 IOI 패턴 검사
	for (int i = 1; i < M - 1; ++i) {
		if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
			++pattern; // IOI 하나 발견

			if (pattern == N) {
				++count;   // Pn 완성
				--pattern; // 겹치는 부분 중복 카운트 방지
			}
			++i; // 다음 패턴의 시작을 I에 맞추기 위함
		}
		else {
			pattern = 0; // 패턴 끊기면 초기화
		}
	}
	cout << count;
}