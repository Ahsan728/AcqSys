/*
 * PostProcessing.h
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

/* Block signals and states (default storage) for system '<S3>/Moving RMS' */
typedef struct {
  dsp_simulink_MovingRMS obj;          /* '<S3>/Moving RMS' */
  real_T MovingRMS_i;                  /* '<S3>/Moving RMS' */
  struct {
    uint_T objisempty:1;               /* '<S3>/Moving RMS' */
  } bitsForTID0;
} DW_MovingRMS;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_MovingRMS MovingRMS7;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS6;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS5;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS4;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS3;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS2;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS1;             /* '<S3>/Moving RMS' */
  DW_MovingRMS MovingRMS_p;            /* '<S3>/Moving RMS' */
  real_T Divide;                       /* '<S4>/Divide' */
  real_T Divide1;                      /* '<S4>/Divide1' */
  real_T Divide2;                      /* '<S4>/Divide2' */
  real_T Divide3;                      /* '<S4>/Divide3' */
  real_T Divide4;                      /* '<S4>/Divide4' */
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
 * '<S3>'   : 'FeaturesExtraction_V2/PostProcessing/RMS'
 * '<S4>'   : 'FeaturesExtraction_V2/PostProcessing/SamplesCalibration'
 */
#endif                                 /* RTW_HEADER_PostProcessing_h_ */
