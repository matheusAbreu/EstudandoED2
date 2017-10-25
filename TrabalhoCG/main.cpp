/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: matheus
 *
 * Created on 23 de Outubro de 2017, 12:14
 */

#include <cstdlib>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

/*
 * 
 */

void renderFunction()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0,-1.0, 1.0);
    
    //R G B
    glBegin(GL_POLYGON);
        glColor3f(0.0f,0.0f,1.0f);
            glVertex2f(-0.5, -0.5);
        glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5, 0.5);
            glVertex2f(0.5, 0.5);
        glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}
int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    
    glutCreateWindow("OpenGL");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}

