/*
 * lab_1.c
 *
 * Code generation for model "lab_1".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Oct 21 12:49:16 2021
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lab_1.h"
#include "lab_1_private.h"
#include "lab_1_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double RTWinBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.02, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, RTWinBoardOptions0 },
};

/* Block signals (auto storage) */
B_lab_1_T lab_1_B;

/* Block states (auto storage) */
DW_lab_1_T lab_1_DW;

/* Real-time model */
RT_MODEL_lab_1_T lab_1_M_;
RT_MODEL_lab_1_T *const lab_1_M = &lab_1_M_;

/* Model output function */
void lab_1_output(void)
{
  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) lab_1_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) lab_1_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = lab_1_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = lab_1_M->Timing.t[1];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[999]) {
      currTimeIndex = 998;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    lab_1_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          lab_1_B.FromWorkspace = pDataValues[currTimeIndex];
        } else {
          lab_1_B.FromWorkspace = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        lab_1_B.FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1000;
      }
    }
  }

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab_1_P.AnalogOutput_Channels,
                     &lab_1_B.FromWorkspace, &parm);
    }
  }

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) lab_1_P.AnalogInput_RangeMode;
    parm.rangeidx = lab_1_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &lab_1_P.AnalogInput_Channels,
                   &lab_1_B.AnalogInput, &parm);
  }

  /* S-Function Block: <Root>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) lab_1_P.AnalogInput1_RangeMode;
    parm.rangeidx = lab_1_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &lab_1_P.AnalogInput1_Channels,
                   &lab_1_B.AnalogInput1, &parm);
  }
}

/* Model update function */
void lab_1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab_1_M->Timing.clockTick0)) {
    ++lab_1_M->Timing.clockTickH0;
  }

  lab_1_M->Timing.t[0] = lab_1_M->Timing.clockTick0 * lab_1_M->Timing.stepSize0
    + lab_1_M->Timing.clockTickH0 * lab_1_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++lab_1_M->Timing.clockTick1)) {
      ++lab_1_M->Timing.clockTickH1;
    }

    lab_1_M->Timing.t[1] = lab_1_M->Timing.clockTick1 *
      lab_1_M->Timing.stepSize1 + lab_1_M->Timing.clockTickH1 *
      lab_1_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void lab_1_initialize(void)
{
  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.02, 0.04, 0.06, 0.08, 0.1,
      0.12000000000000001, 0.13999999999999999, 0.16, 0.18, 0.19999999999999998,
      0.22, 0.24, 0.26, 0.28, 0.30000000000000004, 0.32, 0.34,
      0.36000000000000004, 0.38, 0.4, 0.42000000000000004, 0.44, 0.46,
      0.48000000000000004, 0.5, 0.52, 0.54, 0.56, 0.58000000000000007, 0.6, 0.62,
      0.64, 0.66, 0.68, 0.70000000000000007, 0.72000000000000008, 0.74, 0.76,
      0.78, 0.8, 0.82000000000000006, 0.84000000000000008, 0.86, 0.88, 0.9, 0.92,
      0.94000000000000006, 0.96000000000000008, 0.98, 1.0, 1.02, 1.04, 1.06,
      1.08, 1.1, 1.12, 1.1400000000000001, 1.1600000000000001, 1.18, 1.2, 1.22,
      1.24, 1.26, 1.28, 1.3, 1.32, 1.34, 1.36, 1.3800000000000001,
      1.4000000000000001, 1.4200000000000002, 1.44, 1.46, 1.48, 1.5, 1.52, 1.54,
      1.56, 1.58, 1.6, 1.62, 1.6400000000000001, 1.6600000000000001,
      1.6800000000000002, 1.7, 1.72, 1.74, 1.76, 1.78, 1.8, 1.82, 1.84, 1.86,
      1.8800000000000001, 1.9000000000000001, 1.9200000000000002, 1.94, 1.96,
      1.98, 2.0, 2.02, 2.04, 2.06, 2.08, 2.1, 2.12, 2.14, 2.16, 2.18, 2.2, 2.22,
      2.24, 2.2600000000000002, 2.2800000000000002, 2.3000000000000003,
      2.3200000000000003, 2.34, 2.36, 2.38, 2.4, 2.42, 2.44, 2.46, 2.48, 2.5,
      2.52, 2.54, 2.56, 2.58, 2.6, 2.62, 2.64, 2.66, 2.68, 2.7, 2.72, 2.74,
      2.7600000000000002, 2.7800000000000002, 2.8000000000000003,
      2.8200000000000003, 2.84, 2.86, 2.88, 2.9, 2.92, 2.94, 2.96, 2.98, 3.0,
      3.02, 3.04, 3.06, 3.08, 3.1, 3.12, 3.14, 3.16, 3.18, 3.2, 3.22, 3.24,
      3.2600000000000002, 3.2800000000000002, 3.3000000000000003,
      3.3200000000000003, 3.3400000000000003, 3.36, 3.38, 3.4, 3.42, 3.44, 3.46,
      3.48, 3.5, 3.52, 3.54, 3.56, 3.58, 3.6, 3.62, 3.64, 3.66, 3.68, 3.7, 3.72,
      3.74, 3.7600000000000002, 3.7800000000000002, 3.8000000000000003,
      3.8200000000000003, 3.8400000000000003, 3.86, 3.88, 3.9, 3.92, 3.94, 3.96,
      3.98, 4.0, 4.02, 4.04, 4.06, 4.08, 4.1, 4.1199999999999992, 4.14,
      4.1599999999999993, 4.18, 4.1999999999999993, 4.22, 4.2399999999999993,
      4.26, 4.2799999999999994, 4.3, 4.3199999999999994, 4.34,
      4.3599999999999994, 4.38, 4.3999999999999995, 4.42, 4.4399999999999995,
      4.46, 4.4799999999999995, 4.5, 4.52, 4.54, 4.56, 4.58, 4.6, 4.62, 4.64,
      4.6599999999999993, 4.68, 4.6999999999999993, 4.72, 4.7399999999999993,
      4.76, 4.7799999999999994, 4.8, 4.8199999999999994, 4.84,
      4.8599999999999994, 4.88, 4.8999999999999995, 4.92, 4.9399999999999995,
      4.96, 4.9799999999999995, 5.0, 5.02, 5.04, 5.06, 5.08, 5.1, 5.12, 5.14,
      5.1599999999999993, 5.18, 5.1999999999999993, 5.22, 5.2399999999999993,
      5.26, 5.2799999999999994, 5.3, 5.3199999999999994, 5.34,
      5.3599999999999994, 5.38, 5.3999999999999995, 5.42, 5.4399999999999995,
      5.46, 5.4799999999999995, 5.5, 5.52, 5.54, 5.56, 5.58, 5.6, 5.62, 5.64,
      5.6599999999999993, 5.68, 5.6999999999999993, 5.72, 5.7399999999999993,
      5.76, 5.7799999999999994, 5.8, 5.8199999999999994, 5.84,
      5.8599999999999994, 5.88, 5.8999999999999995, 5.92, 5.9399999999999995,
      5.96, 5.9799999999999995, 6.0, 6.02, 6.04, 6.06, 6.08, 6.1, 6.12, 6.14,
      6.16, 6.18, 6.1999999999999993, 6.22, 6.2399999999999993, 6.26,
      6.2799999999999994, 6.3, 6.3199999999999994, 6.34, 6.3599999999999994,
      6.38, 6.3999999999999995, 6.42, 6.4399999999999995, 6.46,
      6.4799999999999995, 6.5, 6.52, 6.54, 6.56, 6.58, 6.6, 6.62, 6.64, 6.66,
      6.68, 6.6999999999999993, 6.72, 6.7399999999999993, 6.76,
      6.7799999999999994, 6.8, 6.8199999999999994, 6.84, 6.8599999999999994,
      6.88, 6.8999999999999995, 6.92, 6.9399999999999995, 6.96,
      6.9799999999999995, 7.0, 7.02, 7.04, 7.06, 7.08, 7.1, 7.12, 7.14, 7.16,
      7.18, 7.1999999999999993, 7.22, 7.2399999999999993, 7.26,
      7.2799999999999994, 7.3, 7.3199999999999994, 7.34, 7.3599999999999994,
      7.38, 7.3999999999999995, 7.42, 7.4399999999999995, 7.46,
      7.4799999999999995, 7.5, 7.52, 7.54, 7.56, 7.58, 7.6, 7.62, 7.64, 7.66,
      7.68, 7.6999999999999993, 7.72, 7.7399999999999993, 7.76,
      7.7799999999999994, 7.8, 7.8199999999999994, 7.84, 7.8599999999999994,
      7.88, 7.8999999999999995, 7.92, 7.9399999999999995, 7.96,
      7.9799999999999995, 8.0, 8.02, 8.04, 8.06, 8.08, 8.1, 8.12, 8.14, 8.16,
      8.18, 8.2, 8.2199999999999989, 8.24, 8.26, 8.28, 8.2999999999999989, 8.32,
      8.34, 8.36, 8.379999999999999, 8.4, 8.42, 8.44, 8.4599999999999991, 8.48,
      8.5, 8.52, 8.54, 8.56, 8.58, 8.6, 8.62, 8.64, 8.66, 8.68, 8.7, 8.72, 8.74,
      8.76, 8.78, 8.7999999999999989, 8.82, 8.84, 8.86, 8.879999999999999, 8.9,
      8.92, 8.94, 8.9599999999999991, 8.98, 9.0, 9.02, 9.04, 9.06, 9.08, 9.1,
      9.12, 9.14, 9.16, 9.18, 9.2, 9.22, 9.24, 9.26, 9.28, 9.2999999999999989,
      9.32, 9.34, 9.36, 9.379999999999999, 9.4, 9.42, 9.44, 9.4599999999999991,
      9.48, 9.5, 9.52, 9.54, 9.56, 9.58, 9.6, 9.62, 9.64, 9.66, 9.68, 9.7, 9.72,
      9.74, 9.76, 9.78, 9.7999999999999989, 9.82, 9.84, 9.86, 9.879999999999999,
      9.9, 9.92, 9.94, 9.9599999999999991, 9.98, 10.0, 10.02, 10.04, 10.06,
      10.08, 10.1, 10.12, 10.14, 10.16, 10.18, 10.2, 10.22, 10.24, 10.26, 10.28,
      10.299999999999999, 10.32, 10.34, 10.36, 10.379999999999999, 10.4, 10.42,
      10.44, 10.459999999999999, 10.48, 10.5, 10.52, 10.54, 10.56, 10.58, 10.6,
      10.62, 10.64, 10.66, 10.68, 10.7, 10.72, 10.74, 10.76, 10.78,
      10.799999999999999, 10.82, 10.84, 10.86, 10.879999999999999, 10.9, 10.92,
      10.94, 10.959999999999999, 10.98, 11.0, 11.02, 11.04, 11.06, 11.08, 11.1,
      11.12, 11.14, 11.16, 11.18, 11.2, 11.22, 11.24, 11.26, 11.28,
      11.299999999999999, 11.32, 11.34, 11.36, 11.379999999999999, 11.4, 11.42,
      11.44, 11.459999999999999, 11.48, 11.5, 11.52, 11.54, 11.56, 11.58, 11.6,
      11.62, 11.64, 11.66, 11.68, 11.7, 11.72, 11.74, 11.76, 11.78, 11.8, 11.82,
      11.84, 11.86, 11.879999999999999, 11.9, 11.92, 11.94, 11.959999999999999,
      11.98, 12.0, 12.02, 12.04, 12.059999999999999, 12.08, 12.1,
      12.120000000000001, 12.14, 12.16, 12.18, 12.2, 12.219999999999999, 12.24,
      12.26, 12.280000000000001, 12.3, 12.32, 12.34, 12.36, 12.379999999999999,
      12.399999999999999, 12.42, 12.44, 12.46, 12.48, 12.5, 12.52, 12.54,
      12.559999999999999, 12.58, 12.6, 12.620000000000001, 12.64, 12.66, 12.68,
      12.7, 12.719999999999999, 12.74, 12.76, 12.780000000000001, 12.8, 12.82,
      12.84, 12.86, 12.879999999999999, 12.899999999999999, 12.92, 12.94, 12.96,
      12.98, 13.0, 13.02, 13.04, 13.059999999999999, 13.08, 13.1,
      13.120000000000001, 13.14, 13.16, 13.18, 13.2, 13.219999999999999, 13.24,
      13.26, 13.280000000000001, 13.3, 13.32, 13.34, 13.36, 13.379999999999999,
      13.399999999999999, 13.42, 13.44, 13.46, 13.48, 13.5, 13.52, 13.54,
      13.559999999999999, 13.58, 13.6, 13.620000000000001, 13.64, 13.66, 13.68,
      13.7, 13.719999999999999, 13.74, 13.76, 13.780000000000001, 13.8, 13.82,
      13.84, 13.86, 13.879999999999999, 13.899999999999999, 13.92, 13.94, 13.96,
      13.98, 14.0, 14.02, 14.04, 14.059999999999999, 14.08, 14.1,
      14.120000000000001, 14.14, 14.16, 14.18, 14.2, 14.219999999999999, 14.24,
      14.26, 14.280000000000001, 14.3, 14.32, 14.34, 14.36, 14.379999999999999,
      14.399999999999999, 14.42, 14.44, 14.46, 14.48, 14.5, 14.52, 14.54,
      14.559999999999999, 14.58, 14.6, 14.620000000000001, 14.64, 14.66, 14.68,
      14.7, 14.719999999999999, 14.74, 14.76, 14.780000000000001, 14.8, 14.82,
      14.84, 14.86, 14.879999999999999, 14.899999999999999, 14.92, 14.94, 14.96,
      14.98, 15.0, 15.02, 15.04, 15.059999999999999, 15.08, 15.1,
      15.120000000000001, 15.14, 15.16, 15.18, 15.2, 15.219999999999999, 15.24,
      15.26, 15.280000000000001, 15.3, 15.32, 15.34, 15.36, 15.379999999999999,
      15.399999999999999, 15.42, 15.44, 15.46, 15.48, 15.5, 15.52, 15.54,
      15.559999999999999, 15.58, 15.6, 15.620000000000001, 15.64, 15.66, 15.68,
      15.7, 15.719999999999999, 15.74, 15.76, 15.780000000000001, 15.8, 15.82,
      15.84, 15.86, 15.879999999999999, 15.9, 15.92, 15.94, 15.96, 15.98, 16.0,
      16.02, 16.04, 16.06, 16.08, 16.1, 16.12, 16.14, 16.16, 16.18, 16.2, 16.22,
      16.24, 16.259999999999998, 16.28, 16.3, 16.32, 16.34, 16.36, 16.38, 16.4,
      16.42, 16.44, 16.46, 16.48, 16.5, 16.52, 16.54, 16.56, 16.58, 16.6, 16.62,
      16.64, 16.66, 16.68, 16.7, 16.72, 16.74, 16.759999999999998, 16.78, 16.8,
      16.82, 16.84, 16.86, 16.88, 16.9, 16.92, 16.94, 16.96, 16.98, 17.0, 17.02,
      17.04, 17.06, 17.08, 17.1, 17.12, 17.14, 17.16, 17.18, 17.2, 17.22, 17.24,
      17.259999999999998, 17.28, 17.3, 17.32, 17.34, 17.36, 17.38, 17.4, 17.42,
      17.44, 17.46, 17.48, 17.5, 17.52, 17.54, 17.56, 17.58, 17.6, 17.62, 17.64,
      17.66, 17.68, 17.7, 17.72, 17.74, 17.759999999999998, 17.78, 17.8, 17.82,
      17.84, 17.86, 17.88, 17.9, 17.92, 17.94, 17.96, 17.98, 18.0, 18.02, 18.04,
      18.06, 18.08, 18.1, 18.12, 18.14, 18.16, 18.18, 18.2, 18.22, 18.24, 18.26,
      18.28, 18.3, 18.32, 18.34, 18.36, 18.38, 18.4, 18.42, 18.44, 18.46, 18.48,
      18.5, 18.52, 18.54, 18.56, 18.58, 18.6, 18.62, 18.64, 18.66, 18.68, 18.7,
      18.72, 18.74, 18.76, 18.78, 18.8, 18.82, 18.84, 18.86, 18.88, 18.9, 18.92,
      18.94, 18.96, 18.98, 19.0, 19.02, 19.04, 19.06, 19.08, 19.1, 19.12, 19.14,
      19.16, 19.18, 19.2, 19.22, 19.24, 19.26, 19.28, 19.3, 19.32, 19.34, 19.36,
      19.38, 19.4, 19.42, 19.44, 19.46, 19.48, 19.5, 19.52, 19.54, 19.56, 19.58,
      19.6, 19.62, 19.64, 19.66, 19.68, 19.7, 19.72, 19.74, 19.76, 19.78, 19.8,
      19.82, 19.84, 19.86, 19.88, 19.9, 19.92, 19.94, 19.96, 19.98, 20.0 } ;

    static real_T pDataValues0[] = { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0 } ;

    lab_1_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    lab_1_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    lab_1_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab_1_P.AnalogOutput_Channels,
                     &lab_1_P.AnalogOutput_InitialValue, &parm);
    }
  }
}

