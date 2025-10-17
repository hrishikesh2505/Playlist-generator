#include<iostream>
using namespace std;
int main() {
	int choice;
	bool running= true;
	while(running){
		cout<<"Menu:"<<endl;
		cout<<"1. Start Game"<<endl;
		cout<<"2. Load Game"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Starting new game..."<<endl;
				// Add code to start a new game
				break;
			case 2:
				cout<<"Loading game..."<<endl;
				// Add code to load a game
				break;
			case 3:
				cout<<"Exiting..."<<endl;
				running = false;
				break;
			default:
				cout<<"Invalid choice. Please try again."<<endl;
		}
	}
	return 0;
}