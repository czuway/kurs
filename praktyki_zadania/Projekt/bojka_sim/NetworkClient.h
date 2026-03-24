#pragma once
#include <string>
#include <winsock2.h>

class NetworkClient {
public:
    NetworkClient(const std::string& server, int port);
    ~NetworkClient();

    bool send(const std::string& message);

private:
    std::string server_;
    int port_;
    SOCKET sock_;
};
