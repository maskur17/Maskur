/*	PROGRAM		: TICTACTOE.c
	AUTHOR		: DIMAS KURNIAWAN & MUHAMAD ARYADIPPURA
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>

//Modul Utama
	void gameTictoe();
	void setPapan();
	void setLevel();
	void setMode();
	void setScore();
	void turn();
	void inputPlayer1(int i, int j);
	void inputPlayer2(int i, int j);
	void dispPapan();

	void papan1();
	void papan2();
	void papan3();

	void papan1com();
	void papan2com();
	void papan3com();
	void papan1ply();
	void papan2ply();
	void papan3ply();
	void persiapanPapan();
	bool cekPenuh();
	bool cekJadi();


//Variabel Global
	int p, q, r, s, t, size;
	char prepan [6][6];


int main()
{
menu:
    printf("\n================================");
    printf("\n                                ");
    printf("\n          TIC TAC TOE");
    printf("\n                                ");
    printf("\n================================");
    printf("\n [1] Play Game	  [2] Exit Game");
    printf("\n Pilihan anda : "); scanf("%d", &p);
    system("cls");
	 switch(p)
{
    case 1 :
        setPapan();
    break;

    case 2 :
	printf("\n BYE :)");
	break;
	default:
        printf("WRONG INPUT NUMBER.\n");
        system("pause");
        goto menu;
	}
	return 0;
}
void setMode()
{
    printf("\n==================================================");
    printf("\n                                ");
    printf("\n  		Mode permainan");
    printf("\n                                ");
    printf("\n==================================================");
    printf("\n [1] Player vs komputer   [2] Player vs player");
    printf("\n Pilihan anda : "); scanf("%d", &r);
    system("cls");
	switch(r)
{
    case 1:
	//
        printf("player vs komp \n");
        setLevel();
        system("cls");
	break;
	//
    case 2:
	//
        printf("player vs player \n");
        setScore();
        system("cls");
	break;
	//
	default:
		printf("WRONG INPUT NUMBER.\n");
        system("pause");
        setMode();
}
}

void setLevel(){
    printf("\n==================================================");
    printf("\n                                ");
    printf("\n  			level ");
    printf("\n                                ");
    printf("\n==================================================");
    printf("\n [1] Easy 	 [2] Medium		[3] Hard");
    printf("\n Pilihan anda : "); scanf("%d", &s);
    system("cls");
	if(s > 3){
		printf("WRONG INPUT NUMBER.\n");
        system("pause");
        setLevel();
    }else{
        system("cls");
        setScore();
}
}

void setScore() {
    printf("\n==================================================");
    printf("\n                                ");
    printf("\n  			Score limit ");
    printf("\n                                ");
    printf("\n==================================================");
    printf("\n [1] 3     	   [2] 4	        	[3] 5");
    printf("\n Pilihan anda : "); scanf("%d", &t);
//printf("\n%d\n", t);
    system("pause");
    system("cls");
	if(t > 3){
		printf("WRONG INPUT NUMBER.\n");
        system("pause");
        setScore();
    }else{
        system("cls");
        gameTictoe();
}
}

void setPapan() {
	printf("\n==================================================");
	printf("\n                                ");
	printf("\n  		Pilih papan permainan");
	printf("\n                                ");
	printf("\n==================================================");
	printf("\n [1] ukuran 3x3  [2] ukuran 4x4   [3] ukruan 5x5");
	printf("\n Pilihan anda : "); scanf("%d", &q);
	system("cls");
	if(q > 3){
		printf("WRONG INPUT NUMBER.\n");
        system("pause");
        	system("cls");
			setPapan();
	}else{	setMode();
}
}

void gameTictoe(){
	switch(q){
		case 1:
		papan1();
		break;
		case 2:
		papan2();
		break;
		case 3:
		papan3();
		break;

}
}

void papan1(){
    switch(r){
    case 1:
        papan1com();
	break;
    case 2:
        papan1ply();
	break;
}
}

void papan1com(){
	size=4;
	persiapanPapan();
}

void persiapanPapan(){
	int i, j;
	char prepBar = '0';
	char prepKol = '1';
	for (i = 0; i< size;i++){
		for(j=0; j< size; j++){
			if(i==0){
				prepan[i][j]= prepBar;
				prepBar++;
			}else if(j==0){
				prepan[i][j]= prepKol;
				prepKol++;
		}else {
			prepan[i][j]='_';
              }
            printf("%c | ", prepan[i][j]);
}
            printf("\n");
}
}

void papan2(){
	switch(r){
    case 1:
        papan2com();
	break;
    case 2:
        papan2ply();
	break;
}
}

void papan1ply(){
	size=4;
	persiapanPapan();
	system("pause");
	turn();

}

void papan2com(){
	size=5;
	persiapanPapan();
	system("pause");
}

void papan2ply(){
	size=5;
	persiapanPapan();
	system("pause");
}

void papan3(){
switch(r){
    case 1:
        papan3com();
	break;
    case 2:
        papan3ply();
	break;
}
}

void papan3com(){
	size=6;
	persiapanPapan();
	system("pause");
}

void papan3ply(){
	size=6;
	persiapanPapan();
	system("pause");
}


void turn(){
	int x=0, y=0;
	do{
	inputPlayer1(x, y);
	dispPapan();
	system("cls");
	dispPapan();
	inputPlayer2(x, y);
	dispPapan();
	system("cls");
	dispPapan();
	}
while(1);
}

void inputPlayer1(int i, int j){
	int x, y;
	printf("Pilihan Anda : ");
	scanf("%d %d", &x, &y);
	i = x; j = y;
	prepan[i][j]='X';
}

void inputPlayer2(int i, int j){
	int x, y;
        printf("Pilihan Anda : ");
        scanf("%d %d", &x, &y);
        i = x; j = y;
        prepan[i][j]='O';
}

void dispPapan(){
int i, j;
    for (i = 0; i< size;i++){
		for(j=0; j< size; j++){
            printf("%c | ", prepan[i][j]);
}
            printf("\n");
}
}

bool cekPenuh(){
	cekJadi();
}

bool cekJadi(){
}
