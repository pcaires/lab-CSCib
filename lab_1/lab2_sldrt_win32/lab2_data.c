/*
 * lab2_data.c
 *
 * Code generation for model "lab2".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Nov 04 13:28:04 2021
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab2.h"
#include "lab2_private.h"

/* Block parameters (auto storage) */
P_lab2_T lab2_P = {
  /*  Variable: A
   * Referenced by:
   *   '<Root>/Discrete State-Space'
   *   '<S1>/Gain5'
   */
  { 1.3676831331797774, 1.0, 0.0, 0.0, 0.0, 0.0, 0.7999474490801971, 0.0, 1.0,
    0.0, 0.0, 0.0, -1.7059409377090224, 0.0, 0.0, 1.0, 0.0, 0.0,
    -0.1700912109682442, 0.0, 0.0, 0.0, 1.0, 0.0, 1.1418248250727341, 0.0, 0.0,
    0.0, 0.0, 1.0, -0.43342325865544223, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: B
   * Referenced by:
   *   '<Root>/Discrete State-Space'
   *   '<S1>/Gain2'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: C
   * Referenced by:
   *   '<Root>/Discrete State-Space'
   *   '<Root>/Gain2'
   *   '<S1>/Gain3'
   */
  { 0.17024271284376752, -0.29673284123772731, -0.091942850536980383,
    0.10020793968978108, -0.35794350585887541, 0.0 },
  0.0,                                 /* Variable: D
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */

  /*  Variable: K
   * Referenced by: '<Root>/Gain1'
   */
  { 0.15294527932161958, -0.04889439173144202, -0.17979342427798412,
    0.073217364206742283, 0.10966304798769082, -0.063124925844661312 },

  /*  Variable: M
   * Referenced by: '<S1>/Gain4'
   */
  { -4.04542861485215, -3.8334108817092769, -2.8610381708487309,
    -1.35145656847338, -1.1731876412714202, 0.62786253294026506 },
  -2.1925281718107539,                 /* Variable: Nbar
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput_MaxMissedTicks
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  10.0,                                /* Mask Parameter: AnalogInput1_MaxMissedTicks
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput_YieldWhenWaiting
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogInput1_YieldWhenWaiting
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogInput_Channels
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  1,                                   /* Mask Parameter: AnalogInput1_Channels
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogInput_RangeMode
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_RangeMode
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<Root>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogInput_VoltRange
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  0,                                   /* Mask Parameter: AnalogInput1_VoltRange
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Delay'
                                        */
  1U                                   /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S1>/Delay'
                                        */
};
