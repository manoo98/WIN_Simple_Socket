// WINDOW_SOCKET.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "client1.h"
constexpr auto PORT = 6001;
int main()
{
    WSADATA wsadata;
    SOCKET sockfd;
    struct sockaddr_in server;
    const char* message;
    char server_buffr[200];
    int receive_message_size, irs;

    cout << "Start Client Socket" << endl;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        cout << "Client Socket Fail " << WSAGetLastError() << endl;
        return 1;
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Client Socket Fail & Error- " << WSAGetLastError() << endl; 
        return 1;
    }
    else
        cout << "Client Socket Created & socket_ID- " << sockfd << endl;  

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;  
    server.sin_port = htons(PORT); 

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == 0)
    {
        cout << "Error Client Connection " << WSAGetLastError() << endl;
        return 1;
    }
    else
        cout << "Client Connecting" << endl;


    if ((irs = recv(sockfd, (char*)server_buffr, 200, 0)) == 0)
    {
        cout << "Fail Receiving Data " << WSAGetLastError() << endl;
        return 1;
    }
    else
    {
        cout << "Client! Successfully receive Data --\t" << server_buffr << endl;
    }



    message = "Client, Ready to Communicate";
    if (irs = send(sockfd, message, (int)strlen(message), 0) == 0)
    {
        cout << "Client Sending Data! Fail " << WSAGetLastError() << endl;
        return 1;
    }
    else
    {
        cout << "Ready to sending the data " << endl;
        cin >> irs;
        cout << "Acknowledge Data Send " << irs << "\n" << endl;
    }
    
    closesocket(sockfd);
    WSACleanup();

}
