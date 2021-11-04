/*
 * lab2.c
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
#include "lab2_dt.h"

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

const real_T lab2_RGND = 0.0;          /* real_T ground */

/* Block signals (auto storage) */
B_lab2_T lab2_B;

/* Block states (auto storage) */
DW_lab2_T lab2_DW;

/* Real-time model */
RT_MODEL_lab2_T lab2_M_;
RT_MODEL_lab2_T *const lab2_M = &lab2_M_;

/* Model output function */
void lab2_output(void)
{
  real_T rtb_Sum1[6];
  real_T rtb_Sum;
  int32_T i;
  real_T tmp;
  int32_T i_0;
  real_T rtb_Sum1_n;

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab2_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab2_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab2_P.AnalogOutput_Channels,
                     (real_T*)&lab2_RGND, &parm);
    }
  }

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) lab2_P.AnalogInput_RangeMode;
    parm.rangeidx = lab2_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &lab2_P.AnalogInput_Channels,
                   &lab2_B.AnalogInput, &parm);
  }

  /* S-Function Block: <Root>/Analog Input1 */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) lab2_P.AnalogInput1_RangeMode;
    parm.rangeidx = lab2_P.AnalogInput1_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &lab2_P.AnalogInput1_Channels,
                   &lab2_B.AnalogInput1, &parm);
  }

  /* DiscreteStateSpace: '<Root>/Discrete State-Space' */
  lab2_B.DiscreteStateSpace = 0.0;
  for (i = 0; i < 6; i++) {
    lab2_B.DiscreteStateSpace += lab2_P.C[i] *
      lab2_DW.DiscreteStateSpace_DSTATE[i];
  }

  /* End of DiscreteStateSpace: '<Root>/Discrete State-Space' */

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_Sum = lab2_P.SignalGenerator_Frequency * lab2_M->Timing.t[0];
  if (rtb_Sum - floor(rtb_Sum) >= 0.5) {
    lab2_B.SignalGenerator = lab2_P.SignalGenerator_Amplitude;
  } else {
    lab2_B.SignalGenerator = -lab2_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<S1>/Gain3' incorporates:
   *  Delay: '<S1>/Delay'
   */
  tmp = 0.0;
  for (i = 0; i < 6; i++) {
    tmp += -lab2_P.C[i] * lab2_DW.Delay_DSTATE[i];
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain3'
   */
  rtb_Sum = tmp + lab2_B.DiscreteStateSpace;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Sum: '<S1>/Sum1'
   */
  tmp = 0.0;
  for (i = 0; i < 6; i++) {
    /* Sum: '<S1>/Sum1' incorporates:
     *  Delay: '<S1>/Delay'
     *  Gain: '<S1>/Gain4'
     */
    rtb_Sum1_n = lab2_P.M[i] * rtb_Sum + lab2_DW.Delay_DSTATE[i];
    tmp += lab2_P.C[i] * rtb_Sum1_n;
    rtb_Sum1[i] = rtb_Sum1_n;
  }

  lab2_B.Gain2 = tmp;

  /* End of Gain: '<Root>/Gain2' */

  /* Gain: '<Root>/Gain1' */
  tmp = 0.0;
  for (i = 0; i < 6; i++) {
    /* Gain: '<Root>/Gain1' */
    tmp += -lab2_P.K[i] * rtb_Sum1[i];

    /* Gain: '<S1>/Gain5' */
    lab2_B.Gain5[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      lab2_B.Gain5[i] += lab2_P.A[6 * i_0 + i] * rtb_Sum1[i_0];
    }

    /* End of Gain: '<S1>/Gain5' */
  }

  /* Gain: '<Root>/Gain1' */
  lab2_B.Gain1 = tmp;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/Gain'
   */
  lab2_B.Sum3 = lab2_P.Nbar * lab2_B.SignalGenerator + lab2_B.Gain1;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/Gain2'
   */
  for (i = 0; i < 6; i++) {
    lab2_B.Sum2[i] = lab2_P.B[i] * lab2_B.Sum3 + lab2_B.Gain5[i];
  }

  /* End of Sum: '<S1>/Sum2' */
}

/* Model update function */
void lab2_update(void)
{
  int_T i;
  int_T j;
  real_T xnew[6];

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space' */
  for (i = 0; i < 6; i++) {
    xnew[i] = 0.0;
    for (j = 0; j < 6; j++) {
      xnew[i] += lab2_P.A[6 * j + i] * lab2_DW.DiscreteStateSpace_DSTATE[j];
    }

    xnew[i] += lab2_P.B[i] * lab2_B.Sum3;
  }

  for (i = 0; i < 6; i++) {
    /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space' */
    lab2_DW.DiscreteStateSpace_DSTATE[i] = xnew[i];

    /* Update for Delay: '<S1>/Delay' */
    lab2_DW.Delay_DSTATE[i] = lab2_B.Sum2[i];
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab2_M->Timing.clockTick0)) {
    ++lab2_M->Timing.clockTickH0;
  }

  lab2_M->Timing.t[0] = lab2_M->Timing.clockTick0 * lab2_M->Timing.stepSize0 +
    lab2_M->Timing.clockTickH0 * lab2_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++lab2_M->Timing.clockTick1)) {
      ++lab2_M->Timing.clockTickH1;
    }

    lab2_M->Timing.t[1] = lab2_M->Timing.clockTick1 * lab2_M->Timing.stepSize1 +
      lab2_M->Timing.clockTickH1 * lab2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void lab2_initialize(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab2_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab2_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab2_P.AnalogOutput_Channels,
                     &lab2_P.AnalogOutput_InitialValue, &parm);
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space' */
      lab2_DW.DiscreteStateSpace_DSTATE[i] = lab2_P.DiscreteStateSpace_X0;

      /* InitializeConditions for Delay: '<S1>/Delay' */
      lab2_DW.Delay_DSTATE[i] = lab2_P.Delay_InitialCondition;
    }
  }
}

