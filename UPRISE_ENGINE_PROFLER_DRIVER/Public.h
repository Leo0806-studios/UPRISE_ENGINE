/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_UPRISEENGINEPROFLERDRIVER,
    0xc54017e9,0xe285,0x4569,0x91,0xcd,0xa2,0x36,0xb9,0x6d,0xb6,0x5f);
// {c54017e9-e285-4569-91cd-a236b96db65f}
