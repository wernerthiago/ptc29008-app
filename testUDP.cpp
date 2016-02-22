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
   //Structure for address of server
   struct sockaddr_in myaddr;
   int sock;

   //Construct the server sockaddr_ structure
   memset(&myaddr, 0, sizeof(myaddr));
   myaddr.sin_family=AF_INET;
//-----------------------------------------------------------------
// This line is correct because you want to bind an address on 
// you machine
//-----------------------------------------------------------------
   myaddr.sin_addr.s_addr=htonl(INADDR_ANY);

//-----------------------------------------------------------------
// This is the port on your machine that you are going to bind.  
// This doesn't matter because the server just returns to the port
// it received the request on.  Port zero is any port.
//-----------------------------------------------------------------
   //myaddr.sin_port=htons(9045);
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
 
//-----------------------------------------------------------------
// You need to add the code that takes the blitz.cs.niu.edu name 
// and translates it to the network address.  
// Google "getaddrinfo examples"
// or http://www.logix.cz/michal/devel/various/getaddrinfo.c.xp
//-----------------------------------------------------------------
   std::string to("blitz.cs.niu.edu");
   // Your code goes here ...

//-----------------------------------------------------------------
// But now you want to send a message to blitz.cs.niu.edu so you
// must change the value of myaddr.sin_addr.s_addr to be the network
// address of that server you want to talk to.  Using nslookup I 
// found that the IP address of blitz.cs.niu.edu is 131.156.145.90.
// Use inet_pton to turn 131.156.145.90 into an integer used in the
// socket functions
//-----------------------------------------------------------------
   inet_pton(AF_INET,"127.0.0.1",&myaddr.sin_addr.s_addr);
//-----------------------------------------------------------------
// Here is where the port matters, because you know the server is
// listening on that port.  So we must set the port number here 
// for the out going message.
//-----------------------------------------------------------------
   myaddr.sin_port=htons(1234);

//-----------------------------------------------------------------
// I don't know where the exact string is but this returns a message
//-----------------------------------------------------------------
   std::string s("funcionou");

   //send the message to server
   if(sendto(sock, s.c_str(), s.size(), 0, (struct sockaddr *)&myaddr, sizeof(myaddr))!=s.size()) {
      perror("Mismatch in number of bytes sent");
      exit(EXIT_FAILURE);
   }

   //Receive the datagram back from server
   int addrLength(sizeof(myaddr)),received(0);
   char buffer[256] = {0};
   if((received=recvfrom(sock, buffer, 256, 0, (sockaddr *)&myaddr, (socklen_t*)&addrLength)) < 0) {
      perror("Mismatch in number of bytes received");
      exit(EXIT_FAILURE);
   }
   buffer[received]='\0';
   std::cout << "Server (" << inet_ntoa(myaddr.sin_addr) << ") echoed: " << buffer << std::endl;
   close(sock);
   return 0;
}