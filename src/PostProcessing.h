/*
 * PostProcessing.h
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
#ifndef RTW_HEADER_PostProcessing_h_
#define RTW_HEADER_PostProcessing_h_
#ifndef PostProcessing_COMMON_INCLUDES_
#define PostProcessing_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PostProcessing_COMMON_INCLUDES_ */

#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define PostProcessing_M               (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T RMS_SqData;                   /* '<S1>/RMS' */
  uint32_T RMS_Iteration;              /* '<S1>/RMS' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Samples_32b;                  /* '<Root>/Samples_32b' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out_RMS;                      /* '<Root>/Out_RMS' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void PostProcessing_initialize(void);
extern void PostProcessing_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
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
 */
#endif                                 /* RTW_HEADER_PostProcessing_h_ */