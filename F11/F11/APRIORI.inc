 APRIORI DXE {
    
  #
  # PI DXE Drivers producing Architectural Protocols (EFI Services)
  #
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF ArmPkg/Drivers/ArmGic/ArmGicDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf

  #
  # FAT filesystem + GPT/MBR partitioning
  #
  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF FatPkg/EnhancedFatDxe/Fat.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf

  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

    FILE DRIVER = f541d663-4a48-40aa-aabf-ff158ccae34c {
    SECTION DXE_DEPEX = Dxe/use/SmemDxe/SmemDxe.depex
    SECTION PE32 =  Dxe/use/SmemDxe/SmemDxe.efi
    SECTION UI = "SmemDxe"
  }

    FILE DRIVER = 8E9BD160-B184-11DF-94E2-0800200C9A66 {
   SECTION DXE_DEPEX = Dxe/use/DALSys/DALSys.depex
    SECTION PE32 = Dxe/use/DALSys/DALSys.efi
    SECTION UI = "DALSys"
  }

    FILE DRIVER = 8681CC5A-0DF6-441E-B4B8-E915C538F067 {
    SECTION DXE_DEPEX = Dxe/use/HWIODxeDriver/HWIODxeDriver.depex
    SECTION PE32 = Dxe/use/HWIODxeDriver/HWIODxeDriver.efi
    SECTION UI = "HWIODxeDriver"
  }

    FILE DRIVER = 10e193df-9966-44e7-b17c-59dd831e20fc {
    SECTION DXE_DEPEX = Dxe/use/ChipInfo/ChipInfo.depex
    SECTION PE32 = Dxe/use/ChipInfo/ChipInfo.efi
    SECTION UI = "ChipInfo"
  }

    FILE DRIVER = B105211B-BBBD-4ADD-A3B0-D1CF4A52154C {
    SECTION DXE_DEPEX = Dxe/use/PlatformInfoDxeDriver/PlatformInfoDxeDriver.depex
    SECTION PE32 = Dxe/use/PlatformInfoDxeDriver/PlatformInfoDxeDriver.efi
    SECTION UI = "PlatformInfoDxeDriver"
  }

    FILE DRIVER = 9A00771F-36D4-4DD5-8916-C48ED9B16B86 {
    SECTION DXE_DEPEX = Dxe/use/HALIOMMU/HALIOMMU.depex
    SECTION PE32 = Dxe/use/HALIOMMU/HALIOMMU.efi
    SECTION UI = "HALIOMMU"
  }

    FILE DRIVER = E43128A8-8692-42B6-8AFA-676158578D18 {
    SECTION DXE_DEPEX = Dxe/use/ULogDxe/ULogDxe.depex
    SECTION PE32 = Dxe/use/ULogDxe/ULogDxe.efi
    SECTION UI = "ULogDxe"
  }

    FILE DRIVER = ABA01FF8-2CCB-4E12-8B2E-CD3F4A742993 {
    SECTION DXE_DEPEX = Dxe/use/CmdDbDxe/CmdDbDxe.depex
    SECTION PE32 = Dxe/use/CmdDbDxe/CmdDbDxe.efi
    SECTION UI = "CmdDbDxe"
 }

    FILE DRIVER = CB29F4D1-7F37-4692-A416-93E82E219711 {
    SECTION DXE_DEPEX = Dxe/use/NpaDxe/NpaDxe.depex
    SECTION PE32 = Dxe/use/NpaDxe/NpaDxe.efi
    SECTION UI = "NpaDxe"
  }

    FILE DRIVER = CB29F4D1-7F37-4692-A416-93E82E219766 {
    SECTION DXE_DEPEX = Dxe/use/RpmhDxe/RpmhDxe.depex
        SECTION PE32 = Dxe/use/RpmhDxe/RpmhDxe.efi
        SECTION UI = "RpmhDxe"
  }

    FILE DRIVER = B43C22DB-6333-490C-872D-0A73439059FD {
    SECTION DXE_DEPEX = Dxe/use/PdcDxe/PdcDxe.depex
        SECTION PE32 = Dxe/use/PdcDxe/PdcDxe.efi
        SECTION UI = "PdcDxe"
  }

   FILE DRIVER = 4DB5DEA6-5302-4D1A-8A82-677A683B0D29 {
  SECTION DXE_DEPEX = Dxe/use/ClockDxe/ClockDxe.depex
        SECTION PE32 = Dxe/use/ClockDxe/ClockDxe.efi
        SECTION UI = "ClockDxe"
  }

    FILE DRIVER = 1B52138D-3FA3-4E50-B958-20887353F809 {
    SECTION DXE_DEPEX = Dxe/use/CPRDxe/CPRDxe.depex
        SECTION PE32 = Dxe/use/CPRDxe/CPRDxe.efi
        SECTION UI = "CPRDxe"
  }

    FILE DRIVER = AF9763A2-033B-4109-8E17-56A98D380C92 {
   SECTION DXE_DEPEX = Dxe/use/DALTLMM/DALTLMM.depex
        SECTION PE32 = Dxe/use/DALTLMM/DALTLMM.efi
        SECTION UI = "DALTLMM"
  }

   FILE DRIVER = 04DE8591-D2B3-4077-BBBE-B12070094EB6 {
  SECTION DXE_DEPEX = Dxe/use/I2C/I2C.depex
       SECTION PE32 = Dxe/use/I2C/I2C.efi
       SECTION UI = "I2C"
  }

    FILE DRIVER = 2a7b4bef-80cd-49e1-b473-374ba4d673fc {
   SECTION DXE_DEPEX = Dxe/use/SPMI/SPMI.depex
    SECTION PE32 = Dxe/use/SPMI/SPMI.efi
    SECTION UI = "SPMI"
  }

    FILE DRIVER = 5776232e-082d-4b75-9a0e-fe1d13f7a5d9 {
    SECTION DXE_DEPEX = Dxe/use/PmicDxe/PmicDxe.depex
    SECTION PE32 = Dxe/use/PmicDxe/PmicDxe.efi
    SECTION UI = "PmicDxe"
  }

  FILE DRIVER = 11faed4c-b21f-4d88-8e48-c4c28a1e50df {
    SECTION DXE_DEPEX = Dxe/use/UsbPwrCtrlDxe/UsbPwrCtrlDxe.depex
	 SECTION PE32 = Dxe/use/UsbPwrCtrlDxe/UsbPwrCtrlDxe.efi
  SECTION UI = "UsbPwrCtrlDxe"
  }

  FILE DRIVER = C9C6BB00-44FC-4C87-8AF9-F93218E17C10 {
    SECTION DXE_DEPEX = Dxe/usb/UsbcSetDrpDxe/UsbcSetDrpDxe.depex
   SECTION PE32 = Dxe/usb/UsbcSetDrpDxe/UsbcSetDrpDxe.efi
    SECTION UI = "UsbcSetDrpDxe"
  }


    FILE DRIVER = 94f8a6a7-dc34-4101-88c1-99179cceae83 {
   SECTION DXE_DEPEX = Dxe/use/UsbfnDwc3Dxe/UsbfnDwc3Dxe.depex
    SECTION PE32 = Dxe/use/UsbfnDwc3Dxe/UsbfnDwc3Dxe.efi
   SECTION UI = "UsbfnDwc3Dxe"
  }

    FILE DRIVER = cd823a4d-7dec-4531-ae5d-4134fa4127b8 {
    SECTION DXE_DEPEX = Dxe/usb/UsbConfig/UsbConfigDxe.depex
    SECTION PE32 = Dxe/usb/UsbConfig/UsbConfigDxe.efi
    SECTION UI = "UsbConfigDxe"
 }

    FILE DRIVER = 0A134F0E-075E-40B3-9C63-3B3906804663 {
    SECTION DXE_DEPEX = Dxe/usb/UsbInitDxe/UsbInitDxe.depex
    SECTION PE32 = Dxe/usb/UsbInitDxe/UsbInitDxe.efi
   SECTION UI = "UsbInitDxe"
  }

    FILE DRIVER = 3299a266-15f0-4346-8318-716336736d3e {
    SECTION DXE_DEPEX = Dxe/use/UsbDeviceDxe/UsbDeviceDxe.depex
    SECTION PE32 = Dxe/use/UsbDeviceDxe/UsbDeviceDxe.efi
    SECTION UI = "UsbDeviceDxe"
  }


FILE DRIVER = 2D2E62CF-9ECF-43B7-8219-94E7FC713DFE {
   SECTION PE32 = Dxe/usb/UsbKbDxe/UsbKbDxe.efi
    SECTION UI = "UsbKbDxe"
  }

FILE DRIVER = 5AF77F10-90DF-4E7E-8325-A17EC09D5443{
    SECTION DXE_DEPEX = Dxe/usb/UsbMsdDxe/UsbMsdDxe.depex
   SECTION PE32 = Dxe/usb/UsbMsdDxe/UsbMsdDxe.efi
    SECTION UI = "UsbMsdDxe"
  }




FILE DRIVER = BEB12BEE-F6E1-11E1-9FB8-6C626DE4AEB1 {
   # SECTION DXE_DEPEX = Dxe/usb/XhciPciEmulation.depex
    SECTION PE32 = Dxe/usb/XhciPciEmulation/XhciPciEmulation.efi
    SECTION UI = "XhciPciEmulation"
  }

FILE DRIVER =B7F50E91-A759-412C-ADE4-DCD03E7F7C28 {
    SECTION DXE_DEPEX = Dxe/usb/XhciDxe/XhciDxe.depex
    SECTION PE32 = Dxe/usb/XhciDxe/XhciDxe.efi
    SECTION UI = "XhciDxe"
  }

    FILE DRIVER = 5bd181db-0487-4f1a-ae73-820e165611b3 {
    SECTION DXE_DEPEX = Dxe/use/ButtonsDxe/ButtonsDxe.depex
    SECTION PE32 = Dxe/use/ButtonsDxe/ButtonsDxe.efi
    SECTION UI = "ButtonsDxe"
  }

FILE DRIVER = 0d35cd8e-97ea-4f9a-96af-0f0d89f76567 {
    SECTION DXE_DEPEX = Dxe/UFSDxe/UFSDxe.depex
    SECTION PE32 = Dxe/UFSDxe/UFSDxe.efi
    SECTION UI = "UFSDxe"
  }

  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

}
