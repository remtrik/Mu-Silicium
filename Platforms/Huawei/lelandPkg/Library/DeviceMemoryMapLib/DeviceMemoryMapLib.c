#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceType, ResourceAttribute, MemoryType, ArmAttribute

  // DDR Regions
  {"SecOS",              0x36200000, 0x01E00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Display Reserved",   0x5D000000, 0x03000000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH},
  {"Log Buffer",         0xBE100000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},


  // Register Regions
  {"Smmu",               0x34A78000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"Timer",              0xFFF14000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},


  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}
