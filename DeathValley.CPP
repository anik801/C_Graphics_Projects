#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<math.h>

//Declaring global variables//
int x1[10],y1[10],fx[10],fy[10]; 	//ghost cord && cord change flag
int flag11[10],flag22[20];      	//ghost life
int x,y,button,tx,ty; 			 	//mouse variables
int snd=1,dummy;					//sound & ghost dummy
clock_t t1,t2; 					 	//clock variables
void *p2,*p3,*p4,*p5,*p10;			//for characters
int area2,area3,area4,area5,area10; 	//for characters
	int i2,j2,i1,j1,n;  				//loops & number of ghosts
	int t3=15;					//score target  ?
	float t4=15.0;              //time   ?
	int entry_x[]={70,390};
	int entry_y[]={70,180,390};
	int score=0,sd=0; //sd=score dummy
	int level=0,d=60;    //level & delay
char sc1[10],sc2[10];				//score & level
char hint[50];   					//printing other writings in game
char time1[30];  					//printing time & level

union REGS i, o;
	float f2=230;		//frequency
	float l=1.0595;     //multiply for next note
float sargam[]={f2,f2*pow(l,2),f2*pow(l,3),f2*pow(l,5),f2*pow(l,6),f2*pow(l,8),f2*pow(l,10)};

#define scn 5
FILE *fps;
struct score    //?
{
	int score;
	char name[6];
}	sco2[scn],sco3;

//Declaring user-defined funtions//
int initmouse();
void showmouseptr();
void hidemouseptr();
void getmousepos(int*,int*,int*); //?
void murad();
void zilani();
void mEh();
void bigvoot();
void load_image();
void change();
void check();
void new_game();
void new_score();
void new_ghost();
void side_score_level();
int check_level();
void show_time();
void level_1();
void load_cord();
void load_flags();
void finishing();
void show_mouse1();
void show_mouse2();
void main_menu();
void help();
void about();
void highscore();
void set_default();
void check_high_score(int score);
void fcopys();   // file copy structure
void scopyf();   // structure copy file
void background1();
void background2();
void settings();
void deathvalley();
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	initmouse();
	load_image();
	load_flags();
	load_cord();
	fcopys();
	deathvalley();
	main_menu();

	getch();
	closegraph();
	return 0;
}


int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

void hidemouseptr()
{
   i.x.ax = 2;             // to hide mouse
   int86(0X33,&i,&o);
}

void load_image()
{
	setcolor(4);     //mouse image
	circle(100,100,10);
	line(90,100,110,100);
	line(100,90,100,110);
	area2=imagesize(90,90,110,110);
	p2=malloc(area2);
	getimage(90,90,110,110,p2);
	putimage(200,200,p2,XOR_PUT);
	setcolor(15);
	cleardevice();

	zilani();
	area4=imagesize(40,50,80,90);
	p4=malloc(area4);
	getimage(40,50,80,90,p4);
	putimage(100,100,p4,XOR_PUT);
	cleardevice();

	murad();
	area3=imagesize(10,50,50,90);
	p3=malloc(area3);
	getimage(10,50,50,90,p3);
	putimage(100,100,p3,XOR_PUT);
	cleardevice();

	mEh();
	area5=imagesize(10,45,50,90);
	p5=malloc(area5);
	getimage(10,45,50,90,p5);
	putimage(300,300,p5,XOR_PUT);
	cleardevice();

	set_default();

}

void murad()
{
	setlinestyle(0,0,1);
	setfillstyle(SOLID_FILL,GREEN);
	circle(30,70,20);
	floodfill(30,70,WHITE);
	setfillstyle(SOLID_FILL,RED);
	circle(22,62,4);
	floodfill(22,62,15);
	setfillstyle(SOLID_FILL,RED);
	circle(38,62,4);
	floodfill(38,62,15);
	setcolor(0);
	setlinestyle(0,7,3);
	line(20,55,26,59);
	setlinestyle(0,7,3);
	line(35,58,41,55);
	setcolor(15);
	setlinestyle(0,7,3);
	line(28,77,39,77);
	setcolor(15);
	setfillstyle(0,0);
	setlinestyle(0,0,1);
}

