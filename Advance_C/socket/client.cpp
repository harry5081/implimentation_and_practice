#include <sys/socket.h>
#include <arpa/inet.h>

#include <iostream>
#include <cstring>

#include <unistd.h>
#include <signal.h>

#define PORT 123457

short createSocket();
int socketConnect(int hSocket);
int socketSend(int hSocket, char* Rqst, short lenRqst);
int socketReceive(int hSocket, char* Rsp, short RvcSize);

static bool clientRunning = true;

void intHandler(int) {
    clientRunning = false;
}

int main(){
    int socket_df = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[100] = {0};
    char server_reply[200] = {0};

    socket_df = createSocket();
    if(!socket_df){
        std::cout << "Could not create socket" << std::endl;
        return 1;
    }
    std::cout << " Socket created" << std::endl;

    if(socketConnect(socket_df) < 0){
        std::cout << "Connection failed" << std::endl;
        return 1;
    }
    int i=0;
    while(1){
    std::cout << "Connect successfully" << std::endl;
    fgets(sendToServer, 100, stdin);
    socketSend(socket_df, sendToServer, strlen(sendToServer));
    read_size = socketReceive(socket_df, server_reply, 200);
    if(i==3){
        break;
    }
    i++;
    // struct sigaction act;
    // act.sa_handler = intHandler;
    // sigaction(SIGINT, &act, NULL);

    // while(1){
        // if(clientRunning == false){
        //     std::cout<< "get terminate" << std::endl;
        //     socketSend(socket_df, sendToServer, strlen(sendToServer));
        // read_size = socketReceive(socket_df, server_reply, 200);
        //     close(socket_df);
        //     return 0;
        // }
        
        // if(clientRunning == false){
        //     std::cout<< "get terminate" << std::endl;
        //     socketSend(socket_df, sendToServer, strlen(sendToServer));
        // read_size = socketReceive(socket_df, server_reply, 200);
        //     close(socket_df);
        //     return 0;
        // }
        
        
        std::cout<< "Server response:" << server_reply << std::endl;
    // }
    std::cout<< "close socket" << server_reply << std::endl;
    }
    close(socket_df);
    return 0;
}

short createSocket(){
    short hSocket;
    std::cout << "create socket" << std::endl;
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnect(int hSocket){
    int iRetval = -1;
    int port = PORT;

    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_port = htons(port);

    iRetval = connect(hSocket,(struct sockaddr *) &remote, sizeof(remote));
    return iRetval;
}

int socketSend(int hSocket, char* Rqst, short lenRqst){
    int shortRetval = -1;
    struct timeval tv;

    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0){
        std::cout<< "Time out" << std::endl;
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;

}

int socketReceive(int hSocket, char* Rsp, short RvcSize){
    int shortRetval = -1;

    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0){
        std::cout<< "Time out" << std::endl;
        return -1;
    }

    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    std::cout<< "Response" << Rsp << std::endl;
    return shortRetval;

}



