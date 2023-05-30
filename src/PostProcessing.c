/*
 * PostProcessing.c
 *
 * Code generation for model "PostProcessing".
 *
 * Model version              : 8.6
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri May 26 10:37:26 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "PostProcessing.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_; //declares a static variable "rtM_" of type "RT_MODEL" and initializes it with an empty structure
RT_MODEL *const rtM = &rtM_; // a constant pointer "rtM" that points to "rtM_".

/* Model step function */
void PostProcessing_step(void)
{
  /* S-Function (sdspstatfcns): '<S1>/RMS' incorporates:
   *  Inport: '<Root>/Samples_32b'
   */
  rtDW.RMS_Iteration++; //increments the value of the variable rtDW.RMS_Iteration by 1
  if (rtDW.RMS_Iteration > 1U) {
    rtDW.RMS_SqData += rtU.Samples_32b * rtU.Samples_32b;
    //The value of rtU.Samples_32b is squared (rtU.Samples_32b * rtU.Samples_32b) and added to the variable rtDW.RMS_SqData.
    /* Outport: '<Root>/Out_RMS' incorporates:
     *  Inport: '<Root>/Samples_32b'
     */
    rtY.Out_RMS = sqrt(rtDW.RMS_SqData / (real_T)rtDW.RMS_Iteration);
    //The square root of the ratio between rtDW.RMS_SqData and rtDW.RMS_Iteration is calculated using the sqrt() function. 
    //The result is assigned to rtY.Out_RMS.
  } else {
    if (rtDW.RMS_Iteration == 0U) {
      rtDW.RMS_Iteration = 1U;
    }//If rtDW.RMS_Iteration is 0, it is assigned the value 1 to ensure it is at least 1
    rtDW.RMS_SqData = rtU.Samples_32b * rtU.Samples_32b;
    //The value of rtU.Samples_32b is squared, and the result is assigned to rtDW.RMS_SqData.
    /* Outport: '<Root>/Out_RMS' incorporates:
     *  Inport: '<Root>/Samples_32b'
     */
    rtY.Out_RMS = fabs(rtU.Samples_32b);
    //The absolute value of rtU.Samples_32b is calculated using the fabs() function, and the result is assigned to rtY.Out_RMS.
  }

  /* End of S-Function (sdspstatfcns): '<S1>/RMS' */
}

/* Model initialize function */
void PostProcessing_initialize(void)
{
  /* (no initialization code required) */
}
