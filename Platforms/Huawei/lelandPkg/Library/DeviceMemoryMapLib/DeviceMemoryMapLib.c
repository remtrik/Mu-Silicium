#include <Library/DeviceMemoryMapLib.h>

STATIC
ARM_MEMORY_REGION_DESCRIPTOR_EX
gDeviceMemoryDescriptorEx[] = {
  // Name, Address, Length, HobOption, ResourceType, ResourceAttribute, MemoryType, ArmAttribute

  // DDR Regions
  {"RAM Partition",      0x00400000, 0x00080000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Kernel",             0x00480000, 0x02AC0000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_BACK_XN},

  // probably mem hole from 2f40000 till 0e001000

  {"DXE Heap",           0x0E001000, 0x04000000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
  {"UEFI FD",            0x12001000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"UEFI Stack",         0x12201000, 0x00020000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN},
  {"CPU Vectors",        0x12221000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
  {"RAM Partition",      0x12222000, 0x1DDDE000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"TUI",                0x30000000, 0x01000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Graphic",            0x31000000, 0x01a40000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
  {"MNTN",               0x34000000, 0x00800000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
  {"RAM Partition",      0x34800000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"LPMX",               0x34900000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
  {"FastbootMem",        0x34A00000, 0x00078000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"SMMU",               0x34A78000, 0x00008000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"SensorHub SHM",      0x34A80000, 0x00080000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"ISP",                0x34B00000, 0x00030000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"HIFI",               0x34F00000, 0x00F00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"BL31",               0x35E00000, 0x000C0000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"SensorHub",          0x36000000, 0x00200000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"SecureOS",           0x36200000, 0x01E00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Modem",              0x38000000, 0x06C00000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Modem SHM",          0x3EC00000, 0x00500000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Modem SoC",          0x3F100000, 0x01000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"RAM Partition",      0x40100000, 0x00400000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Modem Log",          0x40500000, 0x03200000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"XMD",                0x43700000, 0x18900000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"CMA_ALIGN",          0x5C000000, 0x01000000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Reserved",           0x5D000000, 0x008E5000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE}, 
  {"Display Reserved",   0x5D8E5000, 0x03000000, AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH},
  {"RAM Partition",      0x608E6000, 0x5D81A000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},
  {"Log Buffer",         0xBE100000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN},
  {"RAM Partition",      0xBE200000, 0x01E00000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN},

  // Register Regions
  {"PinCtrl 0",          0xE896C000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"USB",                0xFF100000, 0x00040000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
  {"PinCtrl 1",          0xFFF11000, 0x00001000, AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE},
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
