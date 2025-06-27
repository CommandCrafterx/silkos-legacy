#!/usr/bin/env bash
ISO="$1"
IMG="helenos_disk.qcow2"

if [[ -z "$ISO" ]]; then
  echo "Usage: $0 <image.iso>"
  exit 1
fi

# Create a 512MB qcow2 disk image
echo "Creating disk image: $IMG"
qemu-img create -f qcow2 "$IMG" 512M

# Launch QEMU with Live-CD and IDE disk
echo "[$(date)] Starting HelenOS Live-CD installer..."
qemu-system-x86_64 \
  -enable-kvm \
  -m 512M \
  -drive file="$IMG",format=qcow2,if=ide \
  -cdrom "$ISO" \
  -boot d

echo
echo "   - Open the Qemu window"
echo "   – log in if needed, then run 'sysinst'"
echo "   – Wait for the installer to finish"
echo "   – Then close QEMU"

read -rp "Press ENTER once installation finishes to continue..."

# Boot from the Harddisk
echo
echo "Booting installed HelenOS from disk..."
qemu-system-x86_64 \
  -enable-kvm \
  -m 512M \
  -drive file="$IMG",format=qcow2,if=ide \
  -boot c
