#ifndef MODELS_H
#define MODELS_H

#include <GL/freeglut.h>
#include <stdbool.h>

void createLevels();
void createStepLights();
void createSeat();
void createSpeaker(float xSide);
void createDoor();
void createRoom();
void createLights();
void createProjector();
void createPerson();
void createPopcornBucket();
void animatePerson(int value);

#endif