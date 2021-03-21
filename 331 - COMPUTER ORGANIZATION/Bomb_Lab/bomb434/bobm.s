
bomb:     file format elf64-x86-64


Disassembly of section .init:

0000000000400b38 <_init>:
  400b38:	48 83 ec 08          	sub    $0x8,%rsp
  400b3c:	48 8b 05 b5 34 20 00 	mov    0x2034b5(%rip),%rax        # 603ff8 <__gmon_start__>
  400b43:	48 85 c0             	test   %rax,%rax
  400b46:	74 05                	je     400b4d <_init+0x15>
  400b48:	e8 f3 01 00 00       	callq  400d40 <__gmon_start__@plt>
  400b4d:	48 83 c4 08          	add    $0x8,%rsp
  400b51:	c3                   	retq   

Disassembly of section .plt:

0000000000400b60 <.plt>:
  400b60:	ff 35 a2 34 20 00    	pushq  0x2034a2(%rip)        # 604008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400b66:	ff 25 a4 34 20 00    	jmpq   *0x2034a4(%rip)        # 604010 <_GLOBAL_OFFSET_TABLE_+0x10>
  400b6c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400b70 <__strcat_chk@plt>:
  400b70:	ff 25 a2 34 20 00    	jmpq   *0x2034a2(%rip)        # 604018 <__strcat_chk@GLIBC_2.3.4>
  400b76:	68 00 00 00 00       	pushq  $0x0
  400b7b:	e9 e0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400b80 <getenv@plt>:
  400b80:	ff 25 9a 34 20 00    	jmpq   *0x20349a(%rip)        # 604020 <getenv@GLIBC_2.2.5>
  400b86:	68 01 00 00 00       	pushq  $0x1
  400b8b:	e9 d0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400b90 <strcasecmp@plt>:
  400b90:	ff 25 92 34 20 00    	jmpq   *0x203492(%rip)        # 604028 <strcasecmp@GLIBC_2.2.5>
  400b96:	68 02 00 00 00       	pushq  $0x2
  400b9b:	e9 c0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400ba0 <__errno_location@plt>:
  400ba0:	ff 25 8a 34 20 00    	jmpq   *0x20348a(%rip)        # 604030 <__errno_location@GLIBC_2.2.5>
  400ba6:	68 03 00 00 00       	pushq  $0x3
  400bab:	e9 b0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bb0 <strcpy@plt>:
  400bb0:	ff 25 82 34 20 00    	jmpq   *0x203482(%rip)        # 604038 <strcpy@GLIBC_2.2.5>
  400bb6:	68 04 00 00 00       	pushq  $0x4
  400bbb:	e9 a0 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bc0 <puts@plt>:
  400bc0:	ff 25 7a 34 20 00    	jmpq   *0x20347a(%rip)        # 604040 <puts@GLIBC_2.2.5>
  400bc6:	68 05 00 00 00       	pushq  $0x5
  400bcb:	e9 90 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bd0 <write@plt>:
  400bd0:	ff 25 72 34 20 00    	jmpq   *0x203472(%rip)        # 604048 <write@GLIBC_2.2.5>
  400bd6:	68 06 00 00 00       	pushq  $0x6
  400bdb:	e9 80 ff ff ff       	jmpq   400b60 <.plt>

0000000000400be0 <__stack_chk_fail@plt>:
  400be0:	ff 25 6a 34 20 00    	jmpq   *0x20346a(%rip)        # 604050 <__stack_chk_fail@GLIBC_2.4>
  400be6:	68 07 00 00 00       	pushq  $0x7
  400beb:	e9 70 ff ff ff       	jmpq   400b60 <.plt>

0000000000400bf0 <alarm@plt>:
  400bf0:	ff 25 62 34 20 00    	jmpq   *0x203462(%rip)        # 604058 <alarm@GLIBC_2.2.5>
  400bf6:	68 08 00 00 00       	pushq  $0x8
  400bfb:	e9 60 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c00 <close@plt>:
  400c00:	ff 25 5a 34 20 00    	jmpq   *0x20345a(%rip)        # 604060 <close@GLIBC_2.2.5>
  400c06:	68 09 00 00 00       	pushq  $0x9
  400c0b:	e9 50 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c10 <read@plt>:
  400c10:	ff 25 52 34 20 00    	jmpq   *0x203452(%rip)        # 604068 <read@GLIBC_2.2.5>
  400c16:	68 0a 00 00 00       	pushq  $0xa
  400c1b:	e9 40 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c20 <__libc_start_main@plt>:
  400c20:	ff 25 4a 34 20 00    	jmpq   *0x20344a(%rip)        # 604070 <__libc_start_main@GLIBC_2.2.5>
  400c26:	68 0b 00 00 00       	pushq  $0xb
  400c2b:	e9 30 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c30 <fgets@plt>:
  400c30:	ff 25 42 34 20 00    	jmpq   *0x203442(%rip)        # 604078 <fgets@GLIBC_2.2.5>
  400c36:	68 0c 00 00 00       	pushq  $0xc
  400c3b:	e9 20 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c40 <signal@plt>:
  400c40:	ff 25 3a 34 20 00    	jmpq   *0x20343a(%rip)        # 604080 <signal@GLIBC_2.2.5>
  400c46:	68 0d 00 00 00       	pushq  $0xd
  400c4b:	e9 10 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c50 <gethostbyname@plt>:
  400c50:	ff 25 32 34 20 00    	jmpq   *0x203432(%rip)        # 604088 <gethostbyname@GLIBC_2.2.5>
  400c56:	68 0e 00 00 00       	pushq  $0xe
  400c5b:	e9 00 ff ff ff       	jmpq   400b60 <.plt>

0000000000400c60 <__memmove_chk@plt>:
  400c60:	ff 25 2a 34 20 00    	jmpq   *0x20342a(%rip)        # 604090 <__memmove_chk@GLIBC_2.3.4>
  400c66:	68 0f 00 00 00       	pushq  $0xf
  400c6b:	e9 f0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400c70 <strtol@plt>:
  400c70:	ff 25 22 34 20 00    	jmpq   *0x203422(%rip)        # 604098 <strtol@GLIBC_2.2.5>
  400c76:	68 10 00 00 00       	pushq  $0x10
  400c7b:	e9 e0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400c80 <fflush@plt>:
  400c80:	ff 25 1a 34 20 00    	jmpq   *0x20341a(%rip)        # 6040a0 <fflush@GLIBC_2.2.5>
  400c86:	68 11 00 00 00       	pushq  $0x11
  400c8b:	e9 d0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400c90 <__isoc99_sscanf@plt>:
  400c90:	ff 25 12 34 20 00    	jmpq   *0x203412(%rip)        # 6040a8 <__isoc99_sscanf@GLIBC_2.7>
  400c96:	68 12 00 00 00       	pushq  $0x12
  400c9b:	e9 c0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400ca0 <__printf_chk@plt>:
  400ca0:	ff 25 0a 34 20 00    	jmpq   *0x20340a(%rip)        # 6040b0 <__printf_chk@GLIBC_2.3.4>
  400ca6:	68 13 00 00 00       	pushq  $0x13
  400cab:	e9 b0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cb0 <fopen@plt>:
  400cb0:	ff 25 02 34 20 00    	jmpq   *0x203402(%rip)        # 6040b8 <fopen@GLIBC_2.2.5>
  400cb6:	68 14 00 00 00       	pushq  $0x14
  400cbb:	e9 a0 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cc0 <gethostname@plt>:
  400cc0:	ff 25 fa 33 20 00    	jmpq   *0x2033fa(%rip)        # 6040c0 <gethostname@GLIBC_2.2.5>
  400cc6:	68 15 00 00 00       	pushq  $0x15
  400ccb:	e9 90 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cd0 <exit@plt>:
  400cd0:	ff 25 f2 33 20 00    	jmpq   *0x2033f2(%rip)        # 6040c8 <exit@GLIBC_2.2.5>
  400cd6:	68 16 00 00 00       	pushq  $0x16
  400cdb:	e9 80 fe ff ff       	jmpq   400b60 <.plt>

0000000000400ce0 <connect@plt>:
  400ce0:	ff 25 ea 33 20 00    	jmpq   *0x2033ea(%rip)        # 6040d0 <connect@GLIBC_2.2.5>
  400ce6:	68 17 00 00 00       	pushq  $0x17
  400ceb:	e9 70 fe ff ff       	jmpq   400b60 <.plt>

0000000000400cf0 <__fprintf_chk@plt>:
  400cf0:	ff 25 e2 33 20 00    	jmpq   *0x2033e2(%rip)        # 6040d8 <__fprintf_chk@GLIBC_2.3.4>
  400cf6:	68 18 00 00 00       	pushq  $0x18
  400cfb:	e9 60 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d00 <sleep@plt>:
  400d00:	ff 25 da 33 20 00    	jmpq   *0x2033da(%rip)        # 6040e0 <sleep@GLIBC_2.2.5>
  400d06:	68 19 00 00 00       	pushq  $0x19
  400d0b:	e9 50 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d10 <__ctype_b_loc@plt>:
  400d10:	ff 25 d2 33 20 00    	jmpq   *0x2033d2(%rip)        # 6040e8 <__ctype_b_loc@GLIBC_2.3>
  400d16:	68 1a 00 00 00       	pushq  $0x1a
  400d1b:	e9 40 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d20 <__sprintf_chk@plt>:
  400d20:	ff 25 ca 33 20 00    	jmpq   *0x2033ca(%rip)        # 6040f0 <__sprintf_chk@GLIBC_2.3.4>
  400d26:	68 1b 00 00 00       	pushq  $0x1b
  400d2b:	e9 30 fe ff ff       	jmpq   400b60 <.plt>

0000000000400d30 <socket@plt>:
  400d30:	ff 25 c2 33 20 00    	jmpq   *0x2033c2(%rip)        # 6040f8 <socket@GLIBC_2.2.5>
  400d36:	68 1c 00 00 00       	pushq  $0x1c
  400d3b:	e9 20 fe ff ff       	jmpq   400b60 <.plt>

Disassembly of section .plt.got:

0000000000400d40 <__gmon_start__@plt>:
  400d40:	ff 25 b2 32 20 00    	jmpq   *0x2032b2(%rip)        # 603ff8 <__gmon_start__>
  400d46:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400d50 <_start>:
  400d50:	31 ed                	xor    %ebp,%ebp
  400d52:	49 89 d1             	mov    %rdx,%r9
  400d55:	5e                   	pop    %rsi
  400d56:	48 89 e2             	mov    %rsp,%rdx
  400d59:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  400d5d:	50                   	push   %rax
  400d5e:	54                   	push   %rsp
  400d5f:	49 c7 c0 50 26 40 00 	mov    $0x402650,%r8
  400d66:	48 c7 c1 e0 25 40 00 	mov    $0x4025e0,%rcx
  400d6d:	48 c7 c7 46 0e 40 00 	mov    $0x400e46,%rdi
  400d74:	e8 a7 fe ff ff       	callq  400c20 <__libc_start_main@plt>
  400d79:	f4                   	hlt    
  400d7a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400d80 <deregister_tm_clones>:
  400d80:	b8 87 47 60 00       	mov    $0x604787,%eax
  400d85:	55                   	push   %rbp
  400d86:	48 2d 80 47 60 00    	sub    $0x604780,%rax
  400d8c:	48 83 f8 0e          	cmp    $0xe,%rax
  400d90:	48 89 e5             	mov    %rsp,%rbp
  400d93:	76 1b                	jbe    400db0 <deregister_tm_clones+0x30>
  400d95:	b8 00 00 00 00       	mov    $0x0,%eax
  400d9a:	48 85 c0             	test   %rax,%rax
  400d9d:	74 11                	je     400db0 <deregister_tm_clones+0x30>
  400d9f:	5d                   	pop    %rbp
  400da0:	bf 80 47 60 00       	mov    $0x604780,%edi
  400da5:	ff e0                	jmpq   *%rax
  400da7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400dae:	00 00 
  400db0:	5d                   	pop    %rbp
  400db1:	c3                   	retq   
  400db2:	0f 1f 40 00          	nopl   0x0(%rax)
  400db6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400dbd:	00 00 00 

0000000000400dc0 <register_tm_clones>:
  400dc0:	be 80 47 60 00       	mov    $0x604780,%esi
  400dc5:	55                   	push   %rbp
  400dc6:	48 81 ee 80 47 60 00 	sub    $0x604780,%rsi
  400dcd:	48 c1 fe 03          	sar    $0x3,%rsi
  400dd1:	48 89 e5             	mov    %rsp,%rbp
  400dd4:	48 89 f0             	mov    %rsi,%rax
  400dd7:	48 c1 e8 3f          	shr    $0x3f,%rax
  400ddb:	48 01 c6             	add    %rax,%rsi
  400dde:	48 d1 fe             	sar    %rsi
  400de1:	74 15                	je     400df8 <register_tm_clones+0x38>
  400de3:	b8 00 00 00 00       	mov    $0x0,%eax
  400de8:	48 85 c0             	test   %rax,%rax
  400deb:	74 0b                	je     400df8 <register_tm_clones+0x38>
  400ded:	5d                   	pop    %rbp
  400dee:	bf 80 47 60 00       	mov    $0x604780,%edi
  400df3:	ff e0                	jmpq   *%rax
  400df5:	0f 1f 00             	nopl   (%rax)
  400df8:	5d                   	pop    %rbp
  400df9:	c3                   	retq   
  400dfa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400e00 <__do_global_dtors_aux>:
  400e00:	80 3d a1 39 20 00 00 	cmpb   $0x0,0x2039a1(%rip)        # 6047a8 <completed.7594>
  400e07:	75 11                	jne    400e1a <__do_global_dtors_aux+0x1a>
  400e09:	55                   	push   %rbp
  400e0a:	48 89 e5             	mov    %rsp,%rbp
  400e0d:	e8 6e ff ff ff       	callq  400d80 <deregister_tm_clones>
  400e12:	5d                   	pop    %rbp
  400e13:	c6 05 8e 39 20 00 01 	movb   $0x1,0x20398e(%rip)        # 6047a8 <completed.7594>
  400e1a:	f3 c3                	repz retq 
  400e1c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400e20 <frame_dummy>:
  400e20:	bf 20 3e 60 00       	mov    $0x603e20,%edi
  400e25:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400e29:	75 05                	jne    400e30 <frame_dummy+0x10>
  400e2b:	eb 93                	jmp    400dc0 <register_tm_clones>
  400e2d:	0f 1f 00             	nopl   (%rax)
  400e30:	b8 00 00 00 00       	mov    $0x0,%eax
  400e35:	48 85 c0             	test   %rax,%rax
  400e38:	74 f1                	je     400e2b <frame_dummy+0xb>
  400e3a:	55                   	push   %rbp
  400e3b:	48 89 e5             	mov    %rsp,%rbp
  400e3e:	ff d0                	callq  *%rax
  400e40:	5d                   	pop    %rbp
  400e41:	e9 7a ff ff ff       	jmpq   400dc0 <register_tm_clones>

