#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <iostream>
#include <cstring>

#include <unistd.h>

#define PORT 123457

short createSocket();
int bindCreatedSocket(int hSocket);


int main(){
    int socket_df = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_msg[200] = {0};
    char msg[100] = {0};
    const char *pMsg = "Here is my server";

    socket_df = createSocket();
    if(!socket_df){
        std::cout << "Could not create socket" << std::endl;
        return 1;
    }
    std::cout << " Socket created" << std::endl;

    if(bindCreatedSocket(socket_df) < 0){
        std::cout << "Bind fialed." << std::endl;
        return 1;
    }
    std::cout << "Bind done" << std::endl;

    listen(socket_df, 3);

    while(1){
        std::cout << "Waiting for incoming connection" << std::endl;        
        clientLen = sizeof(struct sockaddr_in);

        sock = accept(socket_df, (struct sockaddr *) &client, (socklen_t*) &clientLen);
        
        int i =1;
        if(setsockopt(socket_df, SOL_SOCKET, SO_KEEPALIVE, &i, sizeof(int)) < 0){
            std::cout<< "keep alive" << std::endl;
            return -1;
        }
        if(socket < 0){
            std::cout << "Accept failed" << std::endl;
            return 1;
        }
        std::cout << "Connection accepted" << std::endl;
        while(1){

            std::cout << "aaa"  << std::endl;
            memset(client_msg,'\0',sizeof client_msg);
            memset(msg,'\0',sizeof msg);
            std::cout << "bbb"  << std::endl;
            int recv_cnt = recv(sock, client_msg, 200, 0);
            if(recv_cnt < 0){
                std::cout << "Recv failed" << std::endl;
                break;
            }
            std::cout << "ccc"  << std::endl;
            std::cout << "Client reply:" << client_msg << std::endl;
            std::cout << "ddd"  << std::endl;
            strcpy(msg,"Server got client msg");
            std::cout << "eee"  << std::endl;
            std::cout << recv_cnt  << std::endl;
            if(recv_cnt>0){
                std::cout << "fff"  << std::endl;
                if(send(sock, msg, strlen(msg), 0) < 0){
                    std::cout << "ggg"  << std::endl;
                    std::cout << "Send fail" << std::endl;
                    return 1;
                }
            }
            else{
                break;
            }
            std::cout << "hhh"  << std::endl;
                
            

        }
        close(sock);
        sleep(1);
        

    }
    


    return 0;
}

short createSocket(){
    short hSocket;
    std::cout << "create socket" << std::endl;
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket){
    int iRetvai = -1;
    int port = PORT;

    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(port);

    iRetvai = bind(hSocket,(struct sockaddr *) &remote, sizeof(remote));
    return iRetvai;
}