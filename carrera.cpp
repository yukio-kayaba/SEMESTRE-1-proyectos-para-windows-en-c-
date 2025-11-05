#include<iostream>
#include<conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void dado(int t);
void carga();
class usuario{
	private:
		string nombre;
		int x,y;
		int image;
	public:
		usuario(){
			
		}
		usuario(string nombre,int x,int y){
			this->nombre = nombre;
			this->x = x;
			this->y = y;
		}
		void registrar(int x_a,int y_a,int image_c){
			cout<<"Ingresa tu nombre por favor : ";cin>>nombre;
			x = x_a;
			y = y_a;
			image = image_c;
		}
		int setx(){
			return x;
		}
		int sety(){
			return y;
		}
		string setnombre(){
			return nombre;
		}
		int image_r(){
			return image;
		}
		void avanse_x(int x_a){
			int aux;
			aux = x;
			x += x_a;
			gotoxy(x,y);cout<<char(image);
			gotoxy(aux,y);cout<<" ";
		}
		void avanse_y(int y_a){
			int aux;
			aux = y;
			x += y_a;
			gotoxy(x,y);cout<<char(image);
			gotoxy(aux,y);cout<<" ";
		}
		void dibujar(){
			gotoxy(x,y);cout<<char(image);
		}
};

usuario* player = new usuario[5];int cant = 0,dado_m;

int main(){
	srand(time(NULL));
	string mov;
	int opc;
	int cant_p;
	cout<<"Cuantos jugadores jugaran : ";cin>>cant;
	for(int i = 0;i < cant;i++){
		player[i].registrar(3,i + 11,207 + i);
	}
	system("cls");
	
	gotoxy(30,5);cout<<"1. TIRAR\t\t 2. AUMENTAR POSIBILIDAD DE SALIR 6";
	for(int r = 0;r < cant;r++){
		player[r].dibujar();
		gotoxy((r*9)+40,2);cout<<player[r].setnombre();
	}
	for(int i = 2;i < 110;i++){
		gotoxy(i,9);cout<<char(205);
		gotoxy(i,(13+cant)-1);cout<<char(205);
	}
	for(int i = 9;i < 11 + cant;i++){
		gotoxy(110,i+1);cout<<char(177);
	}
	do{
		for(int i = 0;i < cant;i++){
			dado(i);
			carga();
			player[i].avanse_x(dado_m+1);
		}	
	}while(true);
}
void dado(int t){
	int aux,opc;
	gotoxy(50,13+cant+1);cout<<"                   "<<endl;
	gotoxy(50,13+cant+1);cout<<"Turno de "<<player[t].setnombre() <<" "<<char(player[t].image_r())<<endl;
	gotoxy(45,6);cout<<"         ";
	gotoxy(45,6);cout<<"--> ";cin>>opc;
	
	if(opc == 1){
		gotoxy(32,7);cout<<"                        ";
		dado_m = 1 + rand()%(5);
	}else if(opc == 2){
		gotoxy(32,7);cout<<"                        ";
		dado_m = 3 + rand()%(5);
	}else{
		gotoxy(32,7);cout<<"* opcion no disponible *";
	}
}
void carga(){
	gotoxy(40,8);cout<<"dado:";
	for(int i = 6;i > 1;i--){
		gotoxy(48,8);cout<<1 + rand()%(5);
		sleep(0.5);
	}
	gotoxy(48,8);cout<<dado_m;
}

