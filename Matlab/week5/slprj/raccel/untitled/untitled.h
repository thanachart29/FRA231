#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "untitled_48324b08_1_gateway.h"
#endif
#include "untitled_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME untitled
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (6) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (13)   
#elif NCSTATES != 13
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ewitn5xjqu [ 13 ] ; real_T kqf2fs2t1y ; real_T
ieynslkjq3 [ 4 ] ; real_T kji3dnoobq [ 4 ] ; real_T biaotuu3xg ; real_T
lvevo4t3wn ; } B ; typedef struct { real_T oc10ft5oa2 [ 2 ] ; real_T
n4nmpo2ryg [ 2 ] ; real_T pdwwkimpfc ; real_T mfl3kjtovu ; void * o2mwkdt5ya
; void * mqnpyike4n ; void * mbe4pdfwl2 ; void * hyf4zyfns4 ; void *
baxb0rvvcm ; void * aofv5yv5hq ; void * ov4ulhkgil ; void * oukxnbv2xn ; void
* db3tnebuta ; void * iptlzwujaq ; struct { void * LoggedData ; } oay4q0giah
; struct { void * LoggedData ; } dproym02o0 ; struct { void * LoggedData ; }
cktgrwupax ; struct { void * LoggedData ; } lfz5yh4cfx ; int_T gptd1jty42 ;
int_T cugokxgzzg ; boolean_T jqj2t5fvef ; boolean_T jhfhlmq5jb ; boolean_T
nv1qywh0t4 ; } DW ; typedef struct { real_T izv2gt4f3j [ 13 ] ; } X ; typedef
struct { real_T izv2gt4f3j [ 13 ] ; } XDot ; typedef struct { boolean_T
izv2gt4f3j [ 13 ] ; } XDis ; typedef struct { real_T izv2gt4f3j [ 13 ] ; }
CStateAbsTol ; typedef struct { real_T izv2gt4f3j [ 13 ] ; } CXPtMin ;
typedef struct { real_T izv2gt4f3j [ 13 ] ; } CXPtMax ; typedef struct {
real_T oqgs52rvdj ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T Constant_Value ; real_T Force_Value ; real_T
Gain_Gain ; real_T Gain1_Gain ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_untitled_GetDWork ( ) ; extern void
mr_untitled_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_untitled_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * untitled_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
