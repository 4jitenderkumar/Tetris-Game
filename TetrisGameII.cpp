  #include<iostream>
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<cwchar>
#include<vector>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int matrix[25][25]={0}; //23*24     
int x,y,prev_x,prev_y;//initially x and y is at 1,12 position
int current_piece,current_piecetype=0;
char direction,control;      
void gotoxy(int y,int x)
{
	  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay()
{
	int i;
	for(i=1;i<=10000000;i++)
	{
	}
	for(i=1;i<=10000000;i++)
    {
	}
		for(i=1;i<=10000000;i++)
	{
	}
	for(i=1;i<=10000000;i++)
    {
	}
		for(i=1;i<=10000000;i++)
    {
	}
}
void changecolor(int color)
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
SetConsoleTextAttribute(hStdOut,color);
	
}	
void font()
{
				CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X =0 ;                   // Width of each character in the font
cfi.dwFontSize.Y = 30;                  // Height
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
int pieces [7 /*kind */ ][4 /* rotation */ ][5 /* horizontal blocks */ ][5 /* vertical blocks */ ] =
{
// Square
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },
 
// I
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}, 
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
  ,
// L
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// L mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
 
 
 
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// T
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
};
int piece_color(int pc){
	if(pc==0)
	return 5;
	if(pc==1)
	return 9;
		if(pc==2)
	return 10;
		if(pc==3)
	return 11;
		if(pc==4)
	return 12;
		if(pc==5)
	return 13;
		if(pc==6)
	return 14;
	
}