0000000000400e46 <main>:
  400e46:	53                   	push   %rbx
  400e47:	83 ff 01             	cmp    $0x1,%edi
  400e4a:	75 10                	jne    400e5c <main+0x16>
  400e4c:	48 8b 05 3d 39 20 00 	mov    0x20393d(%rip),%rax        # 604790 <stdin@@GLIBC_2.2.5>
  400e53:	48 89 05 56 39 20 00 	mov    %rax,0x203956(%rip)        # 6047b0 <infile>
  400e5a:	eb 63                	jmp    400ebf <main+0x79>
  400e5c:	48 89 f3             	mov    %rsi,%rbx
  400e5f:	83 ff 02             	cmp    $0x2,%edi
  400e62:	75 3a                	jne    400e9e <main+0x58>
  400e64:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
  400e68:	be de 2e 40 00       	mov    $0x402ede,%esi
  400e6d:	e8 3e fe ff ff       	callq  400cb0 <fopen@plt>
  400e72:	48 89 05 37 39 20 00 	mov    %rax,0x203937(%rip)        # 6047b0 <infile>
  400e79:	48 85 c0             	test   %rax,%rax
  400e7c:	75 41                	jne    400ebf <main+0x79>
  400e7e:	48 8b 4b 08          	mov    0x8(%rbx),%rcx
  400e82:	48 8b 13             	mov    (%rbx),%rdx
  400e85:	be 64 26 40 00       	mov    $0x402664,%esi
  400e8a:	bf 01 00 00 00       	mov    $0x1,%edi
  400e8f:	e8 0c fe ff ff       	callq  400ca0 <__printf_chk@plt>
  400e94:	bf 08 00 00 00       	mov    $0x8,%edi
  400e99:	e8 32 fe ff ff       	callq  400cd0 <exit@plt>
  400e9e:	48 8b 16             	mov    (%rsi),%rdx
  400ea1:	be 81 26 40 00       	mov    $0x402681,%esi
  400ea6:	bf 01 00 00 00       	mov    $0x1,%edi
  400eab:	b8 00 00 00 00       	mov    $0x0,%eax
  400eb0:	e8 eb fd ff ff       	callq  400ca0 <__printf_chk@plt>
  400eb5:	bf 08 00 00 00       	mov    $0x8,%edi
  400eba:	e8 11 fe ff ff       	callq  400cd0 <exit@plt>
  400ebf:	e8 cc 06 00 00       	callq  401590 <initialize_bomb>
  400ec4:	bf e8 26 40 00       	mov    $0x4026e8,%edi
  400ec9:	e8 f2 fc ff ff       	callq  400bc0 <puts@plt>
  400ece:	bf 28 27 40 00       	mov    $0x402728,%edi
  400ed3:	e8 e8 fc ff ff       	callq  400bc0 <puts@plt>
  400ed8:	e8 95 09 00 00       	callq  401872 <read_line>
  400edd:	48 89 c7             	mov    %rax,%rdi
  400ee0:	e8 98 00 00 00       	callq  400f7d <phase_1>
  400ee5:	e8 ae 0a 00 00       	callq  401998 <phase_defused>
  400eea:	bf 58 27 40 00       	mov    $0x402758,%edi
  400eef:	e8 cc fc ff ff       	callq  400bc0 <puts@plt>
  400ef4:	e8 79 09 00 00       	callq  401872 <read_line>
  400ef9:	48 89 c7             	mov    %rax,%rdi
  400efc:	e8 fe 00 00 00       	callq  400fff <phase_2>
  400f01:	e8 92 0a 00 00       	callq  401998 <phase_defused>
  400f06:	bf 9b 26 40 00       	mov    $0x40269b,%edi
  400f0b:	e8 b0 fc ff ff       	callq  400bc0 <puts@plt>
  400f10:	e8 5d 09 00 00       	callq  401872 <read_line>
  400f15:	48 89 c7             	mov    %rax,%rdi
  400f18:	e8 46 01 00 00       	callq  401063 <phase_3>
  400f1d:	e8 76 0a 00 00       	callq  401998 <phase_defused>
  400f22:	bf b9 26 40 00       	mov    $0x4026b9,%edi
  400f27:	e8 94 fc ff ff       	callq  400bc0 <puts@plt>
  400f2c:	e8 41 09 00 00       	callq  401872 <read_line>
  400f31:	48 89 c7             	mov    %rax,%rdi
  400f34:	e8 1e 02 00 00       	callq  401157 <phase_4>
  400f39:	e8 5a 0a 00 00       	callq  401998 <phase_defused>
  400f3e:	bf 88 27 40 00       	mov    $0x402788,%edi
  400f43:	e8 78 fc ff ff       	callq  400bc0 <puts@plt>
  400f48:	e8 25 09 00 00       	callq  401872 <read_line>
  400f4d:	48 89 c7             	mov    %rax,%rdi
  400f50:	e8 6f 02 00 00       	callq  4011c4 <phase_5>
  400f55:	e8 3e 0a 00 00       	callq  401998 <phase_defused>
  400f5a:	bf c8 26 40 00       	mov    $0x4026c8,%edi
  400f5f:	e8 5c fc ff ff       	callq  400bc0 <puts@plt>
  400f64:	e8 09 09 00 00       	callq  401872 <read_line>
  400f69:	48 89 c7             	mov    %rax,%rdi
  400f6c:	e8 d8 02 00 00       	callq  401249 <phase_6>
  400f71:	e8 22 0a 00 00       	callq  401998 <phase_defused>
  400f76:	b8 00 00 00 00       	mov    $0x0,%eax
  400f7b:	5b                   	pop    %rbx
  400f7c:	c3                   	retq   

0000000000400f7d <phase_1>:
  400f7d:	53                   	push   %rbx
  400f7e:	48 83 ec 60          	sub    $0x60,%rsp
  400f82:	48 89 fb             	mov    %rdi,%rbx
  400f85:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  400f8c:	00 00 
  400f8e:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
  400f93:	31 c0                	xor    %eax,%eax
  400f95:	48 b8 4d 79 20 74 65 	movabs $0x207478657420794d,%rax
  400f9c:	78 74 20 
  400f9f:	48 89 04 24          	mov    %rax,(%rsp)
  400fa3:	48 c7 44 24 08 69 73 	movq   $0x207369,0x8(%rsp)
  400faa:	20 00 
  400fac:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  400fb1:	b9 08 00 00 00       	mov    $0x8,%ecx
  400fb6:	b8 00 00 00 00       	mov    $0x0,%eax
  400fbb:	f3 48 ab             	rep stos %rax,%es:(%rdi)
  400fbe:	ba 50 00 00 00       	mov    $0x50,%edx
  400fc3:	be b0 27 40 00       	mov    $0x4027b0,%esi
  400fc8:	48 89 e7             	mov    %rsp,%rdi
  400fcb:	e8 a0 fb ff ff       	callq  400b70 <__strcat_chk@plt>
  400fd0:	48 89 e6             	mov    %rsp,%rsi
  400fd3:	48 89 df             	mov    %rbx,%rdi
  400fd6:	e8 32 05 00 00       	callq  40150d <strings_not_equal>
  400fdb:	85 c0                	test   %eax,%eax
  400fdd:	74 05                	je     400fe4 <phase_1+0x67>
  400fdf:	e8 19 08 00 00       	callq  4017fd <explode_bomb>
  400fe4:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
  400fe9:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  400ff0:	00 00 
  400ff2:	74 05                	je     400ff9 <phase_1+0x7c>
  400ff4:	e8 e7 fb ff ff       	callq  400be0 <__stack_chk_fail@plt>
  400ff9:	48 83 c4 60          	add    $0x60,%rsp
  400ffd:	5b                   	pop    %rbx
  400ffe:	c3                   	retq   

0000000000400fff <phase_2>:
  400fff:	55                   	push   %rbp
  401000:	53                   	push   %rbx
  401001:	48 83 ec 28          	sub    $0x28,%rsp
  401005:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40100c:	00 00 
  40100e:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  401013:	31 c0                	xor    %eax,%eax
  401015:	48 89 e6             	mov    %rsp,%rsi
  401018:	e8 16 08 00 00       	callq  401833 <read_six_numbers>
  40101d:	48 89 e5             	mov    %rsp,%rbp
  401020:	bb 02 00 00 00       	mov    $0x2,%ebx
  401025:	89 d8                	mov    %ebx,%eax
  401027:	c1 e8 1f             	shr    $0x1f,%eax   // *2
  40102a:	01 d8                	add    %ebx,%eax
  40102c:	d1 f8                	sar    %eax  // __divide_by_ 2
  40102e:	03 45 04             	add    0x4(%rbp),%eax
  401031:	39 45 08             	cmp    %eax,0x8(%rbp)
  401034:	74 05                	je     40103b <phase_2+0x3c>
  401036:	e8 c2 07 00 00       	callq  4017fd <explode_bomb>
  40103b:	83 c3 01             	add    $0x1,%ebx
  40103e:	48 83 c5 04          	add    $0x4,%rbp
  401042:	83 fb 06             	cmp    $0x6,%ebx
  401045:	75 de                	jne    401025 <phase_2+0x26>
  401047:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
  40104c:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401053:	00 00 
  401055:	74 05                	je     40105c <phase_2+0x5d>
  401057:	e8 84 fb ff ff       	callq  400be0 <__stack_chk_fail@plt>
  40105c:	48 83 c4 28          	add    $0x28,%rsp
  401060:	5b                   	pop    %rbx
  401061:	5d                   	pop    %rbp
  401062:	c3                   	retq   

0000000000401063 <phase_3>:
  401063:	48 83 ec 28          	sub    $0x28,%rsp
  401067:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40106e:	00 00 
  401070:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  401075:	31 c0                	xor    %eax,%eax
  401077:	4c 8d 44 24 14       	lea    0x14(%rsp),%r8
  40107c:	48 8d 4c 24 10       	lea    0x10(%rsp),%rcx
  401081:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  401086:	be aa 2a 40 00       	mov    $0x402aaa,%esi
  40108b:	e8 00 fc ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  401090:	83 f8 02             	cmp    $0x2,%eax
  401093:	7f 05                	jg     40109a <phase_3+0x37>
  401095:	e8 63 07 00 00       	callq  4017fd <explode_bomb>
  40109a:	83 7c 24 0c 07       	cmpl   $0x7,0xc(%rsp)
  40109f:	77 3c                	ja     4010dd <phase_3+0x7a>
  4010a1:	8b 44 24 0c          	mov    0xc(%rsp),%eax
  4010a5:	ff 24 c5 10 28 40 00 	jmpq   *0x402810(,%rax,8)
  4010ac:	be b6 01 00 00       	mov    $0x1b6,%esi
  4010b1:	eb 3b                	jmp    4010ee <phase_3+0x8b>
  4010b3:	be b6 03 00 00       	mov    $0x3b6,%esi
  4010b8:	eb 34                	jmp    4010ee <phase_3+0x8b>
  4010ba:	be 22 02 00 00       	mov    $0x222,%esi
  4010bf:	eb 2d                	jmp    4010ee <phase_3+0x8b>
  4010c1:	be 5f 00 00 00       	mov    $0x5f,%esi
  4010c6:	eb 26                	jmp    4010ee <phase_3+0x8b>
  4010c8:	be a8 03 00 00       	mov    $0x3a8,%esi
  4010cd:	eb 1f                	jmp    4010ee <phase_3+0x8b>
  4010cf:	be e7 03 00 00       	mov    $0x3e7,%esi
  4010d4:	eb 18                	jmp    4010ee <phase_3+0x8b>
  4010d6:	be bb 03 00 00       	mov    $0x3bb,%esi
  4010db:	eb 11                	jmp    4010ee <phase_3+0x8b>
  4010dd:	e8 1b 07 00 00       	callq  4017fd <explode_bomb>
  4010e2:	be 00 00 00 00       	mov    $0x0,%esi
  4010e7:	eb 05                	jmp    4010ee <phase_3+0x8b>
  4010e9:	be 89 02 00 00       	mov    $0x289,%esi
  4010ee:	8b 54 24 14          	mov    0x14(%rsp),%edx
  4010f2:	8b 7c 24 10          	mov    0x10(%rsp),%edi
  4010f6:	e8 b2 03 00 00       	callq  4014ad <check_multiplication_equal>
  4010fb:	85 c0                	test   %eax,%eax
  4010fd:	75 05                	jne    401104 <phase_3+0xa1>
  4010ff:	e8 f9 06 00 00       	callq  4017fd <explode_bomb>
  401104:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
  401109:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401110:	00 00 
  401112:	74 05                	je     401119 <phase_3+0xb6>
  401114:	e8 c7 fa ff ff       	callq  400be0 <__stack_chk_fail@plt>
  401119:	48 83 c4 28          	add    $0x28,%rsp
  40111d:	c3                   	retq   

000000000040111e <func4>:
  40111e:	b8 00 00 00 00       	mov    $0x0,%eax
  401123:	83 ff 0a             	cmp    $0xa,%edi
  401126:	7f 2d                	jg     401155 <func4+0x37>
  401128:	89 f0                	mov    %esi,%eax
  40112a:	83 ff 0a             	cmp    $0xa,%edi
  40112d:	74 26                	je     401155 <func4+0x37>
  40112f:	41 54                	push   %r12
  401131:	55                   	push   %rbp
  401132:	53                   	push   %rbx
  401133:	89 f5                	mov    %esi,%ebp
  401135:	89 fb                	mov    %edi,%ebx
  401137:	8d 7f 01             	lea    0x1(%rdi),%edi
  40113a:	e8 df ff ff ff       	callq  40111e <func4>
  40113f:	44 8d 64 05 00       	lea    0x0(%rbp,%rax,1),%r12d
  401144:	8d 7b 02             	lea    0x2(%rbx),%edi
  401147:	89 ee                	mov    %ebp,%esi
  401149:	e8 d0 ff ff ff       	callq  40111e <func4>
  40114e:	44 01 e0             	add    %r12d,%eax
  401151:	5b                   	pop    %rbx
  401152:	5d                   	pop    %rbp
  401153:	41 5c                	pop    %r12
  401155:	f3 c3                	repz retq 

0000000000401157 <phase_4>:
  401157:	48 83 ec 18          	sub    $0x18,%rsp
  40115b:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401162:	00 00 
  401164:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  401169:	31 c0                	xor    %eax,%eax
  40116b:	48 89 e1             	mov    %rsp,%rcx
  40116e:	48 8d 54 24 04       	lea    0x4(%rsp),%rdx
  401173:	be ad 2a 40 00       	mov    $0x402aad,%esi
  401178:	e8 13 fb ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  40117d:	83 f8 02             	cmp    $0x2,%eax
  401180:	75 0b                	jne    40118d <phase_4+0x36>
  401182:	8b 04 24             	mov    (%rsp),%eax   #??
  401185:	83 e8 02             	sub    $0x2,%eax     #??
  401188:	83 f8 02             	cmp    $0x2,%eax     #??
  40118b:	76 05                	jbe    401192 <phase_4+0x3b>
  40118d:	e8 6b 06 00 00       	callq  4017fd <explode_bomb>
  401192:	8b 34 24             	mov    (%rsp),%esi
  401195:	bf 07 00 00 00       	mov    $0x7,%edi
  40119a:	e8 7f ff ff ff       	callq  40111e <func4>
  40119f:	3b 44 24 04          	cmp    0x4(%rsp),%eax
  4011a3:	74 05                	je     4011aa <phase_4+0x53>
  4011a5:	e8 53 06 00 00       	callq  4017fd <explode_bomb>
  4011aa:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  4011af:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4011b6:	00 00 
  4011b8:	74 05                	je     4011bf <phase_4+0x68>
  4011ba:	e8 21 fa ff ff       	callq  400be0 <__stack_chk_fail@plt>
  4011bf:	48 83 c4 18          	add    $0x18,%rsp
  4011c3:	c3                   	retq   

