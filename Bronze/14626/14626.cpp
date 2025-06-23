#include<iostream>
#include<vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	int mark = -1; // * 위치 저장
	int sum = 0;
	for (int i = 0; i < 13; ++i) {
		if (str[i] == '*') {
			mark = i;
			continue;
		}
		int num = str[i] - '0';
		if (i % 2 == 0) sum += num; // 가중치 1
		else if (i % 2 != 0) sum += 3 * num; // 가중치 3
	}
	if (mark == 12) { // 마지막 자리일 경우
		cout << (10 - (sum % 10)) % 10;
	}
	else {
		for (int i = 0; i < 10; ++i) { // 반복문 돌면서 0~9 중에 문제 조건을 만족하는 숫자 찾기
			if (mark % 2 == 0) { //가중치 1
				int tmp_sum = sum;
				tmp_sum += i;
				if (tmp_sum % 10 == 0) {
					cout << i;
				}
			}
			else { //가중치 3
				int tmp_sum = sum;
				tmp_sum += 3 * i;
				if (tmp_sum % 10 == 0) {
					cout << i;
				}
			}
		}
	}
}