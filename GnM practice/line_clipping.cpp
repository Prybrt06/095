#include<GLUT/glut.h>
#include<string>
#include<iostream>
using namespace std;

void lineClipping(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    
    int xmin, ymin, xmax, ymax;
    cout<<"Enter min and max point : \n";
    cin>>xmin>>ymin;
    cin>>xmax>>ymax;
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmax, ymin);
    glEnd();
    
    int top = 8;
    int bottom = 4;
    int right = 2;
    int left = 1;
    
    int x1, y1, x2, y2;
    
    cout<<"Enter the two points : \n";
    cin>>x1>>y1;
    cin>>x2>>y2;
    
    int region1 = 0;
    int region2 = 0;
    
    if(x1<xmin)
    {
        region1 |= left;
    }
    
    if(x1>xmax)
    {
        region1 |= right;
    }
    
    if(y1<ymin)
    {
        region1 |= bottom;
    }
    
    if(y1>ymax)
    {
        region1 |= top;
    }

    if(x2<xmin)
    {
        region2 |= left;
    }

    if(x2>xmax)
    {
        region2 |= right;
    }

    if(y2<ymin)
    {
        region2 |= bottom;
    }

    if(y2>ymax)
    {
        region2 |= top;
    }
    
    glColor3f(1, 0, 0);
        
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    
    if(region1 & region2)
    {
        glColor3f(1, 0, 0);
        
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
    
    else{
        float m = (y2-y1)/(x2-x1);
        
        if(region1 & left)
        {
            y1 = m*(xmin-x1) + y1;
            x1 = xmin;
        }
        
        if(region1 & top)
        {
            y1 = ymax;
            x1 = m/(y2-y1) + x2;
        }
        
        if(region1 & bottom)
        {
            y1 = ymin;
            x1 = m/(y2-y1) + x2;
        }
        
        if(region2 & left)
        {
            x2 = xmin;
            y2 = m*(x2-x1) + y1;
        }
        
        if(region1 & right)
        {
            x2 = xmax;
            y2 = m*(x2-x1) + y1;
        }
        
        if(region1 & top)
        {
            y2 = ymax;
            x2 = m/(y2-y1) + x1;
        }
        
        if(region1 & bottom)
        {
            y2 = ymin;
            x2 = m/(y2-y1) + x1;
        }
        
        glColor3f(0, 1, 0);
        
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Line Clipping");
    
    glClearColor(1,1,1,0);
    glPointSize(5.0);
    gluOrtho2D(-50, 50, -50, 50);
    
    glutDisplayFunc(lineClipping);
    
    glutMainLoop();
    
    return 0;
}
