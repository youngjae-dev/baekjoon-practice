# [2579] 계단 오르기

## 문제 요약
주어진 계단을 오르면서 얻을 수 있는 "최댓값"을 구하는 문제
- 제한 조건
  - 세 칸 연속으로 밟을 수 없음
  - 마지막 계단은 반드시 밟아야 함

## 풀이 핵심
- 각 계단에 도달했을 때 누적 가능한 최댓값을 저장하는 Dynamic Programming 활용
- i번째 계단에 도달할 수 있는 두 가지 경우:
  1. `i-2 → i` (2칸 아래에서 점프)
  2. `i-3 → i-1 → i` (3칸 아래에서 점프 후 한 칸 올라오기)

- 점화식:
```cpp
arr[i] = score[i] + max(arr[i-2], score[i-1] + arr[i-3]);
```

## 시행착오 & 개선
- 누적 점수 대신 고유 점수를 더해야 함을 간과해 중복 카운트 실수 발생
- 불필요하게 많은 분기를 나눠서, 코드 복잡도가 올라감
- 점화식을 사용해 단순화

## 느낀 점
- DP는 점화식 설계와 조건 분기 단순화가 중요