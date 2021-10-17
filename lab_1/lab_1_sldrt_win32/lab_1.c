/*
 * lab_1.c
 *
 * Code generation for model "lab_1".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Oct 14 12:02:21 2021
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
const int RTWinTimerCount = 2;
const double RTWinTimers[4] = {
  0.02, 0.0,
  0.5, 0.0,
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
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(lab_1_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(lab_1_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (lab_1_M->Timing.TaskCounters.TID[2])++;
  if ((lab_1_M->Timing.TaskCounters.TID[2]) > 24) {/* Sample time: [0.5s, 0.0s] */
    lab_1_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void lab_1_output0(void)               /* Sample time: [0.0s, 0.0s] */
{
  real_T temp;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = lab_1_P.SignalGenerator_Frequency * lab_1_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    lab_1_B.SignalGenerator = lab_1_P.SignalGenerator_Amplitude;
  } else {
    lab_1_B.SignalGenerator = -lab_1_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab_1_P.AnalogOutput_Channels,
                     &lab_1_B.SignalGenerator, &parm);
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

/* Model update function for TID0 */
void lab_1_update0(void)               /* Sample time: [0.0s, 0.0s] */
{
  /* Update absolute time */
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

  /* Update absolute time */
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

  lab_1_M->Timing.t[1] = lab_1_M->Timing.clockTick1 * lab_1_M->Timing.stepSize1
    + lab_1_M->Timing.clockTickH1 * lab_1_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
void lab_1_output2(void)               /* Sample time: [0.5s, 0.0s] */
{
  /* (no output code required) */
}

/* Model update function for TID2 */
void lab_1_update2(void)               /* Sample time: [0.5s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lab_1_M->Timing.clockTick2)) {
    ++lab_1_M->Timing.clockTickH2;
  }

  lab_1_M->Timing.t[2] = lab_1_M->Timing.clockTick2 * lab_1_M->Timing.stepSize2
    + lab_1_M->Timing.clockTickH2 * lab_1_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void lab_1_output(int_T tid)
{
  switch (tid) {
   case 0 :
    lab_1_output0();
    break;

   case 2 :
    lab_1_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void lab_1_update(int_T tid)
{
  switch (tid) {
   case 0 :
    lab_1_update0();
    break;

   case 2 :
    lab_1_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lab_1_initialize(void)
{
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
  if (tid == 1)
    tid = 0;
  lab_1_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  lab_1_update(tid);
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
    mdlTsMap[2] = 2;
    lab_1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lab_1_M->Timing.sampleTimes = (&lab_1_M->Timing.sampleTimesArray[0]);
    lab_1_M->Timing.offsetTimes = (&lab_1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lab_1_M->Timing.sampleTimes[0] = (0.0);
    lab_1_M->Timing.sampleTimes[1] = (0.02);
    lab_1_M->Timing.sampleTimes[2] = (0.5);

    /* task offsets */
    lab_1_M->Timing.offsetTimes[0] = (0.0);
    lab_1_M->Timing.offsetTimes[1] = (0.0);
    lab_1_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(lab_1_M, &lab_1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lab_1_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = lab_1_M->Timing.perTaskSampleHitsArray;
    lab_1_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    lab_1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lab_1_M, 20.0);
  lab_1_M->Timing.stepSize0 = 0.02;
  lab_1_M->Timing.stepSize1 = 0.02;
  lab_1_M->Timing.stepSize2 = 0.5;

  /* External mode info */
  lab_1_M->Sizes.checksums[0] = (3353435037U);
  lab_1_M->Sizes.checksums[1] = (3595329057U);
  lab_1_M->Sizes.checksums[2] = (2368430789U);
  lab_1_M->Sizes.checksums[3] = (1131888656U);

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
  rtsiSetSolverMode(&lab_1_M->solverInfo, SOLVER_MODE_MULTITASKING);

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
  lab_1_M->Sizes.numSampTimes = (3);   /* Number of sample times */
  lab_1_M->Sizes.numBlocks = (7);      /* Number of blocks */
  lab_1_M->Sizes.numBlockIO = (3);     /* Number of block outputs */
  lab_1_M->Sizes.numBlockPrms = (19);  /* Sum of parameter "widths" */
  return lab_1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