void zilani()
{
   setfillstyle(SOLID_FILL,8);
   fillellipse(60,70,20,20);

  setlinestyle(0,0,6);
  setfillstyle(SOLID_FILL,RED);
  fillellipse(52,64,3,8);
  setfillstyle(SOLID_FILL,RED);
  fillellipse(70,64,3,8);
  setfillstyle(SOLID_FILL,WHITE);
  circle(52,65,3);
  floodfill(52,65,15);
  circle(70,65,3);
  floodfill(70,65,15);
  setlinestyle(3,7,3);
  line(48,80,72,80);
  setlinestyle(3,7,3);
  line(48,85,72,85);

  setlinestyle(0,0,1);
  setfillstyle(0,1);
}

void mEh()
{
	 setlinestyle(0,3,3);
	 setcolor(8);
	 circle(30,70,20);
	 setfillstyle(1,8);
	 circle(22,65,7);
	 floodfill(22,65,8);
	 circle(40,65,3);
	 floodfill(40,65,8);
	 setlinestyle(0,0,2);
	 setfillstyle(7,8);
	 fillellipse(30,80,12,5);
	 setlinestyle(0,0,3);
	 line(30,53,35,45);
	 line(34,53,39,49);
	 line(20,53,25,45);
	 line(45,55,49,53);
	 line(26,58,28,55);
	 line(20,58,23,56);
	 line(40,62,45,60);
	 setlinestyle(3,7,3);
	 line(30,75,35,65);
	 circle(34,71,1);

   //	 setbkcolor(0);
	 setlinestyle(0,0,1);
	 setfillstyle(1,0);
}

void change()
{
	for(i1=0;i1<n;i1++)
	{
		if(fx[i1]==2)
			x1[i1]+=5;
		else
			x1[i1]-=5;
		if(fy[i1]==2)
			y1[i1]+=5;
		else
			y1[i1]-=5;
	}
}
void check()
{
	int r=15,r2=35;
	for(i1=0;i1<n;i1++)
	{
		//wall check
		if(x1[i1]>=410)
			fx[i1]*=-1;
		if(y1[i1]>=410)
			fy[i1]*=-1;
		if(x1[i1]<=30)
			fx[i1]*=-1;
		if(y1[i1]<=30)
			fy[i1]*=-1;

		//ball check
		for(j1=0;j1<n;j1++)
		{
			if(i1==j1)
				break;

			//checking 45 degree
			if((x1[i1]-x1[j1]<=r2&&x1[i1]-x1[j1]>=-r2)&&(y1[i1]-y1[j1]<=r2&&y1[i1]-y1[j1]>=-r2))
			{
				fx[i1]*=-1;
				fx[j1]*=-1;
				fy[i1]*=-1;
				fy[j1]*=-1;
			}
			if(x1[i1]-r==x1[j1]+r&&y1[i1]+r==y1[j1]-r)
			{
				fy[i1]*=-1;
				fy[j1]*=-1;
			}

			else if(x1[i1]+r==x1[j1]-r&&y1[i1]-r==y1[j1]+r)
			{
				fx[i1]*=-1;
				fx[j1]*=-1;
			}
			// CHECKING 45 Degree end
			if(x1[i1]+20==x1[j1]-20&&y1[i1]==y1[j1])
			{
				fx[i1]*=(-1);
				fx[j1]*=(-1);
			}
			if(x1[i1]-20==x1[j1]+20&&y1[i1]==y1[j1])
			{
				fx[i1]*=(-1);
				fx[j1]*=(-1);
			}
			if(y1[i1]+20==y1[j1]-20&&x1[i1]==x1[j1])
			{
				fy[i1]*=(-1);
				fy[j1]*=(-1);
			}
			if(y1[i1]-20==y1[j1]+20&&x1[i1]==x1[j1])
			{
				fy[i1]*=(-1);
				fy[j1]*=(-1);
			}

		}// j loop end
	}    // i loop end
}        // check end

