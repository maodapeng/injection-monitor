/*++

author:

Daulet Tumbayev

Module Name:

im_utils.h

Abstract:

Allocaion, free, copy functions for buffers, resources, strings

Environment:

Kernel mode

--*/

#pragma once

//------------------------------------------------------------------------
//  Includes.
//------------------------------------------------------------------------

#include "im.h"

//------------------------------------------------------------------------
//  Function prototypes.
//------------------------------------------------------------------------

//
// Buffers
//

_Check_return_
    NTSTATUS
    IMAllocateNonPagedBuffer(
        _Outptr_result_buffer_(Size) PVOID *Buffer,
        _In_ SIZE_T Size);

VOID IMFreeNonPagedBuffer(
    _Inout_ PVOID Buffer);

//
// Strings
//

_Check_return_
    NTSTATUS
    IMCopyString(
        _In_ PUNICODE_STRING Src,
        _Out_ PULONG DestSize,
        _Out_ PVOID *Dest,
        _Inout_ PULONG TotalSize);

_Check_return_
    NTSTATUS
    IMAllocateUnicodeString(
        _Inout_ PUNICODE_STRING String,
        _In_ USHORT Size);

_Check_return_
    NTSTATUS
    IMCopyUnicodeString(
        _Inout_ PUNICODE_STRING DestinationString,
        _In_ PCUNICODE_STRING SourceString);

_Check_return_
    NTSTATUS
    IMCopyUnicodeStringEx(
        _Inout_ PUNICODE_STRING DestinationString,
        _In_ PCUNICODE_STRING SourceString,
        _In_ ULONG Start,
        _In_ ULONG Length);

BOOLEAN
IMIsContainsString(
    _In_ PUNICODE_STRING String,
    _In_ PUNICODE_STRING SubString);

BOOLEAN
IMIsStartWithString(
    _In_ PUNICODE_STRING String,
    _In_ PUNICODE_STRING SubString);

_Check_return_
    NTSTATUS
    IMSplitString(
        _In_ PUNICODE_STRING String,
        _Out_ PUNICODE_STRING Beginning,
        _Out_ PUNICODE_STRING Ending,
        _In_ WCHAR Delimeter,
        _In_ LONG Occurrence);

_Check_return_
    NTSTATUS
    IMConcatStrings(
        _Out_ PUNICODE_STRING Dest,
        _In_ PUNICODE_STRING Start,
        _In_ PUNICODE_STRING End);

_Check_return_
    NTSTATUS
    IMToString(
        _In_ PWCHAR Buffer,
        _In_ ULONG Size,
        _In_ PUNICODE_STRING String);