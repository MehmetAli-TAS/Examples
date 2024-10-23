#include <iostream>
using namespace std;

class Nokta{ // s�n�f olu�turuldu
	public: //�zellikler eri�ilebilir yap�ld�
		int x,y;
	void degerAta(int _x, int _y){
		x = _x;
		y = _y;
	}
	void ekranaYaz() { //fonksyion
		cout<< x << "," << y <<endl;
	}
	
	bool baslangictaMi() { //true veya false d�nd�r�lecek (bool ile)
		if (x == 0 && y == 0)
			return true;
		else
			return false;
	}
};

int main() {
	Nokta n; //Nokta s�n�f� tan�mland�
	Nokta n2; //Nokta s�n�f�(2) tan�mland�
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
