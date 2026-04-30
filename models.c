// Felipe Ferreira Moreira 237124
// Juliana da Costa Silva 241078

#include "models.h"
#include <stdbool.h>

extern GLuint texture_screen;
extern bool screenOn;

void createLevels(){
    GLfloat color_diffuse[]    = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat color_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat color_shininess[]    = { 50.0 };
    float height = 1.2;
    float posZ = -7.0;
    for(int i = 0; i < 5; i++) {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, color_shininess);

        glPushMatrix();
        glTranslatef(0.0, height / 2.0 + 0.3, posZ);
        glScalef(30.8, height, 6.0);
        glutSolidCube(1.0);
        glPopMatrix();
        posZ += 6;
        height += 1.2;
    }
}

void createStepLights() {
    float height = 1.2;
    float posZ = -13.0;

    GLfloat color_diffuse[]    = { 0.5, 0.5, 1.0, 1.0 };
    GLfloat color_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat color_shininess[]    = { 50.0 };
    GLfloat color_emission[]    = { 0.5, 0.5, 1.0, 1.0 };

    for (int i = 0; i < 5; i++) {
        float posX = -13.5;
        for (int j = 0; j < 2; j++) {
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color_diffuse);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, color_shininess);
            
            if(screenOn)
                glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color_emission);

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

    GLfloat no_emission[] = { 0.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_emission);
}

void createSeat() {
        GLfloat seat_diffuse[]    = { 0.37, 0.07, 0.07, 1.0 };
        GLfloat seat_specular[] = { 0.2, 0.2, 0.2, 0.2 };
        GLfloat seat_shininess[]    = { 50.0 };

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, seat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, seat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, seat_shininess);
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


        GLfloat arm_diffuse[]    = { 0.37, 0.07, 0.07, 1.0 };
        GLfloat arm_specular[] = { 0.2, 0.2, 0.2, 0.2 };
        GLfloat arm_shininess[]    = { 50.0 };

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, arm_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, arm_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, arm_shininess);
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
    GLfloat support_diffuse[]    = { 0.35, 0.35, 0.35, 1.0 };
    GLfloat support_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat support_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, support_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, support_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, support_shininess);

    glPushMatrix();
        glTranslatef(xSide * 15.64, 0.0, 0.0);
        glScalef(0.12, 1.0, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    
    // haste horizontal
    GLfloat rod_diffuse[]    = { 0.45, 0.45, 0.45, 1.0 };
    GLfloat rod_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat rod_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rod_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, rod_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, rod_shininess);

    glPushMatrix();
        glTranslatef(xSide * 15.1, 0.0, 0.0);
        glScalef(1.7, 0.12, 0.12);
        glutSolidCube(1.0);
    glPopMatrix();

    // corpo da caixa
    GLfloat box_diffuse[]    = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat box_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat box_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, box_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, box_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, box_shininess);

    glPushMatrix();
        glTranslatef(xSide * 14.5, 0.0, 0.0);
        glScalef(1.0, 1.8, 1.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // grade frontal
    GLfloat front_diffuse[]    = { 0.22, 0.22, 0.22, 1.0 };
    GLfloat front_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat front_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, front_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, front_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, front_shininess);

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

    
    // topo
    GLfloat top_diffuse[]    = { 0.82, 0.82, 0.82, 1.0 };
    GLfloat top_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat top_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, top_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, top_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, top_shininess);

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
    GLfloat middle_diffuse[]    = { 0.15, 0.15, 0.15, 1.0 };
    GLfloat middle_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat middle_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, middle_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, middle_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, middle_shininess);

    glPushMatrix();
        glTranslatef(dx, dy, dz);
        glScalef(bt, dy * 2.0, gap);
        glutSolidCube(1.0);
    glPopMatrix();

    // === FOLHA ESQUERDA — cinza liso, sem paineis ===
    GLfloat gray_diffuse[]    = { 0.78, 0.78, 0.78, 1.0 };
    GLfloat gray_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat gray_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gray_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gray_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, gray_shininess);

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
    GLfloat bottom_diffuse[]    = { 0.35, 0.35, 0.35, 1.0 };
    GLfloat bottom_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat bottom_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, bottom_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, bottom_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, bottom_shininess);

    glPushMatrix();
        glTranslatef(dx, 0.15, dz);
        glScalef(bt, 0.30, fw * 2.0 + gap);
        glutSolidCube(1.0);
    glPopMatrix();
}

