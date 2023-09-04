<style>
.highlight
{
    color: red;
}

.footnote
{
    color: gray;
    font-size: 90%;
}

img
{
    display: block;
    margin: auto;
}

.img-desc
{
    color: gray;
    text-align: center;
    margin-bottom: 1%;
}
</style>

# 2. TCP/IP의 데이터를 전기 신호로 만들어 보낸다.
## 2-1. 소켓을 작성한다.
- 네트워크 모델
    - 캡슐화와 역캡슐화
- netstat
- 소켓 생성..

## 2-2. 서버에 접속한다.
- 세션/커넥션 성립
    - 송수신 버퍼 확보
    - 3way handshake
- TCP 헤더

## 2-3. 데이터를 송∙수신한다.
- MTU
- MSS
- 네이글 알고리즘
- ARQ
    - 몇 번 다시 보내도 회복의 전망이 없으면 강제 종료하고 애플리케이션에 오류 통지
- RTO는 RTT를 기반으로 매 번 재 계산함.
    - OS마다 다르지만 재전송 타이머의 최소값은 0.5초에서 1초
- Sliding Window
    - Window Notification
- HTTP 응답

## 2-4. 서버에서 연결을 끊어 소켓을 말소한다.
- HTTP의 연결 관리
    - 1.0은 서버 응답 후 종료
    - 1.1은 연결 유지 -> 클라가 종료
- 연결 해제
    - 4way handshake
    
