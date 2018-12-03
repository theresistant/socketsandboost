#include <iostream>
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

class Client1{
public:
	void test(){
		Sm1 sm1, sm2, sm3, sm4, sm5;
		string ev;

		while (true){
			cout << "Insert event:"<<endl;
			cin >> ev;

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
	}
};

int main (){
	Client1 c;
	c.test();
	return 0;
}
