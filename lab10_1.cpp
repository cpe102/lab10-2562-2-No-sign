#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string grade[]={"A","B+","B","C+","C","D+","D","F","W"};

int main(){
	srand(time(0));
	int x=rand();
	cout<<"Press Enter 3 times to revel your future.";
	cin.get();
	cin.get();
	cin.get();
	cout<<"You will get "<<grade[x%9]<<" in this 261102";
	return 0;
	
}
