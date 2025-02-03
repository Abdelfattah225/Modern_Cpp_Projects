// Dependencies
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>

class process
{
	public:
	int id ; 
	std::string name ;
	int priority ; 
};
class TaskManger
{
	public:
	std::stack<process> STACK ;
	std::queue<process> QUEUE;
};


/*function to print msg: 
	inputs: string
	output: nothing
*/
void print_mag(std::string msg)
{
	std::cout << msg <<"\n";
}

void print_hash()
{
	print_mag("#################################################");

}
/*function to print main screen and take an option: 
	inputs: nothing
	output: return optoin
*/
int Welcome_View()
{
	int display_optoin = 0 ;
	
	print_mag("1. Add process");
	print_mag("2. View Next Process");
	print_mag("3. Execute Process");
	print_mag("4. List all Process");
	print_mag("5. End program");
	print_hash();
	std::cin >> display_optoin ;
	return display_optoin ;

}
/*function to print add process screen and take an optoin: 
	inputs: nothing
	output: return an optoin 
*/
int add_process_view()
{
	int add_option ; 
	print_mag("1. Add to Stack");
	print_mag("2. Add to queue");
	print_hash();	
	std::cin >> add_option ;

	return add_option ;

}
/*
function to display the view nxt process screen and take and option ;
	intputs: nothing
	outputs: return an optoin
*/
int view_Next_process()
{
	int Nxt_process ;
			print_mag("1. Display Next process in stack");
			print_mag("2. Display Next process in queue");
			print_hash();

			std::cin >> Nxt_process;

			return Nxt_process ;

}
/*function print porcess info
	intputs: class(process)
	outputs: nothing
*/
void print_NXT_process(process pr)
{

	print_mag("process Id : "+std::to_string(pr.id)+", Name : "+pr.name+", and priority : "+std::to_string(pr.priority));
				// print_mag("process ID : "+ std::to_string(pr.id));
				// print_mag("Process Name: "+pr.name);
				// print_mag("Process priority: "+std::to_string(pr.priority));
	print_hash();

}
/*function to execute the process and remove it
	intputs: nothing
	outputs: return int (an option)
*/

int Execute_Next_process()
{
	int Nxt_process ;
			print_mag("1. Execute Next process in stack");
			print_mag("2. Execute Next process in queue");
			print_hash();

			std::cin >> Nxt_process;

			return Nxt_process ;

}
/*function to print all process in task manager
	intputs: class(TaskManger)
	outputs: nothing
*/

void print_all_process(TaskManger m)
{
	TaskManger s;

	//copy taksmanger 
	s = m ; 


	print_mag("stack:");

	if(s.STACK.empty()==true)
	{
		print_mag("stack is empty");
	}
	else
	{
		while(s.STACK.empty()==false)
			{
				print_mag("process Id : "+std::to_string(s.STACK.top().id)+", Name : "+s.STACK.top().name+", and priority : "+std::to_string(s.STACK.top().priority));
				s.STACK.pop();
			}
						print_hash();

	}
	print_mag("queue:");

	if(s.QUEUE.empty()==true)
	{
		print_mag("queue is empty");
	}
	else
	{
		while (s.QUEUE.empty()==false)
		{
		
				print_mag("process Id : "+std::to_string(s.QUEUE.back().id)+", Name : "+s.QUEUE.back().name+", and priority : "+std::to_string(s.QUEUE.back().priority));
				s.QUEUE.pop();							
		}
		print_hash();

	}
	
}

constexpr int add_process = 1 ;
constexpr int view_Nxt_process = 2 ;
constexpr int Execute_process = 3 ;
constexpr int List_all_process = 4 ;
constexpr int endProgam = 5 ;

constexpr int stack_option = 1 ;
constexpr int queue_option = 2 ;

int main()
{
	process pr ; 
	TaskManger Manager ; 

	int display_optoin = 0  ;
	int add_option = 0 ;
	int ID =0 ;
	std::string NAME;
	int Pro  =0;
	int Nxt_process = 0 ;
	bool display_flag = true ;







	// Dispaly
	// Add process 


	


	
print_mag("Welcome to our Program ") ; 
print_mag("#################################################");

while (display_flag)
{
	display_optoin = Welcome_View() ; 
	/**********************************************************************/
	switch (display_optoin)
	{
	case add_process:
		{
			

			add_option = add_process_view();

			print_mag("Enter process id , name and prioriy");
			std::cin >> ID ;
			std::cin >> NAME ;
			std::cin >> Pro ;

			pr.id = ID ;
			pr.name = NAME ;
			pr.priority = Pro ;

			switch (add_option)
			{
			case stack_option:

				Manager.STACK.push(pr);

				print_mag("The process added to stack successfully.");
				print_hash();

				// return to main displayfunction

				break;
			case queue_option :

				Manager.QUEUE.push(pr);

				print_mag("The process added to queue successfully.");
				print_hash();
				
				// return to main displayfunction
				break;

			default:
				print_mag("InValid optoin!!!!!!!!!!");
				print_hash();
				
				// return to main displayfunction

				break;
			}

		}
		break;
	case view_Nxt_process:
		{
			 Nxt_process = view_Next_process();

			switch (Nxt_process)
			{
			case stack_option:
				/* stack */
				pr = Manager.STACK.top();
				print_NXT_process(pr);
				break;
				/* queue */
			case queue_option:
			pr = Manager.QUEUE.back();
			print_NXT_process(pr);	
				break;
			default:
				print_mag("InValid Optoin");
				print_hash();
				break;
			}

		}
		break;
	case Execute_process:
		{
			Nxt_process = Execute_Next_process();

			switch (Nxt_process)
			{
			case stack_option:
					 Manager.STACK.pop();
					 print_mag("NXT process has been executed.");
					 print_hash();




				break;
			case queue_option:
					Manager.QUEUE.pop();
					 print_mag("NXT process has been executed.");
					 print_hash();
				break;
			default:
				print_mag("InValid Optoin");
				print_hash();
				break;
			}
		}
		break;
	case List_all_process:
		{
			print_all_process(Manager);
		}
		break;
	case endProgam:
				print_mag("program was ended");
				display_flag = false ;	
		break;
	default:
		print_mag("Invalid optoin");
		print_hash();
		break;
	}
}

}