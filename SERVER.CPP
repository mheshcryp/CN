#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

using namespace std;

int main()
{
int serverSocket=socket(AF_INET,SOCK_STREAM,0);
sockaddr_in serverAddress;
serverAddress.sin_family=AF_INET;
serverAddress.sin_port=htons(8080);
serverAddress.sin_addr.s_addr=INADDR_ANY;

bind(serverSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
listen(serverSocket,5);
int clientSocket=accept(serverSocket,nullptr,nullptr);
char buff[1000]={0};
recv(clientSocket,buff,sizeof(buff),0);
cout<<buff<<endl;
close(serverSocket);
return 0;
}
