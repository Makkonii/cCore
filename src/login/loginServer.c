#include "loginServer.h"

void handleOpCode(uint8_t buffer[]) {
    uint8_t opCode = buffer[0];
    if (opCode == CMD_AUTH_LOGON_CHALLENGE) {
        parseLogonChallenge(buffer);
    }
}

void createLoginServer() {
    int socket_desc;
    struct sockaddr_in loginServer;
    socket_desc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_desc == -1) {
        printf("Unable to create socket");
    }

    loginServer.sin_addr.s_addr = inet_addr(LOGINSERVER_ADDRESS);
    loginServer.sin_family = AF_INET;
    loginServer.sin_port = htons(LOGINSERVER_PORT);

    if (bind(socket_desc, (struct sockaddr *) &loginServer,
             sizeof(loginServer)) == -1) {
        perror("socket_desc");
        shutdown(socket_desc, SHUT_RDWR);
        return;
    }
    if (listen(socket_desc, 1) == -1) {
        shutdown(socket_desc, SHUT_RDWR);
        close(socket_desc);
        return;
    }
    int addressSize = sizeof(loginServer);
    int loginSocket = accept(socket_desc, (struct sockaddr *) &loginServer,
                             (socklen_t *) &addressSize);
    if (loginSocket == -1) {
        printf("Error: %s\n", strerror(errno));
        shutdown(loginSocket, SHUT_RDWR);
        close(loginSocket);
        return;
    }
    uint8_t buffer[512];
    ssize_t result = recv(loginSocket, buffer, 512, 0);
    handleOpCode(buffer);
}

