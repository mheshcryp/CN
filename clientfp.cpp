Conversation opened. 1 read message.

Skip to content
Using Gmail with screen readers
Enable desktop notifications for Gmail.
   OK  No thanks
1 of 24
Fwd: CN lab
Inbox

Mayur Bhavsar <bhavsarmayur664@gmail.com>
Attachments
10:43 PM (47 minutes ago)
to me


---------- Forwarded message ---------
From: Mayur Bhavsar <bhavsarmayur664@gmail.com>
Date: Sun, 22 Sept 2024, 10:42 pm
Subject: Fwd: CN lab
To: <amanwalfar99@gmail.com>



---------- Forwarded message ---------
From: Mayur Bhavsar <bhavsarmayur664@gmail.com>
Date: Mon, 2 Sept 2024, 12:23 pm
Subject: CN lab
To: Mayur Bhavsar <bhavsarmayur664@gmail.com>




 4 Attachments
  •  Scanned by Gmail
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <fstream>
#include <cerrno>

using namespace std;
int main() {
    int sockfd;
    int byteReceived;
    char recvBuff[256];
    memset(recvBuff, '0', sizeof(recvBuff));
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        cerr << "Socket creation error: " << strerror(errno) << endl;
        return 1;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Connection failed: " << strerror(errno) << endl;
        close(sockfd);
        return 1;
    }

    ofstream fp("newclient.txt", ios::out);
    if (!fp.is_open()) {
        cerr << "Failed to open file for writing: " << strerror(errno) << endl;
        close(sockfd);
        return 1;
    }

    while ((byteReceived = read(sockfd, recvBuff, sizeof(recvBuff))) > 0) {
        fp.write(recvBuff, byteReceived);
        fp<<recvBuff;
    }

    if (byteReceived < 0) {
        cerr << "Error reading from socket: " << strerror(errno) << endl;
    }

    close(sockfd);
    fp.close();
    cout << "File received and saved" << endl;
    return 0;
}

clientfp.cpp
Displaying servercp.cpp.
