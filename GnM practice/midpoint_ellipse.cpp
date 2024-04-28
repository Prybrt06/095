#include<GLUT/glut.h>
#include<iostream>
using namespace std;

float solve(float x, float y, float a, float b)
{
    float ans = x*x*b*b + y*y*a*a - a*a*b*b;
    
    return ans;
}

void midpointEllipse(){
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
    
    float a, b;
    cout<<"Enter a and b : ";
    cin>>a>>b;
    
    float p = b*b - a*a*b + (a*a)/4;
    
    float x = 0, y = b;
    
    vector<pair<int,int>> points;
    
    points.push_back({x, y});
    
    while(2*b*b*x < 2*a*a*y)
    {
        x = x + 1;
        if(p>=0)
        {
            p = p + 2*b*b*x - 2*a*a*y + b*b;
            y = y - 1;
        }
        
        else
        {
            p = p + 2*b*b*x + b*b;
        }
        
        points.push_back({x, y});
    }
    
    p = solve(x+(1/2), y-1, a, b);
    
    while(y!=0)
    {
        y = y - 1;
        if(p>=0)
        {
            p = p - 2*a*a*y + a*a;
        }
        
        else
        {
            x = x + 1;
            p = p - 2*a*a*y + 2*b*b*x + a*a;
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
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Midpoint Ellipse");
    
    glClearColor(1, 1, 1, 0);
    glPointSize(5.0);
    gluOrtho2D(-50, 50, -50, 50);
    
    glutDisplayFunc(midpointEllipse);
    
    glutMainLoop();
}