void finishing()
{   //finishing
	cleardevice();
	rectangle(0,0,639,479);
	setcolor(1);
	settextstyle(4,0,4);
	outtextxy(25,100,"This Is The End of The Evolution Copy");
	outtextxy(75,200,"Thank You For Playing Our Game");
	outtextxy(75,300,"We Hope,You Enjoyed Playing It,");
	outtextxy(60,350,"As Much As We Enjoyed Making It");
	getch();
	set_default();
}

void load_flags()
{
	for(i2=0;i2<10;i2++)
		flag11[i2]=0;
	for(i2=0;i2<20;i2++)
		flag22[i2]=0;
	for(i1=0;i1<10;i1++)
	{
		fx[i1]=2;
		fy[i1]=2;
	}
}

void load_cord()
{
	x1[0]=70;	y1[0]=70;
	x1[1]=70;	y1[1]=390;
	x1[2]=390;	y1[2]=70;
	x1[3]=390;	y1[3]=390;
	x1[4]=70;	y1[4]=180;
	x1[5]=390;  y1[5]=180;
}

void level_1()
{
	rectangle(0,0,639,479);
	rectangle(30,30,450,450);
	setfillstyle(5,8);
	floodfill(100,100,15);
	settextstyle(7,0,4);
	outtextxy(80,100,"Finish All Enimies");
	outtextxy(60,130,"Before Time Finishes");
	settextstyle(7,0,3);
	outtextxy(90,340,"Press Any Key To Begin");
	setcolor(1);
	settextstyle(4,0,5);
	outtextxy(160,200,"Level 01");
	getch();

	cleardevice();
	setcolor(1);
	rectangle(0,0,639,479);
	rectangle(30,30,450,450);

	//bar(50,50,420,250); //for deleting menu
	//bar(460,160,630,180);
	settextstyle(4,0,3);
	sprintf(hint,"Target: %d",t3);
	outtextxy(460,160,hint);

	show_mouse1();

}
void show_time()
{
	settextstyle(4,0,3);
	setcolor(1);
	bar(465,240,635,300);
	t2=clock();
	sprintf(time1,"Time: %.02f",t4-(t2-t1)/18.0);
	outtextxy(465,240,time1);
}
int check_level()
{
		int i3;
		side_score_level();
		if((t2-t1)/18.0>=t4)
		{
			nosound();
			bar(31,31,449,449);
			settextstyle(4,0,5);
			outtextxy(140,180,"Game Over");
			delay(2000);
			return 1;
		}

		sd=0;
		if(score>=t3) //entering level 2
		{
			if(level==0)
			{
				nosound();
				for(i3=1;i3<10;i3++)
				{
					sound(500*i3);
					delay(i3*10);
				}

				nosound();
				bar(31,31,449,449);
				settextstyle(4,0,4);
				setcolor(1);
				outtextxy(180,180,"Level 02");
				setcolor(15);
				settextstyle(7,0,3);
				outtextxy(90,220,"Press Any Key To Begin");
				getch();
				bar(50,50,420,280);
				p10=p3;
				d=30;
				level=1;
				n=4;
				putimage(tx,ty,p2,XOR_PUT); //mouse
				t1=clock();
				t3=20; t4=20.0;
				j2=5;                         //for music change
				settextstyle(4,0,3);
				bar(460,160,630,180);
				setcolor(1);
				sprintf(hint,"Target: %d",3*t3);
				outtextxy(460,160,hint);
				load_cord();
			}
		}

		if(score>=3*t3) // entering level 3
		{
			if(level==1)
			{
				nosound();
				{
					for(i3=1;i3<10;i3++)
					{
						sound(500*i3);
						delay(i3*10);
					}
					nosound();
				}
				bar(31,31,449,449);
				settextstyle(4,0,4);
				outtextxy(180,180,"Level 03");
				setcolor(15);
				settextstyle(7,0,3);
				outtextxy(90,220,"Press Any Key To Begin");
				getch();
				bar(50,50,420,280);

				p10=p4;
				d=20;
				level=2;
				n=5;
				j2=4;                      //for music change
				putimage(tx,ty,p2,XOR_PUT);
				t1=clock();
				t3=30; t4=30.0;
				settextstyle(4,0,3);
				bar(460,160,630,180);
				setcolor(1);
				sprintf(hint,"Target: ALL");
				outtextxy(460,160,hint);
				load_cord();
			}
		}
		return 0;
}

