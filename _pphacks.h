#ifndef YES_I_KNOW_WHAT_I_AM_DOING
#error "Do not include _pphacks.h directly!"
#endif
#undef YES_I_KNOW_WHAT_I_AM_DOING

#ifndef _COMMON_PPHACKS_H_

/* from <dqqj9j$31l$1@rzsun03.rrz.uni-hamburg.de> */
#define _COMMON_PPHACKS_NARG(...) \
         _COMMON_PPHACKS_NARG_(__VA_ARGS__,_COMMON_PPHACKS_RSEQ_N())
#define _COMMON_PPHACKS_NARG_(...) \
         _COMMON_PPHACKS_ARG_N(__VA_ARGS__)
#define _COMMON_PPHACKS_ARG_N( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,N,...) N
#define _COMMON_PPHACKS_RSEQ_N() \
         63,62,61,60,                   \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

#define _COMMON_PPHACKS_PREFIX_1(pfx, stmt) pfx##stmt
#define _COMMON_PPHACKS_PREFIX_2(pfx, stmt, ...) \
      pfx##stmt , _COMMON_PPHACKS_PREFIX_1(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_3(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_2(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_4(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_3(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_5(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_4(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_6(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_5(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_7(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_6(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_8(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_7(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_9(pfx, stmt, ...) \
      pfx##stmt, _COMMON_PPHACKS_PREFIX_8(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_10(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_9(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_11(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_10(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_12(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_11(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_13(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_12(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_14(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_13(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_15(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_14(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_16(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_15(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_17(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_16(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_18(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_17(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_19(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_18(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_20(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_19(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_21(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_20(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_22(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_21(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_23(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_22(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_24(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_23(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_25(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_24(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_26(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_25(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_27(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_26(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_28(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_27(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_29(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_28(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_30(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_29(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_31(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_30(pfx, __VA_ARGS__)
#define _COMMON_PPHACKS_PREFIX_32(pfx, stmt, ...) \
     pfx##stmt, _COMMON_PPHACKS_PREFIX_31(pfx, __VA_ARGS__)

#define _COMMON_PPHACKS_FUNCALL_1(fun, sep, stmt)       fun(stmt)
#define _COMMON_PPHACKS_FUNCALL_2(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_1(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_3(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_2(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_4(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_3(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_5(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_4(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_6(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_5(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_7(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_6(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_8(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_7(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_9(fun, sep, stmt, ...) \
      fun(stmt) sep _COMMON_PPHACKS_FUNCALL_8(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_10(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_9(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_11(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_10(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_12(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_11(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_13(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_12(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_14(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_13(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_15(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_14(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_16(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_15(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_17(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_16(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_18(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_17(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_19(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_18(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_20(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_19(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_21(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_20(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_22(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_21(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_23(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_22(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_24(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_23(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_25(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_24(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_26(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_25(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_27(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_26(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_28(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_27(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_29(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_28(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_30(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_29(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_31(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_30(fun, sep, __VA_ARGS__)
#define _COMMON_PPHACKS_FUNCALL_32(fun, sep, stmt, ...) \
     fun(stmt) sep _COMMON_PPHACKS_FUNCALL_31(fun, sep, __VA_ARGS__)

#define _COMMON_PPHACKS_CAT(a, b)   a ## b
#define _COMMON_PPHACKS_XCAT(a, b)  _COMMON_PPHACKS_CAT(a, b)

#define FUNCALL(fun, sep, ...) \
    _COMMON_PPHACKS_XCAT(_COMMON_PPHACKS_FUNCALL_, _COMMON_PPHACKS_NARG(__VA_ARGS__))(fun, sep, __VA_ARGS__)

#define PREFIX(pfx, ...) \
    _COMMON_PPHACKS_XCAT(_COMMON_PPHACKS_PREFIX_, _COMMON_PPHACKS_NARG(__VA_ARGS__))(pfx, __VA_ARGS__)

#endif
