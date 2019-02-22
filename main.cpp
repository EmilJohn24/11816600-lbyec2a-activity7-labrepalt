#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "console.h"
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void getCenter(int &center_x, int &center_y);
void drawHorizontal(int &length, int start_x, int start_y);
void drawVertical(int &length, int start_x, int start_y);
void drawSquare(int &side, int color);
void squareFamilyDraw(int &count, int &upperBound);

int main() {
	int count = 4;
	int upperBound = 30;
	setWindowSize(51, 51);


	drawSquare(upperBound, TGREEN);
	squareFamilyDraw(count, upperBound);
}

void getCenter(int &center_x, int &center_y){
	int size_x, size_y;
	getLargestWindowSize(&size_x, &size_y);
	center_x = size_x / 2;
	center_y = size_y / 2;
}

void drawHorizontal(int &length, int start_x, int start_y){
	gotoxy(start_x, start_y);
	for (int i = 0; i != length; i++){	
		printf("*");
		gotoxy(start_x + i, start_y);
	}
}

void drawVertical(int &length, int start_x, int start_y){
	gotoxy(start_x, start_y);
	for (int i = 1; i != length + 1; i++){
		printf("*");
		gotoxy(start_x, start_y - i);
	}
}
void drawSquare(int &side, int color){
	int center_x, center_y;
	getCenter(center_x, center_y);
	drawVertical(side, center_x, center_y);
	int halfSide = (int)side / 2;
	drawHorizontal(side, center_x - halfSide, center_y - halfSide);
	drawHorizontal(side, center_x - halfSide, center_y + halfSide);
	drawVertical(side, center_x - halfSide, center_y - halfSide);
	drawVertical(side, center_x + halfSide, center_y - halfSide);
}

void squareFamilyDraw(int &count, int &upperBound){
	srand(time(NULL));
	int side;
	for (int i = 0; i != count; i++){
		side = rand() % (upperBound - 20) + 20;
		drawSquare(side, TYELLOW);
	}
}


