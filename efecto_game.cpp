#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}
void efecto_entrada();
int main(){
	efecto_entrada();
}
void efecto_entrada(){
	char letra[] = "BIENVENIDO  EH AQUI ALGUNAS INTRUCCIONES";
	string aux;
	int cant_da = 0;
	for(int i = 0;i < strlen(letra);i++){
		aux += letra[i];
		system("cls");
		gotoxy(40 - i,10);cout<<"|| "<<aux<<" ||";
		//gotoxy(45 + i,10);cout<<"||";
		Sleep(100);
	}
	cant_da = strlen(letra);
	sleep(4);
	for(int i = 0;i < strlen(letra);i++){
		gotoxy((40 - cant_da) + i,10);cout<<"|| "<<aux;
		gotoxy((43 + cant_da) - i,10);cout<<"||";
	}
}

/*
/*if(codigo ==  3 or codigo == 26){
		switch(1 + rand()%(15)){
			case 1: leer.open("casualidad\\1.txt",ios::in);break;
			case 2: leer.open("casualidad\\2.txt",ios::in);break;
			case 3: leer.open("casualidad\\3.txt",ios::in);break;
			case 4: leer.open("casualidad\\4.txt",ios::in);break;
			case 5: leer.open("casualidad\\5.txt",ios::in);break;
			case 6: leer.open("casualidad\\6.txt",ios::in);break;
			case 7: leer.open("casualidad\\7.txt",ios::in);break;
			case 8: leer.open("casualidad\\8.txt",ios::in);break;
			case 9: leer.open("casualidad\\9.txt",ios::in);break;
			case 10: leer.open("casualidad\\10.txt",ios::in);break;
			case 11: leer.open("casualidad\\11.txt",ios::in);break;
			case 12: leer.open("casualidad\\12.txt",ios::in);break;
			case 13: leer.open("casualidad\\13.txt",ios::in);break;
			case 14: leer.open("casualidad\\14.txt",ios::in);break;
			case 15: leer.open("casualidad\\15.txt",ios::in);break;
		}
		if(leer.fail()){
			gotoxy(85,13);cout<<"error al abrir archivo"<<endl;
			sleep(1);
		}
		while(!leer.eof()){
			getline(leer,cartas.letra);
		}
		leer.close();
		gotoxy(85,13);cout<<"CASUALIDAD ";
		gotoxy(85,14);cout<<cartas.letra;
	}else if(codigo == 8){
		
	}else{
		switch(codigo){
			case 1: leer.open("propiedades\\1.txt");break;
			case 2: leer.open("propiedades\\2.txt");break;
			case 4: leer.open("propiedades\\4.txt");break;
			case 5: leer.open("propiedades\\5.txt");break;
			case 6: leer.open("propiedades\\6.txt");break;
			case 7: leer.open("propiedades\\7.txt");break;
			case 9: leer.open("propiedades\\9.txt");break;
			case 10: leer.open("propiedades\\10.txt");break;
			case 11: leer.open("propiedades\\11.txt");break;
			case 12: leer.open("propiedades\\12.txt");break;
			case 13: leer.open("propiedades\\13.txt");break;
			case 14: leer.open("propiedades\\14.txt");break;
			case 15: leer.open("propiedades\\15.txt");break;
			case 16: leer.open("propiedades\\16.txt");break;
			case 17: leer.open("propiedades\\17.txt");break;
			case 19: leer.open("propiedades\\19.txt");break;
			case 20: leer.open("propiedades\\20.txt");break;
			case 21: leer.open("propiedades\\21.txt");break;
			case 23: leer.open("propiedades\\23.txt");break;
			case 24: leer.open("propiedades\\24.txt");break;
			case 26: leer.open("propiedades\\26.txt");break;
			case 27: leer.open("propiedades\\27.txt");break;
			case 28: leer.open("propiedades\\28.txt");break;
			case 29: leer.open("propiedades\\29.txt");break;
			case 30: leer.open("propiedades\\30.txt");break;
			case 31: leer.open("propiedades\\31.txt");break;
			case 32: leer.open("propiedades\\32.txt");break;
			case 33: leer.open("propiedades\\33.txt");break;
			case 34: leer.open("propiedades\\34.txt");break;
			case 35: leer.open("propiedades\\35.txt");break;
		}
		if(!leer.is_open()){
			gotoxy(85,13);cout<<"error al abrir archivo"<<endl;
			sleep(1);
		}else{
			leer>>propiedad.nombre_casa>>propiedad.cobro_casa>>propiedad.precio_casa>>propiedad.hipoteca;
			leer.close();
			gotoxy(85,13);cout<<"NOMBRE: "<<propiedad.nombre_casa;
			gotoxy(85,14);cout<<"COBRO CASA : "<<propiedad.cobro_casa;
			gotoxy(85,15);cout<<"HIPOTECA CASA : "<<propiedad.hipoteca;
			gotoxy(85,16);cout<<"PRECIO CASA :"<<propiedad.precio_casa;
		}	
	//}
	/*