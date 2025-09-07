/** @file
*
*  Copyright (c) 2018, Linaro. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include <Library/UefiBootServicesTableLib.h>

#include <Protocol/EmbeddedGpio.h>
#include <Library/DebugLib.h>

GPIO_CONTROLLER gGpioDevice[] = {
  //
  // { base address, gpio index, gpio count }
  //
  //{ 0xe8a0b000, 0, 8 },    // GPIO0
  { 0xe8a0c000, 5, 8 },    // GPIO1
  { 0xe8a0d000, 13, 8 },   // GPIO2
  { 0xe8a0e000, 21, 8 },   // GPIO3
  { 0xe8a0f000, 29, 8 },   // GPIO4
  { 0xe8a10000, 37, 8 },   // GPIO5
  { 0xe8a11000, 45, 8 },   // GPIO6
  { 0xe8a12000, 53, 8 },   // GPIO7
  { 0xe8a13000, 61, 8 },   // GPIO8
  { 0xe8a14000, 69, 8 },   // GPIO9
  { 0xe8a15000, 77, 8 },   // GPIO10
  { 0xe8a16000, 85, 8 },   // GPIO11
  { 0xe8a17000, 93, 8 },   // GPIO12
  { 0xe8a18000, 101, 8 },  // GPIO13
  { 0xe8a19000, 109, 8 },  // GPIO14
  { 0xe8a1a000, 117, 8 },  // GPIO15
  { 0xe8a1b000, 125, 8 },  // GPIO16
  { 0xe8a1c000, 133, 8 },  // GPIO17
  { 0xe8a1d000, 51, 2 },   // GPIO18
  //{ 0xe8a1e000, 152, 8 }   // GPIO19
  //{ 0xe8a1f000, 152, 8 }   // GPIO20
  //{ 0xe8a20000, 152, 8 }   // GPIO21
  { 0xfff0b000, 0, 6 },   // GPIO22
  { 0xfff0c000, 6, 7 },   // GPIO23
  { 0xfff0d000, 13, 6 },   // GPIO24
  { 0xfff0e000, 21, 4 },   // GPIO25
  { 0xfff0f000, 28, 8 },   // GPIO26
  { 0xfff10000, 36, 3 },   // GPIO27
  { 0xfff1d000, 19, 2 },   // GPIO28
  { 0xfff1e000, 39, 4 },   // GPIO29
  //{ 0xfff1f000, 152, 8 },   // GPIO30
};

PLATFORM_GPIO_CONTROLLER gPlatformGpioDevice = {
  //
  // { global gpio count, gpio controller counter, GPIO_CONTROLLER }
  //
  184, 26, gGpioDevice
};

EFI_STATUS
EFIAPI
Hi6250GpioEntryPoint (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS  Status;
  EFI_HANDLE  Handle;

  // Install the Embedded Platform GPIO Protocol onto a new handle
  Handle = NULL;
  Status = gBS->InstallMultipleProtocolInterfaces(
                  &Handle,
                  &gPlatformGpioProtocolGuid, &gPlatformGpioDevice,
                  NULL
                 );
  if (EFI_ERROR(Status)) {
    DEBUG((EFI_D_ERROR, "Hi6250Gpio: FAIL\n"));
    Status = EFI_OUT_OF_RESOURCES;
  }

  return Status;
}
