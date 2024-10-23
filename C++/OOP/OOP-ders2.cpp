#include <iostream>
using namespace std;

class Nokta{ // sýnýf oluþturuldu
	public: //özellikler eriþilebilir yapýldý
		int x,y;
	void degerAta(int _x, int _y){
		x = _x;
		y = _y;
	}
	void ekranaYaz() { //fonksyion
		cout<< x << "," << y <<endl;
	}
	
	bool baslangictaMi() { //true veya false döndürülecek (bool ile)
		if (x == 0 && y == 0)
			return true;
		else
			return false;
	}
};

int main() {
	Nokta n; //Nokta sýnýfý tanýmlandý
	Nokta n2; //Nokta sýnýfý(2) tanýmlandý
	n.x = 0;
	n.y = 5;
	
	n.degerAta(2, 7);
	
	n2.degerAta(0 ,0);
	n2.ekranaYaz();
	
	if(n2.baslangictaMi()){
		cout<<"n2 noktasi baslangicta"<<endl;
	}
	
	cout << n.x <<endl;
		
	return 0;
}
