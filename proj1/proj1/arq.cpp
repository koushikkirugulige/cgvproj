#include<GL\glut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int sucf = 0, name = 0;

void disp_name(char * str, int x, int y)
{
	glColor3f(0.522, 0, 0.522);
	glRasterPos2f(x, y);
	for (int i = 0; str[i] != '\0'; i++)    //to display all alphabets
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	glFlush();
}
void disp_msg(char * str, int x, int y, int ack)
{
	if (ack == 0)
		glColor3f(1, 0.502, 0.502);
	else
		glColor3f(0, 1, 1);
	glRasterPos2f(x, y);
	for (int i = 0; str[i] != '\0'; i++)    //to display all alphabets
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	glFlush();
}
void clear() //clear main text
{
	glColor3f(0, 0, 0);
	glRectd(391, 555, 1104, 666);
}
void clear_rec()
{
	glColor3f(0, 0, 0);
	glRectd(900, 150, 1100, 245);
}
void clear_sen()
{
	glColor3f(0, 0, 0);
	glRectd(100, 150, 300, 245);
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1366, 0, 706);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w, int h)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}
void disp()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glRectd(900, 250, 1100, 350); //sender rect

	glRectd(100, 250, 300, 350); //receiver rect
	glBegin(GL_LINES);
	glVertex2f(300, 300);
	glVertex2f(900, 300);

	glVertex2f(300, 320);
	glVertex2f(900, 320);
	glEnd();
	char sender[] = "SENDER", receiver[] = "RECEIVER";
	glColor3f(0, 0, 0.5);
	disp_msg(receiver, 120, 295, 0);
	disp_msg(sender, 920, 295, 0);
	glFlush();

	if (sucf == 1) //successful case
	{

		char tosend[100] = "Packet 0 being sent", ack[100] = "Acknowledgement 1 being sent on successful transmission";
		char rec[100] = "Packet 0 received";
		disp_msg(tosend, 600, 600, 0);

		for (int i = 870; i >= 300; i -= 10) //to send packet
		{
			int px, pxa;
			glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);//to clear packet in transmission 
		clear();
		glColor3f(0, 0.5, 0);
		glRectd(151, 350, 169, 380);
		disp_msg(ack, 400, 600, 1);
		disp_msg(rec, 100, 200, 0);
		glFlush();
		glColor3f(0, 1, 1);
		for (int i = 300; i <= 870; i += 10) //to send ack
		{
			int px, pxa;
			//glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		char tosend1[] = "Packet 1 being sent", ack1[] = "Acknowledgement 0 being sent on successful transmission";
		char rec1[] = "Packet 1 received", ackrec[] = "Ack 1 received", ackrec2[] = "Ack 0 received";
		disp_msg(ackrec, 900, 200, 1);

		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);//to clear packet in transmission 
		clear();
		clear_rec();
		clear_sen();
		glColor3f(1, 1, 1);
		disp_msg(tosend1, 600, 600, 0);
		for (int i = 870; i >= 300; i -= 10) //to send packet
		{
			int px, pxa;
			glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		disp_msg(rec1, 100, 200, 0);
		glColor3f(0, 0.5, 0);
		glRectd(151, 381, 169, 411);// 2nd packet at rec side
		glFlush();
		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);//to clear packet in transmission 
		clear();

		disp_msg(ack1, 400, 600, 1);
		glColor3f(0, 1, 1);
		for (int i = 300; i <= 870; i += 10) //to send ack
		{
			int px, pxa;
			//glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		disp_msg(ackrec2, 900, 200, 1);
		/*
		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);//to clear packet in transmission
		clear();
		clear_rec();
		clear_sen();

		char tosend2[] = "Packet 3 being sent";
		char rec2[] = "Packet 3 received", comp[] = "Transmission complete";
		disp_msg(tosend2, 600, 600);

		for (int i = 870; i >= 300; i -= 10) //to send packet
		{
		int px, pxa;
		glColor3f(0, 0.5, 0);
		px = i; pxa = i + 30;
		glRectd(px, 301, pxa, 320);
		Sleep(50);
		glFlush();
		}

		disp_msg(rec2, 100, 200);
		glColor3f(0, 0.5, 0);
		glRectd(151, 412, 169, 442);// 2nd packet at rec side
		glFlush();
		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);//to clear packet in transmission
		clear();
		disp_msg(comp, 600, 600);
		*/
	}//end of if ==1
	if (sucf == 2)
	{
		char tosend[] = "Packet being sent", packetlost[] = "Packet Lost in transmission", timer[] = "Timer Timed out";
		char retrans[] = "Retransmitting packets";
		disp_msg(tosend, 600, 600, 0);
		for (int i = 870; i >= 500; i -= 10) //sending the packet
		{
			int px, pxa;
			glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}

		Sleep(200);
		glColor3f(0, 0, 0);
		glRectd(900, 301, 500, 320);
		glColor3f(0, 0.5, 0);
		glRectd(470, 270, 500, 290);
		
		clear();
		disp_msg(packetlost, 600, 600, 0);
		Sleep(1500);
		clear();
		disp_msg(timer, 600, 600, 0);
		Sleep(1500);
		clear();
		disp_msg(retrans, 600, 600, 0);
		Sleep(1000);
		sucf = 1;
		glutPostRedisplay();
	}// end of if sucf==2

	if (sucf == 3)
	{
		char tosend[] = "Packet 1 being sent", ack[] = "acknowledgement  2 being sent on successful transmission";
		char rec[] = "Packet  1 received", acklost[] = "ack lost in transmission", timer[] = "Timer timed out";
		char retrans[] = "Retransmitting packets";
		disp_msg(tosend, 600, 600, 0);
		for (int i = 870; i >= 300; i -= 10)
		{
			int px, pxa;
			glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		disp_msg(rec, 100, 200, 0);
		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);//to clear packet in transmission 
		clear();
		glColor3f(0, 0.5, 0);
		glRectd(151, 350, 169, 380);
		disp_msg(ack, 600, 600, 1);
		glColor3f(0, 1, 1);
		for (int i = 300; i <= 550; i += 10) //to send ack
		{
			int px, pxa;
			//glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}

		Sleep(1000);
		glColor3f(0, 0, 0);
		glRectd(300, 301, 580, 320);
		glColor3f(0, 0.5, 0);
		glRectd(580, 275, 610, 295);
		glFlush();
		clear();
		disp_msg(acklost, 600, 600, 1);
		Sleep(1500);
		clear();
		disp_msg(timer, 600, 600, 0);
		Sleep(1500);
		clear();
		disp_msg(retrans, 600, 600, 0);
		Sleep(1500);
		sucf = 1;
		glutPostRedisplay();
	} // end of if==3

	if (sucf == 4) //arq success
	{
		cout << "Hello";
		char tosend[] = "Packet being sent", sucss[] = "Sucessful Transmission", rec[] = "Packet received";
		disp_msg(tosend, 600, 600, 0);
		for (int i = 870; i >= 300; i -= 10)
		{
			int px, pxa;
			glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		Sleep(1000);
		glColor3f(0, 0.5, 0);
		glRectd(151, 350, 169, 380);
		glFlush();
		glColor3f(0, 0, 0);
		glRectd(300, 301, 900, 320);
		glRectd(151, 350, 169, 380);
		clear();
		disp_msg(rec, 100, 200, 0);
		disp_msg(sucss, 600, 600, 0);
	}// end of sucf 4

	if (sucf == 5) //unsucesful arq
	{
		char tosend[] = "Packet being sent", lost[] = "Packet lost but Sender dosen't know it", unsu[] = "Hence unsucessful transmission";
		disp_msg(tosend, 600, 600, 0);
		for (int i = 870; i >= 500; i -= 10) //sending the packet
		{
			int px, pxa;
			glColor3f(0, 0.5, 0);
			px = i; pxa = i + 30;
			glRectd(px, 301, pxa, 320);
			Sleep(50);
			glFlush();
		}
		Sleep(200);
		glColor3f(0, 0, 0);
		glRectd(900, 301, 500, 320);
		glColor3f(0, 0.5, 0);
		glRectd(470, 270, 500, 290);
		clear();
		disp_msg(lost, 600, 600, 1);
		Sleep(1500);
		clear();
		disp_msg(unsu, 600, 600, 1);


	} //end of if ==5
	if (name == 1)
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		char projdon[] = "Project Done By ", koushikr[] = "KOUSHIK R K", koushikks[] = "KOUSHIK K S", harish[] = "HARISH SHETTY K";
		disp_msg(projdon, 600, 600, 0);
		disp_name(harish, 600, 500);
		disp_name(koushikks, 600, 400);
		disp_name(koushikr, 600, 300);
		Sleep(5000);
		exit(0);

	}

	glFlush();
}
void mouse(int b, int s, int x, int y)
{
	if (b = GLUT_LEFT_BUTTON && s == GLUT_DOWN)
		cout << x << "\t" << 706 - y << endl;
}
void menu(int ch)
{
	if (ch == 1)
		sucf = 1;
	if (ch == 2)
		sucf = 2;
	if (ch == 4)
		sucf = 3;
	glutPostRedisplay();
}
void sub(int ch)
{
	if (ch == 3)
	{
		name = 1;
		sucf = 0;
		glutPostRedisplay();
	}
	}
void menu_2(int cho)
{
	if (cho == 6)
		sucf = 4;
	if (cho == 7)
		sucf = 5;
	glutPostRedisplay();
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 706);
	glutCreateWindow("ARQ PROTOCOLS");
	myinit();
	int menu2 = glutCreateMenu(menu_2);
	glutAddMenuEntry("Succuessful", 6);
	glutAddMenuEntry("Unsuccessful", 7);


	int menu1 = glutCreateMenu(menu);
	glutAddMenuEntry("Succuessful", 1);
	glutAddMenuEntry("Unsuccessful(Packet)", 2);
	glutAddMenuEntry("Unsuccessful(Ack)", 4);

	glutCreateMenu(sub);
	glutAddSubMenu("SW ARQ", menu1);
	glutAddSubMenu("ARQ", menu2);
	glutAddMenuEntry("Quit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
