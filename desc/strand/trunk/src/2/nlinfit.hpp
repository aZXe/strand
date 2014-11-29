//
// MATLAB Compiler: 2.1
// Date: Fri Jan 04 16:59:50 2002
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-L" "Cpp" "-A"
// "annotation:all" "-O" "all" "-O" "fold_scalar_mxarrays:on" "-O"
// "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "nlinfit" 
//
#ifndef __nlinfit_hpp
#define __nlinfit_hpp 1

#include "matlab.hpp"

extern void InitializeModule_nlinfit();
extern void TerminateModule_nlinfit();
extern _mexLocalFunctionTable _local_function_table_nlinfit;

extern mwArray nlinfit(mwArray * r,
                       mwArray * J,
                       mwArray X = mwArray::DIN,
                       mwArray y = mwArray::DIN,
                       mwArray model = mwArray::DIN,
                       mwArray beta0 = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxNlinfit(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif
