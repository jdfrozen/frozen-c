#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void error_handling(char * messages);
int main(int argc,char *argv[]){
  int sock;
  struct sockaddr_in send_adr;
  if (argc != 3){
    printf("Usage: %s <IP> <port> \n",argv[0]);
    exit(1);
  }
  sock = socket(AF_INET,SOCK_STREAM,0);
  memset(&send_adr,0,sizeof(send_adr));
  send_adr.sin_family = AF_INET;
  send_adr.sin_addr.s_addr = inet_addr(argv[1]);
  send_adr.sin_port = htons(atoi(argv[2]));
  if (connect(sock,(struct sockaddr*)&send_adr,sizeof(send_adr)) == -1){error_handling("connect() error");}
  write(sock,"1234",strlen("1234"));
  close(sock);
  return 0;
}
void error_handling(char * messages){
    puts(messages);
    exit(1);
}
