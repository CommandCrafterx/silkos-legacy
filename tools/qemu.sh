#!/usr/bin/env bash
#
# Copyright (c) 2025 CommandCrafterx
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# - Redistributions of source code must retain the above copyright
#   notice, this list of conditions and the following disclaimer.
# - Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
# - The name of the author may not be used to endorse or promote products
#   derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
ISO="$1"
IMG="silkos_disk.qcow2"

if [[ -z "$ISO" ]]; then
  echo "Usage: $0 <image.iso>"
  exit 1
fi

# Create a 512MB qcow2 disk image
echo "Creating disk image: $IMG"
qemu-img create -f qcow2 "$IMG" 512M

# Launch QEMU with Live-CD and IDE disk
echo "Starting SilkOS Live-CD installer..."
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
echo "Booting installed SilkOS from disk..."
qemu-system-x86_64 \
  -enable-kvm \
  -m 512M \
  -drive file="$IMG",format=qcow2,if=ide \
  -boot c
