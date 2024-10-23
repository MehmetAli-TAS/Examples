#include <iostream>
using namespace std;

class Nokta{ // sýnýf oluþturuldu
	public: //özellikler eriþilebilir yapýldý
	int x,y;
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
	Nokta n2; //Nokta sýnýfý(2) tanýmlandý
	Nokta* n3; // pointer tanýmlandý
	Nokta* n4;
	Nokta array[10];
	Nokta* pArray;
	pArray = new Nokta[10]; 
	n4 = new Nokta();
	n3 = &n2;
	
	for(int i =0; i<10; i++){
		array[i].degerAta(i,i+2);
		(pArray + sizeof(Nokta)*i)->degerAta(i+5,i+10);
	}
	for(int i =0; i<10; i++){
		array[i].ekranaYaz();
		(pArray + sizeof(Nokta) * i)->ekranaYaz();
		cout <<endl;
	}
	
	
	n1.x = 0;
	n1.y = 5;
	
	n1.degerAta(2, 7);
	
	n2.degerAta(1 ,0);
	n2.ekranaYaz();
	
	if(n2.baslangictaMi()){
		cout<<"n2 noktasi baslangicta"<<endl;
	}
	
	cout << n1.x <<endl;
	
	cout <<"n3 pointer ile yazlan degerler"<<endl;
	n3->ekranaYaz();
	
	n4->degerAta(100, 200);
	cout<<"n4 pointer degerleri ekrana yaz"<<endl;
	n4->ekranaYaz();
	
	
	
	
	
	
	return 0;
}
