#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char * messages);

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1){error_handling("socket() error");}
    struct sockaddr_in serv_addr, from_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    //也可以基于“连接”
    //connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    char message[BUF_SIZE];
    int strLen;
    socklen_t addr_size;
    while(1){
        puts("Input message(Q to quit):");
        fgets(message, BUF_SIZE, stdin);
        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n")){break;}
        sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
        //基于“连接”，可以使用IO函数write,read
        //write(sock, message, strlen(message));
        addr_size = sizeof(from_addr);
        strLen = recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr*)&from_addr, &addr_size);
        //strLen = read(sock,message,sizeof(message)-1);
        message[strLen]=0;
        printf("Message from server: %s\n", message);
    }
    close(sock);
    return 0;
}

void error_handling(char * messages){
    puts(messages);
    exit(1);
}
