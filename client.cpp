#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include <cstring>
#include<arpa/inet.h> 

using namespace std;

int main()
{
int clientSocket = socket(AF_INET,SOCK_STREAM,0);
sockaddr_in serverAddress;
serverAddress.sin_family=AF_INET;
serverAddress.sin_port=htons(8080);
//serverAddress.sin_addr.s_addr=INADDR_ANY;
const char* server_ip = "192.168.211.119";
if (inet_pton(AF_INET, server_ip, &serverAddress.sin_addr) <= 0) {
cerr << "Invalid address/ Address not supported" << endl;
return 1;
}

connect(clientSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));

string msg;
cout << "Enter the message: ";
getline(cin, msg);
send(clientSocket, msg.c_str(), msg.length(), 0);
close(clientSocket);
return 0;
}
