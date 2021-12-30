

//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

/********************************************************************************************************************************************
 * Name: Muhammad Siddique Umer
 * Roll: no 21I_0519
 * Program: Rush HOur
 * *****************************************************************************************************************************************/




#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"CImg.h"

using namespace std;


/**************************************************************************************************************
 * 
 * Declaring all the variables that will used in the whole program
 * 
 * 
 ************************************************************************************************************/

bool menu=false;
bool gameover=false;
bool highscoreshower=false;
int randomize1X=0;
int randomize2X=0;
int randomize3X=0;
int randomize1Y=0;
int randomize2Y=0;
int randomize3Y=0;
int randdestinationX=0;
int randdestinationY=0;
int a=0;
int b=0;
int c=0;
int g=0;
bool check =false;
int taxi=0;

bool game1=false;
bool game2=false;
bool game3=false;
int highscore[10]={0};

vector<unsigned char> imgArray;


/**************************************************************************************************************************
 * 
 * 
 * 
 *This functions defines the initial height and width of the screen on which game will be played
 * 
 * 
 * ***********************************************************************************************************************/

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
int result=0;

int boardW = 800;
int boardH = 600;

int car_move_size = 10;
int car_size = 20;
int road_width = 1;
int padh = 5;
int padw = 3;
const int ROWS = (boardH/car_move_size)-road_width-1; // array index starts from 0;
const int COLS = (boardW/car_move_size)-car_size-padw-1; // array index starts from 0;
int xI = 0+(road_width+padw), yI = boardH-(car_size+padw);


int aI=xI;
int bI=yI;

int car_x = 0;
int car_y = 0;


// int autox2=
// int autoy2=


int d_1=20;
int d_2=500;
int score=0;
int *points=&score;
int green=0;
int welcome=0;

	
/*****************************************************************************************************************************************************
 * 
 * 
 * Following are all the functions that are used to create the cars in the game and then these functions are also called into the game display function
 * 
 * 
 * ****************************************************************************************************************************************************/
void drawCar() {
	DrawRectangle(aI, bI, 25,15, colors[OLIVE]);                           


	DrawCircle(aI+6,bI-5,5,colors[OLIVE]);
	DrawCircle(aI+18,bI-5,5,colors[OLIVE]);

	glutPostRedisplay();
}
void drawCarR() {
	DrawRectangle(aI, bI, 25,15, colors[RED]);                           


	DrawCircle(aI+6,bI-5,5,colors[RED]);
	DrawCircle(aI+18,bI-5,5,colors[RED]);

	glutPostRedisplay();
}

//function to draw a car
 
void drawCar1() {
	DrawRectangle(d_1, d_2, 25,15, colors [TOMATO]);
	DrawCircle(d_1+6,d_2-5,5,colors[TOMATO]);
	DrawCircle(d_1+18,d_2-5,5,colors[TOMATO]);
	glutPostRedisplay();
}


int autoX1=770;
int autoY1=537;
int autoX2=50;
int autoY2=240;



void auto1(){
DrawRectangle(autoX1,autoY1,25,15,colors[DARK_RED]);
DrawCircle(autoX1+6,autoY1-5,5,colors[DARK_RED]);
DrawCircle(autoX1+18,autoY1-5,5,colors[DARK_RED]);
glutPostRedisplay();
}
void auto2(){
	DrawRectangle(autoX2,autoY2,25,15,colors[BLUE]);
	DrawCircle(autoX2+6,autoY2-5,5,colors[BLUE]);
	DrawCircle(autoX2+18,autoY2-5,5,colors[BLUE]);

}


/********************************************************************************************************************************************************
 * 
 * 
 * FOllowing are the functions that are used to automatically moves the cars in the games and then these functions are also called into the timer function
 * 
 * 
 * *******************************************************************************************************************************************************/
bool TIE=true;
void moveauto1(){


	if (autoY1 > 10 && TIE) {
		autoY1 -= (car_move_size+(road_width+padw));
	
	
			
		if(autoY1 <190)

			TIE = false;

	}
	else if (autoY1 < 500 && !TIE) {
		// cout << "go right";
		autoY1 += 10;

	
		if (autoY1 > 450){
			TIE = true;
		}
	}
	
}
bool fruity=false;
void moveauto2(){

	if (autoY2 > 10 && fruity) {
		autoY2 -= (car_move_size+(road_width+padw));
	
	
			
		if(autoY2 <100)

			fruity = false;

	}
	else if (autoY2 < 300 && !fruity) {
		// cout << "go right";
		autoY2 += 10;

	
		if (autoY2 > 250){
			fruity = true;
		}
	}



}