00000000004011c4 <phase_5>:
  4011c4:	55                   	push   %rbp
  4011c5:	53                   	push   %rbx
  4011c6:	48 83 ec 18          	sub    $0x18,%rsp
  4011ca:	48 89 fd             	mov    %rdi,%rbp  #input rbp'de tutuluyor
  4011cd:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4011d4:	00 00 
  4011d6:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  4011db:	31 c0                	xor    %eax,%eax
  4011dd:	e8 9d 02 00 00       	callq  40147f <string_length>
  4011e2:	83 f8 06             	cmp    $0x6,%eax
  4011e5:	74 05                	je     4011ec <phase_5+0x28>
  4011e7:	e8 11 06 00 00       	callq  4017fd <explode_bomb>
  4011ec:	bb 00 00 00 00       	mov    $0x0,%ebx           # i=0
  4011f1:	0f be 7c 1d 00       	movsbl 0x0(%rbp,%rbx,1),%edi #i=1
  4011f6:	e8 79 03 00 00       	callq  401574 <from_char_to_int>
  4011fb:	83 e0 0f             	and    $0xf,%eax
  4011fe:	0f b6 80 50 28 40 00 	movzbl 0x402850(%rax),%eax  #0x402850= "maduiersnfotvbyl"
  401205:	88 04 1c             	mov    %al,(%rsp,%rbx,1)
  401208:	48 83 c3 01          	add    $0x1,%rbx
  40120c:	48 83 fb 06          	cmp    $0x6,%rbx
  401210:	75 df                	jne    4011f1 <phase_5+0x2d>
  401212:	c6 44 24 06 00       	movb   $0x0,0x6(%rsp)
  401217:	be 06 28 40 00       	mov    $0x402806,%esi #0x402806= "devils"
  40121c:	48 89 e7             	mov    %rsp,%rdi
  40121f:	e8 e9 02 00 00       	callq  40150d <strings_not_equal>
  401224:	85 c0                	test   %eax,%eax
  401226:	74 05                	je     40122d <phase_5+0x69>
  401228:	e8 d0 05 00 00       	callq  4017fd <explode_bomb>
  40122d:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  401232:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401239:	00 00 
  40123b:	74 05                	je     401242 <phase_5+0x7e>
  40123d:	e8 9e f9 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  401242:	48 83 c4 18          	add    $0x18,%rsp
  401246:	5b                   	pop    %rbx
  401247:	5d                   	pop    %rbp
  401248:	c3                   	retq   


p ( (double(*) () )pow ) (2.,2.)

BASKA COCUGUNKI:
0x00000000004011de <+0>: push   %rbp
   0x00000000004011df <+1>: push   %rbx
   0x00000000004011e0 <+2>: sub    $0x18,%rsp
   0x00000000004011e4 <+6>: mov    %rdi,%rbp
   0x00000000004011e7 <+9>: mov    %fs:0x28,%rax
   0x00000000004011f0 <+18>: mov    %rax,0x8(%rsp)
   0x00000000004011f5 <+23>: xor    %eax,%eax
   0x00000000004011f7 <+25>: callq  0x401491 <string_length>
   0x00000000004011fc <+30>: cmp    $0x6,%eax
   0x00000000004011ff <+33>: je     0x401206 <phase_5+40>
   0x0000000000401201 <+35>: callq  0x40180f <explode_bomb>
   0x0000000000401206 <+40>: mov    $0x0,%ebx
   0x000000000040120b <+45>: movsbl 0x0(%rbp,%rbx,1),%edi
   0x0000000000401210 <+50>: callq  0x401586 <from_char_to_int>
   0x0000000000401215 <+55>: and    $0xf,%eax
   0x0000000000401218 <+58>: movzbl 0x402860(%rax),%eax
   0x000000000040121f <+65>: mov    %al,(%rsp,%rbx,1)
   0x0000000000401222 <+68>: add    $0x1,%rbx
   0x0000000000401226 <+72>: cmp    $0x6,%rbx
   0x000000000040122a <+76>: jne    0x40120b <phase_5+45>
   0x000000000040122c <+78>: movb   $0x0,0x6(%rsp)
   0x0000000000401231 <+83>: mov    $0x40280e,%esi
   0x0000000000401236 <+88>: mov    %rsp,%rdi
   0x0000000000401239 <+91>: callq  0x40151f <strings_not_equal>
   0x000000000040123e <+96>: test   %eax,%eax
   0x0000000000401240 <+98>: je     0x401247 <phase_5+105>
   0x0000000000401242 <+100>: callq  0x40180f <explode_bomb>
   0x0000000000401247 <+105>: mov    0x8(%rsp),%rax
   0x000000000040124c <+110>: xor    %fs:0x28,%rax
   0x0000000000401255 <+119>: je     0x40125c <phase_5+126>
   0x0000000000401257 <+121>: callq  0x400be0 <__stack_chk_fail@plt>
   0x000000000040125c <+126>: add    $0x18,%rsp
   0x0000000000401260 <+130>: pop    %rbx
   0x0000000000401261 <+131>: pop    %rbp
   0x0000000000401262 <+132>: retq  


KADİRCAN:


00000000004011c0 <phase_5>:
  4011c0: 41 54                 push   %r12
  4011c2: 55                    push   %rbp
  4011c3: 53                    push   %rbx
  4011c4: 49 89 fc              mov    %rdi,%r12
  4011c7: e8 87 02 00 00        callq  401453 <string_length>
  4011cc: 83 f8 06              cmp    $0x6,%eax
  4011cf: 74 05                 je     4011d6 <phase_5+0x16>
  4011d1: e8 fb 05 00 00        callq  4017d1 <explode_bomb>
  4011d6: 49 8d 5c 24 01        lea    0x1(%r12),%rbx
  4011db: 49 83 c4 06           add    $0x6,%r12
  4011df: 0f be 3b              movsbl (%rbx),%edi
  4011e2: e8 61 03 00 00        callq  401548 <from_char_to_int>
  4011e7: 89 c5                 mov    %eax,%ebp
  4011e9: 0f be 7b ff           movsbl -0x1(%rbx),%edi
  4011ed: e8 56 03 00 00        callq  401548 <from_char_to_int>
  4011f2: 83 e5 0f              and    $0xf,%ebp
  4011f5: 89 c2                 mov    %eax,%edx
  4011f7: 83 e2 0f              and    $0xf,%edx # grab the last 4 bits
  4011fa: 8b 04 95 40 28 40 00  mov    0x402840(,%rdx,4),%eax
  401201: 39 04 ad 40 28 40 00  cmp    %eax,0x402840(,%rbp,4)
  401208: 7d 05                 jge    40120f <phase_5+0x4f>
  40120a: e8 c2 05 00 00        callq  4017d1 <explode_bomb>
  40120f: 48 83 c3 01           add    $0x1,%rbx
  401213: 4c 39 e3              cmp    %r12,%rbx
  401216: 75 c7                 jne    4011df <phase_5+0x1f>
  401218: 5b                    pop    %rbx
  401219: 5d                    pop    %rbp
  40121a: 41 5c                 pop    %r12
  40121c: c3                    retq
















0000000000401249 <phase_6>:
  401249:	41 55                	push   %r13
  40124b:	41 54                	push   %r12
  40124d:	55                   	push   %rbp
  40124e:	53                   	push   %rbx
  40124f:	48 83 ec 68          	sub    $0x68,%rsp
  401253:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40125a:	00 00 
  40125c:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
  401261:	31 c0                	xor    %eax,%eax
  401263:	48 89 e6             	mov    %rsp,%rsi
  401266:	e8 c8 05 00 00       	callq  401833 <read_six_numbers>
  40126b:	49 89 e4             	mov    %rsp,%r12  #first number to r12
  40126e:	41 bd 00 00 00 00    	mov    $0x0,%r13d
  401274:	4c 89 e5             	mov    %r12,%rbp  #first/second number to rbp
  401277:	41 8b 04 24          	mov    (%r12),%eax
  40127b:	83 e8 01             	sub    $0x1,%eax
  40127e:	83 f8 05             	cmp    $0x5,%eax 
  401281:	76 05                	jbe    401288 <phase_6+0x3f> #check first/second number <= 6
  401283:	e8 75 05 00 00       	callq  4017fd <explode_bomb>
  401288:	41 83 c5 01          	add    $0x1,%r13d
  40128c:	41 83 fd 06          	cmp    $0x6,%r13d
  401290:	74 3d                	je     4012cf <phase_6+0x86>
  401292:	44 89 eb             	mov    %r13d,%ebx  #i=1
  401295:	48 63 c3             	movslq %ebx,%rax  #no change,just 32 bit to 64
  401298:	8b 04 84             	mov    (%rsp,%rax,4),%eax  #eax = n2->0x4(rsp),n3->0x8(rsp) 
  40129b:	39 45 00             	cmp    %eax,0x0(%rbp) #n2 is compared to n1
  40129e:	75 05                	jne    4012a5 <phase_6+0x5c>
  4012a0:	e8 58 05 00 00       	callq  4017fd <explode_bomb>
  4012a5:	83 c3 01             	add    $0x1,%ebx #i=2,3
  4012a8:	83 fb 05             	cmp    $0x5,%ebx
  4012ab:	7e e8                	jle    401295 <phase_6+0x4c>

  

  4012ad:	49 83 c4 04          	add    $0x4,%r12 #r12 n2'yi tutuyor artik
  4012b1:	eb c1                	jmp    401274 <phase_6+0x2b>

  #buraya kadar,girdiğimiz 6 number da farkli olmali ve hepsi <=6

  4012b3:	48 8b 52 08          	mov    0x8(%rdx),%rdx
  4012b7:	83 c0 01             	add    $0x1,%eax
  4012ba:	39 c8                	cmp    %ecx,%eax
  4012bc:	75 f5                	jne    4012b3 <phase_6+0x6a>
  4012be:	48 89 54 74 20       	mov    %rdx,0x20(%rsp,%rsi,2)
  4012c3:	48 83 c6 04          	add    $0x4,%rsi
  4012c7:	48 83 fe 18          	cmp    $0x18,%rsi
  4012cb:	75 07                	jne    4012d4 <phase_6+0x8b>
  4012cd:	eb 19                	jmp    4012e8 <phase_6+0x9f>
  4012cf:	be 00 00 00 00       	mov    $0x0,%esi
  4012d4:	8b 0c 34             	mov    (%rsp,%rsi,1),%ecx
  4012d7:	b8 01 00 00 00       	mov    $0x1,%eax
  4012dc:	ba f0 42 60 00       	mov    $0x6042f0,%edx
  4012e1:	83 f9 01             	cmp    $0x1,%ecx
  4012e4:	7f cd                	jg     4012b3 <phase_6+0x6a>
  4012e6:	eb d6                	jmp    4012be <phase_6+0x75>
  4012e8:	48 8b 5c 24 20       	mov    0x20(%rsp),%rbx
  4012ed:	48 8d 44 24 20       	lea    0x20(%rsp),%rax
  4012f2:	48 8d 74 24 48       	lea    0x48(%rsp),%rsi
  4012f7:	48 89 d9             	mov    %rbx,%rcx
  4012fa:	48 8b 50 08          	mov    0x8(%rax),%rdx
  4012fe:	48 89 51 08          	mov    %rdx,0x8(%rcx)
  401302:	48 83 c0 08          	add    $0x8,%rax
  401306:	48 89 d1             	mov    %rdx,%rcx
  401309:	48 39 f0             	cmp    %rsi,%rax
  40130c:	75 ec                	jne    4012fa <phase_6+0xb1>
  40130e:	48 c7 42 08 00 00 00 	movq   $0x0,0x8(%rdx)
  401315:	00 
  401316:	bd 03 00 00 00       	mov    $0x3,%ebp
  40131b:	48 8b 43 08          	mov    0x8(%rbx),%rax
  40131f:	8b 00                	mov    (%rax),%eax
  401321:	39 03                	cmp    %eax,(%rbx)
  401323:	7d 05                	jge    40132a <phase_6+0xe1>
  401325:	e8 d3 04 00 00       	callq  4017fd <explode_bomb>
  40132a:	48 8b 5b 08          	mov    0x8(%rbx),%rbx
  40132e:	83 ed 01             	sub    $0x1,%ebp
  401331:	75 e8                	jne    40131b <phase_6+0xd2>
  401333:	48 8b 43 08          	mov    0x8(%rbx),%rax
  401337:	8b 3b                	mov    (%rbx),%edi
  401339:	39 38                	cmp    %edi,(%rax)
  40133b:	7d 05                	jge    401342 <phase_6+0xf9>
  40133d:	e8 bb 04 00 00       	callq  4017fd <explode_bomb>
  401342:	48 8b 43 08          	mov    0x8(%rbx),%rax
  401346:	48 8b 50 08          	mov    0x8(%rax),%rdx
  40134a:	8b 3a                	mov    (%rdx),%edi
  40134c:	39 38                	cmp    %edi,(%rax)
  40134e:	7e 05                	jle    401355 <phase_6+0x10c>
  401350:	e8 a8 04 00 00       	callq  4017fd <explode_bomb>
  401355:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
  40135a:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401361:	00 00 
  401363:	74 05                	je     40136a <phase_6+0x121>
  401365:	e8 76 f8 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  40136a:	48 83 c4 68          	add    $0x68,%rsp
  40136e:	5b                   	pop    %rbx
  40136f:	5d                   	pop    %rbp
  401370:	41 5c                	pop    %r12
  401372:	41 5d                	pop    %r13
  401374:	c3                   	retq   

0000000000401375 <fun7>:
  401375:	48 83 ec 08          	sub    $0x8,%rsp
  401379:	48 85 ff             	test   %rdi,%rdi
  40137c:	74 2b                	je     4013a9 <fun7+0x34>
  40137e:	8b 17                	mov    (%rdi),%edx
  401380:	39 f2                	cmp    %esi,%edx
  401382:	7e 0d                	jle    401391 <fun7+0x1c>
  401384:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
  401388:	e8 e8 ff ff ff       	callq  401375 <fun7>
  40138d:	01 c0                	add    %eax,%eax
  40138f:	eb 1d                	jmp    4013ae <fun7+0x39>
  401391:	b8 00 00 00 00       	mov    $0x0,%eax
  401396:	39 f2                	cmp    %esi,%edx
  401398:	74 14                	je     4013ae <fun7+0x39>
  40139a:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
  40139e:	e8 d2 ff ff ff       	callq  401375 <fun7>
  4013a3:	8d 44 00 01          	lea    0x1(%rax,%rax,1),%eax
  4013a7:	eb 05                	jmp    4013ae <fun7+0x39>
  4013a9:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4013ae:	48 83 c4 08          	add    $0x8,%rsp
  4013b2:	c3                   	retq   

00000000004013b3 <secret_phase>:
  4013b3:	53                   	push   %rbx
  4013b4:	e8 b9 04 00 00       	callq  401872 <read_line>
  4013b9:	ba 0a 00 00 00       	mov    $0xa,%edx
  4013be:	be 00 00 00 00       	mov    $0x0,%esi
  4013c3:	48 89 c7             	mov    %rax,%rdi
  4013c6:	e8 a5 f8 ff ff       	callq  400c70 <strtol@plt>
  4013cb:	48 89 c3             	mov    %rax,%rbx
  4013ce:	8d 40 ff             	lea    -0x1(%rax),%eax
  4013d1:	3d e8 03 00 00       	cmp    $0x3e8,%eax
  4013d6:	76 05                	jbe    4013dd <secret_phase+0x2a>
  4013d8:	e8 20 04 00 00       	callq  4017fd <explode_bomb>
  4013dd:	89 de                	mov    %ebx,%esi
  4013df:	bf 10 41 60 00       	mov    $0x604110,%edi
  4013e4:	e8 8c ff ff ff       	callq  401375 <fun7>
  4013e9:	83 f8 04             	cmp    $0x4,%eax
  4013ec:	74 05                	je     4013f3 <secret_phase+0x40>
  4013ee:	e8 0a 04 00 00       	callq  4017fd <explode_bomb>
  4013f3:	bf e0 27 40 00       	mov    $0x4027e0,%edi
  4013f8:	e8 c3 f7 ff ff       	callq  400bc0 <puts@plt>
  4013fd:	e8 96 05 00 00       	callq  401998 <phase_defused>
  401402:	5b                   	pop    %rbx
  401403:	c3                   	retq   

