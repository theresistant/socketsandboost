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
	struct Open1{};
	struct Open2{};
	struct Open3{};
	struct Open4{};
	struct Open5{};
	struct Close1{};
	struct Close2{};
	struct Close3{};
	struct Close4{};
	struct Close5{};

	//State Machine
	struct Sm1_:msmf::state_machine_def<Sm1_>{
		//States
		struct Init:msmf::state<>{};
		struct Valve1:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 1 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 1 closed" << endl;
			}
		};

		struct Valve2:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 2 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 2 closed" << endl;
			}
		};

		struct Valve3:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 3 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 3 closed" << endl;
			}
		};

		struct Valve4:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 4 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 4 closed" << endl;
			}
		};

		struct Valve5:msmf::state<>{
			template <class Event, class Fsm>
			void on_entry(Event const&, Fsm&) const{
				cout << "Valve 5 openned" << endl;
			}
			template <class Event, class Fsm>
			void on_exit(Event const&, Fsm&) const{
				cout << "Valve 5 closed" << endl;
			}
		};

		//Set initial state
		typedef Init initial_state;

		//Enable deferred capability
		typedef int activate_deferred_events;

		//Transition table
		struct transition_table:mpl::vector
		<
			msmf::Row <Valve1, Close1, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open1, Valve1, msmf::none, msmf::none>,
			msmf::Row <Valve2, Close2, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open2, Valve2, msmf::none, msmf::none>,
			msmf::Row <Valve3, Close3, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open3, Valve3, msmf::none, msmf::none>,
			msmf::Row <Valve4, Close4, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open4, Valve4, msmf::none, msmf::none>,
			msmf::Row <Valve5, Close5, Init, msmf::none, msmf::none>,
			msmf::Row <Init, Open5, Valve5, msmf::none, msmf::none>
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
	Sm1 sm1, sm2, sm3, sm4, sm5;
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


		memset(MESSAGE, 0, sizeof(MESSAGE));

		//permite receber as mensagem do servidor
		ok = recv(sock, MESSAGE, sizeof(MESSAGE), 0);
		string ev;
		ev = MESSAGE;
		//cin>>msg;*/
		//cout << MESSAGE;
		if (ev == "close" || ev == "Close"){
			sm1.process_event(Close1());
			sm2.process_event(Close2());
			sm3.process_event(Close3());
			sm4.process_event(Close4());
			sm5.process_event(Close5());
		} else if (ev == "open" || ev == "Open"){
			sm1.process_event(Open1());
			sm2.process_event(Open2());
			sm3.process_event(Open3());
			sm4.process_event(Open4());
			sm5.process_event(Open5());
		}

	}
	return 0;
}