/* *************************************************************************************************************************
*
* this function calculates the time for the game and after 180 seconds game automatically ends and total score is displayed;
*
*****************************************************************************************************************************/
int seconds=180;
void counts(int m){
	seconds--;
	if(seconds<=0){
		exit(1);
	}
	glutTimerFunc(1000,counts,0);
}










//declaring my 2d dynaimic array 

int** gameBoard = new int*[ROWS];

/******************************************************************************************************************************************
 * 
 * 
 * this screen is one of the part of the welcome screen and is displayed at the welcome and ask the user weather they want to continue or not
 * 
 * 
 * ******************************************************************************************************************************************/
 
 		
void blank(){

	glClear(GL_COLOR_BUFFER_BIT);


	DrawString(200,500,"Please right click anywhere on the screen to continue",colors[WHITE]);
		DrawString(200,500,"Please right click anywhere on the screen to continue",colors[WHITE]);

glutSwapBuffers();


}




void name (){
	glClearColor(0.0,0.0,1.0,0.0);
	//(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		//	0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); 
//	DrawString(100,500,"please enter your name ",colors[BLACK]);
	DrawString(100,500,"Press R to play with Yellow taxi",colors[BLACK]);
	//DrawString(100,400,"Press Y to play with the yellow taxi"colors[BLACK]);
	DrawString(100,300,"press S to start the game",colors[BLACK]);
	glutSwapBuffers();


}


/******************************************************************************************************************************************************

// it is the window to create the welcome screen on which different options are displayed the user can select any of the option with the help of mouse 

********************************************************************************************************************************************************/
	void welcome_display(){
	glClear(GL_COLOR_BUFFER_BIT);


	if (!menu)
	{
		
		
		{
			DrawRoundRect(250 , 500 , 160 , 40 , colors[WHITE] ,5); 
			DrawString(260 , 515 , "Start Game" , colors[WHITE]);
		}
	
		{
			DrawString(260 , 515 , "Start Game" , colors[BLACK]);
		}
	
		{
			DrawRoundRect(250 , 430 , 160 , 40 , colors[WHITE] ,5);
			DrawString(260, 440 , "High Score" , colors[BLACK]);
		}
	
		{
			DrawString(260 , 440 , "High Score" , colors[BLACK]);
		}
	
		
		{
			DrawRoundRect(250 , 350 , 160 , 40 , colors[WHITE] ,5);
			DrawString(260 , 365 , "Exit" , colors[BLACK]);
		}
		
		{
			DrawString(260 , 365 , "Exit" , colors[BLACK]);
		}
		
		
	
	}



	glutSwapBuffers();
}

///////////////////////////////////////////////////////////////
/*******************************************************************************
 * 
 * 
 * 
 * this is the fuke handling  function which will be used to display the higest 10 scores of the game
 * 
 * 
 * 
 * ****************************************************************************/
void readfromfile(){
	ofstream myfile ;
	myfile.open("Highscore.txt" ,ios:: app);
	for (int i=0;i<10;i++){
	myfile<<highscore[i]<<endl;
}
myfile.close();


fstream my_file;
	my_file.open("Highscore.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		char ch;

		while (1) {
			my_file >> ch;
			if (my_file.eof())
				break;

			cout << ch;
		}

	}
	my_file.close();

}








/*******************************************************
 * 
 * 
 * 
 * creating my 2d dynaimic array with the help of pointer of size 80*60
 * 
 * 
 * 
 * 
 * *********************************************************/


void init_gameBoard(){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			gameBoard[i][j] = 0;
		}
	}
}



/****************************************************************************************************
 * 
 * 
 * 
 * loops are used to create bulding in the screen with the help of loop i wrote 2 in the place 
 * 
 * 
 * 
 * 
 * *************************************************************************************************/

