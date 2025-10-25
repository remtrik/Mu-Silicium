#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>

#include <Protocol/EFIStorageWriteProtect.h>

EFI_STATUS
EFIAPI
EnableWriteProtect (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable)
{
  EFI_STATUS              Status                 = EFI_SUCCESS;
  EFI_STORAGE_WRITEPROTECT_PROTOCOL *mStorageWpProtocol    = NULL;

  // Locate Write Protect Protocol
  Status = gBS->LocateProtocol (&gEfiStorageWriteProtectProtocolGuid, NULL, (VOID *)&mStorageWpProtocol);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "Failed to Locate Storage Write Protect Protocol! Status = %r\n", Status));
    return Status;
  }

  Status = mStorageWpProtocol->SetLUWriteProtect (mStorageWpProtocol);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "Failed to Enable Storage Write Protection! Status = %r\n", Status));
    return Status;
  }

  return EFI_SUCCESS;
}
