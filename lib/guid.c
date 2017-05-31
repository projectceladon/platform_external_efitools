/*
 * Copyright 2012 <James.Bottomley@HansenPartnership.com>
 *
 * see COPYING file
 */

#include <guid.h>
#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))

#ifndef BUILD_EFI
/* EFI has %g for this, so it's only needed in platform c */
const char *guid_to_str(EFI_GUID *guid)
{
	static char str[256];

	sprintf(str, "%08x-%04hx-%04hx-%02hhx%02hhx-%02hhx%02hhx%02hhx%02hhx%02hhx%02hhx",
		guid->Data1, guid->Data2, guid->Data3,
		guid->Data4[0], guid->Data4[1], guid->Data4[2],
		guid->Data4[3], guid->Data4[4], guid->Data4[5],
		guid->Data4[6], guid->Data4[7]);

	return str;
}

int str_to_guid(const char *str, EFI_GUID *guid)
{
	int args;
	args = sscanf(str,
		      "%8x-%4hx-%4hx-%2hhx%2hhx-%2hhx%2hhx%2hhx%2hhx%2hhx%2hhx",
		      &guid->Data1, &guid->Data2, &guid->Data3,
		      guid->Data4, guid->Data4 + 1, guid->Data4 + 2,
		      guid->Data4 + 3, guid->Data4 + 4, guid->Data4 + 5,
		      guid->Data4 + 6, guid->Data4 + 7);

	return args != 11;
}

int
compare_guid(EFI_GUID *g1, EFI_GUID *g2)
{
	return memcmp(g1, g2, sizeof(*g1));
}

EFI_GUID *
get_owner_guid(char *var)
{
	char *variables[] = { "PK", "KEK", "db", "dbx", "dbt", "MokList" };
	EFI_GUID *owners[] = { &GV_GUID, &GV_GUID, &SIG_DB, &SIG_DB, &SIG_DB, &MOK_OWNER };
	EFI_GUID *owner = NULL;
	int i;

	for(i = 0; i < ARRAY_SIZE(variables); i++) {
		if (strcmp(var, variables[i]) == 0) {
			owner = owners[i];
			break;
		}
	}

	return owner;
}
#endif



/* all the necessary guids */
EFI_GUID GV_GUID = EFI_GLOBAL_VARIABLE;
EFI_GUID SIG_DB = { 0xd719b2cb, 0x3d3a, 0x4596, {0xa3, 0xbc, 0xda, 0xd0,  0xe, 0x67, 0x65, 0x6f }};

EFI_GUID X509_GUID =   { 0xa5c059a1, 0x94e4, 0x4aa7, {0x87, 0xb5, 0xab, 0x15, 0x5c, 0x2b, 0xf0, 0x72} };
EFI_GUID RSA2048_GUID = { 0x3c5766e8, 0x269c, 0x4e34, {0xaa, 0x14, 0xed, 0x77, 0x6e, 0x85, 0xb3, 0xb6} };
EFI_GUID PKCS7_GUID = { 0x4aafd29d, 0x68df, 0x49ee, {0x8a, 0xa9, 0x34, 0x7d, 0x37, 0x56, 0x65, 0xa7} };
EFI_GUID IMAGE_PROTOCOL = LOADED_IMAGE_PROTOCOL;
EFI_GUID SIMPLE_FS_PROTOCOL = SIMPLE_FILE_SYSTEM_PROTOCOL;
EFI_GUID EFI_CERT_SHA256_GUID  = { 0xc1c41626, 0x504c, 0x4092, { 0xac, 0xa9, 0x41, 0xf9, 0x36, 0x93, 0x43, 0x28 } };
EFI_GUID MOK_OWNER = { 0x605dab50, 0xe046, 0x4300, {0xab, 0xb6, 0x3d, 0xd8, 0x10, 0xdd, 0x8b, 0x23} };
EFI_GUID SECURITY_PROTOCOL_GUID = { 0xA46423E3, 0x4617, 0x49f1, {0xB9, 0xFF, 0xD1, 0xBF, 0xA9, 0x11, 0x58, 0x39 } };
EFI_GUID SECURITY2_PROTOCOL_GUID = { 0x94ab2f58, 0x1438, 0x4ef1, {0x91, 0x52, 0x18, 0x94, 0x1a, 0x3a, 0x0e, 0x68 } };
EFI_GUID SECURE_VARIABLE_GUID = { 0xaaf32c78, 0x947b, 0x439a, { 0xa1, 0x80, 0x2e, 0x14, 0x4e, 0xc3, 0x77, 0x92 } };
