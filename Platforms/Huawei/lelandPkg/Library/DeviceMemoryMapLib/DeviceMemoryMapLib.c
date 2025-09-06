#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceType, ResourceAttribute, MemoryType, ArmAttribute

  // DDR Regions
  //"Kernel",             0x00480000, 0x02ABFFFF, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},
  {"DXE Heap",           0x0E001000, 0x04000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
  {"UEFI FD",            0x12001000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI Stack",         0x12201000, 0x00020000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"CPU Vectors",        0x12221000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},


  {"SecureOS",           0x36200000, 0x01E00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Display Reserved",   0x5D8E5120, 0x03000000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH},
  {"Log Buffer",         0xBE100000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},

  // Register Regions
  {"Smmu",               0x34A78000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PinCtrl0_Range1",    0xE896C000, 0x00000227, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PinCtrl0_Range2",    0xE896C800, 0x00000223, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB",                0xFF100000, 0x00040000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PinCtrl1_Range1",    0xFFF11000, 0x000000AB, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PinCtrl1_Range2",    0xFFF11800, 0x000000BB, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"Timer",              0xFFF14000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PMU",                0xFFF34000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"CRG",                0xFFF35000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},


  // Terminator for MMU
  {"Terminator", 0, 0, 0, 0, 0, 0, 0}
};

ARM_MEMORY_REGION_DESCRIPTOR_EX*
GetDeviceMemoryMap ()
{
  return gDeviceMemoryDescriptorEx;
}
