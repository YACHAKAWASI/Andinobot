
#ifndef __TB6612FNG_
#define __TB6612FNG_

#include "DEV_Config.h"


//GPIO config
#define PWMA        PCA_CHANNEL_0
#define AIN1        PCA_CHANNEL_1
#define AIN2        PCA_CHANNEL_2
#define PWMB        PCA_CHANNEL_5
#define BIN1        PCA_CHANNEL_3
#define BIN2        PCA_CHANNEL_4

#define MOTORA       0
#define MOTORB       1

typedef enum {
    BACKWARD = 0,
    FORWARD,
} DIR;

void Motor_Init(void);
void Motor_Run(UBYTE motor, DIR dir, UWORD speed);
void Motor_Stop(UBYTE motor);
UBYTE Motor_Direction(UBYTE motor);

#endif