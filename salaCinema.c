#include <GL/freeglut.h>
#include <stdbool.h>
#include "models.h"

static float fovAngle = 65.0f;
static float fAspect = 1.0f;
static int rot = 0;
static float posX = 0.0;
static float posZ = 0.0;
static float posY = 0.0;

void setCameraValues() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovAngle, fAspect, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0 + posX, 20.0 + posY, 60.0 + posZ, 0.0 + posX, 0.0 + posY, 0.0 + posZ, 0.0, 1.0, 0.0);
}

void display() {
    
    /* rotacao da cena*/
    glPushMatrix();
    glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0, 0.0, 0.0);

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
    glPushMatrix();
    createLevels();
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
            if(fovAngle < 65.0f)
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
        case 27:
            exit(0);
            break;
    }
    setCameraValues();
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
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