0000000000401404 <sig_handler>:
  401404:	48 83 ec 08          	sub    $0x8,%rsp
  401408:	bf 60 28 40 00       	mov    $0x402860,%edi
  40140d:	e8 ae f7 ff ff       	callq  400bc0 <puts@plt>
  401412:	bf 03 00 00 00       	mov    $0x3,%edi
  401417:	e8 e4 f8 ff ff       	callq  400d00 <sleep@plt>
  40141c:	be 29 2a 40 00       	mov    $0x402a29,%esi
  401421:	bf 01 00 00 00       	mov    $0x1,%edi
  401426:	b8 00 00 00 00       	mov    $0x0,%eax
  40142b:	e8 70 f8 ff ff       	callq  400ca0 <__printf_chk@plt>
  401430:	48 8b 3d 49 33 20 00 	mov    0x203349(%rip),%rdi        # 604780 <stdout@@GLIBC_2.2.5>
  401437:	e8 44 f8 ff ff       	callq  400c80 <fflush@plt>
  40143c:	bf 01 00 00 00       	mov    $0x1,%edi
  401441:	e8 ba f8 ff ff       	callq  400d00 <sleep@plt>
  401446:	bf 31 2a 40 00       	mov    $0x402a31,%edi
  40144b:	e8 70 f7 ff ff       	callq  400bc0 <puts@plt>
  401450:	bf 10 00 00 00       	mov    $0x10,%edi
  401455:	e8 76 f8 ff ff       	callq  400cd0 <exit@plt>

000000000040145a <invalid_phase>:
  40145a:	48 83 ec 08          	sub    $0x8,%rsp
  40145e:	48 89 fa             	mov    %rdi,%rdx
  401461:	be 39 2a 40 00       	mov    $0x402a39,%esi
  401466:	bf 01 00 00 00       	mov    $0x1,%edi
  40146b:	b8 00 00 00 00       	mov    $0x0,%eax
  401470:	e8 2b f8 ff ff       	callq  400ca0 <__printf_chk@plt>
  401475:	bf 08 00 00 00       	mov    $0x8,%edi
  40147a:	e8 51 f8 ff ff       	callq  400cd0 <exit@plt>

000000000040147f <string_length>:
  40147f:	80 3f 00             	cmpb   $0x0,(%rdi)
  401482:	74 13                	je     401497 <string_length+0x18>
  401484:	b8 00 00 00 00       	mov    $0x0,%eax
  401489:	48 83 c7 01          	add    $0x1,%rdi
  40148d:	83 c0 01             	add    $0x1,%eax
  401490:	80 3f 00             	cmpb   $0x0,(%rdi)
  401493:	75 f4                	jne    401489 <string_length+0xa>
  401495:	f3 c3                	repz retq 
  401497:	b8 00 00 00 00       	mov    $0x0,%eax
  40149c:	c3                   	retq   

000000000040149d <check_division_equal>:
  40149d:	89 d1                	mov    %edx,%ecx
  40149f:	89 f8                	mov    %edi,%eax
  4014a1:	99                   	cltd   
  4014a2:	f7 fe                	idiv   %esi
  4014a4:	39 c8                	cmp    %ecx,%eax
  4014a6:	0f 94 c0             	sete   %al
  4014a9:	0f b6 c0             	movzbl %al,%eax
  4014ac:	c3                   	retq   

00000000004014ad <check_multiplication_equal>:
  4014ad:	0f af f7             	imul   %edi,%esi
  4014b0:	39 d6                	cmp    %edx,%esi
  4014b2:	0f 94 c0             	sete   %al
  4014b5:	0f b6 c0             	movzbl %al,%eax
  4014b8:	c3                   	retq   

00000000004014b9 <check_substraction_equal>:
  4014b9:	29 f7                	sub    %esi,%edi
  4014bb:	39 d7                	cmp    %edx,%edi
  4014bd:	0f 94 c0             	sete   %al
  4014c0:	0f b6 c0             	movzbl %al,%eax
  4014c3:	c3                   	retq   

00000000004014c4 <reverse_string>:
  4014c4:	48 89 fe             	mov    %rdi,%rsi
  4014c7:	48 85 ff             	test   %rdi,%rdi
  4014ca:	74 3d                	je     401509 <reverse_string+0x45>
  4014cc:	80 3f 00             	cmpb   $0x0,(%rdi)
  4014cf:	74 38                	je     401509 <reverse_string+0x45>
  4014d1:	b8 00 00 00 00       	mov    $0x0,%eax
  4014d6:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  4014dd:	f2 ae                	repnz scas %es:(%rdi),%al
  4014df:	48 f7 d1             	not    %rcx
  4014e2:	48 8d 4c 0e fe       	lea    -0x2(%rsi,%rcx,1),%rcx
  4014e7:	48 39 ce             	cmp    %rcx,%rsi
  4014ea:	73 1d                	jae    401509 <reverse_string+0x45>
  4014ec:	48 89 f2             	mov    %rsi,%rdx
  4014ef:	0f b6 02             	movzbl (%rdx),%eax
  4014f2:	32 01                	xor    (%rcx),%al
  4014f4:	88 02                	mov    %al,(%rdx)
  4014f6:	32 01                	xor    (%rcx),%al
  4014f8:	88 01                	mov    %al,(%rcx)
  4014fa:	30 02                	xor    %al,(%rdx)
  4014fc:	48 83 c2 01          	add    $0x1,%rdx
  401500:	48 83 e9 01          	sub    $0x1,%rcx
  401504:	48 39 ca             	cmp    %rcx,%rdx
  401507:	72 e6                	jb     4014ef <reverse_string+0x2b>
  401509:	48 89 f0             	mov    %rsi,%rax
  40150c:	c3                   	retq   

000000000040150d <strings_not_equal>:
  40150d:	41 54                	push   %r12
  40150f:	55                   	push   %rbp
  401510:	53                   	push   %rbx
  401511:	48 89 fb             	mov    %rdi,%rbx
  401514:	48 89 f5             	mov    %rsi,%rbp
  401517:	e8 63 ff ff ff       	callq  40147f <string_length>
  40151c:	41 89 c4             	mov    %eax,%r12d
  40151f:	48 89 ef             	mov    %rbp,%rdi
  401522:	e8 58 ff ff ff       	callq  40147f <string_length>
  401527:	ba 01 00 00 00       	mov    $0x1,%edx
  40152c:	41 39 c4             	cmp    %eax,%r12d
  40152f:	75 3c                	jne    40156d <strings_not_equal+0x60>
  401531:	0f b6 03             	movzbl (%rbx),%eax
  401534:	84 c0                	test   %al,%al
  401536:	74 22                	je     40155a <strings_not_equal+0x4d>
  401538:	3a 45 00             	cmp    0x0(%rbp),%al
  40153b:	74 07                	je     401544 <strings_not_equal+0x37>
  40153d:	eb 22                	jmp    401561 <strings_not_equal+0x54>
  40153f:	3a 45 00             	cmp    0x0(%rbp),%al
  401542:	75 24                	jne    401568 <strings_not_equal+0x5b>
  401544:	48 83 c3 01          	add    $0x1,%rbx
  401548:	48 83 c5 01          	add    $0x1,%rbp
  40154c:	0f b6 03             	movzbl (%rbx),%eax
  40154f:	84 c0                	test   %al,%al
  401551:	75 ec                	jne    40153f <strings_not_equal+0x32>
  401553:	ba 00 00 00 00       	mov    $0x0,%edx
  401558:	eb 13                	jmp    40156d <strings_not_equal+0x60>
  40155a:	ba 00 00 00 00       	mov    $0x0,%edx
  40155f:	eb 0c                	jmp    40156d <strings_not_equal+0x60>
  401561:	ba 01 00 00 00       	mov    $0x1,%edx
  401566:	eb 05                	jmp    40156d <strings_not_equal+0x60>
  401568:	ba 01 00 00 00       	mov    $0x1,%edx
  40156d:	89 d0                	mov    %edx,%eax
  40156f:	5b                   	pop    %rbx
  401570:	5d                   	pop    %rbp
  401571:	41 5c                	pop    %r12
  401573:	c3                   	retq   

0000000000401574 <from_char_to_int>:
  401574:	40 0f be c7          	movsbl %dil,%eax
  401578:	40 80 ff 69          	cmp    $0x69,%dil
  40157c:	7e 04                	jle    401582 <from_char_to_int+0xe>
  40157e:	83 e8 09             	sub    $0x9,%eax
  401581:	c3                   	retq   
  401582:	83 ef 33             	sub    $0x33,%edi
  401585:	8d 50 fd             	lea    -0x3(%rax),%edx
  401588:	40 80 ff 09          	cmp    $0x9,%dil
  40158c:	0f 46 c2             	cmovbe %edx,%eax
  40158f:	c3                   	retq   

0000000000401590 <initialize_bomb>:
  401590:	53                   	push   %rbx
  401591:	48 81 ec 50 20 00 00 	sub    $0x2050,%rsp
  401598:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  40159f:	00 00 
  4015a1:	48 89 84 24 48 20 00 	mov    %rax,0x2048(%rsp)
  4015a8:	00 
  4015a9:	31 c0                	xor    %eax,%eax
  4015ab:	be 04 14 40 00       	mov    $0x401404,%esi
  4015b0:	bf 02 00 00 00       	mov    $0x2,%edi
  4015b5:	e8 86 f6 ff ff       	callq  400c40 <signal@plt>
  4015ba:	be 40 00 00 00       	mov    $0x40,%esi
  4015bf:	48 89 e7             	mov    %rsp,%rdi
  4015c2:	e8 f9 f6 ff ff       	callq  400cc0 <gethostname@plt>
  4015c7:	85 c0                	test   %eax,%eax
  4015c9:	75 13                	jne    4015de <initialize_bomb+0x4e>
  4015cb:	48 8b 3d ae 2d 20 00 	mov    0x202dae(%rip),%rdi        # 604380 <host_table>
  4015d2:	bb 88 43 60 00       	mov    $0x604388,%ebx
  4015d7:	48 85 ff             	test   %rdi,%rdi
  4015da:	75 16                	jne    4015f2 <initialize_bomb+0x62>
  4015dc:	eb 52                	jmp    401630 <initialize_bomb+0xa0>
  4015de:	bf 98 28 40 00       	mov    $0x402898,%edi
  4015e3:	e8 d8 f5 ff ff       	callq  400bc0 <puts@plt>
  4015e8:	bf 08 00 00 00       	mov    $0x8,%edi
  4015ed:	e8 de f6 ff ff       	callq  400cd0 <exit@plt>
  4015f2:	48 89 e6             	mov    %rsp,%rsi
  4015f5:	e8 96 f5 ff ff       	callq  400b90 <strcasecmp@plt>
  4015fa:	85 c0                	test   %eax,%eax
  4015fc:	74 46                	je     401644 <initialize_bomb+0xb4>
  4015fe:	48 83 c3 08          	add    $0x8,%rbx
  401602:	48 8b 7b f8          	mov    -0x8(%rbx),%rdi
  401606:	48 85 ff             	test   %rdi,%rdi
  401609:	75 e7                	jne    4015f2 <initialize_bomb+0x62>
  40160b:	eb 23                	jmp    401630 <initialize_bomb+0xa0>
  40160d:	48 8d 54 24 40       	lea    0x40(%rsp),%rdx
  401612:	be 4a 2a 40 00       	mov    $0x402a4a,%esi
  401617:	bf 01 00 00 00       	mov    $0x1,%edi
  40161c:	b8 00 00 00 00       	mov    $0x0,%eax
  401621:	e8 7a f6 ff ff       	callq  400ca0 <__printf_chk@plt>
  401626:	bf 08 00 00 00       	mov    $0x8,%edi
  40162b:	e8 a0 f6 ff ff       	callq  400cd0 <exit@plt>
  401630:	bf d0 28 40 00       	mov    $0x4028d0,%edi
  401635:	e8 86 f5 ff ff       	callq  400bc0 <puts@plt>
  40163a:	bf 08 00 00 00       	mov    $0x8,%edi
  40163f:	e8 8c f6 ff ff       	callq  400cd0 <exit@plt>
  401644:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  401649:	e8 49 0d 00 00       	callq  402397 <init_driver>
  40164e:	85 c0                	test   %eax,%eax
  401650:	78 bb                	js     40160d <initialize_bomb+0x7d>
  401652:	48 8b 84 24 48 20 00 	mov    0x2048(%rsp),%rax
  401659:	00 
  40165a:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401661:	00 00 
  401663:	74 05                	je     40166a <initialize_bomb+0xda>
  401665:	e8 76 f5 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  40166a:	48 81 c4 50 20 00 00 	add    $0x2050,%rsp
  401671:	5b                   	pop    %rbx
  401672:	c3                   	retq   

0000000000401673 <initialize_bomb_solve>:
  401673:	f3 c3                	repz retq 

0000000000401675 <blank_line>:
  401675:	55                   	push   %rbp
  401676:	53                   	push   %rbx
  401677:	48 83 ec 08          	sub    $0x8,%rsp
  40167b:	48 89 fd             	mov    %rdi,%rbp
  40167e:	eb 17                	jmp    401697 <blank_line+0x22>
  401680:	e8 8b f6 ff ff       	callq  400d10 <__ctype_b_loc@plt>
  401685:	48 83 c5 01          	add    $0x1,%rbp
  401689:	48 0f be db          	movsbq %bl,%rbx
  40168d:	48 8b 00             	mov    (%rax),%rax
  401690:	f6 44 58 01 20       	testb  $0x20,0x1(%rax,%rbx,2)
  401695:	74 0f                	je     4016a6 <blank_line+0x31>
  401697:	0f b6 5d 00          	movzbl 0x0(%rbp),%ebx
  40169b:	84 db                	test   %bl,%bl
  40169d:	75 e1                	jne    401680 <blank_line+0xb>
  40169f:	b8 01 00 00 00       	mov    $0x1,%eax
  4016a4:	eb 05                	jmp    4016ab <blank_line+0x36>
  4016a6:	b8 00 00 00 00       	mov    $0x0,%eax
  4016ab:	48 83 c4 08          	add    $0x8,%rsp
  4016af:	5b                   	pop    %rbx
  4016b0:	5d                   	pop    %rbp
  4016b1:	c3                   	retq   

00000000004016b2 <skip>:
  4016b2:	53                   	push   %rbx
  4016b3:	48 63 05 f2 30 20 00 	movslq 0x2030f2(%rip),%rax        # 6047ac <num_input_strings>
  4016ba:	48 8d 3c 80          	lea    (%rax,%rax,4),%rdi
  4016be:	48 c1 e7 04          	shl    $0x4,%rdi
  4016c2:	48 81 c7 c0 47 60 00 	add    $0x6047c0,%rdi
  4016c9:	48 8b 15 e0 30 20 00 	mov    0x2030e0(%rip),%rdx        # 6047b0 <infile>
  4016d0:	be 50 00 00 00       	mov    $0x50,%esi
  4016d5:	e8 56 f5 ff ff       	callq  400c30 <fgets@plt>
  4016da:	48 89 c3             	mov    %rax,%rbx
  4016dd:	48 85 c0             	test   %rax,%rax
  4016e0:	74 0c                	je     4016ee <skip+0x3c>
  4016e2:	48 89 c7             	mov    %rax,%rdi
  4016e5:	e8 8b ff ff ff       	callq  401675 <blank_line>
  4016ea:	85 c0                	test   %eax,%eax
  4016ec:	75 c5                	jne    4016b3 <skip+0x1>
  4016ee:	48 89 d8             	mov    %rbx,%rax
  4016f1:	5b                   	pop    %rbx
  4016f2:	c3                   	retq   

00000000004016f3 <send_msg>:
  4016f3:	48 81 ec 18 40 00 00 	sub    $0x4018,%rsp
  4016fa:	41 89 f8             	mov    %edi,%r8d
  4016fd:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401704:	00 00 
  401706:	48 89 84 24 08 40 00 	mov    %rax,0x4008(%rsp)
  40170d:	00 
  40170e:	31 c0                	xor    %eax,%eax
  401710:	8b 35 96 30 20 00    	mov    0x203096(%rip),%esi        # 6047ac <num_input_strings>
  401716:	8d 46 ff             	lea    -0x1(%rsi),%eax
  401719:	48 98                	cltq   
  40171b:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  40171f:	48 c1 e2 04          	shl    $0x4,%rdx
  401723:	48 81 c2 c0 47 60 00 	add    $0x6047c0,%rdx
  40172a:	b8 00 00 00 00       	mov    $0x0,%eax
  40172f:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  401736:	48 89 d7             	mov    %rdx,%rdi
  401739:	f2 ae                	repnz scas %es:(%rdi),%al
  40173b:	48 f7 d1             	not    %rcx
  40173e:	48 83 c1 63          	add    $0x63,%rcx
  401742:	48 81 f9 00 20 00 00 	cmp    $0x2000,%rcx
  401749:	76 19                	jbe    401764 <send_msg+0x71>
  40174b:	be 08 29 40 00       	mov    $0x402908,%esi
  401750:	bf 01 00 00 00       	mov    $0x1,%edi
  401755:	e8 46 f5 ff ff       	callq  400ca0 <__printf_chk@plt>
  40175a:	bf 08 00 00 00       	mov    $0x8,%edi
  40175f:	e8 6c f5 ff ff       	callq  400cd0 <exit@plt>
  401764:	45 85 c0             	test   %r8d,%r8d
  401767:	41 b9 6c 2a 40 00    	mov    $0x402a6c,%r9d
  40176d:	b8 64 2a 40 00       	mov    $0x402a64,%eax
  401772:	4c 0f 45 c8          	cmovne %rax,%r9
  401776:	52                   	push   %rdx
  401777:	56                   	push   %rsi
  401778:	44 8b 05 f5 2b 20 00 	mov    0x202bf5(%rip),%r8d        # 604374 <bomb_id>
  40177f:	b9 75 2a 40 00       	mov    $0x402a75,%ecx
  401784:	ba 00 20 00 00       	mov    $0x2000,%edx
  401789:	be 01 00 00 00       	mov    $0x1,%esi
  40178e:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401793:	b8 00 00 00 00       	mov    $0x0,%eax
  401798:	e8 83 f5 ff ff       	callq  400d20 <__sprintf_chk@plt>
  40179d:	4c 8d 84 24 10 20 00 	lea    0x2010(%rsp),%r8
  4017a4:	00 
  4017a5:	b9 00 00 00 00       	mov    $0x0,%ecx
  4017aa:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
  4017af:	be 50 43 60 00       	mov    $0x604350,%esi
  4017b4:	bf 68 43 60 00       	mov    $0x604368,%edi
  4017b9:	e8 ae 0d 00 00       	callq  40256c <driver_post>
  4017be:	48 83 c4 10          	add    $0x10,%rsp
  4017c2:	85 c0                	test   %eax,%eax
  4017c4:	79 17                	jns    4017dd <send_msg+0xea>
  4017c6:	48 8d bc 24 00 20 00 	lea    0x2000(%rsp),%rdi
  4017cd:	00 
  4017ce:	e8 ed f3 ff ff       	callq  400bc0 <puts@plt>
  4017d3:	bf 00 00 00 00       	mov    $0x0,%edi
  4017d8:	e8 f3 f4 ff ff       	callq  400cd0 <exit@plt>
  4017dd:	48 8b 84 24 08 40 00 	mov    0x4008(%rsp),%rax
  4017e4:	00 
  4017e5:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  4017ec:	00 00 
  4017ee:	74 05                	je     4017f5 <send_msg+0x102>
  4017f0:	e8 eb f3 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  4017f5:	48 81 c4 18 40 00 00 	add    $0x4018,%rsp
  4017fc:	c3                   	retq   

00000000004017fd <explode_bomb>:
  4017fd:	48 83 ec 08          	sub    $0x8,%rsp
  401801:	bf 81 2a 40 00       	mov    $0x402a81,%edi
  401806:	e8 b5 f3 ff ff       	callq  400bc0 <puts@plt>
  40180b:	bf 8a 2a 40 00       	mov    $0x402a8a,%edi
  401810:	e8 ab f3 ff ff       	callq  400bc0 <puts@plt>
  401815:	bf 00 00 00 00       	mov    $0x0,%edi
  40181a:	e8 d4 fe ff ff       	callq  4016f3 <send_msg>
  40181f:	bf 30 29 40 00       	mov    $0x402930,%edi
  401824:	e8 97 f3 ff ff       	callq  400bc0 <puts@plt>
  401829:	bf 08 00 00 00       	mov    $0x8,%edi
  40182e:	e8 9d f4 ff ff       	callq  400cd0 <exit@plt>

0000000000401833 <read_six_numbers>:
  401833:	48 83 ec 08          	sub    $0x8,%rsp
  401837:	48 89 f2             	mov    %rsi,%rdx
  40183a:	48 8d 4e 04          	lea    0x4(%rsi),%rcx
  40183e:	48 8d 46 14          	lea    0x14(%rsi),%rax
  401842:	50                   	push   %rax
  401843:	48 8d 46 10          	lea    0x10(%rsi),%rax
  401847:	50                   	push   %rax
  401848:	4c 8d 4e 0c          	lea    0xc(%rsi),%r9
  40184c:	4c 8d 46 08          	lea    0x8(%rsi),%r8
  401850:	be a1 2a 40 00       	mov    $0x402aa1,%esi
  401855:	b8 00 00 00 00       	mov    $0x0,%eax
  40185a:	e8 31 f4 ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  40185f:	48 83 c4 10          	add    $0x10,%rsp
  401863:	83 f8 05             	cmp    $0x5,%eax
  401866:	7f 05                	jg     40186d <read_six_numbers+0x3a>
  401868:	e8 90 ff ff ff       	callq  4017fd <explode_bomb>
  40186d:	48 83 c4 08          	add    $0x8,%rsp
  401871:	c3                   	retq   

0000000000401872 <read_line>:
  401872:	48 83 ec 08          	sub    $0x8,%rsp
  401876:	b8 00 00 00 00       	mov    $0x0,%eax
  40187b:	e8 32 fe ff ff       	callq  4016b2 <skip>
  401880:	48 85 c0             	test   %rax,%rax
  401883:	75 6e                	jne    4018f3 <read_line+0x81>
  401885:	48 8b 05 04 2f 20 00 	mov    0x202f04(%rip),%rax        # 604790 <stdin@@GLIBC_2.2.5>
  40188c:	48 39 05 1d 2f 20 00 	cmp    %rax,0x202f1d(%rip)        # 6047b0 <infile>
  401893:	75 14                	jne    4018a9 <read_line+0x37>
  401895:	bf b3 2a 40 00       	mov    $0x402ab3,%edi
  40189a:	e8 21 f3 ff ff       	callq  400bc0 <puts@plt>
  40189f:	bf 08 00 00 00       	mov    $0x8,%edi
  4018a4:	e8 27 f4 ff ff       	callq  400cd0 <exit@plt>
  4018a9:	bf d1 2a 40 00       	mov    $0x402ad1,%edi
  4018ae:	e8 cd f2 ff ff       	callq  400b80 <getenv@plt>
  4018b3:	48 85 c0             	test   %rax,%rax
  4018b6:	74 0a                	je     4018c2 <read_line+0x50>
  4018b8:	bf 00 00 00 00       	mov    $0x0,%edi
  4018bd:	e8 0e f4 ff ff       	callq  400cd0 <exit@plt>
  4018c2:	48 8b 05 c7 2e 20 00 	mov    0x202ec7(%rip),%rax        # 604790 <stdin@@GLIBC_2.2.5>
  4018c9:	48 89 05 e0 2e 20 00 	mov    %rax,0x202ee0(%rip)        # 6047b0 <infile>
  4018d0:	b8 00 00 00 00       	mov    $0x0,%eax
  4018d5:	e8 d8 fd ff ff       	callq  4016b2 <skip>
  4018da:	48 85 c0             	test   %rax,%rax
  4018dd:	75 14                	jne    4018f3 <read_line+0x81>
  4018df:	bf b3 2a 40 00       	mov    $0x402ab3,%edi
  4018e4:	e8 d7 f2 ff ff       	callq  400bc0 <puts@plt>
  4018e9:	bf 00 00 00 00       	mov    $0x0,%edi
  4018ee:	e8 dd f3 ff ff       	callq  400cd0 <exit@plt>
  4018f3:	8b 35 b3 2e 20 00    	mov    0x202eb3(%rip),%esi        # 6047ac <num_input_strings>
  4018f9:	48 63 c6             	movslq %esi,%rax
  4018fc:	48 8d 14 80          	lea    (%rax,%rax,4),%rdx
  401900:	48 c1 e2 04          	shl    $0x4,%rdx
  401904:	48 81 c2 c0 47 60 00 	add    $0x6047c0,%rdx
  40190b:	b8 00 00 00 00       	mov    $0x0,%eax
  401910:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  401917:	48 89 d7             	mov    %rdx,%rdi
  40191a:	f2 ae                	repnz scas %es:(%rdi),%al
  40191c:	48 f7 d1             	not    %rcx
  40191f:	48 83 e9 01          	sub    $0x1,%rcx
  401923:	83 f9 4e             	cmp    $0x4e,%ecx
  401926:	7e 46                	jle    40196e <read_line+0xfc>
  401928:	bf dc 2a 40 00       	mov    $0x402adc,%edi
  40192d:	e8 8e f2 ff ff       	callq  400bc0 <puts@plt>
  401932:	8b 05 74 2e 20 00    	mov    0x202e74(%rip),%eax        # 6047ac <num_input_strings>
  401938:	8d 50 01             	lea    0x1(%rax),%edx
  40193b:	89 15 6b 2e 20 00    	mov    %edx,0x202e6b(%rip)        # 6047ac <num_input_strings>
  401941:	48 98                	cltq   
  401943:	48 6b c0 50          	imul   $0x50,%rax,%rax
  401947:	48 bf 2a 2a 2a 74 72 	movabs $0x636e7572742a2a2a,%rdi
  40194e:	75 6e 63 
  401951:	48 89 b8 c0 47 60 00 	mov    %rdi,0x6047c0(%rax)
  401958:	48 bf 61 74 65 64 2a 	movabs $0x2a2a2a64657461,%rdi
  40195f:	2a 2a 00 
  401962:	48 89 b8 c8 47 60 00 	mov    %rdi,0x6047c8(%rax)
  401969:	e8 8f fe ff ff       	callq  4017fd <explode_bomb>
  40196e:	83 e9 01             	sub    $0x1,%ecx
  401971:	48 63 c9             	movslq %ecx,%rcx
  401974:	48 63 c6             	movslq %esi,%rax
  401977:	48 8d 04 80          	lea    (%rax,%rax,4),%rax
  40197b:	48 c1 e0 04          	shl    $0x4,%rax
  40197f:	c6 84 01 c0 47 60 00 	movb   $0x0,0x6047c0(%rcx,%rax,1)
  401986:	00 
  401987:	8d 46 01             	lea    0x1(%rsi),%eax
  40198a:	89 05 1c 2e 20 00    	mov    %eax,0x202e1c(%rip)        # 6047ac <num_input_strings>
  401990:	48 89 d0             	mov    %rdx,%rax
  401993:	48 83 c4 08          	add    $0x8,%rsp
  401997:	c3                   	retq   

0000000000401998 <phase_defused>:
  401998:	48 83 ec 78          	sub    $0x78,%rsp
  40199c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4019a3:	00 00 
  4019a5:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
  4019aa:	31 c0                	xor    %eax,%eax
  4019ac:	bf 01 00 00 00       	mov    $0x1,%edi
  4019b1:	e8 3d fd ff ff       	callq  4016f3 <send_msg>
  4019b6:	83 3d ef 2d 20 00 06 	cmpl   $0x6,0x202def(%rip)        # 6047ac <num_input_strings>
  4019bd:	75 6d                	jne    401a2c <phase_defused+0x94>
  4019bf:	4c 8d 44 24 10       	lea    0x10(%rsp),%r8
  4019c4:	48 8d 4c 24 0c       	lea    0xc(%rsp),%rcx
  4019c9:	48 8d 54 24 08       	lea    0x8(%rsp),%rdx
  4019ce:	be f7 2a 40 00       	mov    $0x402af7,%esi
  4019d3:	bf b0 48 60 00       	mov    $0x6048b0,%edi
  4019d8:	b8 00 00 00 00       	mov    $0x0,%eax
  4019dd:	e8 ae f2 ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  4019e2:	83 f8 03             	cmp    $0x3,%eax
  4019e5:	75 31                	jne    401a18 <phase_defused+0x80>
  4019e7:	be 00 2b 40 00       	mov    $0x402b00,%esi
  4019ec:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4019f1:	e8 17 fb ff ff       	callq  40150d <strings_not_equal>
  4019f6:	85 c0                	test   %eax,%eax
  4019f8:	75 1e                	jne    401a18 <phase_defused+0x80>
  4019fa:	bf 58 29 40 00       	mov    $0x402958,%edi
  4019ff:	e8 bc f1 ff ff       	callq  400bc0 <puts@plt>
  401a04:	bf 80 29 40 00       	mov    $0x402980,%edi
  401a09:	e8 b2 f1 ff ff       	callq  400bc0 <puts@plt>
  401a0e:	b8 00 00 00 00       	mov    $0x0,%eax
  401a13:	e8 9b f9 ff ff       	callq  4013b3 <secret_phase>
  401a18:	bf b8 29 40 00       	mov    $0x4029b8,%edi
  401a1d:	e8 9e f1 ff ff       	callq  400bc0 <puts@plt>
  401a22:	bf e8 29 40 00       	mov    $0x4029e8,%edi
  401a27:	e8 94 f1 ff ff       	callq  400bc0 <puts@plt>
  401a2c:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
  401a31:	64 48 33 04 25 28 00 	xor    %fs:0x28,%rax
  401a38:	00 00 
  401a3a:	74 05                	je     401a41 <phase_defused+0xa9>
  401a3c:	e8 9f f1 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  401a41:	48 83 c4 78          	add    $0x78,%rsp
  401a45:	c3                   	retq   

0000000000401a46 <sigalrm_handler>:
  401a46:	48 83 ec 08          	sub    $0x8,%rsp
  401a4a:	b9 00 00 00 00       	mov    $0x0,%ecx
  401a4f:	ba d8 2d 40 00       	mov    $0x402dd8,%edx
  401a54:	be 01 00 00 00       	mov    $0x1,%esi
  401a59:	48 8b 3d 40 2d 20 00 	mov    0x202d40(%rip),%rdi        # 6047a0 <stderr@@GLIBC_2.2.5>
  401a60:	b8 00 00 00 00       	mov    $0x0,%eax
  401a65:	e8 86 f2 ff ff       	callq  400cf0 <__fprintf_chk@plt>
  401a6a:	bf 01 00 00 00       	mov    $0x1,%edi
  401a6f:	e8 5c f2 ff ff       	callq  400cd0 <exit@plt>

