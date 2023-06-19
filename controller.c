/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: controller.c
 *
 * MATLAB Coder version            : 5.5
 * C/C++ source code generated on  : 19-Jun-2023 08:54:25
 */

/* Include Files */
#include <stdbool.h>
#include "controller.h"

/* Variable Definitions */
static double e_prev;

static double integral;

bool isInitialized_controller = false;

/* Function Definitions */
/*
 * Arguments    : double e
 * Return Type  : double
 */
double controller(double e)
{
    double derivative;
    if (!isInitialized_controller) {
        controller_initialize();
    }
    integral += e;
    derivative = e - e_prev;
    e_prev = e;
    return (0.8 * e + integral * 0.01 * 9.0) + derivative * 100.0 * 0.15;
}

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void controller_initialize(void)
{
    controller_init();
    isInitialized_controller = true;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void controller_init(void)
{
    e_prev = 0.0;
    integral = 0.0;
}

/*
 * File trailer for controller.c
 *
 * [EOF]
 */
