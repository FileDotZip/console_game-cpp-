// to compile this game, use this command -> g++ -Wall -g -std=c++0x -pthread -pedantic -Wextra -lcurses console_game.cpp

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <thread>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////
//Area for defined functions//
//////////////////////////////
void getInput();
void logic();
void draw();

//LEFT OFF GETTING PLAYER INPUT, NEXT STEP: Game Logic

//////////////////////////////
//Area for defined variables//
//////////////////////////////
int gameAreaX = 20;
int gameAreaY = 10;

int playerSpawnX = 10;
int playerSpawnY = 5;

int playerPosX = playerSpawnX;
int playerPosY = playerSpawnY;

bool running = true;
unsigned int gameSpeedMS = 20;
char input;

//int coins = 0;
//////////////////////////////
//////////////////////////////

//**Program Start**//
int main(){
		std::thread threadObj(getInput);
	while(running){ 			//Infinatly run the game
		//getInput();
		logic();
		draw();
		usleep(gameSpeedMS);
	}
		threadObj.join();
	return 0;
}

void getInput(){
	system("stty -echo");
	system("stty cbreak");

	while(running){
        input = getchar();
	switch (input){
	case 'a':
		playerPosX -= 1;
		break;
	case 'w':
		playerPosY -= 1;
		break;
	case 'd':
		playerPosX += 1;
		break;	
	case 's':
		playerPosY += 1;
		break;
		}
	}
	
	system("stty -echo");	
	system("stty cbreak");
}

void logic(){

}

void draw(){
	for(int i = 0 ; i < gameAreaY ; i++){
		for(int j = 0 ; j < gameAreaX ; j++){
			std::cout << " ";
			if(i == playerPosY && j == playerPosX){
				std::cout << "Y";
			}
		}
		std::cout<<""<<std::endl;
	}

	//std::cout << playerPosX << " : " << playerPosY << " Key pressed: " << input << std::endl;
	
	//std::cout << "Coins collected: " << coins << std::endl;
	
	std::system("clear");
}
