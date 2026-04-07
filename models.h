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

void createStepLights() {
    float height = 1.2;
    float posZ = -13.0;

    for (int i = 0; i < 5; i++) {
        float posX = -13.5;
        for (int j = 0; j < 2; j++) {
            glColor3f(0.5, 0.5, 1.0);
            glPushMatrix();
                glTranslatef(posX, height + 0.3, posZ + 2.9);
                glScalef(1.8, 0.25, 0.25);
                glutSolidCube(1.0);
            glPopMatrix();
            posX += 27.0;
        }

        posZ += 6.0;
        height += 1.2;
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

//CAIXA DE SOM
void createSpeaker(float xSide) {
    // suporte
    glColor3f(0.35, 0.35, 0.35);
    glPushMatrix();
        glTranslatef(xSide * 15.64, 0.0, 0.0);
        glScalef(0.12, 1.0, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    // haste horizontal
    glColor3f(0.45, 0.45, 0.45);
    glPushMatrix();
        glTranslatef(xSide * 15.1, 0.0, 0.0);
        glScalef(1.7, 0.12, 0.12);
        glutSolidCube(1.0);
    glPopMatrix();

    // corpo da caixa
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
        glTranslatef(xSide * 14.5, 0.0, 0.0);
        glScalef(1.0, 1.8, 1.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // grade frontal
    glColor3f(0.22, 0.22, 0.22);
    glPushMatrix();
        glTranslatef(xSide * 13.98, 0.0, 0.0);
        glScalef(0.06, 1.6, 0.95);
        glutSolidCube(1.0);
    glPopMatrix();
}

void createDoor() {
    
    float dx = 15.4;   
    float dy = 5.5;    // metade da altura 
    float dz = -14.0;   
    float fw = 2.6;    
    float gap = 0.10;   

    // largura total do batente lateral 
    float bw = 0.55;
    float bt = 0.20;

   
    glColor3f(0.82, 0.82, 0.82);

    // topo
    glPushMatrix();
        glTranslatef(dx, dy * 2.0 + bw * 0.5, dz);
        glScalef(bt, bw, fw * 2.0 + gap + bw * 2.0);
        glutSolidCube(1.0);
    glPopMatrix();

    // montante lateral z-
    glPushMatrix();
        glTranslatef(dx, dy, dz - fw - gap * 0.5 - bw * 0.5);
        glScalef(bt, dy * 2.0, bw);
        glutSolidCube(1.0);
    glPopMatrix();

    // montante lateral z+
    glPushMatrix();
        glTranslatef(dx, dy, dz + fw + gap * 0.5 + bw * 0.5);
        glScalef(bt, dy * 2.0, bw);
        glutSolidCube(1.0);
    glPopMatrix();

    // espaço do meio
    glColor3f(0.15, 0.15, 0.15);
    glPushMatrix();
        glTranslatef(dx, dy, dz);
        glScalef(bt, dy * 2.0, gap);
        glutSolidCube(1.0);
    glPopMatrix();

    // === FOLHA ESQUERDA — cinza liso, sem paineis ===
    glColor3f(0.78, 0.78, 0.78);
    glPushMatrix();
        glTranslatef(dx, dy, dz - fw * 0.5 - gap * 0.5f);
        glScalef(bt * 0.8, dy * 2.0, fw);
        glutSolidCube(1.0);
    glPopMatrix();

    // === FOLHA DIREITA — cinza liso, sem paineis ===
    glPushMatrix();
        glTranslatef(dx, dy, dz + fw * 0.5 + gap * 0.5);
        glScalef(bt * 0.8, dy * 2.0, fw);
        glutSolidCube(1.0);
    glPopMatrix();

    // === SOLEIRA (faixa escura na base) ===
    glColor3f(0.35, 0.35, 0.35);
    glPushMatrix();
        glTranslatef(dx, 0.15, dz);
        glScalef(bt, 0.30, fw * 2.0 + gap);
        glutSolidCube(1.0);
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

    // PAREDE LATERAL DIREITA
    glPushMatrix();
    glTranslatef(15.7, 10.3, 0.0);
    glScalef(0.6, 20.0, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // PAREDE TELA
    glPushMatrix();
    glTranslatef(0.3, 10.3, -20);
    glScalef(31.4, 20.0, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // PAREDE FUNDO
    glPushMatrix();
    glTranslatef(0.3, 10.3, 20);
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