0000000000401a74 <rio_readlineb>:
  401a74:	41 56                	push   %r14
  401a76:	41 55                	push   %r13
  401a78:	41 54                	push   %r12
  401a7a:	55                   	push   %rbp
  401a7b:	53                   	push   %rbx
  401a7c:	48 83 ec 10          	sub    $0x10,%rsp
  401a80:	48 89 fb             	mov    %rdi,%rbx
  401a83:	49 89 f5             	mov    %rsi,%r13
  401a86:	49 89 d6             	mov    %rdx,%r14
  401a89:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401a90:	00 00 
  401a92:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  401a97:	31 c0                	xor    %eax,%eax
  401a99:	41 bc 01 00 00 00    	mov    $0x1,%r12d
  401a9f:	48 8d 6f 10          	lea    0x10(%rdi),%rbp
  401aa3:	48 83 fa 01          	cmp    $0x1,%rdx
  401aa7:	77 2c                	ja     401ad5 <rio_readlineb+0x61>
  401aa9:	eb 6d                	jmp    401b18 <rio_readlineb+0xa4>
  401aab:	ba 00 20 00 00       	mov    $0x2000,%edx
  401ab0:	48 89 ee             	mov    %rbp,%rsi
  401ab3:	8b 3b                	mov    (%rbx),%edi
  401ab5:	e8 56 f1 ff ff       	callq  400c10 <read@plt>
  401aba:	89 43 04             	mov    %eax,0x4(%rbx)
  401abd:	85 c0                	test   %eax,%eax
  401abf:	79 0c                	jns    401acd <rio_readlineb+0x59>
  401ac1:	e8 da f0 ff ff       	callq  400ba0 <__errno_location@plt>
  401ac6:	83 38 04             	cmpl   $0x4,(%rax)
  401ac9:	74 0a                	je     401ad5 <rio_readlineb+0x61>
  401acb:	eb 6c                	jmp    401b39 <rio_readlineb+0xc5>
  401acd:	85 c0                	test   %eax,%eax
  401acf:	74 71                	je     401b42 <rio_readlineb+0xce>
  401ad1:	48 89 6b 08          	mov    %rbp,0x8(%rbx)
  401ad5:	8b 43 04             	mov    0x4(%rbx),%eax
  401ad8:	85 c0                	test   %eax,%eax
  401ada:	7e cf                	jle    401aab <rio_readlineb+0x37>
  401adc:	48 8b 53 08          	mov    0x8(%rbx),%rdx
  401ae0:	0f b6 0a             	movzbl (%rdx),%ecx
  401ae3:	88 4c 24 07          	mov    %cl,0x7(%rsp)
  401ae7:	48 83 c2 01          	add    $0x1,%rdx
  401aeb:	48 89 53 08          	mov    %rdx,0x8(%rbx)
  401aef:	83 e8 01             	sub    $0x1,%eax
  401af2:	89 43 04             	mov    %eax,0x4(%rbx)
  401af5:	49 83 c5 01          	add    $0x1,%r13
  401af9:	41 88 4d ff          	mov    %cl,-0x1(%r13)
  401afd:	80 f9 0a             	cmp    $0xa,%cl
  401b00:	75 0a                	jne    401b0c <rio_readlineb+0x98>
  401b02:	eb 14                	jmp    401b18 <rio_readlineb+0xa4>
  401b04:	41 83 fc 01          	cmp    $0x1,%r12d
  401b08:	75 0e                	jne    401b18 <rio_readlineb+0xa4>
  401b0a:	eb 16                	jmp    401b22 <rio_readlineb+0xae>
  401b0c:	41 83 c4 01          	add    $0x1,%r12d
  401b10:	49 63 c4             	movslq %r12d,%rax
  401b13:	4c 39 f0             	cmp    %r14,%rax
  401b16:	72 bd                	jb     401ad5 <rio_readlineb+0x61>
  401b18:	41 c6 45 00 00       	movb   $0x0,0x0(%r13)
  401b1d:	49 63 c4             	movslq %r12d,%rax
  401b20:	eb 05                	jmp    401b27 <rio_readlineb+0xb3>
  401b22:	b8 00 00 00 00       	mov    $0x0,%eax
  401b27:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  401b2c:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  401b33:	00 00 
  401b35:	74 22                	je     401b59 <rio_readlineb+0xe5>
  401b37:	eb 1b                	jmp    401b54 <rio_readlineb+0xe0>
  401b39:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  401b40:	eb 05                	jmp    401b47 <rio_readlineb+0xd3>
  401b42:	b8 00 00 00 00       	mov    $0x0,%eax
  401b47:	85 c0                	test   %eax,%eax
  401b49:	74 b9                	je     401b04 <rio_readlineb+0x90>
  401b4b:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  401b52:	eb d3                	jmp    401b27 <rio_readlineb+0xb3>
  401b54:	e8 87 f0 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  401b59:	48 83 c4 10          	add    $0x10,%rsp
  401b5d:	5b                   	pop    %rbx
  401b5e:	5d                   	pop    %rbp
  401b5f:	41 5c                	pop    %r12
  401b61:	41 5d                	pop    %r13
  401b63:	41 5e                	pop    %r14
  401b65:	c3                   	retq   

