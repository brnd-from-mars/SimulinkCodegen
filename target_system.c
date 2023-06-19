/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: target_system.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 19-Jun-2023 11:30:08
 */

/* Include Files */
#include <stdbool.h>
#include "target_system.h"

/* Variable Definitions */
static double yn1;

static double xn1;

bool isInitialized_target_system = false;

/* Function Definitions */
/*
 * Arguments    : double u
 * Return Type  : double
 */
double target_system(double u)
{
    double y;
    if (!isInitialized_target_system) {
        target_system_initialize();
    }
    y = yn1 + 0.099999999999999992 * xn1;
    xn1 += 0.099999999999999992 * ((2.0 * u - yn1) - 0.4 * xn1);
    yn1 = y;
    return y;
}

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void target_system_initialize(void)
{
    target_system_init();
    isInitialized_target_system = true;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void target_system_init(void)
{
    yn1 = 0.0;
    xn1 = 0.0;
}

/*
 * File trailer for target_system.c
 *
 * [EOF]
 */