void side_score_level()
{
		if(sd==score)	//printing score
		{
			settextstyle(4,0,3);
			setcolor(1);
			bar(460,30,630,150);
			sprintf(sc1,"Level: %d",level+1);
			sprintf(sc2,"Score: %d",score);
			outtextxy(460,50,sc1);
			outtextxy(460,100,sc2);
		}
}
void new_ghost()
{
	while(1)
	{
		i1=random(2);
		j1=random(3);
		if(getpixel(entry_x[i1]-19,entry_y[j1])==0&&getpixel(entry_x[i1]+19,entry_y[j1])==0&&getpixel(entry_x[i1],entry_y[j1]+19)==0&&getpixel(entry_x[i1],entry_y[j1]-19)==0)
		if(getpixel(entry_x[i1]-15,entry_y[j1])==0&&getpixel(entry_x[i1]+15,entry_y[j1])==0&&getpixel(entry_x[i1],entry_y[j1]+15)==0&&getpixel(entry_x[i1],entry_y[j1]-15)==0)
		if(getpixel(entry_x[i1]-10,entry_y[j1])==0&&getpixel(entry_x[i1]+10,entry_y[j1])==0&&getpixel(entry_x[i1],entry_y[j1]+10)==0&&getpixel(entry_x[i1],entry_y[j1]-10)==0)
		if(getpixel(entry_x[i1]-5,entry_y[j1])==0&&getpixel(entry_x[i1]+5,entry_y[j1])==0&&getpixel(entry_x[i1],entry_y[j1]+5)==0&&getpixel(entry_x[i1],entry_y[j1]-5)==0)
		if(getpixel(entry_x[i1],entry_y[j1])==0)
		{
			x1[i2]=entry_x[i1];
			y1[i2]=entry_y[j1];
			break;
		}
	}
	flag11[i2]=0;
}
void new_score()
{
	if(level==1)
		score+=2;
	else if(level==2)
		score+=3;
	else
		score++;
	sd=score;

	t4+=t3/(score*5);//bonus time
}

void new_game()
{
	set_default();
	n=3;  p10=p5;  d=40;  t1=clock(); score=0; sd=0; level=0;
	clock_t m3,m4;
	j2=6;
	m3=clock();
	while(!kbhit())
	{
		if(snd)
		{
			m4=clock();
			if((m4-m3)>=(float)j2)
			{
				sound(sargam[random(7)]*j2);
				m3=clock();
			}
		}
		show_time();
		if(check_level()==1)
			break;
		side_score_level();
		show_mouse2();
		check();
		change();
		//entring ghosts
		A:
		for(i2=0;i2<n;i2++)
		{
			if(flag11[i2]==0)
				putimage(x1[i2],y1[i2],p10,XOR_PUT);
		}
		//checking fire
		getmousepos(&button,&x,&y);
		for(i2=0;i2<n;i2++)
		{
			if((x<=x1[i2]+20&&x>=x1[i2]-20)&&(y<=y1[i2]+20&&y>=y1[i2]-20)&&button==1)
			{
				flag11[i2]=1;
				putimage(x1[i2],y1[i2],p10,XOR_PUT);
			}
		}
		delay(d);
		//removing ghost / creating new & scoring
		for(i2=0;i2<n;i2++)
		{
			if(flag11[i2]==0)
				putimage(x1[i2],y1[i2],p10,XOR_PUT);
			else if(flag11[i2]==1)
			{
				new_ghost();
				new_score(); //change score
				//putimage(x1[i2],y1[i2],p10,XOR_PUT);
				dummy=1;
			}

		}//removing & begining end
		side_score_level(); // print score & level
		if(dummy==1)
		{
			dummy=0;
			goto A;
		}
	}

	nosound();
}

