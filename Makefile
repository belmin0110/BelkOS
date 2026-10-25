all:
	zig cc -target mips-freestanding -nostdlib -ffreestanding -T linker.ld **/*.s **/*.c -o os.elf
	qemu-system-mips -M malta -cpu 24Kf -kernel os.elf -nographic

compile:
	zig cc -target mips-freestanding -nostdlib -ffreestanding -T linker.ld **/*.s **/*.c -o os.elf

run:
	qemu-system-mips -M malta -cpu 24Kf -kernel os.elf -nographic

