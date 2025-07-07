#include<iostream>
#include<cmath>
using namespace std;

int result = 0; // 현재까지 방문한 칸 수

// Z 순서에 따라 2차원 배열을 순회하며, 목표 좌표 (r, c)가 몇 번째로 방문되는지 계산하는 함수
void divide(int x, int y, int length, int r, int c) {
	if (length == 1) return;

	int half_length = length / 2;
	int square = pow(half_length, 2);

	// 왼쪽 위 : 아무것도 더하지 않음
	if (r < x + half_length && c < y + half_length) {
		divide(x, y, half_length, r, c);
	}

	// 오른쪽 위 : 이전 사분면 칸 수만큼 더함
	else if (r < x + half_length && c >= y + half_length) {
		result += square;
		divide(x, y + half_length, half_length, r, c);
	}

	// 왼쪽 아래 : 이전 2개 사분면 칸 수만큼 더함
	else if (r >= x + half_length && c < y + half_length) {
		result += (2 * square);
		divide(x + half_length, y, half_length, r, c);
	}

	// 오른쪽 아래 : 이전 3개 사분면 칸 수만큼 더함
	else if (r >= x + half_length && c >= y + half_length) {
		result += (3 * square);
		divide(x + half_length, y + half_length, half_length, r, c);
	}
}

int main() {
	int N, r, c; // 배열 크기 : 2^N x 2^N, (r, c)는 방문 순서를 구할 좌표
	cin >> N >> r >> c;
	int length = pow(2, N); // 전체 배열의 한 변의 길이

	divide(0, 0, length, r, c);

	// 결과 출력
	cout << result;
}