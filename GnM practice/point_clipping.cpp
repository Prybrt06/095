#include<GLUT/glut.h>
#include<string>
#include<iostream>
using namespace std;

void pointClip(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    
    glBegin(GL_LINES);
    glVertex2f(0, -500);
    glVertex2f(0, 500);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glEnd();
    
    int xmin, ymin, xmax, ymax;
    cout<<"Enter min point and max point : \n";
    cin>>xmin>>ymin;
    cin>>xmax>>ymax;
    
    glColor3f(0,0,1);
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmax, ymin);
    glEnd();
    
    int x, y;
    cout<<"Enter the point : \n";
    cin>>x>>y;
    
    string name = "Point is inside the clipping window";
    
    if(x<xmin || x>xmax || y<ymin || y>ymax)
    {
        glColor3f(1, 0, 0);
        
        name = "Point is out of the clipping window";
    }
    
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
    glRasterPos2f(10, 40);
    
    for(int i=0;i<name.length();i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, name[i]);
    }
    
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Point Clipping");
    
    glClearColor(1, 1, 1, 0);
    glPointSize(5);
    glLineWidth(2);
    gluOrtho2D(-50, 50, -50, 50);
    
    glutDisplayFunc(pointClip);
    
    glutMainLoop();
    
    return 0;
}
