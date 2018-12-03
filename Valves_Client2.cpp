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

class Client2{
public:
	void test(){
		Sm1 sm6, sm7, sm8, sm9, sm10;
		string ev;

		while (true){
			cout << "Insert event:"<<endl;
			cin >> ev;

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
		}
	}
};

int main (){
	Client2 c;
	c.test();
	return 0;
}
