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

# 1. 웹 브라우저가 메시지를 만든다.
네이버에 접속하기 위해 웹 브라우저의 주소창에 `www.naver.com`이라고 입력했을 때, 가장 먼저 웹 브라우저가 하는 일은 메시지를 만드는 것이다. 이번 챕터에서는 어떤 과정을 거쳐 메시지가 작성되는지 알아보도록 하자.

## 1-1. HTTP 리퀘스트 메시지를 작성한다.
### URI
주소창에 작성했던 `www.naver.com`와 같은 것을 URL(Uniform Resource Locator)이라고 한다. 사실 우리가 웹 페이지(Web Page)라고 부르는 것의 실체는 HTML(Hypertext Markup Language) 문서로 웹 브라우저가 이를 분석해 우리에게 보여주는 것이다. 다시 말해 `www.naver.com`를 입력하면 네이버의 서버에 어떤 HTML 문서 파일을 요청하는 것이라고 할 수 있다.

![네이버의 실체 두둥탁](.resources/1-1.png)
<div class="img-desc">우리가 보는 네이버는 오른쪽의 HTML 문서를 분석한 결과다.</div>

서버에는 여러 가지 자원이 있기 때문에 우리가 원하는 자원을 요청하려면 이를 식별할 수 있어야 한다. 웹에서는 이를 위해 URI(Uniform Resource Identifier)를 사용한다. URI는 URL과 URN(Uniform Resource Name)으로 나뉘는데, URL은 자원의 위치를 나타내고 URN은 자원의 이름을 나타낸다.* URI 문법에 대한 설명은 [여기](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Identifying_resources_on_the_Web#syntax_of_uniform_resource_identifiers_uris)로 대체한다.
<span class="footnote"> * URN보다는 URL을 더 많이 사용하긴 한다.</span>

### HTTP
HTTP(Hypertext Transfer Protocol)는 이름에서도 알 수 있듯 HTML 문서를 전송하기 위한 프로토콜*이다. 하지만 지금은 HTML 문서 외에도 이미지, 비디오 등 다양한 자료를 전송할 수 있게 됐다. 
<span class="footnote"> * 프로토콜은 통신을 위한 규칙을 말한다.</div>

![HTTP는 웹의 근간](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview/fetching_a_page.png)
<div class="img-desc">하나의 웹 문서를 구성하기 위해 여러 번의 HTTP 호출이 필요한 경우도 있다.</div>

HTTP의 동작은 서버에 무언가 요청하면 그에 대한 응답을 받는 것으로 구성된다. 요청 서식과 응답 서식이 정해져 있는데 이를 각각 요청 메시지*(Request Message)와 응답 메시지(Response Message)라고 한다.
<span class="footnote"> * 메시지란 통신되는 데이터를 지칭한다.</div>

![요청 메시지와 응답 메시지의 구조](https://developer.mozilla.org/en-US/docs/Web/HTTP/Messages/httpmsgstructure2.png)
<div class="img-desc">요청 메시지와 응답 메시지의 예시</div>

메시지를 잘 들여다보면 구성이 크게 다르지 않은 것을 알 수 있다. 시작 줄에는 요청 혹은 응답의 내용을 적고, 여러 가지 부가 정보가 담긴 헤더*(Header)를 작성한다. 그 후 한 줄의 개행 후에 바디(Body)를 작성하는데, 여기에는 요청과 관련된 데이터나 요청에 대한 결과가 포함된다.
<span class="footnote"> * 헤더의 각 항목에 대해서 알고 싶다면 [여기](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers)를 참고하라.</span>

#### 메소드
요청 메시지의 시작 줄에는 메소드(Method)가 포함된다. 메소드는 메소드는 HTTP의 동작 방법을 의미하며 종류는 아래와 같다. 각각에 대해서 자세히 알고 싶다면 [여기](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods)를 참고하라.

| 메소드 | 설명 |
| --- | --- |
| GET | 데이터를 요청한다. |
| HEAD | 데이터에 대한 정보를 요청한다. |
| POST | 데이터를 전송한다. |
| PUT | 서버의 파일을 교체한다. |
| DELETE | 서버의 파일을 삭제한다. |
| CONNECT | 서버와의 터널을 구성한다. |
| OPTIONS | 통신 옵션을 통지하거나 조사한다. |
| TRACE | 메시지 루프백 테스트를 수행한다. |
| PATCH | 자원의 수정된 내역을 적용한다. |

#### 상태 코드
응답 메시지의 시작 줄에는 상태 코드(Status Code)가 포함된다. 상태 코드는 요청이 성공적으로 완료되었는지를 나타낸다. 상태 코드는 5개의 그룹으로 묶여있다. 각각에 대해서 자세히 알고 싶다면 [여기](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)를 참고하라.

| 상태 코드 값 | 설명 |
| --- | --- |
| 100 ~ 199 | 처리의 경과 상황 등을 통지한다. |
| 200 ~ 299 | 요청 성공적으로 완료됐음을 알린다. |
| 300 ~ 399 | 다른 조치가 필요함을 나타낸다. |
| 400 ~ 499 | 클라이언트 오류를 나타낸다. |
| 500 ~ 599 | 서버 오류를 나타낸다. |


## 1-2. 웹 서버의 IP 주소를 DNS 서버에 조회한다.
### IP 주소
인터넷에는 수많은 컴퓨터가 접속되어 있다. 이중 우리가 원하는 컴퓨터에 HTTP 요청을 하려면 해당 컴퓨터를 찾아낼 수 있는 정보가 필요한데, 여기에는 IP(Internet Protocol) 주소를 사용한다.

IP 주소는 32비트의 숫자이며*, 네트워크 ID와 호스트 ID로 구성 된다. 표기는 `221.149.9.93`과 같이 8비트씩 끊어서 십진수로 표기하는 십진수 점 표기법(DDN; Dotted Decimal Notation)을 사용한다.
<span class="footnote"> * 엄밀히는 IPv4 주소 길이이며, IPv6 주소의 길이는 128비트이다.</span>

![IP 주소 예시](.resources/1-2.png)
<div class="img-desc">인터넷에 접속한 모든 컴퓨터는 IP 주소를 갖고 있다.</div>

#### 서브넷 마스크
`221.149.9.93`을 다시 보자. 이 주소에서 네트워크 ID와 호스트 ID가 구분이 되는가? 이를 구분하려면 서브넷 마스크(Subnet Mask)가 필요하다. 서브넷 마스크는 `221.149.9.93/24`처럼 IP 주소 뒤에 네트워크 ID의 길이를 표기한다*. 혹은 DDN이나 이진수로도 표기할 수 있다.
<span class="footnote">* 이를 [CIDR](http://www.ktword.co.kr/test/view/view.php?nav=2&no=1144&sh=CIDR)(Classless Inter-Domain Routing)이라고 한다.</span>

<!-- 서브넷 마스크 -->

#### 특수한 IP 주소
IP 주소 중 몇 가지 특수한 IP 주소가 있다.

- **네트워크(Network) 주소**
네트워크를 나타내는 주소로 호스트 ID의 모든 비트가 0이다. 예를 들어 `221.149.9.93/24`에서는 `221.149.9.0`가 네트워크 주소다.

- **브로드캐스트(Broadcast) 주소**
네트워크에 속한 모든 호스트에게 데이터를 전송하기 위한 주소로 호스트 ID의 모든 비트가 1이다. 예를 들어 `221.149.9.93/24`에서는 `221.149.9.255`가 브로드캐스트 주소다.

- **와일드카드(Wildcard) 주소**
0.0.0.0/0 주소를 말하며, 모든 IP를 지칭한다.

- **루프백(Loopback) 주소**
로컬 머신을 지칭하는 주소다. 127.0.0.0/8을 사용한다. 로컬호스트(Localhost)라고도 한다.

### 도메인 이름
`223.130.200.107`라는 IP 주소가 있다고 해보자. 이게 어느 컴퓨터인지 알 수 있는가? 그러면 `www.naver.com`은 어떤가? 한눈에 네이버라는 것을 알 수 있다. `223.130.200.107`은 네이버 서버의 IP 주소다. 

이처럼 IP 주소는 외우기가 어렵다. 이를 대신하여 사용하는 것이 바로 도메인 이름(Domain Name)이다. 그래서 웹 브라우저는 URL에 적힌 도메인 이름을 DNS(Domain Name System)에 의해 IP 주소로 해석(Resolution)한 후, HTTP 요청을 한다.

도메인 이름 해석을 위해서는 소켓 라이브러리를 사용해야 한다. BSD 소켓 라이브러리를 사용해 `www.naver.com`의 해석을 하는 프로그램은 아래와 같다.

```c
// Unix OS에서만 동작한다.

#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void PrintDomain(const struct addrinfo* addresses);

int main()
{
  const char* domain = "www.naver.com";
  const char* port = "80"; // HTTP

  struct addrinfo hints = { 0 };
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  struct addrinfo* result = NULL;
  int errorCode = getaddrinfo(domain, port, &hints, &result);
  
  if (errorCode != 0)
  {
    printf("getaddrinfo error : %s\n", gai_strerror(errorCode));

    exit(EXIT_FAILURE);
  }

  PrintDomain(result);

  freeaddrinfo(result);
  
  exit(EXIT_SUCCESS);
}

void PrintDomain(const struct addrinfo* addresses)
{
  puts("Result");

  while (addresses != NULL)
  {
    struct sockaddr_in* address = (struct sockaddr_in*)addresses->ai_addr;

    printf("%s\n", inet_ntoa((struct in_addr)address->sin_addr));

    addresses = addresses->ai_next;
  }
}

// Output:
// Result
// 223.130.195.200
// 223.130.195.95
```

## 1-3. 전 세계의 DNS 서버가 연대한다.
### DNS 동작 원리
앞서 살펴본 DNS의 동작 원리에 대해서 자세히 살펴보자. HTTP가 요청-응답의 흐름을 가졌던 것처럼 DNS도 질의-응답의 흐름을 가진다. DNS 질의 메시지에는 질의할 도메인 이름, 자원 레코드 유형, 질의 클래스의 정보가 저장되어 있다.

![DNS 질의 메시지 구성](http://www.ktword.co.kr/img_data/4889_1.jpg)
<div class="img-desc">DNS 메시지의 질의 섹션에 질의할 도메인 이름, 자원 레코드 유형, 질의 클래스 데이터가 저장된다.</div>

질의할 도메인 이름에는 `www.naver.com`와 같이 IP 주소를 얻고 싶은 도메인 이름이 기록된다. 질의 클래스에는 DNS가 고안될 당시에 인터넷 이외에도 다양한 네트워크에 대응하기 위해 해당 정보를 준비했다. 질의 클래스에 저장될 수 있는 값에는 인터넷을 의미하는 `IN`, COAS 네트워크를 의미하는 `CS`, Hesoid 서버를 의미하는 `HS`가 있는데 현재는 인터넷을 제외하고 사용되지 않으므로 질의 클래스 영역에는 항상 `IN`이 저장된다.
<span class="footnote"> * 괄호 안의 값은 실제 값을 나타낸다.</span>

#### 자원 레코드
그럼 자원 레코드 유형이란 무엇일까? 먼저 자원 레코드에 대해서 알아보자. 자원 레코드(RR; Resource Record)는 DNS 서버에 저장되는 데이터로 자원 레코드 하나에는 도메인 이름, 값, 유형의 데이터가 저장되어 있다. DNS에 저장될 수 있는 데이터에는 IP 주소 외에도 여러 가지가 존재하는데 유형은 이를 나타낸다. 어떤 유형이냐에 따라 응답하는 내용이 달라진다. 유형에는 여러 가지가 있지만 A, CNAME, MX 대표적인 몇 개만 살펴보자.*
<span class="footnote"> * 이 외의 유형은 [여기](http://www.ktword.co.kr/test/view/view.php?m_temp1=4889&id=434)를 참고하라</span>

A(Address) 레코드는 자원 레코드의 가장 기본적인 유형으로 IP 주소를 조회하기 위한 용도로 사용된다. 예를 들어 `www.naver.com`을 질의했을 때, DNS 서버에는 아래처럼 자원 레코드가 저장되어 있을 것이다.

| 도메인 이름 | 값 | 유형 |
| --- | --- | --- |
| www.naver.com | 223.130.195.200 | A |
| www.naver.com | 223.130.195.95 | A |

CNAME 레코드는 도메인 이름의 별칭이 저장된 레코드다. 

MX(Mail Exchange)는 이메일에 대한 메일 서버 IP 주소를 조회하기 위한 용도로 사용한다.

#### nslookup
nslookup을 이용해 DNS 질의를 눈으로 확인해보자.

<!-- nslookup을 이용한 자원 레코드 응답 확인 -->

### 분산 계층 구조
DNS 서버는 분산 계층 구조를 이루고 있다. 다시 말해 `www.naver.com`을 조회한다고 할 때 하나의 DNS 서버에게 질의하는 것이 아니라 차례대로 상위 계층에 속하는 DNS 서버에게 질의하며 최종 결과를 얻는다. 질의하는 방법에는 반복적 질의(Iterative Queries)와 재귀적 질의(Recursive Queries)가 있다.

<!-- 각 질의 방법 이미지 -->

또, 각 계층에 하나의 DNS 서버만 존재하는 것이 아니라 여러 개의 DNS 서버가 존재하여 원활한 서비스가 이뤄지게 하고 있다. 각 계층의 정보는 도메인 이름에 명시되어 있다.

#### 도메인 이름
도메인 이름에 대해서 다시 자세히 살펴보자. 도메인 이름의 `.`은 사실 각 계층을 구분하기 위한 것으로 `.`의 오른편에 상위 계층을 적는다. 즉, `www.naver.com`은 `com`이 최상위 계층에 위치함을 나타내고, `naver`가 그 다음 하위 계층을 `www`가 그 다음 하위 계층을 나타낸다. 사실 `com` 위에 더 상위 계층이 존재하는데 이를 루트 도메인(Root Domain)이라 한다. 루트 도메인은 이름이 없어 사실상 생략되는데, `www.naver.com`은 `www.naver.com.`와 같으며 마지막에 위치한 `.`이 루트 도메인을 나타낸다. 계층의 갯수는 가변적이며 최대 128개다. 전세계 도메인 관리는 [ICANN](https://www.icann.org/)이 국내는 [KRNIC](https://xn--3e0bx5euxnjje69i70af08bea817g.xn--3e0b707e/)이 관리하고 있다.

<!-- 도메인 이름 예시 -->

계층에 대해서 조금 더 알아보자. 먼저 루트 서버는 하위 계층인 최상위 도메인에 대한 IP 주소를 제공하고 있다. 루트 서버는 13개 관리 기관에 의해서 관리되고 있으며*, 이 주소는 전세계에 존재하는 모든 DNS 주소가 알고 있다. 그 다음 최상위 도메인 서버는 `com`, `kr`, `org`와 같은 것인데 책임 DNS 서버에 대한 IP 주소를 제공한다.** 책임 DNS 서버는 `naver`, `google` 등과 같이 회사가 관리하며 각 회사의 서비스에 대한 IP 주소를 제공한다. 가령 네이버 웹툰 서비스의 도메인은 `comic.naver.com`인데 이는 네이버 웹툰 홈페이지가 `naver` DNS 서버에 의해 제공되는 것이다.
<span class="footnote"> * 루트 서버 목록은 [여기](https://www.iana.org/domains/root/servers)서 확인할 수 있다.
** 최상위 도메인 서버 목록은 [여기](https://www.iana.org/domains/root/db)서 확인 가능하다.</span>

### 캐싱
같은 호스트에 접속하는 일은 생각보다 많다. 예를 들어, 네이버 홈페이지에 접속 후 1시간 뒤에 네이버에 다시 접속한다고 할 때, 같은 질의 메시지를 발생시키는 것은 트래픽 낭비라고 볼 수 있다. 따라서 한번 요청된 질의는 TTL에 저장된 값을 초 단위로 캐싱해둔다. 즉, 응답 영역의 TTL에 86400라는 값이 저장되어 있다면 응답 받은 시점으로부터 하루(86400초)동안 캐싱하여 동일한 질의에 대해 신속히 처리한다. 캐싱은 올바른 질의(Positive Caching)와 잘못된 질의(Negative Caching) 모두에 대해서 이뤄진다.*
<span class="footnote">* 캐싱된 데이터를 삭제하고 싶다면 Windows에서는 ipconfig /flushdns를 Unix에서는 sudo killall -HUP mDNSResponder를 입력하면 된다.</span>

## 1-4. 프로토콜 스택에 메시지 송신을 의뢰한다.
- 세션
세션(Session)이라는 것은 네트워크 상에서 종단 간 일회용 논리적 연결을 의미하며, 서로 데이터를 주고 받기 위한 가상의 파이프라고 보면 된다. 연결은 시간에 따라 상태가 변화하는데 아래와 같다. 점선은 서버의 변화를 나타내며, 실선은 클라이언트의 변화를 나타낸다.

  - 연결 설정
  연결 설정 과정부터 살펴보자. 연결 설정은 양단 프로세스 간에 데이터를 동기화하는 과정이다. 동기화 되는 데이터는 소켓 주소, 시작 순서 번호(ISN; Initial Sequence Number), 수신 윈도우 크기*다. 3번의 단계를 거쳐서 설정이 완료되기에 3-way 핸드셰이크(3-way Handshake)라고 부른다.

  - 연결 해제
  연결 해제도 설정과 비슷하게 3-4단계(3-way Handshake / 4-way Handshake)를 거쳐서 이뤄진다. 이를 깔끔한 종료(Graceful Close / Graceful Shutdown)라고 한다.* 클라이언트가 마지막 ACK 세그먼트를 보낸 후 일정 시간** 동안 연결을 열어두는데, 이는 마지막 ACK 세그먼트가 유실될 시 재전송하는 목적도 있으며, 뒤늦게 도착한 패킷을 폐기하려는 목적도 있다.
  <span class="footnote"> * 강제 종료(Hard Close / Abortive Close)도 있다.
  ** 일반적으로 30초며, 이에 사용되는 타이머를 시간 대기 타이머(Time-waited Timer)라 한다.
  </span>

- 에코 서버 제작하기
  - 디스크립터
  - 포트 번호
  - 송신 버퍼 수신 버퍼

- HTTP 1.1
  - Keep-Alive
  <!-- 마지막 참고자료 토대로 정리 -->


# 참고자료
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Identifying_resources_on_the_Web#syntax_of_uniform_resource_identifiers_uris
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Messages
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers
- https://youtu.be/Yv7KIbbWSow
- https://youtu.be/s5kIGnaNFvM
- https://youtu.be/K1o6sTZng-4
- https://youtu.be/9GSvbn6y9uU
- https://youtu.be/3-dIUtXHEr0
- https://youtu.be/JDh_lzHO_CA
- http://www.ktword.co.kr/test/view/view.php?nav=2&no=1144&sh=CIDR
- https://opentutorials.org/course/3276
- http://www.ktword.co.kr/test/view/view.php?m_temp1=385&id=433

- https://youtu.be/Epu3m_9zp8M
- https://youtu.be/XXzxetbAIfA
- https://opentutorials.org/course/3276
- http://www.ktword.co.kr/test/view/view.php?nav=2&no=264
- http://www.ktword.co.kr/test/view/view.php?m_temp1=385&id=433
- http://www.ktword.co.kr/test/view/view.php?m_temp1=2017&id=433
- http://www.ktword.co.kr/test/view/view.php?m_temp1=2251&id=434
- http://www.ktword.co.kr/test/view/view.php?m_temp1=3042&id=434
- http://www.ktword.co.kr/test/view/view.php?m_temp1=2110&id=434
- http://www.ktword.co.kr/test/view/view.php?m_temp1=2918&id=434
- http://www.ktword.co.kr/test/view/view.php?m_temp1=2705&id=1230
- https://www.cloudflare.com/ko-kr/learning/dns/dns-records/dns-a-record/
- https://www.lesstif.com/system-admin/nslookup-20775988.html
- https://www.cloudflare.com/ko-kr/learning/dns/dns-records/dns-cname-record/
- https://www.cloudflare.com/ko-kr/learning/dns/dns-records/dns-mx-record/

- https://youtu.be/6fd6wdMVXmQ
- https://youtu.be/K9L9YZhEjC0
- https://youtu.be/0ZXIRuEVa5E
- https://sunyzero.tistory.com/269
- https://www.geeksforgeeks.org/socket-programming-cc/
- https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Evolution_of_HTTP#http1.1_–_the_standardized_protocol
