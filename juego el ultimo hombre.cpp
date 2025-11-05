
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int x = 25,y=25,p_x= 22 ,p_y = 12,error = 0;
int aux_x,aux_y,al_x = 0,al_y = 0;
// variables comida
int c_x = 0,c_y = 0,alimento = 0;
char letra;
// vida 
int vida = 3;
int tabla[25][25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void tabla_D();
void mov_player(char &);
void bomba();
void comida();
void titulo();
void cont_vida();
int main(){
	int i_bom = 0,i_com = 0,i_comd = 0;
	char letra1;
	cout<<"\n\n\n\n\n\n\n";
	titulo();
	cout<<"\n\n\t\t\t\t\t"<<char(190)<<" : ES EL JUGADOR "<<endl;
	cout<<"\n\t\t\t\t\t"<<char(207)<<" : ES UN ENEMIGO "<<endl;
	cout<<"\n\t\t\t\t\t"<<char(15)<<" : ES UN ALIADO A RESCATAR "<<endl;
	cout<<"\n\t\t\t\t\t\t"<<" RESCATA A LOS 50 HOMBRES ! "<<endl;
	sleep(6);
	do{
		system("cls");
		cout<<"\n";
		titulo();
		cout<<" \n "<<endl;
		tabla_D();
		cout<<"\t\t\t\t\tHOMBRES RESCATADOS : "<<alimento<<endl;
		letra1 = getch();
		i_bom ++;i_com++;i_comd++;
		// bomba
		if(i_bom == 10){
			bomba();
			i_bom = 0;
		}
		// comida
		
		if (i_com == 23){
			comida();
			i_com = 0;
		}
		
		mov_player(letra1);
	}while(vida > 0 && alimento < 50);
	if (vida == 0){
		cout<<"\n\t\t\t AGOTASTE TUS VIDAS - PERDISTE "<<endl;
	}else if(alimento > 49){
		cout<<"\n\t\t\t FELICITACIONES COMPLETASTE LA MISION "<<endl;
	}
	sleep(4);
}
void cont_vida(){
	for(int i = 0;i < vida;i++){
		cout<<"+ ";
	}
}
void tabla_D(){
	// arriba 2 y abajo 4  
	for(int i = 1;i < x;i++){
		tabla[0][i] = 2;
		tabla[24][i] = 4;
	}
	// lados i = 6  y lado d = 8
	for(int lado_d = 1;lado_d < y ;lado_d ++){
		tabla[lado_d][0] = 6;
		tabla[lado_d][24] = 8;
	}
	tabla[0][0]=3;//lado 
	tabla[0][24]=5;
	tabla[24][0]=7;
	tabla[24][24]=9;
	tabla[p_x][p_y] = 11;
	for(int lado_x = 0;lado_x < x;lado_x ++){
		for(int lado_y = 0;lado_y < y;lado_y++){
			if(tabla[lado_x][lado_y]== 2 || tabla[lado_x][lado_y]==4){
				cout<<char(205)<<char(205);
			}else if(tabla[lado_x][lado_y]==6){
				cout<<"\t\t\t\t\t"<<char(186);
			}else if(tabla[lado_x][lado_y]== 8){
				if(lado_x == 7 && lado_y == 24){
					cout<<char(186);
					cout<<"\t vida "<<vida<<" : ";cont_vida();
				}else{
					cout<<char(186);
				}
			}else if(tabla[lado_x][lado_y] == 3){
				cout<<"\t\t\t\t\t"<<char(201);
			}else if(tabla[lado_x][lado_y] == 5){
				cout<<char(187);
			}else if(tabla[lado_x][lado_y]== 7){
				cout<<"\t\t\t\t\t"<<char(200);
			}else if(tabla[lado_x][lado_y] == 9){
				cout<<char(188);
			}else if(tabla[lado_x][lado_y] == 11){//  muestra de jugador 
				cout<<char(190)<<" ";
			}else if(tabla[lado_x][lado_y] == 12){//mostrador de bomba
				cout<<char(207)<<" ";
			}else if(tabla[lado_x][lado_y] == 10){//mostrador de alim
				cout<<char(15)<<" ";
			}else if(tabla[lado_x][lado_y] == 0){
				cout<<" "<<" ";
			}/// capa 3
			//cout<<tabla[lado_x][lado_y]<<" ";//capa 2
			//cout<<lado_x<<":"<<lado_y<<" ";//capa 1
		}cout<<"\n";
	}
}
void mov_player(char &letra){
		if(letra == 'w'){
			aux_x = p_x;
			if(tabla[p_x-1][p_y] == 12){
				vida -= 1;
				p_x -=1;
				tabla[p_x][p_y] = 11;
				tabla[aux_x][p_y] = 0;
			}else if(tabla[p_x-1][p_y] == 10){
				alimento += 1;
				p_x -=1;
				tabla[p_x][p_y] = 11;
				tabla[aux_x][p_y] = 0;
			}else if(tabla[p_x-1][p_y] == 6 || tabla[p_x-1][p_y] == 8 || tabla[p_x-1][p_y] == 2 || tabla[p_x-1][p_y] == 4){
				tabla[p_x][p_y] = 11;
				tabla[aux_x][p_y] = 0;
			}else{
			p_x -= 1;
			tabla[p_x][p_y] = 11;
			tabla[aux_x][p_y] = 0;
			}
		// otros
		}else if(letra == 's'){
			aux_x = p_x;
			if(tabla[p_x + 1][p_y] == 12){
				vida -= 1;
				p_x += 1;
				tabla[aux_x][p_y] = 0;
				tabla[p_x][p_y] = 11;
			}else if(tabla[p_x + 1][p_y] == 10){
				alimento += 1;
				p_x += 1;
				tabla[aux_x][p_y] = 0;
				tabla[p_x][p_y] = 11;
			}else if(tabla[p_x + 1][p_y] == 6 ||tabla[p_x + 1][p_y] == 8 ||tabla[p_x + 1][p_y] == 4 ||tabla[p_x + 1][p_y] == 2){//limite
				tabla[aux_x][p_y] = 0;
				tabla[p_x][p_y] = 11;
			}else{
			p_x += 1;
			tabla[aux_x][p_y] = 0;
			tabla[p_x][p_y] = 11;
			}
		// otros  sss
		}else if(letra == 'a'){
			aux_y = p_y;
			if(tabla[p_x][p_y - 1] == 12){
				vida -= 1;
				p_y -= 1;
				tabla[p_x][aux_y] = 0;
				tabla[p_x][p_y] = 11;	
			}else if(tabla[p_x][p_y - 1] == 10){
				alimento += 1;
				p_y -= 1;
				tabla[p_x][aux_y] = 0;
				tabla[p_x][p_y] = 11;
			}else if(tabla[p_x][p_y - 1] == 6 || tabla[p_x][p_y - 1] == 8 || tabla[p_x][p_y - 1] == 2 || tabla[p_x][p_y - 1] == 4){//limite
				tabla[p_x][aux_y] = 0;
				tabla[p_x][p_y] = 11;
			}else{
			p_y -= 1;
			tabla[p_x][aux_y] = 0;
			tabla[p_x][p_y] = 11;
			}
		}else if(letra == 'd'){
			aux_y = p_y;
			if(tabla[p_x][p_y + 1] == 12){
				vida -= 1;
				p_y += 1;
				tabla[p_x][aux_y] = 0;
				tabla[p_x][p_y] = 11;
			}else if(tabla[p_x][p_y + 1] == 10){
				alimento += 1;
				p_y += 1;
				tabla[p_x][aux_y] = 0;
				tabla[p_x][p_y] = 11;
			}else if (tabla[p_x][p_y + 1] == 6 || tabla[p_x][p_y + 1] == 8 || tabla[p_x][p_y + 1] == 2 || tabla[p_x][p_y + 1] == 4){
				tabla[p_x][aux_y] = 0;
				tabla[p_x][p_y] = 11;
			}else{
			p_y += 1;
			tabla[p_x][aux_y] = 0;
			tabla[p_x][p_y] = 11;
			}
		}
}
void bomba(){
	srand(time(NULL));
	al_x = 1 + rand()%24;
	al_y = 1 + rand()%24;
	tabla[al_x][al_y] = 12;
}

void comida(){
	srand(time(NULL));
	c_x = 1 + rand()%23;
	c_y = 1 + rand()%23;
	tabla[c_x][c_y] = 10;
}
void titulo(){
	for(int i = 0;i<26;i++){
		if(i==0){
			cout<<"\t\t\t\t\t\t  "<<char(201);
		}else if(i == 25){
			cout<<char(187);
		}else{
			cout<<char(205);
		}
		sleep(0.99);
	}
	cout<<"\n";
	cout<<"\t\t\t\t\t\t  "<<char(186)<<" HASTA EL ULTIMO HOMBRE "<<char(186)<<endl;
	for(int r=0;r < 26;r++){
		if(r == 0){
			cout<<"\t\t\t\t\t\t  "<<char(200);
		}else if(r == 25){
			cout<<char(188);
		}else{
			cout<<char(205);
		}
	}
}
