# Hjemmeeksamen i C programmering - Erik Valderhaug

Oppgaven var å kunne cracke MD5 passord når man har en hash-verdi.
Alt er skrevet og kjørt under Ubuntu 18.04. I mappen vil man finne det kjørbare-programmet "password_cracker".

For å kompilere:
    Makefile brukes ved å skrive inn "make password_cracker"
    For å fjerne object-filene skriver man inn "make clean"

For å kjøre:
    ./password_cracker 'X' (hvorav X er hash-verdien)