/* Model terminate function */
void lab2_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab2_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab2_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab2_P.AnalogOutput_Channels,
                     &lab2_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  lab2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lab2_update();
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
  lab2_initialize();
}

void MdlTerminate(void)
{
  lab2_terminate();
}

/* Registration function */
RT_MODEL_lab2_T *lab2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lab2_M, 0,
                sizeof(RT_MODEL_lab2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&lab2_M->solverInfo, &lab2_M->Timing.simTimeStep);
    rtsiSetTPtr(&lab2_M->solverInfo, &rtmGetTPtr(lab2_M));
    rtsiSetStepSizePtr(&lab2_M->solverInfo, &lab2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&lab2_M->solverInfo, (&rtmGetErrorStatus(lab2_M)));
    rtsiSetRTModelPtr(&lab2_M->solverInfo, lab2_M);
  }

  rtsiSetSimTimeStep(&lab2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&lab2_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lab2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    lab2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab2_M->Timing.sampleTimes = (&lab2_M->Timing.sampleTimesArray[0]);
    lab2_M->Timing.offsetTimes = (&lab2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab2_M->Timing.sampleTimes[0] = (0.0);
    lab2_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    lab2_M->Timing.offsetTimes[0] = (0.0);
    lab2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(lab2_M, &lab2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    lab2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab2_M, 20.0);
  lab2_M->Timing.stepSize0 = 0.02;
  lab2_M->Timing.stepSize1 = 0.02;

  /* External mode info */
  lab2_M->Sizes.checksums[0] = (2668036084U);
  lab2_M->Sizes.checksums[1] = (1534880569U);
  lab2_M->Sizes.checksums[2] = (910442074U);
  lab2_M->Sizes.checksums[3] = (2107450028U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    lab2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(lab2_M->extModeInfo,
      &lab2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(lab2_M->extModeInfo, lab2_M->Sizes.checksums);
    rteiSetTPtr(lab2_M->extModeInfo, rtmGetTPtr(lab2_M));
  }

  lab2_M->solverInfoPtr = (&lab2_M->solverInfo);
  lab2_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&lab2_M->solverInfo, 0.02);
  rtsiSetSolverMode(&lab2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lab2_M->ModelData.blockIO = ((void *) &lab2_B);
  (void) memset(((void *) &lab2_B), 0,
                sizeof(B_lab2_T));

  /* parameters */
  lab2_M->ModelData.defaultParam = ((real_T *)&lab2_P);

  /* states (dwork) */
  lab2_M->ModelData.dwork = ((void *) &lab2_DW);
  (void) memset((void *)&lab2_DW, 0,
                sizeof(DW_lab2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    lab2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  lab2_M->Sizes.numContStates = (0);   /* Number of continuous states */
  lab2_M->Sizes.numY = (0);            /* Number of model outputs */
  lab2_M->Sizes.numU = (0);            /* Number of model inputs */
  lab2_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  lab2_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  lab2_M->Sizes.numBlocks = (23);      /* Number of blocks */
  lab2_M->Sizes.numBlockIO = (9);      /* Number of block outputs */
  lab2_M->Sizes.numBlockPrms = (84);   /* Sum of parameter "widths" */
  return lab2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
