/*******************************************
 This program demonstrates plotting of the
 projectile motion problem. Given a velocity
 and departure angle, plot the motion of the
 projectile. 
 
 The program is currently configured for
 a maximum horizontal and vertical distances
 depending on the window size. if window size
 is 50 rows x 100 columns, the vertical and 
 horizontal distances that can be displayed
 are 50m and 100m, respectively.

*******************************************/

#include <stdio.h>
#include "console.h"
#include <math.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
int plotProjectile(int maxx, int maxy, float v, float ang, float tmax);
void plotGroundLine(int maxx, int maxy, int range_1, int range_2);
void createRange(int &range_1, int &range_2, int &max);
void victory();
void defeat();
#define MAX_ATTEMPTS 5

int attempts = 0;

int main() {
  float v,ang;
  int maxx,maxy;
  int range_1, range_2;
  getLargestWindowSize(&maxy,&maxx);
  setWindowSize(maxy,maxx);
  createRange(range_1, range_2, maxx);
  plotGroundLine(maxx,maxy, range_1, range_2);
  gotoxy(0, 0);
  printf("Attempt # %d\n", attempts);
  printf("Velocity (m/s)? ");
  scanf("%f",&v);
  printf("Angle (0-90deg)? ");
  scanf("%f",&ang);
  ang = ang*M_PI/180;
  int last_x = plotProjectile(maxx,maxy-1,v,ang,maxx/v);
  if (last_x >= range_1 && last_x <= range_2) victory();
  else if (attempts == MAX_ATTEMPTS) defeat();
  else{
	  attempts++;
	  getch(); // pause until keypress 
	  system("cls");
	  main();
	}
  
  return 0;
}

void victory(){
	gotoxy(51, 51);
	printf("GOOD JOB! You win!");
	system("pause");
	exit(0);
	
}

void defeat(){
	gotoxy(51, 51);
	printf("YOU LOSE!");
	system("pause");
	exit(0);
}



void plotGroundLine(int maxx, int maxy, int range_1, int range_2) {
	int i;
	gotoxy(0,maxy-1);

	for (i=0;i<maxx;i++) {
		
		if (i >= range_1 && i <= range_2){
			textcolor(TGREEN);
		}
		
		printf("-");
		textcolor(TWHITE);
	}	
}



void createRange(int &range_1, int &range_2, int &max){
	srand(time(NULL));
	range_1 = rand() % max - 1;
	range_2 = (rand() % (max - range_1)) + range_1;
}

int plotProjectile(int maxx, int maxy, float v, float ang, float tmax) {
  int x, y, steps=100;
  int last_x;
  float t;
  textcolor(TYELLOW);
  // set up a loop to iterate time
  // from 0 to tmax. x and y for
  // each time value is calculated
  // and plotted. the increment is
  // tmax/steps
  for (t=0;t<tmax;t+=tmax/steps) {
    x = v*t*cos(ang);
    y = (v*t*sin(ang) - 9.81*t*t/2);
    // check if the calculated x and y
    // values are within the window.
    // if yes, plot *
    if ((x>0)&&(y>0)&&(x<maxx)&&(y<maxy)) {
      gotoxy(x,maxy-y);
    	last_x = x;

      printf("*");
    }
    // adds a delay of 30 ms
    Sleep(50);
    //system("timeout -t 1 /NOBREAK >nul");
  
  }
  
  return last_x; 
}
