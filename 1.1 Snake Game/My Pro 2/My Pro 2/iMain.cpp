# include "iGraphics.h"
#include "stdlib.h"

int fx = 400, fy = 400, highscore;

/*
function iDraw() is called again and again by the system.
*/

int px = 10, py = 10;

int dx = 0, dy = 0;

int count_food = 0;
bool upbutton = false, downbutton = false, leftbutton = false, righbutton = false;

 


struct co_ordinate
{
	int x, y;
}snake[100];
string str;
string str2;

void score(){
	stringstream ss;
	ss << count_food;
	 str = ss.str();
}
void high(){
	stringstream ss;
	ss << highscore;
	str2 = ss.str();
}

void iDraw()
{


	iClear();
	if (dx == 0){

		iShowBMP(0, 0, "snk.bmp");
		iSetcolor(255, 255, 255);
		iText(320, 550, "Snake game !", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(10, 10, "Press enter to start game, H for help, Q for exit.");

		iShowBMP(330, 400, "snake.bmp");
		iSetcolor(.5, 1, 0);
		int s = 270;
		for (int q = 260; q >= 150; q -= 50)
		{
			iFilledRectangle(s, q, 230, 40);


		}

		iSetcolor(255, 255, 255);
		iText(290, 270, "    Start Game  ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 220, "    Help  ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(320, 170, "    Quit !   ", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	

	if (dx == 1)
	{



		iClear();
		iShowBMP(0, 0, "bac1.bmp");
		
		iText(560, 550, " SCORE : ");
		iSetcolor(1, 1, 1);
	
		iFilledRectangle(fx, fy, 8, 5);
		
		
		iSetcolor(0, 1, 0);
		
		score();
		iText(660, 550, str);
		//iFilledRectangle(snake[0].x, snake[0].y, 15, 15);
	
		for (int index_snake = 0; index_snake <= count_food; index_snake++) {


			iFilledRectangle(snake[index_snake].x, snake[index_snake].y, px, py);

		}


		if ((snake[0].x <= fx && snake[0].x +15 >= fx) && (snake[0].y <= fy && snake[0].y + 15 >= fy))
		{
		
			
			fx = rand() % 600;
			srand(time(0));
			fy = rand() % 500;
			fx += 50; fy += 50;

			

			count_food++;




			snake[count_food].x = snake[count_food - 1].x;
			snake[count_food].y = snake[count_food - 1].y;


		}

		

	}
	 else if (dx == 2)
	{
		iClear();
		iSetcolor(1, 1, 1);
		iShowBMP(0, 0, "MNO.bmp");
		iText(300, 300, " processing");
	}
	 else if (dx == 3)
	{
		iClear();
		iSetcolor(1, 1, 1);
		iText(300, 300, " Your Score: ");
		iText(400, 300, str);
		iText(300, 200, " Highscore");
		high();
		iText(400, 200, str2);
		
		iText(300, 100, " press B to play again ");
		iText(300, 50, " press Q to Quit ");
		
	}
		
	 
		


	

	//place your drawing codes here	
}


void collision_check()
{
	for (int n = count_food; n > 0; n--) {
		if ((snake[n].x == snake[0].x) && (snake[n].y == snake[0].y))
		{

			dx = 3;
			if (count_food > highscore){
				highscore = count_food;
				FILE *fp;
				fopen_s(&fp, "Score", "wb");
				fwrite(&count_food, sizeof(int), 1, fp);
				fclose(fp);
			}
		}

	}
}

void touchboard_check()
{
	if (( snake[0].y < 5 )&&( snake[0].x>5 && snake[0].x +15< 695)) { dx = 3; }
	else if ((snake[0].y + 15 > 595) && (snake[0].x > 5 && snake[0].x + 15 < 695))  { dx = 3; }
	else if (snake[0].x +15>695) { dx = 3; }
	else if (snake[0].x < 5) { dx = 3; }
	if (dx == 3)
	{
		if (count_food> highscore)

		{
			highscore=count_food;
			FILE *fp;
			fopen_s(&fp, "Score", "wb");
			fwrite(&count_food, sizeof(int), 1, fp);
			fclose(fp);
		}
	}
}

void snakemove(){



	if (dy == 1)
	{

		{

		upbutton = true;
		downbutton = false; leftbutton = false; righbutton = false;

		for (int i = count_food; i > 0; i--)
		{

			snake[i].x = snake[i - 1].x;
			snake[i].y = snake[i - 1].y;

		}


		snake[0].y = (snake[0].y + 15);
		collision_check();

	}
	touchboard_check();
}
		
		
	


	else if (dy == 2)
	{

		{
			downbutton = true;
			upbutton = false; leftbutton = false; righbutton = false;

			for (int i = count_food; i > 0; i--)
			{
				snake[i].x = snake[i - 1].x;
				snake[i].y = snake[i - 1].y;

			}

			snake[0].y = (snake[0].y - 15);
			collision_check();
		}

		touchboard_check();
	}

		
	
	else if (dy == 3)
	{
		{
			leftbutton = true;
			upbutton = false; downbutton = false; righbutton = false;

			for (int i = count_food; i > 0; i--) 
			{
				snake[i].x = snake[i - 1].x;
				snake[i].y = snake[i - 1].y;

			}

			snake[0].x = (snake[0].x - 15);
			collision_check();
			
		}
		
		touchboard_check();
	}
	else if (dy == 4)
	{

		{
			righbutton = true;
			upbutton = false; leftbutton = false; downbutton = false;

			for (int i = count_food; i > 0; i--) 
			{
				snake[i].x = snake[i - 1].x;
				snake[i].y = snake[i - 1].y;

			}

			snake[0].x = (snake[0].x + 15);
			collision_check();
			
		}
	


		touchboard_check();



	}

}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}




/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		dx = 1;//place your codes here	
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}




/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{

	if (key == '\r' )
	{

		dx = 1;


	}
	if (key == 'h')
	{
		dx = 2;
	}
	if (key == 'q')
	{
		exit(0);
	}
	if (key == 'w' && downbutton != true)
	{

		dy = 1;

	}
	if (key == 's' && upbutton != true)
	{
		dy = 2;
	}
	if (key == 'a' && righbutton != true)
	{
		dy = 3;
	}
	if (key == 'd' && leftbutton != true)
	{
		dy = 4;
	}
	


	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	snake[0].x = 200;
	snake[0].y = 200;
	iSettimer(200, snakemove);
	
	FILE *fp;
	fopen_s(&fp, "Score","rb");
	fread(&highscore, sizeof(highscore), 1, fp);
	fclose(fp);
	

	iInitialize(700,595, "	Snake!	");
	
	return 0;
}
