// Unix OS에서만 동작한다.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // 1. 서버와 통신하기 위한 소켓을 제작한다.
    int serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 2. 서버와 연결한다.
    // 서버의 소켓 주소를 명시하면 프로토콜 스택이 알아서 소켓 주소에 해당하는 소켓과 연결해준다.
    // 서버에서 봤던 bind()와 다르게 serverAddress가 serverSocket과 바인드되는 것이 아니다.
    // serverSocket의 소켓 주소는 연결 수립 시 알아서 주소가 대응된다.
    // 그리고 이때 서버는 대기 소켓이 대기 상태여야 한다.
    struct sockaddr_in serverAddress = { 0 };
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(12345);
    connect(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    puts("Connected to server!");

    // 3. 메시지를 서버로 보낸다.
    const char* message = "Hello, Server!";
    int messageLength = strlen(message);
    send(serverSocket, message, messageLength, 0);
    printf("To Server : %s\n", message);

    // 4. 에코된 메시지를 받는다.
    char buffer[1024] = { 0 };
    int remainBytes = 1023;
    recv(serverSocket , buffer, remainBytes, 0);
    printf("Echo from server : %s\n", buffer);

    // 5. 연결을 종료한다.
    shutdown(serverSocket, SHUT_RDWR);
    close(serverSocket);

    exit(EXIT_SUCCESS);
}