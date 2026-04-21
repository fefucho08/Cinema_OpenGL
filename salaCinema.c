// Felipe Ferreira Moreira 237124
// Juliana da Costa Silva 241078

#include <GL/freeglut.h>
#include <stdbool.h>
#include <stdio.h>
#include "image.h"
#include "models.h"

#define MOVIE_TEXTURE "shrek.sgi"


static float fovAngle = 80.0f;
static float fAspect = 1.0f;
static int rot = 0;
static float posX = 0.0;
static float posZ = 0.0;
static float posY = 0.0;
bool screenOn = true;

GLuint texture_screen;

void setCameraValues() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovAngle, fAspect, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0 + posX, 12.0 + posY, 0.0 + posZ, 0.0 + posX, 12.0 + posY, -1.0 + posZ, 0.0, 1.0, 0.0);
}

void display() {

    /* rotacao da cena*/
    glPushMatrix();
    glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    createRoom();

    float seatX = -10;
    float seatZ = 0;
    float seatY = 2.4;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 6; j++) {
            glPushMatrix();
            glTranslatef(seatX, 0.3 + seatY, seatZ);
            glRotatef(180, 0.0, 1.0, 0.0);
            createSeat();
            glPopMatrix();
            seatX += 4;
        }
        seatX = -10;
        seatZ += 6;
        seatY += 1.2;
    }
    createLevels();
    createStepLights();

    createDoor();

    float wall = 1.0;
    for(int i = 0; i < 2; i++) {
        float posZ = 0.0;
        float posY = 15.0;
        for(int j = 0; j < 4; j++) {
            glPushMatrix();
                glTranslatef(0.0, posY, posZ);
                createSpeaker(wall);
            glPopMatrix();
            posZ += 6;
            posY += 1.2;
        }
        wall = -wall;
    }

    createLights();

    glPushMatrix();
    glTranslatef(0.0, 20.3, 11.0);
    glScalef(0.6, 0.6, 0.6);
    createProjector();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    fAspect = (float)w / (float)h;

    setCameraValues();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            if(fovAngle > 10.0f)
                fovAngle -= 2;
            break;
        case '-':
            if(fovAngle < 80.0f)
                fovAngle += 2;
            break;
        case 'r':
            rot = (rot+5) % 360;
            break;
        case 'R':
            rot = (rot-5) % 360;
            break;
        case 'd':
            posX += 1.0;
            break;
        case 'a':
            posX -= 1.0;
            break;
        case 'w':
            posZ -= 1.0;
            break;
        case 's':
            posZ += 1.0;
            break;
        case 'q':
            posY += 1.0;
            break;
        case 'e':
            posY -= 1.0;
            break;
        case 'l':
            screenOn = !screenOn;
            break;
        case 27:
            exit(0);
            break;
    }
    setCameraValues();
    glutPostRedisplay();
}

void loadTextures(){
    IMAGE *img;
    GLenum gluerr;

    /* textura do plano */
    glGenTextures(1, &texture_screen);
    glBindTexture(GL_TEXTURE_2D, texture_screen);

    if(!(img=ImageLoad(MOVIE_TEXTURE))) {
        fprintf(stderr,"Error reading a texture.\n");
        exit(-1);
    }

    gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
                 img->sizeX, img->sizeY,
                 GL_RGB, GL_UNSIGNED_BYTE,
                 (GLvoid *)(img->data));
    if(gluerr){
        fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
        exit(-1);
    }

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    loadTextures();
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}