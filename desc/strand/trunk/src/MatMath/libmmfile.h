
/* $Revision: 1.1 $ */
/*
 * Copyright (c) 1984-1998 by The MathWorks, Inc.
 * All Rights Reserved.
 */
/*
 * MATLAB Compiler: 2.1
 * Date: Wed Sep 27 18:52:50 2000
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-c" "-w" "error" "-w"
 * "enable:break_without_loop" "-w" "enable:undefined_variable" "-w"
 * "enable:undefined_variable_or_unknown_function" "-w"
 * "enable:matlab_method_used" "-w" "disable:using_mex_only_function" "-w"
 * "disable:using_graphics_function" "-w" "disable:max_page_width_violation"
 * "-I" "/devel/R12fcs/build/standalone/libmmfile/modified_M" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/audio" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/datafun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/datatypes" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/elfun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/elmat" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/funfun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/general" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/graphics" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/graph2d" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/graph3d" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/iofun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/lang" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/matfun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/ops" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/polyfun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/specfun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/strfun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/timefun" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/sparfun" "-I"
 * "/devel/R12fcs/build/toolbox/compiler" "-I"
 * "/devel/R12fcs/build/toolbox/matlab/uitools" "-Z" "-v" "-W" "lib:libmmfile"
 * "-d" "mfile_src" "-B" "mfile_src/libmmfile_response" "acot.m" "acoth.m"
 * "acsc.m" "acsch.m" "angle.m" "asec.m" "asech.m" "automesh.m" "bin2dec.m"
 * "bitmax.m" "base2dec.m" "betainc.m" "beta.m" "betacore.m" "betaln.m"
 * "blanks.m" "cart2pol.m" "cart2sph.m" "cdf2rdf.m" "compan.m" "cot.m" "coth.m"
 * "csc.m" "csch.m" "condeig.m" "condest.m" "conv.m" "cumtrapz.m" "cov.m"
 * "cond.m" "cplxpair.m" "cross.m" "calendar.m" "corrcoef.m" "date.m"
 * "datenum.m" "dec2base.m" "dec2hex.m" "deconv.m" "del2.m" "datestr.m"
 * "datevec.m" "dec2bin.m" "delaunay.m" "delaunayn.m" "dblquad.m" "dot.m"
 * "dsearch.m" "eomday.m" "erfc.m" "erfcx.m" "etime.m" "expm1.m" "expm2.m"
 * "expm3.m" "expint.m" "ellipj.m" "ellipke.m" "erf.m" "erfinv.m" "fcnchk.m"
 * "fftshift.m" "fft2.m" "filter2.m" "foptions.m" "factor.m" "freqspace.m"
 * "fliplr.m" "flipud.m" "frewind.m" "fgetl.m" "fmin.m" "fmins.m" "funm.m"
 * "fzero.m" "fminbnd.m" "fminsearch.m" "fileparts.m" "filesep.m" "fullfile.m"
 * "lsqnonneg.m" "gammainc.m" "gcd.m" "getfield.m" "gradient.m" "griddata.m"
 * "hadamard.m" "hankel.m" "hilb.m" "hex2dec.m" "hex2num.m" "ifft2.m"
 * "int2str.m" "invhilb.m" "inpolygon.m" "ipermute.m" "iscellstr.m" "isprime.m"
 * "interpft.m" "interp1.m" "interp1q.m" "interp2.m" "isnumeric.m" "iscell.m"
 * "isieee.m" "isobject.m" "ispc.m" "isunix.m" "isvms.m" "kron.m" "lcm.m"
 * "linspace.m" "log10.m" "logm.m" "logspace.m" "lin2mu.m" "lscov.m"
 * "legendre.m" "magic.m" "mat2str.m" "mkpp.m" "meshgrid.m" "mod.m" "mu2lin.m"
 * "mean.m" "median.m" "nargchk.m" "nargoutchk.m" "nextpow2.m" "nchoosek.m"
 * "now.m" "null.m" "nnls.m" "normest.m" "normest1.m" "num2str.m" "numjac.m"
 * "orth.m" "odeget.m" "odeset.m" "ode113.m" "ode15s.m" "ode23.m" "ode23s.m"
 * "ode45.m" "odeplot.m" "optimset.m" "optimget.m" "polyfit.m" "pascal.m"
 * "pchip.m" "pinv.m" "planerot.m" "pol2cart.m" "poly.m" "polyvalm.m" "perms.m"
 * "polyarea.m" "polyder.m" "ppval.m" "primes.m" "polyval.m" "polyeig.m"
 * "pwd.m" "qrdelete.m" "qrinsert.m" "quad.m" "quad8.m" "rank.m" "roots.m"
 * "rosser.m" "rref.m" "rsf2csf.m" "realmax.m" "realmin.m" "rectint.m"
 * "repmat.m" "resi2.m" "residue.m" "rot90.m" "rat.m" "rats.m" "setfield.m"
 * "sec.m" "sech.m" "shiftdim.m" "sph2cart.m" "spline.m" "subspace.m" "sqrtm.m"
 * "str2double.m" "str2mat.m" "str2num.m" "strjust.m" "strtok.m" "sortrows.m"
 * "splncore.m" "std.m" "strvcat.m" "table1.m" "table2.m" "tic.m" "toc.m"
 * "toeplitz.m" "tsearch.m" "trace.m" "trapz.m" "tempdir.m" "tempname.m"
 * "unmkpp.m" "unwrap.m" "vander.m" "vectorize.m" "wilkinson.m" "weekday.m"
 * "xor.m" "xychk.m" "xyzchk.m" "mpoles.m" "mbintvector.m" "mbrealvector.m"
 * "mbintscalar.m" "mbrealscalar.m" "mbcharvector.m" "mbcharscalar.m"
 * "reallog.m" "realpow.m" "realsqrt.m" "usejava.m" "rmfield.m" "isfield.m"
 * "isstruct.m" "celldisp.m" "num2cell.m" "deal.m" "cellstr.m" "ind2sub.m"
 * "sub2ind.m" "speye.m" "sprand.m" "sprandn.m" "sprandsym.m" "spdiags.m"
 * "spconvert.m" "nnz.m" "nonzeros.m" "nzmax.m" "spones.m" "spalloc.m"
 * "spfun.m" "colmmd.m" "symmmd.m" "symrcm.m" "colperm.m" "randperm.m"
 * "dmperm.m" "eigs.m" "svds.m" "pcg.m" "bicg.m" "bicgstab.m" "cgs.m" "gmres.m"
 * "qmr.m" "symbfact.m" "spparms.m" "spaugment.m" "rjr.m" "eigs2.m" "axis.m"
 * "allchild.m" "gcf.m" "gca.m" "hold.m" "ishold.m" "refresh.m" "view.m"
 * "deblank.m" "intersect.m" "ismember.m" "setdiff.m" "setxor.m" "strcat.m"
 * "strmatch.m" "union.m" "unique.m" "@cell/deblank.m" "@cell/intersect.m"
 * "@cell/ismember.m" "@cell/setdiff.m" "@cell/setxor.m" "@cell/strcat.m"
 * "@cell/strmatch.m" "@cell/union.m" "@cell/unique.m" "@cell/sort.m"
 * "@char/delete.m" "arpackc" "complex" "gamma" "erfcore" "gammaln" "histc"
 * "ismembc" "cellfun" "datenummx" "datevecmx"
 * "/devel/R12fcs/build/toolbox/matlab/polyfun/private/cubicmx"
 * "/devel/R12fcs/build/toolbox/matlab/polyfun/private/qhullmx"
 * "/devel/R12fcs/build/toolbox/matlab/polyfun/private/tsrchmx"
 * "/devel/R12fcs/build/toolbox/matlab/polyfun/private/delaunayc"
 * "/devel/R12fcs/build/toolbox/matlab/polyfun/private/dsrchmx"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/daeic3.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/daeic12.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odemxv.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/colgroup.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odezero.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odearguments.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odemass.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odeevents.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odejacobian.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/odemassexplicit.m"
 * "/devel/R12fcs/build/toolbox/matlab/funfun/private/funstring.m"
 * "/devel/R12fcs/build/toolbox/matlab/sparfun/private/iterchk.m"
 * "/devel/R12fcs/build/toolbox/matlab/sparfun/private/iterapp.m"
 * "/devel/R12fcs/build/toolbox/matlab/sparfun/private/itermsg.m"
 * "@default/deblank.m" "@default/intersect.m" "@default/ismember.m"
 * "@default/setdiff.m" "@default/setxor.m" "@default/strcat.m"
 * "@default/strmatch.m" "@default/union.m" "@default/unique.m" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __libmmfile_h
#define __libmmfile_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_libmmfile(void);
extern void TerminateModule_libmmfile(void);
extern mxArray * mlfAcot(mxArray * z);
extern void mlxAcot(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAcoth(mxArray * z);
extern void mlxAcoth(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAcsc(mxArray * z);
extern void mlxAcsc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAcsch(mxArray * z);
extern void mlxAcsch(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAngle(mxArray * h);
extern void mlxAngle(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAsec(mxArray * z);
extern void mlxAsec(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAsech(mxArray * z);
extern void mlxAsech(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAutomesh(mxArray * synthetic_varargin_argument, ...);
extern void mlxAutomesh(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBin2dec(mxArray * s);
extern void mlxBin2dec(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBitmax(void);
extern void mlxBitmax(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBase2dec(mxArray * h, mxArray * b);
extern void mlxBase2dec(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBetainc(mxArray * x, mxArray * a, mxArray * b);
extern void mlxBetainc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBeta(mxArray * z, mxArray * w, mxArray * v);
extern void mlxBeta(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBetacore(mxArray * x, mxArray * a, mxArray * b);
extern void mlxBetacore(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBetaln(mxArray * z, mxArray * w);
extern void mlxBetaln(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfBlanks(mxArray * n);
extern void mlxBlanks(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCart2pol(mxArray * * r,
                             mxArray * * z,
                             mxArray * x,
                             mxArray * y,
                             mxArray * z_in);
extern void mlxCart2pol(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCart2sph(mxArray * * elev,
                             mxArray * * r,
                             mxArray * x,
                             mxArray * y,
                             mxArray * z);
extern void mlxCart2sph(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCdf2rdf(mxArray * * dd, mxArray * v, mxArray * d);
extern void mlxCdf2rdf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCompan(mxArray * c);
extern void mlxCompan(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCot(mxArray * z);
extern void mlxCot(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCoth(mxArray * z);
extern void mlxCoth(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCsc(mxArray * z);
extern void mlxCsc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCsch(mxArray * z);
extern void mlxCsch(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNCondeig(int nargout,
                             mxArray * * D,
                             mxArray * * s,
                             mxArray * A);
extern mxArray * mlfCondeig(mxArray * * D, mxArray * * s, mxArray * A);
extern void mlfVCondeig(mxArray * A);
extern void mlxCondeig(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCondest(mxArray * * v, mxArray * A, mxArray * t);
extern void mlxCondest(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfConv(mxArray * a, mxArray * b);
extern void mlxConv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCumtrapz(mxArray * x, mxArray * y, mxArray * dim);
extern void mlxCumtrapz(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCov(mxArray * x, ...);
extern void mlxCov(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCond(mxArray * A, mxArray * p);
extern void mlxCond(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCplxpair(mxArray * x, mxArray * tol, mxArray * dim);
extern void mlxCplxpair(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCross(mxArray * a, mxArray * b, mxArray * dim);
extern void mlxCross(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNCalendar(int nargout, mxArray * c, mxArray * m);
extern mxArray * mlfCalendar(mxArray * c, mxArray * m);
extern void mlfVCalendar(mxArray * c, mxArray * m);
extern void mlxCalendar(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCorrcoef(mxArray * x, mxArray * y);
extern void mlxCorrcoef(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDate(void);
extern void mlxDate(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDatenum(mxArray * arg1,
                            mxArray * arg2,
                            mxArray * arg3,
                            mxArray * h,
                            mxArray * min,
                            mxArray * s);
extern void mlxDatenum(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDec2base(mxArray * d, mxArray * base, mxArray * n);
extern void mlxDec2base(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDec2hex(mxArray * d, mxArray * n);
extern void mlxDec2hex(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNDeconv(int nargout,
                            mxArray * * r,
                            mxArray * b,
                            mxArray * a);
extern mxArray * mlfDeconv(mxArray * * r, mxArray * b, mxArray * a);
extern void mlfVDeconv(mxArray * b, mxArray * a);
extern void mlxDeconv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDel2(mxArray * f, ...);
extern void mlxDel2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDatestr(mxArray * D,
                            mxArray * dateform,
                            mxArray * pivotyear);
extern void mlxDatestr(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNDatevec(int nargout,
                             mxArray * * mo,
                             mxArray * * d,
                             mxArray * * h,
                             mxArray * * mi,
                             mxArray * * s,
                             mxArray * t,
                             mxArray * pivotyear);
extern mxArray * mlfDatevec(mxArray * * mo,
                            mxArray * * d,
                            mxArray * * h,
                            mxArray * * mi,
                            mxArray * * s,
                            mxArray * t,
                            mxArray * pivotyear);
extern void mlfVDatevec(mxArray * t, mxArray * pivotyear);
extern void mlxDatevec(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDec2bin(mxArray * d, mxArray * n);
extern void mlxDec2bin(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDelaunay(mxArray * x, mxArray * y, mxArray * flag);
extern void mlxDelaunay(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDelaunayn(mxArray * x);
extern void mlxDelaunayn(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfDblquad(mxArray * intfcn,
                            mxArray * xmin,
                            mxArray * xmax,
                            mxArray * ymin,
                            mxArray * ymax,
                            mxArray * tol,
                            mxArray * quadf,
                            ...);
extern void mlxDblquad(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDot(mxArray * a, mxArray * b, mxArray * dim);
extern void mlxDot(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDsearch(mxArray * synthetic_varargin_argument, ...);
extern void mlxDsearch(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfEomday(mxArray * y, mxArray * m);
extern void mlxEomday(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfErfc(mxArray * x);
extern void mlxErfc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfErfcx(mxArray * x);
extern void mlxErfcx(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfEtime(mxArray * t1, mxArray * t0);
extern void mlxEtime(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfExpm1(mxArray * A);
extern void mlxExpm1(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfExpm2(mxArray * A);
extern void mlxExpm2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfExpm3(mxArray * A);
extern void mlxExpm3(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfExpint(mxArray * x);
extern void mlxExpint(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfEllipj(mxArray * * cn,
                           mxArray * * dn,
                           mxArray * u,
                           mxArray * m,
                           mxArray * tol);
extern void mlxEllipj(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfEllipke(mxArray * * e, mxArray * m, mxArray * tol);
extern void mlxEllipke(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfErf(mxArray * x);
extern void mlxErf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfErfinv(mxArray * y);
extern void mlxErfinv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNFcnchk(int nargout, mxArray * * msg, mxArray * fun, ...);
extern mxArray * mlfFcnchk(mxArray * * msg, mxArray * fun, ...);
extern void mlfVFcnchk(mxArray * fun, ...);
extern void mlxFcnchk(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFftshift(mxArray * x, mxArray * dim);
extern void mlxFftshift(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFft2(mxArray * x, mxArray * mrows, mxArray * ncols);
extern void mlxFft2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFilter2(mxArray * b, mxArray * x, mxArray * shape);
extern void mlxFilter2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFoptions(mxArray * parain);
extern void mlxFoptions(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFactor(mxArray * n);
extern void mlxFactor(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNFreqspace(int nargout,
                               mxArray * * f2,
                               mxArray * n,
                               mxArray * flag);
extern mxArray * mlfFreqspace(mxArray * * f2, mxArray * n, mxArray * flag);
extern void mlfVFreqspace(mxArray * n, mxArray * flag);
extern void mlxFreqspace(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfFliplr(mxArray * x);
extern void mlxFliplr(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFlipud(mxArray * x);
extern void mlxFlipud(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void mlfFrewind(mxArray * fid);
extern void mlxFrewind(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFgetl(mxArray * fid);
extern void mlxFgetl(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFmin(mxArray * * options,
                         mxArray * funfcn,
                         mxArray * ax,
                         mxArray * bx,
                         mxArray * options_in,
                         ...);
extern void mlxFmin(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFmins(mxArray * * options,
                          mxArray * funfcn,
                          mxArray * x_in,
                          mxArray * options_in,
                          mxArray * grad,
                          ...);
extern void mlxFmins(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNFunm(int nargout,
                          mxArray * * esterr,
                          mxArray * A,
                          mxArray * fun);
extern mxArray * mlfFunm(mxArray * * esterr, mxArray * A, mxArray * fun);
extern void mlfVFunm(mxArray * A, mxArray * fun);
extern void mlxFunm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNFzero(int nargout,
                           mxArray * * fval,
                           mxArray * * exitflag,
                           mxArray * * output,
                           mxArray * FunFcnIn,
                           mxArray * x,
                           ...);
extern mxArray * mlfFzero(mxArray * * fval,
                          mxArray * * exitflag,
                          mxArray * * output,
                          mxArray * FunFcnIn,
                          mxArray * x,
                          ...);
extern void mlfVFzero(mxArray * FunFcnIn, mxArray * x, ...);
extern void mlxFzero(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNFminbnd(int nargout,
                             mxArray * * fval,
                             mxArray * * exitflag,
                             mxArray * * output,
                             mxArray * funfcn,
                             mxArray * ax,
                             mxArray * bx,
                             mxArray * options,
                             ...);
extern mxArray * mlfFminbnd(mxArray * * fval,
                            mxArray * * exitflag,
                            mxArray * * output,
                            mxArray * funfcn,
                            mxArray * ax,
                            mxArray * bx,
                            mxArray * options,
                            ...);
extern void mlfVFminbnd(mxArray * funfcn,
                        mxArray * ax,
                        mxArray * bx,
                        mxArray * options,
                        ...);
extern void mlxFminbnd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNFminsearch(int nargout,
                                mxArray * * fval,
                                mxArray * * exitflag,
                                mxArray * * output,
                                mxArray * funfcn,
                                mxArray * x_in,
                                mxArray * options,
                                ...);
extern mxArray * mlfFminsearch(mxArray * * fval,
                               mxArray * * exitflag,
                               mxArray * * output,
                               mxArray * funfcn,
                               mxArray * x_in,
                               mxArray * options,
                               ...);
extern void mlfVFminsearch(mxArray * funfcn,
                           mxArray * x_in,
                           mxArray * options,
                           ...);
extern void mlxFminsearch(int nlhs,
                          mxArray * plhs[],
                          int nrhs,
                          mxArray * prhs[]);
extern mxArray * mlfFileparts(mxArray * * fname,
                              mxArray * * extension,
                              mxArray * * version,
                              mxArray * name);
extern void mlxFileparts(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfFilesep(void);
extern void mlxFilesep(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfFullfile(mxArray * synthetic_varargin_argument, ...);
extern void mlxFullfile(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNLsqnonneg(int nargout,
                               mxArray * * resnorm,
                               mxArray * * resid,
                               mxArray * * exitflag,
                               mxArray * * output,
                               mxArray * * lambda,
                               mxArray * C,
                               mxArray * d,
                               mxArray * x0,
                               mxArray * options);
extern mxArray * mlfLsqnonneg(mxArray * * resnorm,
                              mxArray * * resid,
                              mxArray * * exitflag,
                              mxArray * * output,
                              mxArray * * lambda,
                              mxArray * C,
                              mxArray * d,
                              mxArray * x0,
                              mxArray * options);
extern void mlfVLsqnonneg(mxArray * C,
                          mxArray * d,
                          mxArray * x0,
                          mxArray * options);
extern void mlxLsqnonneg(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfGammainc(mxArray * x, mxArray * a);
extern void mlxGammainc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfGcd(mxArray * * c, mxArray * * d, mxArray * a, mxArray * b);
extern void mlxGcd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfGetfield(mxArray * s, ...);
extern void mlxGetfield(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfGradient(mlfVarargoutList * varargout, mxArray * f, ...);
extern void mlxGradient(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNGriddata(int nargout,
                              mxArray * * yi,
                              mxArray * * zi,
                              mxArray * x,
                              mxArray * y,
                              mxArray * z,
                              mxArray * xi_in,
                              mxArray * yi_in,
                              mxArray * method);
extern mxArray * mlfGriddata(mxArray * * yi,
                             mxArray * * zi,
                             mxArray * x,
                             mxArray * y,
                             mxArray * z,
                             mxArray * xi_in,
                             mxArray * yi_in,
                             mxArray * method);
extern void mlfVGriddata(mxArray * x,
                         mxArray * y,
                         mxArray * z,
                         mxArray * xi_in,
                         mxArray * yi_in,
                         mxArray * method);
extern void mlxGriddata(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfHadamard(mxArray * n);
extern void mlxHadamard(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfHankel(mxArray * c, mxArray * r);
extern void mlxHankel(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfHilb(mxArray * n);
extern void mlxHilb(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfHex2dec(mxArray * h);
extern void mlxHex2dec(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfHex2num(mxArray * s);
extern void mlxHex2num(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIfft2(mxArray * f, mxArray * mrows, mxArray * ncols);
extern void mlxIfft2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInt2str(mxArray * x);
extern void mlxInt2str(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInvhilb(mxArray * n);
extern void mlxInvhilb(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInpolygon(mxArray * x,
                              mxArray * y,
                              mxArray * xv,
                              mxArray * yv);
extern void mlxInpolygon(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfIpermute(mxArray * b, mxArray * order);
extern void mlxIpermute(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIscellstr(mxArray * s);
extern void mlxIscellstr(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfIsprime(mxArray * X);
extern void mlxIsprime(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInterpft(mxArray * x, mxArray * ny, mxArray * dim);
extern void mlxInterpft(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInterp1(mxArray * synthetic_varargin_argument, ...);
extern void mlxInterp1(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInterp1q(mxArray * x, mxArray * y, mxArray * xi);
extern void mlxInterp1q(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfInterp2(mxArray * synthetic_varargin_argument, ...);
extern void mlxInterp2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsnumeric(mxArray * a);
extern void mlxIsnumeric(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfIscell(mxArray * a);
extern void mlxIscell(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsieee(void);
extern void mlxIsieee(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsobject(mxArray * a);
extern void mlxIsobject(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIspc(void);
extern void mlxIspc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsunix(void);
extern void mlxIsunix(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsvms(void);
extern void mlxIsvms(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfKron(mxArray * A, mxArray * B);
extern void mlxKron(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfLcm(mxArray * a, mxArray * b);
extern void mlxLcm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfLinspace(mxArray * d1, mxArray * d2, mxArray * n);
extern void mlxLinspace(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfLog10(mxArray * x);
extern void mlxLog10(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNLogm(int nargout, mxArray * * esterr, mxArray * A);
extern mxArray * mlfLogm(mxArray * * esterr, mxArray * A);
extern void mlfVLogm(mxArray * A);
extern void mlxLogm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfLogspace(mxArray * d1, mxArray * d2, mxArray * n);
extern void mlxLogspace(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfLin2mu(mxArray * y);
extern void mlxLin2mu(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNLscov(int nargout,
                           mxArray * * dx,
                           mxArray * A,
                           mxArray * b,
                           mxArray * V);
extern mxArray * mlfLscov(mxArray * * dx,
                          mxArray * A,
                          mxArray * b,
                          mxArray * V);
extern void mlfVLscov(mxArray * A, mxArray * b, mxArray * V);
extern void mlxLscov(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfLegendre(mxArray * l, mxArray * amu, mxArray * tflag);
extern void mlxLegendre(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMagic(mxArray * n);
extern void mlxMagic(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMat2str(mxArray * matrix, mxArray * n);
extern void mlxMat2str(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMkpp(mxArray * breaks, mxArray * coefs, mxArray * d);
extern void mlxMkpp(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNMeshgrid(int nargout,
                              mxArray * * yy,
                              mxArray * * zz,
                              mxArray * x,
                              mxArray * y,
                              mxArray * z);
extern mxArray * mlfMeshgrid(mxArray * * yy,
                             mxArray * * zz,
                             mxArray * x,
                             mxArray * y,
                             mxArray * z);
extern void mlfVMeshgrid(mxArray * x, mxArray * y, mxArray * z);
extern void mlxMeshgrid(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMod(mxArray * x, mxArray * y);
extern void mlxMod(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMu2lin(mxArray * mu);
extern void mlxMu2lin(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMean(mxArray * x, mxArray * dim);
extern void mlxMean(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMedian(mxArray * x, mxArray * dim);
extern void mlxMedian(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNargchk(mxArray * low, mxArray * high, mxArray * number);
extern void mlxNargchk(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNargoutchk(mxArray * low, mxArray * high, mxArray * number);
extern void mlxNargoutchk(int nlhs,
                          mxArray * plhs[],
                          int nrhs,
                          mxArray * prhs[]);
extern mxArray * mlfNextpow2(mxArray * n);
extern void mlxNextpow2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNchoosek(mxArray * v, mxArray * k);
extern void mlxNchoosek(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNow(void);
extern void mlxNow(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNull(mxArray * A, mxArray * how);
extern void mlxNull(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNnls(mxArray * * w,
                         mxArray * E,
                         mxArray * f,
                         mxArray * tol);
extern void mlxNnls(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNormest(mxArray * * cnt, mxArray * S, mxArray * tol);
extern void mlxNormest(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNormest1(mxArray * * v,
                             mxArray * * w,
                             mxArray * * iter,
                             mxArray * A,
                             mxArray * t,
                             mxArray * X,
                             ...);
extern void mlxNormest1(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNum2str(mxArray * x, mxArray * f);
extern void mlxNum2str(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNumjac(mxArray * * fac,
                           mxArray * * g,
                           mxArray * * nfevals,
                           mxArray * F,
                           mxArray * t,
                           mxArray * y,
                           mxArray * Fty,
                           mxArray * thresh,
                           mxArray * fac_in,
                           mxArray * vectorized,
                           mxArray * S,
                           mxArray * g_in,
                           ...);
extern void mlxNumjac(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfOrth(mxArray * A);
extern void mlxOrth(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfOdeget(mxArray * options,
                           mxArray * name,
                           mxArray * default0,
                           mxArray * flag);
extern void mlxOdeget(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOdeset(int nargout, ...);
extern mxArray * mlfOdeset(mxArray * synthetic_varargin_argument, ...);
extern void mlfVOdeset(mxArray * synthetic_varargin_argument, ...);
extern void mlxOdeset(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOde113(int nargout,
                            mxArray * * yout,
                            mlfVarargoutList * varargout,
                            mxArray * ode,
                            mxArray * tspan,
                            mxArray * y0,
                            mxArray * options,
                            ...);
extern mxArray * mlfOde113(mxArray * * yout,
                           mlfVarargoutList * varargout,
                           mxArray * ode,
                           mxArray * tspan,
                           mxArray * y0,
                           mxArray * options,
                           ...);
extern void mlfVOde113(mxArray * ode,
                       mxArray * tspan,
                       mxArray * y0,
                       mxArray * options,
                       ...);
extern void mlxOde113(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOde15s(int nargout,
                            mxArray * * yout,
                            mlfVarargoutList * varargout,
                            mxArray * ode,
                            mxArray * tspan,
                            mxArray * y0,
                            mxArray * options,
                            ...);
extern mxArray * mlfOde15s(mxArray * * yout,
                           mlfVarargoutList * varargout,
                           mxArray * ode,
                           mxArray * tspan,
                           mxArray * y0,
                           mxArray * options,
                           ...);
extern void mlfVOde15s(mxArray * ode,
                       mxArray * tspan,
                       mxArray * y0,
                       mxArray * options,
                       ...);
extern void mlxOde15s(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOde23(int nargout,
                           mxArray * * yout,
                           mlfVarargoutList * varargout,
                           mxArray * ode,
                           mxArray * tspan,
                           mxArray * y0,
                           mxArray * options,
                           ...);
extern mxArray * mlfOde23(mxArray * * yout,
                          mlfVarargoutList * varargout,
                          mxArray * ode,
                          mxArray * tspan,
                          mxArray * y0,
                          mxArray * options,
                          ...);
extern void mlfVOde23(mxArray * ode,
                      mxArray * tspan,
                      mxArray * y0,
                      mxArray * options,
                      ...);
extern void mlxOde23(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOde23s(int nargout,
                            mxArray * * yout,
                            mlfVarargoutList * varargout,
                            mxArray * ode,
                            mxArray * tspan,
                            mxArray * y0,
                            mxArray * options,
                            ...);
extern mxArray * mlfOde23s(mxArray * * yout,
                           mlfVarargoutList * varargout,
                           mxArray * ode,
                           mxArray * tspan,
                           mxArray * y0,
                           mxArray * options,
                           ...);
extern void mlfVOde23s(mxArray * ode,
                       mxArray * tspan,
                       mxArray * y0,
                       mxArray * options,
                       ...);
extern void mlxOde23s(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOde45(int nargout,
                           mxArray * * yout,
                           mlfVarargoutList * varargout,
                           mxArray * ode,
                           mxArray * tspan,
                           mxArray * y0,
                           mxArray * options,
                           ...);
extern mxArray * mlfOde45(mxArray * * yout,
                          mlfVarargoutList * varargout,
                          mxArray * ode,
                          mxArray * tspan,
                          mxArray * y0,
                          mxArray * options,
                          ...);
extern void mlfVOde45(mxArray * ode,
                      mxArray * tspan,
                      mxArray * y0,
                      mxArray * options,
                      ...);
extern void mlxOde45(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfOdeplot(mxArray * t, mxArray * y, mxArray * flag, ...);
extern void mlxOdeplot(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNOptimset(int nargout, ...);
extern mxArray * mlfOptimset(mxArray * synthetic_varargin_argument, ...);
extern void mlfVOptimset(mxArray * synthetic_varargin_argument, ...);
extern void mlxOptimset(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfOptimget(mxArray * options,
                             mxArray * name,
                             mxArray * default0,
                             mxArray * flag);
extern void mlxOptimget(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNPolyfit(int nargout,
                             mxArray * * S,
                             mxArray * * mu,
                             mxArray * x,
                             mxArray * y,
                             mxArray * n);
extern mxArray * mlfPolyfit(mxArray * * S,
                            mxArray * * mu,
                            mxArray * x,
                            mxArray * y,
                            mxArray * n);
extern void mlfVPolyfit(mxArray * x, mxArray * y, mxArray * n);
extern void mlxPolyfit(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPascal(mxArray * n, mxArray * k);
extern void mlxPascal(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPchip(mxArray * x, mxArray * y, mxArray * u);
extern void mlxPchip(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPinv(mxArray * A, mxArray * tol);
extern void mlxPinv(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPlanerot(mxArray * * x, mxArray * x_in);
extern void mlxPlanerot(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPol2cart(mxArray * * y,
                             mxArray * * z,
                             mxArray * th,
                             mxArray * r,
                             mxArray * z_in);
extern void mlxPol2cart(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPoly(mxArray * x);
extern void mlxPoly(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPolyvalm(mxArray * c, mxArray * x);
extern void mlxPolyvalm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPerms(mxArray * V);
extern void mlxPerms(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPolyarea(mxArray * x, mxArray * y, mxArray * dim);
extern void mlxPolyarea(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNPolyder(int nargout,
                             mxArray * * b,
                             mxArray * u,
                             mxArray * v);
extern mxArray * mlfPolyder(mxArray * * b, mxArray * u, mxArray * v);
extern void mlfVPolyder(mxArray * u, mxArray * v);
extern void mlxPolyder(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPpval(mxArray * pp, mxArray * xx);
extern void mlxPpval(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPrimes(mxArray * n);
extern void mlxPrimes(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNPolyval(int nargout,
                             mxArray * * delta,
                             mxArray * p,
                             mxArray * x,
                             mxArray * S,
                             mxArray * mu);
extern mxArray * mlfPolyval(mxArray * * delta,
                            mxArray * p,
                            mxArray * x,
                            mxArray * S,
                            mxArray * mu);
extern void mlfVPolyval(mxArray * p, mxArray * x, mxArray * S, mxArray * mu);
extern void mlxPolyval(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNPolyeig(int nargout, mxArray * * E, ...);
extern mxArray * mlfPolyeig(mxArray * * E, ...);
extern void mlfVPolyeig(mxArray * synthetic_varargin_argument, ...);
extern void mlxPolyeig(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfPwd(void);
extern void mlxPwd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfQrdelete(mxArray * * R,
                             mxArray * Q_in,
                             mxArray * R_in,
                             mxArray * j);
extern void mlxQrdelete(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfQrinsert(mxArray * * R,
                             mxArray * Q_in,
                             mxArray * R_in,
                             mxArray * j,
                             mxArray * x);
extern void mlxQrinsert(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfQuad(mxArray * * fcnt,
                         mxArray * funfcn,
                         mxArray * a,
                         mxArray * b,
                         mxArray * tol,
                         mxArray * trace,
                         ...);
extern void mlxQuad(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfQuad8(mxArray * * cnt,
                          mxArray * funfcn,
                          mxArray * a,
                          mxArray * b,
                          mxArray * tol,
                          mxArray * trace,
                          ...);
extern void mlxQuad8(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRank(mxArray * A, mxArray * tol);
extern void mlxRank(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRoots(mxArray * c);
extern void mlxRoots(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRosser(void);
extern void mlxRosser(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRref(mxArray * * jb, mxArray * A_in, mxArray * tol);
extern void mlxRref(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRsf2csf(mxArray * * T, mxArray * U_in, mxArray * T_in);
extern void mlxRsf2csf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRealmax(void);
extern void mlxRealmax(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRealmin(void);
extern void mlxRealmin(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRectint(mxArray * A, mxArray * B);
extern void mlxRectint(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRepmat(mxArray * A, mxArray * M, mxArray * N);
extern void mlxRepmat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfResi2(mxArray * u,
                          mxArray * v,
                          mxArray * pole,
                          mxArray * n,
                          mxArray * k);
extern void mlxResi2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfResidue(mxArray * * poles,
                            mxArray * * k,
                            mxArray * u,
                            mxArray * v,
                            mxArray * k_in);
extern void mlxResidue(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRot90(mxArray * A, mxArray * k);
extern void mlxRot90(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNRat(int nargout,
                         mxArray * * D,
                         mxArray * X,
                         mxArray * tol);
extern mxArray * mlfRat(mxArray * * D, mxArray * X, mxArray * tol);
extern void mlfVRat(mxArray * X, mxArray * tol);
extern void mlxRat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRats(mxArray * X, mxArray * lens);
extern void mlxRats(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSetfield(mxArray * s_in, ...);
extern void mlxSetfield(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSec(mxArray * z);
extern void mlxSec(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSech(mxArray * z);
extern void mlxSech(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfShiftdim(mxArray * * nshifts, mxArray * x, mxArray * n);
extern void mlxShiftdim(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSph2cart(mxArray * * y,
                             mxArray * * z,
                             mxArray * az,
                             mxArray * elev,
                             mxArray * r);
extern void mlxSph2cart(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpline(mxArray * x, mxArray * y, mxArray * xx);
extern void mlxSpline(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSubspace(mxArray * A, mxArray * B);
extern void mlxSubspace(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNSqrtm(int nargout,
                           mxArray * * arg2,
                           mxArray * * condest,
                           mxArray * A);
extern mxArray * mlfSqrtm(mxArray * * arg2, mxArray * * condest, mxArray * A);
extern void mlfVSqrtm(mxArray * A);
extern void mlxSqrtm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStr2double(mxArray * s);
extern void mlxStr2double(int nlhs,
                          mxArray * plhs[],
                          int nrhs,
                          mxArray * prhs[]);
extern mxArray * mlfStr2mat(mxArray * synthetic_varargin_argument, ...);
extern void mlxStr2mat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStr2num(mxArray * s);
extern void mlxStr2num(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStrjust(mxArray * s, mxArray * justify);
extern void mlxStrjust(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNStrtok(int nargout,
                            mxArray * * remainder,
                            mxArray * string,
                            mxArray * delimiters);
extern mxArray * mlfStrtok(mxArray * * remainder,
                           mxArray * string,
                           mxArray * delimiters);
extern void mlfVStrtok(mxArray * string, mxArray * delimiters);
extern void mlxStrtok(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSortrows(mxArray * * ndx, mxArray * x, mxArray * col);
extern void mlxSortrows(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSplncore(mxArray * x,
                             mxArray * v,
                             mxArray * xi,
                             mxArray * flag);
extern void mlxSplncore(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStd(mxArray * x, mxArray * flag, mxArray * dim);
extern void mlxStd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStrvcat(mxArray * synthetic_varargin_argument, ...);
extern void mlxStrvcat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTable1(mxArray * tab, mxArray * x0);
extern void mlxTable1(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTable2(mxArray * tab, mxArray * x0, mxArray * y0);
extern void mlxTable2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void mlfTic(void);
extern void mlxTic(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNToc(int nargout);
extern mxArray * mlfToc(void);
extern void mlfVToc(void);
extern void mlxToc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfToeplitz(mxArray * c, mxArray * r);
extern void mlxToeplitz(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTsearch(mxArray * x,
                            mxArray * y,
                            mxArray * tri,
                            mxArray * xi,
                            mxArray * yi);
extern void mlxTsearch(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTrace(mxArray * a);
extern void mlxTrace(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTrapz(mxArray * x, mxArray * y, mxArray * dim);
extern void mlxTrapz(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTempdir(void);
extern void mlxTempdir(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfTempname(void);
extern void mlxTempname(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfUnmkpp(mxArray * * coefs,
                           mxArray * * l,
                           mxArray * * k,
                           mxArray * * d,
                           mxArray * pp);
extern void mlxUnmkpp(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfUnwrap(mxArray * p, mxArray * cutoff, mxArray * dim);
extern void mlxUnwrap(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfVander(mxArray * v);
extern void mlxVander(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfVectorize(mxArray * s);
extern void mlxVectorize(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfWilkinson(mxArray * n);
extern void mlxWilkinson(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfWeekday(mxArray * * w, mxArray * t);
extern void mlxWeekday(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfXor(mxArray * S, mxArray * T);
extern void mlxXor(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfXychk(mxArray * * x, mxArray * * y, mxArray * * xi, ...);
extern void mlxXychk(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfXyzchk(mxArray * * x,
                           mxArray * * y,
                           mxArray * * z,
                           mxArray * * out5,
                           mxArray * * out6,
                           mxArray * arg1,
                           mxArray * arg2,
                           mxArray * arg3,
                           mxArray * arg4,
                           mxArray * arg5);
extern void mlxXyzchk(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfMpoles(mxArray * * indx,
                           mxArray * p,
                           mxArray * mpoles_tol,
                           mxArray * reorder);
extern void mlxMpoles(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void mlfMbintvector(mxArray * a);
extern void mlxMbintvector(int nlhs,
                           mxArray * plhs[],
                           int nrhs,
                           mxArray * prhs[]);
extern void mlfMbrealvector(mxArray * a);
extern void mlxMbrealvector(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern void mlfMbintscalar(mxArray * a);
extern void mlxMbintscalar(int nlhs,
                           mxArray * plhs[],
                           int nrhs,
                           mxArray * prhs[]);
extern void mlfMbrealscalar(mxArray * a);
extern void mlxMbrealscalar(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern void mlfMbcharvector(mxArray * a);
extern void mlxMbcharvector(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern void mlfMbcharscalar(mxArray * a);
extern void mlxMbcharscalar(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern mxArray * mlfReallog(mxArray * b);
extern void mlxReallog(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRealpow(mxArray * b, mxArray * c);
extern void mlxRealpow(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRealsqrt(mxArray * b);
extern void mlxRealsqrt(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfUsejava(mxArray * feature);
extern void mlxUsejava(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRmfield(mxArray * s, mxArray * field);
extern void mlxRmfield(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsfield(mxArray * s, mxArray * f);
extern void mlxIsfield(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIsstruct(mxArray * a);
extern void mlxIsstruct(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void mlfCelldisp(mxArray * c, mxArray * s);
extern void mlxCelldisp(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNum2cell(mxArray * a, mxArray * dims);
extern void mlxNum2cell(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNDeal(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfDeal(mlfVarargoutList * varargout, ...);
extern void mlfVDeal(mxArray * synthetic_varargin_argument, ...);
extern void mlxDeal(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfCellstr(mxArray * s);
extern void mlxCellstr(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNInd2sub(int nargout,
                             mlfVarargoutList * varargout,
                             mxArray * siz,
                             mxArray * ndx);
extern mxArray * mlfInd2sub(mlfVarargoutList * varargout,
                            mxArray * siz,
                            mxArray * ndx);
extern void mlfVInd2sub(mxArray * siz, mxArray * ndx);
extern void mlxInd2sub(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSub2ind(mxArray * siz, ...);
extern void mlxSub2ind(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpeye(mxArray * m, mxArray * n);
extern void mlxSpeye(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSprand(mxArray * arg1,
                           mxArray * n,
                           mxArray * density,
                           mxArray * rc);
extern void mlxSprand(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSprandn(mxArray * arg1,
                            mxArray * n,
                            mxArray * density,
                            mxArray * rc);
extern void mlxSprandn(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSprandsym(mxArray * arg1,
                              mxArray * density,
                              mxArray * rcond,
                              mxArray * kind);
extern void mlxSprandsym(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfSpdiags(mxArray * * res2,
                            mxArray * arg1,
                            mxArray * arg2,
                            mxArray * arg3,
                            mxArray * arg4);
extern void mlxSpdiags(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpconvert(mxArray * D);
extern void mlxSpconvert(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfNnz(mxArray * S);
extern void mlxNnz(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNonzeros(mxArray * S);
extern void mlxNonzeros(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNzmax(mxArray * S);
extern void mlxNzmax(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpones(mxArray * S);
extern void mlxSpones(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpalloc(mxArray * m, mxArray * n, mxArray * nzmax);
extern void mlxSpalloc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpfun(mxArray * fun, mxArray * s);
extern void mlxSpfun(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfColmmd(mxArray * S);
extern void mlxColmmd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSymmmd(mxArray * S);
extern void mlxSymmmd(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSymrcm(mxArray * S);
extern void mlxSymrcm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfColperm(mxArray * S);
extern void mlxColperm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfRandperm(mxArray * n);
extern void mlxRandperm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNDmperm(int nargout,
                            mxArray * * q,
                            mxArray * * r,
                            mxArray * * s,
                            mxArray * A);
extern mxArray * mlfDmperm(mxArray * * q,
                           mxArray * * r,
                           mxArray * * s,
                           mxArray * A);
extern void mlfVDmperm(mxArray * A);
extern void mlxDmperm(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNEigs(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfEigs(mlfVarargoutList * varargout, ...);
extern void mlfVEigs(mxArray * synthetic_varargin_argument, ...);
extern void mlxEigs(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNSvds(int nargout,
                          mxArray * * S,
                          mxArray * * V,
                          mxArray * * flag,
                          ...);
extern mxArray * mlfSvds(mxArray * * S, mxArray * * V, mxArray * * flag, ...);
extern void mlfVSvds(mxArray * synthetic_varargin_argument, ...);
extern void mlxSvds(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNPcg(int nargout,
                         mxArray * * flag,
                         mxArray * * relres,
                         mxArray * * iter,
                         mxArray * * resvec,
                         mxArray * A,
                         mxArray * b,
                         mxArray * tol,
                         mxArray * maxit,
                         mxArray * M1,
                         mxArray * M2,
                         mxArray * x0,
                         ...);
extern mxArray * mlfPcg(mxArray * * flag,
                        mxArray * * relres,
                        mxArray * * iter,
                        mxArray * * resvec,
                        mxArray * A,
                        mxArray * b,
                        mxArray * tol,
                        mxArray * maxit,
                        mxArray * M1,
                        mxArray * M2,
                        mxArray * x0,
                        ...);
extern void mlfVPcg(mxArray * A,
                    mxArray * b,
                    mxArray * tol,
                    mxArray * maxit,
                    mxArray * M1,
                    mxArray * M2,
                    mxArray * x0,
                    ...);
extern void mlxPcg(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNBicg(int nargout,
                          mxArray * * flag,
                          mxArray * * relres,
                          mxArray * * iter,
                          mxArray * * resvec,
                          mxArray * A,
                          mxArray * b,
                          mxArray * tol,
                          mxArray * maxit,
                          mxArray * M1,
                          mxArray * M2,
                          mxArray * x0,
                          ...);
extern mxArray * mlfBicg(mxArray * * flag,
                         mxArray * * relres,
                         mxArray * * iter,
                         mxArray * * resvec,
                         mxArray * A,
                         mxArray * b,
                         mxArray * tol,
                         mxArray * maxit,
                         mxArray * M1,
                         mxArray * M2,
                         mxArray * x0,
                         ...);
extern void mlfVBicg(mxArray * A,
                     mxArray * b,
                     mxArray * tol,
                     mxArray * maxit,
                     mxArray * M1,
                     mxArray * M2,
                     mxArray * x0,
                     ...);
extern void mlxBicg(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNBicgstab(int nargout,
                              mxArray * * flag,
                              mxArray * * relres,
                              mxArray * * iter,
                              mxArray * * resvec,
                              mxArray * A,
                              mxArray * b,
                              mxArray * tol,
                              mxArray * maxit,
                              mxArray * M1,
                              mxArray * M2,
                              mxArray * x0,
                              ...);
extern mxArray * mlfBicgstab(mxArray * * flag,
                             mxArray * * relres,
                             mxArray * * iter,
                             mxArray * * resvec,
                             mxArray * A,
                             mxArray * b,
                             mxArray * tol,
                             mxArray * maxit,
                             mxArray * M1,
                             mxArray * M2,
                             mxArray * x0,
                             ...);
extern void mlfVBicgstab(mxArray * A,
                         mxArray * b,
                         mxArray * tol,
                         mxArray * maxit,
                         mxArray * M1,
                         mxArray * M2,
                         mxArray * x0,
                         ...);
extern void mlxBicgstab(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNCgs(int nargout,
                         mxArray * * flag,
                         mxArray * * relres,
                         mxArray * * iter,
                         mxArray * * resvec,
                         mxArray * A,
                         mxArray * b,
                         mxArray * tol,
                         mxArray * maxit,
                         mxArray * M1,
                         mxArray * M2,
                         mxArray * x0,
                         ...);
extern mxArray * mlfCgs(mxArray * * flag,
                        mxArray * * relres,
                        mxArray * * iter,
                        mxArray * * resvec,
                        mxArray * A,
                        mxArray * b,
                        mxArray * tol,
                        mxArray * maxit,
                        mxArray * M1,
                        mxArray * M2,
                        mxArray * x0,
                        ...);
extern void mlfVCgs(mxArray * A,
                    mxArray * b,
                    mxArray * tol,
                    mxArray * maxit,
                    mxArray * M1,
                    mxArray * M2,
                    mxArray * x0,
                    ...);
extern void mlxCgs(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNGmres(int nargout,
                           mxArray * * flag,
                           mxArray * * relres,
                           mxArray * * iter,
                           mxArray * * resvec,
                           mxArray * A,
                           mxArray * b,
                           mxArray * restart,
                           mxArray * tol,
                           mxArray * maxit,
                           mxArray * M1,
                           mxArray * M2,
                           mxArray * x0,
                           ...);
extern mxArray * mlfGmres(mxArray * * flag,
                          mxArray * * relres,
                          mxArray * * iter,
                          mxArray * * resvec,
                          mxArray * A,
                          mxArray * b,
                          mxArray * restart,
                          mxArray * tol,
                          mxArray * maxit,
                          mxArray * M1,
                          mxArray * M2,
                          mxArray * x0,
                          ...);
extern void mlfVGmres(mxArray * A,
                      mxArray * b,
                      mxArray * restart,
                      mxArray * tol,
                      mxArray * maxit,
                      mxArray * M1,
                      mxArray * M2,
                      mxArray * x0,
                      ...);
extern void mlxGmres(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNQmr(int nargout,
                         mxArray * * flag,
                         mxArray * * relres,
                         mxArray * * iter,
                         mxArray * * resvec,
                         mxArray * A,
                         mxArray * b,
                         mxArray * tol,
                         mxArray * maxit,
                         mxArray * M1,
                         mxArray * M2,
                         mxArray * x0,
                         ...);
extern mxArray * mlfQmr(mxArray * * flag,
                        mxArray * * relres,
                        mxArray * * iter,
                        mxArray * * resvec,
                        mxArray * A,
                        mxArray * b,
                        mxArray * tol,
                        mxArray * maxit,
                        mxArray * M1,
                        mxArray * M2,
                        mxArray * x0,
                        ...);
extern void mlfVQmr(mxArray * A,
                    mxArray * b,
                    mxArray * tol,
                    mxArray * maxit,
                    mxArray * M1,
                    mxArray * M2,
                    mxArray * x0,
                    ...);
extern void mlxQmr(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNSymbfact(int nargout,
                              mxArray * * h,
                              mxArray * * parent,
                              mxArray * * post,
                              mxArray * * R,
                              mxArray * A,
                              mxArray * f);
extern mxArray * mlfSymbfact(mxArray * * h,
                             mxArray * * parent,
                             mxArray * * post,
                             mxArray * * R,
                             mxArray * A,
                             mxArray * f);
extern void mlfVSymbfact(mxArray * A, mxArray * f);
extern void mlxSymbfact(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNSpparms(int nargout,
                             mxArray * * return2,
                             mxArray * arg1,
                             mxArray * arg2);
extern mxArray * mlfSpparms(mxArray * * return2,
                            mxArray * arg1,
                            mxArray * arg2);
extern void mlfVSpparms(mxArray * arg1, mxArray * arg2);
extern void mlxSpparms(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSpaugment(mxArray * A, mxArray * c);
extern void mlxSpaugment(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfRjr(mxArray * A, mxArray * k);
extern void mlxRjr(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNEigs2(int nargout,
                           mlfVarargoutList * varargout,
                           mxArray * A,
                           mxArray * n,
                           mxArray * B,
                           mxArray * k,
                           mxArray * whch,
                           mxArray * sigma,
                           mxArray * cholB,
                           ...);
extern mxArray * mlfEigs2(mlfVarargoutList * varargout,
                          mxArray * A,
                          mxArray * n,
                          mxArray * B,
                          mxArray * k,
                          mxArray * whch,
                          mxArray * sigma,
                          mxArray * cholB,
                          ...);
extern void mlfVEigs2(mxArray * A,
                      mxArray * n,
                      mxArray * B,
                      mxArray * k,
                      mxArray * whch,
                      mxArray * sigma,
                      mxArray * cholB,
                      ...);
extern void mlxEigs2(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAxis(mxArray * * ans2, mxArray * * ans3, ...);
extern void mlxAxis(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfAllchild(mxArray * HandleList);
extern void mlxAllchild(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfGcf(void);
extern void mlxGcf(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfGca(mxArray * fig);
extern void mlxGca(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void mlfHold(mxArray * opt_hold_state);
extern void mlxHold(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfIshold(mxArray * ca);
extern void mlxIshold(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void mlfRefresh(mxArray * h);
extern void mlxRefresh(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNView(int nargout,
                          mxArray * * ret2,
                          mxArray * arg1,
                          mxArray * arg2,
                          mxArray * arg3);
extern mxArray * mlfView(mxArray * * ret2,
                         mxArray * arg1,
                         mxArray * arg2,
                         mxArray * arg3);
extern void mlfVView(mxArray * arg1, mxArray * arg2, mxArray * arg3);
extern void mlxView(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfDeblank(mxArray * s);
extern void mlxDeblank(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNIntersect(int nargout,
                               mxArray * * ia,
                               mxArray * * ib,
                               mxArray * a,
                               mxArray * b,
                               mxArray * flag);
extern mxArray * mlfIntersect(mxArray * * ia,
                              mxArray * * ib,
                              mxArray * a,
                              mxArray * b,
                              mxArray * flag);
extern void mlfVIntersect(mxArray * a, mxArray * b, mxArray * flag);
extern void mlxIntersect(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfIsmember(mxArray * a, mxArray * s, mxArray * flag);
extern void mlxIsmember(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfSetdiff(mxArray * * ia,
                            mxArray * a,
                            mxArray * b,
                            mxArray * flag);
extern void mlxSetdiff(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNSetxor(int nargout,
                            mxArray * * ia,
                            mxArray * * ib,
                            mxArray * a,
                            mxArray * b,
                            mxArray * flag);
extern mxArray * mlfSetxor(mxArray * * ia,
                           mxArray * * ib,
                           mxArray * a,
                           mxArray * b,
                           mxArray * flag);
extern void mlfVSetxor(mxArray * a, mxArray * b, mxArray * flag);
extern void mlxSetxor(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStrcat(mxArray * synthetic_varargin_argument, ...);
extern void mlxStrcat(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfStrmatch(mxArray * str, mxArray * strs, mxArray * flag);
extern void mlxStrmatch(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNUnion(int nargout,
                           mxArray * * ia,
                           mxArray * * ib,
                           mxArray * a,
                           mxArray * b,
                           mxArray * flag);
extern mxArray * mlfUnion(mxArray * * ia,
                          mxArray * * ib,
                          mxArray * a,
                          mxArray * b,
                          mxArray * flag);
extern void mlfVUnion(mxArray * a, mxArray * b, mxArray * flag);
extern void mlxUnion(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNUnique(int nargout,
                            mxArray * * ndx,
                            mxArray * * pos,
                            mxArray * a,
                            mxArray * flag);
extern mxArray * mlfUnique(mxArray * * ndx,
                           mxArray * * pos,
                           mxArray * a,
                           mxArray * flag);
extern void mlfVUnique(mxArray * a, mxArray * flag);
extern void mlxUnique(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlf_cell_deblank(mxArray * s);
extern void mlx_cell_deblank(int nlhs,
                             mxArray * plhs[],
                             int nrhs,
                             mxArray * prhs[]);
extern mxArray * mlf_cell_intersect(mxArray * * ia,
                                    mxArray * * ib,
                                    mxArray * a,
                                    mxArray * b,
                                    mxArray * flag);
extern void mlx_cell_intersect(int nlhs,
                               mxArray * plhs[],
                               int nrhs,
                               mxArray * prhs[]);
extern mxArray * mlf_cell_ismember(mxArray * a, mxArray * s, mxArray * flag);
extern void mlx_cell_ismember(int nlhs,
                              mxArray * plhs[],
                              int nrhs,
                              mxArray * prhs[]);
extern mxArray * mlf_cell_setdiff(mxArray * * ia,
                                  mxArray * a,
                                  mxArray * b,
                                  mxArray * flag);
extern void mlx_cell_setdiff(int nlhs,
                             mxArray * plhs[],
                             int nrhs,
                             mxArray * prhs[]);
extern mxArray * mlf_cell_setxor(mxArray * * ia,
                                 mxArray * * ib,
                                 mxArray * a,
                                 mxArray * b,
                                 mxArray * flag);
extern void mlx_cell_setxor(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern mxArray * mlf_cell_strcat(mxArray * synthetic_varargin_argument, ...);
extern void mlx_cell_strcat(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern mxArray * mlf_cell_strmatch(mxArray * str,
                                   mxArray * strs,
                                   mxArray * flag);
extern void mlx_cell_strmatch(int nlhs,
                              mxArray * plhs[],
                              int nrhs,
                              mxArray * prhs[]);
extern mxArray * mlfN_cell_union(int nargout,
                                 mxArray * * ia,
                                 mxArray * * ib,
                                 mxArray * a,
                                 mxArray * b,
                                 mxArray * flag);
extern mxArray * mlf_cell_union(mxArray * * ia,
                                mxArray * * ib,
                                mxArray * a,
                                mxArray * b,
                                mxArray * flag);
extern void mlfV_cell_union(mxArray * a, mxArray * b, mxArray * flag);
extern void mlx_cell_union(int nlhs,
                           mxArray * plhs[],
                           int nrhs,
                           mxArray * prhs[]);
extern mxArray * mlf_cell_unique(mxArray * * ndx,
                                 mxArray * * pos,
                                 mxArray * a,
                                 mxArray * flag);
extern void mlx_cell_unique(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern mxArray * mlf_cell_sort(mxArray * * i, mxArray * x, mxArray * dim);
extern void mlx_cell_sort(int nlhs,
                          mxArray * plhs[],
                          int nrhs,
                          mxArray * prhs[]);
extern void mlf_char_delete(mxArray * synthetic_varargin_argument, ...);
extern void mlx_char_delete(int nlhs,
                            mxArray * plhs[],
                            int nrhs,
                            mxArray * prhs[]);
extern mxArray * mlfNArpackc(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfArpackc(mlfVarargoutList * varargout, ...);
extern void mlfVArpackc(mxArray * synthetic_varargin_argument, ...);
extern void mlxArpackc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNComplex(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfComplex(mlfVarargoutList * varargout, ...);
extern void mlfVComplex(mxArray * synthetic_varargin_argument, ...);
extern void mlxComplex(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNGamma(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfGamma(mlfVarargoutList * varargout, ...);
extern void mlfVGamma(mxArray * synthetic_varargin_argument, ...);
extern void mlxGamma(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNErfcore(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfErfcore(mlfVarargoutList * varargout, ...);
extern void mlfVErfcore(mxArray * synthetic_varargin_argument, ...);
extern void mlxErfcore(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNGammaln(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfGammaln(mlfVarargoutList * varargout, ...);
extern void mlfVGammaln(mxArray * synthetic_varargin_argument, ...);
extern void mlxGammaln(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNHistc(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfHistc(mlfVarargoutList * varargout, ...);
extern void mlfVHistc(mxArray * synthetic_varargin_argument, ...);
extern void mlxHistc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNIsmembc(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfIsmembc(mlfVarargoutList * varargout, ...);
extern void mlfVIsmembc(mxArray * synthetic_varargin_argument, ...);
extern void mlxIsmembc(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNCellfun(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfCellfun(mlfVarargoutList * varargout, ...);
extern void mlfVCellfun(mxArray * synthetic_varargin_argument, ...);
extern void mlxCellfun(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern mxArray * mlfNDatenummx(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfDatenummx(mlfVarargoutList * varargout, ...);
extern void mlfVDatenummx(mxArray * synthetic_varargin_argument, ...);
extern void mlxDatenummx(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfNDatevecmx(int nargout, mlfVarargoutList * varargout, ...);
extern mxArray * mlfDatevecmx(mlfVarargoutList * varargout, ...);
extern void mlfVDatevecmx(mxArray * synthetic_varargin_argument, ...);
extern void mlxDatevecmx(int nlhs,
                         mxArray * plhs[],
                         int nrhs,
                         mxArray * prhs[]);
extern mxArray * mlfNPolyfun_private_cubicmx(int nargout,
                                             mlfVarargoutList * varargout,
                                             ...);
extern mxArray * mlfPolyfun_private_cubicmx(mlfVarargoutList * varargout, ...);
extern void mlfVPolyfun_private_cubicmx(mxArray * synthetic_varargin_argument,
                                        ...);
extern void mlxPolyfun_private_cubicmx(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfNPolyfun_private_qhullmx(int nargout,
                                             mlfVarargoutList * varargout,
                                             ...);
extern mxArray * mlfPolyfun_private_qhullmx(mlfVarargoutList * varargout, ...);
extern void mlfVPolyfun_private_qhullmx(mxArray * synthetic_varargin_argument,
                                        ...);
extern void mlxPolyfun_private_qhullmx(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfNPolyfun_private_tsrchmx(int nargout,
                                             mlfVarargoutList * varargout,
                                             ...);
extern mxArray * mlfPolyfun_private_tsrchmx(mlfVarargoutList * varargout, ...);
extern void mlfVPolyfun_private_tsrchmx(mxArray * synthetic_varargin_argument,
                                        ...);
extern void mlxPolyfun_private_tsrchmx(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfNPolyfun_private_delaunayc(int nargout,
                                               mlfVarargoutList * varargout,
                                               ...);
extern mxArray * mlfPolyfun_private_delaunayc(mlfVarargoutList * varargout,
                                              ...);
extern void mlfVPolyfun_private_delaunayc(mxArray * synthetic_varargin_argument,
                                          ...);
extern void mlxPolyfun_private_delaunayc(int nlhs,
                                         mxArray * plhs[],
                                         int nrhs,
                                         mxArray * prhs[]);
extern mxArray * mlfNPolyfun_private_dsrchmx(int nargout,
                                             mlfVarargoutList * varargout,
                                             ...);
extern mxArray * mlfPolyfun_private_dsrchmx(mlfVarargoutList * varargout, ...);
extern void mlfVPolyfun_private_dsrchmx(mxArray * synthetic_varargin_argument,
                                        ...);
extern void mlxPolyfun_private_dsrchmx(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfFunfun_private_daeic3(mxArray * * yp,
                                          mxArray * * f,
                                          mxArray * * DfDy,
                                          mxArray * * nFE,
                                          mxArray * * nPD,
                                          mxArray * * fac,
                                          mxArray * * g,
                                          mxArray * fun,
                                          mxArray * args,
                                          mxArray * tspan,
                                          mxArray * htry,
                                          mxArray * Mtype,
                                          mxArray * M0,
                                          mxArray * Mfun,
                                          mxArray * Margs,
                                          mxArray * Mvs,
                                          mxArray * y0,
                                          mxArray * yp0,
                                          mxArray * f0,
                                          mxArray * reltol,
                                          mxArray * Jconstant,
                                          mxArray * Janalytic,
                                          mxArray * Jac,
                                          mxArray * Jargs,
                                          mxArray * thresh,
                                          mxArray * vectorized,
                                          mxArray * Js);
extern void mlxFunfun_private_daeic3(int nlhs,
                                     mxArray * plhs[],
                                     int nrhs,
                                     mxArray * prhs[]);
extern mxArray * mlfFunfun_private_daeic12(mxArray * * yp,
                                           mxArray * * f,
                                           mxArray * * DfDy,
                                           mxArray * * nFE,
                                           mxArray * * nPD,
                                           mxArray * * fac,
                                           mxArray * * g,
                                           mxArray * fun,
                                           mxArray * args,
                                           mxArray * t0,
                                           mxArray * ICtype,
                                           mxArray * M0,
                                           mxArray * y_in,
                                           mxArray * yp0,
                                           mxArray * f_in,
                                           mxArray * reltol,
                                           mxArray * Jconstant,
                                           mxArray * Janalytic,
                                           mxArray * Jac,
                                           mxArray * Jargs,
                                           mxArray * thresh,
                                           mxArray * vectorized,
                                           mxArray * Js);
extern void mlxFunfun_private_daeic12(int nlhs,
                                      mxArray * plhs[],
                                      int nrhs,
                                      mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odemxv(mxArray * t,
                                          mxArray * y,
                                          mxArray * Mfun,
                                          mxArray * Margs,
                                          mxArray * v);
extern void mlxFunfun_private_odemxv(int nlhs,
                                     mxArray * plhs[],
                                     int nrhs,
                                     mxArray * prhs[]);
extern mxArray * mlfFunfun_private_colgroup(mxArray * S);
extern void mlxFunfun_private_colgroup(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odezero(mxArray * * yout,
                                           mxArray * * iout,
                                           mxArray * * vnew,
                                           mxArray * * stop,
                                           mxArray * ntrpfun,
                                           mxArray * eventfun,
                                           mxArray * eventargs,
                                           mxArray * v,
                                           mxArray * t,
                                           mxArray * y,
                                           mxArray * tnew,
                                           mxArray * ynew,
                                           mxArray * t0,
                                           ...);
extern void mlxFunfun_private_odezero(int nlhs,
                                      mxArray * plhs[],
                                      int nrhs,
                                      mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odearguments(mxArray * * tspan,
                                                mxArray * * ntspan,
                                                mxArray * * next,
                                                mxArray * * t0,
                                                mxArray * * tfinal,
                                                mxArray * * tdir,
                                                mxArray * * y0,
                                                mxArray * * f0,
                                                mxArray * * args,
                                                mxArray * * options,
                                                mxArray * * atol,
                                                mxArray * * rtol,
                                                mxArray * * threshold,
                                                mxArray * * normcontrol,
                                                mxArray * * normy,
                                                mxArray * * hmax,
                                                mxArray * * htry,
                                                mxArray * FcnHandlesUsed,
                                                mxArray * solver,
                                                mxArray * ode,
                                                mxArray * tspan_in,
                                                mxArray * y0_in,
                                                mxArray * options_in,
                                                mxArray * extras);
extern void mlxFunfun_private_odearguments(int nlhs,
                                           mxArray * plhs[],
                                           int nrhs,
                                           mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odemass(mxArray * * massFcn,
                                           mxArray * * massArgs,
                                           mxArray * * massM,
                                           mxArray * * Mvs,
                                           mxArray * * Mfac,
                                           mxArray * FcnHandlesUsed,
                                           mxArray * ode,
                                           mxArray * t0,
                                           mxArray * y0,
                                           mxArray * options,
                                           mxArray * extras);
extern void mlxFunfun_private_odemass(int nlhs,
                                      mxArray * plhs[],
                                      int nrhs,
                                      mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odeevents(mxArray * * eventFcn,
                                             mxArray * * eventArgs,
                                             mxArray * * eventValue,
                                             mxArray * * teout,
                                             mxArray * * yeout,
                                             mxArray * * ieout,
                                             mxArray * FcnHandlesUsed,
                                             mxArray * ode,
                                             mxArray * t0,
                                             mxArray * y0,
                                             mxArray * options,
                                             mxArray * extras);
extern void mlxFunfun_private_odeevents(int nlhs,
                                        mxArray * plhs[],
                                        int nrhs,
                                        mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odejacobian(mxArray * * Janalytic,
                                               mxArray * * JacFcn,
                                               mxArray * * JacArgs,
                                               mxArray * * JacPattern,
                                               mxArray * * jthresh,
                                               mxArray * * vectorized,
                                               mxArray * FcnHandlesUsed,
                                               mxArray * ode,
                                               mxArray * t0,
                                               mxArray * y0,
                                               mxArray * options,
                                               mxArray * extras);
extern void mlxFunfun_private_odejacobian(int nlhs,
                                          mxArray * plhs[],
                                          int nrhs,
                                          mxArray * prhs[]);
extern mxArray * mlfFunfun_private_odemassexplicit(mxArray * * odeArgs,
                                                   mxArray * FcnHandlesUsed,
                                                   mxArray * massType,
                                                   mxArray * odeFcn_in,
                                                   mxArray * odeArgs_in,
                                                   mxArray * massFcn,
                                                   mxArray * massArgs,
                                                   mxArray * massL,
                                                   mxArray * massU);
extern void mlxFunfun_private_odemassexplicit(int nlhs,
                                              mxArray * plhs[],
                                              int nrhs,
                                              mxArray * prhs[]);
extern mxArray * mlfFunfun_private_funstring(mxArray * fun);
extern void mlxFunfun_private_funstring(int nlhs,
                                        mxArray * plhs[],
                                        int nrhs,
                                        mxArray * prhs[]);
extern mxArray * mlfSparfun_private_iterchk(mxArray * * afun,
                                            mxArray * * afcnstr,
                                            mxArray * A);
extern void mlxSparfun_private_iterchk(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfSparfun_private_iterapp(mxArray * afun,
                                            mxArray * atype,
                                            mxArray * afcnstr,
                                            mxArray * x,
                                            ...);
extern void mlxSparfun_private_iterapp(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlfSparfun_private_itermsg(mxArray * itermeth,
                                            mxArray * tol,
                                            mxArray * maxit,
                                            mxArray * i,
                                            mxArray * flag,
                                            mxArray * iter,
                                            mxArray * relres);
extern void mlxSparfun_private_itermsg(int nlhs,
                                       mxArray * plhs[],
                                       int nrhs,
                                       mxArray * prhs[]);
extern mxArray * mlf_default_deblank(mxArray * s);
extern void mlx_default_deblank(int nlhs,
                                mxArray * plhs[],
                                int nrhs,
                                mxArray * prhs[]);
extern mxArray * mlfN_default_intersect(int nargout,
                                        mxArray * * ia,
                                        mxArray * * ib,
                                        mxArray * a,
                                        mxArray * b,
                                        mxArray * flag);
extern mxArray * mlf_default_intersect(mxArray * * ia,
                                       mxArray * * ib,
                                       mxArray * a,
                                       mxArray * b,
                                       mxArray * flag);
extern void mlfV_default_intersect(mxArray * a, mxArray * b, mxArray * flag);
extern void mlx_default_intersect(int nlhs,
                                  mxArray * plhs[],
                                  int nrhs,
                                  mxArray * prhs[]);
extern mxArray * mlf_default_ismember(mxArray * a, mxArray * s, mxArray * flag);
extern void mlx_default_ismember(int nlhs,
                                 mxArray * plhs[],
                                 int nrhs,
                                 mxArray * prhs[]);
extern mxArray * mlf_default_setdiff(mxArray * * ia,
                                     mxArray * a,
                                     mxArray * b,
                                     mxArray * flag);
extern void mlx_default_setdiff(int nlhs,
                                mxArray * plhs[],
                                int nrhs,
                                mxArray * prhs[]);
extern mxArray * mlfN_default_setxor(int nargout,
                                     mxArray * * ia,
                                     mxArray * * ib,
                                     mxArray * a,
                                     mxArray * b,
                                     mxArray * flag);
extern mxArray * mlf_default_setxor(mxArray * * ia,
                                    mxArray * * ib,
                                    mxArray * a,
                                    mxArray * b,
                                    mxArray * flag);
extern void mlfV_default_setxor(mxArray * a, mxArray * b, mxArray * flag);
extern void mlx_default_setxor(int nlhs,
                               mxArray * plhs[],
                               int nrhs,
                               mxArray * prhs[]);
extern mxArray * mlf_default_strcat(mxArray * synthetic_varargin_argument, ...);
extern void mlx_default_strcat(int nlhs,
                               mxArray * plhs[],
                               int nrhs,
                               mxArray * prhs[]);
extern mxArray * mlf_default_strmatch(mxArray * str,
                                      mxArray * strs,
                                      mxArray * flag);
extern void mlx_default_strmatch(int nlhs,
                                 mxArray * plhs[],
                                 int nrhs,
                                 mxArray * prhs[]);
extern mxArray * mlfN_default_union(int nargout,
                                    mxArray * * ia,
                                    mxArray * * ib,
                                    mxArray * a,
                                    mxArray * b,
                                    mxArray * flag);
extern mxArray * mlf_default_union(mxArray * * ia,
                                   mxArray * * ib,
                                   mxArray * a,
                                   mxArray * b,
                                   mxArray * flag);
extern void mlfV_default_union(mxArray * a, mxArray * b, mxArray * flag);
extern void mlx_default_union(int nlhs,
                              mxArray * plhs[],
                              int nrhs,
                              mxArray * prhs[]);
extern mxArray * mlfN_default_unique(int nargout,
                                     mxArray * * ndx,
                                     mxArray * * pos,
                                     mxArray * a,
                                     mxArray * flag);
extern mxArray * mlf_default_unique(mxArray * * ndx,
                                    mxArray * * pos,
                                    mxArray * a,
                                    mxArray * flag);
extern void mlfV_default_unique(mxArray * a, mxArray * flag);
extern void mlx_default_unique(int nlhs,
                               mxArray * plhs[],
                               int nrhs,
                               mxArray * prhs[]);
extern void libmmfileInitialize(void);
extern void libmmfileTerminate(void);

#ifdef __cplusplus
}
#endif

#endif
