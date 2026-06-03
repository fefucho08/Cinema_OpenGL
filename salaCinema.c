// Felipe Ferreira Moreira 237124
// Juliana da Costa Silva 241078

#include <GL/freeglut.h>
#include <stdbool.h>
#include <stdio.h>
#include "image.h"
#include "models.h"


#define MOVIE_TEXTURE "shrek.sgi"

static float fovAngle = 40.0f; // 80
static float fAspect = 1.0f;
static int rot = 180; // 0
static float posX = 0.0;
static float posZ = 10.0; // 0
static float posY = 0.0;
bool screenOn = false;
bool eating = false;
bool drinking = false;
bool animatingCamera = false;

float lightTransition = 0.0f;
bool lightTransitioning = false;

typedef enum {
    POPCORN,
    SODA,
    FREE
} seatState;

seatState seatOccupied[4][6] = {
    {FREE, SODA, FREE, FREE, FREE, POPCORN},
    {POPCORN, FREE, POPCORN, FREE, POPCORN, FREE},
    {SODA, FREE, POPCORN, POPCORN, FREE, SODA},
    {FREE, SODA, SODA, FREE, POPCORN, SODA},
};

GLuint texture_screen;

void initLights() {
    GLfloat light_color[]        = { 1.0, 1.0, 1.0, 1.0};
    GLfloat light_color_amb[]    = { 0.2, 0.2, 0.2, 1.0};

    // LUZES SEM FILME
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_color_amb);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_color_amb);

    // LUZES COM FILME

    // feixe do projetor
    GLfloat proj_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat proj_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat proj_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

    glLightfv(GL_LIGHT2, GL_DIFFUSE, proj_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, proj_specular);
    glLightfv(GL_LIGHT2, GL_AMBIENT, proj_ambient);
    
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 26.0);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.0);

    // luzes escada
    GLfloat step_color[] = { 0.0, 0.0, 1.0, 1.0};
    GLfloat step_color_amb[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT3, GL_DIFFUSE, step_color);
    glLightfv(GL_LIGHT3, GL_SPECULAR, step_color);
    glLightfv(GL_LIGHT3, GL_AMBIENT, step_color_amb);

    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.4);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.08);

    glLightfv(GL_LIGHT4, GL_DIFFUSE, step_color);
    glLightfv(GL_LIGHT4, GL_SPECULAR, step_color);
    glLightfv(GL_LIGHT4, GL_AMBIENT, step_color_amb);

    glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.4);
    glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.08);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
}

void animateLights(int value) {
    float target = screenOn ? 1.0f : 0.0f;
    float step = 0.02f;

    if(lightTransition < target) {
        lightTransition += step;
        if(lightTransition >= target) {
            lightTransition = target;
            lightTransitioning = false;
        }
    } else if(lightTransition > target) {
        lightTransition -= step;
        if(lightTransition <= target) {
            lightTransition = target;
            lightTransitioning = false;
        }
    } else {
        lightTransitioning = false;
    }

    glutPostRedisplay();
    if(lightTransitioning) {
        glutTimerFunc(16, animateLights, 0);
    }
}

void displayLights() {
    float roomFactor = 1.0f - lightTransition;
    float movieFactor = lightTransition;

    GLfloat light_color[] = { roomFactor, roomFactor, roomFactor, 1.0 };
    GLfloat light_color_amb[] = { 0.2f * roomFactor, 0.2f * roomFactor, 0.2f * roomFactor, 1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_color_amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_color_amb);

    GLfloat ligh1_position[] = { 0.0, 19.0, 16.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, ligh1_position);

    GLfloat light2_position[] = { 0.0, 19.0, -16.0, 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, light2_position);

    GLfloat proj_diffuse[] = { movieFactor, movieFactor, movieFactor, 1.0 };
    GLfloat proj_ambient[] = { 0.2f * movieFactor, 0.2f * movieFactor, 0.2f * movieFactor, 1.0 };
    glLightfv(GL_LIGHT2, GL_DIFFUSE, proj_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, proj_diffuse);
    glLightfv(GL_LIGHT2, GL_AMBIENT, proj_ambient);

    GLfloat proj_pos[] = { 0.0, 20, 12.0, 1.0 };
    glLightfv(GL_LIGHT2, GL_POSITION, proj_pos);
    GLfloat proj_dir[] = { 0.0, -0.315, -0.949 };
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, proj_dir);

    GLfloat step_color[] = { 0.0, 0.0, movieFactor, 1.0 };
    glLightfv(GL_LIGHT3, GL_DIFFUSE, step_color);
    glLightfv(GL_LIGHT3, GL_SPECULAR, step_color);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, step_color);
    glLightfv(GL_LIGHT4, GL_SPECULAR, step_color);

    GLfloat step1_position[] = { -14.0, 1.0, -4.0, 1.0};
    glLightfv(GL_LIGHT3, GL_POSITION, step1_position);

    GLfloat step2_position[] = { 14.0, 1.0, -4.0, 1.0};
    glLightfv(GL_LIGHT4, GL_POSITION, step2_position);
}


void setCameraValues() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovAngle, fAspect, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0 + posX, 12.0 + posY, 0.0 + posZ, 0.0 + posX, 12.0 + posY, -1.0 + posZ, 0.0, 1.0, 0.0);
}

void animateCamera(int value) {
    if(animatingCamera) {
        if(rot >= 0) rot -= 1;
        if(fovAngle < 80.0) fovAngle += 0.5;
        if(posZ >= 0) posZ -= 0.2;

        if(rot < 0) {
            rot = 0;
        }
        if(fovAngle >= 80.0) {
            fovAngle = 80.0;
        }
        if(posZ < 0.0) {
            posZ = 0.0;
        }

        if(rot == 0 && fovAngle == 80.0 && posZ == 0.0) {
            animatingCamera = false;
            screenOn = !screenOn;
            
            if(!lightTransitioning) {
                lightTransitioning = true;
                glutTimerFunc(16, animateLights, 0);
            }
        }

        setCameraValues();
        glutPostRedisplay();
        glutTimerFunc(16, animateCamera, 1);
    }
} 

void display() {

    /* rotacao da cena*/
    glPushMatrix();
    glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    displayLights();

    createRoom();

    float seatX = -10;
    float seatZ = 0;
    float seatY = 2.4;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 6; j++) {
            glPushMatrix();
            glTranslatef(seatX, 0.3 + seatY, seatZ);
            glRotatef(180, 0.0, 1.0, 0.0);
            if(seatOccupied[i][j] == POPCORN) {
                createPopcornPerson();
            } else if(seatOccupied[i][j] == SODA) {
                createSodaPerson();
            }
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
            if(!lightTransitioning) {
                lightTransitioning = true;
                glutTimerFunc(16, animateLights, 0);
            }
            break;
        case 'p':
            eating = !eating;
            if(eating) {
                glutTimerFunc(16, animatePopcornPerson, 1);
            }
            break;
        case 'S':
            drinking = !drinking;
            if(drinking) {
                glutTimerFunc(16, animateSodaPerson, 1);
            }
            break;
        case 'c':
            animatingCamera = !animatingCamera;
            fovAngle = 40.0f;
            rot = 180;
            posX = 0.0;
            posY = 0.0;
            posZ = 10.0;
            
            if(animatingCamera){
                glutTimerFunc(16, animateCamera, 1);
            }

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
    glEnable(GL_LIGHTING);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    initLights();

    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
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