void createRoom() {
    // CHAO
    GLfloat floor_diffuse[]    = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat floor_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat floor_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, floor_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, floor_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, floor_shininess);

    glPushMatrix();
    glScalef(32.0, 0.6, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // TETO
    GLfloat ceiling_diffuse[]    = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat ceiling_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat ceiling_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ceiling_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ceiling_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, ceiling_shininess);

    glPushMatrix();
    glTranslatef(0.0, 20.6, 0.0);
    glScalef(32.0, 0.6, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    
    // PAREDE LATERAL ESQUERDA
    GLfloat wall_diffuse[]    = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat wall_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat wall_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wall_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wall_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, wall_shininess);

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
    GLfloat black_diffuse[]    = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat black_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat black_shininess[]    = { 50.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, black_shininess);

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

    if(screenOn) {
        GLfloat planotext[4][2]={
            {0,0},
            {+1,0},
            {+1,+1},
            {0,+1}
        };
    
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBindTexture(GL_TEXTURE_2D, texture_screen);
    
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2fv(planotext[0]);  glVertex3f(-11.7, 4.3,-0.2);
        glTexCoord2fv(planotext[1]);  glVertex3f(11.7,4.3,-0.2);
        glTexCoord2fv(planotext[2]);  glVertex3f(11.7,16,-0.2);
        glTexCoord2fv(planotext[3]);  glVertex3f(-11.7,16,-0.2);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    } else {
        GLfloat screen_diffuse[]    = { 0.9, 0.9, 0.9, 1.0 };
        GLfloat screen_specular[] = { 0.2, 0.2, 0.2, 0.2 };
        GLfloat screen_shininess[]    = { 50.0 };

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, screen_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, screen_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, screen_shininess);
        
        glPushMatrix();
        glTranslatef(0.0, 10.15, 0.0);
        glScalef(23.4, 11.4, 0.5);
        glutSolidCube(1.0);
        glPopMatrix();
    }
    

    glPopMatrix();
}

void createLights() {
    glPushMatrix();
    glTranslatef(0.0, 20.0, 0.0);

    GLfloat white_diffuse[]    = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat white_specular[] = { 0.2, 0.2, 0.2, 0.2 };
    GLfloat white_shininess[]    = { 50.0 };
    GLfloat white_emission[] = { 0.7, 0.7, 0.7, 1.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, white_shininess);

    if(!screenOn)
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  white_emission);

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

    GLfloat no_emission[] = { 0.0, 0.0, 0.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_emission);

    glPopMatrix();
}

void createProjector() {
    glPushMatrix();

        GLfloat rod_diffuse[]    = { 0.2, 0.2, 0.2, 1.0 };
        GLfloat rod_specular[] = { 0.2, 0.2, 0.2, 0.2 };
        GLfloat rod_shininess[]    = { 50.0 };

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rod_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, rod_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, rod_shininess);

        glPushMatrix();
            glRotatef(90, 1.0, 0.0, 0.0);
            glutSolidCylinder(0.5, 2.0, 10.0, 1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0, -2.25, 0.0);
        glRotatef(-10.0, 1.0, 0.0, 0.0);

            glPushMatrix();
                GLfloat box_diffuse[]    = { 0.6, 0.6, 0.6, 1.0 };
                GLfloat box_specular[] = { 0.2, 0.2, 0.2, 0.2 };
                GLfloat box_shininess[]    = { 50.0 };

                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, box_diffuse);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, box_specular);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, box_shininess);

                glScalef(2.5, 1.5, 3.0);
                glutSolidCube(1.0);
            glPopMatrix();
            

            
            glPushMatrix();                
                glTranslatef(0.0, 0.0, -1.6);
                
                GLfloat frame_diffuse[]    = { 0.1, 0.1, 0.1, 1.0 };
                GLfloat frame_specular[] = { 0.2, 0.2, 0.2, 0.2 };
                GLfloat frame_shininess[]    = { 50.0 };

                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, frame_diffuse);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, frame_specular);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, frame_shininess);

                glutSolidCylinder(0.5, 0.2, 10.0, 1.0);

                GLfloat lens_diffuse[]    = { 0.9, 0.9, 0.9, 1.0 };
                GLfloat lens_specular[] = { 0.2, 0.2, 0.2, 0.2 };
                GLfloat lens_shininess[]    = { 50.0 };
                GLfloat lens_emission[] = { 0.7, 0.7, 0.7, 1.0 };

                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lens_diffuse);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, lens_specular);
                glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, lens_shininess);
                if(screenOn)
                    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  lens_emission);

                glTranslatef(0.0, 0.0, -0.1);
                glutSolidCylinder(0.3, 0.2, 10.0, 1.0);
            glPopMatrix();

        glPopMatrix();

        GLfloat no_emission[] = { 0.0, 0.0, 0.0, 1.0 };
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_emission);

    glPopMatrix();
}