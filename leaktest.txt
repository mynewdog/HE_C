==8625== Memcheck, a memory error detector
==8625== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8625== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8625== Command: ./cracker $1$abcdefgh$Jwp6Q/QKKhKcyWQ5xPTCB.
==8625== 
Searching for password in the dictionary
==8625== Conditional jump or move depends on uninitialised value(s)
==8625==    at 0x4C32D08: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8625==    by 0x4E3D951: __md5_crypt (md5-crypt.c:315)
==8625==    by 0x108BC5: compare (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108C93: dictionary_attack (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108AF9: main (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625== 
Password was not found in dictionary.

Starting brute force attack
==8625== Conditional jump or move depends on uninitialised value(s)
==8625==    at 0x4C32D08: strlen (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8625==    by 0x4E3D951: __md5_crypt (md5-crypt.c:315)
==8625==    by 0x108BC5: compare (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108D16: permutations (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108DD4: brute_force_attack (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108B39: main (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625== 
Found hash: $1$abcdefgh$Jwp6Q/QKKhKcyWQ5xPTCB.
The password is: hei
==8625== 
==8625== HEAP SUMMARY:
==8625==     in use at exit: 76 bytes in 2 blocks
==8625==   total heap usage: 5 allocs, 3 frees, 5,748 bytes allocated
==8625== 
==8625== 33 bytes in 1 blocks are still reachable in loss record 1 of 2
==8625==    at 0x4C31B25: calloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8625==    by 0x108D8E: brute_force_attack (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108B39: main (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625== 
==8625== 43 bytes in 1 blocks are still reachable in loss record 2 of 2
==8625==    at 0x4C2FA3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8625==    by 0x4C31D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==8625==    by 0x4E3D970: __md5_crypt (md5-crypt.c:319)
==8625==    by 0x108BC5: compare (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108C93: dictionary_attack (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625==    by 0x108AF9: main (in /home/osboxes/Documents/HE_C/kode/cracker)
==8625== 
==8625== LEAK SUMMARY:
==8625==    definitely lost: 0 bytes in 0 blocks
==8625==    indirectly lost: 0 bytes in 0 blocks
==8625==      possibly lost: 0 bytes in 0 blocks
==8625==    still reachable: 76 bytes in 2 blocks
==8625==         suppressed: 0 bytes in 0 blocks
==8625== 
==8625== For counts of detected and suppressed errors, rerun with: -v
==8625== Use --track-origins=yes to see where uninitialised values come from
==8625== ERROR SUMMARY: 51636 errors from 2 contexts (suppressed: 0 from 0)
