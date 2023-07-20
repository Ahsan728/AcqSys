/*
 * PostProcessing.c
 *
 * Code generation for model "PostProcessing".
 *
 * Model version              : 8.43
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Jul 19 15:12:54 2023
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

  /* InitializeConditions for MATLABSystem: '<S4>/Moving RMS' */
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S4>/Moving RMS' */
}

/* Start for atomic system: */
static void MovingRMS_Start(DW_MovingRMS *localDW)
{
  /* Start for MATLABSystem: '<S4>/Moving RMS' */
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

  /* MATLABSystem: '<S4>/Moving RMS' */
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

  /* MATLABSystem: '<S4>/Moving RMS' */
  localDW->MovingRMS_i = sqrt(a);
}

/* Model step function */
void PostProcessing_step(void)
{
  /* local block i/o variables */
  real_T rtb_Product7;
  int32_T Delay_DSTATE_tmp;
  int32_T Delay_DSTATE_tmp_0;
  int_T idxDelay;

  /* Product: '<S5>/Product' incorporates:
   *  Inport: '<Root>/CalI1'
   *  Inport: '<Root>/I1'
   */
  rtDW.Product = rtU.I1 * rtU.CalI1;
  MovingRMS(rtDW.Product, &rtDW.MovingRMS_p);

  /* Product: '<S5>/Product1' incorporates:
   *  Inport: '<Root>/CalI2'
   *  Inport: '<Root>/I2'
   */
  rtDW.Product1 = rtU.I2 * rtU.CalI2;
  MovingRMS(rtDW.Product1, &rtDW.MovingRMS1);

  /* Product: '<S5>/Product2' incorporates:
   *  Inport: '<Root>/CalI3'
   *  Inport: '<Root>/I3'
   */
  rtDW.Product2 = rtU.I3 * rtU.CalI3;
  MovingRMS(rtDW.Product2, &rtDW.MovingRMS2);

  /* Product: '<S5>/Product3' incorporates:
   *  Inport: '<Root>/CalI4'
   *  Inport: '<Root>/I4'
   */
  rtDW.Product3 = rtU.I4 * rtU.CalI4;
  MovingRMS(rtDW.Product3, &rtDW.MovingRMS3);

  /* Product: '<S5>/Product4' incorporates:
   *  Inport: '<Root>/CalV1'
   *  Inport: '<Root>/V1'
   *  Inport: '<Root>/V2'
   *  Sum: '<S2>/Minus'
   */
  rtDW.Product4 = (rtU.V1 - rtU.V2) * rtU.CalV1;
  MovingRMS(rtDW.Product4, &rtDW.MovingRMS4);

  /* Product: '<S5>/Product5' incorporates:
   *  Inport: '<Root>/CalV2'
   *  Inport: '<Root>/V2'
   *  Inport: '<Root>/V3'
   *  Sum: '<S2>/Minus1'
   */
  rtDW.Product5 = (rtU.V2 - rtU.V3) * rtU.CalV2;
  MovingRMS(rtDW.Product5, &rtDW.MovingRMS5);

  /* Product: '<S5>/Product6' incorporates:
   *  Inport: '<Root>/CalV3'
   *  Inport: '<Root>/V1'
   *  Inport: '<Root>/V3'
   *  Sum: '<S2>/Minus2'
   */
  rtDW.Product6 = (rtU.V1 - rtU.V3) * rtU.CalV3;
  MovingRMS(rtDW.Product6, &rtDW.MovingRMS6);

  /* Product: '<S5>/Product7' incorporates:
   *  Inport: '<Root>/CalV4'
   *  Inport: '<Root>/V4'
   */
  rtb_Product7 = rtU.V4 * rtU.CalV4;
  MovingRMS(rtb_Product7, &rtDW.MovingRMS7);

  /* Outport: '<Root>/RMSDisplay' */
  rtY.RMSDisplay[0] = rtDW.MovingRMS_p.MovingRMS_i;
  rtY.RMSDisplay[1] = rtDW.MovingRMS1.MovingRMS_i;
  rtY.RMSDisplay[2] = rtDW.MovingRMS2.MovingRMS_i;
  rtY.RMSDisplay[3] = rtDW.MovingRMS3.MovingRMS_i;
  rtY.RMSDisplay[4] = rtDW.MovingRMS4.MovingRMS_i;
  rtY.RMSDisplay[5] = rtDW.MovingRMS5.MovingRMS_i;
  rtY.RMSDisplay[6] = rtDW.MovingRMS6.MovingRMS_i;
  rtY.RMSDisplay[7] = rtDW.MovingRMS7.MovingRMS_i;

  /* InitialCondition: '<S14>/Initial' */
  if (rtDW.bitsForTID0.Initial_FirstOutputTime) {
    rtDW.bitsForTID0.Initial_FirstOutputTime = false;

    /* InitialCondition: '<S14>/Initial' */
    rtDW.Initial = 0.0;
  } else {
    /* InitialCondition: '<S14>/Initial' incorporates:
     *  Bias: '<S17>/Bias'
     *  Gain: '<S17>/Gain'
     *  Gain: '<S17>/Gain1'
     *  Rounding: '<S17>/Rounding Function'
     *  Sum: '<S17>/Sum1'
     */
    rtDW.Initial = rtDW.Integrator_DSTATE - floor(0.15915494309189535 *
      rtDW.Integrator_DSTATE) * 6.2831853071795862;
  }

  /* End of InitialCondition: '<S14>/Initial' */

  /* DiscreteIntegrator: '<S14>/Integrator' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S16>/Constant'
   *  Logic: '<S14>/Logical Operator'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/Compare'
   */
  if ((rtDW.Integrator_DSTATE < 0.0) || (rtDW.Integrator_DSTATE >=
       6.2831853071795862)) {
    rtDW.Integrator_DSTATE = rtDW.Initial;
  }

  /* Trigonometry: '<S9>/Trigonometric Function1' incorporates:
   *  DiscreteIntegrator: '<S14>/Integrator'
   */
  rtDW.ComplextoRealImag_o2 = sin(rtDW.Integrator_DSTATE);
  rtDW.ComplextoRealImag_o1 = cos(rtDW.Integrator_DSTATE);

  /* Product: '<S9>/Product1' */
  rtDW.Initial = rtDW.Product4 * rtDW.ComplextoRealImag_o2;
  rtDW.rtb_Product1_n_idx_1 = rtDW.Product4 * rtDW.ComplextoRealImag_o1;

  /* DiscreteIntegrator: '<S9>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S9>/Integrator' */
    rtDW.Integrator = rtDW.Integrator_DSTATE_i[0];
  } else {
    /* DiscreteIntegrator: '<S9>/Integrator' */
    rtDW.Integrator = 0.000125 * rtDW.Initial + rtDW.Integrator_DSTATE_i[0];
  }

  /* DiscreteIntegrator: '<S9>/Integrator' */
  rtDW.Integrator_idx_0 = rtDW.Integrator;

  /* UnitDelay: '<S10>/Unit Delay2' */
  rtDW.rtb_UnitDelay2_k = rtDW.UnitDelay2_DSTATE[0];

  /* Sum: '<S10>/Subtract1' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  rtDW.Initial_p = rtDW.UnitDelay1_DSTATE[0];

  /* Sum: '<S10>/Subtract3' incorporates:
   *  Sum: '<S10>/Add1'
   *  Sum: '<S10>/Subtract1'
   *  UnitDelay: '<S10>/Unit Delay2'
   */
  rtDW.Initial_p = ((rtDW.Integrator - rtDW.Initial_p) + rtDW.Initial_p) -
    rtDW.UnitDelay2_DSTATE[0];

  /* Delay: '<S10>/Delay' incorporates:
   *  UnitDelay: '<S10>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE[0] = rtDW.Delay_DSTATE[0];

  /* Gain: '<S9>/Gain' incorporates:
   *  Delay: '<S10>/Delay'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/delta''
   *  Sum: '<S10>/Add2'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S10>/Subtract2'
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S10>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[0] = ((rtDW.Integrator - ((rtDW.Delay_DSTATE[0] -
    rtDW.rtb_UnitDelay2_k) * 0.0 + rtDW.rtb_UnitDelay2_k)) + rtDW.Initial_p) *
    0.5 * 100.0;

  /* DiscreteIntegrator: '<S9>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S9>/Integrator' */
    rtDW.Integrator = rtDW.Integrator_DSTATE_i[1];
  } else {
    /* DiscreteIntegrator: '<S9>/Integrator' */
    rtDW.Integrator = 0.000125 * rtDW.rtb_Product1_n_idx_1 +
      rtDW.Integrator_DSTATE_i[1];
  }

  /* UnitDelay: '<S10>/Unit Delay2' */
  rtDW.rtb_UnitDelay2_k = rtDW.UnitDelay2_DSTATE[1];

  /* Sum: '<S10>/Subtract1' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   */
  rtDW.Initial_p = rtDW.UnitDelay1_DSTATE[1];

  /* Sum: '<S10>/Subtract3' incorporates:
   *  Sum: '<S10>/Add1'
   *  Sum: '<S10>/Subtract1'
   *  UnitDelay: '<S10>/Unit Delay2'
   */
  rtDW.Initial_p = ((rtDW.Integrator - rtDW.Initial_p) + rtDW.Initial_p) -
    rtDW.UnitDelay2_DSTATE[1];

  /* Delay: '<S10>/Delay' incorporates:
   *  UnitDelay: '<S10>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE[1] = rtDW.Delay_DSTATE[1];

  /* Gain: '<S9>/Gain' incorporates:
   *  Delay: '<S10>/Delay'
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/delta''
   *  Sum: '<S10>/Add2'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S10>/Subtract2'
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S10>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[1] = ((rtDW.Integrator - ((rtDW.Delay_DSTATE[1] -
    rtDW.rtb_UnitDelay2_k) * 0.0 + rtDW.rtb_UnitDelay2_k)) + rtDW.Initial_p) *
    0.5 * 100.0;

  /* RealImagToComplex: '<S9>/Real-Imag to Complex' incorporates:
   *  Gain: '<S27>/Gain2'
   */
  rtDW.rtb_Gain2_re = rtDW.UnitDelay1_DSTATE[0];
  rtDW.rtb_Gain2_im_c = rtDW.UnitDelay1_DSTATE[1];

  /* Product: '<S9>/Product2' */
  rtDW.ComplextoRealImag_o2 *= rtDW.Product;
  rtDW.ComplextoRealImag_o1 *= rtDW.Product;

  /* DiscreteIntegrator: '<S9>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S9>/Integrator1' */
    rtDW.rtb_UnitDelay2_k = rtDW.Integrator1_DSTATE[0];
  } else {
    /* DiscreteIntegrator: '<S9>/Integrator1' */
    rtDW.rtb_UnitDelay2_k = 0.000125 * rtDW.ComplextoRealImag_o2 +
      rtDW.Integrator1_DSTATE[0];
  }

  /* DiscreteIntegrator: '<S9>/Integrator1' */
  rtDW.Integrator1_idx_0 = rtDW.rtb_UnitDelay2_k;

  /* UnitDelay: '<S11>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_j[0];

  /* Sum: '<S11>/Subtract1' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE_l_c = rtDW.UnitDelay1_DSTATE_l[0];

  /* Sum: '<S11>/Subtract3' incorporates:
   *  Sum: '<S11>/Add1'
   *  Sum: '<S11>/Subtract1'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtDW.UnitDelay1_DSTATE_l_c = ((rtDW.rtb_UnitDelay2_k -
    rtDW.UnitDelay1_DSTATE_l_c) + rtDW.UnitDelay1_DSTATE_l_c) -
    rtDW.UnitDelay2_DSTATE_j[0];

  /* Delay: '<S11>/Delay' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_j[0] = rtDW.Delay_DSTATE_j[0];

  /* Gain: '<S9>/Gain1' incorporates:
   *  Delay: '<S11>/Delay'
   *  Gain: '<S11>/Gain'
   *  Gain: '<S11>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S11>/Add2'
   *  Sum: '<S11>/Add3'
   *  Sum: '<S11>/Subtract2'
   *  Sum: '<S11>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[0] = ((rtDW.rtb_UnitDelay2_k - ((rtDW.Delay_DSTATE_j[0]
    - rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) + rtDW.UnitDelay1_DSTATE_l_c) *
    0.5 * 100.0;

  /* DiscreteIntegrator: '<S9>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S9>/Integrator1' */
    rtDW.rtb_UnitDelay2_k = rtDW.Integrator1_DSTATE[1];
  } else {
    /* DiscreteIntegrator: '<S9>/Integrator1' */
    rtDW.rtb_UnitDelay2_k = 0.000125 * rtDW.ComplextoRealImag_o1 +
      rtDW.Integrator1_DSTATE[1];
  }

  /* UnitDelay: '<S11>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_j[1];

  /* Sum: '<S11>/Subtract1' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE_l_c = rtDW.UnitDelay1_DSTATE_l[1];

  /* Sum: '<S11>/Subtract3' incorporates:
   *  Sum: '<S11>/Add1'
   *  Sum: '<S11>/Subtract1'
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtDW.UnitDelay1_DSTATE_l_c = ((rtDW.rtb_UnitDelay2_k -
    rtDW.UnitDelay1_DSTATE_l_c) + rtDW.UnitDelay1_DSTATE_l_c) -
    rtDW.UnitDelay2_DSTATE_j[1];

  /* Delay: '<S11>/Delay' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_j[1] = rtDW.Delay_DSTATE_j[1];

  /* Gain: '<S9>/Gain1' incorporates:
   *  Delay: '<S11>/Delay'
   *  Gain: '<S11>/Gain'
   *  Gain: '<S11>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S11>/Add2'
   *  Sum: '<S11>/Add3'
   *  Sum: '<S11>/Subtract2'
   *  Sum: '<S11>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[1] = ((rtDW.rtb_UnitDelay2_k - ((rtDW.Delay_DSTATE_j[1]
    - rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) + rtDW.UnitDelay1_DSTATE_l_c) *
    0.5 * 100.0;

  /* Math: '<S9>/Math Function' incorporates:
   *  RealImagToComplex: '<S9>/Real-Imag to Complex1'
   */
  rtDW.Initial_p = rtDW.UnitDelay1_DSTATE[0];
  rtDW.im = -rtDW.UnitDelay1_DSTATE[1];

  /* Product: '<S9>/Product3' incorporates:
   *  Gain: '<S27>/Gain2'
   */
  rtDW.UnitDelay1_DSTATE_l_c = rtDW.rtb_Gain2_re * rtDW.Initial_p -
    rtDW.rtb_Gain2_im_c * rtDW.im;
  rtDW.rtb_Gain2_im = rtDW.rtb_Gain2_re * rtDW.im + rtDW.rtb_Gain2_im_c *
    rtDW.Initial_p;

  /* InitialCondition: '<S23>/Initial' */
  if (rtDW.bitsForTID0.Initial_FirstOutputTime_n) {
    rtDW.bitsForTID0.Initial_FirstOutputTime_n = false;

    /* InitialCondition: '<S23>/Initial' */
    rtDW.Initial_a = 0.0;
  } else {
    /* InitialCondition: '<S23>/Initial' incorporates:
     *  Bias: '<S26>/Bias'
     *  Gain: '<S26>/Gain'
     *  Gain: '<S26>/Gain1'
     *  Rounding: '<S26>/Rounding Function'
     *  Sum: '<S26>/Sum1'
     */
    rtDW.Initial_a = rtDW.Integrator_DSTATE_o - floor(0.15915494309189535 *
      rtDW.Integrator_DSTATE_o) * 6.2831853071795862;
  }

  /* End of InitialCondition: '<S23>/Initial' */

  /* DiscreteIntegrator: '<S23>/Integrator' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Logic: '<S23>/Logical Operator'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   */
  if ((rtDW.Integrator_DSTATE_o < 0.0) || (rtDW.Integrator_DSTATE_o >=
       6.2831853071795862)) {
    rtDW.Integrator_DSTATE_o = rtDW.Initial_a;
  }

  /* Trigonometry: '<S18>/Trigonometric Function1' incorporates:
   *  DiscreteIntegrator: '<S23>/Integrator'
   */
  rtDW.ComplextoRealImag_o2_j = sin(rtDW.Integrator_DSTATE_o);
  rtDW.ComplextoRealImag_o1_d = cos(rtDW.Integrator_DSTATE_o);

  /* Product: '<S18>/Product1' */
  rtDW.Initial_a = rtDW.Product5 * rtDW.ComplextoRealImag_o2_j;
  rtDW.rtb_Product1_m_idx_1 = rtDW.Product5 * rtDW.ComplextoRealImag_o1_d;

  /* Product: '<S18>/Product2' */
  rtDW.ComplextoRealImag_o2_j *= rtDW.Product1;
  rtDW.ComplextoRealImag_o1_d *= rtDW.Product1;

  /* DiscreteIntegrator: '<S18>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE_k != 0) {
    /* DiscreteIntegrator: '<S18>/Integrator' */
    rtDW.Integrator_k = rtDW.Integrator_DSTATE_h[0];
  } else {
    /* DiscreteIntegrator: '<S18>/Integrator' */
    rtDW.Integrator_k = 0.000125 * rtDW.Initial_a + rtDW.Integrator_DSTATE_h[0];
  }

  /* DiscreteIntegrator: '<S18>/Integrator' */
  rtDW.Integrator_k_idx_0 = rtDW.Integrator_k;

  /* UnitDelay: '<S19>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_o[0];

  /* Sum: '<S19>/Subtract1' incorporates:
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  rtDW.Integrator1_o_idx_1 = rtDW.UnitDelay1_DSTATE_b[0];

  /* Sum: '<S19>/Subtract3' incorporates:
   *  Sum: '<S19>/Add1'
   *  Sum: '<S19>/Subtract1'
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  rtDW.Integrator1_o_idx_1 = ((rtDW.Integrator_k - rtDW.Integrator1_o_idx_1) +
    rtDW.Integrator1_o_idx_1) - rtDW.UnitDelay2_DSTATE_o[0];

  /* Delay: '<S19>/Delay' incorporates:
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_o[0] = rtDW.Delay_DSTATE_h[0];

  /* Gain: '<S18>/Gain' incorporates:
   *  Delay: '<S19>/Delay'
   *  Gain: '<S19>/Gain'
   *  Gain: '<S19>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S19>/Add2'
   *  Sum: '<S19>/Add3'
   *  Sum: '<S19>/Subtract2'
   *  Sum: '<S19>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[0] = ((rtDW.Integrator_k - ((rtDW.Delay_DSTATE_h[0] -
    rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) + rtDW.Integrator1_o_idx_1) * 0.5 *
    100.0;

  /* DiscreteIntegrator: '<S18>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE_n != 0) {
    /* DiscreteIntegrator: '<S18>/Integrator1' */
    rtDW.Integrator1_o_idx_0 = rtDW.Integrator1_DSTATE_i[0];
  } else {
    /* DiscreteIntegrator: '<S18>/Integrator1' */
    rtDW.Integrator1_o_idx_0 = 0.000125 * rtDW.ComplextoRealImag_o2_j +
      rtDW.Integrator1_DSTATE_i[0];
  }

  /* DiscreteIntegrator: '<S18>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE_k != 0) {
    /* DiscreteIntegrator: '<S18>/Integrator' */
    rtDW.Integrator_k = rtDW.Integrator_DSTATE_h[1];
  } else {
    /* DiscreteIntegrator: '<S18>/Integrator' */
    rtDW.Integrator_k = 0.000125 * rtDW.rtb_Product1_m_idx_1 +
      rtDW.Integrator_DSTATE_h[1];
  }

  /* UnitDelay: '<S19>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_o[1];

  /* Sum: '<S19>/Subtract1' incorporates:
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  rtDW.Integrator1_o_idx_1 = rtDW.UnitDelay1_DSTATE_b[1];

  /* Sum: '<S19>/Subtract3' incorporates:
   *  Sum: '<S19>/Add1'
   *  Sum: '<S19>/Subtract1'
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  rtDW.Integrator1_o_idx_1 = ((rtDW.Integrator_k - rtDW.Integrator1_o_idx_1) +
    rtDW.Integrator1_o_idx_1) - rtDW.UnitDelay2_DSTATE_o[1];

  /* Delay: '<S19>/Delay' incorporates:
   *  UnitDelay: '<S19>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_o[1] = rtDW.Delay_DSTATE_h[1];

  /* Gain: '<S18>/Gain' incorporates:
   *  Delay: '<S19>/Delay'
   *  Gain: '<S19>/Gain'
   *  Gain: '<S19>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S19>/Add2'
   *  Sum: '<S19>/Add3'
   *  Sum: '<S19>/Subtract2'
   *  Sum: '<S19>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[1] = ((rtDW.Integrator_k - ((rtDW.Delay_DSTATE_h[1] -
    rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) + rtDW.Integrator1_o_idx_1) * 0.5 *
    100.0;

  /* DiscreteIntegrator: '<S18>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE_n != 0) {
    /* DiscreteIntegrator: '<S18>/Integrator1' */
    rtDW.Integrator1_o_idx_1 = rtDW.Integrator1_DSTATE_i[1];
  } else {
    /* DiscreteIntegrator: '<S18>/Integrator1' */
    rtDW.Integrator1_o_idx_1 = 0.000125 * rtDW.ComplextoRealImag_o1_d +
      rtDW.Integrator1_DSTATE_i[1];
  }

  /* RealImagToComplex: '<S18>/Real-Imag to Complex' incorporates:
   *  RealImagToComplex: '<S27>/Real-Imag to Complex'
   */
  rtDW.rtb_Gain2_re = rtDW.UnitDelay1_DSTATE[0];
  rtDW.rtb_Gain2_im_c = rtDW.UnitDelay1_DSTATE[1];

  /* UnitDelay: '<S20>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_e[0];

  /* Sum: '<S20>/Subtract1' incorporates:
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE_m_m = rtDW.UnitDelay1_DSTATE_m[0];

  /* Sum: '<S20>/Subtract3' incorporates:
   *  Sum: '<S20>/Add1'
   *  Sum: '<S20>/Subtract1'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  rtDW.UnitDelay1_DSTATE_m_m = ((rtDW.Integrator1_o_idx_0 -
    rtDW.UnitDelay1_DSTATE_m_m) + rtDW.UnitDelay1_DSTATE_m_m) -
    rtDW.UnitDelay2_DSTATE_e[0];

  /* Delay: '<S20>/Delay' incorporates:
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_e[0] = rtDW.Delay_DSTATE_a[0];

  /* Gain: '<S18>/Gain1' incorporates:
   *  Delay: '<S20>/Delay'
   *  Gain: '<S20>/Gain'
   *  Gain: '<S20>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S20>/Add2'
   *  Sum: '<S20>/Add3'
   *  Sum: '<S20>/Subtract1'
   *  Sum: '<S20>/Subtract2'
   *  Sum: '<S20>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[0] = ((rtDW.Integrator1_o_idx_0 -
    ((rtDW.Delay_DSTATE_a[0] - rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) +
    rtDW.UnitDelay1_DSTATE_m_m) * 0.5 * 100.0;

  /* UnitDelay: '<S20>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_e[1];

  /* Sum: '<S20>/Subtract1' incorporates:
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE_m_m = rtDW.UnitDelay1_DSTATE_m[1];

  /* Sum: '<S20>/Subtract3' incorporates:
   *  Sum: '<S20>/Add1'
   *  Sum: '<S20>/Subtract1'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  rtDW.UnitDelay1_DSTATE_m_m = ((rtDW.Integrator1_o_idx_1 -
    rtDW.UnitDelay1_DSTATE_m_m) + rtDW.UnitDelay1_DSTATE_m_m) -
    rtDW.UnitDelay2_DSTATE_e[1];

  /* Delay: '<S20>/Delay' incorporates:
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_e[1] = rtDW.Delay_DSTATE_a[1];

  /* Gain: '<S18>/Gain1' incorporates:
   *  Delay: '<S20>/Delay'
   *  Gain: '<S20>/Gain'
   *  Gain: '<S20>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S20>/Add2'
   *  Sum: '<S20>/Add3'
   *  Sum: '<S20>/Subtract1'
   *  Sum: '<S20>/Subtract2'
   *  Sum: '<S20>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[1] = ((rtDW.Integrator1_o_idx_1 -
    ((rtDW.Delay_DSTATE_a[1] - rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) +
    rtDW.UnitDelay1_DSTATE_m_m) * 0.5 * 100.0;

  /* Math: '<S18>/Math Function' incorporates:
   *  RealImagToComplex: '<S18>/Real-Imag to Complex1'
   */
  rtDW.Initial_p = rtDW.UnitDelay1_DSTATE[0];
  rtDW.im = -rtDW.UnitDelay1_DSTATE[1];

  /* Product: '<S18>/Product3' incorporates:
   *  RealImagToComplex: '<S27>/Real-Imag to Complex'
   */
  rtDW.UnitDelay1_DSTATE_m_m = rtDW.rtb_Gain2_re * rtDW.Initial_p -
    rtDW.rtb_Gain2_im_c * rtDW.im;
  rtDW.im = rtDW.rtb_Gain2_re * rtDW.im + rtDW.rtb_Gain2_im_c * rtDW.Initial_p;

  /* InitialCondition: '<S32>/Initial' */
  if (rtDW.bitsForTID0.Initial_FirstOutputTime_f) {
    rtDW.bitsForTID0.Initial_FirstOutputTime_f = false;

    /* InitialCondition: '<S32>/Initial' */
    rtDW.Initial_p = 0.0;
  } else {
    /* InitialCondition: '<S32>/Initial' incorporates:
     *  Bias: '<S35>/Bias'
     *  Gain: '<S35>/Gain'
     *  Gain: '<S35>/Gain1'
     *  Rounding: '<S35>/Rounding Function'
     *  Sum: '<S35>/Sum1'
     */
    rtDW.Initial_p = rtDW.Integrator_DSTATE_a - floor(0.15915494309189535 *
      rtDW.Integrator_DSTATE_a) * 6.2831853071795862;
  }

  /* End of InitialCondition: '<S32>/Initial' */

  /* DiscreteIntegrator: '<S32>/Integrator' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S34>/Constant'
   *  Logic: '<S32>/Logical Operator'
   *  RelationalOperator: '<S33>/Compare'
   *  RelationalOperator: '<S34>/Compare'
   */
  if ((rtDW.Integrator_DSTATE_a < 0.0) || (rtDW.Integrator_DSTATE_a >=
       6.2831853071795862)) {
    rtDW.Integrator_DSTATE_a = rtDW.Initial_p;
  }

  /* Trigonometry: '<S27>/Trigonometric Function1' incorporates:
   *  DiscreteIntegrator: '<S32>/Integrator'
   */
  rtDW.rtb_Gain2_re = sin(rtDW.Integrator_DSTATE_a);
  rtDW.Initial_p = cos(rtDW.Integrator_DSTATE_a);

  /* Product: '<S27>/Product1' */
  rtDW.rtb_Product1_j_idx_0 = rtDW.Product6 * rtDW.rtb_Gain2_re;
  rtDW.rtb_Product1_j_idx_1 = rtDW.Product6 * rtDW.Initial_p;

  /* Product: '<S27>/Product2' */
  rtDW.rtb_Product2_i_idx_0 = rtDW.Product2 * rtDW.rtb_Gain2_re;
  rtDW.rtb_Product2_i_idx_1 = rtDW.Product2 * rtDW.Initial_p;

  /* DiscreteIntegrator: '<S27>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE_b != 0) {
    /* DiscreteIntegrator: '<S27>/Integrator' */
    rtDW.Integrator_p = rtDW.Integrator_DSTATE_l[0];
  } else {
    /* DiscreteIntegrator: '<S27>/Integrator' */
    rtDW.Integrator_p = 0.000125 * rtDW.rtb_Product1_j_idx_0 +
      rtDW.Integrator_DSTATE_l[0];
  }

  /* DiscreteIntegrator: '<S27>/Integrator' */
  rtDW.Integrator_p_idx_0 = rtDW.Integrator_p;

  /* UnitDelay: '<S28>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_d[0];

  /* Sum: '<S28>/Subtract1' incorporates:
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  rtDW.rtb_Gain2_re = rtDW.UnitDelay1_DSTATE_m4[0];

  /* Sum: '<S28>/Subtract3' incorporates:
   *  Sum: '<S28>/Add1'
   *  Sum: '<S28>/Subtract1'
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  rtDW.rtb_Gain2_re = ((rtDW.Integrator_p - rtDW.rtb_Gain2_re) +
                       rtDW.rtb_Gain2_re) - rtDW.UnitDelay2_DSTATE_d[0];

  /* Delay: '<S28>/Delay' incorporates:
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_d[0] = rtDW.Delay_DSTATE_e[0];

  /* Gain: '<S27>/Gain' incorporates:
   *  Delay: '<S28>/Delay'
   *  Gain: '<S28>/Gain'
   *  Gain: '<S28>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S28>/Add2'
   *  Sum: '<S28>/Add3'
   *  Sum: '<S28>/Subtract2'
   *  Sum: '<S28>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[0] = ((rtDW.Integrator_p - ((rtDW.Delay_DSTATE_e[0] -
    rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) + rtDW.rtb_Gain2_re) * 0.5 * 100.0;

  /* DiscreteIntegrator: '<S27>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE_b != 0) {
    /* DiscreteIntegrator: '<S27>/Integrator1' */
    rtDW.Integrator1_b_idx_0 = rtDW.Integrator1_DSTATE_p[0];
  } else {
    /* DiscreteIntegrator: '<S27>/Integrator1' */
    rtDW.Integrator1_b_idx_0 = 0.000125 * rtDW.rtb_Product2_i_idx_0 +
      rtDW.Integrator1_DSTATE_p[0];
  }

  /* DiscreteIntegrator: '<S27>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE_b != 0) {
    /* DiscreteIntegrator: '<S27>/Integrator' */
    rtDW.Integrator_p = rtDW.Integrator_DSTATE_l[1];
  } else {
    /* DiscreteIntegrator: '<S27>/Integrator' */
    rtDW.Integrator_p = 0.000125 * rtDW.rtb_Product1_j_idx_1 +
      rtDW.Integrator_DSTATE_l[1];
  }

  /* UnitDelay: '<S28>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_d[1];

  /* Sum: '<S28>/Subtract1' incorporates:
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  rtDW.rtb_Gain2_re = rtDW.UnitDelay1_DSTATE_m4[1];

  /* Sum: '<S28>/Subtract3' incorporates:
   *  Sum: '<S28>/Add1'
   *  Sum: '<S28>/Subtract1'
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  rtDW.rtb_Gain2_re = ((rtDW.Integrator_p - rtDW.rtb_Gain2_re) +
                       rtDW.rtb_Gain2_re) - rtDW.UnitDelay2_DSTATE_d[1];

  /* Delay: '<S28>/Delay' incorporates:
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_d[1] = rtDW.Delay_DSTATE_e[1];

  /* Gain: '<S27>/Gain' incorporates:
   *  Delay: '<S28>/Delay'
   *  Gain: '<S28>/Gain'
   *  Gain: '<S28>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S28>/Add2'
   *  Sum: '<S28>/Add3'
   *  Sum: '<S28>/Subtract2'
   *  Sum: '<S28>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[1] = ((rtDW.Integrator_p - ((rtDW.Delay_DSTATE_e[1] -
    rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) + rtDW.rtb_Gain2_re) * 0.5 * 100.0;

  /* DiscreteIntegrator: '<S27>/Integrator1' */
  if (rtDW.Integrator1_SYSTEM_ENABLE_b != 0) {
    /* DiscreteIntegrator: '<S27>/Integrator1' */
    rtDW.Integrator1_b_idx_1 = rtDW.Integrator1_DSTATE_p[1];
  } else {
    /* DiscreteIntegrator: '<S27>/Integrator1' */
    rtDW.Integrator1_b_idx_1 = 0.000125 * rtDW.rtb_Product2_i_idx_1 +
      rtDW.Integrator1_DSTATE_p[1];
  }

  /* RealImagToComplex: '<S27>/Real-Imag to Complex' */
  rtDW.rtb_Gain2_re = rtDW.UnitDelay1_DSTATE[0];
  rtDW.rtb_Gain2_im_c = rtDW.UnitDelay1_DSTATE[1];

  /* Outport: '<Root>/PowerDisplay' incorporates:
   *  Gain: '<S18>/Gain2'
   *  Gain: '<S9>/Gain2'
   */
  rtY.PowerDisplay[0] = 0.5 * rtDW.UnitDelay1_DSTATE_l_c;
  rtY.PowerDisplay[1] = 0.5 * rtDW.rtb_Gain2_im;
  rtY.PowerDisplay[2] = 0.5 * rtDW.UnitDelay1_DSTATE_m_m;
  rtY.PowerDisplay[3] = 0.5 * rtDW.im;

  /* Update for DiscreteIntegrator: '<S14>/Integrator' incorporates:
   *  Constant: '<S9>/Radial frequencies'
   */
  rtDW.Integrator_DSTATE += 0.078539816339744828;

  /* Update for DiscreteIntegrator: '<S9>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 0U;

  /* UnitDelay: '<S29>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_g[0];

  /* Sum: '<S29>/Subtract1' incorporates:
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE_l_c = rtDW.UnitDelay1_DSTATE_f[0];

  /* Sum: '<S29>/Subtract3' incorporates:
   *  Sum: '<S29>/Add1'
   *  Sum: '<S29>/Subtract1'
   *  UnitDelay: '<S29>/Unit Delay2'
   */
  rtDW.UnitDelay1_DSTATE_l_c = ((rtDW.Integrator1_b_idx_0 -
    rtDW.UnitDelay1_DSTATE_l_c) + rtDW.UnitDelay1_DSTATE_l_c) -
    rtDW.UnitDelay2_DSTATE_g[0];

  /* Delay: '<S29>/Delay' incorporates:
   *  UnitDelay: '<S29>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_g[0] = rtDW.Delay_DSTATE_d[0];

  /* Gain: '<S27>/Gain1' incorporates:
   *  Delay: '<S29>/Delay'
   *  Gain: '<S29>/Gain'
   *  Gain: '<S29>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S29>/Add2'
   *  Sum: '<S29>/Add3'
   *  Sum: '<S29>/Subtract1'
   *  Sum: '<S29>/Subtract2'
   *  Sum: '<S29>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[0] = ((rtDW.Integrator1_b_idx_0 -
    ((rtDW.Delay_DSTATE_d[0] - rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) +
    rtDW.UnitDelay1_DSTATE_l_c) * 0.5 * 100.0;

  /* Update for DiscreteIntegrator: '<S9>/Integrator' */
  rtDW.Integrator_DSTATE_i[0] = 0.000125 * rtDW.Initial + rtDW.Integrator_idx_0;

  /* UnitDelay: '<S29>/Unit Delay2' */
  rtDW.Initial_p = rtDW.UnitDelay2_DSTATE_g[1];

  /* Sum: '<S29>/Subtract1' incorporates:
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE_l_c = rtDW.UnitDelay1_DSTATE_f[1];

  /* Sum: '<S29>/Subtract3' incorporates:
   *  Sum: '<S29>/Add1'
   *  Sum: '<S29>/Subtract1'
   *  UnitDelay: '<S29>/Unit Delay2'
   */
  rtDW.UnitDelay1_DSTATE_l_c = ((rtDW.Integrator1_b_idx_1 -
    rtDW.UnitDelay1_DSTATE_l_c) + rtDW.UnitDelay1_DSTATE_l_c) -
    rtDW.UnitDelay2_DSTATE_g[1];

  /* Delay: '<S29>/Delay' incorporates:
   *  UnitDelay: '<S29>/Unit Delay2'
   */
  rtDW.UnitDelay2_DSTATE_g[1] = rtDW.Delay_DSTATE_d[1];

  /* Gain: '<S27>/Gain1' incorporates:
   *  Delay: '<S29>/Delay'
   *  Gain: '<S29>/Gain'
   *  Gain: '<S29>/delta''
   *  Sum: '<S10>/Subtract3'
   *  Sum: '<S29>/Add2'
   *  Sum: '<S29>/Add3'
   *  Sum: '<S29>/Subtract1'
   *  Sum: '<S29>/Subtract2'
   *  Sum: '<S29>/Subtract4'
   */
  rtDW.UnitDelay1_DSTATE[1] = ((rtDW.Integrator1_b_idx_1 -
    ((rtDW.Delay_DSTATE_d[1] - rtDW.Initial_p) * 0.0 + rtDW.Initial_p)) +
    rtDW.UnitDelay1_DSTATE_l_c) * 0.5 * 100.0;

  /* Update for DiscreteIntegrator: '<S9>/Integrator' */
  rtDW.Integrator_DSTATE_i[1] = 0.000125 * rtDW.rtb_Product1_n_idx_1 +
    rtDW.Integrator;

  /* Math: '<S27>/Math Function' incorporates:
   *  RealImagToComplex: '<S27>/Real-Imag to Complex1'
   */
  rtDW.Initial_p = rtDW.UnitDelay1_DSTATE[0];
  rtDW.im = -rtDW.UnitDelay1_DSTATE[1];

  /* Outport: '<Root>/PowerDisplay' incorporates:
   *  Gain: '<S27>/Gain2'
   *  Product: '<S27>/Product3'
   *  RealImagToComplex: '<S27>/Real-Imag to Complex'
   */
  rtY.PowerDisplay[4] = (rtDW.rtb_Gain2_re * rtDW.Initial_p -
    rtDW.rtb_Gain2_im_c * rtDW.im) * 0.5;
  rtY.PowerDisplay[5] = (rtDW.rtb_Gain2_re * rtDW.im + rtDW.rtb_Gain2_im_c *
    rtDW.Initial_p) * 0.5;

  /* Update for UnitDelay: '<S10>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S9>/Integrator'
   *  Sum: '<S10>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE[0] = rtDW.Integrator_idx_0;
  rtDW.UnitDelay1_DSTATE[1] = rtDW.Integrator;

  /* Update for DiscreteIntegrator: '<S9>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE = 0U;
  rtDW.Integrator1_DSTATE[0] = 0.000125 * rtDW.ComplextoRealImag_o2 +
    rtDW.Integrator1_idx_0;

  /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S9>/Integrator1'
   *  Sum: '<S11>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_l[0] = rtDW.Integrator1_idx_0;

  /* Update for DiscreteIntegrator: '<S9>/Integrator1' */
  rtDW.Integrator1_DSTATE[1] = 0.000125 * rtDW.ComplextoRealImag_o1 +
    rtDW.rtb_UnitDelay2_k;

  /* Update for UnitDelay: '<S11>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S9>/Integrator1'
   *  Sum: '<S11>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_l[1] = rtDW.rtb_UnitDelay2_k;

  /* Update for DiscreteIntegrator: '<S23>/Integrator' incorporates:
   *  Constant: '<S18>/Radial frequencies'
   */
  rtDW.Integrator_DSTATE_o += 0.078539816339744828;

  /* Update for DiscreteIntegrator: '<S18>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE_k = 0U;
  rtDW.Integrator_DSTATE_h[0] = 0.000125 * rtDW.Initial_a +
    rtDW.Integrator_k_idx_0;

  /* Update for UnitDelay: '<S19>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator'
   *  Sum: '<S19>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_b[0] = rtDW.Integrator_k_idx_0;

  /* Update for DiscreteIntegrator: '<S18>/Integrator' */
  rtDW.Integrator_DSTATE_h[1] = 0.000125 * rtDW.rtb_Product1_m_idx_1 +
    rtDW.Integrator_k;

  /* Update for UnitDelay: '<S19>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator'
   *  Sum: '<S19>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_b[1] = rtDW.Integrator_k;

  /* Update for DiscreteIntegrator: '<S18>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE_n = 0U;
  rtDW.Integrator1_DSTATE_i[0] = 0.000125 * rtDW.ComplextoRealImag_o2_j +
    rtDW.Integrator1_o_idx_0;

  /* Update for UnitDelay: '<S20>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator1'
   *  Sum: '<S20>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_m[0] = rtDW.Integrator1_o_idx_0;

  /* Update for DiscreteIntegrator: '<S18>/Integrator1' */
  rtDW.Integrator1_DSTATE_i[1] = 0.000125 * rtDW.ComplextoRealImag_o1_d +
    rtDW.Integrator1_o_idx_1;

  /* Update for UnitDelay: '<S20>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator1'
   *  Sum: '<S20>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_m[1] = rtDW.Integrator1_o_idx_1;

  /* Update for DiscreteIntegrator: '<S32>/Integrator' incorporates:
   *  Constant: '<S27>/Radial frequencies'
   */
  rtDW.Integrator_DSTATE_a += 0.078539816339744828;

  /* Update for DiscreteIntegrator: '<S27>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE_b = 0U;
  rtDW.Integrator_DSTATE_l[0] = 0.000125 * rtDW.rtb_Product1_j_idx_0 +
    rtDW.Integrator_p_idx_0;

  /* Update for UnitDelay: '<S28>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S27>/Integrator'
   *  Sum: '<S28>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_m4[0] = rtDW.Integrator_p_idx_0;

  /* Update for DiscreteIntegrator: '<S27>/Integrator' */
  rtDW.Integrator_DSTATE_l[1] = 0.000125 * rtDW.rtb_Product1_j_idx_1 +
    rtDW.Integrator_p;

  /* Update for UnitDelay: '<S28>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S27>/Integrator'
   *  Sum: '<S28>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_m4[1] = rtDW.Integrator_p;

  /* Update for DiscreteIntegrator: '<S27>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE_b = 0U;
  rtDW.Integrator1_DSTATE_p[0] = 0.000125 * rtDW.rtb_Product2_i_idx_0 +
    rtDW.Integrator1_b_idx_0;

  /* Update for UnitDelay: '<S29>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S27>/Integrator1'
   *  Sum: '<S29>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_f[0] = rtDW.Integrator1_b_idx_0;

  /* Update for DiscreteIntegrator: '<S27>/Integrator1' */
  rtDW.Integrator1_DSTATE_p[1] = 0.000125 * rtDW.rtb_Product2_i_idx_1 +
    rtDW.Integrator1_b_idx_1;

  /* Update for UnitDelay: '<S29>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S27>/Integrator1'
   *  Sum: '<S29>/Subtract3'
   */
  rtDW.UnitDelay1_DSTATE_f[1] = rtDW.Integrator1_b_idx_1;
  for (idxDelay = 0; idxDelay < 78; idxDelay++) {
    /* Update for Delay: '<S10>/Delay' incorporates:
     *  Delay: '<S11>/Delay'
     *  Delay: '<S19>/Delay'
     *  Delay: '<S20>/Delay'
     *  Delay: '<S28>/Delay'
     *  Delay: '<S29>/Delay'
     */
    Delay_DSTATE_tmp = (idxDelay + 1) << 1;
    Delay_DSTATE_tmp_0 = idxDelay << 1;
    rtDW.Delay_DSTATE[Delay_DSTATE_tmp_0] = rtDW.Delay_DSTATE[Delay_DSTATE_tmp];
    rtDW.Delay_DSTATE[Delay_DSTATE_tmp_0 + 1] =
      rtDW.Delay_DSTATE[Delay_DSTATE_tmp + 1];

    /* Update for Delay: '<S11>/Delay' incorporates:
     *  Delay: '<S10>/Delay'
     */
    rtDW.Delay_DSTATE_j[Delay_DSTATE_tmp_0] =
      rtDW.Delay_DSTATE_j[Delay_DSTATE_tmp];
    rtDW.Delay_DSTATE_j[Delay_DSTATE_tmp_0 + 1] =
      rtDW.Delay_DSTATE_j[Delay_DSTATE_tmp + 1];

    /* Update for Delay: '<S19>/Delay' incorporates:
     *  Delay: '<S10>/Delay'
     */
    rtDW.Delay_DSTATE_h[Delay_DSTATE_tmp_0] =
      rtDW.Delay_DSTATE_h[Delay_DSTATE_tmp];
    rtDW.Delay_DSTATE_h[Delay_DSTATE_tmp_0 + 1] =
      rtDW.Delay_DSTATE_h[Delay_DSTATE_tmp + 1];

    /* Update for Delay: '<S20>/Delay' incorporates:
     *  Delay: '<S10>/Delay'
     */
    rtDW.Delay_DSTATE_a[Delay_DSTATE_tmp_0] =
      rtDW.Delay_DSTATE_a[Delay_DSTATE_tmp];
    rtDW.Delay_DSTATE_a[Delay_DSTATE_tmp_0 + 1] =
      rtDW.Delay_DSTATE_a[Delay_DSTATE_tmp + 1];

    /* Update for Delay: '<S28>/Delay' incorporates:
     *  Delay: '<S10>/Delay'
     */
    rtDW.Delay_DSTATE_e[Delay_DSTATE_tmp_0] =
      rtDW.Delay_DSTATE_e[Delay_DSTATE_tmp];
    rtDW.Delay_DSTATE_e[Delay_DSTATE_tmp_0 + 1] =
      rtDW.Delay_DSTATE_e[Delay_DSTATE_tmp + 1];

    /* Update for Delay: '<S29>/Delay' incorporates:
     *  Delay: '<S10>/Delay'
     */
    rtDW.Delay_DSTATE_d[Delay_DSTATE_tmp_0] =
      rtDW.Delay_DSTATE_d[Delay_DSTATE_tmp];
    rtDW.Delay_DSTATE_d[Delay_DSTATE_tmp_0 + 1] =
      rtDW.Delay_DSTATE_d[Delay_DSTATE_tmp + 1];
  }

  /* Update for Delay: '<S10>/Delay' incorporates:
   *  DiscreteIntegrator: '<S9>/Integrator'
   */
  rtDW.Delay_DSTATE[156] = rtDW.Integrator_idx_0;
  rtDW.Delay_DSTATE[157] = rtDW.Integrator;

  /* Update for Delay: '<S11>/Delay' incorporates:
   *  DiscreteIntegrator: '<S9>/Integrator1'
   */
  rtDW.Delay_DSTATE_j[156] = rtDW.Integrator1_idx_0;
  rtDW.Delay_DSTATE_j[157] = rtDW.rtb_UnitDelay2_k;

  /* Update for Delay: '<S19>/Delay' incorporates:
   *  DiscreteIntegrator: '<S18>/Integrator'
   */
  rtDW.Delay_DSTATE_h[156] = rtDW.Integrator_k_idx_0;
  rtDW.Delay_DSTATE_h[157] = rtDW.Integrator_k;

  /* Update for Delay: '<S20>/Delay' */
  rtDW.Delay_DSTATE_a[156] = rtDW.Integrator1_o_idx_0;
  rtDW.Delay_DSTATE_a[157] = rtDW.Integrator1_o_idx_1;

  /* Update for Delay: '<S28>/Delay' incorporates:
   *  DiscreteIntegrator: '<S27>/Integrator'
   */
  rtDW.Delay_DSTATE_e[156] = rtDW.Integrator_p_idx_0;
  rtDW.Delay_DSTATE_e[157] = rtDW.Integrator_p;

  /* Update for Delay: '<S29>/Delay' */
  rtDW.Delay_DSTATE_d[156] = rtDW.Integrator1_b_idx_0;
  rtDW.Delay_DSTATE_d[157] = rtDW.Integrator1_b_idx_1;
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

  /* Start for InitialCondition: '<S14>/Initial' */
  rtDW.bitsForTID0.Initial_FirstOutputTime = true;

  /* Start for InitialCondition: '<S23>/Initial' */
  rtDW.bitsForTID0.Initial_FirstOutputTime_n = true;

  /* Start for InitialCondition: '<S32>/Initial' */
  rtDW.bitsForTID0.Initial_FirstOutputTime_f = true;
  MovingRMS_Init(&rtDW.MovingRMS_p);
  MovingRMS_Init(&rtDW.MovingRMS1);
  MovingRMS_Init(&rtDW.MovingRMS2);
  MovingRMS_Init(&rtDW.MovingRMS3);
  MovingRMS_Init(&rtDW.MovingRMS4);
  MovingRMS_Init(&rtDW.MovingRMS5);
  MovingRMS_Init(&rtDW.MovingRMS6);
  MovingRMS_Init(&rtDW.MovingRMS7);

  /* Enable for DiscreteIntegrator: '<S9>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S9>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S18>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE_k = 1U;

  /* Enable for DiscreteIntegrator: '<S18>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE_n = 1U;

  /* Enable for DiscreteIntegrator: '<S27>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE_b = 1U;

  /* Enable for DiscreteIntegrator: '<S27>/Integrator1' */
  rtDW.Integrator1_SYSTEM_ENABLE_b = 1U;
}
