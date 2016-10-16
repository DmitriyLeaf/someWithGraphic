# include <graphics.h>
# include <iostream>
# include <windows.h>
# include <time.h>
# include <conio.h>
# include <fstream>

using namespace std;

class Object{
	public:
		int coord_x;
		int coord_y;
		int width;
		int height;
		char *body_file;
		int body[100][100];
		
		void putch_object(){
			//const char *body_file = "body.txt";
			ifstream fin(body_file);
			char ch, ch_2, ch_3;
			int i = 0, j = 0;
			while(fin.get(ch)){
				fin.get(ch_2);
				fin.get(ch_3);
				body[i][j] = (ch-'0')*10 + ch_2-'0';
				j++;
				if (ch_3 == '\n') j=0, i++;
			}
			i++;
			width = j; 
			height = i;
		}
		void draw_object(char *yes){
			for (int i = 0; i < height; i++){
				for (int j = 0; j < width; j++){
					if (body[i][j] != 16) putpixel(coord_x + j, coord_y + i, body[i][j]);
				}
			}
		}
		void draw_object(){
			line(coord_x, coord_y, coord_x + width, coord_y);
			line(coord_x, coord_y, coord_x, coord_y + height);
			line(coord_x + width, coord_y + height, coord_x, coord_y + height);
			line(coord_x + width, coord_y + height, coord_x + width, coord_y);
		}
		
		Object(): coord_x(0), coord_y(0), width(630), height(466) {}
		Object(int x, int y, int wi, int he): coord_x(x), coord_y(y), width(wi), height(he) {}
		Object(char *name_file): coord_x(0), coord_y(0), width(630), height(466), body_file(name_file) {}
		Object(int x, int y, int wi, int he, char *name_file): coord_x(x), coord_y(y), width(wi), height(he), body_file(name_file) {}
};

class Animal : virtual public Object{
	public:
		int health;
		int damage;
		int speed;
		char symbol;
		
		void move_wasd(){
	    	symbol = getch();
	    	switch (symbol){
				case 'd': coord_x+=speed; break;
	            case 'a': coord_x-=speed; break;
	            case 'w': coord_y-=speed; break;
	            case 's': coord_y+=speed; break;
	            default: break;
			}
		}
		void move_ijkl(){
	    	symbol = getch();
	    	switch (symbol){
				case 'l': coord_x+=speed; break;
	            case 'j': coord_x-=speed; break;
	            case 'i': coord_y-=speed; break;
	            case 'k': coord_y+=speed; break;
	            default: break;
			}
		}
		void move_bot(){
			
		}
		void check_animal(int width_, int height_){
			if (coord_x < 1) coord_x = 1;
			if (coord_x + width > width_) coord_x = width_ - width;
			if (coord_y < 1) coord_y = 1;
			if (coord_y + height > height_) coord_y = height_ - height;
		}
		
		Animal(): Object(1, 1, 0, 0, "human.txt"), health(100), damage(10), speed(5) {}
		Animal(char *name_file): Object(1, 1, 0, 0, name_file), health(100), damage(10), speed(5) {}
		Animal(int x, int y, int wi, int he, char *name_file, int h, int d, int s): Object(x, y, wi, he, name_file), health(h), damage(d), speed(s) {}
};
