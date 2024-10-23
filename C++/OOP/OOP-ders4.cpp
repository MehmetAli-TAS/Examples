//kendi isim deðiþkenlerimizi oluþturma (std)

#include <iostream>
using namespace std;

namespace programci1{ //kendi isim uzayýmýzý olutþturduk
	int x = 15;
	void Boo() {
		int x = 7;
		cout<<x<<endl;
	}
}

int x = 3; //global deðiþken

void Foo() {
	int x = 5; //yerel deðiþken
	cout<<x<<endl;
	
}

int main() {
	int x = 10;
	cout<<programci1::x<<endl;
	Foo();
	cout<<x<<endl;
	
	return 0;
}

// kendi isim uzayýmýzý oluþturmak farklý kodlardaki ayný deðiþkenler
// çakýþmadan istenen deðerler döndürülebilir
