//kendi isim de�i�kenlerimizi olu�turma (std)

#include <iostream>
using namespace std;

namespace programci1{ //kendi isim uzay�m�z� olut�turduk
	int x = 15;
	void Boo() {
		int x = 7;
		cout<<x<<endl;
	}
}

int x = 3; //global de�i�ken

void Foo() {
	int x = 5; //yerel de�i�ken
	cout<<x<<endl;
	
}

int main() {
	int x = 10;
	cout<<programci1::x<<endl;
	Foo();
	cout<<x<<endl;
	
	return 0;
}

// kendi isim uzay�m�z� olu�turmak farkl� kodlardaki ayn� de�i�kenler
// �ak��madan istenen de�erler d�nd�r�lebilir
