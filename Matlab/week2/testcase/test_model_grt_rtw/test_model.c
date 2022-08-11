/*
 * test_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "test_model".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sat Aug 21 21:35:16 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_model.h"
#include "test_model_private.h"

/* Block signals (default storage) */
B_test_model_T test_model_B;

/* Real-time model */
static RT_MODEL_test_model_T test_model_M_;
RT_MODEL_test_model_T *const test_model_M = &test_model_M_;

/* Forward declaration for local functions */
static real_T test_model_det(const real_T x[16]);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test_model_M->Timing.TaskCounters.TID[2])++;
  if ((test_model_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [1.0s, 0.0s] */
    test_model_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T test_model_det(const real_T x[16])
{
  real_T A[16];
  real_T b_y;
  real_T smax;
  real_T y;
  int32_T c;
  int32_T c_ix;
  int32_T c_k;
  int32_T d;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int8_T ipiv[4];
  boolean_T isodd;
  memcpy(&A[0], &x[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    iy = 0;
    ix = c;
    smax = fabs(A[c]);
    for (c_k = 2; c_k <= 4 - j; c_k++) {
      ix++;
      b_y = fabs(A[ix]);
      if (b_y > smax) {
        iy = c_k - 1;
        smax = b_y;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        smax = A[j];
        A[j] = A[iy];
        A[iy] = smax;
        smax = A[j + 4];
        A[j + 4] = A[iy + 4];
        A[iy + 4] = smax;
        smax = A[j + 8];
        A[j + 8] = A[iy + 8];
        A[iy + 8] = smax;
        smax = A[j + 12];
        A[j + 12] = A[iy + 12];
        A[iy + 12] = smax;
      }

      iy = (c - j) + 4;
      for (ix = c + 1; ix < iy; ix++) {
        A[ix] /= A[c];
      }
    }

    iy = c;
    ix = c + 4;
    for (c_k = 0; c_k <= 2 - j; c_k++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = c + 1;
        d = (iy - j) + 8;
        for (ijA = iy + 5; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  isodd = (ipiv[0] > 1);
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }

  y = A[0] * A[5] * A[10] * A[15];
  if (ipiv[2] > 3) {
    isodd = !isodd;
  }

  if (isodd) {
    y = -y;
  }

  return y;
}

/* Model step function */
void test_model_step(void)
{
  real_T A[16];
  real_T ac0[16];
  real_T ac1[16];
  real_T ac2[16];
  real_T ac3[16];
  real_T A_tmp;
  real_T A_tmp_0;
  real_T rtb_time;
  int32_T i;

  /* Clock: '<S1>/Clock1' */
  rtb_time = test_model_M->Timing.t[0];
  if (test_model_M->Timing.TaskCounters.TID[2] == 0) {
    /* Constant: '<S1>/t_f1' */
    test_model_B.t_f = test_model_P.t_f1_Value;

    /* Constant: '<S1>/t_i1' */
    test_model_B.t_i = test_model_P.t_i1_Value;
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/q_f1'
   *  Constant: '<S1>/q_i1'
   */
  A[0] = 1.0;
  A[4] = test_model_B.t_i;
  A_tmp = test_model_B.t_i * test_model_B.t_i;
  A[8] = A_tmp;
  A[12] = rt_powd_snf(test_model_B.t_i, 3.0);
  A[1] = 1.0;
  A[5] = test_model_B.t_f;
  A_tmp_0 = test_model_B.t_f * test_model_B.t_f;
  A[9] = A_tmp_0;
  A[13] = rt_powd_snf(test_model_B.t_f, 3.0);
  A[2] = 0.0;
  A[6] = 1.0;
  A[10] = 2.0 * test_model_B.t_i;
  A[14] = A_tmp * 3.0;
  A[3] = 0.0;
  A[7] = 1.0;
  A[11] = 2.0 * test_model_B.t_f;
  A[15] = A_tmp_0 * 3.0;
  for (i = 0; i < 16; i++) {
    A_tmp = A[i];
    ac0[i] = A_tmp;
    ac1[i] = A_tmp;
    ac2[i] = A_tmp;
    ac3[i] = A_tmp;
  }

  ac0[0] = test_model_P.q_i1_Value;
  ac0[1] = test_model_P.q_f1_Value;
  ac0[2] = 0.0;
  ac0[3] = 0.0;
  ac1[4] = test_model_P.q_i1_Value;
  ac1[5] = test_model_P.q_f1_Value;
  ac1[6] = 0.0;
  ac1[7] = 0.0;
  ac2[8] = test_model_P.q_i1_Value;
  ac2[9] = test_model_P.q_f1_Value;
  ac2[10] = 0.0;
  ac2[11] = 0.0;
  ac3[12] = test_model_P.q_i1_Value;
  ac3[13] = test_model_P.q_f1_Value;
  ac3[14] = 0.0;
  ac3[15] = 0.0;
  A_tmp = test_model_det(A);
  test_model_B.c[0] = test_model_det(ac3) / A_tmp;
  test_model_B.c[1] = test_model_det(ac2) / A_tmp;
  test_model_B.c[2] = test_model_det(ac1) / A_tmp;
  test_model_B.c[3] = test_model_det(ac0) / A_tmp;

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Switch: '<S1>/Switch2' incorporates:
   *  RelationalOperator: '<S1>/Relational Operator'
   *  RelationalOperator: '<S1>/Relational Operator1'
   *  Switch: '<S1>/Switch1'
   */
  if (rtb_time > test_model_B.t_f) {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/q_f1'
     */
    test_model_B.Switch2 = test_model_P.q_f1_Value;
  } else if (rtb_time < test_model_B.t_i) {
    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<S1>/q_i1'
     *  Switch: '<S1>/Switch1'
     */
    test_model_B.Switch2 = test_model_P.q_i1_Value;
  } else {
    /* S-Function (sdsppolyval2): '<S1>/Polynomial Evaluation' incorporates:
     *  Switch: '<S1>/Switch1'
     */
    test_model_B.gt = ((test_model_B.c[0] * rtb_time + test_model_B.c[1]) *
                       rtb_time + test_model_B.c[2]) * rtb_time +
      test_model_B.c[3];

    /* Switch: '<S1>/Switch2' incorporates:
     *  Switch: '<S1>/Switch1'
     */
    test_model_B.Switch2 = test_model_B.gt;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(test_model_M->rtwLogInfo, (test_model_M->Timing.t));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(test_model_M)!=-1) &&
        !((rtmGetTFinal(test_model_M)-test_model_M->Timing.t[0]) >
          test_model_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_model_M, "Simulation finished");
    }
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
  if (!(++test_model_M->Timing.clockTick0)) {
    ++test_model_M->Timing.clockTickH0;
  }

  test_model_M->Timing.t[0] = test_model_M->Timing.clockTick0 *
    test_model_M->Timing.stepSize0 + test_model_M->Timing.clockTickH0 *
    test_model_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    test_model_M->Timing.clockTick1++;
    if (!test_model_M->Timing.clockTick1) {
      test_model_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void test_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_model_M, 0,
                sizeof(RT_MODEL_test_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test_model_M->solverInfo,
                          &test_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&test_model_M->solverInfo, &rtmGetTPtr(test_model_M));
    rtsiSetStepSizePtr(&test_model_M->solverInfo,
                       &test_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test_model_M->solverInfo, (&rtmGetErrorStatus
      (test_model_M)));
    rtsiSetRTModelPtr(&test_model_M->solverInfo, test_model_M);
  }

  rtsiSetSimTimeStep(&test_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&test_model_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(test_model_M, &test_model_M->Timing.tArray[0]);
  rtmSetTFinal(test_model_M, 18.0);
  test_model_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    test_model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(test_model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(test_model_M->rtwLogInfo, (NULL));
    rtliSetLogT(test_model_M->rtwLogInfo, "tout");
    rtliSetLogX(test_model_M->rtwLogInfo, "");
    rtliSetLogXFinal(test_model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(test_model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(test_model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(test_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(test_model_M->rtwLogInfo, 1);
    rtliSetLogY(test_model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(test_model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(test_model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &test_model_B), 0,
                sizeof(B_test_model_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(test_model_M->rtwLogInfo, 0.0, rtmGetTFinal
    (test_model_M), test_model_M->Timing.stepSize0, (&rtmGetErrorStatus
    (test_model_M)));

  /* Start for Constant: '<S1>/t_f1' */
  test_model_B.t_f = test_model_P.t_f1_Value;

  /* Start for Constant: '<S1>/t_i1' */
  test_model_B.t_i = test_model_P.t_i1_Value;
}

/* Model terminate function */
void test_model_terminate(void)
{
  /* (no terminate code required) */
}