void show_mouse1()
{
	getmousepos(&button,&x,&y);
	tx=x; ty=y;
	putimage(x,y,p2,XOR_PUT); //mouse pointer
}
void show_mouse2()
{
	getmousepos(&button,&x,&y);
	if(tx!=x||ty!=y)
	{
		putimage(tx,ty,p2,XOR_PUT);   //mouse pointer
		putimage(x,y,p2,XOR_PUT);     //mouse pointer
		tx=x; ty=y;
	}
}
void help()
{
	cleardevice();
	set_default();
	background2();
	setcolor(15);
	settextstyle(3,0,4);
	outtextxy(50,50,"This Is A Shooter Game Where You");
	outtextxy(50,80,"Have To Kill The Moving Ghosts....");

	outtextxy(50,130,"Use Your Mouse For Aim...");
	outtextxy(50,170,"And Left Button To Shoot");
//	outtextxy(50,190,"Bonus Time Will Be Given For Each Hit");

	outtextxy(50,230,"Finish All The Ghosts Within...");
	outtextxy(50,270,"The Time Limit or else...");
	outtextxy(50,310,"You'll Be DEAD MEAT...");

	outtextxy(20,400,"Back");
	show_mouse1();
	while(1)
	{
		show_mouse2();
		if(x>=20&&x<=80&&y>=380&&y<=420)
		{
			setcolor(4);
			outtextxy(20,400,"Back");
		}
		else if(!(x>=20&&x<=80&&y>=380&&y<=420))
		{
			setcolor(15);
			outtextxy(20,400,"Back");
		}
		if(x>=20&&x<=80&&y>=380&&y<=420&&button==1)
			main_menu();
	}
}

void set_default()
{
	setbkcolor(0);
	setcolor(15);
	settextstyle(0,0,2);
	setfillstyle(0,15);
}
void about()
{
	cleardevice();
	set_default();
//	background2();
	setcolor(15);
	settextstyle(3,0,3);
/*
	outtextxy(50,50,"The Death Valley");

	outtextxy(50,130,"Created By:");
	outtextxy(110,150,"Sk. Murad Hassan");
	outtextxy(110,170,"Subha Fairuz");
	outtextxy(110,190,"Abdul Kader Zilani");

	outtextxy(50,230,"This game is just a fun project.");
	outtextxy(50,250,"Whoever is playing the game,");
	outtextxy(50,270,"We hope you enjoy it..");
	outtextxy(50,310,"Thank You Very Much For Playing");
*/
	outtextxy(20,400,"Back");

	int up=480;
	setfillstyle(1,0);
	show_mouse1();
	while(1)
	{
		sound(sargam[random(7)]*8);
		setcolor(1);
		{
		settextstyle(4,0,5);
		setcolor(15);
		outtextxy(160,up,"The Death Valley");
		settextstyle(3,0,3);
		setcolor(1);

		outtextxy(250,up+80,"Created By");
		outtextxy(210,up+110,"Sk. Murad Hassan");
		outtextxy(240,up+130,"Subha Fairuz");
		outtextxy(210,up+150,"Abdul Kader Zilani");

		outtextxy(150,up+200,"This game is just a fun project.");
		outtextxy(165,up+220,"Whoever is playing the game,");
		outtextxy(200,up+240,"We hope you enjoy it..");
		outtextxy(145,up+280,"Thank You Very Much For Playing");
		delay(100);
		bar(50,0,550,480);
		}
		if(up<=-200)
			up=480;
		up-=10;

		show_mouse2();
		if(x>=20&&x<=80&&y>=380&&y<=420)
		{
			setcolor(4);
			outtextxy(20,400,"Back");
		}
		else if(!(x>=20&&x<=80&&y>=380&&y<=420))
		{
			setcolor(15);
			outtextxy(20,400,"Back");
		}
		if(x>=20&&x<=80&&y>=380&&y<=420&&button==1)
		{
			nosound();
			main_menu();
		}
	}
}

