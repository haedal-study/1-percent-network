// Unix OS에서만 동작한다.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // 1. 소켓을 제작한다.
    // 소켓(Socket)은 네트워킹을 위한 인터페이스로 데이터 송∙수신이 일어나는 통로다.
    // 소켓의 실체는 파일이기 때문에 socket()의 반환값은 파일 디스크립터(File Descriptor)다.
    // 파일 디스크립터는 파일을 구분하기 위한 ID라고 생각하면 된다.
    int listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // 2. 소켓 주소에 바인드한다.
    // 하나의 프로그램이 여러 개의 소켓을 만들 수 있다.
    // 그렇기 때문에 각 소켓을 구분할 수 있는 게 필요한데 이것이 바로 소켓 주소다.
    // 즉, 각 소켓에는 대응되는 소켓 주소가 필요하다.
    // 바인드를 한다는 것은 소켓과 소켓 주소를 사상시키는 것을 의미한다.
    // 다른 컴퓨터가 서버에 올바르게 접속하기 위해 소켓 주소를 만들고 이를 바인드하는 것이다.
    // 아래 코드는 listenSocket과 127.0.0.1:12345라는 주소를 바인드하는 것이다.
    struct sockaddr_in serverSocketAddress = { 0 };
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(12345);
    serverSocketAddress.sin_addr.s_addr = INADDR_ANY;
    bind(listenSocket, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress));

    // 3. 대기 상태로 만든다.
    // 서버에서는 여러 클라이언트의 접속을 처리하기 위해 대기 소켓이라는 것을 만든다.
    // MMORPG의 접속 대기열 같은 것이라고 생각해도 무방하다.
    int errorCode = listen(listenSocket, 10);

    while (true)
    {
        // 4. 클라이언트와의 연결을 수립한다.
        // 어떤 클라이언트가 서버에 접속할 때, 가장 먼저 해야하는 것은 데이터 송∙수신을 위한 연결을 수립하는 것이다.
        // 연결은 세션이라고도 하는데 서로 데이터를 보낼 수 있는 가상의 파이프라고 생각하면 된다.
        // 클라이언트와 소통할 수 있는 가상의 파이프를 만드는 것이다.
        struct sockaddr_in clientSocketAddress = { 0 };
        socklen_t clientSocketAddressLength = 0;
        int clientSocket = accept(listenSocket, (struct sockaddr*)&clientSocketAddress, &clientSocketAddressLength);
        printf("Connected to [%s]\n", inet_ntoa(clientSocketAddress.sin_addr));

        // 5. 클라이언트로부터 메시지를 수신한다.
        char buffer[1024] = { 0 };
        ssize_t readBytes = recv(clientSocket, buffer, 1023, 0);
        printf("From Client : %s\n", buffer);

        // 6. 클라이언트에게 메시지를 에코한다. 즉, 다시 전송한다.
        send(clientSocket, buffer, readBytes, 0);

        // 7. 연결을 끊는다.
        shutdown(clientSocket, SHUT_RDWR);
        close(clientSocket);
    }
    
    exit(EXIT_SUCCESS);    
}