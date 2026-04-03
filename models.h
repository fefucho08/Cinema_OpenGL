#include <GL/freeglut.h>
#include <stdbool.h>

void createLevels(){
    float grayTone = 0.1;
    float height = 1.2;
    float posZ = -7.0;                                                                                                                                       
    for(int i = 0; i < 5; i++) {
        glColor3f(grayTone, grayTone, grayTone);
        glPushMatrix();
        glTranslatef(0.0, height / 2.0 + 0.3, posZ);
        glScalef(30.8, height, 6.0);
        glutSolidCube(1.0);
        glPopMatrix();
        posZ += 6;
        height += 1.2;
        grayTone += 0.03;
    }
}

void createSeat() {
        glColor3f(0.35, 0.05, 0.05);
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

        glColor3f(0.37, 0.07, 0.07);
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

    glColor3f(0.5, 0.5, 0.5);
    // PAREDE LATERAL ESQUERDA
    glPushMatrix();
    glTranslatef(-15.7, 10.3, 0.0);
    glScalef(0.6, 20.0, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // PAREDE TELA
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

void createLights() {
    glPushMatrix();
    glTranslatef(0.0, 20.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);

    float posX = -11;
    float posZ = 15;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            glPushMatrix();
            glTranslatef(posX, 0.0, posZ);
            glRotatef(90.0, 1.0, 0.0, 0.0);
            glutSolidTorus(0.2, 1.0, 10.0, 10.0);
            glPopMatrix();
            posX += 11;
        }
        posZ -= 10;
        posX = -11;
    }

    glPopMatrix();
}

void createProjector() {
    glPushMatrix();
    
        glColor3f(0.2, 0.2, 0.2);
        glPushMatrix();
            glRotatef(90, 1.0, 0.0, 0.0);
            glutSolidCylinder(0.5, 2.0, 10.0, 1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0, -2.25, 0.0);
        glRotatef(-10.0, 1.0, 0.0, 0.0);
        
            glPushMatrix();
                glColor3f(0.6, 0.6, 0.6);
                glScalef(2.5, 1.5, 3.0);
                glutSolidCube(1.0);
            glPopMatrix();

            glColor3f(0.0, 0.0, 1.0);
            glPushMatrix();
                glTranslatef(0.0, 0.0, -1.6);
                glColor3f(0.1, 0.1, 0.1);
                glutSolidCylinder(0.5, 0.2, 10.0, 1.0);
                glColor3f(0.9, 0.9, 0.9);
                glTranslatef(0.0, 0.0, -0.1);
                glutSolidCylinder(0.3, 0.2, 10.0, 1.0);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
}