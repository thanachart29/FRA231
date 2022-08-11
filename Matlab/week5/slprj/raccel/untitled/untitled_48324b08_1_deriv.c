#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "sm_ssci_run_time_errors.h"
#include "sm_RuntimeDerivedValuesBundle.h"
#include "untitled_48324b08_1_geometries.h"
PmfMessageId untitled_48324b08_1_compDerivs ( const
RuntimeDerivedValuesBundle * rtdv , const int * eqnEnableFlags , const double
* state , const int * modeVector , const double * input , const double *
inputDot , const double * inputDdot , const double * discreteState , double *
deriv , double * errorResult , NeuDiagnosticManager * neDiagMgr ) { const
double * rtdvd = rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv ->
mInts . mValues ; int ii [ 1 ] ; double xx [ 153 ] ; ( void ) rtdvd ; ( void
) rtdvi ; ( void ) eqnEnableFlags ; ( void ) modeVector ; ( void ) inputDot ;
( void ) inputDdot ; ( void ) discreteState ; ( void ) neDiagMgr ; xx [ 0 ] =
state [ 3 ] ; xx [ 1 ] = state [ 4 ] ; xx [ 2 ] = state [ 5 ] ; xx [ 3 ] =
state [ 6 ] ; xx [ 4 ] = state [ 10 ] ; xx [ 5 ] = state [ 11 ] ; xx [ 6 ] =
state [ 12 ] ; pm_math_Quaternion_compDeriv_ra ( xx + 0 , xx + 4 , xx + 7 ) ;
xx [ 0 ] = 1.0 ; xx [ 1 ] = state [ 5 ] * state [ 5 ] ; xx [ 2 ] = state [ 6
] * state [ 6 ] ; xx [ 3 ] = 2.0 ; xx [ 11 ] = xx [ 0 ] - ( xx [ 1 ] + xx [ 2
] ) * xx [ 3 ] ; xx [ 12 ] = state [ 4 ] * state [ 5 ] ; xx [ 13 ] = state [
3 ] * state [ 6 ] ; xx [ 14 ] = xx [ 3 ] * ( xx [ 12 ] - xx [ 13 ] ) ; xx [
15 ] = state [ 3 ] * state [ 5 ] ; xx [ 16 ] = state [ 4 ] * state [ 6 ] ; xx
[ 17 ] = ( xx [ 15 ] + xx [ 16 ] ) * xx [ 3 ] ; xx [ 18 ] = xx [ 11 ] ; xx [
19 ] = xx [ 14 ] ; xx [ 20 ] = xx [ 17 ] ; xx [ 21 ] = 0.1951 ; xx [ 22 ] =
xx [ 21 ] * xx [ 11 ] ; xx [ 11 ] = xx [ 21 ] * xx [ 14 ] ; xx [ 14 ] = xx [
21 ] * xx [ 17 ] ; xx [ 23 ] = xx [ 22 ] ; xx [ 24 ] = xx [ 11 ] ; xx [ 25 ]
= xx [ 14 ] ; xx [ 17 ] = ( xx [ 13 ] + xx [ 12 ] ) * xx [ 3 ] ; xx [ 12 ] =
xx [ 21 ] * xx [ 17 ] ; xx [ 13 ] = state [ 4 ] * state [ 4 ] ; xx [ 26 ] =
xx [ 0 ] - ( xx [ 2 ] + xx [ 13 ] ) * xx [ 3 ] ; xx [ 2 ] = xx [ 21 ] * xx [
26 ] ; xx [ 27 ] = state [ 5 ] * state [ 6 ] ; xx [ 28 ] = state [ 3 ] *
state [ 4 ] ; xx [ 29 ] = xx [ 3 ] * ( xx [ 27 ] - xx [ 28 ] ) ; xx [ 30 ] =
xx [ 21 ] * xx [ 29 ] ; xx [ 31 ] = xx [ 12 ] ; xx [ 32 ] = xx [ 2 ] ; xx [
33 ] = xx [ 30 ] ; xx [ 34 ] = pm_math_Vector3_dot_ra ( xx + 18 , xx + 31 ) ;
xx [ 35 ] = xx [ 3 ] * ( xx [ 16 ] - xx [ 15 ] ) ; xx [ 15 ] = xx [ 21 ] * xx
[ 35 ] ; xx [ 16 ] = ( xx [ 28 ] + xx [ 27 ] ) * xx [ 3 ] ; xx [ 27 ] = xx [
21 ] * xx [ 16 ] ; xx [ 28 ] = xx [ 0 ] - ( xx [ 13 ] + xx [ 1 ] ) * xx [ 3 ]
; xx [ 0 ] = xx [ 21 ] * xx [ 28 ] ; xx [ 36 ] = xx [ 15 ] ; xx [ 37 ] = xx [
27 ] ; xx [ 38 ] = xx [ 0 ] ; xx [ 1 ] = pm_math_Vector3_dot_ra ( xx + 18 ,
xx + 36 ) ; xx [ 13 ] = 0.0 ; xx [ 39 ] = xx [ 17 ] ; xx [ 40 ] = xx [ 26 ] ;
xx [ 41 ] = xx [ 29 ] ; xx [ 17 ] = pm_math_Vector3_dot_ra ( xx + 39 , xx +
36 ) ; xx [ 42 ] = xx [ 35 ] ; xx [ 43 ] = xx [ 16 ] ; xx [ 44 ] = xx [ 28 ]
; xx [ 16 ] = 2.357458333333333e-4 ; xx [ 26 ] = 6.015583333333331e-5 ; xx [
28 ] = 2.9265e-4 ; xx [ 45 ] = pm_math_Vector3_dot_ra ( xx + 18 , xx + 23 ) ;
xx [ 46 ] = xx [ 34 ] ; xx [ 47 ] = xx [ 1 ] ; xx [ 48 ] = xx [ 13 ] ; xx [
49 ] = xx [ 13 ] ; xx [ 50 ] = xx [ 13 ] ; xx [ 51 ] = xx [ 34 ] ; xx [ 52 ]
= pm_math_Vector3_dot_ra ( xx + 39 , xx + 31 ) ; xx [ 53 ] = xx [ 17 ] ; xx [
54 ] = xx [ 13 ] ; xx [ 55 ] = xx [ 13 ] ; xx [ 56 ] = xx [ 13 ] ; xx [ 57 ]
= xx [ 1 ] ; xx [ 58 ] = xx [ 17 ] ; xx [ 59 ] = pm_math_Vector3_dot_ra ( xx
+ 42 , xx + 36 ) ; xx [ 60 ] = xx [ 13 ] ; xx [ 61 ] = xx [ 13 ] ; xx [ 62 ]
= xx [ 13 ] ; xx [ 63 ] = xx [ 13 ] ; xx [ 64 ] = xx [ 13 ] ; xx [ 65 ] = xx
[ 13 ] ; xx [ 66 ] = xx [ 16 ] ; xx [ 67 ] = xx [ 13 ] ; xx [ 68 ] = xx [ 13
] ; xx [ 69 ] = xx [ 13 ] ; xx [ 70 ] = xx [ 13 ] ; xx [ 71 ] = xx [ 13 ] ;
xx [ 72 ] = xx [ 13 ] ; xx [ 73 ] = xx [ 26 ] ; xx [ 74 ] = xx [ 13 ] ; xx [
75 ] = xx [ 13 ] ; xx [ 76 ] = xx [ 13 ] ; xx [ 77 ] = xx [ 13 ] ; xx [ 78 ]
= xx [ 13 ] ; xx [ 79 ] = xx [ 13 ] ; xx [ 80 ] = xx [ 28 ] ; ii [ 0 ] =
factorSymmetricPosDef ( xx + 45 , 6 , xx + 31 ) ; if ( ii [ 0 ] != 0 ? 1 : 0
!= 0 ) { return sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMassImplicit6Dof" ,
"An implicit 6-DOF joint is attached to a degenerate mass distribution." ,
neDiagMgr ) ; } xx [ 31 ] = - state [ 3 ] ; xx [ 32 ] = - state [ 4 ] ; xx [
33 ] = - state [ 5 ] ; xx [ 34 ] = - state [ 6 ] ; xx [ 23 ] = state [ 7 ] ;
xx [ 24 ] = state [ 8 ] ; xx [ 25 ] = state [ 9 ] ;
pm_math_Quaternion_inverseXform_ra ( xx + 31 , xx + 23 , xx + 35 ) ;
pm_math_Vector3_cross_ra ( xx + 4 , xx + 35 , xx + 23 ) ; xx [ 31 ] = - xx [
35 ] ; xx [ 32 ] = - xx [ 36 ] ; xx [ 33 ] = - xx [ 37 ] ;
pm_math_Vector3_cross_ra ( xx + 4 , xx + 31 , xx + 34 ) ; xx [ 31 ] = ( xx [
23 ] + xx [ 34 ] ) * xx [ 21 ] - input [ 0 ] ; xx [ 32 ] = ( xx [ 24 ] + xx [
35 ] ) * xx [ 21 ] - input [ 1 ] ; xx [ 33 ] = ( xx [ 25 ] + xx [ 36 ] ) * xx
[ 21 ] ; xx [ 23 ] = xx [ 16 ] * state [ 10 ] ; xx [ 24 ] = xx [ 26 ] * state
[ 11 ] ; xx [ 25 ] = xx [ 28 ] * state [ 12 ] ; pm_math_Vector3_cross_ra ( xx
+ 4 , xx + 23 , xx + 34 ) ; xx [ 81 ] = - pm_math_Vector3_dot_ra ( xx + 18 ,
xx + 31 ) ; xx [ 82 ] = - pm_math_Vector3_dot_ra ( xx + 39 , xx + 31 ) ; xx [
83 ] = - pm_math_Vector3_dot_ra ( xx + 42 , xx + 31 ) ; xx [ 84 ] = - xx [ 34
] ; xx [ 85 ] = - xx [ 35 ] ; xx [ 86 ] = 0.06 * input [ 0 ] - 0.03 * input [
1 ] - xx [ 36 ] ; solveSymmetricPosDef ( xx + 45 , xx + 81 , 6 , 1 , xx + 31
, xx + 37 ) ; xx [ 81 ] = xx [ 13 ] ; xx [ 82 ] = xx [ 13 ] ; xx [ 83 ] = xx
[ 13 ] ; xx [ 84 ] = xx [ 16 ] ; xx [ 85 ] = xx [ 13 ] ; xx [ 86 ] = xx [ 13
] ; xx [ 87 ] = xx [ 13 ] ; xx [ 88 ] = xx [ 13 ] ; xx [ 89 ] = xx [ 13 ] ;
xx [ 90 ] = xx [ 13 ] ; xx [ 91 ] = xx [ 26 ] ; xx [ 92 ] = xx [ 13 ] ; xx [
93 ] = xx [ 13 ] ; xx [ 94 ] = xx [ 13 ] ; xx [ 95 ] = xx [ 13 ] ; xx [ 96 ]
= xx [ 13 ] ; xx [ 97 ] = xx [ 13 ] ; xx [ 98 ] = xx [ 28 ] ; xx [ 99 ] = xx
[ 22 ] ; xx [ 100 ] = xx [ 12 ] ; xx [ 101 ] = xx [ 15 ] ; xx [ 102 ] = xx [
13 ] ; xx [ 103 ] = xx [ 13 ] ; xx [ 104 ] = xx [ 13 ] ; xx [ 105 ] = xx [ 11
] ; xx [ 106 ] = xx [ 2 ] ; xx [ 107 ] = xx [ 27 ] ; xx [ 108 ] = xx [ 13 ] ;
xx [ 109 ] = xx [ 13 ] ; xx [ 110 ] = xx [ 13 ] ; xx [ 111 ] = xx [ 14 ] ; xx
[ 112 ] = xx [ 30 ] ; xx [ 113 ] = xx [ 0 ] ; xx [ 114 ] = xx [ 13 ] ; xx [
115 ] = xx [ 13 ] ; xx [ 116 ] = xx [ 13 ] ; solveSymmetricPosDef ( xx + 45 ,
xx + 81 , 6 , 6 , xx + 117 , xx + 14 ) ; xx [ 0 ] = xx [ 135 ] ; xx [ 1 ] =
xx [ 141 ] ; xx [ 2 ] = xx [ 147 ] ; xx [ 4 ] = 9.806649999999999 ; xx [ 5 ]
= xx [ 4 ] * state [ 6 ] ; xx [ 6 ] = xx [ 4 ] * state [ 4 ] ; xx [ 14 ] = (
xx [ 5 ] * state [ 3 ] + xx [ 6 ] * state [ 5 ] ) * xx [ 3 ] ; xx [ 15 ] = xx
[ 4 ] - ( xx [ 5 ] * state [ 6 ] + xx [ 6 ] * state [ 4 ] ) * xx [ 3 ] ; xx [
16 ] = xx [ 3 ] * ( xx [ 5 ] * state [ 5 ] - xx [ 6 ] * state [ 3 ] ) ; xx [
3 ] = xx [ 136 ] ; xx [ 4 ] = xx [ 142 ] ; xx [ 5 ] = xx [ 148 ] ; xx [ 17 ]
= xx [ 137 ] ; xx [ 18 ] = xx [ 143 ] ; xx [ 19 ] = xx [ 149 ] ; xx [ 20 ] =
xx [ 138 ] ; xx [ 21 ] = xx [ 144 ] ; xx [ 22 ] = xx [ 150 ] ; xx [ 23 ] = xx
[ 139 ] ; xx [ 24 ] = xx [ 145 ] ; xx [ 25 ] = xx [ 151 ] ; xx [ 26 ] = xx [
140 ] ; xx [ 27 ] = xx [ 146 ] ; xx [ 28 ] = xx [ 152 ] ; deriv [ 0 ] = state
[ 7 ] ; deriv [ 1 ] = state [ 8 ] ; deriv [ 2 ] = state [ 9 ] ; deriv [ 3 ] =
xx [ 7 ] ; deriv [ 4 ] = xx [ 8 ] ; deriv [ 5 ] = xx [ 9 ] ; deriv [ 6 ] = xx
[ 10 ] ; deriv [ 7 ] = xx [ 31 ] - pm_math_Vector3_dot_ra ( xx + 0 , xx + 14
) ; deriv [ 8 ] = xx [ 32 ] - pm_math_Vector3_dot_ra ( xx + 3 , xx + 14 ) ;
deriv [ 9 ] = xx [ 33 ] - pm_math_Vector3_dot_ra ( xx + 17 , xx + 14 ) ;
deriv [ 10 ] = xx [ 34 ] - pm_math_Vector3_dot_ra ( xx + 20 , xx + 14 ) ;
deriv [ 11 ] = xx [ 35 ] - pm_math_Vector3_dot_ra ( xx + 23 , xx + 14 ) ;
deriv [ 12 ] = xx [ 36 ] - pm_math_Vector3_dot_ra ( xx + 26 , xx + 14 ) ;
errorResult [ 0 ] = xx [ 13 ] ; return NULL ; } PmfMessageId
untitled_48324b08_1_numJacPerturbLoBounds ( const RuntimeDerivedValuesBundle
* rtdv , const int * eqnEnableFlags , const double * state , const int *
modeVector , const double * input , const double * inputDot , const double *
inputDdot , const double * discreteState , double * bounds , double *
errorResult , NeuDiagnosticManager * neDiagMgr ) { const double * rtdvd =
rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ;
double xx [ 2 ] ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ;
( void ) state ; ( void ) modeVector ; ( void ) input ; ( void ) inputDot ; (
void ) inputDdot ; ( void ) discreteState ; ( void ) neDiagMgr ; xx [ 0 ] =
1.0e-9 ; xx [ 1 ] = 1.0e-8 ; bounds [ 0 ] = xx [ 0 ] ; bounds [ 1 ] = xx [ 0
] ; bounds [ 2 ] = xx [ 0 ] ; bounds [ 3 ] = xx [ 1 ] ; bounds [ 4 ] = xx [ 1
] ; bounds [ 5 ] = xx [ 1 ] ; bounds [ 6 ] = xx [ 1 ] ; bounds [ 7 ] = xx [ 0
] ; bounds [ 8 ] = xx [ 0 ] ; bounds [ 9 ] = xx [ 0 ] ; bounds [ 10 ] = xx [
1 ] ; bounds [ 11 ] = xx [ 1 ] ; bounds [ 12 ] = xx [ 1 ] ; errorResult [ 0 ]
= 0.0 ; return NULL ; } PmfMessageId
untitled_48324b08_1_numJacPerturbHiBounds ( const RuntimeDerivedValuesBundle
* rtdv , const int * eqnEnableFlags , const double * state , const int *
modeVector , const double * input , const double * inputDot , const double *
inputDdot , const double * discreteState , double * bounds , double *
errorResult , NeuDiagnosticManager * neDiagMgr ) { const double * rtdvd =
rtdv -> mDoubles . mValues ; const int * rtdvi = rtdv -> mInts . mValues ;
double xx [ 2 ] ; ( void ) rtdvd ; ( void ) rtdvi ; ( void ) eqnEnableFlags ;
( void ) state ; ( void ) modeVector ; ( void ) input ; ( void ) inputDot ; (
void ) inputDdot ; ( void ) discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = +
pmf_get_inf ( ) ; xx [ 1 ] = 0.1 ; bounds [ 0 ] = xx [ 0 ] ; bounds [ 1 ] =
xx [ 0 ] ; bounds [ 2 ] = xx [ 0 ] ; bounds [ 3 ] = xx [ 1 ] ; bounds [ 4 ] =
xx [ 1 ] ; bounds [ 5 ] = xx [ 1 ] ; bounds [ 6 ] = xx [ 1 ] ; bounds [ 7 ] =
xx [ 0 ] ; bounds [ 8 ] = xx [ 0 ] ; bounds [ 9 ] = xx [ 0 ] ; bounds [ 10 ]
= xx [ 0 ] ; bounds [ 11 ] = xx [ 0 ] ; bounds [ 12 ] = xx [ 0 ] ;
errorResult [ 0 ] = 0.0 ; return NULL ; }
