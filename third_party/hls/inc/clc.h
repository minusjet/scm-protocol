
/*
 Copyright 2013 Xilinx, Inc. All rights reserved.
 This file contains confidential and proprietary information
 of Xilinx, Inc. and is protected under U.S. and
 international copyright and other intellectual property
 laws.

 DISCLAIMER
 This disclaimer is not a license and does not grant any
 rights to the materials distributed herewith. Except as
 otherwise provided in a valid license issued to you by
 Xilinx, and to the maximum extent permitted by applicable
 law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
 WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
 AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
 INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
 (2) Xilinx shall not be liable (whether in contract or tort,
 including negligence, or under any other theory of
 liability) for any loss or damage of any kind or nature
 related to, arising under or in connection with these
 materials, including for any direct, or any indirect,
 special, incidental, or consequential loss or damage
 (including loss of data, profits, goodwill, or any type of
 loss or damage suffered as a result of any action brought
 by a third party) even if such damage or loss was
 reasonably foreseeable or Xilinx had been advised of the
 possibility of the same.
 CRITICAL APPLICATIONS
 Xilinx products are not designed or intended to be fail-
 safe, or for use in any application requiring fail-safe
 performance, such as life-support or safety devices or
 systems, Class III medical devices, nuclear facilities,
 applications related to the deployment of airbags, or any
 other applications that could lead to death, personal
 injury, or severe property or environmental damage
 (individually and collectively, "Critical
 Applications"\). Customer assumes the sole risk and
 liability of any use of Xilinx products in Critical
 Applications, subject only to applicable laws and
 regulations governing limitations on product liability.
 THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
 PART OF THIS FILE AT ALL TIMES.
*/
#ifndef _CLC_H_
#define _CLC_H_

#define __xilinx__
#define global __global
#define local __local
#define constant __constant
#define private __private
// typedef image begin
#define image1d_t unsigned char *
#define image1d_buffer_t unsigned char *
#define image1d_array_t unsigned char *
#define image2d_t unsigned int *
#define image2d_array_t unsigned int *
#define image2d_depth_t unsigned int *
#define image2d_array_depth_t unsigned int *
#define image3d_t int *
#define sampler_t unsigned int
#define CLK_SNORM_INT8 0x10D0
#define CLK_SNORM_INT16 0x10D1
#define CLK_UNORM_INT8 0x10D2
#define CLK_UNORM_INT16 0x10D3
#define CLK_UNORM_SHORT_565 0x10D4
#define CLK_UNORM_SHORT_555 0x10D5
#define CLK_UNORM_INT_101010 0x10D6
#define CLK_SIGNED_INT8 0x10D7
#define CLK_SIGNED_INT16 0x10D8
#define CLK_SIGNED_INT32 0x10D9
#define CLK_UNSIGNED_INT8 0x10DA
#define CLK_UNSIGNED_INT16 0x10DB
#define CLK_UNSIGNED_INT32 0x10DC
#define CLK_HALF_FLOAT 0x10DD
#define CLK_FLOAT 0x10DE

/* get_image_channel_order flags */
#define CLK_R 0x10B0
#define CLK_A 0x10B1
#define CLK_RG 0x10B2
#define CLK_RA 0x10B3
#define CLK_RGB 0x10B4
#define CLK_RGBA 0x10B5
#define CLK_BGRA 0x10B6
#define CLK_ARGB 0x10B7
#define CLK_INTENSITY 0x10B8
#define CLK_LUMINANCE 0x10B9
#define CLK_Rx 0x10BA
#define CLK_RGx 0x10BB
#define CLK_RGBx 0x10BC

/* sampler normalized coords */
#define CLK_NORMALIZED_COORDS_FALSE 0x0000
#define CLK_NORMALIZED_COORDS_TRUE 0x0001

/* sampler addressing mode */
#define CLK_ADDRESS_NONE 0x0000
#define CLK_ADDRESS_CLAMP_TO_EDGE 0x0002
#define CLK_ADDRESS_CLAMP 0x0004
#define CLK_ADDRESS_REPEAT 0x0006
#define CLK_ADDRESS_MIRRORED_REPEAT 0x0008

/* sampler filter mode */
#define CLK_FILTER_NEAREST 0x0000
#define CLK_FILTER_LINEAR 0x0010

// typedef image end
// SPIR Specification
// SPIR section 2.1.1 Built-in Scalar Data Types
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
// typedef struct spirhalf* spirhalf;              //todo
#if defined(__SPIR32__)
typedef unsigned int size_t;
typedef unsigned int ptrdiff_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
#elif defined(__SPIR64__)
#if (__clang_major__ == 3) && (__clang_minor__ == 9)
typedef unsigned long size_t;
typedef unsigned long ptrdiff_t;
typedef long intptr_t;
typedef unsigned long uintptr_t;
#else
typedef unsigned long long size_t;
typedef unsigned long long ptrdiff_t;
typedef long long intptr_t;
typedef unsigned long long uintptr_t;
#endif
#else
#error "must compile using spir or spir64 target"
#endif
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(char)))) char char2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(char)))) char char3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(char)))) char char4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(char)))) char char8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(char)))) char char16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(uchar)))) uchar uchar2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(uchar)))) uchar uchar3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(uchar)))) uchar uchar4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(uchar)))) uchar uchar8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(uchar)))) uchar uchar16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(short)))) short short2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(short)))) short short3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(short)))) short short4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(short)))) short short8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(short)))) short short16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(ushort)))) ushort ushort2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(ushort)))) ushort ushort3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(ushort)))) ushort ushort4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(ushort)))) ushort ushort8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(ushort)))) ushort ushort16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(int)))) int int2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(int)))) int int3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(int)))) int int4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(int)))) int int8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(int)))) int int16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(uint)))) uint uint2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(uint)))) uint uint3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(uint)))) uint uint4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(uint)))) uint uint8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(uint)))) uint uint16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(long)))) long long2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(long)))) long long3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(long)))) long long4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(long)))) long long8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(long)))) long long16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(ulong)))) ulong ulong2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(ulong)))) ulong ulong3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(ulong)))) ulong ulong4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(ulong)))) ulong ulong8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(ulong)))) ulong ulong16;
typedef __attribute__((ext_vector_type(2)))
__attribute__((aligned(2 * sizeof(float)))) float float2;
typedef __attribute__((ext_vector_type(3)))
__attribute__((aligned(4 * sizeof(float)))) float float3;
typedef __attribute__((ext_vector_type(4)))
__attribute__((aligned(4 * sizeof(float)))) float float4;
typedef __attribute__((ext_vector_type(8)))
__attribute__((aligned(8 * sizeof(float)))) float float8;
typedef __attribute__((ext_vector_type(16)))
__attribute__((aligned(16 * sizeof(float)))) float float16;
typedef void *reserve_id_t;
// SPIR section 2.10.1.1 Synchronization Functions
#define CLK_LOCAL_MEM_FENCE 0
#define CLK_GLOBAL_MEM_FENCE 1
// OpenCL Section 6.10 Preprocessor Directives and Macros
//__FILE__ defined by GNU CPP
//__LINE__ defined by GNU CPP
#define __OPENCL_VERSION__ CL_VERSION_1_2
#define CL_VERSION_1_0 100
#define CL_VERSION_1_1 110
#define CL_VERSION_1_2 120
#define __OPENCL_C_VERSION__ CL_VERSION_1_2
#define __ENDIAN_LITTLE__ 1
#define __kernel_exec(X, typen)                                                \
  __kernel __attribute__((work_group_size_hint(X, 1, 1)))                      \
      __attribute__(vec_type_hint(typen))
#define kernel_exec(X, typen) __kernel_exec(X, typen)
// define __IMAGE_SUPPORT__      unsupported
// define __FAST_RELAXED_MATH__  unsupported
// OpenCL Section 6.12.3 Integer Function numeric constants
#define CHAR_BIT 8
#define CHAR_MAX SCHAR_MAX
#define CHAR_MIN SCHAR_MIN
#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)
#define LONG_MAX 0x7fffffffffffffffL
#define LONG_MIN (-0x7fffffffffffffffL - 1)
#define SCHAR_MAX 127
#define SCHAR_MIN (-127 - 1)
#define SHRT_MAX 32767
#define SHRT_MIN (-32767 - 1)
#define UCHAR_MAX 255
#define USHRT_MAX 65535
#define UINT_MAX 0xffffffff
#define ULONG_MAX 0xffffffffffffffffUL
// OpenCL Section 6.12.2.1 Floating-point macros and pragmas
#define FLT_DIG 6
#define FLT_MANT_DIG 24
#define FLT_MAX_10_EXP +38
#define FLT_MAX_EXP +128
#define FLT_MIN_10_EXP -37
#define FLT_MIN_EXP -125
#define FLT_RADIX 2
#define FLT_MAX 0x1.fffffep127f
#define FLT_MIN 0x1.0p-126f
#define FLT_EPSILON 0x1.0p-23f
#define FP_ILOGB0 (-2147483647 - 1)
#define FP_ILOGBNAN (-2147483647 - 1)
// OpenCL Section 6.12.2 Math functions P251
// The following constants were generated using generateclconstants
#define M_E_F 2.71828174591064f
#define M_LOG2E_F 1.44269502162933f
#define M_LOG10E_F 0.434294492006302f
#define M_LN2_F 0.6931471824646f
#define M_LN10_F 2.30258512496948f
#define M_PI_F 3.14159274101257f
#define M_PI_2_F 1.57079637050629f
#define M_PI_4_F 0.785398185253143f
#define M_1_PI_F 0.318309873342514f
#define M_2_PI_F 0.636619746685028f
#define M_2_SQRTPI_F 1.1283792257309f
#define M_SQRT2_F 1.41421353816986f
#define M_SQRT1_2_F 0.70710676908493f
#define MAXFLOAT 3.40282346638529e+38f
// from include/bits/huge_valf.h
#define HUGE_VALF                                                              \
  (__extension__((union {                                                      \
     unsigned __l __attribute__((__mode__(__SI__)));                           \
     float __d;                                                                \
   }){__l : 0x7f800000UL})                                                     \
       .__d)
#define INFINITY HUGE_VALF
// from include/bits/nan.h
#define NAN                                                                    \
  (__extension__((union {                                                      \
     unsigned __l __attribute__((__mode__(__SI__)));                           \
     float __d;                                                                \
   }){__l : 0x7fc00000UL})                                                     \
       .__d)
// from include/bits/huge_val.h
#define HUGE_VAL                                                               \
   ((union { unsigned __l __attribute__((__mode__(__DI__))); double __d; })   \
    { __l: 0x7ff0000000000000ULL }).__d)

#if (__clang_major__ == 3) && (__clang_minor__ == 9)
#ifdef __SYNTHESIS__
int printf(__constant char *format, ...);
#else
int __cl_printf(__constant char *__restrict fmt, ...);
#define printf __cl_printf
#endif

#else
int __attribute__((overloadable)) printf(__constant char *format, ...);
#endif

int xilinx_bprintf(__global char *buffer, __constant char *format, ...);

