#include<iostream>
#include<vector>
using namespace std;

int blue_count = 0;
int white_count = 0;

// x : width | y : height
// length를 한변으로 하는 정사각형 판단 함수
bool square(int x, int y, int length, const vector<vector<int>>& v) {
	int standard = v[y][x]; // 기준 색 (0 or 1)

	for (int i = y; i < y + length; ++i) {
		for (int j = x; j < x + length; ++j) {
			if (standard != v[i][j]) {
				return false;
			}
		}
	}

	if (standard == 1) ++blue_count;
	else ++white_count;

	return true;
}

// x : width | y : height
// square 함수를 통해 정사각형 판단 후
// 4등분해서 재귀적으로 호출
void divideSquare(int x, int y, int length, const vector<vector<int>>& v) {
	if (square(x, y, length, v)) return;

	length = length / 2;

	divideSquare(x, y, length, v);
	divideSquare(x, y + length, length, v);
	divideSquare(x + length, y, length, v);
	divideSquare(x + length, y + length, length, v);
}

int main() {
	int N; cin >> N; // 종이 한 변의 길이

	vector<vector<int>> paper(N, vector<int>(N, 0)); // N x N 종이

	// 파란색인지 흰색인지 입력
	// 1 : 파란색 | 0 : 흰색
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> paper[i][j];
		}
	}

	// 종이의 정사각형 개수 구하기 시작
	divideSquare(0, 0, N, paper);

	cout << white_count << '\n' << blue_count;
}