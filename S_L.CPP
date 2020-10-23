#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>

 class s_l
{
  public:

  int pos;
  void board();
  void ladder();
  void snake();
  void dice();
  void puck();
  void p1();
};

void s_l::board()
{    setcolor(YELLOW);


    outtextxy(20,440," 1     2     3     4     5     6    7    8    9    10");
    outtextxy(20,390, "20    19    18    17    16    15   14   13   12    11");
    outtextxy(20,340, "21    22    23    24    25    26   27   28   29    30");
    outtextxy(20,300, "40    39    38    37    36    35   34   33   32    31");
    outtextxy(20,260, "41    42    43    44    45    46   47   48   49    50 ");
    outtextxy(20,210, "60    59    58    57    56    55   54   53   52    51");
    outtextxy(20,160, "61    62    63    64    65    66   67   68   69    70");
    outtextxy(20,110, "80    79    78    77    76    75   74   73   72    71");
    outtextxy(20,70,  "81    82    83    84    85    86   87   88   89    90");
    outtextxy(20,20,  "100   99    98    97    96    95   94   93   92    91");

    outtextxy(480,35," Press 'a' To Roll");
  for( int x=10, y=10; x<=495, y<=495 ; x=x+45, y=y+45)
    {
      line(x,10,x,460);
      line(10,y,460,y);
    }

      ladder();
       getch();
}

void s_l::ladder()
{
     setcolor(GREEN);
    line(340,20,110,380);  //  biggest
    line(360,40,130,400);  //   ladder

    line(375,350,375,255); //small ladder of 2 row jump on right
    line(405,350,405,255);

    line(150,220,60,130);  //small ladder of 2 row jump on left
    line(170,200,80,110);

     setcolor(RED);
    line(260,85,70,360);
    line(250,90,70,360);

    line(300,160,355,300);
    line(320,160,355,300);

    line(270,300,340,380);
    line(255,310,340,380);
}




void s_l::dice()
{
   int dice,xb=60,yb=12;
   dice = random(6) + 1;

    gotoxy( xb , yb );
	pos=pos+dice;

     setcolor(BLUE);
   switch(dice)
   {
      case 1: {
		 rectangle(510,60,580,130);
		 circle(545,95,10);
		  getch();
	      }     break;


       case 2:{
		 rectangle(510,60,580,130);
		  circle(565,115,10);
		 circle(525,75,10);
		    getch();
	      }    break;

	case 3:{
		 rectangle(510,60,580,130);
		 circle(545,95,10);
		 circle(565,115,10);
		 circle(525,75,10);
		  getch();
	      }    break;


	case 4:{
		 rectangle(510,60,580,130);
		 circle(565,115,10);
		 circle(565,75,10);
		 circle(525,115,10);
		 circle(525,75,10);

		  getch();
	      }    break;

	case 5:{
		 rectangle(510,60,580,130);
		 circle(545,95,10);
		  circle(565,115,10);
		 circle(565,75,10);
		 circle(525,115,10);
		 circle(525,75,10);

		  getch();
	      }       break;

	case 6:{
		 rectangle(510,60,580,130);
		 circle(525,75,8);
		 circle(525,95,8);
		 circle(525,115,8);
		 circle(565,75,8);
		 circle(565,95,8);
		 circle(565,115,8);

		  getch();
	      }     break;
   }
    cleardevice();


	if(pos>100)
	  pos-=dice;

      gotoxy(60,15);
       switch(pos)
       {
	  case 67:{ cout<<"You have been bitten!";
			 pos=33;
		  }  break;

	  case 35:{ cout<<"You have been bitten!";
		       pos=13;
		   }   break;

	  case 86:{ cout<<"You have been bitten!";
			pos=22;
		     }   break;

	  case 18:{ cout<<"You got LADDER";
		      pos=93;
		   }   break;

	  case 29:{ cout<<"You got LADDER";
		       pos=49;
		   }   break;


	   case 57:{ cout<<"You got LADDER";
		       pos=79;
		   }    break;


       }
	   getch();
}

 void s_l::puck( )
{
   int 	a,b,x=(pos%10)-1, y=(pos/10);

  if(pos/10==0 || pos/10==2 || pos/10==4 || pos/10==6 || pos/10==8 || pos/10==10)
      {	a=30+45*x;
	 if(a==480)
	   y=y-1;
	   b=440-45*y;
	}
    else
      { a=440-45*x;
	b=440-45*y;
      }

   circle(a,b,10);

   board();
   getch();
}

 void s_l::p1()

{
	   char a;
      while(pos!=100 && pos<100)
    {
      cin>>a;


      if(a=='a')
	    dice();
       else
	  exit(0);

       puck();
       gotoxy(60,10);

      cout<<" Position->" <<pos;
    }

}




 void main()
{
   clrscr();
   randomize();
   int gd = DETECT , gm;
   initgraph( &gd, &gm , "C:\\TC\\BGI");

   gotoxy(25,12);
   cout<<"WELCOME TO Snakes & Ladders!";

      gotoxy(30,16);
	cout<<" A Project by";
       gotoxy(30,17);
	 cout<< "Shikhar & Devankur";
       gotoxy(30,18);
	 cout<< "Class  XII-E";
       gotoxy(30,19);
	 cout<<"Roll No. 19  &  5";

      gotoxy(25,13);
   for(int i =1;i<=28;i++)
       { cout<<char(219);
	 delay(200);
	}

	cleardevice();

   s_l play;
   play.board();
   play.pos=0;
   play.p1();

      cleardevice();

      gotoxy(26,13);
      if(play.pos==100)
	 cout<<"CONGRATULATIONS! You WON!";
      gotoxy(27,14);
	cout<<" THANKS FOR PLAYING!";
   getch();
   closegraph();
}
