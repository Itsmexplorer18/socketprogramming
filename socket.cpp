#include <iostream>
#include <winsock.h>
using namespace std;
#define PORT 9909
struct sockaddr_in srv;
fd_set fr,fw,fe;
int main(){
    WSADATA ws;
    int nRet=0;
    if(WSAStartup(MAKEWORD(2,2),&ws)<0){
        cout<<"startup failed"<<endl;
                exit(EXIT_FAILURE);

    }
    else {
        cout<<"sucessful"<<endl;
    }
    int nSocket= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(nSocket<0){
        cout<<"NOT FOUND"<<endl;
                exit(EXIT_FAILURE);

    }
    else {
        cout<<"successful"<<" socket id is"<<nSocket<<endl;
    }
    srv.sin_family=AF_INET;
    srv.sin_port=htons(PORT);
    srv.sin_addr.s_addr=INADDR_ANY;
    memset(&(srv.sin_zero),0,8);
    nRet=bind(nSocket,(sockaddr*)&srv,sizeof(sockaddr));
    if(nRet<0){
        cout<<"unsucessful binding to the local port"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        cout<<"successful binding"<<endl;
    }
    nRet=listen(nSocket,5);
      if(nRet<0){
        cout<<"failed to start to listen to the local port"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        cout<<"successful listned to the local port"<<endl;
    }

}

