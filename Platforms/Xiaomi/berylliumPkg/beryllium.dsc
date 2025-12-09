##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = beryllium
  PLATFORM_GUID                  = 659EDC0F-E61F-47CA-910B-869BDA57A64D
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/berylliumPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = berylliumPkg/beryllium.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 1

[PcdsFixedAtBuild]
  # DDR Start Address
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000

  # UEFI Stack Addresses
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x9FF90000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000

  # Device GUID
  gSiliciumPkgTokenSpaceGuid.PcdDeviceGuid|{ 0x0F, 0xDC, 0x9E, 0x65, 0x1F, 0xE6, 0xCA, 0x47, 0x91, 0x0B, 0x86, 0x9B, 0xDA, 0x57, 0xA6, 0x4D }

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemManufacturer|"Xiaomi"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"POCOPHONE F1"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"beryllium"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"M1805E10A"
  # Didn't find it for now
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosBoardModel|"" 

  # Simple Frame Buffer
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferWidth|1080
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferHeight|2246
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferColorDepth|32

  # Platform Pei
  gQcomPkgTokenSpaceGuid.PcdPlatformType|"LA"

  # Dynamic RAM Start Address
  gSiliciumPkgTokenSpaceGuid.PcdRamPartitionBase|0xAA000000

  # SD Card Slot
  gQcomPkgTokenSpaceGuid.PcdInitCardSlot|TRUE

[LibraryClasses]
  MemoryMapLib|berylliumPkg/Library/MemoryMapLib/MemoryMapLib.inf
  ConfigurationMapLib|berylliumPkg/Library/ConfigurationMapLib/ConfigurationMapLib.inf
  AcpiDeviceUpdateLib|SiliciumPkg/Library/AcpiDeviceUpdateLibNull/AcpiDeviceUpdateLibNull.inf

!include NapaliPkg/NapaliPkg.dsc.inc
