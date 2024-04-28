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

void drawCube(float size){
    glutSolidCube(size);
}

void drawSphere(float size){
    glutSolidSphere(size, 20, 20);
}

void drawPyramid(float size){
    glBegin(GL_TRIANGLES);
    glVertex3f(size/2, 0, size/2);
    glVertex3f(size/2, 0, -size/2);
    glVertex3f(0, size, 0);
    
    glVertex3f(size/2, 0, -size/2);
    glVertex3f(-size/2, 0, -size/2);
    glVertex3f(0, size, 0);
    
    glVertex3f(-size/2, 0, -size/2);
    glVertex3f(-size/2, 0, size/2);
    glVertex3f(0, size, 0);
    
    glVertex3f(-size/2, 0, size/2);
    glVertex3f(size/2, 0, size/2);
    glVertex3f(0, size, 0);
    glEnd();
}

void createScene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    vector<Object> objects;
    
    objects.push_back({0, {0, 0, -5}, 1});
    objects.push_back({1, {0.5, 0, -6}, 1});
    objects.push_back({2, {-2.5, -1, -4}, 1});
    
    for(auto object: objects)
    {
        glPushMatrix();
        glTranslatef(object.pos.x, object.pos.y, object.pos.z);
        
        switch(object.type){
            case 0: {
                glColor3f(1, 0, 0);
                
                vector<vector<float>> normals;
                normals.push_back({1, 0, 0});
                normals.push_back({-1, 0, 0});
                normals.push_back({0, 1, 0});
                normals.push_back({0, -1, 0});
                normals.push_back({0, 0, 1});
                normals.push_back({0, 0, -1});
                
                for(auto normal: normals)
                {
                    float dot = normal[0]*0 + normal[1]*0 + normal[2]*(-1);
                    
                    if(dot < 0)
                    {
                        drawCube(object.size);
                    }
                }
                
                break;
            }
                
            case 1:{
                glColor3f(0, 1, 0);
                drawSphere(object.size);
                break;
            }
                
            case 2:{
                glColor3f(0, 0, 1);
                Position normal = {0, (float)(-(float)object.size * sqrt(3/2)), (float)object.size / 3};
                
                float dot = normal.x * 0 + normal.y*0 + normal.z*(-1);
                
                if(dot<0)
                {
                    drawPyramid(object.size);
                }
                
                break;
            }
                
            case 3: {
                break;
            }
        }
        
        glPopMatrix();
    }
    
    glutSwapBuffers();
}

void resize(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(450, (float)width/(float)height, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Backface Removal");
    
    glClearColor(1, 1, 1, 0);
//    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(createScene);
    glutReshapeFunc(resize);
    
    glutMainLoop();
    return 0;
}
