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
void shoot(int dir); //1 = up, 2 = right, 3 = down, 4 = left
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

int projectileSpawnX = -1;
int projectileSpawnY = -1;

int projectileX = projectileSpawnX;
int projectileY = projectileSpawnY;

int projectileRangeY = 4;
int projectileRangeX = 7;

bool running = true;
unsigned int gameSpeedMS = 20;
unsigned int projectileUpdateSpeedMSinY = 100000;
unsigned int projectileUpdateSpeedMSinX = 50000;
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
	case 'A':		//Arrow up 1
		shoot(1);
		break;
	case 'D':		//Arrow left 4
		shoot(4);
		break;
	case 'B':		//Arrow down 3
		shoot(3);
		break;
	case 'C':		//Arrow right 2
		shoot(2);
		break;
		}
	///////////////////////////////////////////////////////////
	//if(input == 'A'){
	//	std::thread tO2(shootUp);	//HERE im attempting to fix the player-cannot-move while projectile is moving - note player position updates for all unputs while it visually does not move- after the projectile has stopped.
	//	tO2.join();
	//	shootUp();
	//} 
	//////////////////////////////////////////////////////////
	}
	
	system("stty -echo");	
	system("stty cbreak");
}

void logic(){
	
}

void shoot(int dir){
	if(dir == 1){
		projectileX = playerPosX;
		projectileY = playerPosY;
		for(int i = 0 ; i < projectileRangeY ; i++){
		projectileY -= 1;
		usleep(projectileUpdateSpeedMSinY);
		}
	projectileX = projectileSpawnX;
	projectileY = projectileSpawnY;
	}

	if(dir == 4){
        	projectileX = playerPosX;
        	projectileY = playerPosY;
        	for(int i = 0 ; i < projectileRangeX ; i++){
        	projectileX -= 1;
        	usleep(projectileUpdateSpeedMSinX);
        	}
        projectileX = projectileSpawnX;
        projectileY = projectileSpawnY;
        }
	
	if(dir == 3){                                	
        	projectileX = playerPosX;
        	projectileY = playerPosY;
        	for(int i = 0 ; i < projectileRangeY ; i++){
        	projectileY += 1;
        	usleep(projectileUpdateSpeedMSinY);
        	}
        projectileX = projectileSpawnX;
        projectileY = projectileSpawnY;
        }

	if(dir == 2){
        	projectileX = playerPosX;
        	projectileY = playerPosY;
        	for(int i = 0 ; i < projectileRangeX ; i++){
        	projectileX += 1;
        	usleep(projectileUpdateSpeedMSinX);
        	}
        projectileX = projectileSpawnX;
        projectileY = projectileSpawnY;
        }

}

void draw(){
	for(int scannerY = 0 ; scannerY < gameAreaY ; scannerY++){
		for(int scannerX = 0 ; scannerX < gameAreaX ; scannerX++){
			if(scannerY == playerPosY && scannerX == playerPosX){
				std::cout << "Y";	
			}
			else if(scannerY == projectileY && scannerX == projectileX){
				std::cout<< ".";
			}else{
				std::cout << " ";
			}			
		}
		std::cout<<""<<std::endl;
	}

	//std::cout << playerPosX << " : " << playerPosY << " Key pressed: " << input << " - " << projectileX << " : " << projectileY << std::endl;
	
	//std::cout << "Coins collected: " << coins << std::endl;
	
	std::system("clear");
}
