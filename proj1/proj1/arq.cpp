#include<GL\glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int sucf=0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1366,0,706);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w,int h)
{	
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glViewport(0,0,w,h);
		gluOrtho2D(0,w,0,h);
		glMatrixMode(GL_MODELVIEW);
}		
void disp()
{
	char sender[]="SENDER",receiver[]="RECEIVER";
		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1,1,1);
		
		glRectd(900,250,1100,350); //sender rectangle
		
		glBegin(GL_LINES);
		glVertex2f(1366,320);
		glVertex2f(1100,320);
		glVertex2f(900,320);
		glVertex2f(300,320);
		
		glVertex2f(1366,300);
		glVertex2f(1100,300);
		
		glVertex2f(900,300);
		glVertex2f(300,300);
		glVertex2f(150,350);
		glVertex2f(150,720);
		glVertex2f(170,350);
		glVertex2f(170,706);
		glEnd();
		
		
		glRectd(100,250,300,350); //receiver rectangle
		
		glColor3f(0,0,1);
		int x=950;
		glRasterPos2f(950,300);
		for(int i=0;sender[i] != '\0';i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sender[i]);//display sender
			x+=15;
			glRasterPos2f(x,300);
		}
		int x1=135;
		glRasterPos2f(135,300);
		for(int i=0;receiver[i] != '\0';i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,receiver[i]);//display receiver
			x1+=15;
			glRasterPos2f(x1,300);
		}
		if(sucf == 1)
		{
			int xi=600;//to change pos of character
			char tosend[]="Packet being sent",ack[]="acknowledgement being sent on successful transmission",rec[]="Packet received";
			glRasterPos2f(600,600);
			for(int i=0;tosend[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,tosend[i]);//display to send
			
			}
			glRasterPos2f(600,300);
			for(int i=870;i>=300;i-=10)
			{	
				int px,pxa;
				glColor3f(0,0.5,0);
				px=i;pxa=i+30;
				glRectd(px,301,pxa,320);
				Sleep(50);
				glFlush();
			}
			glRasterPos2f(100,150);
			glColor3f(0,0,0.5);
			
			Sleep(1000);
			glColor3f(0,0,0);
			glRectd(300,301,900,320);//to clear packet in transmission 
			glRectd(600,500,800,700);// to clear text
			
			glColor3f(0,0.5,0);
			glRectd(151,350,169,380);
			
			glColor3f(0,0.5,0.5);
			glRasterPos2f(500,600);
			for(int i=0;ack[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ack[i]);//display ack
			}
			
			glColor3f(0,0,1);
			glRasterPos2f(100,200);
			for(int i=0;rec[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,rec[i]);//display packet received
			}
			
			for(int i=300;i<=870;i+=10) //to send ack
			{	
				int px,pxa;
				glColor3f(0,0.5,0);
				px=i;pxa=i+30;
				glRectd(px,301,pxa,320);
				Sleep(50);
				glFlush();
			}
			
			
			Sleep(1000);
			glColor3f(0,0,0);
			glRectd(300,301,900,320);//to clear ack packet in transmission line
			glRectd(500,500,980,700);// to clear acknowledgment text 
			char ackrec[]="acknowledgment received",final[]="packet sent and ack recieved successfully";
			glColor3f(0,0,1);
			glRasterPos2f(900,200);
			
			for(int i=0;ackrec[i] != '\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ackrec[i]); // ack received
			}
			glRasterPos2f(500,600);
			for(int i=0;final[i] != '\0';i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,final[i]);
			}
		}//end of if flag=1

		if(sucf == 2)
		{ //unsuccessful trans
		char tosend[]="Packet being sent",packetlost[]="Packet Lost in transmission";
			
			glRasterPos2f(600,600);
			for(int i=0;tosend[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,tosend[i]);//display to send
			}

			for(int i=870;i>=500;i-=10)
			{	
				int px,pxa;
				glColor3f(0,0.5,0);
				px=i;pxa=i+30;
				glRectd(px,301,pxa,320);
				Sleep(50);
				glFlush();
			}
			
			Sleep(50);
			glColor3f(0,0,0);
			glRectd(900,301,500,320);
			glColor3f(0,0.5,0);
			glRectd(470,270,500,290);
			glColor3f(0,0,0);
			glRectd(600,590,800,625);
			glColor3f(0.7,0,0);
			glRasterPos2f(450,235);
			for(int i=0;packetlost[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,packetlost[i]);	//to display packet lost
			}
			glFlush();
			Sleep(1000);
			glColor3f(0,0,0);
			glRectd(450,235,850,250);

			char wait[]="Sender Waits for ack till timeout",timer[]="Timer timed out";
			glColor3f(0,0,1);
			glRasterPos2f(600,600);
			for(int i=0;wait[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,wait[i]);	//to display Sender Waits for ack till timeout
			}
			glFlush();
			Sleep(1500);
			glColor3f(0,0,0);
			glRectd(600,590,900,650);

			glColor3f(0,0,1);
			glRasterPos2f(600,600);
			for(int i=0;timer[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,timer[i]);	//to display Timer timed out
			}
			glFlush();
			Sleep(1000);
			glRasterPos2f(600,500);

			char sendfail[]="Sending Failed sender retransmitts packet";
			glColor3f(0,0,1);
			glRasterPos2f(600,550);
			for(int i=0;sendfail[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,sendfail[i]);	//to display sending failed
			}
		} //end of if of flag =2

		if(sucf == 3)
		{ //ack failed
			char tosend[]="Packet being sent",ack[]="acknowledgement being sent on successful transmission",rec[]="Packet received";
			glRasterPos2f(600,600);
			for(int i=0;tosend[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,tosend[i]);//display to send
			
			}
			glRasterPos2f(600,300);
			for(int i=870;i>=300;i-=10)
			{	
				int px,pxa;
				glColor3f(0,0.5,0);
				px=i;pxa=i+30;
				glRectd(px,301,pxa,320);
				Sleep(50);
				glFlush();
			}
			glRasterPos2f(100,150);
			glColor3f(0,0,0.5);
			
			Sleep(1000);
			glColor3f(0,0,0);
			glRectd(300,301,900,320);//to clear packet in transmission 
			glRectd(600,500,800,700);// to clear text
			
			glColor3f(0,0.5,0);
			glRectd(151,350,169,380);
			
			glColor3f(0,0,1);
			glRasterPos2f(100,200);
			for(int i=0;rec[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,rec[i]);//display packet received
			}

			glColor3f(0,0.5,0.5);
			glRasterPos2f(500,600);
			for(int i=0;ack[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ack[i]);//display ack
			}
			for(int i=300;i<=550;i+=10) //to send ack
			{	
				int px,pxa;
				glColor3f(0,0.5,0);
				px=i;pxa=i+30;
				glRectd(px,301,pxa,320);
				Sleep(50);
				glFlush();
			}
			Sleep(1000);
			glColor3f(0,0,0);
			glRectd(300,301,580,320);
			glColor3f(0,0.5,0);
			glRectd(580,275,610,295);
			glFlush();
			char acklost[]="acknowledgment lost in transmission";
			glColor3f(0,0.5,0.5);
			glRasterPos2f(550,250);
			for(int i=0;acklost[i] != '\0';i++)
			{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,acklost[i]);//display ack
			}
			glFlush();
		} // end of flag 3 i.e failure of ack
			
			glFlush();
}
void menu(int ch)
{
	if(ch==1)
		sucf=1;
	if(ch==2)
		sucf=2;
	if(ch == 4)
		sucf=3;
	if(ch==3)
		exit(0);
	glutPostRedisplay();
}
void sub(int ch)
{
//	if(ch == 1)
}
void menu_2(int ch)
{
}
void main()
	{
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(1366,706);
		glutCreateWindow("hope");
		myinit();
		int menu2=glutCreateMenu(menu_2);
		glutAddMenuEntry("succuessful",1);
		glutAddMenuEntry("unsuccessful (packet)",2);
		glutAddMenuEntry("unsuccessful (ack)",4);
		
		int menu1=glutCreateMenu(menu);
		glutAddMenuEntry("succuessful",1);
		glutAddMenuEntry("unsuccessful (packet)",2);
		glutAddMenuEntry("unsuccessful (ack)",4);
		glutAddMenuEntry("Quit",3);
		glutCreateMenu(sub);
		glutAddSubMenu("st arq",menu1);
		glutAddSubMenu("protocol 2",menu2);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutDisplayFunc(disp);
		glutReshapeFunc(reshape);
		glutMainLoop();
	}
