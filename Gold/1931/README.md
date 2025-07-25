# [1931] 회의실 배정

## 문제 요약
한 개의 회의실에서 N개의 회의를 진행하려고 한다.  
각 회의의 시작 시간과 종료 시간이 주어질 때, **회의가 겹치지 않도록 선택할 수 있는 최대 회의 수**를 구하라.  
(단, 회의의 시작 시간과 종료 시간이 같을 수도 있다.)

## 풀이 핵심
- 회의들을 **종료 시간이 빠른 순으로 정렬**한다.
- 이후, 정렬된 회의를 앞에서부터 보며 **이전 회의의 종료 시간보다 같거나 늦게 시작하는 회의만 선택**하면 된다.

## 시행착오 & 개선
- `greater<pair<int, int>>`를 사용하면 `first` 기준으로 정렬된다는 점을 처음에 몰라서, 회의 종료 시간이 아닌 시작 시간 기준으로 정렬이 되어버렸다.
- 이 문제를 해결하기 위해 `Comp`라는 구조체를 만들고, `operator()`를 오버로딩하여 **종료 시간이 기준이 되도록 직접 정렬 기준을 구현**했다.
- 또한 처음에는 회의가 겹치지 않게 하기 위해 **시작 시간과 종료 시간을 모두 조건문에 사용하여 복잡하게 분기**했다.
- 하지만 회의가 겹치지 않으려면 **"이전 회의의 종료 시간 <= 현재 회의의 시작 시간"** 조건 하나만으로 충분하다는 것을 깨닫고, 훨씬 간결하고 효율적인 조건으로 개선했다.

## 느낀 점
- `greater`를 `pair`에 사용할 경우, **`first` 기준으로 정렬된다는 점을 반드시 기억**해야 한다.
- 정렬 기준을 직접 정의해봄으로써, **복잡한 정렬 조건도 얼마든지 내가 구현할 수 있다는 자신감**을 얻었다.
- 문제를 단순히 해결하는 것뿐만 아니라, **더 효율적이고 깔끔한 코드로 개선해 나가는 과정이 정말 중요하다는 것을 다시 한 번 느꼈다.**