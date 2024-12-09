#include <stdio.h>
#include "UDPServer.h"

int main(int argc, char* argv[]) {
    struct sockaddr_in si_other;
    unsigned short srvport;
    int slen;
    char buf[BUFLEN];
    char msg[BUFLEN];

    srvport = (argc == 1) ? PORT : atoi(argv[1]);
    UDPServer server(srvport);
    slen = sizeof(si_other);

    while (1) {
        printf("Waiting for data... ");
        fflush(stdout);

        memset(buf, '\0', BUFLEN);
        server.RecvDatagram(buf, BUFLEN, (struct sockaddr*)&si_other, &slen);

        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n", buf);

        printf("\nAnswer : ");
        gets_s(msg, BUFLEN);

        server.SendDatagram(msg, (int)strlen(msg), (struct sockaddr*)&si_other, slen);
    }

    return 0;
}