void main_menu()
{
	set_default();
	cleardevice();
	background1();
	setbkcolor(1);
	setcolor(15);
	settextstyle(4,0,4);
	{
/*
		//graphics
		rectangle(210,70,430,110);
		rectangle(210,130,430,170);
		rectangle(210,190,430,230);
		rectangle(210,250,430,290);
		rectangle(210,310,430,350);
		rectangle(210,370,430,410);
*/
		outtextxy(250,70,"New Game");
		outtextxy(270,130,"Settings");
		outtextxy(260,190,"Highscore");
		outtextxy(295,250,"Help");
		outtextxy(280,310,"About");
		outtextxy(295,370,"Exit");
	}
	show_mouse1();
	while(1)
	{
		show_mouse2();
		if(x>=210&&x<=430&&y>=70&&y<=110)
		{
			setcolor(4);
			outtextxy(250,70,"New Game");
		}
		else if(!(x>=210&&x<=430&&y>=70&&y<=110))
		{
			setcolor(15);
			outtextxy(250,70,"New Game");
		}
		if(x>=210&&x<=430&&y>=130&&y<=170)
		{
			setcolor(4);
			outtextxy(270,130,"Settings");
		}
		else if(!(x>=210&&x<=430&&y>=130&&y<=170))
		{
			setcolor(15);
			outtextxy(270,130,"Settings");
		}
		if(x>=210&&x<=430&&y>=190&&y<=230)
		{
			setcolor(4);
			outtextxy(260,190,"Highscore");
		}
		else if(!(x>=210&&x<=430&&y>=190&&y<=230))
		{
			setcolor(15);
			outtextxy(260,190,"Highscore");
		}
		if(x>=210&&x<=430&&y>=250&&y<=290)
		{
			setcolor(4);
			outtextxy(295,250,"Help");
		}
		else if(!(x>=210&&x<=430&&y>=250&&y<=290))
		{
			setcolor(15);
			outtextxy(295,250,"Help");
		}
		if(x>=210&&x<=430&&y>=310&&y<=350)
		{
			setcolor(4);
			outtextxy(280,310,"About");
		}
		else if(!(x>=210&&x<=430&&y>=310&&y<=350))
		{
			setcolor(15);
			outtextxy(280,310,"About");
		}

		if(x>=210&&x<=430&&y>=370&&y<=410)
		{
			setcolor(4);
			outtextxy(295,370,"Exit");
		}
		else if(!(x>=210&&x<=430&&y>=370&&y<=410))
		{
			setcolor(15);
			outtextxy(295,370,"Exit");
		}

		if(x>=210&&x<=430&&y>=70&&y<=110&&button==1)
		{
			nosound();
			cleardevice();
			set_default();
			level_1();
			new_game();

			check_high_score(score);
			finishing();
			main_menu();
		}

		else if(x>=210&&x<=430&&y>=130&&y<=170&&button==1)
		{
			nosound();
			cleardevice();
			set_default();
			settings();
		}

		else if(x>=210&&x<=430&&y>=190&&y<=230&&button==1)
		{
			nosound();
			cleardevice();
			set_default();
			highscore();
			main_menu();
		}
		else if(x>=210&&x<=430&&y>=250&&y<=290&&button==1)
		{
			nosound();
			cleardevice();
			set_default();
			help();
			main_menu();
		}
		else if(x>=210&&x<=430&&y>=310&&y<=350&&button==1)
		{
			nosound();
			cleardevice();
			set_default();
			about();
			main_menu();
		}

		else if(x>=210&&x<=430&&y>=370&&y<=410&&button==1)
		{
			nosound();
			cleardevice();
			set_default();
			exit(0);
		}
		if(kbhit())
			if(getch()==27)
			{
				nosound();
				exit(0);
			}
	}
}

