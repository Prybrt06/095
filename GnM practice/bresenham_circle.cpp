#include<GLUT/glut.h>
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bresenhamCircle(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    
    glBegin(GL_LINES);
    glVertex2f(0, -500);
    glVertex2f(0, 500);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glEnd();
    
//    int cx, cy;
    int r;
    
    cout<<"Enter radius : ";
    cin>>r;
    
    vector<pair<int, int>> points;
    
    int x = 0, y = r;
    
    points.push_back({x, y});
    
    float p = 3 - 2*r;
    while(x<y)
    {
        x = x + 1;
        if(p>=0)
        {
            y = y-1;
            p = p + 4*(x-y) + 10;
        }
        
        else
        {
            p = p + 4*x + 6;
        }
        
        points.push_back({x,y});
    }
    
    glBegin(GL_POINTS);
    for(auto point: points)
    {
        x = point.first;
        y = point.second;
        
        glVertex2f(x, y);
        
        for(int i=0;i<x;i++)
        {
            glVertex2f(i, y);
        }
        
        glVertex2f(x, -y);
        
        for(int i=0;i<x;i++)
        {
            glVertex2f(i, -y);
        }
        
        glVertex2f(-x, y);
        
        for(int i=0;i>-x;i--)
        {
            glVertex2f(i, y);
        }
        
        glVertex2f(-x, -y);
        
        for(int i=0;i>-x;i--)
        {
            glVertex2f(i, -y);
        }
        
        swap(&x,&y);
        
        glVertex2f(x, y);
        
        for(int i=0;i<x;i++)
        {
            glVertex2f(i, y);
        }
        
        glVertex2f(x, -y);
        
        for(int i=0;i<x;i++)
        {
            glVertex2f(i, -y);
        }
        
        glVertex2f(-x, y);
        
        for(int i=0;i>-x;i--)
        {
            glVertex2f(i, y);
        }
        
        glVertex2f(-x, -y);
        
        for(int i=0;i>-x;i--)
        {
            glVertex2f(i, -y);
        }
    }
    
    glEnd();
    
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Bresenham");

    glClearColor(1, 1, 1, 0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);

    glutDisplayFunc(bresenhamCircle);

    glutMainLoop();
}

