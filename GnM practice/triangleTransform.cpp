#include<GLUT/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

vector<vector<float>> matrixMultiplication(vector<vector<float>> a, vector<vector<float>> b)
{
    auto n = a.size();
    auto m = a[0].size();
    
    vector<vector<float>> ans;
    for(int i=0;i<n;i++)
    {
        vector<float> temp;
        for(int j=0;j<m;j++)
        {
            float pro = 0;
            for(int k=0;k<m;k++)
            {
                pro += a[i][k]*b[k][j];
            }
            
            cout<<pro<<endl;
            temp.push_back(pro);
        }
        
        ans.push_back(temp);
    }
    
    return ans;
}

void transform(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    
    vector<pair<float, float>> points;
    
    points.push_back({10, 10});
    points.push_back({20, 30});
    points.push_back({50, 10});
    
    glBegin(GL_LINES);
    glVertex2f(0, 500);
    glVertex2f(0, -500);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(500, 0);
    glVertex2f(-500, 0);
    glEnd();
    
    glLineWidth(2);
    
    glBegin(GL_LINE_LOOP);
    for(auto point: points)
    {
        glVertex2f(point.first, point.second);
    }
    glEnd();
    
    
//    float sx, sy;
//    cin>>sx>>sy;
    
//    float tx, ty;
//    cin>>tx>>ty;
    
//    float angle;
//    cin>>angle;
//    
//    float radian = angle * 3.14/180;
//    
//    float sinValue = sin(radian);
//    float cosValue = cos(radian);
    
    float shx, shy;
    cin>>shx>>shy;
    
//    vector<vector<float>> translate = {{1, 0, tx},{0, 1, ty},{0, 0, 1}};
//    vector<vector<float>> scale = {{sx, 0, 0},{0, sy, 0},{0, 0, 1}};
//    vector<vector<float>> rotate = {{cosValue, -sinValue, 0},{sinValue, cosValue, 0},{0, 0, 1}};
//    vector<vector<float>> reflecAboutX = {{1, 0, 0},{0, -1, 0},{0, 0, 1}};
//    vector<vector<float>> reflecAboutY = {{-1, 0, 0},{0, 1, 0},{0, 0, 1}};
    vector<vector<float>> shear = {{1, shx, 0}, {shy, 1, 0}, {0, 0, 1}};
    
    vector<vector<float>> translateToCenter = {{1, 0, -points[0].first}, {0, 1, -points[0].second}, {0, 0, 1}};
    vector<vector<float>> translateBack = {{1, 0, points[0].first}, {0, 1, points[0].second}, {0, 0, 1}};
    
    glBegin(GL_POLYGON);
    for(auto point: points)
    {
        vector<vector<float>> temp = matrixMultiplication(translateToCenter, {{point.first},{point.second},{1}});
        temp = matrixMultiplication(shear, temp);
        temp = matrixMultiplication(translateBack, temp);
        cout<<temp[0][0]<<" "<<temp[1][0]<<endl;
        glVertex2f(temp[0][0], temp[1][0]);
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Transform");
    
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(-100, 100, -100, 100);
    
    glutDisplayFunc(transform);
    
    glutMainLoop();
    
    return 0;
}
