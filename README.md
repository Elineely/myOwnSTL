# 📋 템플릿 메타프로그래밍: 나만의 STL 구현하기(vector/map/stack) / myOwnSTL
 myOwnSTL은 템플릿 메타 프로그래밍을 통해 STL 일부 컨테이너(vector/map/stack)및 내부 class 및 메서드를 구현한 프로젝트입니다.
 레퍼런스인 (https://en.cppreference.com/w/ , clang의 STL)를 참고해 enable_if(c++11) 를 제외하곤 c++ 98 기준에 맞추어 구현했습니다.
 
 템플릿 메타프로그래밍(Template metaprogramming : TMP)이란, 컴파일 도중에 실행되는 템플릿 기반의 프래그래밍입니다. TMP를 사용하면 기존의 작업을 런타임 영역에서 컴파일 타입 영역으로 전환합니다. 이로 인해 선행 에러 탐지, 높은 런타임 효율을 얻을 수 있습니다. TMP 문법은 비 직관적이고 개발도구의 지원도 미약하지만, 런타임에 했다면 까다롭거나 불가능했을 동작을 쉽게 표현할 수 있습니다. 예를 들어 정책 기반 설계(policy-based design)를 사용하는 프로젝트의 경우, 정책 템플릿을 만들어 사용자가 커스텀한 동작을 갖는 패턴으로 구현해, 맞춤식 디자인 패턴 구현을 생성 할 수 있습니다.
 이번 프로젝트에서 사용한 TMP 관련 핵심 내용은 아래에 좀더 정리했습니다.



## ⏲️개발 기간
2022.01 ~ 2022.03 (약 2~3개월)

## ⚙️기능 및 특징
- C++ 기본 제공 STL과 동일한 효율, 동작을 하는 컨테이너 


## 주요 개념

###SFINAE(Substitution Failure Is Not An Error)
함수 템플릿의 오버로드 해결 중에 적용되는 규칙입니다. 템플릿 매개 변수(Tp)에 대해 명시적으로 지정되거나 추론된 유형이 치환 실패 했을 때, 특수화는 컴파일 오류를 일으키지 않고 오버로드 세트에서 삭제되는 특징(규칙)을 의미합니다.



###STL(표준 템플릿 라이브러리)
 C++ ISO 표준에서 설명하는 모든 필수 표준 라이브러리 헤더를 지원하는 호스트된 구현.



-------------------------------------------------
## 🦿작동방법
1. repository를 git clone 합니다.
```
git clone https://github.com/Elineely/Raycasting-engine-in-C.git
```
2. clone 한 폴더에 들어갑니다.
```
cd RaycastingEngine
```
3. makefile을 실행시켜 컴파일 합니다.
```
make
```
4. 생성된 실행 파일에 원하는 맵 정보 파일(.cub)의 경로를 argument로 입력해 실행합니다.
```
./my_raycaster ./maps/pink_m.cub
```

### 선행 조건
1. 실행 파일에 적용하려는 맵정보는 *.cub 로 명명 해야하며, 다음과 같은 형식을 따릅니다.
   <p align="center">
     <img width="818" alt="스크린샷 2024-01-30 오후 5 42 44" src="https://github.com/Elineely/Raycasting-engine-in-C/assets/80635378/5680eda8-d173-4438-a516-c2ffe5660033">
*.cub 파일에는 먼저 벽에 사용할 xpm 이미지 경로를 넣습니다.
동,서,남,북의 순서는 상관 없으며, 경로를 상대경로로 넣을 시엔 실행파일 기준으로 합니다.
C,F는 천장과 바닥에 적용할 색의 RGB 값이며 0~255 사이값이 ',' 기호로 구분합니다.
  </p>
2. 적용하고 싶은 이미지가 따로 있을 시, .xpm 이미지로 변경해야합니다.
   <p align="center">
    <img width="956" alt="스크린샷 2024-01-30 오후 5 42 25" src="https://github.com/Elineely/Raycasting-engine-in-C/assets/80635378/22c0c40d-ef12-4272-b184-889866c27411">
   </p>