int random_piece(int lower,int upper){
	return((rand() %(upper - lower + 1)) + lower);
}
void print_piece(int perma_print){
int startx=x,starty;//because y is in centre so we want to print thar piece array from 0,0
changecolor(piece_color(current_piece));//changecolor for every piece
for(int i=0;i<5;i++){
	starty=y-2;
	for(int j=0;j<5;j++){
	//gotoxy(startx,starty);
	if(pieces[current_piece][current_piecetype][i][j]==1){
	gotoxy(startx,starty);
	cout<<"O";
    } 
	starty++;
    }
    startx++;
}
//delay
if(perma_print==0){
delay();
startx=x;	
for(int i=0;i<5;i++){
	starty=y-2;
	for(int j=0;j<5;j++){
	gotoxy(startx,starty);
	if(pieces[current_piece][current_piecetype][i][j]==1)
	cout<<" ";
	starty++;
    }
    startx++;
}		
}//end perma_print		
}//end
void generate_piece(){
x=1,y=12;//init position of piece
control='s';//init the control is down
current_piece=random_piece(0,6);//range of 7 pieces	
current_piecetype=0;// by default first piece type is always 0
print_piece(0);
}
void unshow_level(int level){//clear the level
	for(int j=1;j<=23;j++){
	gotoxy(level,j);
	cout<<" ";	
	}
}
void show_level(int level){//will show the modified level
for(int j=1;j<=23;j++){
changecolor(matrix[level][j]);
gotoxy(level,j);
cout<<"O";	
}		
}//end
void down_levels(int level){
for(int j=1;j<=23;j++){
matrix[level+1][j]=matrix[level][j];//update level
}
//show_level
show_level(level+1);
//unshow_level
unshow_level(level);
}
void del_level(int level){
	
for(int i=level;i>=2;i--){//lowering all upper levels
int count=0;
for(int j=1;j<=23;j++){
	if(matrix[i][j]!=0)
	count++;
}
if(count==0)//if we are on top of the blocks then no need to check further
return;
else
down_levels(i);//this fun will down the level	
}


}//end
void check_level(){
	int count;
for(int i=22;i>=2;i--){
	count=0;
	for(int j=1;j<=23;j++){
		if(matrix[i][j]!=0)
		count++;
	}
	if(count==0)//if we are on top of the blocks then no need to check further
	return;
	if(count==23){//if level is found
	    unshow_level(i);
		del_level(i-1);
	}	
}	
}
void update_matrix(){
int startx=x,starty;//because y is in centre so we want to print thar piece array from 0,0
for(int i=0;i<5;i++){
	starty=y-2;
	for(int j=0;j<5;j++){
	gotoxy(startx,starty);
	if(pieces[current_piece][current_piecetype][i][j]==1)
	{
		matrix[startx][starty]=piece_color(current_piece);//updating new piece in matrix
	}
	starty++;
    }
    startx++;
}		
}		
bool check_boundary(){//1-23
int startx=x,starty=y;
for(int i=0;i<5;i++){
	starty=y-2;
	for(int j=0;j<5;j++){
	if(pieces[current_piece][current_piecetype][i][j]==1)
	{
	if(starty>=24 || starty<=0)	
	return true;	//if piece is touching is boundary
	}
	starty++;
    }
    startx++;
}
return false;//if piece is not touching boundary	
}
bool pieceat_bottom(int startx){
	if(startx==22)
	return true;
	else
	return false;
}
bool check_set(){
if(control!='s')//if piece is moving left or rigth then no action
return false;
int startx=x,starty;
for(int i=0;i<5;i++){
	starty=y-2;
	for(int j=0;j<5;j++){
	gotoxy(startx,starty);
	if(pieces[current_piece][current_piecetype][i][j]==1)
    {
    	if(pieceat_bottom(startx))//if piece is toucing bottom of the matrix
    	return true;
    	if(matrix[startx+1][starty]!=0)
    	return true;//is piece is valid
    }
	starty++;
    }
    startx++;
}
return false;//if piece is not valid
}
bool check_overlapping(){
	int startx=x,starty;//because y is in centre so we want to print thar piece array from 0,0
for(int i=0;i<5;i++){
	starty=y-2;
	for(int j=0;j<5;j++){
	gotoxy(startx,starty);
	if(pieces[current_piece][current_piecetype][i][j]==1)
	{
		if(matrix[startx][starty]!=0)
		return true;//if piece is overl with matrix
	}
	starty++;
    }
    startx++;
}
return false;//if piece is not overl with matrix
}
void movement(){
	if(check_boundary()){//if piece is touching boundary then no action
	x=prev_x;y=prev_y;//reset the value of x and y beacuase it is not valid move
	return;
    }
    if(check_overlapping()){//if piece is overlappinf with matrix
    x=prev_x;y=prev_y;
    return;
    }
	if(check_set()){//if piece is setelled in matrix then no action
	update_matrix();//update new piece in matrix
	check_level();
	print_piece(1);
	generate_piece();// generating new piece at top
	return;
    }
	print_piece(0);//if movement of piece is valid then print the piece
}
void left(){
	y--;
	movement();
	control='s';//reset the value of control necause piece is always moving down
}             
void right(){
	y++;
	movement();
	control='s';//reset the value of control necause piece is always moving down
}           
void down(){
	x++;
	movement();
	control='s';//reset the value of control necause piece is always moving down
}           
void rotate(){
	int temp_type=current_piecetype;
	if(current_piecetype==3){
		current_piecetype=0;
	}
	else
	{
		current_piecetype++;
	}
if(check_boundary() || check_overlapping()){// if in any case rotation is false then do nothing
current_piecetype=temp_type;	
}
if(check_set()){
	update_matrix();//update new piece in matrix
	check_level();
	print_piece(1);
	generate_piece();// generating new piece at top
return;
}
print_piece(0);//if rotation is valid
	control='s';//reset the value of control necause piece is always moving down
}
void game(){
	while(1){
		if(kbhit()){
		control=getch();
		prev_x=x;//saving value of prev x
		prev_y=y;//saving value of prev y                 
		switch(control){
			case 'a':
				       left();break;
			case 'd':
			           right();break;
			case 's':  
			           down();break;
		    case 'z':
			           rotate();break;
			default:
			           break;		    		   	       
		}
	}
	else{
		down();//beacuase piece is always moving down if user is not pressing any key
	}
}	
}
void make_boundary(){
	changecolor(15);
    for(int i=0;i<=23;i++)//vertical line left	
	{
	matrix[i][0]=-1;
	gotoxy(i,0);
	cout<<"|";	
	}
	for(int i=0;i<=23;i++)//vertical line right	
	{
	matrix[i][24]=-1;	
	gotoxy(i,24);
	cout<<"|";
	}
	for(int i=0;i<=24;i++)//horizonal line up	
	{
	matrix[0][i]=-1;	

	gotoxy(0,i);
	cout<<"!";
	}
	for(int i=0;i<=24;i++)//horizonal line down	
	{
	matrix[23][i]=-1;	
	gotoxy(23,i);
	cout<<"!";
	}	
}
int main()
{
	srand(time(0));//to avoid sequence same random numbers every time
	font();
    make_boundary();
     generate_piece();//generate piece when game is starting
	 game();
    getchar();
	return 0;
}

