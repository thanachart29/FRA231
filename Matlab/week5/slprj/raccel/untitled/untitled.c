#include "rt_logging_mmi.h"
#include "untitled_capi.h"
#include <math.h>
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlStart ( void ) { CXPtMax * _rtXPerturbMax ; CXPtMin *
_rtXPerturbMin ; NeModelParameters modelParameters ; NeModelParameters
modelParameters_p ; NeslSimulationData * simulationData ; NeslSimulator * tmp
; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree *
diagnosticTree ; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree *
diagnosticTree_p ; char * msg ; char * msg_e ; char * msg_p ; real_T tmp_m [
8 ] ; real_T time ; real_T tmp_e ; int32_T tmp_i ; int_T tmp_g [ 3 ] ;
boolean_T tmp_p ; boolean_T val ; { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} _rtXPerturbMax = ( ( CXPtMax * ) ssGetJacobianPerturbationBoundsMaxVec (
rtS ) ) ; _rtXPerturbMin = ( ( CXPtMin * )
ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ; tmp = nesl_lease_simulator
( "untitled/Solver Configuration1_1" , 0 , 0 ) ; rtDW . o2mwkdt5ya = ( void *
) tmp ; tmp_p = pointer_is_null ( rtDW . o2mwkdt5ya ) ; if ( tmp_p ) {
untitled_48324b08_1_gateway ( ) ; tmp = nesl_lease_simulator (
"untitled/Solver Configuration1_1" , 0 , 0 ) ; rtDW . o2mwkdt5ya = ( void * )
tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"untitled/Solver Configuration1_100" , ( void * * ) ( & rtDW . o2mwkdt5ya ) ,
0U * sizeof ( real_T ) , nesl_save_simdata , nesl_restore_simdata ) ;
simulationData = nesl_create_simulation_data ( ) ; rtDW . mqnpyike4n = ( void
* ) simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
mbe4pdfwl2 = ( void * ) diagnosticManager ; modelParameters . mSolverType =
NE_SOLVER_TYPE_DAE ; modelParameters . mSolverTolerance = 0.001 ;
modelParameters . mVariableStepSolver = true ; modelParameters . mIsUsingODEN
= false ; modelParameters . mFixedStepSize = 0.001 ; modelParameters .
mStartTime = 0.0 ; modelParameters . mLoadInitialState = false ;
modelParameters . mUseSimState = false ; modelParameters . mLinTrimCompile =
false ; modelParameters . mLoggingMode = SSC_LOGGING_NONE ; modelParameters .
mRTWModifiedTimeStamp = 5.58140918E+8 ; tmp_e = 0.001 ; modelParameters .
mSolverTolerance = tmp_e ; tmp_e = 0.0 ; modelParameters . mFixedStepSize =
tmp_e ; tmp_p = true ; modelParameters . mVariableStepSolver = tmp_p ; tmp_p
= false ; modelParameters . mIsUsingODEN = tmp_p ; val = false ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp_p ) { tmp_p =
ssGetGlobalInitialStatesAvailable ( rtS ) ; val = ( tmp_p &&
ssIsFirstInitCond ( rtS ) ) ; } modelParameters . mLoadInitialState = val ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . mbe4pdfwl2 ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . o2mwkdt5ya
, & modelParameters , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . mqnpyike4n ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 13 ;
simulationData -> mData -> mContStates . mX = & rtX . izv2gt4f3j [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . pdwwkimpfc ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
gptd1jty42 ; tmp_p = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS
) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp_p
; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
tmp_p = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp_p ; tmp_p =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp_p ; tmp_p = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp_p ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp_p = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp_p ; tmp_p = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp_p ; tmp_g [ 0 ] = 0 ;
tmp_m [ 0 ] = rtB . ieynslkjq3 [ 0 ] ; tmp_m [ 1 ] = rtB . ieynslkjq3 [ 1 ] ;
tmp_m [ 2 ] = rtB . ieynslkjq3 [ 2 ] ; tmp_m [ 3 ] = rtB . ieynslkjq3 [ 3 ] ;
tmp_g [ 1 ] = 4 ; tmp_m [ 4 ] = rtB . kji3dnoobq [ 0 ] ; tmp_m [ 5 ] = rtB .
kji3dnoobq [ 1 ] ; tmp_m [ 6 ] = rtB . kji3dnoobq [ 2 ] ; tmp_m [ 7 ] = rtB .
kji3dnoobq [ 3 ] ; tmp_g [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_g [ 0 ] ; simulationData -> mData ->
mNumjacDxLo . mN = 13 ; simulationData -> mData -> mNumjacDxLo . mX = &
_rtXPerturbMin -> izv2gt4f3j [ 0 ] ; simulationData -> mData -> mNumjacDxHi .
mN = 13 ; simulationData -> mData -> mNumjacDxHi . mX = & _rtXPerturbMax ->
izv2gt4f3j [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
mbe4pdfwl2 ; diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. o2mwkdt5ya , NESL_SIM_NUMJAC_DX_BOUNDS , simulationData , diagnosticManager
) ; if ( tmp_i != 0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus (
rtS ) ) ; if ( tmp_p ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } tmp = nesl_lease_simulator (
"untitled/Solver Configuration1_1" , 1 , 0 ) ; rtDW . aofv5yv5hq = ( void * )
tmp ; tmp_p = pointer_is_null ( rtDW . aofv5yv5hq ) ; if ( tmp_p ) {
untitled_48324b08_1_gateway ( ) ; tmp = nesl_lease_simulator (
"untitled/Solver Configuration1_1" , 1 , 0 ) ; rtDW . aofv5yv5hq = ( void * )
tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"untitled/Solver Configuration1_110" , ( void * * ) ( & rtDW . aofv5yv5hq ) ,
0U * sizeof ( real_T ) , nesl_save_simdata , nesl_restore_simdata ) ;
simulationData = nesl_create_simulation_data ( ) ; rtDW . ov4ulhkgil = ( void
* ) simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
oukxnbv2xn = ( void * ) diagnosticManager ; modelParameters_p . mSolverType =
NE_SOLVER_TYPE_DAE ; modelParameters_p . mSolverTolerance = 0.001 ;
modelParameters_p . mVariableStepSolver = true ; modelParameters_p .
mIsUsingODEN = false ; modelParameters_p . mFixedStepSize = 0.001 ;
modelParameters_p . mStartTime = 0.0 ; modelParameters_p . mLoadInitialState
= false ; modelParameters_p . mUseSimState = false ; modelParameters_p .
mLinTrimCompile = false ; modelParameters_p . mLoggingMode = SSC_LOGGING_NONE
; modelParameters_p . mRTWModifiedTimeStamp = 5.58140918E+8 ; tmp_e = 0.001 ;
modelParameters_p . mSolverTolerance = tmp_e ; tmp_e = 0.0 ;
modelParameters_p . mFixedStepSize = tmp_e ; tmp_p = true ; modelParameters_p
. mVariableStepSolver = tmp_p ; tmp_p = false ; modelParameters_p .
mIsUsingODEN = tmp_p ; val = false ; tmp_p = slIsRapidAcceleratorSimulating (
) ; if ( tmp_p ) { tmp_p = ssGetGlobalInitialStatesAvailable ( rtS ) ; val =
( tmp_p && ssIsFirstInitCond ( rtS ) ) ; } modelParameters_p .
mLoadInitialState = val ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW
. oukxnbv2xn ; diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . aofv5yv5hq , & modelParameters_p , diagnosticManager ) ; if ( tmp_i !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus ( rtS
, msg_e ) ; } } } void MdlOutputs ( int_T tid ) { NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; NeuDiagnosticTree * diagnosticTree_p ; char * msg ; char *
msg_p ; real_T tmp_m [ 21 ] ; real_T tmp_p [ 8 ] ; real_T time ; real_T
time_p ; int32_T tmp_i ; int_T tmp_g [ 4 ] ; int_T tmp_e [ 3 ] ; boolean_T
tmp ; simulationData = ( NeslSimulationData * ) rtDW . mqnpyike4n ; time =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 13 ; simulationData -> mData -> mContStates . mX = & rtX . izv2gt4f3j [ 0 ]
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = & rtDW . pdwwkimpfc ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
gptd1jty42 ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS )
-> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ieynslkjq3 [ 0 ] ; tmp_p [ 1 ] = rtB . ieynslkjq3 [ 1 ] ;
tmp_p [ 2 ] = rtB . ieynslkjq3 [ 2 ] ; tmp_p [ 3 ] = rtB . ieynslkjq3 [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . kji3dnoobq [ 0 ] ; tmp_p [ 5 ] = rtB .
kji3dnoobq [ 1 ] ; tmp_p [ 6 ] = rtB . kji3dnoobq [ 2 ] ; tmp_p [ 7 ] = rtB .
kji3dnoobq [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; simulationData -> mData -> mOutputs .
mN = 13 ; simulationData -> mData -> mOutputs . mX = & rtB . ewitn5xjqu [ 0 ]
; simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData
-> mSampleHits . mX = NULL ; simulationData -> mData ->
mIsFundamentalSampleHit = false ; simulationData -> mData -> mTolerances . mN
= 0 ; simulationData -> mData -> mTolerances . mX = NULL ; simulationData ->
mData -> mCstateHasChanged = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . mbe4pdfwl2 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . o2mwkdt5ya ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( ssIsMajorTimeStep ( rtS ) && simulationData -> mData ->
mCstateHasChanged ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
simulationData = ( NeslSimulationData * ) rtDW . ov4ulhkgil ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . mfl3kjtovu ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . cugokxgzzg ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp =
ssGetIsOkayToUpdateMode ( rtS ) ; simulationData -> mData ->
mIsOkayToUpdateMode = tmp ; tmp_g [ 0 ] = 0 ; tmp_m [ 0 ] = rtB . ieynslkjq3
[ 0 ] ; tmp_m [ 1 ] = rtB . ieynslkjq3 [ 1 ] ; tmp_m [ 2 ] = rtB . ieynslkjq3
[ 2 ] ; tmp_m [ 3 ] = rtB . ieynslkjq3 [ 3 ] ; tmp_g [ 1 ] = 4 ; tmp_m [ 4 ]
= rtB . kji3dnoobq [ 0 ] ; tmp_m [ 5 ] = rtB . kji3dnoobq [ 1 ] ; tmp_m [ 6 ]
= rtB . kji3dnoobq [ 2 ] ; tmp_m [ 7 ] = rtB . kji3dnoobq [ 3 ] ; tmp_g [ 2 ]
= 8 ; memcpy ( & tmp_m [ 8 ] , & rtB . ewitn5xjqu [ 0 ] , 13U * sizeof (
real_T ) ) ; tmp_g [ 3 ] = 21 ; simulationData -> mData -> mInputValues . mN
= 21 ; simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 4 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_g [ 0 ] ; simulationData -> mData -> mOutputs .
mN = 1 ; simulationData -> mData -> mOutputs . mX = & rtB . kqf2fs2t1y ;
simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData ->
mSampleHits . mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit
= false ; simulationData -> mData -> mTolerances . mN = 0 ; simulationData ->
mData -> mTolerances . mX = NULL ; simulationData -> mData ->
mCstateHasChanged = false ; diagnosticManager = ( NeuDiagnosticManager * )
rtDW . oukxnbv2xn ; diagnosticTree_p =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . aofv5yv5hq ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg_p
= rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS , msg_p )
; } } if ( ssIsMajorTimeStep ( rtS ) && simulationData -> mData ->
mCstateHasChanged ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetIsOkayToUpdateMode ( rtS ) )
{ rtDW . nv1qywh0t4 = ( rtB . kqf2fs2t1y < rtP . Constant_Value ) ; } if (
rtDW . nv1qywh0t4 ) { ssSetStopRequested ( rtS , 1 ) ; } } rtB . ieynslkjq3 [
0 ] = rtB . lvevo4t3wn ; rtB . ieynslkjq3 [ 1 ] = 0.0 ; rtB . ieynslkjq3 [ 2
] = 0.0 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . oc10ft5oa2 [ 0 ] = ! (
rtB . ieynslkjq3 [ 0 ] == rtDW . oc10ft5oa2 [ 1 ] ) ; rtDW . oc10ft5oa2 [ 1 ]
= rtB . ieynslkjq3 [ 0 ] ; } rtB . ieynslkjq3 [ 0 ] = rtDW . oc10ft5oa2 [ 1 ]
; rtB . ieynslkjq3 [ 3 ] = rtDW . oc10ft5oa2 [ 0 ] ; rtB . kji3dnoobq [ 0 ] =
rtB . biaotuu3xg ; rtB . kji3dnoobq [ 1 ] = 0.0 ; rtB . kji3dnoobq [ 2 ] =
0.0 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . n4nmpo2ryg [ 0 ] = ! ( rtB .
kji3dnoobq [ 0 ] == rtDW . n4nmpo2ryg [ 1 ] ) ; rtDW . n4nmpo2ryg [ 1 ] = rtB
. kji3dnoobq [ 0 ] ; } rtB . kji3dnoobq [ 0 ] = rtDW . n4nmpo2ryg [ 1 ] ; rtB
. kji3dnoobq [ 3 ] = rtDW . n4nmpo2ryg [ 0 ] ; UNUSED_PARAMETER ( tid ) ; }
void MdlOutputsTID2 ( int_T tid ) { rtB . biaotuu3xg = rtP . Gain_Gain * rtP
. Force_Value ; rtB . lvevo4t3wn = rtP . Gain1_Gain * rtP . Force_Value ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; char * msg ; real_T
tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [ 3 ] ; boolean_T tmp
; simulationData = ( NeslSimulationData * ) rtDW . mqnpyike4n ; time = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 13 ;
simulationData -> mData -> mContStates . mX = & rtX . izv2gt4f3j [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . pdwwkimpfc ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
gptd1jty42 ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS )
-> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ieynslkjq3 [ 0 ] ; tmp_p [ 1 ] = rtB . ieynslkjq3 [ 1 ] ;
tmp_p [ 2 ] = rtB . ieynslkjq3 [ 2 ] ; tmp_p [ 3 ] = rtB . ieynslkjq3 [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . kji3dnoobq [ 0 ] ; tmp_p [ 5 ] = rtB .
kji3dnoobq [ 1 ] ; tmp_p [ 6 ] = rtB . kji3dnoobq [ 2 ] ; tmp_p [ 7 ] = rtB .
kji3dnoobq [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . mbe4pdfwl2 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . o2mwkdt5ya , NESL_SIM_UPDATE
, simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; XDot * _rtXdot ;
char * msg ; real_T tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [
3 ] ; boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ;
simulationData = ( NeslSimulationData * ) rtDW . mqnpyike4n ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 13 ;
simulationData -> mData -> mContStates . mX = & rtX . izv2gt4f3j [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . pdwwkimpfc ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = & rtDW .
gptd1jty42 ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS )
-> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ieynslkjq3 [ 0 ] ; tmp_p [ 1 ] = rtB . ieynslkjq3 [ 1 ] ;
tmp_p [ 2 ] = rtB . ieynslkjq3 [ 2 ] ; tmp_p [ 3 ] = rtB . ieynslkjq3 [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . kji3dnoobq [ 0 ] ; tmp_p [ 5 ] = rtB .
kji3dnoobq [ 1 ] ; tmp_p [ 6 ] = rtB . kji3dnoobq [ 2 ] ; tmp_p [ 7 ] = rtB .
kji3dnoobq [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN =
13 ; simulationData -> mData -> mDx . mX = & _rtXdot -> izv2gt4f3j [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . mbe4pdfwl2 ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . o2mwkdt5ya ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlProjection ( void ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; char * msg ; real_T tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e
[ 3 ] ; boolean_T tmp ; simulationData = ( NeslSimulationData * ) rtDW .
mqnpyike4n ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 13 ; simulationData -> mData -> mContStates . mX = &
rtX . izv2gt4f3j [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . pdwwkimpfc ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = & rtDW . gptd1jty42 ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ieynslkjq3 [ 0 ] ; tmp_p [ 1 ] = rtB . ieynslkjq3 [ 1 ] ;
tmp_p [ 2 ] = rtB . ieynslkjq3 [ 2 ] ; tmp_p [ 3 ] = rtB . ieynslkjq3 [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . kji3dnoobq [ 0 ] ; tmp_p [ 5 ] = rtB .
kji3dnoobq [ 1 ] ; tmp_p [ 6 ] = rtB . kji3dnoobq [ 2 ] ; tmp_p [ 7 ] = rtB .
kji3dnoobq [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . mbe4pdfwl2 ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . o2mwkdt5ya ,
NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV *
) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> oqgs52rvdj = rtB .
kqf2fs2t1y - rtP . Constant_Value ; } void MdlTerminate ( void ) {
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . mbe4pdfwl2
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . mqnpyike4n
) ; nesl_erase_simulator ( "untitled/Solver Configuration1_1" ) ;
nesl_destroy_registry ( ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . oukxnbv2xn ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . ov4ulhkgil ) ; nesl_erase_simulator (
"untitled/Solver Configuration1_1" ) ; nesl_destroy_registry ( ) ; } static
void mr_untitled_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_untitled_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_untitled_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_untitled_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_untitled_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_untitled_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_untitled_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_untitled_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_untitled_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_untitled_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_untitled_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_untitled_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_untitled_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_untitled_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_untitled_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_untitled_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_untitled_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_untitled_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 9 ] = {
"rtDW.oc10ft5oa2" , "rtDW.n4nmpo2ryg" , "rtDW.pdwwkimpfc" , "rtDW.mfl3kjtovu"
, "rtDW.gptd1jty42" , "rtDW.cugokxgzzg" , "rtDW.jqj2t5fvef" ,
"rtDW.jhfhlmq5jb" , "rtDW.nv1qywh0t4" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 9 , rtdwDataFieldNames ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW
. oc10ft5oa2 ) , sizeof ( rtDW . oc10ft5oa2 ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW
. n4nmpo2ryg ) , sizeof ( rtDW . n4nmpo2ryg ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. pdwwkimpfc ) , sizeof ( rtDW . pdwwkimpfc ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. mfl3kjtovu ) , sizeof ( rtDW . mfl3kjtovu ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW
. gptd1jty42 ) , sizeof ( rtDW . gptd1jty42 ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW
. cugokxgzzg ) , sizeof ( rtDW . cugokxgzzg ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW
. jqj2t5fvef ) , sizeof ( rtDW . jqj2t5fvef ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW
. jhfhlmq5jb ) , sizeof ( rtDW . jhfhlmq5jb ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & ( rtDW
. nv1qywh0t4 ) , sizeof ( rtDW . nv1qywh0t4 ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_untitled_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_untitled_restoreDataFromMxArray ( (
void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . oc10ft5oa2 ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . oc10ft5oa2 ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . n4nmpo2ryg ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . n4nmpo2ryg ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . pdwwkimpfc ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . pdwwkimpfc ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . mfl3kjtovu ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . mfl3kjtovu ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . gptd1jty42 ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . gptd1jty42 ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . cugokxgzzg ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . cugokxgzzg ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . jqj2t5fvef ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . jqj2t5fvef ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . jhfhlmq5jb ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . jhfhlmq5jb ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . nv1qywh0t4 ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . nv1qywh0t4 ) ) ; } } mxArray *
mr_untitled_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 8 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 8 ] = { "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , "Scope" , "Scope" , "Scope" , "Scope" ,
"SimscapeExecutionBlock" , "SimscapeExecutionBlock" , } ; static const char *
blockPath [ 8 ] = { "untitled/Solver Configuration1/EVAL_KEY/STATE_1" ,
"untitled/Solver Configuration1/EVAL_KEY/OUTPUT_1_0" , "untitled/Scope" ,
"untitled/Scope1" , "untitled/Scope2" , "untitled/Scope3" ,
"untitled/Solver Configuration1/EVAL_KEY/OUTPUT_1_0" ,
"untitled/Solver Configuration1/EVAL_KEY/STATE_1" , } ; static const int
reason [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 5 , 5 , } ; for ( subs [ 0 ] = 0 ;
subs [ 0 ] < 8 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 13 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 32 ) ; ssSetNumBlockIO ( rtS , 6 ) ;
ssSetNumBlockParams ( rtS , 4 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2621274426U ) ;
ssSetChecksumVal ( rtS , 1 , 300984499U ) ; ssSetChecksumVal ( rtS , 2 ,
4063082783U ) ; ssSetChecksumVal ( rtS , 3 , 857176414U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
untitled_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "untitled" ) ; ssSetPath
( rtS , "untitled" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , rtInf
) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 4 , 1 , 1 , 1 , 3
, 2 , 2 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1
, 1 , 4 , 1 , 1 , 1 , 3 , 2 , 2 } ; static boolean_T rt_LoggedStateIsVarDims
[ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) }
; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "Discrete"
, "Discrete" } ; static const char_T * rt_LoggedStateBlockNames [ ] = {
"untitled/Brick Solid1" , "untitled/Brick Solid1" , "untitled/Brick Solid1" ,
"untitled/Brick Solid1" , "untitled/Brick Solid1" , "untitled/Brick Solid1" ,
"untitled/Brick Solid1" , "untitled/Brick Solid1" ,
"untitled/Solver\nConfiguration1/EVAL_KEY/INPUT_1_1_1" ,
"untitled/Solver\nConfiguration1/EVAL_KEY/INPUT_2_1_1" } ; static const
char_T * rt_LoggedStateNames [ ] = {
"untitled.Brick_Solid1.implicit6dof1.Px.p" ,
"untitled.Brick_Solid1.implicit6dof1.Py.p" ,
"untitled.Brick_Solid1.implicit6dof1.Pz.p" ,
"untitled.Brick_Solid1.implicit6dof1.S.Q" ,
"untitled.Brick_Solid1.implicit6dof1.Px.v" ,
"untitled.Brick_Solid1.implicit6dof1.Py.v" ,
"untitled.Brick_Solid1.implicit6dof1.Pz.v" ,
"untitled.Brick_Solid1.implicit6dof1.S.w" , "Discrete" , "Discrete" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = {
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 0 , 1 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 10 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 10 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . izv2gt4f3j [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . izv2gt4f3j [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . izv2gt4f3j [ 2 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . izv2gt4f3j [ 3 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . izv2gt4f3j [ 7 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . izv2gt4f3j [ 8 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . izv2gt4f3j [ 9 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . izv2gt4f3j [ 10 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) rtDW . oc10ft5oa2 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) rtDW . n4nmpo2ryg ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3
; static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 13 ] ; static real_T absTol [ 13 ] = { 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 13 ] = { 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 13 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 13 ] ; static uint8_T zcAttributes [ 1 ] = {
( ZC_EVENT_ALL ) } ; { int i ; for ( i = 0 ; i < 13 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.2 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
_ssSetSolverUpdateJacobianAtReset ( rtS , true ) ; ssSetAbsTolVector ( rtS ,
absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 1 ) ; (
void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ;
ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 1 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 1 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2621274426U ) ; ssSetChecksumVal ( rtS , 1 ,
300984499U ) ; ssSetChecksumVal ( rtS , 2 , 4063082783U ) ; ssSetChecksumVal
( rtS , 3 , 857176414U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_untitled_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_untitled_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_untitled_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
