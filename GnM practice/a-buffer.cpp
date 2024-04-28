#include<GLUT/glut.h>
#include<iostream>
using namespace std;

class Position{
public:
    float x, y, z;
};

class Object{
public:
    int type;
    Position pos;
    float size;
};

class Fragment {
public:
    float x;
    float r, g, b;
};

vector<vector<Fragment>> aBuffer;
int screenWidth = 750;
int screenHeight = 750;

void drawCube(float size){
    glutSolidCube(size/2);
}

void drawSphere(float size){
    glutSolidSphere(size, 20, 20);
}

void drawPyramid(float size){
    glBegin(GL_TRIANGLES);
    glVertex3f(-size / 2, 0, -size / 2);
    glVertex3f(size / 2, 0, -size / 2);
    glVertex3f(0, size, 0);
    
    glVertex3f(size / 2, 0, -size / 2);
    glVertex3f(size / 2, 0, size / 2);
    glVertex3f(0, size, 0);
    
    glVertex3f(size / 2, 0, size / 2);
    glVertex3f(-size / 2, 0, size / 2);
    glVertex3f(0, size, 0);
    
    glVertex3f(-size / 2, 0, size / 2);
    glVertex3f(-size / 2, 0, -size / 2);
    glVertex3f(0, size, 0);
    glEnd();
}

void resize(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)width/(float)height, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    
//    screenWidth = width;
//    screenHeight = height;
//    
//    aBuffer.resize(screenWidth*screenHeight);
}

void createScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0, 0, 0);
    
//    glBegin(GL_LINES);
//    glVertex2f(0, 500);
//    glVertex2f(0, -500);
//    glEnd();
//    
//    glBegin(GL_LINES);
//    glVertex2f(500, 0);
//    glVertex2f(-500, 0);
//    glEnd();
    
    vector<Object> objects;
    
    objects.push_back({1, {0, 1.3, -5}, 1});
    objects.push_back({2, {0.5, 0, -4}, 1});
    objects.push_back({3, {2, 0, -5}, 1});
    
    for(auto object: objects)
    {
        glPushMatrix();
        glTranslatef(object.pos.x, object.pos.y, object.pos.z);
        
        switch (object.type) {
            case 1:
                glColor3f(1, 0, 0);
                drawCube(object.size);
                break;
            
            case 2:
                glColor3f(0, 1, 0);
                drawSphere(object.size);
                break;
                
            case 3:
                glColor3f(0, 0, 1);
                drawPyramid(object.size);
                break;
                
            default:
                break;
        }
        
        glPopMatrix();
    }
    
    glutSwapBuffers();
    
//    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("A Buffer");
    
    glEnable(GL_DEPTH_TEST);
//    aBuffer.resize(screenWidth*screenHeight);
    
    glClearColor(1, 1, 1, 0);
//    gluOrtho2D(-50, 50, -50, 50);
    
    glutDisplayFunc(createScene);
    glutReshapeFunc(resize);
    
    glutMainLoop();
    
    return 0;
}
