#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
void error_handling(char * messages);
int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
    //format addr
    int serverSock =socket(PF_INET, SOCK_DGRAM, 0);
    if(serverSock == -1){error_handling("socket() error");}
    struct sockaddr_in serverAddr, clientAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(atoi(argv[1]));
    //bind
    if(bind(serverSock, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1)
        error_handling("bind() error");
    puts("Server start...");
    //data
    char message[BUF_SIZE];
    int strLen;
    socklen_t clientAddrSize;
    while(1){
        clientAddrSize = sizeof(clientAddr);
        strLen = recvfrom(serverSock, message, BUF_SIZE, 0, (struct sockaddr*) &clientAddr, &clientAddrSize);
        sendto(serverSock, message, strLen, 0, (struct sockaddr*)&clientAddr, clientAddrSize);
    }
    close(serverSock);
    puts("Server close...");
    return 0;
}
void error_handling(char * messages)
{
    puts(messages);
    exit(1);
}
