# derived from external/uefi_shim.

LOCAL_PATH := $(call my-dir)

EFITOOLS_CFLAGS :=  -fpic -Wall -fshort-wchar -fno-strict-aliasing -fno-merge-constants -mno-red-zone -fno-stack-protector -g

EFITOOLS_LDLIBS_windows := -lws2_32 -lgdi32

EFITOOLS_LDLIBS_linux := -lrt -ldl -lpthread
EFITOOLS_CXX_STL := libc++_static

EFITOOLS_C_INCLUDES := \
    external/gnu-efi/gnu-efi-3.0/inc \
    external/gnu-efi/gnu-efi-3.0/inc/ia32 \
    vendor/intel/external/openssl/include/ \
    $(LOCAL_PATH)/lib \
    $(LOCAL_PATH)/include

EFITOOLS_STATIC_LIBRARIES := libcrypto_static2

include $(CLEAR_VARS)

LOCAL_MODULE := sign-efi-sig-list
LOCAL_MODULE_HOST_OS := linux
#LOCAL_LDLIBS_windows := $(EFITOOLS_LDLIBS_windows)
LOCAL_LDLIBS_linux := $(EFITOOLS_LDLIBS_linux)
LOCAL_CXX_STL := $(EFITOOLS_CXX_STL)

LOCAL_STATIC_LIBRARIES := $(EFITOOLS_STATIC_LIBRARIES)
LOCAL_SRC_FILES_linux := sign-efi-sig-list.c lib/guid.c
LOCAL_CFLAGS := $(EFITOOLS_CFLAGS)
#LOCAL_SRC_FILES_windows := sign-efi-sig-list.c lib/guid.c strptime.c
#LOCAL_CFLAGS_windows := $(LOCAL_CFLAGS) -DHAVE_LOCALE_H
LOCAL_C_INCLUDES := $(EFITOOLS_C_INCLUDES)

include $(BUILD_HOST_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_MODULE := cert-to-efi-sig-list
LOCAL_MODULE_HOST_OS := linux
#LOCAL_LDLIBS_windows := $(EFITOOLS_LDLIBS_windows)
LOCAL_LDLIBS_linux := $(EFITOOLS_LDLIBS_linux)
LOCAL_CXX_STL := $(EFITOOLS_CXX_STL)

LOCAL_SRC_FILES := cert-to-efi-sig-list.c lib/guid.c
LOCAL_STATIC_LIBRARIES := $(EFITOOLS_STATIC_LIBRARIES)
LOCAL_CFLAGS := $(EFITOOLS_CFLAGS)
LOCAL_C_INCLUDES := $(EFITOOLS_C_INCLUDES)

include $(BUILD_HOST_EXECUTABLE)


