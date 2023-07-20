/*
 * PostProcessing.h
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

#ifndef RTW_HEADER_PostProcessing_h_
#define RTW_HEADER_PostProcessing_h_
#ifndef PostProcessing_COMMON_INCLUDES_
#define PostProcessing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PostProcessing_COMMON_INCLUDES_ */

#ifndef struct_tag_xm5q3dGCROLmOPhUk992jB
#define struct_tag_xm5q3dGCROLmOPhUk992jB

struct tag_xm5q3dGCROLmOPhUk992jB
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN;
  real_T plambda;
};

#endif                                 /* struct_tag_xm5q3dGCROLmOPhUk992jB */

#ifndef typedef_g_dsp_internal_ExponentialMovin
#define typedef_g_dsp_internal_ExponentialMovin

typedef struct tag_xm5q3dGCROLmOPhUk992jB g_dsp_internal_ExponentialMovin;

#endif                             /* typedef_g_dsp_internal_ExponentialMovin */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_4cCnIZk3PKZ5pfZVNQa5jB
#define struct_tag_4cCnIZk3PKZ5pfZVNQa5jB

struct tag_4cCnIZk3PKZ5pfZVNQa5jB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  g_dsp_internal_ExponentialMovin *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  g_dsp_internal_ExponentialMovin _pobj0;
};

#endif                                 /* struct_tag_4cCnIZk3PKZ5pfZVNQa5jB */

#ifndef typedef_dsp_simulink_MovingRMS
#define typedef_dsp_simulink_MovingRMS

typedef struct tag_4cCnIZk3PKZ5pfZVNQa5jB dsp_simulink_MovingRMS;

#endif                                 /* typedef_dsp_simulink_MovingRMS */

