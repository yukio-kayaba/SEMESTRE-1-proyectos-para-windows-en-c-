#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class jugadores{
	private:
		string nombre;
		int x,y;
		int personaje;
	public:
		jugadores(){
			
		}
		jugadores(int x,int y){
			this->x = x;
			this->y = y;
		}
		void dar_valores(string nombre,int x,int y,int personaje){
			this->x = x;this->y = y;this->nombre = nombre;this->personaje = personaje;
		}
		void primer_dibujo(){
			gotoxy(x,y);cout<<char(personaje);
		}
		void movimiento_Arriba(int y_o){
			int var;
			var = y;
			this->y -= y_o; 
			//gotoxy(x,var);cout<<" ";
			for(int i = var;i >= y;i--){
				gotoxy(x,i);cout<<char(personaje);
				Sleep(200);
				gotoxy(x,i+1);cout<<" ";
			}
			gotoxy(x,y);cout<<char(personaje);
		}
		int setX(){
			return x;
		}
		int setY(){
			return y;
		}
		string setNombre(){
			return nombre;
		}
		int avatar_r(){
			return personaje;
		}
};
void inicio();
void registro_jugadores();
void dibujo_grapi();
void animacion_dado();
bool meta(int x,int y);
int dado(int p);
int cont,dad;
jugadores* game_u = new jugadores[6];
int main(){
	int opc,dir_win;
	srand(time(NULL));
	bool active = true,ban;
	inicio();
	registro_jugadores();
	system("cls");
	dibujo_grapi();
	for(int i = 0;i < cont;i++){
		game_u[i].primer_dibujo();
	}
	gotoxy(25,1);cout<<"META";
	for(int i = 7;i < 50;i++){
		gotoxy(i,2);cout<<"=";
	}
	do{
		for(int t = 0;t < cont;t++){
			gotoxy(78,15);cout<<"  ";
			gotoxy(75,10);cout<<"                   ";
			gotoxy(75,10);cout<<game_u[t].setNombre()<<"  "<<char(game_u[t].avatar_r());
			gotoxy(70,14);cout<<"1. lanzar dado  2. crecer ";
			gotoxy(75,15);cout<<" + ";cin>>opc;
			animacion_dado();
			game_u[t].movimiento_Arriba(dado(opc));
			ban = meta(game_u[t].setX(),game_u[t].setY());
			if(ban){
				active = false;
				dir_win = t;
			}
		}
	}while(active);
	gotoxy(70,18);cout<<"GANADOR";
	gotoxy(75,19);cout<<game_u[dir_win].setNombre()<<" "<<char(game_u[dir_win].avatar_r());
	gotoxy(70,20);cout<<" ";
	system("pause");
}
void inicio(){
	cout<<"Hola ";
	sleep(1);
	cout<<"Bienvenido ";sleep(1);
	cout<<"a ";sleep(1);
	cout<<"mi ";sleep(1);
	cout<<"juego";sleep(1);
	cout<<" llamado ";sleep(1);
	gotoxy(50,10);cout<<"[ CARRERA MORTAL ] "<<endl;
	sleep(3);
	gotoxy(45,12);cout<<"> presione cualquier tecla < ";
	gotoxy(55,13);getch();
	system("cls");
} 
void registro_jugadores(){
	string nombre;
	int opc,avatar;
	int valor;
	do{
		gotoxy(20,5);cout<<"CUANTOS JUGADORES SE REGISTRARAN ? : ";cin>>cont;
		if(cont == 1){
			gotoxy(25,6);cout<<" No permitido ";
		}
	}while(cont == 1);
	for(int i = 0;i < cont;i++){
			gotoxy(57,8);cout<<"            ";
			gotoxy(25,8);cout<<i+1<<". jugador  Ingrese su nombre : ";
			gotoxy(57,8);cin>>nombre;
			game_u[i].dar_valores(nombre,20+(i*3),23,207+i);
	}
}
int dado(int p){
	int r;
	if(p == 2){
		r = 3 + rand()%(5);
	}else{
		r = 1 + rand()%(5);
	}
	gotoxy(78,12);cout<<r;
	return r;
}
void animacion_dado(){
	for(int i = 0;i < 10;i++){
		gotoxy(78,12);cout<<1+rand()%(5);
		Sleep(500);
	}
}
void dibujo_grapi(){
	for(int i = 2;i < 25;i++){
		gotoxy(5,i);cout<<"::";
		gotoxy(50,i);cout<<"::";
	}
	gotoxy(70,8);cout<<"[ CARRERA MORTAL ]";
	gotoxy(65,10);cout<<"Turno : ";gotoxy(70,12);cout<<"DADO : ";
}
bool meta(int x,int y){
	bool rat = false;
	for(int i = 7;i < 50;i++){
		if(x > i && (y == 2 || y == 1 )){
			rat = true;
		}
	}
	return rat;
}