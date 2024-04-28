#include<GLUT/glut.h>
#include<iostream>
using namespace std;

int xmin, ymin, xmax, ymax;

void left(vector<pair<float, float>> points, vector<pair<float, float>>& finalPoints){
    int n = points.size();
    
    for(int i=0;i<n;i++)
    {
        pair<float, float> p1 = points[i];
        pair<float, float> p2;
        if(i==n-1){
            p2 = points[0];
        }
        
        else{
            p2 = points[i+1];
        }
        
        if(p1.first<xmin)
        {
            if(p2.first<xmin)
            {
                
            }
            
            else
            {
                float x = xmin;
                float y = p2.second - (p2.second - p1.second)*(p2.first - x)/(p2.first - p1.first);
                
                finalPoints.push_back({x, y});
                finalPoints.push_back(p2);
            }
        }
        
        else
        {
            if(p2.first<xmin)
            {
                float x = xmin;
                float y = p2.second - (p2.second - p1.second)*(p2.first - x)/(p2.first - p1.first);
                
                finalPoints.push_back({x, y});
            }
            
            else{
                finalPoints.push_back(p2);
            }
        }
    }
}

void right(vector<pair<float, float>> points, vector<pair<float, float>>& finalPoints){
    int n = points.size();
    
    for(int i=0;i<n;i++){
        pair<float, float> p1 = points[i];
        pair<float, float> p2;
        
        if(i==n-1)
        {
            p2 = points[0];
        }
        else {
            p2 = points[i+1];
        }
        
        if(p1.first<=xmax)
        {
            if(p2.first<=xmax)
            {
                finalPoints.push_back(p2);
            }
            
            else
            {
                float x = xmax;
                float y = p2.second - (p2.second - p1.second)*(p2.first - x)/(p2.first - p1.first);
                
                finalPoints.push_back({x, y});
            }
        }
        
        else
        {
            if(p2.first<=xmax)
            {
                float x = xmax;
                float y = p2.second - (p2.second - p1.second)*(p2.first - x)/(p2.first - p1.first);
                
                finalPoints.push_back({x, y});
                finalPoints.push_back(p2);
            }
        }
    }
}

void top(vector<pair<float, float>> points, vector<pair<float, float>>& finalPoints){
    int n = points.size();
    for(int i=0;i<n;i++)
    {
        pair<float, float> p1 = points[i];
        pair<float, float> p2;
        
        if(i==n-1)
        {
            p2 = points[0];
        }
        
        else{
            p2 = points[i+1];
        }
        
        if(p1.second>ymax)
        {
            if(p2.second>ymax){
                
            }
            
            else{
                float y = ymax;
                float x = p2.first - (p2.second-y)*(p2.first - p1.first)/(p2.second - p1.second);
                
                finalPoints.push_back({x, y});
                finalPoints.push_back(p2);
            }
        }
        
        else
        {
            if(p2.second<=ymax)
            {
                finalPoints.push_back(p2);
            }
            
            else{
                float y = ymax;
                float x = p2.first - (p2.second-y)*(p2.first - p1.first)/(p2.second - p1.second);
                
                finalPoints.push_back({x, y});
            }
        }
    }
}

void bottom(vector<pair<float, float>> points, vector<pair<float, float>>& finalPoints) {
    int n = points.size();
    
    for(int i=0;i<n;i++){
        pair<float, float> p1 = points[i];
        pair<float, float> p2;
        
        if(i==n-1)
        {
            p2 = points[0];
        }
        
        else{
            p2 = points[i+1];
        }
        
        if(p1.second<ymin)
        {
            if(p2.second<ymin){
                
            }
            
            else{
                float y = ymin;
                float x = p2.first - (p2.second - y)*(p2.first - p1.first)/(p2.second - p1.second);
                
                finalPoints.push_back({x, y});
                finalPoints.push_back(p2);
            }
        }
        
        else {
            if(p2.second<ymin) {
                float y = ymin;
                float x = p2.first - (p2.second - y)*(p2.first - p1.first)/(p2.second - p1.second);
                
                finalPoints.push_back({x, y});
            }
            
            else{
                finalPoints.push_back(p2);
            }
        }
    }
}

void polygonClipping(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0, 0, 0);
    
    glBegin(GL_LINES);
    glVertex2f(0, 500);
    glVertex2f(0, -500);
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glEnd();
    
    vector<pair<float, float>> points;
    
    cout<<"Enter no of points followed by the points (x, y)\n";
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        float x, y;
        cin>>x>>y;
        
        points.push_back({x, y});
    }
    
    cout<<"Enter min and max points of the clipping window\n";
    cin>>xmin>>ymin;
    cin>>xmax>>ymax;
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();
    
    vector<pair<float, float>> finalPoints;
    
    left(points, finalPoints);
    points = finalPoints;
    finalPoints.clear();
    
    right(points, finalPoints);
    points = finalPoints;
    finalPoints.clear();
    
    top(points, finalPoints);
    points = finalPoints;
    finalPoints.clear();
    
    bottom(points, finalPoints);
    points = finalPoints;
    finalPoints.clear();
    
    for(auto point: points)
    {
        cout<<point.first<<" "<<point.second<<endl;
    }
    
    glBegin(GL_POLYGON);
    
    for(auto point: points)
    {
        glVertex2f(point.first, point.second);
    }
    
    glEnd();
    
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    
    glutCreateWindow("Polygon Clipping");
    
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(-250, 250, -250, 250);
    
    glutDisplayFunc(polygonClipping);
    
    glutMainLoop();
    
    return 0;
}
