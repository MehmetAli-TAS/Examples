#include <iostream>
using namespace std;

class Nokta{ // s�n�f olu�turuldu
	private: // kapal� alan
		int x;
		
	protected: // d��ar�dan eri�ime kapal�, kal�t�ma a��k ise eri�ilebilir
		
		
	public: //�zellikler eri�ilebilir yap�ld�(d��ar�dan eri�ilebilir)
	int y;
	void degerAta(int, int);	

	void ekranaYaz();
	
	bool baslangictaMi();
};


void Nokta::degerAta(int _x,int _y){
	x = _x;
	y = _y;
}

void Nokta::ekranaYaz(){
	cout<<x<<","<<y<<endl;
}

bool Nokta::baslangictaMi(){
	return x == 0 && y == 0;
}

int main() {
	Nokta n1; //Nokta s�n�f� tan�mland�
	//n1.x = 5;
	n1.y = 7;
	//cout << n1.x<<endl;
	cout << n1.y<<endl;
	
	
	return 0;
}
