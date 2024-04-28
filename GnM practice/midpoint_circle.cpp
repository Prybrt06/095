#include<GLUT/glut.h>
#include<iostream>
using namespace std;

void midpointCircle(){
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
    
    int r;
    
    cout<<"Enter radius : ";
    cin>>r;
    
    int x = 0, y = r;
    
    int p = 1-r;
    
    vector<pair<int,int>> points;
    points.push_back({x,y});
    
    while(x<y)
    {
        x = x+1;
        if(p>=0)
        {
            y = y-1;
            p = p + 2*(x-y) + 1;
        }
        
        else
        {
            p = p + 2*x + 1;
        }
        
        points.push_back({x,y});
    }
    
    glBegin(GL_POINTS);
    for(auto point: points)
    {
        x = point.first;
        y = point.second;
        
        glVertex2f(x, y);
        glVertex2f(-x, y);
        glVertex2f(-x, -y);
        glVertex2f(x, -y);
        
        glVertex2f(y, x);
        glVertex2f(-y, x);
        glVertex2f(-y, -x);
        glVertex2f(y, -x);
    }
    
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Midpoint circle");
    
    glClearColor(1, 1, 1, 0);
    glPointSize(5.0);
    gluOrtho2D(-50, 50, -50, 50);
    
    glutDisplayFunc(midpointCircle);
    
    glutMainLoop();
}
