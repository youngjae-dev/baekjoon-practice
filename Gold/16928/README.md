# [16928] 뱀과 사다리 게임

## 문제 요약
뱀과 사다리 게임에서 **도착 지점(100번 칸)**까지 도달하기 위해 **주사위를 최소 몇 번 굴려야 하는지** 구해라.

- 보드판은 1부터 100까지 숫자가 순서대로 적힌 칸으로 구성된다.
- 각 칸에는 **최대 하나의 사다리 또는 뱀이 존재**할 수 있다.
    - 사다리 또는 뱀: 출발점 `x`에서 도착점 `y`로 즉시 이동한다.

## 풀이 핵심
- **시작점(1번 칸)**을 기준으로 BFS를 수행한다.
- 주사위는 **1~6**까지 나올 수 있으며, 현재 칸에서 `+1 ~ +6`까지 이동할 수 있다.
- 이동한 칸에 **사다리나 뱀이 있을 경우**, 곧바로 도착점으로 이동한다.
- 새로 도달한 칸의 `굴린 횟수`는 → `이전 칸의 횟수 + 1`로 갱신한다.
- 도중에 100번 칸에 도달하면 **BFS를 조기 종료**한다.

## 시행착오 & 개선
- 처음엔 보드판의 각 칸을 단순히 인덱스로 보고,  
  주사위 횟수를 별도로 변수로 관리하려 했지만 구조가 복잡해졌다.
- 이후, 보드판 배열에 각 칸까지 도달하는 데 필요한 **굴린 횟수 자체를 저장**하게 하여 구조를 단순화시켰다.
- 그리고 **사다리/뱀을 탈 때 중복으로 +1을 누적하는 실수**도 있었는데, 사다리/뱀을 **주사위 이동 후 바로 처리**하도록 바꿔서 해결했다.

## 느낀 점
- 배열의 인덱스를 **정보 저장용 변수처럼 활용**하면, 코드를 훨씬 효율적으로 구성할 수 있다는 것을 느꼈다.
- 누적값을 관리할 때는 **불필요하게 중복 누적되는 경우가 있는지** 디버깅 과정에서 철저히 확인해야 한다는 교훈을 얻었다.