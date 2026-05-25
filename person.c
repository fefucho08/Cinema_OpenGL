// Felipe Ferreira Moreira 237124
// Juliana da Costa Silva 241078

#include <GL/freeglut.h>
#include <stdbool.h>
#include <stdio.h>

static float fovAngle = 80.0f;
static float fAspect = 1.0f;
static int rot = 0;
static float posX = 0.0;
static float posZ = 0.0;
static float posY = 0.0;
static bool eating = false;

void createSeat() {
        glColor3f(0.37, 0.07, 0.07);
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
        glPushMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glScalef(2.5, 1, 2.0);
            glutSolidCube(1.0);
        glPopMatrix();

        // ENCOSTO
        glPushMatrix();
            glTranslatef(0.0, 0.0, -1.0);

            glPushMatrix();
                glTranslatef(0.0, 1.75, 0.0);
                glScalef(2.5, 3.5, 1.0);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, 2.0, 0.0);
                glScalef(1.5, 4, 1.0);
                glutSolidCube(1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.75, 3.5, -0.5);
                glutSolidCylinder(0.5, 1.0, 10.0, 1.5);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.75, 3.5, -0.5);
                glutSolidCylinder(0.5, 1.0, 10.0, 1.5);
            glPopMatrix();
        glPopMatrix();
}

void createPerson() {
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 2.25, 0.0);
    // tronco
    glPushMatrix();
        glScalef(1.5, 2.5, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();
    
    //cabeca
    glColor3f(0.89, 0.69, 0.52);
    glPushMatrix();
        glTranslatef(0.0, 2.10, 0.0);
        glutSolidSphere(1.0, 10.0, 10.0);
    glPopMatrix();

    //braco direito
    glPushMatrix();
        glTranslatef(-0.90, 0.5, 0.0);
        if(!eating) glRotatef(10, 1.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        //biceps
        glPushMatrix();
            glutSolidSphere(0.25, 10.0, 10.0);
            glutSolidCylinder(0.25, 1.0, 10.0, 1.0);
        glPopMatrix();

        glColor3f(0.89, 0.69, 0.52);
        // articulacao
        glPushMatrix();
            glTranslatef(0.0, 0.0, 1.0);
            glutSolidSphere(0.25, 10.0, 10.0);
        glPopMatrix();

        //antebraco
        glPushMatrix();
            if(eating) glRotatef(45.0, 0.0, 0.0, 1.0);
            glPushMatrix();
                glTranslatef(0.0, 0.0, 1.0);
                glRotatef(90.0, 0.0, 1.0, 0.0);
                glutSolidCylinder(0.25, 1.0, 10.0, 1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(1.0, 0.0, 1.0);
                glutSolidSphere(0.25, 10.0, 10.0);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    //braco esquerdo
    glPushMatrix();
        glTranslatef(0.90, 0.5, 0.0);
        glRotatef(-10, 1.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        //biceps
        glPushMatrix();
            glRotatef(90, 1.0, 0.0, 0.0);
            glutSolidSphere(0.25, 10.0, 10.0);
            glutSolidCylinder(0.25, 1.0, 10.0, 1.0);
        glPopMatrix();

        glColor3f(0.89, 0.69, 0.52);
        // articulacao
        glPushMatrix();
            glTranslatef(0.0, -1.0, 0.0);
            glutSolidSphere(0.25, 10.0, 10.0);
        glPopMatrix();

        //antebraco
        glPushMatrix();
            glRotatef(-15.0, 0.0, 1.0, 0.0);
            glPushMatrix();
                glTranslatef(0.0, -1.0, 0.0);
                glutSolidCylinder(0.25, 1.0, 10.0, 1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, -1.0, 1.0);
                glutSolidSphere(0.25, 10.0, 10.0);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    // perna direita
    glPushMatrix();
        glTranslatef(-0.375, -0.95, 0.5);
        glColor3f(1.0, 0.0, 0.0);
        // coxa
        glPushMatrix();
            glutSolidCylinder(0.375, 1.0, 10.0, 1.0);
        glPopMatrix();

        // joelho
        glPushMatrix();
        glTranslatef(0.0, 0.0, 1.0);
        glutSolidSphere(0.375, 10.0, 10.0);
        glPopMatrix();
        
        glColor3f(0.89, 0.69, 0.52);
        //panturrilha
        glPushMatrix();
            glTranslatef(0.0, 0.0, 1.0);
            glRotatef(90, 1.0, 0.0, 0.0);
            glutSolidCylinder(0.375, 1.0, 10.0, 1.0);
        glPopMatrix();

        glColor3f(0.0, 0.0, 0.0);
        // pé
        glPushMatrix();
            glTranslatef(0.0, -1.0, 1.0);
            glutSolidSphere(0.375, 10.0, 10.0);
        glPopMatrix();
    glPopMatrix();
    
    // perna esquerda
    glPushMatrix();
        glTranslatef(0.375, -0.95, 0.5);
        glColor3f(1.0, 0.0, 0.0);
        // coxa
        glPushMatrix();
            glutSolidCylinder(0.375, 1.0, 10.0, 1.0);
        glPopMatrix();

        // joelho
        glPushMatrix();
        glTranslatef(0.0, 0.0, 1.0);
        glutSolidSphere(0.375, 10.0, 10.0);
        glPopMatrix();
        
        glColor3f(0.89, 0.69, 0.52);
        //panturrilha
        glPushMatrix();
            glTranslatef(0.0, 0.0, 1.0);
            glRotatef(90, 1.0, 0.0, 0.0);
            glutSolidCylinder(0.375, 1.0, 10.0, 1.0);
        glPopMatrix();
        
        glColor3f(0.0, 0.0, 0.0);
        // pé
        glPushMatrix();
            glTranslatef(0.0, -1.0, 1.0);
            glutSolidSphere(0.375, 10.0, 10.0);
        glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void setCameraValues() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovAngle, fAspect, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0 + posX, 0.0 + posY, 10.0 + posZ, 0.0 + posX, 0.0 + posY, -1.0 + posZ, 0.0, 1.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setCameraValues();

    // Aplicar rotação
    glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

    // Cadeira com cor vermelha
    glColor3f(0.8, 0.2, 0.2);
    createSeat();

    // Pessoa com cor azul
    glColor3f(0.2, 0.2, 0.8);
    createPerson();

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
        case 'p':
            eating = !eating;
            break;
        case 27:
            exit(0);
            break;
    }
    setCameraValues();
    glutPostRedisplay();
}


void setupLighting() {
    // Definir propriedades de iluminação global
    GLfloat luzAmbiente[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat luzDifusa[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat luzEspecular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat posicaoLuz[] = {5.0, 8.0, 10.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    // Configurar material padrão
    GLfloat materiaAmbiente[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat materiaDifusa[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat materiaEspecular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat brilho = 32.0;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materiaAmbiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materiaDifusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materiaEspecular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brilho);
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable(GL_NORMALIZE);
    setupLighting();
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