Conversation opened. 1 unread message.

Skip to content
Using Gmail with screen readers
The attachment has been added to Google Drive.
  Learn more
1 of 24
Fwd: CN lab
Inbox

Mayur Bhavsar <bhavsarmayur664@gmail.com>
Attachments
10:43 PM (46 minutes ago)
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

int main() 
{
    int listenfd = 0;
    int connfd = 0;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char sendBuff[1024];
    ifstream file("new.txt", ios::in);
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        cerr << "Socket creation error: " << strerror(errno) << endl;
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Bind error: " << strerror(errno) << endl;
        close(listenfd);
        return -1;
    }

    if (listen(listenfd, 10) < 0) {
        cerr << "Listen error: " << strerror(errno) << endl;
        close(listenfd);
        return -1;
    }
    cout << "Server listening on port 5000" << endl;
    connfd = accept(listenfd, (struct sockaddr*)&cli_addr, &cli_len);
    if (connfd < 0) {
        cerr << "Accept error: " << strerror(errno) << endl;
        close(listenfd);
        return -1;
    }
    cout << "Client connected" << endl;
    if (!file.is_open()) {
        cerr << "Error opening file: " << strerror(errno) << endl;
        close(connfd);
        close(listenfd);
        return -1;
    }
while (!file.eof()) {
file.read(sendBuff, sizeof(sendBuff));
ssize_t bytesRead = file.gcount();
if (send(connfd, sendBuff, bytesRead, 0) < 0) {
cerr << "Send error: " << strerror(errno) << endl;
file.close();
close(connfd);
close(listenfd);
return -1;
}
}
file.close();
close(connfd);
close(listenfd);
cout << "File sent and connection closed" << endl;
return 0;
}

servercp.cpp
Displaying servercp.cpp.
