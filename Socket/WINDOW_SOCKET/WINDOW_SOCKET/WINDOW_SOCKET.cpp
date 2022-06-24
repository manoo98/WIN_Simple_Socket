// CLIENT_1_SOCKET.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include "socket.h"

using namespace std;

int main()
{
    WSADATA wsadata;
    SOCKET sockfd, new_socket;
    struct sockaddr_in server, client;
    int b, c;
    const char* message;

    cout << "Start Window Server Socket" << endl;

    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
    {
        cout << "Socket Fail " << WSAGetLastError() << endl;
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET)
    {
        cout << "Server Socket not Created " << WSAGetLastError() << endl;
        return 1;
    }
    else
        cout << "Server Socket Successfully Create " << sockfd << endl;

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    b = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    if (b == SOCKET_ERROR)
    {
        cout << "Server Socket not binding " << WSAGetLastError() << endl;
        return 1;
    }
    else
        cout << "Server Socket Successfully Bind " << endl;

    listen(sockfd, 5);
    cout << "Waiting for incoming connections..." << endl;
    
    c = sizeof(struct sockaddr_in);

    while ((new_socket = accept(sockfd, (struct sockaddr*)&client, &c)) == INVALID_SOCKET)
        {
        cout << "Client Accept" << endl;
        message = "Hello Client , I have received your connection. But I have to go now, bye\n";
        send(new_socket, message, (int)strlen(message), 0);
        }

    if (new_socket == INVALID_SOCKET)
    {
        cout << "Server Socket didn't accept client " << WSAGetLastError() << endl;
        return 1;
    }

    closesocket(sockfd);
    WSACleanup();
}