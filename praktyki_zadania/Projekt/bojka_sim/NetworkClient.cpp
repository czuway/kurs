#include "NetworkClient.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

NetworkClient::NetworkClient(const std::string& server, int port)
    : server_(server), port_(port), sock_(INVALID_SOCKET)
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
        std::cerr << "[ERROR] WSAStartup failed\n";
}

NetworkClient::~NetworkClient()
{
    if (sock_ != INVALID_SOCKET)
        closesocket(sock_);
    WSACleanup();
}

bool NetworkClient::send(const std::string& message)
{
    int attempts = 3;

    while (attempts--)
    {
        sock_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock_ == INVALID_SOCKET)
        {
            std::cerr << "[ERROR] Socket creation failed\n";
            return false;
        }

        sockaddr_in serv_addr{};
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port_);

        // Poprawka: u¿ywamy inet_pton z ws2tcpip.h lub fallback do inet_addr
        serv_addr.sin_addr.s_addr = inet_addr(server_.c_str());
        if (serv_addr.sin_addr.s_addr == INADDR_NONE)
        {
            std::cerr << "[ERROR] Invalid server address\n";
            closesocket(sock_);
            return false;
        }

        if (::connect(sock_, (sockaddr*)&serv_addr, sizeof(serv_addr)) == 0)
        {
            int sent = ::send(sock_, message.c_str(), (int)message.size(), 0);
            if (sent == SOCKET_ERROR)
            {
                std::cerr << "[ERROR] Send failed\n";
                closesocket(sock_);
                std::this_thread::sleep_for(std::chrono::seconds(1));
                continue;
            }

            closesocket(sock_);
            sock_ = INVALID_SOCKET;
            std::cout << "[INFO] Data sent successfully\n";
            return true;
        }
        else
        {
            std::cerr << "[ERROR] Connection failed, retrying...\n";
            closesocket(sock_);
            sock_ = INVALID_SOCKET;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    return false;
}
