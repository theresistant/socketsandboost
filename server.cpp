/*
 * server.cpp
 *
 *  Created on: 01/12/2018
 *      Author: Admin
 */
#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>
#include <string>


//pragma comment ( "-lws2_32")

using namespace std;



int main()
{
	SOCKET ConSock;
	SOCKET ListenSock;
	SOCKADDR_IN address;

	long ok;



	//ofstream myfile("log.txt");
	//myfile.close();


	int addrsize = sizeof(address);
	WSAData wsd;
	WORD DllVersion;
	DllVersion = MAKEWORD(2,2);
	 ok = WSAStartup(DllVersion, &wsd);

	//ConSock = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_addr.s_addr = inet_addr ("127.0.0.1");
	address.sin_family = AF_INET;
	address.sin_port = htons (60000);

	ListenSock = socket(AF_INET, SOCK_STREAM, 0);

	bind(ListenSock, (SOCKADDR*)&address, sizeof(address));

	listen(ListenSock, SOMAXCONN);

	cout<<"server waiting for connections\n\n";


	//ConSock = accept(ListenSock, (SOCKADDR*)&address, &addrsize);

	while(true)
	{
		int ConSock;
		struct sockaddr_in client_addr;
		socklen_t sin_size;

		char MESSAGE[4096];

		sin_size = sizeof(struct sockaddr_in);

		if (ConSock = accept(ListenSock, (SOCKADDR*)&address, &addrsize))

		{

			/*{

				cout <<"server receive connection from:\t " <<inet_ntoa(client_addr.sin_addr) << ";"
						<< ntohs (client_addr.sin_port) << endl;
			}*/

			//ok = recv(ConSock, MESSAGE, sizeof(MESSAGE), 0);

			  	  	//cout << string(MESSAGE, 0, ok) << endl;

			  	  //int sendto (int s, char MESSAge, int len, int flags, struct sockaddr *to,
			  	  			//int tolen) ;

			  	 //send(ConSock, MESSAGE, ok+ 1, 0, struct sockaddr *to );


			//ok = recv(ConSock, MESSAGE, sizeof(MESSAGE), 0);

			cout << "Sock: " << ListenSock;



		}

	}

}