void scopyf() //copy structure to file
{
	fps=fopen("FL4.txt","w");
	for(i2=0;i2<scn;i2++)
		fprintf(fps,"%s %d\n",sco2[i2].name,sco2[i2].score);
	fclose(fps);
}

void fcopys() //copy file to structure
{
	fps=fopen("FL4.txt","r");
	for(i2=0;i2<scn;i2++)
	{
		fscanf(fps,"%s %d",sco2[i2].name,&sco2[i2].score);

		if(strlen(sco2[i2].name)<5)
		{
			for(j2=strlen(sco2[i2].name);j2<5;j2++)
				sco2[i2].name[j2]=' ';
		}
	}
	fclose(fps);
}

void check_high_score(int score)
{
	if(score>sco2[4].score)
	{
		cleardevice();
		outtextxy(50,100,"Enter your name: ");
		gotoxy(1,2);
		gets(sco2[4].name);
		sco2[4].score=score;
		if(strlen(sco2[4].name)<5)
		{
			for(i2=strlen(sco2[4].name);i2<5;i2++)
				sco2[4].name[i2]=' ';
		}
	}
	for(i2=0;i2<scn;i2++)
	{
		for(j2=0;j2<scn;j2++)
		{
			if(sco2[i2].score>=sco2[j2].score)
			{
				sco3.score=sco2[i2].score;
				strcpy(sco3.name,sco2[i2].name);

				sco2[i2].score=sco2[j2].score;
				strcpy(sco2[i2].name,sco2[j2].name);

				sco2[j2].score=sco3.score;
				strcpy(sco2[j2].name,sco3.name);
			}
		}//j loop
	}// i loop
	set_default();
	scopyf();
}

void highscore()
{
	cleardevice();
	set_default();
	background2();
	settextstyle(4,0,3);
	setcolor(15);
	outtextxy(100,100,"SL");
	outtextxy(180,100,"Name");
	outtextxy(350,100,"Score");

	char hs[40];
	j2=130;
	for(i2=0;i2<scn;i2++)
	{
		sprintf(hs,"%d      %s         %d",i2+1,sco2[i2].name,sco2[i2].score);
		outtextxy(100,j2,hs);
		j2+=20;
	}
	outtextxy(20,400,"Back");
	show_mouse1();
	while(1)
	{
		show_mouse2();
		if(x>=20&&x<=80&&y>=380&&y<=420)
		{
			setcolor(4);
			outtextxy(20,400,"Back");
		}
		else if(!(x>=20&&x<=80&&y>=380&&y<=420))
		{
			setcolor(15);
			outtextxy(20,400,"Back");
		}
		if(x>=20&&x<=80&&y>=380&&y<=420&&button==1)
			main_menu();
	}
}