0000000000401b66 <submitr>:
  401b66:	41 57                	push   %r15
  401b68:	41 56                	push   %r14
  401b6a:	41 55                	push   %r13
  401b6c:	41 54                	push   %r12
  401b6e:	55                   	push   %rbp
  401b6f:	53                   	push   %rbx
  401b70:	48 81 ec 68 a0 00 00 	sub    $0xa068,%rsp
  401b77:	49 89 fd             	mov    %rdi,%r13
  401b7a:	89 f5                	mov    %esi,%ebp
  401b7c:	48 89 14 24          	mov    %rdx,(%rsp)
  401b80:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
  401b85:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
  401b8a:	4c 89 4c 24 10       	mov    %r9,0x10(%rsp)
  401b8f:	48 8b 9c 24 a0 a0 00 	mov    0xa0a0(%rsp),%rbx
  401b96:	00 
  401b97:	4c 8b bc 24 a8 a0 00 	mov    0xa0a8(%rsp),%r15
  401b9e:	00 
  401b9f:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  401ba6:	00 00 
  401ba8:	48 89 84 24 58 a0 00 	mov    %rax,0xa058(%rsp)
  401baf:	00 
  401bb0:	31 c0                	xor    %eax,%eax
  401bb2:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%rsp)
  401bb9:	00 
  401bba:	ba 00 00 00 00       	mov    $0x0,%edx
  401bbf:	be 01 00 00 00       	mov    $0x1,%esi
  401bc4:	bf 02 00 00 00       	mov    $0x2,%edi
  401bc9:	e8 62 f1 ff ff       	callq  400d30 <socket@plt>
  401bce:	85 c0                	test   %eax,%eax
  401bd0:	79 50                	jns    401c22 <submitr+0xbc>
  401bd2:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  401bd9:	3a 20 43 
  401bdc:	49 89 07             	mov    %rax,(%r15)
  401bdf:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  401be6:	20 75 6e 
  401be9:	49 89 47 08          	mov    %rax,0x8(%r15)
  401bed:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  401bf4:	74 6f 20 
  401bf7:	49 89 47 10          	mov    %rax,0x10(%r15)
  401bfb:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  401c02:	65 20 73 
  401c05:	49 89 47 18          	mov    %rax,0x18(%r15)
  401c09:	41 c7 47 20 6f 63 6b 	movl   $0x656b636f,0x20(%r15)
  401c10:	65 
  401c11:	66 41 c7 47 24 74 00 	movw   $0x74,0x24(%r15)
  401c18:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401c1d:	e9 12 06 00 00       	jmpq   402234 <submitr+0x6ce>
  401c22:	41 89 c4             	mov    %eax,%r12d
  401c25:	4c 89 ef             	mov    %r13,%rdi
  401c28:	e8 23 f0 ff ff       	callq  400c50 <gethostbyname@plt>
  401c2d:	48 85 c0             	test   %rax,%rax
  401c30:	75 6b                	jne    401c9d <submitr+0x137>
  401c32:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  401c39:	3a 20 44 
  401c3c:	49 89 07             	mov    %rax,(%r15)
  401c3f:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  401c46:	20 75 6e 
  401c49:	49 89 47 08          	mov    %rax,0x8(%r15)
  401c4d:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  401c54:	74 6f 20 
  401c57:	49 89 47 10          	mov    %rax,0x10(%r15)
  401c5b:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  401c62:	76 65 20 
  401c65:	49 89 47 18          	mov    %rax,0x18(%r15)
  401c69:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  401c70:	72 20 61 
  401c73:	49 89 47 20          	mov    %rax,0x20(%r15)
  401c77:	41 c7 47 28 64 64 72 	movl   $0x65726464,0x28(%r15)
  401c7e:	65 
  401c7f:	66 41 c7 47 2c 73 73 	movw   $0x7373,0x2c(%r15)
  401c86:	41 c6 47 2e 00       	movb   $0x0,0x2e(%r15)
  401c8b:	44 89 e7             	mov    %r12d,%edi
  401c8e:	e8 6d ef ff ff       	callq  400c00 <close@plt>
  401c93:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401c98:	e9 97 05 00 00       	jmpq   402234 <submitr+0x6ce>
  401c9d:	48 c7 44 24 30 00 00 	movq   $0x0,0x30(%rsp)
  401ca4:	00 00 
  401ca6:	48 c7 44 24 38 00 00 	movq   $0x0,0x38(%rsp)
  401cad:	00 00 
  401caf:	66 c7 44 24 30 02 00 	movw   $0x2,0x30(%rsp)
  401cb6:	48 63 50 14          	movslq 0x14(%rax),%rdx
  401cba:	48 8b 40 18          	mov    0x18(%rax),%rax
  401cbe:	48 8d 7c 24 34       	lea    0x34(%rsp),%rdi
  401cc3:	b9 0c 00 00 00       	mov    $0xc,%ecx
  401cc8:	48 8b 30             	mov    (%rax),%rsi
  401ccb:	e8 90 ef ff ff       	callq  400c60 <__memmove_chk@plt>
  401cd0:	66 c1 cd 08          	ror    $0x8,%bp
  401cd4:	66 89 6c 24 32       	mov    %bp,0x32(%rsp)
  401cd9:	ba 10 00 00 00       	mov    $0x10,%edx
  401cde:	48 8d 74 24 30       	lea    0x30(%rsp),%rsi
  401ce3:	44 89 e7             	mov    %r12d,%edi
  401ce6:	e8 f5 ef ff ff       	callq  400ce0 <connect@plt>
  401ceb:	85 c0                	test   %eax,%eax
  401ced:	79 5d                	jns    401d4c <submitr+0x1e6>
  401cef:	48 b8 45 72 72 6f 72 	movabs $0x55203a726f727245,%rax
  401cf6:	3a 20 55 
  401cf9:	49 89 07             	mov    %rax,(%r15)
  401cfc:	48 b8 6e 61 62 6c 65 	movabs $0x6f7420656c62616e,%rax
  401d03:	20 74 6f 
  401d06:	49 89 47 08          	mov    %rax,0x8(%r15)
  401d0a:	48 b8 20 63 6f 6e 6e 	movabs $0x7463656e6e6f6320,%rax
  401d11:	65 63 74 
  401d14:	49 89 47 10          	mov    %rax,0x10(%r15)
  401d18:	48 b8 20 74 6f 20 74 	movabs $0x20656874206f7420,%rax
  401d1f:	68 65 20 
  401d22:	49 89 47 18          	mov    %rax,0x18(%r15)
  401d26:	41 c7 47 20 73 65 72 	movl   $0x76726573,0x20(%r15)
  401d2d:	76 
  401d2e:	66 41 c7 47 24 65 72 	movw   $0x7265,0x24(%r15)
  401d35:	41 c6 47 26 00       	movb   $0x0,0x26(%r15)
  401d3a:	44 89 e7             	mov    %r12d,%edi
  401d3d:	e8 be ee ff ff       	callq  400c00 <close@plt>
  401d42:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401d47:	e9 e8 04 00 00       	jmpq   402234 <submitr+0x6ce>
  401d4c:	49 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%r9
  401d53:	b8 00 00 00 00       	mov    $0x0,%eax
  401d58:	4c 89 c9             	mov    %r9,%rcx
  401d5b:	48 89 df             	mov    %rbx,%rdi
  401d5e:	f2 ae                	repnz scas %es:(%rdi),%al
  401d60:	48 f7 d1             	not    %rcx
  401d63:	48 89 ce             	mov    %rcx,%rsi
  401d66:	4c 89 c9             	mov    %r9,%rcx
  401d69:	48 8b 3c 24          	mov    (%rsp),%rdi
  401d6d:	f2 ae                	repnz scas %es:(%rdi),%al
  401d6f:	49 89 c8             	mov    %rcx,%r8
  401d72:	4c 89 c9             	mov    %r9,%rcx
  401d75:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  401d7a:	f2 ae                	repnz scas %es:(%rdi),%al
  401d7c:	48 f7 d1             	not    %rcx
  401d7f:	48 89 ca             	mov    %rcx,%rdx
  401d82:	4c 89 c9             	mov    %r9,%rcx
  401d85:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
  401d8a:	f2 ae                	repnz scas %es:(%rdi),%al
  401d8c:	4c 29 c2             	sub    %r8,%rdx
  401d8f:	48 29 ca             	sub    %rcx,%rdx
  401d92:	48 8d 44 76 fd       	lea    -0x3(%rsi,%rsi,2),%rax
  401d97:	48 8d 44 02 7b       	lea    0x7b(%rdx,%rax,1),%rax
  401d9c:	48 3d 00 20 00 00    	cmp    $0x2000,%rax
  401da2:	76 73                	jbe    401e17 <submitr+0x2b1>
  401da4:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  401dab:	3a 20 52 
  401dae:	49 89 07             	mov    %rax,(%r15)
  401db1:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  401db8:	20 73 74 
  401dbb:	49 89 47 08          	mov    %rax,0x8(%r15)
  401dbf:	48 b8 72 69 6e 67 20 	movabs $0x6f6f7420676e6972,%rax
  401dc6:	74 6f 6f 
  401dc9:	49 89 47 10          	mov    %rax,0x10(%r15)
  401dcd:	48 b8 20 6c 61 72 67 	movabs $0x202e656772616c20,%rax
  401dd4:	65 2e 20 
  401dd7:	49 89 47 18          	mov    %rax,0x18(%r15)
  401ddb:	48 b8 49 6e 63 72 65 	movabs $0x6573616572636e49,%rax
  401de2:	61 73 65 
  401de5:	49 89 47 20          	mov    %rax,0x20(%r15)
  401de9:	48 b8 20 53 55 42 4d 	movabs $0x5254494d42555320,%rax
  401df0:	49 54 52 
  401df3:	49 89 47 28          	mov    %rax,0x28(%r15)
  401df7:	48 b8 5f 4d 41 58 42 	movabs $0x46554258414d5f,%rax
  401dfe:	55 46 00 
  401e01:	49 89 47 30          	mov    %rax,0x30(%r15)
  401e05:	44 89 e7             	mov    %r12d,%edi
  401e08:	e8 f3 ed ff ff       	callq  400c00 <close@plt>
  401e0d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401e12:	e9 1d 04 00 00       	jmpq   402234 <submitr+0x6ce>
  401e17:	48 8d 94 24 50 40 00 	lea    0x4050(%rsp),%rdx
  401e1e:	00 
  401e1f:	b9 00 04 00 00       	mov    $0x400,%ecx
  401e24:	b8 00 00 00 00       	mov    $0x0,%eax
  401e29:	48 89 d7             	mov    %rdx,%rdi
  401e2c:	f3 48 ab             	rep stos %rax,%es:(%rdi)
  401e2f:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  401e36:	48 89 df             	mov    %rbx,%rdi
  401e39:	f2 ae                	repnz scas %es:(%rdi),%al
  401e3b:	48 89 c8             	mov    %rcx,%rax
  401e3e:	48 f7 d0             	not    %rax
  401e41:	48 83 e8 01          	sub    $0x1,%rax
  401e45:	85 c0                	test   %eax,%eax
  401e47:	0f 84 90 04 00 00    	je     4022dd <submitr+0x777>
  401e4d:	8d 40 ff             	lea    -0x1(%rax),%eax
  401e50:	4c 8d 74 03 01       	lea    0x1(%rbx,%rax,1),%r14
  401e55:	48 89 d5             	mov    %rdx,%rbp
  401e58:	49 bd d9 ff 00 00 00 	movabs $0x2000000000ffd9,%r13
  401e5f:	00 20 00 
  401e62:	44 0f b6 03          	movzbl (%rbx),%r8d
  401e66:	41 8d 40 d6          	lea    -0x2a(%r8),%eax
  401e6a:	3c 35                	cmp    $0x35,%al
  401e6c:	77 06                	ja     401e74 <submitr+0x30e>
  401e6e:	49 0f a3 c5          	bt     %rax,%r13
  401e72:	72 0d                	jb     401e81 <submitr+0x31b>
  401e74:	44 89 c0             	mov    %r8d,%eax
  401e77:	83 e0 df             	and    $0xffffffdf,%eax
  401e7a:	83 e8 41             	sub    $0x41,%eax
  401e7d:	3c 19                	cmp    $0x19,%al
  401e7f:	77 0a                	ja     401e8b <submitr+0x325>
  401e81:	44 88 45 00          	mov    %r8b,0x0(%rbp)
  401e85:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  401e89:	eb 6c                	jmp    401ef7 <submitr+0x391>
  401e8b:	41 80 f8 20          	cmp    $0x20,%r8b
  401e8f:	75 0a                	jne    401e9b <submitr+0x335>
  401e91:	c6 45 00 2b          	movb   $0x2b,0x0(%rbp)
  401e95:	48 8d 6d 01          	lea    0x1(%rbp),%rbp
  401e99:	eb 5c                	jmp    401ef7 <submitr+0x391>
  401e9b:	41 8d 40 e0          	lea    -0x20(%r8),%eax
  401e9f:	3c 5f                	cmp    $0x5f,%al
  401ea1:	76 0a                	jbe    401ead <submitr+0x347>
  401ea3:	41 80 f8 09          	cmp    $0x9,%r8b
  401ea7:	0f 85 a3 03 00 00    	jne    402250 <submitr+0x6ea>
  401ead:	45 0f b6 c0          	movzbl %r8b,%r8d
  401eb1:	b9 b0 2e 40 00       	mov    $0x402eb0,%ecx
  401eb6:	ba 08 00 00 00       	mov    $0x8,%edx
  401ebb:	be 01 00 00 00       	mov    $0x1,%esi
  401ec0:	48 8d bc 24 50 80 00 	lea    0x8050(%rsp),%rdi
  401ec7:	00 
  401ec8:	b8 00 00 00 00       	mov    $0x0,%eax
  401ecd:	e8 4e ee ff ff       	callq  400d20 <__sprintf_chk@plt>
  401ed2:	0f b6 84 24 50 80 00 	movzbl 0x8050(%rsp),%eax
  401ed9:	00 
  401eda:	88 45 00             	mov    %al,0x0(%rbp)
  401edd:	0f b6 84 24 51 80 00 	movzbl 0x8051(%rsp),%eax
  401ee4:	00 
  401ee5:	88 45 01             	mov    %al,0x1(%rbp)
  401ee8:	0f b6 84 24 52 80 00 	movzbl 0x8052(%rsp),%eax
  401eef:	00 
  401ef0:	88 45 02             	mov    %al,0x2(%rbp)
  401ef3:	48 8d 6d 03          	lea    0x3(%rbp),%rbp
  401ef7:	48 83 c3 01          	add    $0x1,%rbx
  401efb:	49 39 de             	cmp    %rbx,%r14
  401efe:	0f 85 5e ff ff ff    	jne    401e62 <submitr+0x2fc>
  401f04:	e9 d4 03 00 00       	jmpq   4022dd <submitr+0x777>
  401f09:	48 89 da             	mov    %rbx,%rdx
  401f0c:	48 89 ee             	mov    %rbp,%rsi
  401f0f:	44 89 e7             	mov    %r12d,%edi
  401f12:	e8 b9 ec ff ff       	callq  400bd0 <write@plt>
  401f17:	48 85 c0             	test   %rax,%rax
  401f1a:	7f 0f                	jg     401f2b <submitr+0x3c5>
  401f1c:	e8 7f ec ff ff       	callq  400ba0 <__errno_location@plt>
  401f21:	83 38 04             	cmpl   $0x4,(%rax)
  401f24:	75 12                	jne    401f38 <submitr+0x3d2>
  401f26:	b8 00 00 00 00       	mov    $0x0,%eax
  401f2b:	48 01 c5             	add    %rax,%rbp
  401f2e:	48 29 c3             	sub    %rax,%rbx
  401f31:	75 d6                	jne    401f09 <submitr+0x3a3>
  401f33:	4d 85 ed             	test   %r13,%r13
  401f36:	79 5f                	jns    401f97 <submitr+0x431>
  401f38:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  401f3f:	3a 20 43 
  401f42:	49 89 07             	mov    %rax,(%r15)
  401f45:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  401f4c:	20 75 6e 
  401f4f:	49 89 47 08          	mov    %rax,0x8(%r15)
  401f53:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  401f5a:	74 6f 20 
  401f5d:	49 89 47 10          	mov    %rax,0x10(%r15)
  401f61:	48 b8 77 72 69 74 65 	movabs $0x6f74206574697277,%rax
  401f68:	20 74 6f 
  401f6b:	49 89 47 18          	mov    %rax,0x18(%r15)
  401f6f:	48 b8 20 74 68 65 20 	movabs $0x7265732065687420,%rax
  401f76:	73 65 72 
  401f79:	49 89 47 20          	mov    %rax,0x20(%r15)
  401f7d:	41 c7 47 28 76 65 72 	movl   $0x726576,0x28(%r15)
  401f84:	00 
  401f85:	44 89 e7             	mov    %r12d,%edi
  401f88:	e8 73 ec ff ff       	callq  400c00 <close@plt>
  401f8d:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401f92:	e9 9d 02 00 00       	jmpq   402234 <submitr+0x6ce>
  401f97:	44 89 64 24 40       	mov    %r12d,0x40(%rsp)
  401f9c:	c7 44 24 44 00 00 00 	movl   $0x0,0x44(%rsp)
  401fa3:	00 
  401fa4:	48 8d 44 24 50       	lea    0x50(%rsp),%rax
  401fa9:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  401fae:	ba 00 20 00 00       	mov    $0x2000,%edx
  401fb3:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  401fba:	00 
  401fbb:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  401fc0:	e8 af fa ff ff       	callq  401a74 <rio_readlineb>
  401fc5:	48 85 c0             	test   %rax,%rax
  401fc8:	7f 74                	jg     40203e <submitr+0x4d8>
  401fca:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  401fd1:	3a 20 43 
  401fd4:	49 89 07             	mov    %rax,(%r15)
  401fd7:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  401fde:	20 75 6e 
  401fe1:	49 89 47 08          	mov    %rax,0x8(%r15)
  401fe5:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  401fec:	74 6f 20 
  401fef:	49 89 47 10          	mov    %rax,0x10(%r15)
  401ff3:	48 b8 72 65 61 64 20 	movabs $0x7269662064616572,%rax
  401ffa:	66 69 72 
  401ffd:	49 89 47 18          	mov    %rax,0x18(%r15)
  402001:	48 b8 73 74 20 68 65 	movabs $0x6564616568207473,%rax
  402008:	61 64 65 
  40200b:	49 89 47 20          	mov    %rax,0x20(%r15)
  40200f:	48 b8 72 20 66 72 6f 	movabs $0x73206d6f72662072,%rax
  402016:	6d 20 73 
  402019:	49 89 47 28          	mov    %rax,0x28(%r15)
  40201d:	41 c7 47 30 65 72 76 	movl   $0x65767265,0x30(%r15)
  402024:	65 
  402025:	66 41 c7 47 34 72 00 	movw   $0x72,0x34(%r15)
  40202c:	44 89 e7             	mov    %r12d,%edi
  40202f:	e8 cc eb ff ff       	callq  400c00 <close@plt>
  402034:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402039:	e9 f6 01 00 00       	jmpq   402234 <submitr+0x6ce>
  40203e:	4c 8d 84 24 50 80 00 	lea    0x8050(%rsp),%r8
  402045:	00 
  402046:	48 8d 4c 24 2c       	lea    0x2c(%rsp),%rcx
  40204b:	48 8d 94 24 50 60 00 	lea    0x6050(%rsp),%rdx
  402052:	00 
  402053:	be b7 2e 40 00       	mov    $0x402eb7,%esi
  402058:	48 8d bc 24 50 20 00 	lea    0x2050(%rsp),%rdi
  40205f:	00 
  402060:	b8 00 00 00 00       	mov    $0x0,%eax
  402065:	e8 26 ec ff ff       	callq  400c90 <__isoc99_sscanf@plt>
  40206a:	44 8b 44 24 2c       	mov    0x2c(%rsp),%r8d
  40206f:	41 81 f8 c8 00 00 00 	cmp    $0xc8,%r8d
  402076:	0f 84 be 00 00 00    	je     40213a <submitr+0x5d4>
  40207c:	4c 8d 8c 24 50 80 00 	lea    0x8050(%rsp),%r9
  402083:	00 
  402084:	b9 00 2e 40 00       	mov    $0x402e00,%ecx
  402089:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  402090:	be 01 00 00 00       	mov    $0x1,%esi
  402095:	4c 89 ff             	mov    %r15,%rdi
  402098:	b8 00 00 00 00       	mov    $0x0,%eax
  40209d:	e8 7e ec ff ff       	callq  400d20 <__sprintf_chk@plt>
  4020a2:	44 89 e7             	mov    %r12d,%edi
  4020a5:	e8 56 eb ff ff       	callq  400c00 <close@plt>
  4020aa:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4020af:	e9 80 01 00 00       	jmpq   402234 <submitr+0x6ce>
  4020b4:	ba 00 20 00 00       	mov    $0x2000,%edx
  4020b9:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  4020c0:	00 
  4020c1:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  4020c6:	e8 a9 f9 ff ff       	callq  401a74 <rio_readlineb>
  4020cb:	48 85 c0             	test   %rax,%rax
  4020ce:	7f 6a                	jg     40213a <submitr+0x5d4>
  4020d0:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4020d7:	3a 20 43 
  4020da:	49 89 07             	mov    %rax,(%r15)
  4020dd:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  4020e4:	20 75 6e 
  4020e7:	49 89 47 08          	mov    %rax,0x8(%r15)
  4020eb:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4020f2:	74 6f 20 
  4020f5:	49 89 47 10          	mov    %rax,0x10(%r15)
  4020f9:	48 b8 72 65 61 64 20 	movabs $0x6165682064616572,%rax
  402100:	68 65 61 
  402103:	49 89 47 18          	mov    %rax,0x18(%r15)
  402107:	48 b8 64 65 72 73 20 	movabs $0x6f72662073726564,%rax
  40210e:	66 72 6f 
  402111:	49 89 47 20          	mov    %rax,0x20(%r15)
  402115:	48 b8 6d 20 73 65 72 	movabs $0x726576726573206d,%rax
  40211c:	76 65 72 
  40211f:	49 89 47 28          	mov    %rax,0x28(%r15)
  402123:	41 c6 47 30 00       	movb   $0x0,0x30(%r15)
  402128:	44 89 e7             	mov    %r12d,%edi
  40212b:	e8 d0 ea ff ff       	callq  400c00 <close@plt>
  402130:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402135:	e9 fa 00 00 00       	jmpq   402234 <submitr+0x6ce>
  40213a:	80 bc 24 50 20 00 00 	cmpb   $0xd,0x2050(%rsp)
  402141:	0d 
  402142:	0f 85 6c ff ff ff    	jne    4020b4 <submitr+0x54e>
  402148:	80 bc 24 51 20 00 00 	cmpb   $0xa,0x2051(%rsp)
  40214f:	0a 
  402150:	0f 85 5e ff ff ff    	jne    4020b4 <submitr+0x54e>
  402156:	80 bc 24 52 20 00 00 	cmpb   $0x0,0x2052(%rsp)
  40215d:	00 
  40215e:	0f 85 50 ff ff ff    	jne    4020b4 <submitr+0x54e>
  402164:	ba 00 20 00 00       	mov    $0x2000,%edx
  402169:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  402170:	00 
  402171:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  402176:	e8 f9 f8 ff ff       	callq  401a74 <rio_readlineb>
  40217b:	48 85 c0             	test   %rax,%rax
  40217e:	7f 70                	jg     4021f0 <submitr+0x68a>
  402180:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  402187:	3a 20 43 
  40218a:	49 89 07             	mov    %rax,(%r15)
  40218d:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  402194:	20 75 6e 
  402197:	49 89 47 08          	mov    %rax,0x8(%r15)
  40219b:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  4021a2:	74 6f 20 
  4021a5:	49 89 47 10          	mov    %rax,0x10(%r15)
  4021a9:	48 b8 72 65 61 64 20 	movabs $0x6174732064616572,%rax
  4021b0:	73 74 61 
  4021b3:	49 89 47 18          	mov    %rax,0x18(%r15)
  4021b7:	48 b8 74 75 73 20 6d 	movabs $0x7373656d20737574,%rax
  4021be:	65 73 73 
  4021c1:	49 89 47 20          	mov    %rax,0x20(%r15)
  4021c5:	48 b8 61 67 65 20 66 	movabs $0x6d6f726620656761,%rax
  4021cc:	72 6f 6d 
  4021cf:	49 89 47 28          	mov    %rax,0x28(%r15)
  4021d3:	48 b8 20 73 65 72 76 	movabs $0x72657672657320,%rax
  4021da:	65 72 00 
  4021dd:	49 89 47 30          	mov    %rax,0x30(%r15)
  4021e1:	44 89 e7             	mov    %r12d,%edi
  4021e4:	e8 17 ea ff ff       	callq  400c00 <close@plt>
  4021e9:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4021ee:	eb 44                	jmp    402234 <submitr+0x6ce>
  4021f0:	48 8d b4 24 50 20 00 	lea    0x2050(%rsp),%rsi
  4021f7:	00 
  4021f8:	4c 89 ff             	mov    %r15,%rdi
  4021fb:	e8 b0 e9 ff ff       	callq  400bb0 <strcpy@plt>
  402200:	44 89 e7             	mov    %r12d,%edi
  402203:	e8 f8 e9 ff ff       	callq  400c00 <close@plt>
  402208:	41 0f b6 17          	movzbl (%r15),%edx
  40220c:	b8 4f 00 00 00       	mov    $0x4f,%eax
  402211:	29 d0                	sub    %edx,%eax
  402213:	75 15                	jne    40222a <submitr+0x6c4>
  402215:	41 0f b6 57 01       	movzbl 0x1(%r15),%edx
  40221a:	b8 4b 00 00 00       	mov    $0x4b,%eax
  40221f:	29 d0                	sub    %edx,%eax
  402221:	75 07                	jne    40222a <submitr+0x6c4>
  402223:	41 0f b6 47 02       	movzbl 0x2(%r15),%eax
  402228:	f7 d8                	neg    %eax
  40222a:	85 c0                	test   %eax,%eax
  40222c:	0f 95 c0             	setne  %al
  40222f:	0f b6 c0             	movzbl %al,%eax
  402232:	f7 d8                	neg    %eax
  402234:	48 8b 8c 24 58 a0 00 	mov    0xa058(%rsp),%rcx
  40223b:	00 
  40223c:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  402243:	00 00 
  402245:	0f 84 12 01 00 00    	je     40235d <submitr+0x7f7>
  40224b:	e9 08 01 00 00       	jmpq   402358 <submitr+0x7f2>
  402250:	48 b8 45 72 72 6f 72 	movabs $0x52203a726f727245,%rax
  402257:	3a 20 52 
  40225a:	49 89 07             	mov    %rax,(%r15)
  40225d:	48 b8 65 73 75 6c 74 	movabs $0x747320746c757365,%rax
  402264:	20 73 74 
  402267:	49 89 47 08          	mov    %rax,0x8(%r15)
  40226b:	48 b8 72 69 6e 67 20 	movabs $0x6e6f6320676e6972,%rax
  402272:	63 6f 6e 
  402275:	49 89 47 10          	mov    %rax,0x10(%r15)
  402279:	48 b8 74 61 69 6e 73 	movabs $0x6e6120736e696174,%rax
  402280:	20 61 6e 
  402283:	49 89 47 18          	mov    %rax,0x18(%r15)
  402287:	48 b8 20 69 6c 6c 65 	movabs $0x6c6167656c6c6920,%rax
  40228e:	67 61 6c 
  402291:	49 89 47 20          	mov    %rax,0x20(%r15)
  402295:	48 b8 20 6f 72 20 75 	movabs $0x72706e7520726f20,%rax
  40229c:	6e 70 72 
  40229f:	49 89 47 28          	mov    %rax,0x28(%r15)
  4022a3:	48 b8 69 6e 74 61 62 	movabs $0x20656c6261746e69,%rax
  4022aa:	6c 65 20 
  4022ad:	49 89 47 30          	mov    %rax,0x30(%r15)
  4022b1:	48 b8 63 68 61 72 61 	movabs $0x6574636172616863,%rax
  4022b8:	63 74 65 
  4022bb:	49 89 47 38          	mov    %rax,0x38(%r15)
  4022bf:	66 41 c7 47 40 72 2e 	movw   $0x2e72,0x40(%r15)
  4022c6:	41 c6 47 42 00       	movb   $0x0,0x42(%r15)
  4022cb:	44 89 e7             	mov    %r12d,%edi
  4022ce:	e8 2d e9 ff ff       	callq  400c00 <close@plt>
  4022d3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4022d8:	e9 57 ff ff ff       	jmpq   402234 <submitr+0x6ce>
  4022dd:	48 8d 9c 24 50 20 00 	lea    0x2050(%rsp),%rbx
  4022e4:	00 
  4022e5:	48 83 ec 08          	sub    $0x8,%rsp
  4022e9:	48 8d 84 24 58 40 00 	lea    0x4058(%rsp),%rax
  4022f0:	00 
  4022f1:	50                   	push   %rax
  4022f2:	ff 74 24 20          	pushq  0x20(%rsp)
  4022f6:	ff 74 24 30          	pushq  0x30(%rsp)
  4022fa:	4c 8b 4c 24 28       	mov    0x28(%rsp),%r9
  4022ff:	4c 8b 44 24 20       	mov    0x20(%rsp),%r8
  402304:	b9 30 2e 40 00       	mov    $0x402e30,%ecx
  402309:	ba 00 20 00 00       	mov    $0x2000,%edx
  40230e:	be 01 00 00 00       	mov    $0x1,%esi
  402313:	48 89 df             	mov    %rbx,%rdi
  402316:	b8 00 00 00 00       	mov    $0x0,%eax
  40231b:	e8 00 ea ff ff       	callq  400d20 <__sprintf_chk@plt>
  402320:	b8 00 00 00 00       	mov    $0x0,%eax
  402325:	48 c7 c1 ff ff ff ff 	mov    $0xffffffffffffffff,%rcx
  40232c:	48 89 df             	mov    %rbx,%rdi
  40232f:	f2 ae                	repnz scas %es:(%rdi),%al
  402331:	48 89 c8             	mov    %rcx,%rax
  402334:	48 f7 d0             	not    %rax
  402337:	4c 8d 68 ff          	lea    -0x1(%rax),%r13
  40233b:	48 83 c4 20          	add    $0x20,%rsp
  40233f:	4c 89 eb             	mov    %r13,%rbx
  402342:	48 8d ac 24 50 20 00 	lea    0x2050(%rsp),%rbp
  402349:	00 
  40234a:	4d 85 ed             	test   %r13,%r13
  40234d:	0f 85 b6 fb ff ff    	jne    401f09 <submitr+0x3a3>
  402353:	e9 3f fc ff ff       	jmpq   401f97 <submitr+0x431>
  402358:	e8 83 e8 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  40235d:	48 81 c4 68 a0 00 00 	add    $0xa068,%rsp
  402364:	5b                   	pop    %rbx
  402365:	5d                   	pop    %rbp
  402366:	41 5c                	pop    %r12
  402368:	41 5d                	pop    %r13
  40236a:	41 5e                	pop    %r14
  40236c:	41 5f                	pop    %r15
  40236e:	c3                   	retq   

