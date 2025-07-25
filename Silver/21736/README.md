# [21736] 헌내기는 친구가 필요해

## 문제 요약  
도연이는 캠퍼스에서 친구를 만나고 싶다.
N × M 크기의 캠퍼스가 주어지고, 다음과 같은 정보가 포함되어 있다:

- 'I' : 도연이의 시작 위치
- 'P' : 사람
- 'O' : 빈 공간
- 'X' : 벽 (이동 불가)

도연이는 상하좌우로 이동하며 벽을 제외한 공간을 자유롭게 이동할 수 있다.
이때 도연이가 만날 수 있는 사람의 수를 출력하라.
단, 아무도 만나지 못하면 "TT"를 출력한다.

## 풀이 핵심  

- BFS를 활용해 도연이의 이동 가능 범위를 탐색
- 'P'를 만나면 `meetCount++` (사람을 만난 경우)
- 'O' 또는 'P'인 칸으로만 이동 가능
- 'X'(벽)이거나 'I'(이미 방문한 곳)는 이동 불가
- 방문 처리는 'I'로 마킹해 중복 탐색 방지
- 탐색이 끝난 뒤 `meetCount` 값이 0이면 "TT" 출력, 아니면 `meetCount` 출력

## 참고  

- 방문 처리에 별도의 `visited` 배열을 쓰지 않고, 'I'로 직접 마킹하면 코드가 간단해짐
- 'P'를 만나기 전에 방문 마킹을 하지 않으면, 같은 사람을 중복해서 카운트할 수 있음 → 마킹 순서 주의
- 좌표 범위 체크를 먼저 하면 복잡한 조건문도 깔끔하게 정리 가능

## 느낀 점  

- 'P' 조건을 먼저 확인하고 마킹해야 중복 카운트를 방지할 수 있음을 실습을 통해 체감함
- 실전에서는 visited 배열 없이 문제 상황에 맞게 맵 자체를 마킹하는 방식도 꽤 유용하다는 걸 배웠다