void background1()
{
	setcolor(1);

	int poly1[]={0,350,150,280,110,330,250,270,220,380,300,350,330,479,0,479,0,350};
	drawpoly(9,poly1);
	int poly2[]={639,200,500,180,580,240,470,290,610,320,530,360,639,400,639,200};
	drawpoly(9,poly2);
	int poly3[]={150,0,200,100,120,80,220,150,90,120,180,180,0,130};
	drawpoly(7,poly3);

	setfillstyle(10,9);
	floodfill(1,351,1);
	setfillstyle(11,3);
	floodfill(638,201,1);
	setfillstyle(12,4);
	floodfill(149,1,1);

	settextstyle(7,1,7);
	setcolor(9);
	outtextxy(40,50,"Death Valley");
}
void background2()
{
	setcolor(1);

	int poly1[]={0,350,150,280,110,330,250,270,220,380,300,350,330,479,0,479,0,350};
	drawpoly(9,poly1);
	int poly2[]={639,200,500,180,580,240,470,290,610,320,530,360,639,400,639,200};
	drawpoly(9,poly2);
	int poly3[]={150,0,200,100,120,80,220,150,90,120,180,180,0,130};
	drawpoly(7,poly3);

	setfillstyle(10,9);
	floodfill(1,351,1);
	setfillstyle(11,3);
	floodfill(638,201,1);
	setfillstyle(12,4);
	floodfill(149,1,1);
	setbkcolor(0);
}
void settings()
{
	cleardevice();
	background2();
	setcolor(15);
	settextstyle(4,0,4);
	outtextxy(270,180,"SOUND");
	settextstyle(4,0,3);
	outtextxy(190,260,"ON");
	outtextxy(420,260,"OFF");
	outtextxy(20,400,"Back");
//	rectangle(200,260,240,280);
//	rectangle(400,260,460,280);
//	rectangle(20,400,80,420);
	show_mouse1();
	while(1)
	{
		show_mouse2();
		if(x>=180&&x<=240&&y>=240&&y<=280)
		{
			setcolor(4);
			outtextxy(190,260,"ON");
		}
		else if(!(x>=180&&x<=240&&y>=240&&y<=280))
		{
			setcolor(15);
			outtextxy(190,260,"ON");
		}
		if(x>=400&&x<=460&&y>=240&&y<=280)
		{
			setcolor(4);
			outtextxy(420,260,"OFF");
		}
		else if(!(x>=400&&x<=460&&y>=240&&y<=280))
		{
			setcolor(15);
			outtextxy(420,260,"OFF");
		}
		if(x>=20&&x<=80&&y>=380&&y<=420)
		{
			setcolor(4);
			outtextxy(20,400,"Back");
		}
		else if(!(x>=20&&x<=80&&y>=380&&y<=420))
		{
			setcolor(15);
			outtextxy(20,400,"Back");
		}
		if(x>=180&&x<=240&&y>=240&&y<=280&&button==1)
		{
			snd=1;
			main_menu();
		}
		else if(x>=400&&x<=460&&y>=240&&y<=280&&button==1)
		{
			snd=0;
			main_menu();
		}
		else if(x>=20&&x<=80&&y>=380&&y<=420&&button==1)
			main_menu();

	}

}

void deathvalley()
{
	int cx,cy;
	cx=-300;
	settextstyle(7,0,2);
	outtextxy(160,400,"Pres Any Key To Continue");
	settextstyle(4,0,8);
	setcolor(1);
	while(!kbhit())
	{
		sound(2*cx+1000);
		if(cx<160)
		{
			outtextxy(cx,100,"DEATH");
			outtextxy(380-cx,200,"VALLEY");
		}
		if(cx<150)
			cx+=10;
		else break;

		if(cx<160)
		{
			delay(50);
			bar(0,80,640,400);
		}

	}
	nosound();
	A:
	cx=0, cy=0;  p10=p3;
	while(!kbhit())
	{
		sound(6*cy+100);
		putimage(cx,cy,p10,XOR_PUT);
				putimage(640-cx,400-cy,p10,XOR_PUT);
		delay(50);
		putimage(cx,cy,p10,XOR_PUT);
				putimage(640-cx,400-cy,p10,XOR_PUT);
		cx+=10;
		if(cx<=100)
			cy+=10;
		else
			cy-=10;
		if(cx>=200)
			break;
	}
	p10=p4;
	while(!kbhit())
	{
		sound(6*cy+100);
		putimage(cx,cy,p10,XOR_PUT);
				putimage(640-cx,400-cy,p10,XOR_PUT);
		delay(50);
		putimage(cx,cy,p10,XOR_PUT);
				putimage(640-cx,400-cy,p10,XOR_PUT);
		cx+=10;
		if(cx>200&&cx<=300)
			cy+=10;
		else
			cy-=10;
		if(cx>=400)
			break;
	}
	p10=p5;
	while(!kbhit())
	{
		sound(6*cy+100);
		putimage(cx,cy,p10,XOR_PUT);
				putimage(640-cx,400-cy,p10,XOR_PUT);
		delay(50);
		putimage(cx,cy,p10,XOR_PUT);
				putimage(640-cx,400-cy,p10,XOR_PUT);
		cx+=10;
		if(cx>400&&cx<=500)
			cy+=10;
		else
			cy-=10;
		if(cx>=600)
			goto A;
	}
	nosound();
}