000000000040236f <init_timeout>:
  40236f:	85 ff                	test   %edi,%edi
  402371:	74 22                	je     402395 <init_timeout+0x26>
  402373:	53                   	push   %rbx
  402374:	89 fb                	mov    %edi,%ebx
  402376:	be 46 1a 40 00       	mov    $0x401a46,%esi
  40237b:	bf 0e 00 00 00       	mov    $0xe,%edi
  402380:	e8 bb e8 ff ff       	callq  400c40 <signal@plt>
  402385:	85 db                	test   %ebx,%ebx
  402387:	bf 00 00 00 00       	mov    $0x0,%edi
  40238c:	0f 49 fb             	cmovns %ebx,%edi
  40238f:	e8 5c e8 ff ff       	callq  400bf0 <alarm@plt>
  402394:	5b                   	pop    %rbx
  402395:	f3 c3                	repz retq 

0000000000402397 <init_driver>:
  402397:	55                   	push   %rbp
  402398:	53                   	push   %rbx
  402399:	48 83 ec 28          	sub    $0x28,%rsp
  40239d:	48 89 fd             	mov    %rdi,%rbp
  4023a0:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4023a7:	00 00 
  4023a9:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
  4023ae:	31 c0                	xor    %eax,%eax
  4023b0:	be 01 00 00 00       	mov    $0x1,%esi
  4023b5:	bf 0d 00 00 00       	mov    $0xd,%edi
  4023ba:	e8 81 e8 ff ff       	callq  400c40 <signal@plt>
  4023bf:	be 01 00 00 00       	mov    $0x1,%esi
  4023c4:	bf 1d 00 00 00       	mov    $0x1d,%edi
  4023c9:	e8 72 e8 ff ff       	callq  400c40 <signal@plt>
  4023ce:	be 01 00 00 00       	mov    $0x1,%esi
  4023d3:	bf 1d 00 00 00       	mov    $0x1d,%edi
  4023d8:	e8 63 e8 ff ff       	callq  400c40 <signal@plt>
  4023dd:	ba 00 00 00 00       	mov    $0x0,%edx
  4023e2:	be 01 00 00 00       	mov    $0x1,%esi
  4023e7:	bf 02 00 00 00       	mov    $0x2,%edi
  4023ec:	e8 3f e9 ff ff       	callq  400d30 <socket@plt>
  4023f1:	85 c0                	test   %eax,%eax
  4023f3:	79 4f                	jns    402444 <init_driver+0xad>
  4023f5:	48 b8 45 72 72 6f 72 	movabs $0x43203a726f727245,%rax
  4023fc:	3a 20 43 
  4023ff:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402403:	48 b8 6c 69 65 6e 74 	movabs $0x6e7520746e65696c,%rax
  40240a:	20 75 6e 
  40240d:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402411:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402418:	74 6f 20 
  40241b:	48 89 45 10          	mov    %rax,0x10(%rbp)
  40241f:	48 b8 63 72 65 61 74 	movabs $0x7320657461657263,%rax
  402426:	65 20 73 
  402429:	48 89 45 18          	mov    %rax,0x18(%rbp)
  40242d:	c7 45 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%rbp)
  402434:	66 c7 45 24 74 00    	movw   $0x74,0x24(%rbp)
  40243a:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  40243f:	e9 0c 01 00 00       	jmpq   402550 <init_driver+0x1b9>
  402444:	89 c3                	mov    %eax,%ebx
  402446:	bf c8 2e 40 00       	mov    $0x402ec8,%edi
  40244b:	e8 00 e8 ff ff       	callq  400c50 <gethostbyname@plt>
  402450:	48 85 c0             	test   %rax,%rax
  402453:	75 68                	jne    4024bd <init_driver+0x126>
  402455:	48 b8 45 72 72 6f 72 	movabs $0x44203a726f727245,%rax
  40245c:	3a 20 44 
  40245f:	48 89 45 00          	mov    %rax,0x0(%rbp)
  402463:	48 b8 4e 53 20 69 73 	movabs $0x6e7520736920534e,%rax
  40246a:	20 75 6e 
  40246d:	48 89 45 08          	mov    %rax,0x8(%rbp)
  402471:	48 b8 61 62 6c 65 20 	movabs $0x206f7420656c6261,%rax
  402478:	74 6f 20 
  40247b:	48 89 45 10          	mov    %rax,0x10(%rbp)
  40247f:	48 b8 72 65 73 6f 6c 	movabs $0x2065766c6f736572,%rax
  402486:	76 65 20 
  402489:	48 89 45 18          	mov    %rax,0x18(%rbp)
  40248d:	48 b8 73 65 72 76 65 	movabs $0x6120726576726573,%rax
  402494:	72 20 61 
  402497:	48 89 45 20          	mov    %rax,0x20(%rbp)
  40249b:	c7 45 28 64 64 72 65 	movl   $0x65726464,0x28(%rbp)
  4024a2:	66 c7 45 2c 73 73    	movw   $0x7373,0x2c(%rbp)
  4024a8:	c6 45 2e 00          	movb   $0x0,0x2e(%rbp)
  4024ac:	89 df                	mov    %ebx,%edi
  4024ae:	e8 4d e7 ff ff       	callq  400c00 <close@plt>
  4024b3:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  4024b8:	e9 93 00 00 00       	jmpq   402550 <init_driver+0x1b9>
  4024bd:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  4024c4:	00 
  4024c5:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  4024cc:	00 00 
  4024ce:	66 c7 04 24 02 00    	movw   $0x2,(%rsp)
  4024d4:	48 63 50 14          	movslq 0x14(%rax),%rdx
  4024d8:	48 8b 40 18          	mov    0x18(%rax),%rax
  4024dc:	48 8d 7c 24 04       	lea    0x4(%rsp),%rdi
  4024e1:	b9 0c 00 00 00       	mov    $0xc,%ecx
  4024e6:	48 8b 30             	mov    (%rax),%rsi
  4024e9:	e8 72 e7 ff ff       	callq  400c60 <__memmove_chk@plt>
  4024ee:	66 c7 44 24 02 1f 94 	movw   $0x941f,0x2(%rsp)
  4024f5:	ba 10 00 00 00       	mov    $0x10,%edx
  4024fa:	48 89 e6             	mov    %rsp,%rsi
  4024fd:	89 df                	mov    %ebx,%edi
  4024ff:	e8 dc e7 ff ff       	callq  400ce0 <connect@plt>
  402504:	85 c0                	test   %eax,%eax
  402506:	79 32                	jns    40253a <init_driver+0x1a3>
  402508:	41 b8 c8 2e 40 00    	mov    $0x402ec8,%r8d
  40250e:	b9 88 2e 40 00       	mov    $0x402e88,%ecx
  402513:	48 c7 c2 ff ff ff ff 	mov    $0xffffffffffffffff,%rdx
  40251a:	be 01 00 00 00       	mov    $0x1,%esi
  40251f:	48 89 ef             	mov    %rbp,%rdi
  402522:	b8 00 00 00 00       	mov    $0x0,%eax
  402527:	e8 f4 e7 ff ff       	callq  400d20 <__sprintf_chk@plt>
  40252c:	89 df                	mov    %ebx,%edi
  40252e:	e8 cd e6 ff ff       	callq  400c00 <close@plt>
  402533:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  402538:	eb 16                	jmp    402550 <init_driver+0x1b9>
  40253a:	89 df                	mov    %ebx,%edi
  40253c:	e8 bf e6 ff ff       	callq  400c00 <close@plt>
  402541:	66 c7 45 00 4f 4b    	movw   $0x4b4f,0x0(%rbp)
  402547:	c6 45 02 00          	movb   $0x0,0x2(%rbp)
  40254b:	b8 00 00 00 00       	mov    $0x0,%eax
  402550:	48 8b 4c 24 18       	mov    0x18(%rsp),%rcx
  402555:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  40255c:	00 00 
  40255e:	74 05                	je     402565 <init_driver+0x1ce>
  402560:	e8 7b e6 ff ff       	callq  400be0 <__stack_chk_fail@plt>
  402565:	48 83 c4 28          	add    $0x28,%rsp
  402569:	5b                   	pop    %rbx
  40256a:	5d                   	pop    %rbp
  40256b:	c3                   	retq   

000000000040256c <driver_post>:
  40256c:	53                   	push   %rbx
  40256d:	4c 89 c3             	mov    %r8,%rbx
  402570:	85 c9                	test   %ecx,%ecx
  402572:	74 24                	je     402598 <driver_post+0x2c>
  402574:	be e0 2e 40 00       	mov    $0x402ee0,%esi
  402579:	bf 01 00 00 00       	mov    $0x1,%edi
  40257e:	b8 00 00 00 00       	mov    $0x0,%eax
  402583:	e8 18 e7 ff ff       	callq  400ca0 <__printf_chk@plt>
  402588:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  40258d:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  402591:	b8 00 00 00 00       	mov    $0x0,%eax
  402596:	eb 41                	jmp    4025d9 <driver_post+0x6d>
  402598:	48 85 ff             	test   %rdi,%rdi
  40259b:	74 2e                	je     4025cb <driver_post+0x5f>
  40259d:	80 3f 00             	cmpb   $0x0,(%rdi)
  4025a0:	74 29                	je     4025cb <driver_post+0x5f>
  4025a2:	41 50                	push   %r8
  4025a4:	52                   	push   %rdx
  4025a5:	41 b9 f7 2e 40 00    	mov    $0x402ef7,%r9d
  4025ab:	49 89 f0             	mov    %rsi,%r8
  4025ae:	48 89 f9             	mov    %rdi,%rcx
  4025b1:	ba fb 2e 40 00       	mov    $0x402efb,%edx
  4025b6:	be 94 1f 00 00       	mov    $0x1f94,%esi
  4025bb:	bf c8 2e 40 00       	mov    $0x402ec8,%edi
  4025c0:	e8 a1 f5 ff ff       	callq  401b66 <submitr>
  4025c5:	48 83 c4 10          	add    $0x10,%rsp
  4025c9:	eb 0e                	jmp    4025d9 <driver_post+0x6d>
  4025cb:	66 c7 03 4f 4b       	movw   $0x4b4f,(%rbx)
  4025d0:	c6 43 02 00          	movb   $0x0,0x2(%rbx)
  4025d4:	b8 00 00 00 00       	mov    $0x0,%eax
  4025d9:	5b                   	pop    %rbx
  4025da:	c3                   	retq   
  4025db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000004025e0 <__libc_csu_init>:
  4025e0:	41 57                	push   %r15
  4025e2:	41 56                	push   %r14
  4025e4:	41 89 ff             	mov    %edi,%r15d
  4025e7:	41 55                	push   %r13
  4025e9:	41 54                	push   %r12
  4025eb:	4c 8d 25 1e 18 20 00 	lea    0x20181e(%rip),%r12        # 603e10 <__frame_dummy_init_array_entry>
  4025f2:	55                   	push   %rbp
  4025f3:	48 8d 2d 1e 18 20 00 	lea    0x20181e(%rip),%rbp        # 603e18 <__init_array_end>
  4025fa:	53                   	push   %rbx
  4025fb:	49 89 f6             	mov    %rsi,%r14
  4025fe:	49 89 d5             	mov    %rdx,%r13
  402601:	4c 29 e5             	sub    %r12,%rbp
  402604:	48 83 ec 08          	sub    $0x8,%rsp
  402608:	48 c1 fd 03          	sar    $0x3,%rbp
  40260c:	e8 27 e5 ff ff       	callq  400b38 <_init>
  402611:	48 85 ed             	test   %rbp,%rbp
  402614:	74 20                	je     402636 <__libc_csu_init+0x56>
  402616:	31 db                	xor    %ebx,%ebx
  402618:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40261f:	00 
  402620:	4c 89 ea             	mov    %r13,%rdx
  402623:	4c 89 f6             	mov    %r14,%rsi
  402626:	44 89 ff             	mov    %r15d,%edi
  402629:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40262d:	48 83 c3 01          	add    $0x1,%rbx
  402631:	48 39 eb             	cmp    %rbp,%rbx
  402634:	75 ea                	jne    402620 <__libc_csu_init+0x40>
  402636:	48 83 c4 08          	add    $0x8,%rsp
  40263a:	5b                   	pop    %rbx
  40263b:	5d                   	pop    %rbp
  40263c:	41 5c                	pop    %r12
  40263e:	41 5d                	pop    %r13
  402640:	41 5e                	pop    %r14
  402642:	41 5f                	pop    %r15
  402644:	c3                   	retq   
  402645:	90                   	nop
  402646:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40264d:	00 00 00 

0000000000402650 <__libc_csu_fini>:
  402650:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000402654 <_fini>:
  402654:	48 83 ec 08          	sub    $0x8,%rsp
  402658:	48 83 c4 08          	add    $0x8,%rsp
  40265c:	c3                   	retq   
