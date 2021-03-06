/*
 * File: FuelSensor.h
 *
 * Code generated for Simulink model 'FuelSensor'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Sun Mar 22 14:02:44 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FuelSensor_h_
#define RTW_HEADER_FuelSensor_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <string.h>
#ifndef FuelSensor_COMMON_INCLUDES_
# define FuelSensor_COMMON_INCLUDES_
#endif                                 /* FuelSensor_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_FuelSensor_T RT_MODEL_FuelSensor_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T Lighton_DSTATE;            /* '<Root>/Light on  ' */
} DW_FuelSensor_T;

/* Parameters (auto storage) */
struct P_FuelSensor_T_ {
  real_T LowFuelSensor_const;          /* Mask Parameter: LowFuelSensor_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  boolean_T Lighton_InitialCondition;  /* Computed Parameter: Lighton_InitialCondition
                                        * Referenced by: '<Root>/Light on  '
                                        */
};

/* Parameters (auto storage) */
typedef struct P_FuelSensor_T_ P_FuelSensor_T;

/* Real-time Model Data Structure */
struct tag_RTM_FuelSensor_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_FuelSensor_T FuelSensor_P;

/* Block states (auto storage) */
extern DW_FuelSensor_T FuelSensor_DW;

/* Model entry point functions */
void FuelSensor_initialize(void);
void FuelSensor_step(boolean_T* fs_warning_light, real_T* fs_fuel_level);
void FuelSensor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FuelSensor_T *const FuelSensor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FuelSensor'
 * '<S1>'   : 'FuelSensor/Low Fuel Sensor'
 */
#endif                                 /* RTW_HEADER_FuelSensor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
