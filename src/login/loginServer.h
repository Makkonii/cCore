#ifndef LOGINSERVER_H
#define LOGINSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "loginStructs.h"
#include "../../constants/opcodes.h"
#include "loginOpCodeHandler.h"

#define LOGINSERVER_PORT 3724
#define LOGINSERVER_ADDRESS "127.0.0.1"

void createLoginServer();

#endif //LOGINSERVER_H
