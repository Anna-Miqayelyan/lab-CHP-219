#include "UDPSocket.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    struct sockaddr_in si_other;
    int slen = sizeof(si_other);

    char buf[BUFLEN];
    char message[BUFLEN];

    unsigned short srv_port = 0;
    char srv_ip_addr[40] = {0};

    UDPSocket client_sock;

    memset((char*)&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;

    if (argc == 1) {
        si_other.sin_port = htons(PORT);
        si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
        printf("1: Server - addr=%s , port=%d\n", SERVER, PORT);
    } else if (argc == 2) {
        si_other.sin_port = htons(atoi(argv[1]));
        si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
        printf("2: Server - addr=%s , port=%d\n", SERVER, atoi(argv[1]));
    } else {
        si_other.sin_port = htons(atoi(argv[2]));
        si_other.sin_addr.S_un.S_addr = inet_addr(argv[1]);
        printf("3: Server - addr=%s , port=%d\n", argv[1], atoi(argv[2]));
    }

    while (1) {
        printf("\nEnter message : ");
        gets_s(message, BUFLEN);

        client_sock.SendDatagram(message, (int)strlen(message), (struct sockaddr*)&si_other, slen);

        memset(buf, '\0', BUFLEN);
        client_sock.RecvDatagram(buf, BUFLEN, (struct sockaddr*)&si_other, &slen);

        puts(buf);
    }

    return 0;
}