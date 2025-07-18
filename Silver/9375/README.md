# [9375] 패션왕 신해빈

## 문제 요약
의상들을 카테고리별로 조합해서 겹치지 않게 옷을 입을 수 있는 경우의 수를 구하는 문제.  
단, 아무것도 입지 않는 경우는 제외.

## 풀이 핵심
- unordered_map<string, int>을 사용해 카테고리별 의상 개수를 저장
- 입력된 카테고리 목록을 vector<string>에 따로 저장
- 각 카테고리마다 (의상 수 + 1)을 곱해서 조합 수 계산 후 마지막에 -1 (모두 안 입는 경우 제외)

## 시행착오 & 개선
- 처음엔 카테고리 순회를 하려면 vector가 꼭 필요하다고 생각해서 unordered_map과 함께 사용했음
- 나중에 알고보니 unordered_map만으로도 전체 순회가 가능했고, 이 문제에선 vector 없이도 충분했음

## 느낀 점
- unordered_map을 처음 써봤고, 전체 순회 가능하다는 점과 vector 없이도 풀 수 있다는 걸 이번에 알게 됨
- 앞으로 비슷한 조합 문제에서 자료구조를 최소화하는 연습을 해볼 수 있을 것 같음