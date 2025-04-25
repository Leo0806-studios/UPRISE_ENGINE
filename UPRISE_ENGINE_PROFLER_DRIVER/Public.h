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
    0xe791dc1d,0x8b2d,0x429f,0x97,0x29,0x46,0x0a,0xf2,0x17,0x83,0xeb);
// {e791dc1d-8b2d-429f-9729-460af21783eb}
