ENTRY(__start)

SECTIONS { 
  . = 0x80100000; 

  .ktext : {
    _ktext_start = .;
    KEEP(*(.ktext))
    _ktext_end = .;
  }

  .text : {
    *(.text)
  }

  . = ALIGN(4);
  .rodata : {
    *(.rodata)
  }

  . = ALIGN(4);
  .data : {
    *(.data)
  }

  . = ALIGN(4);
  .bss : {
    _bss_start = .;
    *(.bss)
    . = ALIGN(4);
    _bss_end = .;
  }
}
