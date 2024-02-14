# 📋 템플릿 메타 프로그래밍: STL 일부 구현하기(vector/map/stack) / myOwnSTL
 myOwnSTL은 템플릿 메타 프로그래밍을 통해 STL 일부 컨테이너(vector/map/stack)및 내부 class 및 메서드를 구현한 프로젝트입니다.
레퍼런스인 (https://en.cppreference.com/w/ , clang의 STL)를 참고해 enable_if를 제외하곤 c++ 98 기준에 맞추어 구현했습니다.

 
 레이캐스팅은 2차원 맵에서 3차원의 원근감을 만드는 렌더링 기술 입니다.

 사용자가 형식에 맞는 2차원 지도 정보와, 유저의 지도상 위치와 방향, 배경 이미지 정보가 담긴 파일을 제공하면 3D처럼 변환한 윈도우를 제공합니다.
윈도우 내에서 사용자는 (w,a,s,d)키를 이용해 맵 내부에서 이동할 수 있으며, 방향키(<-, ->)를 이용해 바라보는 시각을 조작할 수 있습니다.

## ⏲️개발 기간
2022.01 ~ 2022.03 (약 2~3개월)

## ⚙️기능 및 특징
- 

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
