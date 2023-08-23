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

# 1. 웹 브라우저가 메시지를 만든다 - 웹 브라우저의 내부 탐험
우리는 숨 쉬듯이 자연스럽게 웹 브라우저를 이용해 인터넷을 탐험하고 있지만, 그 과정이 어떻게 되는지는 모르고 있다. 가령 네이버에 접속하기 위해 Chrome에 `www.naver.com`을 입력한 후 엔터를 눌렀을 때 과연 화면 뒤에서는 어떤 일이 일어나고 있을까? 이번 시간에는 이에 대해 이해해보도록 하자.

## 프로토콜
<!-- 마트 구매를 통한 규칙의 비유 -->

네트워크에 대해 이해하려면 프로토콜(Protocol)에 대해서 알아야 한다. 프로토콜은 통신하기 위한 규칙으로 3가지에 대해서 정의하고 있다. 첫 번째는 통신 장치 간에 교환될 메시지의 형식(Syntax)이며, 두 번째는 메시지 교환 순서(Timing)이고, 세 번째는 메시지를 교환할 때 수행해야 할 행위(Semantics)다. 

곧 살펴보겠지만 네트워크는 여러 개의 계층으로 구성되며, 각 계층에서 사용하는 다양한 프로토콜이 존재한다. 그래서 결국 우리가 웹툰과 웹소설, 유튜브나 틱톡 등을 이용할 수 있는 것은 여러 프로토콜이 동작한 결과라고 할 수 있다. 공식 인터넷 프로토콜은 [여기](https://www.rfc-editor.org/standards)서 확인할 수 있다.

![다양한 프로토콜](http://www.ktword.co.kr/img_data/205_2.jpg)
<div class="img-desc">인터넷을 구성하기 위한 여러 가지 프로토콜이 존재한다.</div>

## OSI 모델
네트워크(Network)에 대해서 알고 있는가? 표준국어대사전에서는 네트워크에 대해서 아래처럼 정의하고 있다.

> 랜(LAN)이나 모뎀 따위의 통신 설비를 갖춘 컴퓨터를 이용하여 서로 연결시켜 주는 조직이나 체계.

즉, 컴퓨터끼리 서로 연결되어 통신할 수 있는 체계를 네트워크라 한다. 초창기 네트워크는 한 곳에 집중된 형태(중앙집중형)였는데, 안전한 통신을 위해 이를 분산된 형태의 네트워크를 구상하고자 한 것이 인터넷(Internet)의 출발이었다. 다시 말해 소규모의 네트워크끼리 상호연결(Interconnected)된 형태를 만들고자 했다.*
<span class="footnote"> * 인터넷의 역사에 대해서 좀 더 알아보고 싶다면 [여기](https://opentutorials.org/course/3084/18889)를 참고하라.</span>

그런데 중앙집중형에서 분산형으로 만드는 과정에서 상이한 컴퓨터 시스템끼리 통신하기 위한 방법이 필요했고, 이를 정의한 것이 바로 개방형 시스템 상호 연결 참조 모델(OSI Reference Model; Open System Interconnection Reference Model)이다. 

OSI 참조 모델은 7개의 계층으로 구성된다. 가장 아래 계층부터 물리 계층(Physical Layer), 데이터 링크 계층(Data Link Layer), 네트워크 계층(Network Layer), 전송 계층(Transport Layer), 세션 계층(Session Layer), 표현 계층(Presentation Layer), 응용 계층(Application Layer)이다.*
<span class="footnote"> * OSI 참조 모델의 각 계층에 대한 설명은 지면상 생략한다. 궁금한 사람은 [여기](https://www.cloudflare.com/ko-kr/learning/ddos/glossary/open-systems-interconnection-model-osi/)와 [이 시리즈](https://yozm.wishket.com/magazine/detail/2108/)를 참고하길 바란다.</span>

![OSI 참조 모델](https://cf-assets.www.cloudflare.com/slt3lc6tev37/6ZH2Etm3LlFHTgmkjLmkxp/59ff240fb3ebdc7794ffaa6e1d69b7c2/osi_model_7_layers.png)
<div class="img-desc"> OSI 참조 모델은 7개의 계층으로 구성된다. 그래서 OSI 7계층이라고도 한다.</div>

각 계층은 상호독립적으로 각기 맡은 기능을 수행하고 이를 위한 다수의 프로토콜이 존재한다. 다시 말해 하위 계층의 기능을 이용하며, 상위 계층에 기능을 제공한다. 이렇게 여러 개의 계층으로 나눈 이유는 3가지의 장점이 있기 때문이다. (1) 새로운 프로토콜을 정의하기 편하고, (2) 특정 통신 기능 또는 서비스를 수정하기 용이하며, (3) 전체 시스템을 이해하는 것이 쉽다. 하지만 프로토콜 단위를 사용하고, 계층 간 서비스 인터페이스를 구현하기가 쉽지 않아 최적화된 시스템 구현의 어려움은 존재한다.

### TCP/IP 모델
네트워크에는 인터넷만 있는 것은 아니다. 블루투스와 근거리 무선통신(NFC; Near Field Communication) 또한 네트워크에 속한다. 다시 말해 OSI 참조 모델은 인터넷을 포함한 다양한 통신을 위한 기준이라고 할 수 있다.

현대 인터넷은 OSI 참조 모델보다는 이를 인터넷에 맞게 변형한 TCP/IP 모델을 사용한다. TCP/IP 모델은 가장 아래 계층부터 링크 계층(Link Layer), 인터넷 계층(Internet Layer), 전송 계층(Transport Layer), 응용 계층(Application Layer)으로 구성된다.

![OSI 모델과 TCP/IP 모델과의 비교](https://media.geeksforgeeks.org/wp-content/uploads/20230417045622/OSI-vs-TCP-vs-Hybrid-2.webp)
<div class="img-desc">OSI 모델을 인터넷에 맞게 변형한 것이 TCP/IP 모델이다.</div>

## HTTP
우리가 인터넷을 사용하면서 접한 수많은 화면을 웹 페이지(Web Page)라 부른다. 웹 페이지의 실체는 HTML(Hypertext Markup Language) 문서인데, 우리가 주소창에 무언가를 입력하는 것은 사실 HTML 문서를 요청하는 것이다. 그다음 웹 브라우저가 HTML 문서를 분석하여 웹 페이지를 볼 수 있는 것이다.

![네이버의 실체 두둥탁](.resources/1-1.png)

HTTP(Hypertext Transfer Protocol)는 이런 HTML 문서를 전송하기 위한 프로토콜이다. 

## 메시지 구조

## URI
HTTP를 통해 요청하는 자원은 문서가 될 수도, 이미지나 그 무엇도 될 수 있다. 따라서 이러한 자원을 식별하기 위해 URI(Uniform Resource Identifier)를 사용한다. URI는 다시 URL(Uniform Resource Locator)와 URN(Uniform Resource Name)으로 나뉘는데, URL은 자원의 위치를 나타내고 URN은 자원의 이름을 나타낸다. 자원을 요청할 땐 URN보다는 URL을 많이 사용하기 때문에 URL을 위주로 살펴보도록 하자.*
<span class="footnote"> * URN에 대해서 알아보고 싶다면 [여기](https://en.wikipedia.org/wiki/Uniform_Resource_Name)를 참고하라.</span>


## 메소드

## 헤더

## 응답 코드




<!-- 웹 브라우저에 주소 입력하는 이미지 -->

## 1. HTTP 리퀘스트 메시지를 작성한다.




다시 말하자면 우리가 원하는 HTML 문서를 요청하는 것이다. 이를 요청하기 위해서는 HTTP(Hypertext Transfer Protocol)라는 프로토콜(Protocol)*을 사용한다. 따라서 우리가 주소창에 `https://www.naver.com`라는 것을 입력하면 웹 브라우저는 이에 맞춰 HTTP 요청 메시지**를 작성하여 웹 서버로 요청한다. 


<!-- 웹 서버에 요청하는 이미지 -->

HTTP에 대해서 조금 더 살펴보자. HTTP는 웹에서 HTML 문서 외에도 이미지, 동영상, CSS 파일, 스크립트 파일 등의 자원을 요청할 수 있는 프로토콜이며, 클라이언트가 어떤 형식에 맞춰 자원을 요청하면 서버가 그에 맞는 응답을 한다. <!-- 현실 예시에 빗대어 비유할 것 -->

![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/fetching_a_page.png)
<div class="img-desc">우리가 인터넷에서 보는 모든 문서는 HTTP를 이용해 요청하는 것이다.</div>

HTTP의 요청과 응답 메시지는 모두 우리가 읽을 수 있는 텍스트이며, 시작줄(Start Line), 헤더(Header), 바디(Body)로 구조 또한 같다. 

![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Messages/httpmsgstructure2.png)
<div class="img-desc">HTTP 메시지의 예시</div>

### HTTP 요청 메시지
#### 시작 줄
시작 줄은 `{HTTP 메소드} {요청 대상} {HTTP 버전}`으로 구성 된다. HTTP 메소드는 수행 방식을 의미하는데, 종류와 의미는 아래와 같다.

| 메소드 | 의미 |
| --- | --- |
| GET | 데이터를 요청합니다. |
| HEAD | 데이터에 대한 정보를 요청합니다. |
| POST | 데이터를 전송합니다. |
| PUT | 서버의 파일을 교체합니다. |
| DELETE | 서버의 파일을 삭제합니다. |
| CONNECT | 서버와의 터널을 구성합니다. |
| OPTIONS | 통신 옵션을 통지하거나 조사합니다. |
| TRACE | 메시지 루프백 테스트를 수행합니다. |
| PATCH | 자원의 수정된 내역을 적용합니다. |





![](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/http_request.png)
<div class="img-desc">HTTP 요청 메시지</div>



- URL
- 브라우저는 URL을 해독한 후 HTTP 리퀘스트 메시지를 만든다.
- HTTP
    - Request
        - 리퀘스트 라인(Request Line)
        - 메시지 헤더(Message Header)
            - 부가적인 자세한 정보
                - 날짜, 클라이언트 측이 취급하는 데이터의 종류, 언어, 압축 형식, 클라이언트나 서버의 소프트웨어 명칭과 버전, 데이터의 유효 기간, 최종 변경 일시 등
        - 메시지 본문(Message)
    - Response
        - 상태 코드(Status Code)
            - 1xx : 처리의 경과 상황 등을 통지
            - 2xx : 정상 종료
            - 3xx : 무언가 다른 조치가 필요함
            - 4xx : 클라이언트 측의 오류
            - 5xx : 서버 측의 오류
- CGI

### HTTP
#### HTTP Request Message

#### HTTP Response Message



## 웹 서버의 IP 주소를 DNS 서버에 조회한다.
- HTTP 메시지를 만든 후 OS를 통해 접근 대상의 웹 서버에게 송신
- 서브넷이라는 작은 네트워크를 라우터로 접속하여 전체 네트워크가 만들어진다.
- IP
    - IP 주소 = 네트워크 주소 + 호스트 주소
    - IPv4는 32비트로 구성
    - 이중 네트워크 주소를 나타내기 위해 넷마스크(Netmask) 사용
    - 호스트 번호가 모두 0이면 네트워크를 나타내고 모두 1이면 브로드캐스트를 나타낸다.
- DNS
    - 사용하는 이유
        - IP 주소보다 도메인 이름을 기억하는 것이 상대적으로 더 쉬움
    - 프로그래밍
    - 서비스
        - 이름 확인(Name Resolution)
    - 클라이언트를 DNS Resolver라고 함
    - 마찬가지로 OS의 도움을 받음
- 프로토콜 스택(Protocol Stack)
    - OS 내부에 내장된 네트워크 제어용 소프트웨어
    - 프로토콜 드라이버, TCP/IP 소프트웨어 등으로 부르기도 함

# 참고자료
- https://www.rfc-editor.org/standards
- http://www.ktword.co.kr/test/view/view.php?m_temp1=205&id=861
- https://opentutorials.org/course/3084
- https://en.wikipedia.org/wiki/OSI_model
- https://www.cloudflare.com/ko-kr/learning/ddos/glossary/open-systems-interconnection-model-osi/
- https://www.geeksforgeeks.org/tcp-ip-model/


- https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Messages
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Identifying_resources_on_the_Web#syntax_of_uniform_resource_identifiers_uris




