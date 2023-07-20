/*
 * PostProcessing.c
 *
 * Code generation for model "PostProcessing".
 *
 * Model version              : 8.44
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Jul 20 16:11:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "PostProcessing.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static void MovingRMS_Init(DW_MovingRMS *localDW);
static void MovingRMS_Start(DW_MovingRMS *localDW);
static void MovingRMS(real_T rtu_0, DW_MovingRMS *localDW);

/* Forward declaration for local functions */
static void SystemCore_setup(dsp_simulink_MovingRMS *obj);
static void SystemCore_setup(dsp_simulink_MovingRMS *obj)
{
  boolean_T flag;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  flag = (obj->_pobj0.isInitialized == 1);
  if (flag) {
    obj->_pobj0.TunablePropsChanged = true;
  }

  obj->_pobj0.ForgettingFactor = 1.0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* System initialize for atomic system: */
static void MovingRMS_Init(DW_MovingRMS *localDW)
{
  g_dsp_internal_ExponentialMovin *obj;

  /* InitializeConditions for MATLABSystem: '<S3>/Moving RMS' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S3>/Moving RMS' */
}

/* Start for atomic system: */
static void MovingRMS_Start(DW_MovingRMS *localDW)
{
  /* Start for MATLABSystem: '<S3>/Moving RMS' */
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.FrameLength = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->bitsForTID0.objisempty = true;
  SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
static void MovingRMS(real_T rtu_0, DW_MovingRMS *localDW)
{
  g_dsp_internal_ExponentialMovin *obj;
  real_T a;
  real_T lambda;
  real_T pmLocal;
  real_T pwLocal;

  /* MATLABSystem: '<S3>/Moving RMS' */
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  a = fabs(rtu_0);
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  pwLocal = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  a = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal * (a * a);
  obj->pwN = lambda * pwLocal + 1.0;
  obj->pmN = a;

  /* MATLABSystem: '<S3>/Moving RMS' */
  localDW->MovingRMS_i = sqrt(a);
}

/* Model step function */
void PostProcessing_step(void)
{
  /* local block i/o variables */
  real_T rtb_Divide5;
  real_T rtb_Divide6;
  real_T rtb_Divide7;

  /* Product: '<S4>/Divide' incorporates:
   *  Inport: '<Root>/CalI1'
   *  Inport: '<Root>/I1'
   */
  rtDW.Divide = rtU.I1 / rtU.CalI1;
  MovingRMS(rtDW.Divide, &rtDW.MovingRMS_p);

  /* Product: '<S4>/Divide1' incorporates:
   *  Inport: '<Root>/CalI2'
   *  Inport: '<Root>/I2'
   */
  rtDW.Divide1 = rtU.I2 / rtU.CalI2;
  MovingRMS(rtDW.Divide1, &rtDW.MovingRMS1);

  /* Product: '<S4>/Divide2' incorporates:
   *  Inport: '<Root>/CalI3'
   *  Inport: '<Root>/I3'
   */
  rtDW.Divide2 = rtU.I3 / rtU.CalI3;
  MovingRMS(rtDW.Divide2, &rtDW.MovingRMS2);

  /* Product: '<S4>/Divide3' incorporates:
   *  Inport: '<Root>/CalI4'
   *  Inport: '<Root>/I4'
   */
  rtDW.Divide3 = rtU.I4 / rtU.CalI4;
  MovingRMS(rtDW.Divide3, &rtDW.MovingRMS3);

  /* Product: '<S4>/Divide4' incorporates:
   *  Inport: '<Root>/CalV1'
   *  Inport: '<Root>/V1'
   *  Inport: '<Root>/V2'
   *  Sum: '<S2>/Minus'
   */
  rtDW.Divide4 = (rtU.V1 - rtU.V2) / rtU.CalV1;
  MovingRMS(rtDW.Divide4, &rtDW.MovingRMS4);

  /* Product: '<S4>/Divide5' incorporates:
   *  Inport: '<Root>/CalV2'
   *  Inport: '<Root>/V2'
   *  Inport: '<Root>/V3'
   *  Sum: '<S2>/Minus1'
   */
  rtb_Divide5 = (rtU.V2 - rtU.V3) / rtU.CalV2;
  MovingRMS(rtb_Divide5, &rtDW.MovingRMS5);

  /* Product: '<S4>/Divide6' incorporates:
   *  Inport: '<Root>/CalV3'
   *  Inport: '<Root>/V1'
   *  Inport: '<Root>/V3'
   *  Sum: '<S2>/Minus2'
   */
  rtb_Divide6 = (rtU.V1 - rtU.V3) / rtU.CalV3;
  MovingRMS(rtb_Divide6, &rtDW.MovingRMS6);

  /* Product: '<S4>/Divide7' incorporates:
   *  Inport: '<Root>/CalV4'
   *  Inport: '<Root>/V4'
   */
  rtb_Divide7 = rtU.V4 / rtU.CalV4;
  MovingRMS(rtb_Divide7, &rtDW.MovingRMS7);

  /* Outport: '<Root>/RMSDisplay' */
  rtY.RMSDisplay[0] = rtDW.MovingRMS_p.MovingRMS_i;
  rtY.RMSDisplay[1] = rtDW.MovingRMS1.MovingRMS_i;
  rtY.RMSDisplay[2] = rtDW.MovingRMS2.MovingRMS_i;
  rtY.RMSDisplay[3] = rtDW.MovingRMS3.MovingRMS_i;
  rtY.RMSDisplay[4] = rtDW.MovingRMS4.MovingRMS_i;
  rtY.RMSDisplay[5] = rtDW.MovingRMS5.MovingRMS_i;
  rtY.RMSDisplay[6] = rtDW.MovingRMS6.MovingRMS_i;
  rtY.RMSDisplay[7] = rtDW.MovingRMS7.MovingRMS_i;
}

/* Model initialize function */
void PostProcessing_initialize(void)
{
  MovingRMS_Start(&rtDW.MovingRMS_p);
  MovingRMS_Start(&rtDW.MovingRMS1);
  MovingRMS_Start(&rtDW.MovingRMS2);
  MovingRMS_Start(&rtDW.MovingRMS3);
  MovingRMS_Start(&rtDW.MovingRMS4);
  MovingRMS_Start(&rtDW.MovingRMS5);
  MovingRMS_Start(&rtDW.MovingRMS6);
  MovingRMS_Start(&rtDW.MovingRMS7);

  /* ConstCode for Outport: '<Root>/PowerDisplay' */
  rtY.PowerDisplay[0] = 0.0;
  rtY.PowerDisplay[1] = 0.0;
  rtY.PowerDisplay[2] = 0.0;
  rtY.PowerDisplay[3] = 0.0;
  rtY.PowerDisplay[4] = 0.0;
  rtY.PowerDisplay[5] = 0.0;
  MovingRMS_Init(&rtDW.MovingRMS_p);
  MovingRMS_Init(&rtDW.MovingRMS1);
  MovingRMS_Init(&rtDW.MovingRMS2);
  MovingRMS_Init(&rtDW.MovingRMS3);
  MovingRMS_Init(&rtDW.MovingRMS4);
  MovingRMS_Init(&rtDW.MovingRMS5);
  MovingRMS_Init(&rtDW.MovingRMS6);
  MovingRMS_Init(&rtDW.MovingRMS7);
}