/* Model terminate function */
void lab_1_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab_1_P.AnalogOutput_Channels,
                     &lab_1_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  lab_1_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab_1_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  lab_1_initialize();
}

void MdlTerminate(void)
{
  lab_1_terminate();
}

/* Registration function */
RT_MODEL_lab_1_T *lab_1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab_1_M, 0,
                sizeof(RT_MODEL_lab_1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab_1_M->solverInfo, &lab_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab_1_M->solverInfo, &rtmGetTPtr(lab_1_M));
    rtsiSetStepSizePtr(&lab_1_M->solverInfo, &lab_1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&lab_1_M->solverInfo, (&rtmGetErrorStatus(lab_1_M)));
    rtsiSetRTModelPtr(&lab_1_M->solverInfo, lab_1_M);
  }

  rtsiSetSimTimeStep(&lab_1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&lab_1_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab_1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab_1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab_1_M->Timing.sampleTimes = (&lab_1_M->Timing.sampleTimesArray[0]);
    lab_1_M->Timing.offsetTimes = (&lab_1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab_1_M->Timing.sampleTimes[0] = (0.0);
    lab_1_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    lab_1_M->Timing.offsetTimes[0] = (0.0);
    lab_1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab_1_M, &lab_1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab_1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab_1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab_1_M, 20.0);
  lab_1_M->Timing.stepSize0 = 0.02;
  lab_1_M->Timing.stepSize1 = 0.02;

  /* External mode info */
  lab_1_M->Sizes.checksums[0] = (3109579007U);
  lab_1_M->Sizes.checksums[1] = (4035891963U);
  lab_1_M->Sizes.checksums[2] = (786928964U);
  lab_1_M->Sizes.checksums[3] = (1341728592U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab_1_M->extModeInfo,
      &lab_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab_1_M->extModeInfo, lab_1_M->Sizes.checksums);
    rteiSetTPtr(lab_1_M->extModeInfo, rtmGetTPtr(lab_1_M));
  }

  lab_1_M->solverInfoPtr = (&lab_1_M->solverInfo);
  lab_1_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&lab_1_M->solverInfo, 0.02);
  rtsiSetSolverMode(&lab_1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab_1_M->ModelData.blockIO = ((void *) &lab_1_B);
  (void) memset(((void *) &lab_1_B), 0,
                sizeof(B_lab_1_T));

  /* parameters */
  lab_1_M->ModelData.defaultParam = ((real_T *)&lab_1_P);

  /* states (dwork) */
  lab_1_M->ModelData.dwork = ((void *) &lab_1_DW);
  (void) memset((void *)&lab_1_DW, 0,
                sizeof(DW_lab_1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab_1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab_1_M->Sizes.numContStates = (0);  /* Number of continuous states */
  lab_1_M->Sizes.numY = (0);           /* Number of model outputs */
  lab_1_M->Sizes.numU = (0);           /* Number of model inputs */
  lab_1_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  lab_1_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  lab_1_M->Sizes.numBlocks = (7);      /* Number of blocks */
  lab_1_M->Sizes.numBlockIO = (3);     /* Number of block outputs */
  lab_1_M->Sizes.numBlockPrms = (17);  /* Sum of parameter "widths" */
  return lab_1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
