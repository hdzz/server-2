
#include"c_asyn_server.h"
int main()
{

     printf("start server\n");
     Server *iterSer=new Iterative_Server();

     iterSer->run();
     return 0;



     // nothing works
     int sockfd,connfd,n;
     pid_t pid;
     sockfd=buildConnection(PORT);
     char  rec[MAX],send[MAX];
     while(true)
     {
          connfd=accept(sockfd,NULL,NULL);
              
	  echo(connfd);
         /* if((pid=fork())==0)
          {
               close(sockfd);
               echo(connfd);
          }
          close(connfd);
	  */
     }
     close(sockfd);

}     




