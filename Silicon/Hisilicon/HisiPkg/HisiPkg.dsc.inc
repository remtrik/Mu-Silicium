##
#  Copyright (c) 2011-2012, ARM Limited. All rights reserved.
#  Copyright (c) 2016, Hisilicon Limited. All rights reserved.
#  Copyright (c) 2016, Linaro Limited. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

[PcdsFixedAtBuild]
  # RAM Size (512 MB)
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x20000000

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmBiosProcessorSocket|"Hisilicon"
  gSiliciumPkgTokenSpaceGuid.PcdSmBiosProcessorManufacturer|"Huawei Corporation"

[LibraryClasses]
  # Custom Tegra Libraries
!if $(USE_CUSTOM_TIMER) == 1
  #TimerLib|HisiPkg/GPLLibrary/TegraTimerLib/TegraTimerLib.inf
!endif

  # HOB Library
  PlatformHobLib|SiliciumPkg/Library/PlatformHobLibNull/PlatformHobLibNull.inf

  # Memory Protection Library
  MemoryProtectionLib|HisiPkg/Library/MemoryProtectionLib/MemoryProtectionLib.inf

[Components]
  # DynamicRam
  HisiPkg/Drivers/DynamicRamDxe/DynamicRamDxe.inf

  # SmBios
  HisiPkg/Drivers/SmBiosTableDxe/SmBiosTableDxe.inf

  # Custom Tegra Drivers
  #HisiPkg/GPLDrivers/TegraGpioDxe/TegraGpioDxe.inf
!if $(USE_CUSTOM_TIMER) == 1
  #HisiPkg/GPLDrivers/TegraTimerDxe/TegraTimerDxe.inf
!endif
  #HisiPkg/GPLDrivers/TegraClockDxe/TegraClockDxe.inf

!include SiliciumPkg/SiliciumPkg.dsc.inc