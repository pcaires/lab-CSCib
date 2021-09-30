/*
 * lab_1.c
 *
 * Code generation for model "lab_1".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Sep 30 13:12:03 2021
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
  real_T currentTime;

  /* Step: '<Root>/Step' */
  currentTime = lab_1_M->Timing.t[0];
  if (currentTime < lab_1_P.Step_Time) {
    lab_1_B.Step = lab_1_P.Step_Y0;
  } else {
    lab_1_B.Step = lab_1_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) lab_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = lab_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &lab_1_P.AnalogOutput_Channels,
                     &lab_1_B.Step, &parm);
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

  rtmSetTFinal(lab_1_M, 1.0);
  lab_1_M->Timing.stepSize0 = 0.02;
  lab_1_M->Timing.stepSize1 = 0.02;

  /* External mode info */
  lab_1_M->Sizes.checksums[0] = (1857537430U);
  lab_1_M->Sizes.checksums[1] = (4045224934U);
  lab_1_M->Sizes.checksums[2] = (3584197095U);
  lab_1_M->Sizes.checksums[3] = (2695737935U);

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
  lab_1_M->Sizes.numBlockPrms = (20);  /* Sum of parameter "widths" */
  return lab_1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
