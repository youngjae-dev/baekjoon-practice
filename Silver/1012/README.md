# [1012] 유기농 배추 문제 풀이

## 문제 요약
N×M 크기의 배추밭에 K개의 배추가 심어져 있다.
상하좌우로 인접한 배추끼리는 하나의 덩어리로 간주하며,
총 몇 개의 배추 덩어리가 존재하는지 구하는 문제.

## 풀이 핵심
- 전체 농장을 순회하면서 방문하지 않은 배추(1)를 발견하면 DFS 탐색
- DFS를 통해 인접한 배추들을 전부 방문 처리
- 배추 덩어리 하나를 탐색할 때마다 count++
- dx, dy 배열을 이용한 상하좌우 탐색
- 2차원 DFS 구현 문제

## 시행착오 & 개선
- 처음에는 배추가 입력될 때마다 주변에 배추가 있는지 판단해서 count++ 했지만,
  연결 상태가 나중에 형성되는 경우를 고려하지 못함
- 예: (0,0), (0,2) 입력 후 -> count = 2
  하지만 (0,1) 입력 시 이 셋은 하나의 덩어리여야 함
- 모든 배추 위치를 입력받고, 농장 전체를 순회하며 DFS로 탐색하는 방식으로 수정

## 느낀 점
- dx, dy를 활용한 인접 탐색이 매우 실용적이고 다양한 문제에 적용 가능하다는 걸 느낌
- 특히 DFS를 통한 연결 요소 탐색에서 입력 순서가 아닌 전체 구조 기반 접근의 중요성을 체감함