#include"c_iterative_client.h"

/*
主要功能是创建一个到服务器的链接
参数是 ip 和 端口，char* 和int的
返回一个大于0的套接字，如果小于0，表示失败。会输出错误信息
*/
int buildConnection(char * addr,int port)
{
     int sockfd;
     struct sockaddr_in serv;


     if ((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
     {
          outerr("new socket() error\n");
          exit(0);
     }

     bzero(&serv,sizeof(serv));

     serv.sin_family=AF_INET;
     serv.sin_port=htons(port);

     if(inet_pton(AF_INET,addr,&serv.sin_addr)<=0)
     {
          outerr("ip address error in inet_pton()\n");
          return -1; //error
     }

     if (connect (sockfd,(struct sockaddr *)&serv,sizeof(serv))<0)
     {
          outerr("connection error\n");
          return -1;//error
     }

     return sockfd;
}


int clientReadWrite(int skn)
{
     // to do
     int n;
     char buf[MAX],rec[MAX];
     fgets(buf,MAX,stdin);
     write(skn,buf,strlen(buf));
     while((n=read(skn,rec,MAX))>0)
     {
          rec[n]=0;
          if(fputs(rec,stdout)==EOF)
               printf("puts error\n");
          printf("exit while in clientRW\n");
     }
     if(n<0)
          outerr("read return 0\n");
     return 0;
}

