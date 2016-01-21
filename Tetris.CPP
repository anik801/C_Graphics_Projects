#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
int x1,y1,x2,y2;
//int x1=220,y1=65,x2=260,y2=105; p1
//int x1=225,y1=65,x2=305,y2=105; p2
//int x1=225,y1=65,x2=245,y2=145; p3
//int x1=225,y1=65,x2=285,y2=105; p4
//int x1=225,y1=65,x2=285,y2=105; p5
//int x1=225,y1=65,x2=285,y2=105; p6
//int x1=225,y1=65,x2=285,y2=105; p7

char key=0;
void *imageofbox[8];
int area[8];

void boximage()
{
	//p1
	bar(0,0,40,40);
	area[1]=imagesize(0,0,40,40);
	imageofbox[1]=malloc(area[1]);
	getimage(0,0,40,40,imageofbox[1]);
	cleardevice();

	//p2
	bar(0,0,80,20);
	area[2]=imagesize(0,0,80,20);
	imageofbox[2]=malloc(area[2]);
	getimage(0,0,80,20,imageofbox[2]);
	cleardevice();

	//p3
	bar(0,0,20,80);
	area[3]=imagesize(0,0,20,80);
	imageofbox[3]=malloc(area[3]);
	getimage(0,0,20,80,imageofbox[3]);
	cleardevice();

	//p4
	bar(0,0,20,40);
	bar(20,20,60,40);
	area[4]=imagesize(0,0,80,40);
	imageofbox[4]=malloc(area[4]);
	getimage(0,0,80,40,imageofbox[4]);
	cleardevice();

	//p5
	bar(0,20,40,40);
	bar(40,0,60,40);
	area[5]=imagesize(0,0,60,40);
	imageofbox[5]=malloc(area[5]);
	getimage(0,0,60,40,imageofbox[5]);
	cleardevice();

	//p6
	bar(0,0,40,20);
	bar(40,0,60,40);
	area[6]=imagesize(0,0,60,40);
	imageofbox[6]=malloc(area[6]);
	getimage(0,0,60,40,imageofbox[6]);
	cleardevice();

	//p7
	bar(0,0,20,40);
	bar(20,0,60,20);
	area[7]=imagesize(0,0,60,40);
	imageofbox[7]=malloc(area[7]);
	getimage(0,0,60,40,imageofbox[7]);
	cleardevice();

}

void keycheck(int i)
{
	key=getch();
	if(key==27)
		exit(0);
	if(i==1)
	{
		if(key==77)		//right key
		{
			if(x1>=100&&x2<=420&&getpixel(x2+10,y2+20)!=15)                                                                                                                                                //x2+=10,y1+=20
			{
				putimage(x1,y1,imageofbox[1],XOR_PUT);                                                                            //delete previous box
				x1+=20;
				x2+=20;
				putimage(x1,y1,imageofbox[1],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y2+20)!=15)                                                                                                                                                  //x1-=10,y1+=20
			{
			putimage(x1,y1,imageofbox[1],XOR_PUT);                                                                                     //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[1],XOR_PUT);
			}
		}
	}
	if(i==2)
	{
		if(key==77)		//right key
		{

			if(x1>=100&&x2<=420&&getpixel(x2+10,y2+10)!=15)                                                                                          //x2<386
			{
			putimage(x1,y1,imageofbox[2],XOR_PUT);      //delete previous box
			x1+=20;
			x2+=20;
			putimage(x1,y1,imageofbox[2],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y1+10)!=15)
			{
			putimage(x1,y1,imageofbox[2],XOR_PUT); //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[2],XOR_PUT);
			}
		}
	}
	if(i==3)
	{
		if(key==77)		//right key
		{

			if(x1>=100&&x2<=420&&getpixel(x2+10,y2+10)!=15&&getpixel(x2+10,y1+30)!=15&&getpixel(x2+10,y1+50)!=15&&getpixel(x2+10,y1+70)!=15)
			{
			putimage(x1,y1,imageofbox[3],XOR_PUT);      //delete previous box
			x1+=20;
			x2+=20;
			putimage(x1,y1,imageofbox[3],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y2+10)!=15&&getpixel(x1-10,y1+30)!=15&&getpixel(x1-10,y1+50)!=15&&getpixel(x1-10,y1+70)!=15)
			{
			putimage(x1,y1,imageofbox[3],XOR_PUT); //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[3],XOR_PUT);
			}
		}
	}
	if(i==4)
	{
		if(key==77)		//right key
		{

			if(x1>=100&&x2<=420&&getpixel(x2+10,y2+20)!=15)                                                                                          //x2<386
			{
			putimage(x1,y1,imageofbox[4],XOR_PUT);      //delete previous box
			x1+=20;
			x2+=20;
			putimage(x1,y1,imageofbox[4],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y1+20)!=15)
			{
			putimage(x1,y1,imageofbox[4],XOR_PUT); //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[4],XOR_PUT);
			}
		}
	}
	if(i==5)
	{
		if(key==77)		//right key
		{

			if(x1>=100&&x2<=420&&getpixel(x2+5,y2+20)!=15)                                                                                          //x2<386
			{
			putimage(x1,y1,imageofbox[5],XOR_PUT);      //delete previous box
			x1+=20;
			x2+=20;
			putimage(x1,y1,imageofbox[5],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y1+20)!=15)
			{
			putimage(x1,y1,imageofbox[5],XOR_PUT); //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[5],XOR_PUT);
			}
		}
	}
	if(i==6)
	{
		if(key==77)		//right key
		{

			if(x1>=100&&x2<=420&&getpixel(x2+5,y2+10)!=15&&getpixel(x1+5,y1+30)!=15)
			{
			putimage(x1,y1,imageofbox[6],XOR_PUT);      //delete previous box
			x1+=20;
			x2+=20;
			putimage(x1,y1,imageofbox[6],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y1+10)!=15&&getpixel(x2-10,y2+10)!=15)
			{
			putimage(x1,y1,imageofbox[6],XOR_PUT); //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[6],XOR_PUT);
			}
		}
	}
	if(i==7)
	{
		if(key==77)		//right key
		{

			if(x1>=100&&x2<=420&&getpixel(x1+25,y2+10)!=15&&getpixel(x2+5,y2+15)!=15)
			{
			putimage(x1,y1,imageofbox[7],XOR_PUT);      //delete previous box
			x1+=20;
			x2+=20;
			putimage(x1,y1,imageofbox[7],XOR_PUT);
			}
		}
		else if(key==75)//left key
		{
			if(x1>=100&&x2<=420&&getpixel(x1-10,y1+30)!=15&&getpixel(x1-10,y2+10)!=15&&getpixel(x1+25,y1+30)!=15&&getpixel(x2-5,y1+30)!=15)
			{
			putimage(x1,y1,imageofbox[7],XOR_PUT); //delete previous box
			x1-=20;
			x2-=20;
			putimage(x1,y1,imageofbox[7],XOR_PUT);
			}
		}
	}
}

