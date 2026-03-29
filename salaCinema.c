#include <GL/freeglut.h>
#include <stdbool.h>

static float fovAngle = 65.0f;
static float fAspect = 1.0f;

void setCameraValues() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovAngle, fAspect, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0, 0.0, 0.0);

    glPushMatrix();
    glRotatef(50, 0.0, 1.0, 0.0);
    glutWireCube(1.0);
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