/* Block signals and states (default storage) for system '<S4>/Moving RMS' */
typedef struct {
  dsp_simulink_MovingRMS obj;          /* '<S4>/Moving RMS' */
  real_T MovingRMS_i;                  /* '<S4>/Moving RMS' */
  struct {
    uint_T objisempty:1;               /* '<S4>/Moving RMS' */
  } bitsForTID0;
} DW_MovingRMS;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_MovingRMS MovingRMS7;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS6;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS5;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS4;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS3;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS2;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS1;             /* '<S4>/Moving RMS' */
  DW_MovingRMS MovingRMS_p;            /* '<S4>/Moving RMS' */
  real_T Integrator_DSTATE_i[2];       /* '<S9>/Integrator' */
  real_T UnitDelay1_DSTATE[2];         /* '<S10>/Unit Delay1' */
  real_T UnitDelay2_DSTATE[2];         /* '<S10>/Unit Delay2' */
  real_T Delay_DSTATE[158];            /* '<S10>/Delay' */
  real_T Integrator1_DSTATE[2];        /* '<S9>/Integrator1' */
  real_T UnitDelay1_DSTATE_l[2];       /* '<S11>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_j[2];       /* '<S11>/Unit Delay2' */
  real_T Delay_DSTATE_j[158];          /* '<S11>/Delay' */
  real_T Integrator_DSTATE_h[2];       /* '<S18>/Integrator' */
  real_T UnitDelay1_DSTATE_b[2];       /* '<S19>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_o[2];       /* '<S19>/Unit Delay2' */
  real_T Delay_DSTATE_h[158];          /* '<S19>/Delay' */
  real_T Integrator1_DSTATE_i[2];      /* '<S18>/Integrator1' */
  real_T UnitDelay1_DSTATE_m[2];       /* '<S20>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_e[2];       /* '<S20>/Unit Delay2' */
  real_T Delay_DSTATE_a[158];          /* '<S20>/Delay' */
  real_T Integrator_DSTATE_l[2];       /* '<S27>/Integrator' */
  real_T UnitDelay1_DSTATE_m4[2];      /* '<S28>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_d[2];       /* '<S28>/Unit Delay2' */
  real_T Delay_DSTATE_e[158];          /* '<S28>/Delay' */
  real_T Integrator1_DSTATE_p[2];      /* '<S27>/Integrator1' */
  real_T UnitDelay1_DSTATE_f[2];       /* '<S29>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_g[2];       /* '<S29>/Unit Delay2' */
  real_T Delay_DSTATE_d[158];          /* '<S29>/Delay' */
  real_T Integrator_DSTATE;            /* '<S14>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S23>/Integrator' */
  real_T Integrator_DSTATE_a;          /* '<S32>/Integrator' */
  real_T ComplextoRealImag_o2;         /* '<S9>/Complex to Real-Imag' */
  real_T ComplextoRealImag_o1;         /* '<S9>/Complex to Real-Imag' */
  real_T ComplextoRealImag_o2_j;       /* '<S18>/Complex to Real-Imag' */
  real_T ComplextoRealImag_o1_d;       /* '<S18>/Complex to Real-Imag' */
  real_T Initial;
  real_T Initial_a;
  real_T Initial_p;
  real_T Integrator_p;
  real_T UnitDelay1_DSTATE_m_m;
  real_T Integrator_k;
  real_T UnitDelay1_DSTATE_l_c;
  real_T Integrator;
  real_T rtb_UnitDelay2_k;
  real_T rtb_Product1_n_idx_1;
  real_T rtb_Product1_m_idx_1;
  real_T rtb_Product1_j_idx_0;
  real_T rtb_Product1_j_idx_1;
  real_T rtb_Product2_i_idx_0;
  real_T rtb_Product2_i_idx_1;
  real_T Integrator1_b_idx_0;
  real_T Integrator1_b_idx_1;
  real_T Integrator_p_idx_0;
  real_T Integrator1_o_idx_0;
  real_T Integrator1_o_idx_1;
  real_T Integrator_k_idx_0;
  real_T Integrator1_idx_0;
  real_T Integrator_idx_0;
  real_T rtb_Gain2_im;
  real_T rtb_Gain2_re;
  real_T rtb_Gain2_im_c;
  real_T im;
  real_T Product;                      /* '<S5>/Product' */
  real_T Product1;                     /* '<S5>/Product1' */
  real_T Product2;                     /* '<S5>/Product2' */
  real_T Product3;                     /* '<S5>/Product3' */
  real_T Product4;                     /* '<S5>/Product4' */
  real_T Product5;                     /* '<S5>/Product5' */
  real_T Product6;                     /* '<S5>/Product6' */
  struct {
    uint_T Initial_FirstOutputTime:1;  /* '<S14>/Initial' */
    uint_T Initial_FirstOutputTime_n:1;/* '<S23>/Initial' */
    uint_T Initial_FirstOutputTime_f:1;/* '<S32>/Initial' */
  } bitsForTID0;

  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S9>/Integrator' */
  uint8_T Integrator1_SYSTEM_ENABLE;   /* '<S9>/Integrator1' */
  uint8_T Integrator_SYSTEM_ENABLE_k;  /* '<S18>/Integrator' */
  uint8_T Integrator1_SYSTEM_ENABLE_n; /* '<S18>/Integrator1' */
  uint8_T Integrator_SYSTEM_ENABLE_b;  /* '<S27>/Integrator' */
  uint8_T Integrator1_SYSTEM_ENABLE_b; /* '<S27>/Integrator1' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T I1;                           /* '<Root>/I1' */
  real_T I2;                           /* '<Root>/I2' */
  real_T I3;                           /* '<Root>/I3' */
  real_T I4;                           /* '<Root>/I4' */
  real_T V1;                           /* '<Root>/V1' */
  real_T V2;                           /* '<Root>/V2' */
  real_T V3;                           /* '<Root>/V3' */
  real_T V4;                           /* '<Root>/V4' */
  real_T CalI1;                        /* '<Root>/CalI1' */
  real_T CalI2;                        /* '<Root>/CalI2' */
  real_T CalI3;                        /* '<Root>/CalI3' */
  real_T CalI4;                        /* '<Root>/CalI4' */
  real_T CalV1;                        /* '<Root>/CalV1' */
  real_T CalV2;                        /* '<Root>/CalV2' */
  real_T CalV3;                        /* '<Root>/CalV3' */
  real_T CalV4;                        /* '<Root>/CalV4' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T RMSDisplay[8];                /* '<Root>/RMSDisplay' */
  real_T PowerDisplay[6];              /* '<Root>/PowerDisplay' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void PostProcessing_initialize(void);
extern void PostProcessing_step(void);
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/delta' : Eliminated nontunable gain of 1
 * Block '<S11>/delta' : Eliminated nontunable gain of 1
 * Block '<S12>/Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/delta' : Eliminated nontunable gain of 1
 * Block '<S20>/delta' : Eliminated nontunable gain of 1
 * Block '<S21>/Conversion' : Eliminate redundant data type conversion
 * Block '<S28>/delta' : Eliminated nontunable gain of 1
 * Block '<S29>/delta' : Eliminated nontunable gain of 1
 * Block '<S30>/Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('FeaturesExtraction_V2/PostProcessing')    - opens subsystem FeaturesExtraction_V2/PostProcessing
 * hilite_system('FeaturesExtraction_V2/PostProcessing/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FeaturesExtraction_V2'
 * '<S1>'   : 'FeaturesExtraction_V2/PostProcessing'
 * '<S2>'   : 'FeaturesExtraction_V2/PostProcessing/PhPhConversion'
 * '<S3>'   : 'FeaturesExtraction_V2/PostProcessing/Powers'
 * '<S4>'   : 'FeaturesExtraction_V2/PostProcessing/RMS'
 * '<S5>'   : 'FeaturesExtraction_V2/PostProcessing/SamplesCalibration'
 * '<S6>'   : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement'
 * '<S7>'   : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1'
 * '<S8>'   : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2'
 * '<S9>'   : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete'
 * '<S10>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Corrected discrete transport delay'
 * '<S11>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Corrected discrete transport delay1'
 * '<S12>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Data Type Conversion Inherited'
 * '<S13>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S14>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S15>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S16>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S17>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S18>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete'
 * '<S19>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Corrected discrete transport delay'
 * '<S20>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Corrected discrete transport delay1'
 * '<S21>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Data Type Conversion Inherited'
 * '<S22>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S23>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S24>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S25>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S26>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement1/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S27>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete'
 * '<S28>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Corrected discrete transport delay'
 * '<S29>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Corrected discrete transport delay1'
 * '<S30>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Data Type Conversion Inherited'
 * '<S31>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S32>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S33>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S34>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S35>'  : 'FeaturesExtraction_V2/PostProcessing/Powers/Power Measurement2/Discrete/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 */
#endif                                 /* RTW_HEADER_PostProcessing_h_ */
