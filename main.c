#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    
    int port = 5500;
    int descriptor;
    struct sockaddr_in myaddr, remoteAddr;
    char buffer[1024];
    socklen_t addr_size;
    WSADATA wsaData;
    
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }
    
    descriptor = socket(AF_INET, SOCK_DGRAM, 0);
    
    memset(&myaddr, '\0', sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(port);
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    bind(descriptor, (struct sockaddr*)&myaddr, sizeof(myaddr));
    addr_size = sizeof(remoteAddr);
    while(1) {
        recvfrom(descriptor, buffer, 1024, 0, (struct sockaddr*)& remoteAddr, &addr_size);   
        if(buffer) {
            printf("got data from %s", buffer);
            memset(buffer, 0, sizeof buffer);
        }
    }
    return 0;
}