void down(int i)
{
	if(i==1)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[1],XOR_PUT);
//		 delay(150);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y2+15)==15||getpixel(x2-5,y2+15)==15||getpixel(x1+20,y2+15)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[1],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }
	if(i==2)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[2],XOR_PUT);
//		 delay(150);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y2+15)==15||getpixel(x2-5,y2+15)==15||getpixel(x1+25,y2+15)==15||getpixel(x2-25,y2+15)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[2],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }
	if(i==3)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[3],XOR_PUT);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y2+15)==15||getpixel(x2-5,y2+15)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[3],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }
	if(i==4)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[4],XOR_PUT);
//		 delay(150);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y2+15)==15||getpixel(x2-15,y2+15)==15||getpixel(x1+20,y2+15)==15||getpixel(x2-20,y2+15)==15)		     //||getpixel(x2-1,y2+15)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[4],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }
	if(i==5)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[5],XOR_PUT);
//		 delay(150);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y2+15)==15||getpixel(x2-5,y2+15)==15||getpixel(x1+20,y2+15)==15||getpixel(x2-20,y2+15)==15)		     //||getpixel(x2-1,y2+15)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[5],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }
	if(i==6)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[6],XOR_PUT);
//		 delay(150);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y1+25)==15||getpixel(x1+25,y1+25)==15||getpixel(x2-5,y2+15)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[6],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }
	if(i==7)
	 while(y2<=450)
	 {

		 putimage(x1,y1,imageofbox[7],XOR_PUT);
//		 delay(150);
		 if(kbhit())
		 {
			keycheck(i);
			keycheck(i);
		 }

		 if(getpixel(x1+5,y2+15)==15||getpixel(x2-5,y1+25)==15||getpixel(x1+25,y1+25)==15)
		 {
			break;
		 }
		 delay(150);
		 putimage(x1,y1,imageofbox[7],XOR_PUT);                                                                                                                                                                //delete previous box
		 y1+=20;
		 y2+=20;

	 }

}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	boximage();

	setcolor(5);
	rectangle(100,50,420,450);

	setfillstyle(SOLID_FILL,WHITE);
	floodfill(0,0,5);
	int i,x,y; //1-15 loop variable
	int s1=0, s2=0,sd;
	int flag[21];
	char ar[100];
	settextstyle(0,0,1);
	for(i=1;i<=7;i++)
	{
		if(i==1)
			x1=220,y1=65,x2=260,y2=105;
		else if(i==2)
			x1=220,y1=65,x2=300,y2=85;
		else if(i==3)
			x1=220,y1=65,x2=240,y2=145;
		else if(i==4)
			x1=220,y1=65,x2=280,y2=105;
		else if(i==5)
			x1=220,y1=65,x2=280,y2=105;
		else if(i==6)
			x1=220,y1=65,x2=280,y2=105;
		else if(i==7)
			x1=220,y1=65,x2=280,y2=105;

		down(i);
		if(i==7)
			i=0;

		for(y=60;y<=440;y+=20)
		{
			s1=0;
			//sd=0;
			for(x=110;x<=410;x+=20)
			{
				if(flag[y/20-3]==y)
					break;

				if(getpixel(x,y)==15)
					s1++;
			}
			if(s1%16==0&&s1!=0)
			{
				s2++;
				s1=0;
				flag[y/20-3]=y;
			}

		}

//		if()
		{
			setfillstyle(1,0);
			bar(500,100,600,200);
			sprintf(ar,"Score %d",s2);
			outtextxy(520,120,ar);
		}



	}
	getch();
	closegraph();
	return 0;
}

