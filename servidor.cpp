#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>
#include <string>
#include <ctime>
#include <fstream>

//pragma comment ( "-lws2_32")

using namespace std;

/*class logging{
public:

	void write_file(string file, string msg, int counter){

		ofstream myfile(file, ios::app );

		time_t now = time(0);
		char* dt = ctime(&now);

		if (myfile.is_open()){
			myfile << counter << " " << msg << " " << dt;
			//myfile << dt << " ";
			//myfile << msg ;
			myfile.close();
		}
	}

	int count(string file){
		ifstream myfile(file);
		int counter=0;
		string s;

		while(!myfile.eof()){
			getline(myfile, s);
			counter+=1;
		}
		return counter;

	}

};

bool fileExists(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}

*/

int main()
{
	SOCKET ConSock;
	SOCKET ListenSock;
	SOCKADDR_IN address;

	string msg;

	long ok;

	//logging fich;


	//ofstream myfile("log.txt");
	//myfile.close();

	/*bool exist;

	exist = fileExists("log.txt");
	if (!exist){
	  ofstream myfile("log.txt");
	  myfile.close();
	}*/

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

	listen(ListenSock, 5);

	cout<<"server waiting for connections \n";


	//ConSock = accept(ListenSock, (SOCKADDR*)&address, &addrsize);

	int arr[10];
	int i = 0;
	int ConSock1;
	string m;

	while(true)
	{
		//struct sockaddr_in client_addr;
		//socklen_t sin_size;

		char MESSAGE[100];

		//sin_size = sizeof(struct sockaddr_in);

		ConSock1 = accept(ListenSock, (SOCKADDR*)&address, &addrsize);

		arr[i] = ConSock1;

			/*{

				cout <<"server receive connection from:\t " <<inet_ntoa(client_addr.sin_addr) << ";"
						<< ntohs (client_addr.sin_port) << endl;
			}*/



			/*ok = recv(ConSock, MESSAGE, sizeof(MESSAGE), 0);

			cout << string(MESSAGE, 0, ok) << endl; */

			  	  //int sendto (int s, char MESSAge, int len, int flags, struct sockaddr *to,
			  	  			//int tolen) ;

			  	 //send(ConSock, MESSAGE, ok+ 1, 0, struct sockaddr *to );

			if (i == 2 || i == 3){
				memset(MESSAGE, 0, sizeof(MESSAGE));
				ok = recv(ConSock1, MESSAGE, sizeof(MESSAGE), 0);
				m = MESSAGE;
			}


			cout << m;
			/*cout << "ConSock: " << ConSock;
			arr[i] = ConSock;

			msg = MESSAGE;
			cout<<"Client says: "<<msg<<endl;

			//memset(MESSAGE, 0, sizeof(MESSAGE));

			//ok = send(ConSock, MESSAGE, sizeof(MESSAGE), 0);

			/*int c = fich.count("log.txt");
			fich.write_file("log.txt", msg, c);


			/*string reply;
			cout<<"Enter Reply:\t";
			cin>>reply;*/

			/*const char* s = msg.c_str();
			ok = send(ConSock, s, 1024, 0);*/

				//cout << "Number: " << i << "Sock: " << arr[i];

		if (i == 2){
			for(int c=0; c <= 2; c++){
				ConSock1 = arr[c];
				ok = send(ConSock1, m.c_str(), sizeof(m), 0);
			}
		}
		if (i == 3){
			for(int c=0; c <= 2; c++){
				ConSock1 = arr[c];
				ok = send(ConSock1, m.c_str(), sizeof(m), 0);
			}
		}
		i++;

	}

}

