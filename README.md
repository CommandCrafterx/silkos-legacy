# SilkOS

SilkOS is a microkernel-based hobbyist operating system based on [HelenOS](https://www.helenos.org/). Its goal is to provide a clean, stable, and modular foundation for building custom applications and services.

## Building SilkOS

### Requirements:
- A Linux Install (Recommended Distros: RHEL based, Fedora, Debian, Ubuntu)
- Basic development tools
- The following packages: `wget` `texinfo` `flex` `bison` `dialog` `python-yaml` `genisoimage` `meson` `ninja`

Example commands for installing the needed packages:

Ubuntu:
```
$ sudo apt install build-essential wget texinfo flex bison dialog python3-yaml genisoimage meson
```

Fedora/RHEL:
```
# sudo dnf group install 'Development Tools'
# sudo dnf install wget texinfo python-yaml genisoimage flex bison meson 
```

### Build Process:
First downlaod the source code:
```
$ git clone https://github.com/CommandCrafterx/silkos
```
You need to install the HelenOS toolchain to build SilkOS you can install it by running the toolchain.sh script:
```
$ cd silkos/tools
$ ./toolchain.sh amd64 #Or ia32
```
Since Meson dosen't support in-tree builds you need to create a seperate build directory and enter it after changing the directory back into the directory where you downloaded the SilkOS source code:
```
$ cd ..
& cd ..
$ mkdir -p build/amd64
$ cd build/amd64 #Replace "amd64" with your desired architecture
```
Now you can configure the SilkOS source code:
```
../../silkos/configure.sh amd64 #Replace "amd64" with your desired architecture
```
Now you can compile the Source Code:
```
ninja image_path
```
### Running the OS
Now you should have a file called image.iso in your build directory, you can run it in your favorite virtual machine software or use our QEMU wrapper:
```
./tools/ew.py
```
## Precompiled Images
If you can't compile SilkOS yourself we offer precompiled Images in the [Releases](https://github.com/CommandCrafterx/silkos/releases) Section.
## License 
Most of the Source Code is licensed under the BSD license but some third party components like the grub bootloader are GPL licensed.
