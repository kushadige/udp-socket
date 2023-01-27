# udp-socket

- Basic UDP socket for Windows 

To compile main.c on windows machine, Ws2_32 library must to be linked with it. (ws2_32.lib)

Instance linking via gcc
```
gcc main.c -L. -lWs2_32 -o socket
```
![udp](https://user-images.githubusercontent.com/101992799/215227014-5a40ec37-d2c8-49e9-9dd3-ac99c46ae6a4.png)
