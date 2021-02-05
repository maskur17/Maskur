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

	void turn1();
	void turn2();
	void turn3();

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
	bool cekBarisJadi1();
    bool cekKolomJadi1();
    bool cekDiagonalJadi1();

	bool cekBarisJadi2();
    bool cekKolomJadi2();
    bool cekDiagonalJadi2();

	bool cekBarisJadi3();
    bool cekKolomJadi3();
    bool cekDiagonalJadi3();

void gameover();

//Variabel Global
	int p, q, r, s, t, size;
	int score1, score2;
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
    system("cls");
	if(t > 3){
		printf("WRONG INPUT NUMBER.\n");
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
	printf("player 1 : %d          player2: %d \n", score1, score2);
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
	turn1();

}

void papan2com(){
	size=5;
	persiapanPapan();
	system("pause");
}

void papan2ply(){
	size=5;
	persiapanPapan();
	turn2();
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
    turn3();
}


void turn1(){
	int x=0, y=0;
	score1=0; score2=0;
	bool karakter = true;
	while (score1 != t+2 && score2 != t+2){
	while(cekKolomJadi1() && cekBarisJadi1() && cekDiagonalJadi1 && cekPenuh()){
        inputPlayer1(x, y);
        dispPapan();
        karakter = (cekKolomJadi1() && cekBarisJadi1() && cekDiagonalJadi1 && cekPenuh());
    if (!karakter){
        score1 ++;
        system("cls");
        break ;
    }
        system("cls");
        dispPapan();
        inputPlayer2(x, y);
        dispPapan();
        karakter = (cekKolomJadi1() && cekBarisJadi1() && cekDiagonalJadi1 && cekPenuh());
    if (!karakter){
        score2 ++;
        system("cls");
        break ;
    }
        system("cls");
        dispPapan();
    }
    persiapanPapan();
}
}

void inputPlayer1(int i, int j){
	int x, y;
	printf("\n Pilihan Anda ");
	printf("\n Player1 : ");
	scanf("%d %d", &x, &y);
	i = x; j = y;
	prepan[i][j]='X';
}

void inputPlayer2(int i, int j){
	int x, y;
        printf("\n Pilihan Anda ");
        printf("\n Player2 : ");
        scanf("%d %d", &x, &y);
        i = x; j = y;
        prepan[i][j]='O';
}

void dispPapan(){
int i, j;
printf("player 1 : %d          player2: %d \n", score1, score2);
    for (i = 0; i< size;i++){
		for(j=0; j< size; j++){
            printf("%c | ", prepan[i][j]);
}
            printf("\n");
}
}

bool cekPenuh(){
    int angka = 0;
    bool penuh = true;
    for (int i = 1; i < size; i++){
    for (int j = 1; j < size; j++){
        if (prepan[i][j] !='_'){
            angka ++;
}
}
}   if (angka == 9){
    return false;
}   else {
    return true;
}
}

bool cekBarisJadi1(){
    for (int i = 1; i < size; i++){
    if (prepan[i][1]== 'X'&& prepan[i][2]=='X'&& prepan[i][3]=='X'){
        return false;
    }else if (prepan[i][1]== 'O'&& prepan[i][2]=='O'&& prepan[i][3]=='O'){
        return false;
    }
    }
    return true;
}

bool cekKolomJadi1(){
    for (int i = 1; i < size; i++){
    if (prepan[1][i]== 'X'&& prepan[2][i]=='X'&& prepan[3][i]=='X'){
        return false;
    }else if (prepan[1][i]== 'O'&& prepan[2][i]=='O'&& prepan[3][i]=='O'){
        return false;
    }
    }
    return true;
}

bool cekDiagonalJadi1(){
    for (int i = 1; i < size; i++){
    if (prepan[1][1]== 'X'&& prepan[2][2]=='X'&& prepan[3][3]=='X'){
        return false;
    }else if (prepan[1][3]== 'O'&& prepan[2][3]=='O'&& prepan[3][3]=='O'){
        return false;
    }
    }
    return true;
}

