#include <GL/freeglut.h>
#include <stdbool.h>

static float fovAngle = 65.0f;
static float fAspect = 1.0f;
static int rot = 0;
static float posX = 0.0;
static float posZ = 0.0;
static float posY = 0.0;

void createSeat() {
    
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        // BRACO ESQUERDO
        glPushMatrix();
            glTranslatef(-1.5, 1.0, 0.0);
            glPushMatrix();
                glScalef(0.75, 2.0, 3.0);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, 1.0, 1.5);
                glRotatef(90, 1.0, 0.0, 0.0);
                glutSolidCylinder(0.375, 2.0, 10.0, 1.0);
            glPopMatrix();
        glPopMatrix();

        // BRACO ESQUERDO
        glPushMatrix();
            glTranslatef(1.5, 1.0, 0.0);
            glPushMatrix();
                glScalef(0.75, 2.0, 3.0);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, 1.0, 1.5);
                glRotatef(90, 1.0, 0.0, 0.0);
                glutSolidCylinder(0.375, 2.0, 10.0, 1.0);
            glPopMatrix();
        glPopMatrix();

        // ASSENTO
        glColor3f(1.0, 1.0, 0.0);
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glScalef(2.5, 1, 2.0);
            glutSolidCube(1.0);
        glPopMatrix();
        
        // ENCOSTO
        glColor3f(0.0, 0.0, 1.0);
        glPushMatrix();
            glTranslatef(0.0, 2.0, -1);
            glScalef(2.5, 4.0, 1.0);
            glutSolidCube(1.0);
        glPopMatrix();

    glPopMatrix();
}

void createRoom() {
    // CHAO
    glColor3f(0.3, 0.3, 0.3);
    glPushMatrix();
    glScalef(32.0, 0.6, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // TETO
    glPushMatrix();
    glTranslatef(0.0, 20.6, 0.0);
    glScalef(32.0, 0.6, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // PAREDE LATERAL ESQUERDA
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-15.7, 10.3, 0.0);
    glScalef(0.6, 20.0, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // PAREDE TELA
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.3, 10.3, -20);
    glScalef(31.4, 20.0, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // TELA
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -19.55);
    glScalef(1.0, 1.0, 0.3);

    // BORDAS DA TELA
    // borda inferior
    glPushMatrix();
    glTranslatef(0.0, 4.3, 0.0);
    glScalef(24.0, 0.3, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //borda lateral esquerda
    glPushMatrix();
    glTranslatef(-11.85, 10.3, 0.0);
    glScalef(0.3, 11.7, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // borda superior
    glPushMatrix();
    glTranslatef(0.15, 16, 0.0);
    glScalef(23.7, 0.3, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // borda lateral direita;
    glPushMatrix();
    glTranslatef(11.85, 10.15, 0.0);
    glScalef(0.3, 11.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // INTERIOR DA TELA

    glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glTranslatef(0.0, 10.15, 0.0);
    glScalef(23.4, 11.4, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

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

    // glPushMatrix();
    // glRotatef(50, 0.0, 1.0, 0.0);
    // glutSolidCube(1.0);
    // glPopMatrix();
    createRoom();


    float seatX = -10;
    float seatZ = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 6; j++) {
            glPushMatrix();
            glTranslatef(seatX, 0.6, seatZ);
            glRotatef(180, 0.0, 1.0, 0.0);
            createSeat();
            glPopMatrix();
            seatX += 4;
        }
        seatX = -10;
        seatZ += 6;
    }

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