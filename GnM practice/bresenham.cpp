#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bresenham()
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

    float x1, y1, x2, y2;

    cout << "Enter two points : \n";
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    if (x2 < x1)
    {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }

    float x = x1, y = y1;

    float dx = (x2 - x1);
    float dy = (y2 - y1);

    float p;

    glColor3f(0, 0, 0);

    glBegin(GL_POINTS);
    glVertex2f(x, y);

    float m = dy / dx;
    
    if(m>=0)
    {
        if (abs(m) < 1)
        {
            p = 2 * dy - dx;
            
            while (x != x2 && y != y2)
            {
                cout << "p : " << p << endl;
                
                if (p >= 0)
                {
                    y = y + 1;
                    p = p + 2 * dy - 2 * dx;
                }
                
                else
                {
                    p = p + 2 * dy;
                }
                x = x + 1;
                
                cout << x << " " << y << endl;
                
                glVertex2f(x, y);
            }
        }
        
        else
        {
            p = 2 * dx - dy;
            
            while (x != x2 && y != y2)
            {
                cout << "p : " << p << endl;
                
                if (p >= 0)
                {
                    x = x + 1;
                    p = p + 2 * dx - 2 * dy;
                }
                
                else
                {
                    p = p + 2 * dx;
                }
                y = y + 1;
                
                cout << x << " " << y << endl;
                
                glVertex2f(x, y);
            }
        }
    }
    
    else
    {
        cout<<"Negative m\n";
        if (abs(m) < 1)
        {
            p = - 2 * dy - dx;
            
            while (x != x2 && y != y2)
            {
                cout << "p : " << p << endl;
                
                if (p >= 0)
                {
                    y = y - 1;
                    p = p - 2 * dy - 2 * dx;
                }
                
                else
                {
                    p = p - 2 * dy;
                }
                x = x + 1;
                
                cout << x << " " << y << endl;
                
                glVertex2f(x, y);
            }
        }
        
        else
        {
            p = 2 * dx + dy;
            cout<<"he\n";
            while (x != x2 && y != y2)
            {
                cout << "p : " << p << endl;
                
                if (p >= 0)
                {
                    x = x + 1;
                    p = p + 2 * dx + 2 * dy;
                }
                
                else
                {
                    p = p + 2 * dx;
                }
                y = y - 1;
                
                cout << x << " " << y << endl;
                
                glVertex2f(x, y);
            }
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

    glutDisplayFunc(bresenham);

    glutMainLoop();
}
