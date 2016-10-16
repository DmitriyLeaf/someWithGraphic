# include <graphics.h>
# include <iostream>
# include <windows.h>
# include <time.h>
# include <conio.h>
# include <fstream>
# include "main_a.h"

using namespace std;

int main (){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	//initwindow(400, 300, "First Sample");
	
	Object Earth;
	Earth.draw_object();
	
	Animal Human("human.txt");
	Human.putch_object();
	Human.draw_object("yes");
	
	Animal Elf(200, 200, 0, 0, "elf.txt", 100, 20, 10);
	Elf.putch_object();
	Elf.draw_object("yes");
	
	Animal Bird(100, 100, 0, 0, "bird.txt", 10, 1, 10);
	Bird.putch_object();
	Bird.draw_object("yes");
	
	while (true){
		if (kbhit() == true){
			Human.move_wasd();
			Human.check_animal(Earth.width, Earth.height);
			//Elf.move_ijkl();
			//Elf.check_animal(Earth.width, Earth.height);
			
			cleardevice();
			
			Earth.draw_object();
			Human.draw_object("yes");
			Elf.draw_object("yes");
			Bird.draw_object("yes");
		}
	}
	
	system ("PAUSE");
	closegraph();
}
