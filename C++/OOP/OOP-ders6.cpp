#include <iostream>
using namespace std;

class Nokta{ // sýnýf oluþturuldu
	private: // kapalý alan
		int x;
		
	protected: // dýþarýdan eriþime kapalý, kalýtýma açýk ise eriþilebilir
		
		
	public: //özellikler eriþilebilir yapýldý(dýþarýdan eriþilebilir)
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
	Nokta n1; //Nokta sýnýfý tanýmlandý
	//n1.x = 5;
	n1.y = 7;
	//cout << n1.x<<endl;
	cout << n1.y<<endl;
	
	
	return 0;
}
