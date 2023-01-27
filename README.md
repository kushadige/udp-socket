# udp-socket

- Basic UDP socket for Windows 

To compile main.c on windows machine, Ws2_32 library must to be linked with it. (ws2_32.lib)

Instance linking via gcc
```
gcc main.c -L. -lWs2_32 -o socket
```