void turn2(){
	int x=0, y=0;
	score1=0; score2=0;
	bool karakter = true;
	while (score1 != t+2 && score2 != t+2){
	while(cekKolomJadi2() && cekBarisJadi2() && cekDiagonalJadi2 && cekPenuh()){
        inputPlayer1(x, y);
        dispPapan();
        karakter = (cekKolomJadi2() && cekBarisJadi2() && cekDiagonalJadi2 && cekPenuh());
    if (!karakter){
        score1 ++;
        system("cls");
        break ;
    }
        system("cls");
        dispPapan();
        inputPlayer2(x, y);
        dispPapan();
        karakter = (cekKolomJadi2() && cekBarisJadi2() && cekDiagonalJadi2 && cekPenuh());
    if (!karakter){
        score2 ++;
        system("cls");
        break ;
    }
        system("cls");
        dispPapan();
    }
    persiapanPapan();
}
}

void turn3(){
	int x=0, y=0;
	score1=0; score2=0;
	bool karakter = true;
	while (score1 != t+2 && score2 != t+2){
	while(cekKolomJadi3() && cekBarisJadi3() && cekDiagonalJadi3 && cekPenuh()){
        inputPlayer1(x, y);
        dispPapan();
        karakter = (cekKolomJadi3() && cekBarisJadi3() && cekDiagonalJadi3 && cekPenuh());
    if (!karakter){
        score1 ++;
        system("cls");
        break ;
    }
        system("cls");
        dispPapan();
        inputPlayer2(x, y);
        dispPapan();
        karakter = (cekKolomJadi3() && cekBarisJadi3() && cekDiagonalJadi3 && cekPenuh());
    if (!karakter){
        score2 ++;
        system("cls");
        break ;
    }
        system("cls");
        dispPapan();
    }
    persiapanPapan();
}
}


bool cekBarisJadi2(){
    for (int i = 1; i < size; i++){
    if (prepan[i][1]== 'X'&& prepan[i][2]=='X'&& prepan[i][3]=='X' && prepan[i][4]=='X'){
        return false;
    }else if (prepan[i][1]== 'O'&& prepan[i][2]=='O'&& prepan[i][3]=='O' && prepan[i][4]=='O'){
        return false;
    }
    }
    return true;
}

bool cekKolomJadi2(){
    for (int i = 1; i < size; i++){
    if (prepan[1][i]== 'X'&& prepan[2][i]=='X'&& prepan[3][i]=='X'&& prepan[4][i]=='X'){
        return false;
    }else if (prepan[1][i]== 'O'&& prepan[2][i]=='O'&& prepan[3][i]=='O'&& prepan[4][i]=='O'){
        return false;
    }
    }
    return true;
}

bool cekDiagonalJadi2(){
    for (int i = 1; i < size; i++){
    if (prepan[1][1]== 'X'&& prepan[2][2]=='X'&& prepan[3][3]=='X'&& prepan[4][4]=='X'){
        return false;
    }else if (prepan[1][3]== 'O'&& prepan[2][3]=='O'&& prepan[3][3]=='O'&& prepan[4][4]=='O'){
        return false;
    }
    }
    return true;
}

bool cekBarisJadi3(){
    for (int i = 1; i < size; i++){
    if (prepan[i][1]== 'X'&& prepan[i][2]=='X'&& prepan[i][3]=='X' && prepan[i][4]=='X'&& prepan[i][5]=='X'){
        return false;
    }else if (prepan[i][1]== 'O'&& prepan[i][2]=='O'&& prepan[i][3]=='O' && prepan[i][4]=='O'&& prepan[i][5]=='O'){
        return false;
    }
    }
    return true;
}

bool cekKolomJadi3(){
    for (int i = 1; i < size; i++){
    if (prepan[1][i]== 'X'&& prepan[2][i]=='X'&& prepan[3][i]=='X'&& prepan[4][i]=='X'&& prepan[5][i]=='X'){
        return false;
    }else if (prepan[1][i]== 'O'&& prepan[2][i]=='O'&& prepan[3][i]=='O'&& prepan[4][i]=='O'&& prepan[5][i]=='O'){
        return false;
    }
    }
    return true;
}
bool cekDiagonalJadi3(){
    for (int i = 1; i < size; i++){
    if (prepan[1][1]== 'X'&& prepan[2][2]=='X'&& prepan[3][3]=='X'&& prepan[4][4]=='X'&& prepan[5][5]=='X'){
        return false;
    }else if (prepan[1][3]== 'O'&& prepan[2][3]=='O'&& prepan[3][3]=='O'&& prepan[4][4]=='O'&& prepan[5][5]=='O'){
        return false;
    }
    }
    return true;
}
