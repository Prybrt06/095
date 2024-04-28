#include<GLUT/glut.h>
#include<iostream>
using namespace std;

void swap(float *a, float* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dda()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    
    glBegin(GL_LINES);
    glVertex2f(0, 500);
    glVertex2f(0, -500);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(500, 0);
    glVertex2f(-500, 0);
    glEnd();
    
    float x1,y1,x2,y2;
    cout<<"Enter points (x, y) : \n";
    cin>>x1>>y1;
    cin>>x2>>y2;
    
    if(x2<x1)
    {
        swap(&x1,&x2);
        swap(&y1,&y2);
    }
    
    float m;
    
    float x = x1, y = y1;
    
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));
    
    while(x!=x2 && y!=y2)
    {
        m = (y2-y)/(x2-x);
        
        if(abs(m)>=1)
        {
            x = x + (1/m);
            y = y + 1;
        }
        
        else
        {
            x = x + 1;
            y = y + m;
        }
        
        glVertex2f(round(x), round(y));
    }
    
    glEnd();
    
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(5.0);
    gluOrtho2D(-50, 50, -50, 50);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("DDA");

    init();
    glutDisplayFunc(dda);

    glutMainLoop();

    return 0;
}
