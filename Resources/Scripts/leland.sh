#!/bin/bash

# Build an Android kernel that is actually UEFI disguised as the Kernel
cat ./BootShim/BootShim.bin "./Build/lelandPkg/${TARGET_BUILD_MODE}_CLANGPDB/FV/LELAND_UEFI.fd" > "./Build/lelandPkg/${TARGET_BUILD_MODE}_CLANGPDB/FV/LELAND_UEFI.fd-bootshim"||exit 1
gzip -c < "./Build/lelandPkg/${TARGET_BUILD_MODE}_CLANGPDB/FV/LELAND_UEFI.fd-bootshim" > "./Build/lelandPkg/${TARGET_BUILD_MODE}_CLANGPDB/FV/LELAND_UEFI.fd-bootshim.gz"||exit 1
cat "./Build/lelandPkg/${TARGET_BUILD_MODE}_CLANGPDB/FV/LELAND_UEFI.fd-bootshim.gz" > ./Resources/bootpayload.bin||exit 1

# Create bootable Android boot.img
./Resources/mkbootimg \
  --kernel ./Resources/bootpayload.bin \
  --ramdisk ./Resources/ramdisk \
  --board "" \
  --base 0x00478000 \
  --pagesize 2048 \
  --kernel_offset 0x00008000 \
  --ramdisk_offset 0x0ff88000 \
  --second_offset 0x00e88000 \
  --tags_offset 0x07988000 \
  --dtb_offset  0\
  --os_version 9.0.0 \
  --os_patch_level 2020-10 \
  --header_version 0 \
  -o Mu-leland.img \
  ||_error "\nFailed to create Android Boot Image!\n"
