[Defines]
  # GIC
  USE_CUSTOM_GIC                             = 0

  # Timer
  USE_CUSTOM_TIMER                           = 0
  USE_PHYSICAL_TIMER                         = 1

  # KEP
  ENABLE_KEP                                 = 0
  HAS_ACTLR_EL1_UNIMPLEMENTED_ERRATA         = 0
  HAS_AMCNTENSET0_EL0_UNIMPLEMENTED_ERRATA   = 0
  HAS_GIC_V3_WITHOUT_IRM_FLAG_SUPPORT_ERRATA = 0
  HAS_PSCI_MEMPROTECT_FAILING_ERRATA         = 0

  [BuildOptions]
  *_*_AARCH64_CC_FLAGS = -march=armv8-a+crypto+rcpc

  [PcdsFixedAtBuild]
  # CPU
  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gArmPlatformTokenSpaceGuid.PcdClusterCount|2

  gArmTokenSpaceGuid.PcdVFPEnabled|1

  # GIC
  gSiliciumPkgTokenSpaceGuid.PcdTimerFreqOverwrite|1920000
  gArmTokenSpaceGuid.PcdGicDistributorBase|0xe82b1000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0xe82b2000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0xe82b2000

  # Timer
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|29
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|30
  gArmTokenSpaceGuid.PcdArmArchTimerVirtIntrNum|27
  gArmTokenSpaceGuid.PcdArmArchTimerHypIntrNum|26

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Kirin 659 @ 2.36 GHz"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorPartNumber|"Hi6250"

  # SmBios CPU Extras
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMaxCpuFreq|2362
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel1InstCacheSize|0x30
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel1DataCacheSize|0x20
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosLevel2CacheSize|0x800

  # SmBios Memory Extras
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMemorySpeed|1600
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosMemoryType|30

[Components]
  EmbeddedPkg/Universal/MmcDxe/MmcDxe.inf
  HisiPkg/Drivers/SmBiosTableDxe/SmBiosTableDxe.inf
  ArmPlatformPkg/Drivers/PL061GpioDxe/PL061GpioDxe.inf
  Hi6250Pkg/Drivers/Hi6250GpioDxe/Hi6250GpioDxe.inf

[LibraryClasses]
  PlatformPrePiLib|Hi6250Pkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf
  AcpiPlatformUpdateLib|SiliciumPkg/Library/AcpiPlatformUpdateLibNull/AcpiPlatformUpdateLibNull.inf
  HwResetSystemLib|ArmPkg/Library/ArmPsciResetSystemLib/ArmPsciResetSystemLib.inf
  ResetSystemLib|ArmPkg/Library/ArmPsciResetSystemLib/ArmPsciResetSystemLib.inf
  SoCPlatformLib|Hi6250Pkg/Library/SoCPlatformLib/SoCPlatformLib.inf

!include HisiPkg/HisiPkg.dsc.inc