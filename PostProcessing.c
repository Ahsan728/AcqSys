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
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void PostProcessing_step(void)
{
  /* S-Function (sdspstatfcns): '<S1>/RMS' incorporates:
   *  Inport: '<Root>/Samples_32b'
   */
  rtDW.RMS_Iteration++;
  if (rtDW.RMS_Iteration > 1U) {
    rtDW.RMS_SqData += rtU.Samples_32b * rtU.Samples_32b;

    /* Outport: '<Root>/Out_RMS' incorporates:
     *  Inport: '<Root>/Samples_32b'
     */
    rtY.Out_RMS = sqrt(rtDW.RMS_SqData / (real_T)rtDW.RMS_Iteration);
  } else {
    if (rtDW.RMS_Iteration == 0U) {
      rtDW.RMS_Iteration = 1U;
    }

    rtDW.RMS_SqData = rtU.Samples_32b * rtU.Samples_32b;

    /* Outport: '<Root>/Out_RMS' incorporates:
     *  Inport: '<Root>/Samples_32b'
     */
    rtY.Out_RMS = fabs(rtU.Samples_32b);
  }

  /* End of S-Function (sdspstatfcns): '<S1>/RMS' */
}

/* Model initialize function */
void PostProcessing_initialize(void)
{
  /* (no initialization code required) */
}
