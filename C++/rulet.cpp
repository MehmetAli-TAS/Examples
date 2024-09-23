#include <cstdlib> 
#include <iostream>
#include <unistd.h>

using namespace std;

int rulet(string person,int val,int bullet){
	if(val == bullet){
		cout<<" game over!"<<endl;
		cout<<"**************"<<endl;
		sleep(2);
		return 1;
	}else{
		cout<<" empty bullet!"<<endl;
		cout<<"*************"<<endl;
		sleep(2);
		return 0;
	}
}


int main() {
  string name;
  int conc = 0;
  cout<<"name: ";
  cin>>name;
  sleep(1);
  int highest = 6, lowest = 1;
  int value = highest - lowest + 1;
  int random_number = srand();
  int bullet = (random_number % 6)+1;
  cout<<"***start game***"<<endl;
  cout<<endl;
  sleep(2);
  cout<<bullet<<" "<<rand<<endl;
  	for(int i = 1; i<=6; i++){
  		if(i%2 == 0){
		  cout<<name<<"-->";
  		  int conc = rulet(name, i, bullet);
		  }else{
		  	cout<<"croupier"<<"-->";
  			int conc = rulet("croupier", i, bullet);
		  }
		  
		if(conc == 1){
			break;
		}

	  }


  return 0;
}