void build(){
  for(int i=31;i<=34;i++){
  	for(int j=10;j<=20;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build1(){
  for(int i=11;i<=14;i++){
  	for(int j=10;j<=20;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}

void build2(){
  for(int i=11;i<=14;i++){
  	for(int j=31;j<=46;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build3(){
  for(int i=16;i<=37;i++){
  	for(int j=31;j<=33;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build4(){
  for(int i=16;i<=37;i++){
  	for(int j=45;j<=47;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build5(){
  for(int i=43;i<=52;i++){
  	for(int j=10;j<=15;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build6(){
  for(int i=41;i<=44;i++){
  	for(int j=29;j<=36;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build7(){
  for(int i=24;i<=28;i++){
  	for(int j=24;j<=30;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build8(){
  for(int i=46;i<=54;i++){
  	for(int j=31;j<=33;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build9(){
  for(int i=4;i<=14;i++){
  	for(int j=45;j<=48;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build10(){
  for(int i=4;i<=14;i++){
  	for(int j=45;j<=48;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build11(){
  for(int i=51;i<=54;i++){
  	for(int j=18;j<=26;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}
void build12(){
  for(int i=51;i<=54;i++){
  	for(int j=48;j<=56;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}

void build13(){
  for(int i=44;i<=50;i++){
  	for(int j=55;j<=56;j++){
  		gameBoard[i][j]=2; 
  	}
  }
}


/*********************************************************************************************************************************************************************************************
*
*
*
*
/*these are the random number functions to draw passengers at different place and also the destination is also created randomly but validation is created so that passengers and destinationn does not com
on the buildings and obstacles
*
*
*
*
******************************************************************************************************************************************************************************************/

void rand1(){//creating reandom numbers for the first blue circle 
	int i=0;
		// do {
	InitRandomizer();
		
	
randomize1X=	GetRandInRange(700,750);

randomize1Y=GetRandInRange(100,200);




}
void rand2(){//creating random numbers for second blue circle
	int i=0;
	
//	do {
		
		InitRandomizer();
		
randomize2X=	GetRandInRange(8,131);
	
randomize2Y=GetRandInRange(180,555);


}
void rand3(){//creating random numbers for third blue circle
	int i=0;
	
	//do {
	//srand((unsigned) time(NULL));
	InitRandomizer();
		randomize3X =GetRandInRange(530,635);
		//randomize3X=490 + (rand() % 635);
	//	randomize3Y=160 + (rand() % 400);

	 randomize3Y=  GetRandInRange(160,350);

	
}



void green_circle(){
//creating random numbers for first green circle

	int i=0;
	
	// do {
	
 	InitRandomizer();
		randdestinationX=GetRandInRange(150,430);

		randdestinationY=GetRandInRange(337,440);



}
/***************************************************************************************************************************************************
 * 
 * 
 * 
 * These are the functions that will create random passengers on the screen then our taxi will go the repective circle and press enter and a random destinatoin
 * will be created.
 * 
 * ************************************************************************************************************************************************/
 void passenger1(){
 	DrawCircle(randomize1X,randomize1Y,10,colors[BLUE]);
 }

 void passenger2(){

 		
 		DrawCircle(randomize2X,randomize2Y,10,colors[BLUE]);
 		
 }
 void passenger3(){

 		
 		DrawCircle(randomize3X,randomize3Y,10,colors[BLUE]);
 	
 }
void Green_circle(){

	DrawCircle(randdestinationX,randdestinationY,10,colors[GREEN]);
}









/*************************************************************
 * 
 * 
 * printing my array on the console to see the results and act accordinlgy
 * 
 * 
 * ********************************************************/


void printArray(){
	cout<<"-=-=-==-=-=-=-=-==-==-=-=-=-=-=-=-=-="<<endl;
	for(int i=0;i<ROWS;i++){
		for(int j =0;j<COLS;j++){
			cout<<gameBoard[i][j];
		}
		cout<<endl;
	}
}


 /******************************************************************************************************************
  * 
  * 
  * these are the functions used to draw tress on the map
  * 
  * 
  * ***************************************************************************************************************/
void draw_tree(){
	DrawCircle(640,505,8,colors[GREEN]);
	DrawLine(640,505,643,480,5,colors[BROWN]);
	DrawCircle(700,107,8,colors[GREEN]);
	DrawLine(700,107,700,90,5,colors[BROWN]);
	DrawCircle(441,355,8,colors[GREEN]);
	DrawLine(441,351,443,340,5,colors[BROWN]);
	DrawCircle(178,180,8,colors[GREEN]);
	DrawLine(178,174,178,160,5,colors[BROWN]);
	


}





/*
 * Main Canvas drawing function.
 * */
				
	std::string str = to_string(score);



void scores();




	

/*********************************************************************************************************************************
 * 
 * 
 * this is my main game function display screen all the obstacles cars, buildings and andthing drawn on the screen is called into this function
 * 
 * 
 * 
 * ******************************************************************************************************************************/

void GameDisplay()/**/{
	//set the background color using function glClearColor.
	//to change the background play with the red, green and blue values below.
	//Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.


	glClearColor(0.8, 0.8, 0.8, 1.0);
	//(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		//	0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	
	
	
	
	
	 




	


/*********************************************************************************************
 * 
 * 
 * here I am converting the integer score into string to display the score in the form of string on the screen
 * 
 * 
 * 
 * ****************************************************************************************/

//Display Score
	DrawString( 50, 550, "Score=", colors[BLACK]);
DrawString(450,550,"time:"+ to_string(seconds)+"seconds",colors[BLACK]);
	DrawString( 120, 550, str, colors[BLACK]);






/******************************************************************************************************
 * 
 * 
 * here  I am drawing lines behind the screen to display roads with the help of this single loop all the roads on the 
 * map are created.
 * 
 * 
 * ***************************************************************************************************/
   int x=4;
int line=x*car_move_size;
while (line<boardW){
	line=x*car_move_size;
	DrawLine(line,00,line,750,1,colors[BLACK]);
	x=x+4;

}

/*******************************************************************************************************
 * 
 * 
 * these are the black buldings that are displayed in the game main screen
 * 
 * 
 * ****************************************************************************************************/


  DrawRectangle( 150   , 250 ,  150 , 30 , colors[BLACK] );
 DrawRectangle( 150   , 450 ,  150 , 30 , colors[BLACK] );
 DrawRectangle( 450  , 450 ,  210 , 30 , colors[BLACK] );
   DrawRectangle( 450  , 210 ,  30 , 210 , colors[BLACK] );
   DrawRectangle( 420  , 150 ,  100 , 30 , colors[BLACK] );

   DrawRectangle( 650  , 210 ,  30 , 210 , colors[BLACK] );
    DrawRectangle( 350 , 310 ,  100 , 30 , colors[BLACK] );
     DrawRectangle( 450 , 50 ,  30 , 80 , colors[BLACK] );
     DrawRectangle( 650 , 450 ,  30 , 100 , colors[BLACK] );
     DrawRectangle( 778 , 50 ,  20, 100 , colors[BLACK] );
      DrawRectangle( 650  , 50 ,  210 , 30 , colors[BLACK] );
    DrawRectangle( 265 , 50 ,  120 , 30 , colors[BLACK] );
 


      DrawRectangle( 150 , 70 ,  80 , 90, colors[BLACK] );



     scores();
     




auto1();
auto2();






 
      srand((unsigned) time(0));
    
      if (check==0)
    passenger1();
if (check==0){
      passenger2();
   }
   if (check==0){
      passenger3();
   }
      

if (g==1 or  g%2!=0 )
{
	Green_circle();
	

}
if (a%2==0 )
{
	
	
	passenger1();
	a=a+1;




}
if (b%2==0 ){
	
	
	
	passenger2();
	b=b+1;
}
if (c%2==0 ){
	

	passenger3();
	c=c+1;
}


	// cimg_library::CImg<unsigned char>image1("tree-1578.pgm");
 //  cimg_library::CImg<unsigned char> image2("tree-1578.pgm");  // blue square
 //    (image1,image2).display();
// cimg_library::CImg<unsigned char> image1("tree-1578.pgm");
// int width=200;
// int height=400;
// //unsigned char* ptr = src.data(100,100); 
// (image1).display();



//CImgDisplay& display	(	const CImg< T > & 	"tree-1578.pgm"	)	





draw_tree();


	
	
	drawCar();
	drawCar1();

if (taxi==1){

	drawCarR();
}

	glutSwapBuffers(); // do not modify this line..


}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.

 *
 * */void NonPrintableKeys(int key, int x, int y) {   /***************************************************************************************************** 

 	                                                 
 	
                                                      * this function is used to move the taxi into all four directions 
                                                      * 
                                                      *  
                                                      * ****************************************************************************************************/
 	



	
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//aI -= car_move_size;
		int temp = aI-(car_move_size+(road_width+padw));
		if (gameBoard[car_x][car_y-1]==2){

*points=*points-1;
		}
		if((gameBoard[car_x][car_y-1]!=2 and gameBoard[car_x][car_y-1]!=3)){
			
		if(!(temp<=road_width)){
			aI -= (car_move_size+(road_width+padw));
				cout<<aI<<"  ";
cout<<bI<<"  ";
			gameBoard[car_x][car_y] = 0;
			car_y-=1;
			gameBoard[car_x][car_y] = 1;

		}
	}
}

	else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		//aI += car_move_size;
		int temp = aI+(car_move_size+(road_width+padw));
		if (gameBoard[car_x][car_y+1] == 2){
		*points=*points-1;
		}
		if((gameBoard[car_x][car_y+1]!=2 and gameBoard[car_x][car_y+1] != 3)){
		
		if(!(temp>=boardW-road_width-car_size)){
			aI += (car_move_size+(road_width+padw));
			gameBoard[car_x][car_y] = 0;
			car_y+=1;
			cout<<aI<<"  ";
			cout<<bI<<"   ";
			gameBoard[car_x][car_y] = 1;
		}
	}
}

		// if(gameBoard[car_x][car_y]==2){
		// 		aI -= (car_move_size+(road_width+padw));
		// }
	else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		//bI += car_move_size;
		int temp = bI+(car_move_size);
		
		if (!(temp>=boardH-road_width-padh-car_move_size)){
			if (gameBoard[car_x-1][car_y]==2){
				*points=*points-1;
			}
			if((gameBoard[car_x-1][car_y]!=2 and gameBoard[car_x-1][car_y]!=3)){
			bI+=(car_move_size);
			cout<<aI<<"  ";
cout<<bI<<"  ";
			if (car_x>=1){
				gameBoard[car_x][car_y] = 0;
				car_x-=1;
				gameBoard[car_x][car_y] = 1;  
			}
		}
}
}
	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		//bI -= car_move_size;
		int temp = bI-(car_move_size);
		
		if (!(temp<=(road_width))){
			if ( gameBoard[car_x+1][car_y]==2){
				*points=*points-1;
			}
		if((gameBoard[car_x+1][car_y]!=2 and gameBoard[car_x+1][car_y]!=3)){
			bI-= (car_move_size);
			cout<<aI<<"  ";
			cout<<bI<<"  ";
			if (car_x<ROWS-1){
				gameBoard[car_x][car_y] = 0;
				car_x+=1;
				gameBoard[car_x][car_y] = 1;
			}
		}
			cout<<endl<<"ROWS="<<ROWS<<" CAR="<<car_x<<endl;
		}
	
}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	printArray();
	 if (aI==d_1 and bI==d_2){
	 *points=*points-2;
 }
 if (aI==autoX1 and bI==autoY1){
*points=*points-2;
}
  if (aI==autoX2 and bI==autoY2){
 	*points=*points-2;
}
if (aI>772 ){
	*points=*points-1;
}
if (bI<20 or bI>570){
	*points=*points-1;
}

	glutPostRedisplay();



}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.*/
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}

else if (key==32 and (aI>700 and aI<750) and (bI>100 and bI<200)){
	a+=1;
	g++;

	rand1();
	check=false;
}
	if (key==32 and (aI>8 and aI<131) and (bI>180 and bI<555)){
	b+=21;
  g++;

	rand2();
	check=false;
}
if (key==32 and (aI>530 and aI<635) and (bI>160 and bI<350)){
	c+=1;
	g++;

	rand3();
	check=false;
}
else if (key==32 and (aI>150 and aI<430) and (bI>337 and bI<445)){
	check=false;

*points=*points+5;
g--;
a--;
b--;
c--;



green_circle();


}
if (key=='r' or key=='R'){

taxi+=1;
}
if (key=='s' or key=='S' ){
	glutDisplayFunc(GameDisplay);
}




}
/******************************************************************************
 * 
 * 
 * This function is used to display the score of the player at the top of the window
 * 
 * 
 * ********************************************************************************/
void scores(){

	 str = to_string(score);
	 DrawString( 120, 550, str, colors[BLACK]);
	

}





 int m_1=5;
  int m_2=4;

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
//it is a function to move the car in auto mode.
bool flag = true;
void moveCar() {
	
	if (d_1 > 10 && flag) {
		d_1 -= (car_move_size+(road_width+padw));
	
		// cout << "going left";
			// gameBoard[m_1][m_2]=0;
					m_2-=1;
      //gameBoard[m_1][m_2]=3;
			
		if(d_1 <100)

			flag = false;

	}
	else if (d_1 < 400 && !flag) {
		// cout << "go right";
		d_1 += 10;

	// gameBoard[m_1][m_2]=0;
	m_2+=1;
		 //gameBoard[m_1-1][(m_2)]=3;
	
		//printArray();
	
	
		if (d_1 > 350){
			flag = true;
		}
	}
	
}
// it is the timer function

void Timer(int m) {

	// implement your functionality here

	moveCar();
	// moveauto2();
	moveauto1();
	moveauto2();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

/***************************************************************************************************************
 * 
 * 
 * 
 * 
 * by using mouse the user can select the options from the welcome screen
 * 
 * 
 * 
 * 
 * 
 * ************************************************************************************************************/
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON  and (x>200 and x<410) and (y>77 and y<97))// dealing only with left button
			
	// and (x>240 and x<410) and (y>77 and y<97))// dealing only with left button
			{
// glutDisplayFunc(GameDisplay);
glutDisplayFunc(name);
//if (key_t=='s')
{


}
}


 if (button == GLUT_LEFT_BUTTON and (x>250 and x<410) and (y>205 and y<255)){

exit(1);
}


	 if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			
			// cout<<"Right Button Pressed"<<endl;
			{
		glutDisplayFunc(welcome_display); // tell library which function to call for drawing Canvas.//my welcome screen display funcition
}

	
	glutPostRedisplay();
}
















/*
 * our gateway main function
 * */


/******************************************************************************************************************
 * it is the main function in which all the function have been called 
 * ***************************************************************************************************************/
int main(int argc, char*argv[]) {

// 	cout<<"please enter the color of the car"<<endl;
// cin>>global;

	int width = boardW, height = boardH; // i have set my window size to be 800 x 600

	for(int i=0;i<ROWS;i++){
		gameBoard[i] = new int[COLS];
	}

 readfromfile();//file handling function have been called into main


	init_gameBoard();// game board functnio called into main
	
	gameBoard[car_x][car_y] = 1;


rand1();/***************************************************************************************************/
rand2(); //these are the random number functions called into main         
rand3();
green_circle();
passenger1();
passenger2();
passenger3();
green_circle();//function to display the destination of passenger on to the main have been called into main


cout<<"randomize X"<<endl;
cout<<randomize1X<<"  ";

cout<<randomize2X<<"  "<<randomize3X<<"  "<<"X"<<randdestinationX<<"  "<<endl;
cout<<"randomizey"<<endl;

cout<<randomize1Y<<"  "<<endl;

cout<<randomize2Y<<"  "<<randomize3Y<<"  "<<"y"<<randdestinationY<<"  "<<endl;

 //img
// ReadImage("tree-1578.pgm", imgArray);
// cout<<"size of img "<<imgArray.size();
// glRasterPos2i(100,100);
// glDrawPixels(64,64, GL_RGB, GL_UNSIGNED_INT, &imgArray);

//////////////////
 


////////////////////

	build();/*****************************************************************************************************/
	build1();//these are the buildings fuctions called into main
	build2();
	build3();
	build4();
	build5();
	build6();
	build7();
	build8();
	build9();
	build10();
	build11();
	build12();
	build13();



	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Muhammad Umer"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

glutDisplayFunc(blank);


//glutDisplayFunc(welcome_display);
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	

 





//////////////////////////////////////
		glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.


	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
scores();

	glutTimerFunc(100.0, Timer, 0);
	glutTimerFunc(1000.0, counts, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	
	
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */

