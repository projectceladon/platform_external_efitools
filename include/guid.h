#include <efi.h>

#ifndef BUILD_EFI
const char *guid_to_str(EFI_GUID *guid);
int str_to_guid(const char *str, EFI_GUID *guid);
int compare_guid(EFI_GUID *g1, EFI_GUID *g2);
EFI_GUID *get_owner_guid(char *var);
#endif

extern EFI_GUID GV_GUID;
extern EFI_GUID SIG_DB;
extern EFI_GUID X509_GUID;
extern EFI_GUID RSA2048_GUID;
extern EFI_GUID PKCS7_GUID;
extern EFI_GUID IMAGE_PROTOCOL;
extern EFI_GUID SIMPLE_FS_PROTOCOL;
extern EFI_GUID EFI_CERT_SHA256_GUID;
extern EFI_GUID MOK_OWNER;
extern EFI_GUID SECURITY_PROTOCOL_GUID;
extern EFI_GUID SECURITY2_PROTOCOL_GUID;
extern EFI_GUID SECURE_VARIABLE_GUID;
