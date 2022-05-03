#include "loginServer.h"

#define TEST_SALT

void handleOpCode(uint8_t buffer[]) {
    uint8_t opCode = buffer[0];
    if (opCode == CMD_AUTH_LOGON_CHALLENGE) {
        struct challengeClient authChallenge = parseLogonChallenge(buffer);
    }
}

void closeNetwork(int socketDesc, int loginSocket) {
    shutdown(socketDesc, SHUT_RDWR);
    close(socketDesc);
    shutdown(loginSocket, SHUT_RDWR);
    close(loginSocket);
}

void createLoginServer() {
    int socketDesc;
    int loginSocket;
    struct sockaddr_in loginServer;
    socketDesc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socketDesc == -1) {
        printf("Unable to create socket");
    }

    loginServer.sin_addr.s_addr = inet_addr(LOGINSERVER_ADDRESS);
    loginServer.sin_family = AF_INET;
    loginServer.sin_port = htons(LOGINSERVER_PORT);

    if (bind(socketDesc, (struct sockaddr *) &loginServer,
             sizeof(loginServer)) == -1) {
        printf("loginDesc bind error: %s\n", strerror(errno));
        closeNetwork(socketDesc, loginSocket);
        return;
    }

    if (listen(socketDesc, 1) == -1) {
        closeNetwork(socketDesc, loginSocket);
        return;
    }

    int addressSize = sizeof(loginServer);
    loginSocket = accept(socketDesc, (struct sockaddr *) &loginServer,
                         (socklen_t *) &addressSize);

    if (loginSocket == -1) {
        printf("loginSocket accept error: %s\n", strerror(errno));
        closeNetwork(socketDesc, loginSocket);
        return;
    }

    uint8_t buffer[512];
    recv(loginSocket, buffer, 512, 0);
    handleOpCode(buffer);
    closeNetwork(socketDesc, loginSocket);
}