uint __attribute__((overloadable)) get_work_dim(void);
size_t __attribute__((overloadable)) get_global_size(uint dimindx);
size_t __attribute__((overloadable)) get_global_id(uint dimindx);
size_t __attribute__((overloadable)) get_local_size(uint dimindx);
size_t __attribute__((overloadable)) get_local_id(uint dimindx);
size_t __attribute__((overloadable)) get_num_groups(uint dimindx);
size_t __attribute__((overloadable)) get_group_id(uint dimindx);
size_t __attribute__((overloadable)) get_global_offset(uint dimindx);
size_t __attribute__((overloadable)) get_local_linear_id(void);
size_t __attribute__((overloadable)) get_global_linear_id(void);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
as_char3(char4 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
as_uchar(char f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar2(char2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar3(char3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar3(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(char4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(char8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(char16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
as_short(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
as_short2(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(char16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
as_ushort(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort2(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(char16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
as_int(char4 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(char8 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(char16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
as_uint(char4 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(char8 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(char16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(char8 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(char16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(char8 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(char16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
as_float(char4 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(char8 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(char16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
as_char(uchar f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
as_char2(uchar2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
as_char3(uchar3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
as_char3(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(uchar4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(uchar8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(uchar16 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar3(uchar4 f);
short __attribute__((always_inline)) __attribute__((overloadable))
as_short(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
as_short2(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(uchar16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
as_ushort(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort2(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(uchar16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
as_int(uchar4 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(uchar8 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(uchar16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
as_uint(uchar4 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(uchar8 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(uchar16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(uchar8 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(uchar16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(uchar8 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(uchar16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
as_float(uchar4 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(uchar8 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(uchar16 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
as_char2(short f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(short2 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(short4 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(short8 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar2(short f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(short2 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(short4 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(short8 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
as_short3(short4 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
as_ushort(short f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort2(short2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort3(short3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort3(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(short4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(short8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort16(short16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
as_int(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
as_int8(short16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
as_uint(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
as_uint8(short16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(short4 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(short8 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(short16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(short4 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(short8 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(short16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
as_float(short2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(short4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(short8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
as_float8(short16 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
as_char2(ushort f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(ushort2 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(ushort4 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(ushort8 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar2(ushort f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(ushort2 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(ushort4 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(ushort8 f);
short __attribute__((always_inline)) __attribute__((overloadable))
as_short(ushort f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
as_short2(ushort2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
as_short3(ushort3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
as_short3(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(ushort4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(ushort8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
as_short16(ushort16 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort3(ushort4 f);
int __attribute__((always_inline)) __attribute__((overloadable))
as_int(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
as_int8(ushort16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
as_uint(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
as_uint8(ushort16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(ushort4 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(ushort8 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(ushort16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(ushort4 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(ushort8 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(ushort16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
as_float(ushort2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(ushort4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(ushort8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
as_float8(ushort16 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(int f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(int2 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(int f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(int2 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(int4 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
as_short2(int f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(int2 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(int4 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
as_short16(int8 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort2(int f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(int2 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(int4 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort16(int8 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
as_int3(int4 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
as_uint(int f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(int2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
as_uint3(int3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
as_uint3(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(int4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
as_uint8(int8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
as_uint16(int16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
as_long8(int16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong8(int16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
as_float(int f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(int2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
as_float3(int3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(int3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
as_float3(int4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(int4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
as_float8(int8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
as_float16(int16 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(uint f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(uint2 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(uint f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(uint2 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(uint4 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
as_short2(uint f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(uint2 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(uint4 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
as_short16(uint8 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort2(uint f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(uint2 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(uint4 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort16(uint8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) as_int(uint f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(uint2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
as_int3(uint3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
as_int3(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(uint4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
as_int8(uint8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
as_int16(uint16 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
as_uint3(uint4 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
as_long8(uint16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong8(uint16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
as_float(uint f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(uint2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
as_float3(uint3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(uint3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
as_float3(uint4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(uint4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
as_float8(uint8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
as_float16(uint16 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(long f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(long2 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(long f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(long2 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(long f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(long2 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
as_short16(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(long f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(long2 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort16(long4 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(long f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(long2 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
as_int8(long4 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
as_int16(long8 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(long f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(long2 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
as_uint8(long4 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
as_uint16(long8 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
as_long3(long4 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(long f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(long2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong3(long3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong3(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(long4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong8(long8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong16(long16 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(long f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(long2 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
as_float8(long4 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
as_float16(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(ulong f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(ulong2 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(ulong f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(ulong2 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(ulong f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(ulong2 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
as_short16(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(ulong f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(ulong2 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort16(ulong4 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(ulong f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(ulong2 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
as_int8(ulong4 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
as_int16(ulong8 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(ulong f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(ulong2 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
as_uint8(ulong4 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
as_uint16(ulong8 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(ulong f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(ulong2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
as_long3(ulong3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
as_long3(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(ulong4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
as_long8(ulong8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
as_long16(ulong16 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong3(ulong4 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
as_float2(ulong f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(ulong2 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
as_float8(ulong4 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
as_float16(ulong8 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
as_char4(float f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
as_char8(float2 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
as_char16(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar4(float f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar8(float2 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
as_uchar16(float4 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
as_short2(float f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
as_short4(float2 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
as_short8(float4 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
as_short16(float8 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort2(float f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort4(float2 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort8(float4 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
as_ushort16(float8 f);
int __attribute__((always_inline)) __attribute__((overloadable))
as_int(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
as_int2(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
as_int3(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
as_int3(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
as_int4(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
as_int8(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
as_int16(float16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
as_uint(float f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
as_uint2(float2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
as_uint3(float3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
as_uint3(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
as_uint4(float4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
as_uint8(float8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
as_uint16(float16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
as_long(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
as_long2(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
as_long4(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
as_long8(float16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
as_ulong(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong2(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong4(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
as_ulong8(float16 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
as_float4(float3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
as_float3(float4 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(char f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(char2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(char3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(char4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(char8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(char16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(char f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(char2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(char3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(char4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(char8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(char16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(char f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(char2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(char3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(char4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(char8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(char16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(char f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(char2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(char3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(char4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(char8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(char16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(char f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(char2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(char3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(char4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(char8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(char16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(char f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(char2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(char3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(char4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(char8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(char16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(char f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(char2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(char3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(char4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(char8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(char16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(char f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(char2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(char3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(char4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(char8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(char16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(char f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(char f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(char f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(char f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(char f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(char2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(char2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(char2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(char2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(char2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(char3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(char3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(char3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(char3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(char3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(char4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(char4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(char4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(char4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(char4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(char8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(char8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(char8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(char8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(char8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(char16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(char16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(char16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(char16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(char16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(uchar f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(uchar2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(uchar3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(uchar4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(uchar8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(uchar16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(uchar f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(uchar2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(uchar3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(uchar4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(uchar8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(uchar16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(uchar f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(uchar2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(uchar3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(uchar4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(uchar8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(uchar16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(uchar f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(uchar2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(uchar3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(uchar4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(uchar8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(uchar16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(uchar f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(uchar2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(uchar3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(uchar4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(uchar8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(uchar16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(uchar f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(uchar2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(uchar3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(uchar4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(uchar8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(uchar16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(uchar f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(uchar2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(uchar3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(uchar4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(uchar8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(uchar16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(uchar f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(uchar2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(uchar3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(uchar4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(uchar8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(uchar16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(uchar f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(uchar f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(uchar f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(uchar f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(uchar f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(uchar2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(uchar2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(uchar2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(uchar2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(uchar2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(uchar3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(uchar3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(uchar3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(uchar3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(uchar3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(uchar4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(uchar4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(uchar4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(uchar4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(uchar4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(uchar8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(uchar8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(uchar8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(uchar8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(uchar8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(uchar16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(uchar16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(uchar16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(uchar16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(uchar16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(short f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(short2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(short3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(short4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(short8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(short16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(short f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(short2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(short3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(short4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(short8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(short16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(short f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(short2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(short3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(short4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(short8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(short16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(short f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(short2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(short3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(short4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(short8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(short16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(short f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(short2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(short3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(short4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(short8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(short16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(short f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(short2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(short3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(short4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(short8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(short16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(short f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(short2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(short3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(short4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(short8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(short16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(short f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(short2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(short3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(short4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(short8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(short16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(short f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(short f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(short f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(short f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(short f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(short2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(short2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(short2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(short2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(short2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(short3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(short3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(short3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(short3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(short3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(short4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(short4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(short4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(short4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(short4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(short8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(short8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(short8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(short8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(short8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(short16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(short16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(short16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(short16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(short16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(ushort f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(ushort2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(ushort3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(ushort4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(ushort8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(ushort16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(ushort f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(ushort2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(ushort3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(ushort4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(ushort8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(ushort16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(ushort f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(ushort2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(ushort3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(ushort4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(ushort8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(ushort16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(ushort f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(ushort2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(ushort3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(ushort4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(ushort8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(ushort16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(ushort f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(ushort2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(ushort3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(ushort4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(ushort8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(ushort16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(ushort f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(ushort2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(ushort3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(ushort4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(ushort8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(ushort16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(ushort f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(ushort2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(ushort3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(ushort4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(ushort8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(ushort16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(ushort f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(ushort2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(ushort3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(ushort4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(ushort8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(ushort16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(ushort f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(ushort f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(ushort f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(ushort f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(ushort f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(ushort2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(ushort2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(ushort2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(ushort2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(ushort2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(ushort3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(ushort3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(ushort3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(ushort3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(ushort3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(ushort4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(ushort4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(ushort4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(ushort4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(ushort4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(ushort8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(ushort8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(ushort8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(ushort8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(ushort8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(ushort16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(ushort16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(ushort16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(ushort16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(ushort16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(int f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(int2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(int3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(int4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(int8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(int16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(int f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(int2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(int3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(int4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(int8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(int16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(int f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(int2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(int3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(int4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(int8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(int16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(int f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(int2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(int3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(int4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(int8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(int16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(int f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(int2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(int3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(int4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(int8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(int16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(int f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(int2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(int3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(int4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(int8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(int16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(int f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(int2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(int3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(int4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(int8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(int16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(int f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(int2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(int3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(int4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(int8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(int16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(int f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(int f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(int f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(int f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(int f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(int2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(int2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(int2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(int2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(int2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(int3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(int3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(int3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(int3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(int3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(int4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(int4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(int4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(int4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(int4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(int8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(int8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(int8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(int8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(int8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(int16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(int16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(int16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(int16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(int16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(uint f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(uint2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(uint3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(uint4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(uint8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(uint16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(uint f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(uint2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(uint3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(uint4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(uint8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(uint16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(uint f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(uint2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(uint3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(uint4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(uint8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(uint16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(uint f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(uint2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(uint3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(uint4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(uint8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(uint16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(uint f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(uint2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(uint3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(uint4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(uint8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(uint16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(uint f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(uint2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(uint3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(uint4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(uint8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(uint16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(uint f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(uint2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(uint3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(uint4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(uint8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(uint16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(uint f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(uint2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(uint3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(uint4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(uint8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(uint16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(uint f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(uint f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(uint f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(uint f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(uint f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(uint2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(uint2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(uint2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(uint2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(uint2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(uint3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(uint3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(uint3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(uint3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(uint3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(uint4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(uint4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(uint4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(uint4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(uint4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(uint8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(uint8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(uint8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(uint8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(uint8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(uint16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(uint16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(uint16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(uint16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(uint16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(long f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(long2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(long3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(long4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(long8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(long16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(long f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(long2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(long3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(long4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(long8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(long16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(long f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(long2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(long3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(long4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(long8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(long16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(long f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(long2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(long3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(long4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(long8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(long16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(long f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(long2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(long3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(long4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(long8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(long16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(long f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(long2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(long3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(long4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(long8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(long16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(long f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(long2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(long3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(long4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(long8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(long16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(long f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(long2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(long3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(long4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(long8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(long16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(long f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(long f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(long f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(long f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(long f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(long2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(long2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(long2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(long2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(long2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(long3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(long3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(long3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(long3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(long3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(long4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(long4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(long4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(long4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(long4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(long8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(long8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(long8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(long8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(long8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(long16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(long16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(long16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(long16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(long16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(ulong f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(ulong2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(ulong3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(ulong4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(ulong8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(ulong16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(ulong f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(ulong2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(ulong3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(ulong4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(ulong8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(ulong16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(ulong f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(ulong2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(ulong3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(ulong4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(ulong8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(ulong16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(ulong f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(ulong2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(ulong3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(ulong4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(ulong8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(ulong16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(ulong f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(ulong2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(ulong3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(ulong4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(ulong8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(ulong16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(ulong f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(ulong2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(ulong3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(ulong4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(ulong8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(ulong16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(ulong f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(ulong2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(ulong3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(ulong4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(ulong8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(ulong16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(ulong f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(ulong2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(ulong3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(ulong4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(ulong8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(ulong16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(ulong f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(ulong f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(ulong f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(ulong f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(ulong f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(ulong2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(ulong2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(ulong2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(ulong2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(ulong2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(ulong3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(ulong3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(ulong3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(ulong3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(ulong3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(ulong4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(ulong4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(ulong4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(ulong4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(ulong4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(ulong8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(ulong8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(ulong8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(ulong8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(ulong8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(ulong16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(ulong16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(ulong16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(ulong16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(ulong16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rte(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtz(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtp(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_rtn(float f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rte(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtz(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtp(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_rtn(float2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rte(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtz(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtp(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_rtn(float3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rte(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtz(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtp(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_rtn(float4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rte(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtz(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtp(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_rtn(float8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rte(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtz(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtp(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_rtn(float16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rte(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtz(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtp(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_rtn(float f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rte(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtz(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtp(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_rtn(float2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rte(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtz(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtp(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_rtn(float3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rte(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtz(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtp(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_rtn(float4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rte(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtz(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtp(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_rtn(float8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rte(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtz(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtp(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_rtn(float16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rte(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtz(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtp(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_rtn(float f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rte(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtz(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtp(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_rtn(float2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rte(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtz(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtp(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_rtn(float3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rte(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtz(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtp(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_rtn(float4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rte(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtz(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtp(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_rtn(float8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rte(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtz(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtp(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_rtn(float16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rte(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtz(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtp(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_rtn(float f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rte(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtz(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtp(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_rtn(float2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rte(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtz(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtp(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_rtn(float3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rte(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtz(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtp(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_rtn(float4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rte(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtz(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtp(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_rtn(float8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rte(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtz(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtp(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_rtn(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rte(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtz(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtp(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_rtn(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rte(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtz(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtp(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_rtn(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rte(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtz(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtp(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_rtn(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rte(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtz(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtp(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_rtn(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rte(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtz(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtp(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_rtn(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rte(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtz(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtp(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_rtn(float16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rte(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtz(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtp(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_rtn(float f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rte(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtz(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtp(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_rtn(float2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rte(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtz(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtp(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_rtn(float3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rte(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtz(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtp(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_rtn(float4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rte(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtz(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtp(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_rtn(float8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rte(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtz(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtp(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_rtn(float16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rte(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtz(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtp(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_rtn(float f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rte(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtz(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtp(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_rtn(float2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rte(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtz(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtp(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_rtn(float3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rte(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtz(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtp(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_rtn(float4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rte(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtz(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtp(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_rtn(float8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rte(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtz(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtp(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_rtn(float16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rte(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtz(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtp(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_rtn(float f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rte(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtz(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtp(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_rtn(float2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rte(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtz(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtp(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_rtn(float3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rte(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtz(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtp(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_rtn(float4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rte(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtz(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtp(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_rtn(float8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rte(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtz(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtp(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_rtn(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float(float f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rte(float f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtz(float f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtp(float f);
float __attribute__((always_inline)) __attribute__((overloadable))
convert_float_rtn(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2(float2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rte(float2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtz(float2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtp(float2 f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
convert_float2_rtn(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3(float3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rte(float3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtz(float3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtp(float3 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
convert_float3_rtn(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4(float4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rte(float4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtz(float4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtp(float4 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
convert_float4_rtn(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8(float8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rte(float8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtz(float8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtp(float8 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
convert_float8_rtn(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16(float16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rte(float16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtz(float16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtp(float16 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
convert_float16_rtn(float16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(char f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(char f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(char2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(char2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(char3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(char3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(char4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(char4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(char8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(char8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(char16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(char16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(char f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(char f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(char2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(char2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(char3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(char3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(char4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(char4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(char8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(char8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(char16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(char16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(char f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(char f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(char2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(char2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(char3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(char3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(char4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(char4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(char8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(char8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(char16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(char16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(char f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(char f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(char2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(char2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(char3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(char3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(char4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(char4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(char8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(char8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(char16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(char16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(char f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(char f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(char2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(char2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(char3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(char3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(char4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(char4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(char8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(char8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(char16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(char16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(char f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(char f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(char2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(char2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(char3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(char3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(char4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(char4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(char8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(char8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(char16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(char16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(char f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(char f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(char2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(char2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(char3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(char3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(char4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(char4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(char8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(char8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(char16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(char16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(char f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(char f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(char2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(char2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(char3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(char3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(char4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(char4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(char8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(char8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(char16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(char16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(uchar f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(uchar f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(uchar2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(uchar2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(uchar3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(uchar3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(uchar4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(uchar4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(uchar8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(uchar8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(uchar16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(uchar16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(uchar f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(uchar f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(uchar2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(uchar2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(uchar3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(uchar3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(uchar4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(uchar4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(uchar8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(uchar8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(uchar16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(uchar16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(uchar f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(uchar f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(uchar2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(uchar2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(uchar3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(uchar3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(uchar4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(uchar4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(uchar8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(uchar8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(uchar16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(uchar16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(uchar f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(uchar f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(uchar2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(uchar2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(uchar3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(uchar3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(uchar4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(uchar4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(uchar8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(uchar8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(uchar16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(uchar16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(uchar f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(uchar f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(uchar2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(uchar2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(uchar3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(uchar3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(uchar4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(uchar4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(uchar8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(uchar8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(uchar16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(uchar16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(uchar f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(uchar f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(uchar2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(uchar2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(uchar3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(uchar3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(uchar4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(uchar4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(uchar8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(uchar8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(uchar16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(uchar16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(uchar f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(uchar f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(uchar2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(uchar2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(uchar3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(uchar3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(uchar4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(uchar4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(uchar8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(uchar8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(uchar16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(uchar16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(uchar f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(uchar f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(uchar2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(uchar2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(uchar3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(uchar3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(uchar4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(uchar4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(uchar8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(uchar8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(uchar16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(uchar16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(short f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(short f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(short2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(short2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(short3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(short3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(short4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(short4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(short8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(short8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(short16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(short16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(short f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(short f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(short2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(short2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(short3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(short3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(short4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(short4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(short8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(short8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(short16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(short16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(short f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(short f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(short2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(short2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(short3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(short3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(short4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(short4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(short8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(short8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(short16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(short16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(short f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(short f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(short2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(short2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(short3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(short3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(short4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(short4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(short8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(short8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(short16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(short16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(short f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(short f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(short2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(short2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(short3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(short3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(short4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(short4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(short8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(short8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(short16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(short16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(short f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(short f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(short2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(short2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(short3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(short3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(short4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(short4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(short8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(short8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(short16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(short16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(short f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(short f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(short2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(short2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(short3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(short3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(short4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(short4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(short8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(short8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(short16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(short16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(short f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(short f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(short2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(short2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(short3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(short3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(short4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(short4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(short8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(short8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(short16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(short16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(ushort f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(ushort f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(ushort2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(ushort2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(ushort3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(ushort3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(ushort4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(ushort4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(ushort8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(ushort8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(ushort16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(ushort16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(ushort f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(ushort f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(ushort2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(ushort2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(ushort3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(ushort3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(ushort4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(ushort4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(ushort8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(ushort8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(ushort16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(ushort16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(ushort f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(ushort f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(ushort2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(ushort2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(ushort3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(ushort3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(ushort4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(ushort4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(ushort8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(ushort8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(ushort16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(ushort16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(ushort f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(ushort f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(ushort2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(ushort2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(ushort3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(ushort3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(ushort4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(ushort4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(ushort8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(ushort8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(ushort16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(ushort16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(ushort f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(ushort f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(ushort2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(ushort2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(ushort3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(ushort3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(ushort4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(ushort4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(ushort8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(ushort8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(ushort16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(ushort16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(ushort f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(ushort f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(ushort2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(ushort2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(ushort3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(ushort3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(ushort4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(ushort4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(ushort8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(ushort8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(ushort16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(ushort16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(ushort f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(ushort f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(ushort2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(ushort2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(ushort3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(ushort3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(ushort4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(ushort4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(ushort8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(ushort8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(ushort16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(ushort16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(ushort f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(ushort f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(ushort2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(ushort2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(ushort3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(ushort3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(ushort4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(ushort4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(ushort8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(ushort8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(ushort16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(ushort16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(int f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(int f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(int2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(int2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(int3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(int3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(int4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(int4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(int8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(int8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(int16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(int16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(int f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(int f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(int2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(int2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(int3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(int3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(int4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(int4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(int8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(int8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(int16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(int16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(int f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(int f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(int2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(int2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(int3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(int3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(int4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(int4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(int8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(int8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(int16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(int16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(int f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(int f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(int2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(int2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(int3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(int3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(int4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(int4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(int8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(int8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(int16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(int16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(int f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(int f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(int2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(int2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(int3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(int3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(int4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(int4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(int8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(int8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(int16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(int16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(int f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(int f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(int2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(int2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(int3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(int3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(int4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(int4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(int8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(int8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(int16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(int16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(int f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(int f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(int2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(int2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(int3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(int3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(int4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(int4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(int8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(int8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(int16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(int16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(int f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(int f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(int2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(int2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(int3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(int3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(int4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(int4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(int8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(int8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(int16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(int16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(uint f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(uint f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(uint2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(uint2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(uint3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(uint3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(uint4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(uint4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(uint8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(uint8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(uint16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(uint16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(uint f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(uint f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(uint2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(uint2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(uint3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(uint3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(uint4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(uint4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(uint8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(uint8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(uint16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(uint16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(uint f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(uint f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(uint2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(uint2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(uint3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(uint3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(uint4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(uint4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(uint8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(uint8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(uint16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(uint16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(uint f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(uint f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(uint2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(uint2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(uint3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(uint3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(uint4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(uint4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(uint8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(uint8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(uint16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(uint16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(uint f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(uint f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(uint2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(uint2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(uint3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(uint3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(uint4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(uint4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(uint8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(uint8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(uint16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(uint16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(uint f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(uint f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(uint2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(uint2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(uint3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(uint3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(uint4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(uint4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(uint8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(uint8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(uint16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(uint16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(uint f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(uint f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(uint2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(uint2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(uint3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(uint3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(uint4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(uint4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(uint8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(uint8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(uint16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(uint16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(uint f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(uint f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(uint2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(uint2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(uint3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(uint3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(uint4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(uint4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(uint8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(uint8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(uint16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(uint16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(long f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(long f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(long2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(long2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(long3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(long3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(long4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(long4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(long8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(long8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(long16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(long16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(long f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(long f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(long2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(long2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(long3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(long3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(long4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(long4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(long8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(long8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(long16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(long16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(long f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(long f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(long2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(long2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(long3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(long3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(long4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(long4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(long8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(long8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(long16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(long16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(long f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(long f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(long2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(long2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(long3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(long3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(long4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(long4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(long8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(long8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(long16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(long16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(long f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(long f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(long2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(long2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(long3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(long3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(long4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(long4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(long8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(long8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(long16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(long16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(long f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(long f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(long2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(long2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(long3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(long3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(long4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(long4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(long8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(long8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(long16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(long16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(long f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(long f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(long2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(long2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(long3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(long3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(long4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(long4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(long8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(long8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(long16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(long16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(long f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(long f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(long2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(long2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(long3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(long3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(long4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(long4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(long8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(long8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(long16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(long16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(ulong f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(ulong f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(ulong2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(ulong2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(ulong3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(ulong3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(ulong4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(ulong4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(ulong8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(ulong8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(ulong16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(ulong16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(ulong f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(ulong f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(ulong2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(ulong2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(ulong3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(ulong3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(ulong4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(ulong4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(ulong8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(ulong8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(ulong16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(ulong16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(ulong f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(ulong f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(ulong2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(ulong2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(ulong3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(ulong3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(ulong4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(ulong4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(ulong8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(ulong8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(ulong16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(ulong16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(ulong f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(ulong f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(ulong2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(ulong2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(ulong3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(ulong3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(ulong4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(ulong4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(ulong8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(ulong8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(ulong16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(ulong16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(ulong f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(ulong f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(ulong2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(ulong2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(ulong3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(ulong3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(ulong4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(ulong4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(ulong8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(ulong8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(ulong16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(ulong16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(ulong f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(ulong f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(ulong2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(ulong2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(ulong3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(ulong3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(ulong4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(ulong4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(ulong8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(ulong8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(ulong16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(ulong16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(ulong f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(ulong f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(ulong2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(ulong2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(ulong3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(ulong3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(ulong4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(ulong4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(ulong8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(ulong8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(ulong16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(ulong16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(ulong f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(ulong f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(ulong2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(ulong2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(ulong3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(ulong3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(ulong4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(ulong4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(ulong8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(ulong8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(ulong16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(ulong16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rte(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtz(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtp(float f);
char __attribute__((always_inline)) __attribute__((overloadable))
convert_char_sat_rtn(float f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rte(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtz(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtp(float2 f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
convert_char2_sat_rtn(float2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rte(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtz(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtp(float3 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
convert_char3_sat_rtn(float3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rte(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtz(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtp(float4 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
convert_char4_sat_rtn(float4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rte(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtz(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtp(float8 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
convert_char8_sat_rtn(float8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rte(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtz(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtp(float16 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
convert_char16_sat_rtn(float16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rte(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtz(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtp(float f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar_sat_rtn(float f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rte(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtz(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtp(float2 f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar2_sat_rtn(float2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rte(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtz(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtp(float3 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar3_sat_rtn(float3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rte(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtz(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtp(float4 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar4_sat_rtn(float4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rte(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtz(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtp(float8 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar8_sat_rtn(float8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rte(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtz(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtp(float16 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uchar16_sat_rtn(float16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rte(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtz(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtp(float f);
short __attribute__((always_inline)) __attribute__((overloadable))
convert_short_sat_rtn(float f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rte(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtz(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtp(float2 f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
convert_short2_sat_rtn(float2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rte(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtz(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtp(float3 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
convert_short3_sat_rtn(float3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rte(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtz(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtp(float4 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
convert_short4_sat_rtn(float4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rte(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtz(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtp(float8 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
convert_short8_sat_rtn(float8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rte(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtz(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtp(float16 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
convert_short16_sat_rtn(float16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rte(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtz(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtp(float f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort_sat_rtn(float f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rte(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtz(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtp(float2 f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort2_sat_rtn(float2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rte(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtz(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtp(float3 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort3_sat_rtn(float3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rte(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtz(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtp(float4 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort4_sat_rtn(float4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rte(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtz(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtp(float8 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort8_sat_rtn(float8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rte(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtz(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtp(float16 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ushort16_sat_rtn(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rte(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtz(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtp(float f);
int __attribute__((always_inline)) __attribute__((overloadable))
convert_int_sat_rtn(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rte(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtz(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtp(float2 f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
convert_int2_sat_rtn(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rte(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtz(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtp(float3 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
convert_int3_sat_rtn(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rte(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtz(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtp(float4 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
convert_int4_sat_rtn(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rte(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtz(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtp(float8 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
convert_int8_sat_rtn(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rte(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtz(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtp(float16 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
convert_int16_sat_rtn(float16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rte(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtz(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtp(float f);
uint __attribute__((always_inline)) __attribute__((overloadable))
convert_uint_sat_rtn(float f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rte(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtz(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtp(float2 f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint2_sat_rtn(float2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rte(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtz(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtp(float3 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint3_sat_rtn(float3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rte(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtz(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtp(float4 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint4_sat_rtn(float4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rte(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtz(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtp(float8 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint8_sat_rtn(float8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rte(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtz(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtp(float16 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
convert_uint16_sat_rtn(float16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rte(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtz(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtp(float f);
long __attribute__((always_inline)) __attribute__((overloadable))
convert_long_sat_rtn(float f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rte(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtz(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtp(float2 f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
convert_long2_sat_rtn(float2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rte(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtz(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtp(float3 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
convert_long3_sat_rtn(float3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rte(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtz(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtp(float4 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
convert_long4_sat_rtn(float4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rte(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtz(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtp(float8 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
convert_long8_sat_rtn(float8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rte(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtz(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtp(float16 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
convert_long16_sat_rtn(float16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rte(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtz(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtp(float f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong_sat_rtn(float f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rte(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtz(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtp(float2 f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong2_sat_rtn(float2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rte(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtz(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtp(float3 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong3_sat_rtn(float3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rte(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtz(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtp(float4 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong4_sat_rtn(float4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rte(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtz(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtp(float8 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong8_sat_rtn(float8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rte(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtz(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtp(float16 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
convert_ulong16_sat_rtn(float16 f);
// image 2.0 API
// float4 __attribute__ ((always_inline)) __attribute__((overloadable))
// read_imagef(__global image2d_t image, int2  coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image2d_t image, sampler_t sampler, int2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image2d_t image, sampler_t sampler, float2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image2d_t image, sampler_t sampler, int2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image2d_t image, sampler_t sampler, float2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image2d_t image, sampler_t sampler, int2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image2d_t image, sampler_t sampler, float2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image2d_t image, int2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image2d_t image, int2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image2d_t image, int2 coord);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imagef(__global image2d_t image, int2 coord, float4 color);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imagei(__global image2d_t image, int2 coord, int4 color);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imageui(__global image2d_t image, int2 coord, uint4 color);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image1d_t image, sampler_t sampler, int coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image1d_t image, sampler_t sampler, float coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image1d_t image, sampler_t sampler, int coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image1d_t image, sampler_t sampler, float coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image1d_t image, sampler_t sampler, int coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image1d_t image, sampler_t sampler, float coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image1d_t image, int coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image1d_t image, int coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image1d_t image, int coord);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imagef(__global image1d_t image, int coord, float4 color);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imagei(__global image1d_t image, int coord, int4 color);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imageui(__global image1d_t image, int coord, uint4 color);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image3d_t image, sampler_t sampler, int4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image3d_t image, sampler_t sampler, float4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image3d_t image, sampler_t sampler, int4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image3d_t image, sampler_t sampler, float4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image3d_t image, sampler_t sampler, int4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image3d_t image, sampler_t sampler, float4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) float4
read_imagef(__global image3d_t image, int4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) int4
read_imagei(__global image3d_t image, int4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) uint4
read_imageui(__global image3d_t image, int4 coord);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imagef(__global image3d_t image, int4 coord, float4 color);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imagei(__global image3d_t image, int4 coord, int4 color);
__attribute__((always_inline)) __attribute__((overloadable)) void
write_imageui(__global image3d_t image, int4 coord, uint4 color);
__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_width(__global image1d_t image);
__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_width(__global image2d_t image);
__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_width(__global image3d_t image);
__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_height(__global image2d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_height(__global image3d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_depth(__global image3d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int2
get_image_dim(__global image2d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_channel_data_type(__global image1d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_channel_data_type(__global image2d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_channel_data_type(__global image3d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_channel_order(__global image1d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_channel_order(__global image2d_t image);

__attribute__((always_inline)) __attribute__((overloadable)) int
get_image_channel_order(__global image3d_t image);

// OpenCL 1.2 Section 6.12.2 Math Functions
// Table 6.8
//"gentype" functions can take
// float, float2, float3, float4, float8, float16
// double, double2, double3, double4, double8, double16
float __attribute__((always_inline)) __attribute__((overloadable))
acos(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
acos(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
acos(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
acos(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
acos(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
acos(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
acosh(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
acosh(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
acosh(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
acosh(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
acosh(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
acosh(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
acospi(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
acospi(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
acospi(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
acospi(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
acospi(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
acospi(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
asin(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
asin(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
asin(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
asin(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
asin(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
asin(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
asinh(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
asinh(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
asinh(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
asinh(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
asinh(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
asinh(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
asinpi(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
asinpi(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
asinpi(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
asinpi(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
asinpi(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
asinpi(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
atan(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
atan(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
atan(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
atan(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
atan(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
atan(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
atanpi(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
atanpi(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
atanpi(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
atanpi(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
atanpi(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
atanpi(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
atan2(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
atan2(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
atan2(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
atan2(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
atan2(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
atan2(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
atanh(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
atanh(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
atanh(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
atanh(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
atanh(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
atanh(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
atan2pi(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
atan2pi(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
atan2pi(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
atan2pi(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
atan2pi(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
atan2pi(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
cbrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
cbrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
cbrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
cbrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
cbrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
cbrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
ceil(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
ceil(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
ceil(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
ceil(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
ceil(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
ceil(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
copysign(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
copysign(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
copysign(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
copysign(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
copysign(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
copysign(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable)) cos(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
cos(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
cos(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
cos(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
cos(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
cos(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
cosh(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
cosh(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
cosh(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
cosh(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
cosh(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
cosh(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
cospi(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
cospi(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
cospi(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
cospi(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
cospi(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
cospi(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
erfc(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
erfc(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
erfc(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
erfc(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
erfc(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
erfc(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable)) erf(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
erf(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
erf(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
erf(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
erf(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
erf(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable)) exp(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
exp(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
exp(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
exp(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
exp(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
exp(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
exp2(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
exp2(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
exp2(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
exp2(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
exp2(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
exp2(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
exp10(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
exp10(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
exp10(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
exp10(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
exp10(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
exp10(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
expm1(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
expm1(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
expm1(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
expm1(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
expm1(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
expm1(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fabs(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fabs(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fabs(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fabs(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fabs(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fabs(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fdim(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fdim(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fdim(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fdim(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fdim(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fdim(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
floor(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
floor(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
floor(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
floor(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
floor(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
floor(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fma(float f, float g, float h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fma(float2 f, float2 g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fma(float3 f, float3 g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fma(float4 f, float4 g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fma(float8 f, float8 g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fma(float16 f, float16 g, float16 h);
float __attribute__((always_inline)) __attribute__((overloadable))
fmax(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float16 f, float16 g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float2 f, float g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float3 f, float g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float4 f, float g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float8 f, float g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fmax(float16 f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
fmin(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float16 f, float16 g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float2 f, float g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float3 f, float g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float4 f, float g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float8 f, float g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fmin(float16 f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
fmod(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fmod(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fmod(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fmod(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fmod(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fmod(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
fract(float f, __global float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fract(float2 f, __global float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fract(float3 f, __global float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fract(float4 f, __global float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fract(float8 f, __global float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fract(float16 f, __global float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
fract(float f, __local float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fract(float2 f, __local float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fract(float3 f, __local float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fract(float4 f, __local float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fract(float8 f, __local float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fract(float16 f, __local float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
fract(float f, __private float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fract(float2 f, __private float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fract(float3 f, __private float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fract(float4 f, __private float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fract(float8 f, __private float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fract(float16 f, __private float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
frexp(float f, __global int *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float2 f, __global int2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float3 f, __global int3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float4 f, __global int4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float8 f, __global int8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float16 f, __global int16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
frexp(float f, __local int *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float2 f, __local int2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float3 f, __local int3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float4 f, __local int4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float8 f, __local int8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float16 f, __local int16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
frexp(float f, __private int *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float2 f, __private int2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float3 f, __private int3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float4 f, __private int4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float8 f, __private int8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
frexp(float16 f, __private int16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
hypot(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
hypot(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
hypot(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
hypot(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
hypot(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
hypot(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable)) ilogb(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
ilogb(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
ilogb(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
ilogb(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
ilogb(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
ilogb(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float f, int g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float2 f, int2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float3 f, int3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float4 f, int4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float8 f, int8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float16 f, int16 g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float2 f, int g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float3 f, int g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float4 f, int g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float8 f, int g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
ldexp(float16 f, int g);
float __attribute__((always_inline)) __attribute__((overloadable))
lgamma(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
lgamma(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
lgamma(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
lgamma(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
lgamma(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
lgamma(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float f, __global int *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float2 f, __global int2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float3 f, __global int3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float4 f, __global int4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float8 f, __global int8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float16 f, __global int16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float f, __local int *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float2 f, __local int2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float3 f, __local int3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float4 f, __local int4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float8 f, __local int8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float16 f, __local int16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float f, __private int *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float2 f, __private int2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float3 f, __private int3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float4 f, __private int4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float8 f, __private int8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
lgamma_r(float16 f, __private int16 *g);
float __attribute__((always_inline)) __attribute__((overloadable)) log(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
log(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
log(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
log(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
log(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
log(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
log2(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
log2(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
log2(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
log2(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
log2(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
log2(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
log10(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
log10(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
log10(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
log10(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
log10(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
log10(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
log1p(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
log1p(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
log1p(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
log1p(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
log1p(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
log1p(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
logb(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
logb(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
logb(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
logb(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
logb(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
logb(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
mad(float f, float g, float h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
mad(float2 f, float2 g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
mad(float3 f, float3 g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
mad(float4 f, float4 g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
mad(float8 f, float8 g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
mad(float16 f, float16 g, float16 h);
float __attribute__((always_inline)) __attribute__((overloadable))
maxmag(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
maxmag(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
maxmag(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
maxmag(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
maxmag(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
maxmag(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
minmag(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
minmag(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
minmag(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
minmag(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
minmag(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
minmag(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
modf(float f, __global float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
modf(float2 f, __global float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
modf(float3 f, __global float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
modf(float4 f, __global float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
modf(float8 f, __global float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
modf(float16 f, __global float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
modf(float f, __local float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
modf(float2 f, __local float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
modf(float3 f, __local float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
modf(float4 f, __local float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
modf(float8 f, __local float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
modf(float16 f, __local float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
modf(float f, __private float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
modf(float2 f, __private float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
modf(float3 f, __private float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
modf(float4 f, __private float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
modf(float8 f, __private float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
modf(float16 f, __private float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable)) nan(uint f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
nan(uint2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
nan(uint3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
nan(uint4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
nan(uint8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
nan(uint16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
nextafter(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
nextafter(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
nextafter(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
nextafter(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
nextafter(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
nextafter(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
pow(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
pow(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
pow(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
pow(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
pow(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
pow(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
pown(float f, int g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
pown(float2 f, int2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
pown(float3 f, int3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
pown(float4 f, int4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
pown(float8 f, int8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
pown(float16 f, int16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
powr(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
powr(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
powr(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
powr(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
powr(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
powr(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
remainder(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
remainder(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
remainder(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
remainder(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
remainder(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
remainder(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
remquo(float f, float g, __global int *h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float2 f, float2 g, __global int2 *h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float3 f, float3 g, __global int3 *h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float4 f, float4 g, __global int4 *h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float8 f, float8 g, __global int8 *h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float16 f, float16 g, __global int16 *h);
float __attribute__((always_inline)) __attribute__((overloadable))
remquo(float f, float g, __local int *h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float2 f, float2 g, __local int2 *h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float3 f, float3 g, __local int3 *h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float4 f, float4 g, __local int4 *h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float8 f, float8 g, __local int8 *h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float16 f, float16 g, __local int16 *h);
float __attribute__((always_inline)) __attribute__((overloadable))
remquo(float f, float g, __private int *h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float2 f, float2 g, __private int2 *h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float3 f, float3 g, __private int3 *h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float4 f, float4 g, __private int4 *h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float8 f, float8 g, __private int8 *h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
remquo(float16 f, float16 g, __private int16 *h);
float __attribute__((always_inline)) __attribute__((overloadable))
rint(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
rint(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
rint(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
rint(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
rint(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
rint(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
rootn(float f, int g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
rootn(float2 f, int2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
rootn(float3 f, int3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
rootn(float4 f, int4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
rootn(float8 f, int8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
rootn(float16 f, int16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
round(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
round(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
round(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
round(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
round(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
round(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
rsqrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
rsqrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
rsqrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
rsqrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
rsqrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
rsqrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable)) sin(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sin(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sin(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sin(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sin(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sin(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
sincos(float f, __global float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float2 f, __global float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float3 f, __global float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float4 f, __global float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float8 f, __global float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float16 f, __global float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
sincos(float f, __local float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float2 f, __local float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float3 f, __local float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float4 f, __local float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float8 f, __local float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float16 f, __local float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
sincos(float f, __private float *g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float2 f, __private float2 *g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float3 f, __private float3 *g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float4 f, __private float4 *g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float8 f, __private float8 *g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sincos(float16 f, __private float16 *g);
float __attribute__((always_inline)) __attribute__((overloadable))
sinh(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sinh(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sinh(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sinh(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sinh(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sinh(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
sinpi(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sinpi(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sinpi(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sinpi(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sinpi(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sinpi(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
sqrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sqrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sqrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sqrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sqrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sqrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable)) tan(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
tan(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
tan(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
tan(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
tan(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
tan(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
tanh(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
tanh(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
tanh(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
tanh(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
tanh(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
tanh(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
tanpi(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
tanpi(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
tanpi(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
tanpi(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
tanpi(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
tanpi(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
tgamma(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
tgamma(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
tgamma(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
tgamma(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
tgamma(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
tgamma(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
trunc(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
trunc(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
trunc(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
trunc(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
trunc(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
trunc(float16 f);
// OpenCL 1.2 Section 6.12.2 Math Functions Half
// Table 6.9
//"gentype" functions can take
// float, float2, float3, float4, float8, float16
float __attribute__((always_inline)) __attribute__((overloadable))
half_cos(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_cos(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_cos(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_cos(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_cos(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_cos(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_divide(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_divide(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_divide(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_divide(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_divide(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_divide(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
half_exp(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_exp(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_exp(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_exp(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_exp(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_exp(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_exp2(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_exp2(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_exp2(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_exp2(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_exp2(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_exp2(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_exp10(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_exp10(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_exp10(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_exp10(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_exp10(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_exp10(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_log(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_log(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_log(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_log(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_log(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_log(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_log2(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_log2(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_log2(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_log2(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_log2(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_log2(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_log10(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_log10(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_log10(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_log10(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_log10(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_log10(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_powr(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_powr(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_powr(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_powr(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_powr(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_powr(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
half_recip(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_recip(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_recip(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_recip(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_recip(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_recip(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_rsqrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_rsqrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_rsqrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_rsqrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_rsqrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_rsqrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_sin(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_sin(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_sin(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_sin(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_sin(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_sin(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_sqrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_sqrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_sqrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_sqrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_sqrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_sqrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
half_tan(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
half_tan(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
half_tan(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
half_tan(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
half_tan(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
half_tan(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_cos(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_cos(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_cos(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_cos(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_cos(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_cos(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_divide(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_divide(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_divide(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_divide(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_divide(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_divide(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
native_exp(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_exp(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_exp(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_exp(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_exp(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_exp(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_exp2(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_exp2(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_exp2(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_exp2(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_exp2(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_exp2(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_exp10(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_exp10(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_exp10(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_exp10(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_exp10(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_exp10(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_log(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_log(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_log(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_log(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_log(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_log(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_log2(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_log2(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_log2(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_log2(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_log2(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_log2(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_log10(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_log10(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_log10(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_log10(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_log10(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_log10(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_powr(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_powr(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_powr(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_powr(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_powr(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_powr(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
native_recip(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_recip(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_recip(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_recip(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_recip(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_recip(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_rsqrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_rsqrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_rsqrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_rsqrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_rsqrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_rsqrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_sin(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_sin(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_sin(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_sin(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_sin(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_sin(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_sqrt(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_sqrt(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_sqrt(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_sqrt(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_sqrt(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_sqrt(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
native_tan(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
native_tan(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
native_tan(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
native_tan(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
native_tan(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
native_tan(float16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable)) abs(char f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
abs(char2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
abs(char3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
abs(char4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
abs(char8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
abs(char16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable)) abs(uchar f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
abs(uchar2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
abs(uchar3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
abs(uchar4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
abs(uchar8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
abs(uchar16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
abs(short f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
abs(short2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
abs(short3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
abs(short4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
abs(short8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
abs(short16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
abs(ushort f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
abs(ushort2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
abs(ushort3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
abs(ushort4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
abs(ushort8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
abs(ushort16 f);
uint __attribute__((always_inline)) __attribute__((overloadable)) abs(int f);
uint2 __attribute__((always_inline)) __attribute__((overloadable)) abs(int2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable)) abs(int3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable)) abs(int4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable)) abs(int8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
abs(int16 f);
uint __attribute__((always_inline)) __attribute__((overloadable)) abs(uint f);
uint2 __attribute__((always_inline)) __attribute__((overloadable)) abs(uint2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable)) abs(uint3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable)) abs(uint4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable)) abs(uint8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
abs(uint16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable)) abs(long f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
abs(long2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
abs(long3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
abs(long4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
abs(long8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
abs(long16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable)) abs(ulong f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
abs(ulong2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
abs(ulong3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
abs(ulong4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
abs(ulong8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
abs(ulong16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(char f, char g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(char2 f, char2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(char3 f, char3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(char4 f, char4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(char8 f, char8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uchar16 f, uchar16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(short f, short g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(short2 f, short2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(short3 f, short3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(short4 f, short4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(short8 f, short8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ushort16 f, ushort16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(int f, int g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(int2 f, int2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(int3 f, int3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(int4 f, int4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(int8 f, int8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(uint16 f, uint16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(long f, long g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(long2 f, long2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(long3 f, long3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(long4 f, long4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(long8 f, long8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
abs_diff(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
add_sat(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
add_sat(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
add_sat(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
add_sat(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
add_sat(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
hadd(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
hadd(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
hadd(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
hadd(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
hadd(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
hadd(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
hadd(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
hadd(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
hadd(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
rhadd(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
rhadd(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
rhadd(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
rhadd(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
rhadd(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
clamp(char f, char g, char h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char2 f, char2 g, char2 h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char3 f, char3 g, char3 h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char4 f, char4 g, char4 h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char8 f, char8 g, char8 h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char16 f, char16 g, char16 h);
uchar __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar f, uchar g, uchar h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar2 f, uchar2 g, uchar2 h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar3 f, uchar3 g, uchar3 h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar4 f, uchar4 g, uchar4 h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar8 f, uchar8 g, uchar8 h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar16 f, uchar16 g, uchar16 h);
short __attribute__((always_inline)) __attribute__((overloadable))
clamp(short f, short g, short h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short2 f, short2 g, short2 h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short3 f, short3 g, short3 h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short4 f, short4 g, short4 h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short8 f, short8 g, short8 h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short16 f, short16 g, short16 h);
ushort __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort f, ushort g, ushort h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort2 f, ushort2 g, ushort2 h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort3 f, ushort3 g, ushort3 h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort4 f, ushort4 g, ushort4 h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort8 f, ushort8 g, ushort8 h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort16 f, ushort16 g, ushort16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
clamp(int f, int g, int h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int2 f, int2 g, int2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int3 f, int3 g, int3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int4 f, int4 g, int4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int8 f, int8 g, int8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int16 f, int16 g, int16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint f, uint g, uint h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint2 f, uint2 g, uint2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint3 f, uint3 g, uint3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint4 f, uint4 g, uint4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint8 f, uint8 g, uint8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint16 f, uint16 g, uint16 h);
long __attribute__((always_inline)) __attribute__((overloadable))
clamp(long f, long g, long h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long2 f, long2 g, long2 h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long3 f, long3 g, long3 h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long4 f, long4 g, long4 h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long8 f, long8 g, long8 h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long16 f, long16 g, long16 h);
ulong __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong f, ulong g, ulong h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong2 f, ulong2 g, ulong2 h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong3 f, ulong3 g, ulong3 h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong4 f, ulong4 g, ulong4 h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong8 f, ulong8 g, ulong8 h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong16 f, ulong16 g, ulong16 h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char2 f, char g, char h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char3 f, char g, char h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char4 f, char g, char h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char8 f, char g, char h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(char16 f, char g, char h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar2 f, uchar g, uchar h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar3 f, uchar g, uchar h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar4 f, uchar g, uchar h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar8 f, uchar g, uchar h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uchar16 f, uchar g, uchar h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short2 f, short g, short h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short3 f, short g, short h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short4 f, short g, short h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short8 f, short g, short h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(short16 f, short g, short h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort2 f, ushort g, ushort h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort3 f, ushort g, ushort h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort4 f, ushort g, ushort h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort8 f, ushort g, ushort h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ushort16 f, ushort g, ushort h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int2 f, int g, int h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int3 f, int g, int h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int4 f, int g, int h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int8 f, int g, int h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(int16 f, int g, int h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint2 f, uint g, uint h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint3 f, uint g, uint h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint4 f, uint g, uint h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint8 f, uint g, uint h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(uint16 f, uint g, uint h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long2 f, long g, long h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long3 f, long g, long h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long4 f, long g, long h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long8 f, long g, long h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(long16 f, long g, long h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong2 f, ulong g, ulong h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong3 f, ulong g, ulong h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong4 f, ulong g, ulong h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong8 f, ulong g, ulong h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(ulong16 f, ulong g, ulong h);
char __attribute__((always_inline)) __attribute__((overloadable)) clz(char f);
char2 __attribute__((always_inline)) __attribute__((overloadable)) clz(char2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable)) clz(char3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable)) clz(char4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable)) clz(char8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
clz(char16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable)) clz(uchar f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
clz(uchar2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
clz(uchar3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
clz(uchar4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
clz(uchar8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
clz(uchar16 f);
short __attribute__((always_inline)) __attribute__((overloadable)) clz(short f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
clz(short2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
clz(short3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
clz(short4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
clz(short8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
clz(short16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
clz(ushort f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
clz(ushort2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
clz(ushort3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
clz(ushort4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
clz(ushort8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
clz(ushort16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) clz(int f);
int2 __attribute__((always_inline)) __attribute__((overloadable)) clz(int2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable)) clz(int3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable)) clz(int4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable)) clz(int8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable)) clz(int16 f);
uint __attribute__((always_inline)) __attribute__((overloadable)) clz(uint f);
uint2 __attribute__((always_inline)) __attribute__((overloadable)) clz(uint2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable)) clz(uint3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable)) clz(uint4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable)) clz(uint8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
clz(uint16 f);
long __attribute__((always_inline)) __attribute__((overloadable)) clz(long f);
long2 __attribute__((always_inline)) __attribute__((overloadable)) clz(long2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable)) clz(long3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable)) clz(long4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable)) clz(long8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
clz(long16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable)) clz(ulong f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
clz(ulong2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
clz(ulong3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
clz(ulong4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
clz(ulong8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
clz(ulong16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(char f, char g, char h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(char2 f, char2 g, char2 h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(char3 f, char3 g, char3 h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(char4 f, char4 g, char4 h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(char8 f, char8 g, char8 h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(char16 f, char16 g, char16 h);
uchar __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uchar f, uchar g, uchar h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uchar2 f, uchar2 g, uchar2 h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uchar3 f, uchar3 g, uchar3 h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uchar4 f, uchar4 g, uchar4 h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uchar8 f, uchar8 g, uchar8 h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uchar16 f, uchar16 g, uchar16 h);
short __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(short f, short g, short h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(short2 f, short2 g, short2 h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(short3 f, short3 g, short3 h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(short4 f, short4 g, short4 h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(short8 f, short8 g, short8 h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(short16 f, short16 g, short16 h);
ushort __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ushort f, ushort g, ushort h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ushort2 f, ushort2 g, ushort2 h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ushort3 f, ushort3 g, ushort3 h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ushort4 f, ushort4 g, ushort4 h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ushort8 f, ushort8 g, ushort8 h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ushort16 f, ushort16 g, ushort16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(int f, int g, int h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(int2 f, int2 g, int2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(int3 f, int3 g, int3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(int4 f, int4 g, int4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(int8 f, int8 g, int8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(int16 f, int16 g, int16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uint f, uint g, uint h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uint2 f, uint2 g, uint2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uint3 f, uint3 g, uint3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uint4 f, uint4 g, uint4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uint8 f, uint8 g, uint8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(uint16 f, uint16 g, uint16 h);
long __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(long f, long g, long h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(long2 f, long2 g, long2 h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(long3 f, long3 g, long3 h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(long4 f, long4 g, long4 h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(long8 f, long8 g, long8 h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(long16 f, long16 g, long16 h);
ulong __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ulong f, ulong g, ulong h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ulong2 f, ulong2 g, ulong2 h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ulong3 f, ulong3 g, ulong3 h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ulong4 f, ulong4 g, ulong4 h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ulong8 f, ulong8 g, ulong8 h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
mad_hi(ulong16 f, ulong16 g, ulong16 h);
char __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(char f, char g, char h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(char2 f, char2 g, char2 h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(char3 f, char3 g, char3 h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(char4 f, char4 g, char4 h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(char8 f, char8 g, char8 h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(char16 f, char16 g, char16 h);
uchar __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uchar f, uchar g, uchar h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uchar2 f, uchar2 g, uchar2 h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uchar3 f, uchar3 g, uchar3 h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uchar4 f, uchar4 g, uchar4 h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uchar8 f, uchar8 g, uchar8 h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uchar16 f, uchar16 g, uchar16 h);
short __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(short f, short g, short h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(short2 f, short2 g, short2 h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(short3 f, short3 g, short3 h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(short4 f, short4 g, short4 h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(short8 f, short8 g, short8 h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(short16 f, short16 g, short16 h);
ushort __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ushort f, ushort g, ushort h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ushort2 f, ushort2 g, ushort2 h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ushort3 f, ushort3 g, ushort3 h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ushort4 f, ushort4 g, ushort4 h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ushort8 f, ushort8 g, ushort8 h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ushort16 f, ushort16 g, ushort16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(int f, int g, int h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(int2 f, int2 g, int2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(int3 f, int3 g, int3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(int4 f, int4 g, int4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(int8 f, int8 g, int8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(int16 f, int16 g, int16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uint f, uint g, uint h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uint2 f, uint2 g, uint2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uint3 f, uint3 g, uint3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uint4 f, uint4 g, uint4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uint8 f, uint8 g, uint8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(uint16 f, uint16 g, uint16 h);
long __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(long f, long g, long h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(long2 f, long2 g, long2 h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(long3 f, long3 g, long3 h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(long4 f, long4 g, long4 h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(long8 f, long8 g, long8 h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(long16 f, long16 g, long16 h);
ulong __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ulong f, ulong g, ulong h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ulong2 f, ulong2 g, ulong2 h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ulong3 f, ulong3 g, ulong3 h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ulong4 f, ulong4 g, ulong4 h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ulong8 f, ulong8 g, ulong8 h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
mad_sat(ulong16 f, ulong16 g, ulong16 h);
char __attribute__((always_inline)) __attribute__((overloadable))
max(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
max(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
max(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
max(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
max(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
max(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
max(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
max(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
max(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
max(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
max(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
max(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
max(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
max(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
max(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
max(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
max(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
max(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
max(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
max(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
max(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
max(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
max(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
max(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
max(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
max(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
max(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
max(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
max(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
max(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
max(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
max(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
max(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
max(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
max(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
max(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
max(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
max(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
max(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
max(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
max(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
max(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
max(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
max(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
max(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
max(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
max(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
max(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
min(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
min(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
min(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
min(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
min(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
min(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
min(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
min(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
min(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
min(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
min(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
min(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
min(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
min(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
min(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
min(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
min(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
min(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
min(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
min(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
min(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
min(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
min(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
min(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
min(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
min(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
min(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
min(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
min(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
min(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
min(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
min(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
min(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
min(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
min(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
min(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
min(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
min(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
min(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
min(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
min(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
min(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
min(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
min(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
min(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
min(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
min(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
min(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
mul_hi(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
rotate(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
rotate(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
rotate(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
rotate(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
rotate(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
rotate(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
rotate(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
rotate(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
rotate(ulong16 f, ulong16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(char f, char g);
char2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(char2 f, char2 g);
char3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(char3 f, char3 g);
char4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(char4 f, char4 g);
char8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(char8 f, char8 g);
char16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(char16 f, char16 g);
uchar __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uchar f, uchar g);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uchar2 f, uchar2 g);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uchar3 f, uchar3 g);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uchar4 f, uchar4 g);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uchar8 f, uchar8 g);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uchar16 f, uchar16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(short f, short g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(short2 f, short2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(short3 f, short3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(short4 f, short4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(short8 f, short8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(short16 f, short16 g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ushort f, ushort g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ushort2 f, ushort2 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ushort3 f, ushort3 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ushort4 f, ushort4 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ushort8 f, ushort8 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ushort16 f, ushort16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(uint16 f, uint16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(long f, long g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(long2 f, long2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(long3 f, long3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(long4 f, long4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(long8 f, long8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(long16 f, long16 g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ulong f, ulong g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ulong2 f, ulong2 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ulong3 f, ulong3 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ulong4 f, ulong4 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ulong8 f, ulong8 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
sub_sat(ulong16 f, ulong16 g);
short __attribute__((always_inline)) __attribute__((overloadable))
upsample(char f, uchar g);
ushort __attribute__((always_inline)) __attribute__((overloadable))
upsample(uchar f, uchar g);
short2 __attribute__((always_inline)) __attribute__((overloadable))
upsample(char2 f, uchar2 g);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uchar2 f, uchar2 g);
short3 __attribute__((always_inline)) __attribute__((overloadable))
upsample(char3 f, uchar3 g);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uchar3 f, uchar3 g);
short4 __attribute__((always_inline)) __attribute__((overloadable))
upsample(char4 f, uchar4 g);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uchar4 f, uchar4 g);
short8 __attribute__((always_inline)) __attribute__((overloadable))
upsample(char8 f, uchar8 g);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uchar8 f, uchar8 g);
short16 __attribute__((always_inline)) __attribute__((overloadable))
upsample(char16 f, uchar16 g);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uchar16 f, uchar16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
upsample(short f, ushort g);
uint __attribute__((always_inline)) __attribute__((overloadable))
upsample(ushort f, ushort g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
upsample(short2 f, ushort2 g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
upsample(ushort2 f, ushort2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
upsample(short3 f, ushort3 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
upsample(ushort3 f, ushort3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
upsample(short4 f, ushort4 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
upsample(ushort4 f, ushort4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
upsample(short8 f, ushort8 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
upsample(ushort8 f, ushort8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
upsample(short16 f, ushort16 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
upsample(ushort16 f, ushort16 g);
long __attribute__((always_inline)) __attribute__((overloadable))
upsample(int f, uint g);
ulong __attribute__((always_inline)) __attribute__((overloadable))
upsample(uint f, uint g);
long2 __attribute__((always_inline)) __attribute__((overloadable))
upsample(int2 f, uint2 g);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uint2 f, uint2 g);
long3 __attribute__((always_inline)) __attribute__((overloadable))
upsample(int3 f, uint3 g);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uint3 f, uint3 g);
long4 __attribute__((always_inline)) __attribute__((overloadable))
upsample(int4 f, uint4 g);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uint4 f, uint4 g);
long8 __attribute__((always_inline)) __attribute__((overloadable))
upsample(int8 f, uint8 g);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uint8 f, uint8 g);
long16 __attribute__((always_inline)) __attribute__((overloadable))
upsample(int16 f, uint16 g);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
upsample(uint16 f, uint16 g);
char __attribute__((always_inline)) __attribute__((overloadable))
popcount(char f);
char2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(char2 f);
char3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(char3 f);
char4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(char4 f);
char8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(char8 f);
char16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(char16 f);
uchar __attribute__((always_inline)) __attribute__((overloadable))
popcount(uchar f);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uchar2 f);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uchar3 f);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uchar4 f);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uchar8 f);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uchar16 f);
short __attribute__((always_inline)) __attribute__((overloadable))
popcount(short f);
short2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(short2 f);
short3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(short3 f);
short4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(short4 f);
short8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(short8 f);
short16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(short16 f);
ushort __attribute__((always_inline)) __attribute__((overloadable))
popcount(ushort f);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ushort2 f);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ushort3 f);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ushort4 f);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ushort8 f);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ushort16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
popcount(int f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(int2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(int3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(int4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(int8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(int16 f);
uint __attribute__((always_inline)) __attribute__((overloadable))
popcount(uint f);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uint2 f);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uint3 f);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uint4 f);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uint8 f);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(uint16 f);
long __attribute__((always_inline)) __attribute__((overloadable))
popcount(long f);
long2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(long2 f);
long3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(long3 f);
long4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(long4 f);
long8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(long8 f);
long16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(long16 f);
ulong __attribute__((always_inline)) __attribute__((overloadable))
popcount(ulong f);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ulong2 f);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ulong3 f);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ulong4 f);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ulong8 f);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
popcount(ulong16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
mad24(int f, int g, int h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
mad24(int2 f, int2 g, int2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
mad24(int3 f, int3 g, int3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
mad24(int4 f, int4 g, int4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
mad24(int8 f, int8 g, int8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
mad24(int16 f, int16 g, int16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
mad24(uint f, uint g, uint h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
mad24(uint2 f, uint2 g, uint2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
mad24(uint3 f, uint3 g, uint3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
mad24(uint4 f, uint4 g, uint4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
mad24(uint8 f, uint8 g, uint8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
mad24(uint16 f, uint16 g, uint16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
mul24(int f, int g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
mul24(int2 f, int2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
mul24(int3 f, int3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
mul24(int4 f, int4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
mul24(int8 f, int8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
mul24(int16 f, int16 g);
uint __attribute__((always_inline)) __attribute__((overloadable))
mul24(uint f, uint g);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
mul24(uint2 f, uint2 g);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
mul24(uint3 f, uint3 g);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
mul24(uint4 f, uint4 g);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
mul24(uint8 f, uint8 g);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
mul24(uint16 f, uint16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
clamp(float f, float g, float h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float2 f, float2 g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float3 f, float3 g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float4 f, float4 g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float8 f, float8 g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float16 f, float16 g, float16 h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float2 f, float g, float h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float3 f, float g, float h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float4 f, float g, float h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float8 f, float g, float h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
clamp(float16 f, float g, float h);
float __attribute__((always_inline)) __attribute__((overloadable))
degrees(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
degrees(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
degrees(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
degrees(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
degrees(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
degrees(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
max(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
max(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
max(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
max(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
max(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
max(float16 f, float16 g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
max(float2 f, float g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
max(float3 f, float g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
max(float4 f, float g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
max(float8 f, float g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
max(float16 f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
min(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
min(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
min(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
min(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
min(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
min(float16 f, float16 g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
min(float2 f, float g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
min(float3 f, float g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
min(float4 f, float g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
min(float8 f, float g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
min(float16 f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
mix(float f, float g, float h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
mix(float2 f, float2 g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
mix(float3 f, float3 g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
mix(float4 f, float4 g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
mix(float8 f, float8 g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
mix(float16 f, float16 g, float16 h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
mix(float2 f, float2 g, float h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
mix(float3 f, float3 g, float h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
mix(float4 f, float4 g, float h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
mix(float8 f, float8 g, float h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
mix(float16 f, float16 g, float h);
float __attribute__((always_inline)) __attribute__((overloadable))
radians(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
radians(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
radians(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
radians(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
radians(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
radians(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
step(float f, float g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
step(float2 f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
step(float3 f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
step(float4 f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
step(float8 f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
step(float16 f, float16 g);
float2 __attribute__((always_inline)) __attribute__((overloadable))
step(float f, float2 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
step(float f, float3 g);
float4 __attribute__((always_inline)) __attribute__((overloadable))
step(float f, float4 g);
float8 __attribute__((always_inline)) __attribute__((overloadable))
step(float f, float8 g);
float16 __attribute__((always_inline)) __attribute__((overloadable))
step(float f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float f, float g, float h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float2 f, float2 g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float3 f, float3 g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float4 f, float4 g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float8 f, float8 g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float16 f, float16 g, float16 h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float f, float g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float f, float g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float f, float g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float f, float g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
smoothstep(float f, float g, float16 h);
float __attribute__((always_inline)) __attribute__((overloadable))
sign(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
sign(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
sign(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
sign(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
sign(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
sign(float16 f);
// OpenCL 1.2 Section 6.12.5 Geometric Functions

float4 __attribute__((always_inline)) __attribute__((overloadable))
cross(float4 f, float4 g);
float3 __attribute__((always_inline)) __attribute__((overloadable))
cross(float3 f, float3 g);
float __attribute__((always_inline)) __attribute__((overloadable))
dot(float f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
dot(float2 f, float2 g);
float __attribute__((always_inline)) __attribute__((overloadable))
dot(float3 f, float3 g);
float __attribute__((always_inline)) __attribute__((overloadable))
dot(float4 f, float4 g);
float __attribute__((always_inline)) __attribute__((overloadable))
dot(float8 f, float8 g);
float __attribute__((always_inline)) __attribute__((overloadable))
dot(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
distance(float f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
distance(float2 f, float2 g);
float __attribute__((always_inline)) __attribute__((overloadable))
distance(float3 f, float3 g);
float __attribute__((always_inline)) __attribute__((overloadable))
distance(float4 f, float4 g);
float __attribute__((always_inline)) __attribute__((overloadable))
distance(float8 f, float8 g);
float __attribute__((always_inline)) __attribute__((overloadable))
distance(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
length(float f);
float __attribute__((always_inline)) __attribute__((overloadable))
length(float2 f);
float __attribute__((always_inline)) __attribute__((overloadable))
length(float3 f);
float __attribute__((always_inline)) __attribute__((overloadable))
length(float4 f);
float __attribute__((always_inline)) __attribute__((overloadable))
length(float8 f);
float __attribute__((always_inline)) __attribute__((overloadable))
length(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
normalize(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
normalize(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
normalize(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
normalize(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
normalize(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
normalize(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_distance(float f, float g);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_distance(float2 f, float2 g);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_distance(float3 f, float3 g);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_distance(float4 f, float4 g);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_distance(float8 f, float8 g);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_distance(float16 f, float16 g);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_length(float f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_length(float2 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_length(float3 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_length(float4 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_length(float8 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_length(float16 f);
float __attribute__((always_inline)) __attribute__((overloadable))
fast_normalize(float f);
float2 __attribute__((always_inline)) __attribute__((overloadable))
fast_normalize(float2 f);
float3 __attribute__((always_inline)) __attribute__((overloadable))
fast_normalize(float3 f);
float4 __attribute__((always_inline)) __attribute__((overloadable))
fast_normalize(float4 f);
float8 __attribute__((always_inline)) __attribute__((overloadable))
fast_normalize(float8 f);
float16 __attribute__((always_inline)) __attribute__((overloadable))
fast_normalize(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
isfinite(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isfinite(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isfinite(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isfinite(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isfinite(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isfinite(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) isinf(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isinf(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isinf(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isinf(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isinf(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isinf(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) isnan(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isnan(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isnan(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isnan(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isnan(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isnan(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
isnormal(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isnormal(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isnormal(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isnormal(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isnormal(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isnormal(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
signbit(float f);
int2 __attribute__((always_inline)) __attribute__((overloadable))
signbit(float2 f);
int3 __attribute__((always_inline)) __attribute__((overloadable))
signbit(float3 f);
int4 __attribute__((always_inline)) __attribute__((overloadable))
signbit(float4 f);
int8 __attribute__((always_inline)) __attribute__((overloadable))
signbit(float8 f);
int16 __attribute__((always_inline)) __attribute__((overloadable))
signbit(float16 f);
int __attribute__((always_inline)) __attribute__((overloadable))
isequal(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isequal(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isequal(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isequal(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isequal(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isequal(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
isnotequal(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isnotequal(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isnotequal(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isnotequal(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isnotequal(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isnotequal(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
isgreater(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isgreater(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isgreater(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isgreater(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isgreater(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isgreater(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
isgreaterequal(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isgreaterequal(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isgreaterequal(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isgreaterequal(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isgreaterequal(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isgreaterequal(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
isless(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isless(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isless(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isless(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isless(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isless(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
islessequal(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
islessequal(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
islessequal(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
islessequal(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
islessequal(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
islessequal(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
islessgreater(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
islessgreater(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
islessgreater(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
islessgreater(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
islessgreater(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
islessgreater(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
isordered(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isordered(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isordered(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isordered(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isordered(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isordered(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable))
isunordered(float f, float g);
int2 __attribute__((always_inline)) __attribute__((overloadable))
isunordered(float2 f, float2 g);
int3 __attribute__((always_inline)) __attribute__((overloadable))
isunordered(float3 f, float3 g);
int4 __attribute__((always_inline)) __attribute__((overloadable))
isunordered(float4 f, float4 g);
int8 __attribute__((always_inline)) __attribute__((overloadable))
isunordered(float8 f, float8 g);
int16 __attribute__((always_inline)) __attribute__((overloadable))
isunordered(float16 f, float16 g);
int __attribute__((always_inline)) __attribute__((overloadable)) any(char f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(char2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(char3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(char4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(char8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(char16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(short f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(short2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(short3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(short4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(short8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(short16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(int f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(int2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(int3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(int4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(int8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(int16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(long f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(long2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(long3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(long4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(long8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) any(long16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(char f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(char2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(char3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(char4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(char8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(char16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(short f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(short2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(short3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(short4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(short8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(short16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(int f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(int2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(int3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(int4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(int8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(int16 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(long f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(long2 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(long3 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(long4 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(long8 f);
int __attribute__((always_inline)) __attribute__((overloadable)) all(long16 f);
char __attribute__((always_inline)) __attribute__((overloadable))
bitselect(char f, char g, char h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(char2 f, char2 g, char2 h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(char3 f, char3 g, char3 h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(char4 f, char4 g, char4 h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(char8 f, char8 g, char8 h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(char16 f, char16 g, char16 h);
uchar __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uchar f, uchar g, uchar h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uchar2 f, uchar2 g, uchar2 h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uchar3 f, uchar3 g, uchar3 h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uchar4 f, uchar4 g, uchar4 h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uchar8 f, uchar8 g, uchar8 h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uchar16 f, uchar16 g, uchar16 h);
short __attribute__((always_inline)) __attribute__((overloadable))
bitselect(short f, short g, short h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(short2 f, short2 g, short2 h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(short3 f, short3 g, short3 h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(short4 f, short4 g, short4 h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(short8 f, short8 g, short8 h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(short16 f, short16 g, short16 h);
ushort __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ushort f, ushort g, ushort h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ushort2 f, ushort2 g, ushort2 h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ushort3 f, ushort3 g, ushort3 h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ushort4 f, ushort4 g, ushort4 h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ushort8 f, ushort8 g, ushort8 h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ushort16 f, ushort16 g, ushort16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
bitselect(int f, int g, int h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(int2 f, int2 g, int2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(int3 f, int3 g, int3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(int4 f, int4 g, int4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(int8 f, int8 g, int8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(int16 f, int16 g, int16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uint f, uint g, uint h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uint2 f, uint2 g, uint2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uint3 f, uint3 g, uint3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uint4 f, uint4 g, uint4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uint8 f, uint8 g, uint8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(uint16 f, uint16 g, uint16 h);
long __attribute__((always_inline)) __attribute__((overloadable))
bitselect(long f, long g, long h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(long2 f, long2 g, long2 h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(long3 f, long3 g, long3 h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(long4 f, long4 g, long4 h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(long8 f, long8 g, long8 h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(long16 f, long16 g, long16 h);
ulong __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ulong f, ulong g, ulong h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ulong2 f, ulong2 g, ulong2 h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ulong3 f, ulong3 g, ulong3 h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ulong4 f, ulong4 g, ulong4 h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ulong8 f, ulong8 g, ulong8 h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(ulong16 f, ulong16 g, ulong16 h);
float __attribute__((always_inline)) __attribute__((overloadable))
bitselect(float f, float g, float h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(float2 f, float2 g, float2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(float3 f, float3 g, float3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(float4 f, float4 g, float4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(float8 f, float8 g, float8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
bitselect(float16 f, float16 g, float16 h);
char __attribute__((always_inline)) __attribute__((overloadable))
select(char f, char g, char h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
select(char2 f, char2 g, char2 h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
select(char3 f, char3 g, char3 h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
select(char4 f, char4 g, char4 h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
select(char8 f, char8 g, char8 h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
select(char16 f, char16 g, char16 h);
uchar __attribute__((always_inline)) __attribute__((overloadable))
select(uchar f, uchar g, char h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar2 f, uchar2 g, char2 h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar3 f, uchar3 g, char3 h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar4 f, uchar4 g, char4 h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar8 f, uchar8 g, char8 h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar16 f, uchar16 g, char16 h);
short __attribute__((always_inline)) __attribute__((overloadable))
select(short f, short g, short h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
select(short2 f, short2 g, short2 h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
select(short3 f, short3 g, short3 h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
select(short4 f, short4 g, short4 h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
select(short8 f, short8 g, short8 h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
select(short16 f, short16 g, short16 h);
ushort __attribute__((always_inline)) __attribute__((overloadable))
select(ushort f, ushort g, short h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort2 f, ushort2 g, short2 h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort3 f, ushort3 g, short3 h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort4 f, ushort4 g, short4 h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort8 f, ushort8 g, short8 h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort16 f, ushort16 g, short16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
select(int f, int g, int h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
select(int2 f, int2 g, int2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
select(int3 f, int3 g, int3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
select(int4 f, int4 g, int4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
select(int8 f, int8 g, int8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
select(int16 f, int16 g, int16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
select(uint f, uint g, int h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
select(uint2 f, uint2 g, int2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
select(uint3 f, uint3 g, int3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
select(uint4 f, uint4 g, int4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
select(uint8 f, uint8 g, int8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
select(uint16 f, uint16 g, int16 h);
long __attribute__((always_inline)) __attribute__((overloadable))
select(long f, long g, long h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
select(long2 f, long2 g, long2 h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
select(long3 f, long3 g, long3 h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
select(long4 f, long4 g, long4 h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
select(long8 f, long8 g, long8 h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
select(long16 f, long16 g, long16 h);
ulong __attribute__((always_inline)) __attribute__((overloadable))
select(ulong f, ulong g, long h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong2 f, ulong2 g, long2 h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong3 f, ulong3 g, long3 h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong4 f, ulong4 g, long4 h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong8 f, ulong8 g, long8 h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong16 f, ulong16 g, long16 h);
float __attribute__((always_inline)) __attribute__((overloadable))
select(float f, float g, int h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
select(float2 f, float2 g, int2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
select(float3 f, float3 g, int3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
select(float4 f, float4 g, int4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
select(float8 f, float8 g, int8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
select(float16 f, float16 g, int16 h);
char __attribute__((always_inline)) __attribute__((overloadable))
select(char f, char g, uchar h);
char2 __attribute__((always_inline)) __attribute__((overloadable))
select(char2 f, char2 g, uchar2 h);
char3 __attribute__((always_inline)) __attribute__((overloadable))
select(char3 f, char3 g, uchar3 h);
char4 __attribute__((always_inline)) __attribute__((overloadable))
select(char4 f, char4 g, uchar4 h);
char8 __attribute__((always_inline)) __attribute__((overloadable))
select(char8 f, char8 g, uchar8 h);
char16 __attribute__((always_inline)) __attribute__((overloadable))
select(char16 f, char16 g, uchar16 h);
uchar __attribute__((always_inline)) __attribute__((overloadable))
select(uchar f, uchar g, uchar h);
uchar2 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar2 f, uchar2 g, uchar2 h);
uchar3 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar3 f, uchar3 g, uchar3 h);
uchar4 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar4 f, uchar4 g, uchar4 h);
uchar8 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar8 f, uchar8 g, uchar8 h);
uchar16 __attribute__((always_inline)) __attribute__((overloadable))
select(uchar16 f, uchar16 g, uchar16 h);
short __attribute__((always_inline)) __attribute__((overloadable))
select(short f, short g, ushort h);
short2 __attribute__((always_inline)) __attribute__((overloadable))
select(short2 f, short2 g, ushort2 h);
short3 __attribute__((always_inline)) __attribute__((overloadable))
select(short3 f, short3 g, ushort3 h);
short4 __attribute__((always_inline)) __attribute__((overloadable))
select(short4 f, short4 g, ushort4 h);
short8 __attribute__((always_inline)) __attribute__((overloadable))
select(short8 f, short8 g, ushort8 h);
short16 __attribute__((always_inline)) __attribute__((overloadable))
select(short16 f, short16 g, ushort16 h);
ushort __attribute__((always_inline)) __attribute__((overloadable))
select(ushort f, ushort g, ushort h);
ushort2 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort2 f, ushort2 g, ushort2 h);
ushort3 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort3 f, ushort3 g, ushort3 h);
ushort4 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort4 f, ushort4 g, ushort4 h);
ushort8 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort8 f, ushort8 g, ushort8 h);
ushort16 __attribute__((always_inline)) __attribute__((overloadable))
select(ushort16 f, ushort16 g, ushort16 h);
int __attribute__((always_inline)) __attribute__((overloadable))
select(int f, int g, uint h);
int2 __attribute__((always_inline)) __attribute__((overloadable))
select(int2 f, int2 g, uint2 h);
int3 __attribute__((always_inline)) __attribute__((overloadable))
select(int3 f, int3 g, uint3 h);
int4 __attribute__((always_inline)) __attribute__((overloadable))
select(int4 f, int4 g, uint4 h);
int8 __attribute__((always_inline)) __attribute__((overloadable))
select(int8 f, int8 g, uint8 h);
int16 __attribute__((always_inline)) __attribute__((overloadable))
select(int16 f, int16 g, uint16 h);
uint __attribute__((always_inline)) __attribute__((overloadable))
select(uint f, uint g, uint h);
uint2 __attribute__((always_inline)) __attribute__((overloadable))
select(uint2 f, uint2 g, uint2 h);
uint3 __attribute__((always_inline)) __attribute__((overloadable))
select(uint3 f, uint3 g, uint3 h);
uint4 __attribute__((always_inline)) __attribute__((overloadable))
select(uint4 f, uint4 g, uint4 h);
uint8 __attribute__((always_inline)) __attribute__((overloadable))
select(uint8 f, uint8 g, uint8 h);
uint16 __attribute__((always_inline)) __attribute__((overloadable))
select(uint16 f, uint16 g, uint16 h);
long __attribute__((always_inline)) __attribute__((overloadable))
select(long f, long g, ulong h);
long2 __attribute__((always_inline)) __attribute__((overloadable))
select(long2 f, long2 g, ulong2 h);
long3 __attribute__((always_inline)) __attribute__((overloadable))
select(long3 f, long3 g, ulong3 h);
long4 __attribute__((always_inline)) __attribute__((overloadable))
select(long4 f, long4 g, ulong4 h);
long8 __attribute__((always_inline)) __attribute__((overloadable))
select(long8 f, long8 g, ulong8 h);
long16 __attribute__((always_inline)) __attribute__((overloadable))
select(long16 f, long16 g, ulong16 h);
ulong __attribute__((always_inline)) __attribute__((overloadable))
select(ulong f, ulong g, ulong h);
ulong2 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong2 f, ulong2 g, ulong2 h);
ulong3 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong3 f, ulong3 g, ulong3 h);
ulong4 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong4 f, ulong4 g, ulong4 h);
ulong8 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong8 f, ulong8 g, ulong8 h);
ulong16 __attribute__((always_inline)) __attribute__((overloadable))
select(ulong16 f, ulong16 g, ulong16 h);
float __attribute__((always_inline)) __attribute__((overloadable))
select(float f, float g, uint h);
float2 __attribute__((always_inline)) __attribute__((overloadable))
select(float2 f, float2 g, uint2 h);
float3 __attribute__((always_inline)) __attribute__((overloadable))
select(float3 f, float3 g, uint3 h);
float4 __attribute__((always_inline)) __attribute__((overloadable))
select(float4 f, float4 g, uint4 h);
float8 __attribute__((always_inline)) __attribute__((overloadable))
select(float8 f, float8 g, uint8 h);
float16 __attribute__((always_inline)) __attribute__((overloadable))
select(float16 f, float16 g, uint16 h);
void __attribute__((always_inline)) __attribute__((overloadable))
barrier(uint i);
void mem_fence(uint i);
#include "clc.h.inc"
#if (__clang_major__ == 3) && (__clang_minor__ == 9)
void __attribute__((always_inline)) __attribute__((overloadable))
wait_group_events(int i, event_t *j);
#else
void wait_group_events(int i, event_t *j);
#endif
#define read_pipe __opencl_read_pipe
#define write_pipe __opencl_write_pipe
#define read_pipe_block __opencl_read_pipe_block
#define write_pipe_block __opencl_write_pipe_block
#define reserve_read_pipe __opencl_reserve_read_pipe
#define reserve_write_pipe __opencl_reserve_write_pipe
#define commit_read_pipe __opencl_commit_read_pipe
#define commit_write_pipe __opencl_commit_write_pipe
#define get_pipe_max_packets __opencl_get_pipe_max_packets
#define get_pipe_num_packets __opencl_get_pipe_num_packets
#define work_group_reserve_read_pipe __opencl_work_group_reserve_read_pipe
#define work_group_reserve_write_pipe __opencl_work_group_reserve_write_pipe
#define work_group_commit_read_pipe __opencl_work_group_commit_read_pipe
#define work_group_commit_write_pipe __opencl_work_group_commit_write_pipe
_Bool __attribute__((always_inline)) is_valid_reserve_id(reserve_id_t id);
#endif // _CLC_H_

// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
