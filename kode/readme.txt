Hjemmeeksamen C i Linux

Oppgaven var å kunne cracke MD5 passord når man har en hash-verdi.
Alt er skrevet og kjørt under Ubuntu 18.04. I mappen vil man finne det kjørbare-programmet "password_cracker".

For å kompilere:
    Makefile brukes ved å skrive inn "make password_cracker"
    For å fjerne object-filene skriver man inn "make clean"

For å kjøre:
    ./password_cracker 'X' (hvorav X er hash-verdien)



Ved bruk av Valgrind får jeg still reachable: 43 bytes in 1 blocks.
Dette vil jeg ikke se på som en grov feil ettersom "stil reachable" ikke utgjør et
slags problem som ekte minnelekkasjer kan forårsake. Derimot kan jeg ikke åpenhjertet 
si at det er greit at man får "still reachable" under memory-leak checks.

https://stackoverflow.com/questions/3840582/still-reachable-leak-detected-by-valgrind

Her er vedlagt memory-leak test:
==5190== Memcheck, a memory error detector
==5190== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5190== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==5190== Command: ./password_cracker $1$abcdefgh$gINKdZR2ZOFR0hPWcRObD/
==5190== 

Cracker is now running
--------------------------
Starting dictionary attack
--------------------------
Found password: rekrut
==5190== 
==5190== HEAP SUMMARY:
==5190==     in use at exit: 43 bytes in 1 blocks
==5190==   total heap usage: 6 allocs, 5 frees, 5,729 bytes allocated
==5190== 
==5190== 43 bytes in 1 blocks are still reachable in loss record 1 of 1
==5190==    at 0x4C2FA3F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5190==    by 0x4C31D84: realloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5190==    by 0x4E3D970: __md5_crypt (md5-crypt.c:319)
==5190==    by 0x108D23: compare (in /home/osboxes/HE_C/kode/password_cracker)
==5190==    by 0x108DBB: dictionary_attack (in /home/osboxes/HE_C/kode/password_cracker)
==5190==    by 0x108C11: main (in /home/osboxes/HE_C/kode/password_cracker)
==5190== 
==5190== LEAK SUMMARY:
==5190==    definitely lost: 0 bytes in 0 blocks
==5190==    indirectly lost: 0 bytes in 0 blocks
==5190==      possibly lost: 0 bytes in 0 blocks
==5190==    still reachable: 43 bytes in 1 blocks
==5190==         suppressed: 0 bytes in 0 blocks
==5190== 
==5190== For counts of detected and suppressed errors, rerun with: -v
==5190== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
