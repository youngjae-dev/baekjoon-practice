#include<iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int count = 1; // 연산 횟수 (초기 상태 포함, A에서 시작할 때 1)

	// B를 A로 되돌릴 수 있을 때까지 반복 (B <= A가 되면 종료)
	while (A < B) {
		if (B % 10 == 1) B /= 10;    // 마지막 자리가 1이면, '×10 후 +1' 연산을 되돌림
		else if (B % 2 == 0) B /= 2; // 짝수이면, '×2' 연산을 되돌림
		else break;                  // 그 외의 경우는 A로 만들 수 없으므로 종료
		++count;                     // 연산회수 증가
	}

	// 최종적으로 A로 만들 수 있으면 연산 횟수 출력, 아니면 -1 출력
	if (A == B) cout << count;
	else cout << -1;
}