
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 80

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, MaxMem } DeviceMemoryAddHob;

typedef struct {
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
  DeviceMemoryAddHob           HobOption;
  EFI_MEMORY_TYPE              MemoryType;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Address,	  Length,     ResourceType, Resource Attribute, ARM MMU
       Attribute,  HobOption, EFI Memory Type */
    /*  DDR  */
/*0x80000000, 0x05700000, "Kernel",            AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN
0x85CF0000, 0x00010000, "Boot Info",         AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x85F20000, 0x00020000, "AOP CMD DB",        AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN
0x86000000, 0x00200000, "SMEM",              AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN
0x8B700000, 0x00100000, "PIL Reserved",      AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN
0x8B800000, 0x0E600000, "PIL Reserved II",   AddMem, MEM_RES, WRITE_COMBINEABLE, Reserv, UNCACHED_UNBUFFERED_XN
0x99E00000, 0x01C00000, "DXE Heap",          AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK_XN
0x9BA00000, 0x00600000, "Sched Heap",        AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x9C000000, 0x02400000, "Display Reserved",  AddMem, MEM_RES, SYS_MEM_CAP, Reserv, WRITE_THROUGH_XN
0x9E400000, 0x00F00000, "DBI Dump",          NoHob,  MMAP_IO, INITIALIZED, Conv,   UNCACHED_UNBUFFERED_XN
0x9F800000, 0x00200000, "FV Region",         AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x9FA00000, 0x00200000, "ABOOT FV",          AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN
0x9FC00000, 0x00300000, "UEFI FD",           AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK
0x9FF00000, 0x0008C000, "SEC Heap",          AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x9FF8C000, 0x00001000, "CPU Vectors",       AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK
0x9FF8D000, 0x00003000, "MMU PageTables",    AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x9FF90000, 0x00040000, "UEFI Stack",        AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK_XN
0x9FFF7000, 0x00008000, "Log Buffer",        AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN
0x9FFFF000, 0x00001000, "Info Blk",          AddMem, SYS_MEM, SYS_MEM_CAP, RtData, WRITE_BACK_XN
0xA0000000, 0x04C00000, "MLVM_APSS",         AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN
0xA8800000, 0x07800000, "MLVM_1",            AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN
0xB0400000, 0x09000000, "MLVM",              AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, WRITE_BACK_XN

[RegisterMap]
#--------------------- Other -----
0x0C300000, 0x00100000, "AOP_SS_MSG_RAM",     NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE
0x14680000, 0x00040000, "IMEM Base",          NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE
#--------------------- Register --
#Keep sorted by base address
0x00100000, 0x00200000, "GCC CLK CTL",        AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x00630000, 0x00004000, "MMCX_CPR3",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x00780000, 0x00007000, "SECURITY CONTROL",   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x00790000, 0x00010000, "PRNG_CFG_PRNG",      AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x00800000, 0x000D0000, "QUPV3_0_GSI",        AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x00A00000, 0x000D0000, "QUPV3_1_GSI",        AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x00C00000, 0x000D0000, "QUPV3_2_GSI",        AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x01D80000, 0x00020000, "UFS UFS REGS",       AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x01DC0000, 0x00040000, "CRYPTO0 CRYPTO",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x01FC0000, 0x00030000, "TCSR_TCSR_REGS",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x02C7D000, 0x00002000, "GPU_GMU_CX_BLK",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x02C90000, 0x0000A000, "GPU_CC",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x02C9A000, 0x00004000, "GPU_CPR",            AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x03100000, 0x00300000, "TLMM_WEST",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x03500000, 0x00300000, "TLMM_EAST",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x03900000, 0x00300000, "TLMM_NORTH",         AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x03D00000, 0x00300000, "TLMM_SOUTH",         AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x05A00000, 0x000D0000, "QUPV3_SSC_GSI",      AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x08800000, 0x00200000, "PERIPH_SS",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x090B0000, 0x00001000, "MCCC_MCCC_MSTR",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x09910000, 0x00010000, "NPU_CC",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0A600000, 0x0011B000, "USB30_PRIM",         AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0A720000, 0x00010000, "USB_RUMI",           AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0A800000, 0x0011B000, "USB30_SEC",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0AB00000, 0x00020000, "VIDEO_CC",           AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0AC00000, 0x00100000, "TITAN_SS_TITAN",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0AD00000, 0x00020000, "TITAN_CAM_CC",       AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0AE00000, 0x00134000, "MDSS",               AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0AF00000, 0x00020000, "DISP_CC",            AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0B290000, 0x00020000, "PDC_DISPLAY",        AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0B490000, 0x00020000, "PDC_DISP_SEQ",       AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0BA00000, 0x00200000, "RPMH_BCM_BCM_TOP",   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C200000, 0x00010000, "RPMH_CPRF_CPRF",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C221000, 0x00001000, "SLP_CNTR",           AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C222000, 0x00001000, "TSENS0",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C223000, 0x00001000, "TSENS1",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C263000, 0x00001000, "TSENS0_TM",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C264000, 0x00001000, "PSHOLD",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C265000, 0x00001000, "TSENS1_TM",          AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x0C400000, 0x02800000, "PMIC ARB SPMI",      AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x15000000, 0x000D0000, "SMMU",               AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x17A00000, 0x00010000, "APSS_GIC500_GICD",   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x17A60000, 0x00100000, "APSS_GIC500_GICR",   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x17C00000, 0x00110000, "QTIMER",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x17C10000, 0x00001000, "APSS_WDT_TMR1",      AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18200000, 0x00030000, "APSS_RSC_RSCCR",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18280000, 0x00001000, "SILVER_CLK_CTL",     AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18290000, 0x00001000, "SILVER_ACD",         AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18282000, 0x00001000, "GOLD_CLK_CTL",       AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18286000, 0x00001000, "GOLDPLUS_CLK_CTL",   AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18292000, 0x00001000, "GOLD_ACD",           AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18296000, 0x00001000, "GOLDPLUS_ACD",       AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18284000, 0x00001000, "L3_CLK_CTL",         AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18294000, 0x00001000, "L3_ACD",             AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
0x18300000, 0x000B0000, "APSS_ACTPM_WRAP",    AddDev, MMAP_IO, UNCACHEABLE, MmIO,   NS_DEVICE
*/

//kernel
    {0x80000000, 0x05700000,EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesCode},
//boot info
{0x85CF0000, 0x00010000,EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
     
    // "AOP CMD DB"
    {0x85F20000, 0x00020000, EFI_RESOURCE_MEMORY_RESERVED,
    EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE , ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  SMEM  */
    {0x86000000, 0x00200000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  PIL Reserved  */
    {0x8B700000, 0x00100000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  PIL Reserved II  */
    {0x8B800000, 0x0E600000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  DXE Heap  */    
    {0x99E00000, 0x01C00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},
     
     //"Sched Heap"
     {0x9BA00000, 0x00600000,EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
     
     
    /*  Display Reserved  */
    {0x9C000000, 0x02400000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH,
     AddMem, EfiReservedMemoryType},
     
    //"DBI Dump"
     {0x9E400000, 0x00F00000,EFI_RESOURCE_MEMORY_MAPPED_IO,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     NoHob, EfiConventionalMemory},
    
    /*  FV Region  */
    {0x9F800000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  ABOOT FV  */
    {0x9FA00000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  UEFI FD  */    
    {0x9FC00000, 0x00300000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  SEC Heap  */    
    {0x9FF00000, 0x0008C000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},    
    /*  CPU Vectors  */    
    {0x9FF8C000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  MMU PageTables  */ 
    {0x9FF8D000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  UEFI Stack  */ 
    {0x9FF90000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},

    /*  Log Buffer  */ 
    {0x9FFF7000, 0x00008000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  Info Blk  */ 
    {0x9FFFF000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
 
   //  MLVM_APSS  
    {0xA0000000,0x04C00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
       //  MLVM_1
    {0xA8800000, 0x07800000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
  //   MLVM
     {0xB0400000, 0x09000000,EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},

        /*  HLOS (Upto MLVM)  */
    {0xC0000000, 0xC7C00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},

    /* HLOS (After MLVM)  */
    {0xD9500000, 0xC7C00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},

   

    /* Other memory regions */
   /* AOP_SS_MSG_RAM */
    {0x0C300000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     NoHob, EfiConventionalMemory},
   /* IMEM Base */
    {0x14680000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     NoHob, EfiConventionalMemory},
	 
    /*  Registers  */ 
	/* GCC CLK CTL   */ 
    {0x00100000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* MMCX_CPR3   */ 
    {0x00630000, 0x00004000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

	/* SECURITY CONTROL */ 
    {0x00780000, 0x00007000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/*  PRNG_CFG_PRNG  */ 
    {0x00790000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* QUPV3_0_GSI   */ 
    {0x00800000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* QUPV3_1_GSI   */ 
    {0x00A00000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* QUPV3_2_GSI   */ 
    {0x00C00000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* UFS UFS REGS   */ 
    {0x01D80000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* CRYPTO0 CRYPTO   */ 
    {0x01DC0000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TCSR_TCSR_REGS  */ 
    {0x01FC0000, 0x00030000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* GPU_GMU_CX_BLK   */ 
    {0x02C7D000, 0x00002000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* GPU_CC   */ 
    {0x02C90000, 0x0000A000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* GPU_CPR   */ 
    {0x02C9A000, 0x00004000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TLMM_WEST   */ 
    {0x03100000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TLMM_EAST   */ 
    {0x03500000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TLMM_NORTH   */ 
    {0x03900000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TLMM_SOUTH  */ 
    {0x03D00000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* QUPV3_SSC_GSI   */ 
    {0x05A00000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* PERIPH_SS   */ 
    {0x08800000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* MCCC_MCCC_MSTR   */ 
    {0x090B0000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* NPU_CC   */ 
    {0x09910000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* USB30_PRIM   */ 
    {0x0A600000, 0x0011B000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* USB_RUMI   */ 
    {0x0A720000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* USB30_SEC  */ 
    {0x0A800000, 0x0011B000,EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* VIDEO_CC   */ 
    {0x0AB00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TITAN_SS_TITAN   */ 
    {0x0AC00000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TITAN_CAM_CC   */ 
    {0x0AD00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* MDSS   */ 
    {0x0AE00000, 0x00134000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* DISP_CC   */ 
    {0x0AF00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* PDC_DISPLAY   */ 
    {0x0B290000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* PDC_DISP_SEQ   */ 
    {0x0B490000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* RPMH_BCM_BCM_TOP   */ 
    {0x0BA00000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

	/* RPMH_CPRF_CPRF*/ 
    {0x0C200000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

	/* SLP_CNTR   */ 
    {0x0C221000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TSENS0  */ 
    {0x0C222000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TSENS1   */ 
    {0x0C223000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TSENS0_TM   */ 
    {0x0C263000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* PSHOLD   */ 
    {0x0C264000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* TSENS1_TM   */ 
    {0x0C265000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* PMIC ARB SPMI   */ 
    {0x0C400000, 0x02800000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* SMMU   */ 
    {0x15000000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* APSS_GIC500_GICD   */ 
    {0x17A00000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* APSS_GIC500_GICR   */ 
    {0x17A60000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* QTIMER  */ 
    {0x17C00000, 0x00110000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* APSS_WDT_TMR1  */ 
    {0x17C10000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* APSS_RSC_RSCCR  */ 
    {0x18200000, 0x00030000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* SILVER_CLK_CTL  */ 
    {0x18280000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* SILVER_ACD  */ 
    {0x18290000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* GOLD_CLK_CTL  */ 
    {0x18282000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* GOLDPLUS_CLK_CTL  */ 
    {0x18286000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	/* GOLD_ACD   */ 
    {0x18292000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
 	/* GOLDPLUS_ACD   */ 
    {0x18296000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* L3_CLK_CTL  */ 
    {0x18284000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* L3_ACD  */ 
    {0x18294000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
	 	/* APSS_ACTPM_WRAP   */ 
    {0x18300000, 0x000B0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},


    /* Terminator for MMU*/
    {0},

    /* Terminator for LibMem */
    { 0xFFFFFFFF, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, 
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, 
     AddDev, EfiMemoryMappedIO}
};

