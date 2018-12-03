#include <iostream>
#include <WS2tcpip.h>
#include <sstream>
#include <conio.h>
#include <string>
#include <fstream>
#include <ctime>
#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>

using namespace std;

namespace {
	namespace msm = boost::msm;
	namespace msmf = boost::msm::front;
	namespace mpl = boost::mpl;

	//Events
	struct Open6{};
	struct Open7{};
	struct Open8{};
	struct Open9{};
	struct Open10{};
	struct Close6{};
	struct Close7{};
	struct Close8{};
	struct Close9{};
	struct Close10{};

	//State Machine
	struct Sm1_:msmf::state_machine_def<Sm1_>{
		//States
		struct Init:msmf::state<>{};
		struct Valve6:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 6 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 6 closed" << endl;
			}
		};

		struct Valve7:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 7 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 7 closed" << endl;
			}
		};

		struct Valve8:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 8 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 8 closed" << endl;
			}
		};

		struct Valve9:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 9 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 9 closed" << endl;
			}
		};

		struct Valve10:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 10 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 10 closed" << endl;
			}
		};

		//Set initial state
		typedef Init initial_state;

		//Enable deferred capability
		typedef int activate_deferred_events;

		//Transition table
		struct transition_table:mpl::vector
		<
			msmf::Row <Valve6 , Close6, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open6, Valve6, msmf::none, msmf::none>,
			msmf::Row <Valve7, Close7, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open7, Valve7, msmf::none, msmf::none>,
			msmf::Row <Valve8, Close8, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open8, Valve8, msmf::none, msmf::none>,
			msmf::Row <Valve9, Close9, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open9, Valve9, msmf::none, msmf::none>,
			msmf::Row <Valve10, Close10, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open10, Valve10, msmf::none, msmf::none>
		> {};
	};

	//Pick a back-end
	typedef msm::back::state_machine<Sm1_> Sm1;
}

class Client {
public:
	string getMessage() {
		return "Application 2 Started";
	}

	string display(){
		return "Client program 2 is alive";
	}

};

class logging{
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

bool fileExists(const char *fileName){
	ifstream infile(fileName);
	return infile.good();
}

int main()
{
	Sm1 sm6, sm7, sm8, sm9, sm10;
	//Vari�veis criadas para o nosso socket

	SOCKET sock;
	SOCKADDR_IN address;

	long ok;
	char MESSAGE[200];

	//permite inicliazar o winsock : (implementa��o do socket do windows)

	WSAData wsd;
	WORD DllVersion;
	DllVersion = MAKEWORD(2,1);
	ok = WSAStartup(DllVersion, &wsd);

	//permite criar o socket e preencher a estrutura de endere�os ip e porta

	sock = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_family = AF_INET;
	address.sin_port = htons(60000);

	while(true){
		// conectar ao servidor

		connect(sock, (SOCKADDR*)&address, sizeof(address));

		//enviar mensagem ao servidor

		/*Client c;
		int d = teste.count("log.txt");
		string r = c.display();
		teste.write_file("log.txt", r, d);

		c.display();
		cout<<"enter message:\t" << c.getMessage();
		string s = c.getMessage().c_str();
		d = teste.count("log.txt");
		teste.write_file("log.txt", s, d);
		ok = send(sock,c.getMessage().c_str(),1024,0);*/

		memset(MESSAGE, 0, sizeof(MESSAGE));

		//const char *msg = "Hello";
        //permite receber as mensagem do servidor
		ok = recv(sock, MESSAGE, sizeof(MESSAGE), 0);
		string ev;
		ev = MESSAGE;
		if (ev == "close" || ev == "Close"){
			sm6.process_event(Close6());
			sm7.process_event(Close7());
			sm8.process_event(Close8());
			sm9.process_event(Close9());
			sm10.process_event(Close10());
		} else if (ev == "open" || ev == "Open"){
			sm6.process_event(Open6());
			sm7.process_event(Open7());
			sm8.process_event(Open8());
			sm9.process_event(Open9());
			sm10.process_event(Open10());
		}

		//cin>>msg;*/
		//cout << MESSAGE;
		}
	return 0;
}
