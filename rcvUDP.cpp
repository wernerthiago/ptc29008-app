#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
   struct sockaddr_in myaddr;
   int sock;
   memset(&myaddr, 0, sizeof(myaddr));
   myaddr.sin_family=AF_INET;
   myaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   myaddr.sin_port=htons(0);

   //Create the socket
   if((sock=socket(AF_INET, SOCK_DGRAM, 0))<0) {
      perror("Failed to create socket");
      exit(EXIT_FAILURE);
   }

   if(bind(sock,( struct sockaddr *) &myaddr, sizeof(myaddr))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
   }
 
   inet_pton(AF_INET,"127.0.0.1",&myaddr.sin_addr.s_addr);
   myaddr.sin_port=htons(1234);

   //Receive the datagram back from server
   int addrLength(sizeof(myaddr)),received(0);
   char buffer[256] = {0};
while(true){
   if((received=recvfrom(sock, buffer, 256, 0, (sockaddr *)&myaddr, (socklen_t*)&addrLength)) < 0) {
      perror("Mismatch in number of bytes received");
      exit(EXIT_FAILURE);
   }
   buffer[received]='\0';
   std::cout << "Server (" << inet_ntoa(myaddr.sin_addr) << ") echoed: " << buffer << std::endl;
}
   close(sock);
   return 0;
}
