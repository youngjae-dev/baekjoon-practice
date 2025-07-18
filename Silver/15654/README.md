# [15654] N과 M (5)

## 문제 요약
N개의 자연수가 주어졌을 때, 다음 조건을 만족하는 길이 M인 수열을 **사전 순으로 증가하는 순서**로 모두 출력하라.

- N개의 수 중에서 M개를 골라 만든 **중복 없는 수열**

## 풀이 핵심
- 수열이 정렬된 상태가 아니므로, 먼저 **오름차순 정렬**하여 사전 순 출력을 보장한다.
- **중복 선택을 방지**하기 위해 `visited` 배열을 사용해 방문 여부를 체크한다.
- **재귀 + 백트래킹**을 이용해 모든 가능한 수열을 탐색한다.
- `depth`변수는 현재 수열의 길이를 의미하며, 동시에 `v` 벡터의 인덱스를 제어하는 데 사용된다.

## 시행착오 & 개선
- 처음에는 다른 N과 M 문제들처럼 `startNum`을 넘겨주며 오름차순 수열을 만들면 된다고 생각했지만, 입력 수들이 정렬되어 있지 않다는 점에서 오답이 발생했다.
- 따라서 반복문을 **0부터 N까지 전부 탐색**하는 방식으로 바꾸고, 중복을 피하기 위해 `visited`를 도입했다.
- `depth`를 통해 현재 수열의 길이를 관리하면서 동시에 `v`의 인덱스를 명확하게 지정할 수 있어 코드가 더 간결해졌다.

## 느낀 점
- 문제의 표면적인 난이도와 달리, **정렬 상태 여부와 중복 체크**가 구현 난이도를 크게 좌우할 수 있다는 걸 느꼈다.
- **재귀 함수는 생각보다 강력한 도구**이며, 이를 잘 다루는 것이 백트래킹 문제를 풀기 위한 핵심이라는 걸 다시 한 번 깨달았다.
- `depth`처럼 하나의 변수를 적절히 설정하면 **여러 역할을 동시에 수행**할 수 있다는 점에서 변수 설계의 중요성을 실감했다.
- `visited`는 단순한 체크 배열이 아니라 **탐색의 정확성과 효율성을 보장**하는 중요한 장치임을 명확히 알게 되었다.