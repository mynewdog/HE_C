# Notater rundt hjemmeeksamen

I mappen /etc/ finner man filen shadow som inneholder hashed passord

$1$ indikerer hvilken hash algoritme (MD5 checksum i dette tilfellet) som er brukt. Det grønne er salt, som er skrevet i klartektst. Resterende er hva som vi i oppgaven må løse.

#### MD5 Checksum

~~~
 $id$salt$encrypted

  then instead of using the DES machine, id identifies the
  encryption method used and this then determines how the rest
  of the password string is interpreted.  The following values
  of id are supported:

         ID  | Method
         ─────────────────────────────────────────────────────────
         1   | MD5
         2a  | Blowfish (not in mainline glibc; added in some
             | Linux distributions)
         5   | SHA-256 (since glibc 2.7)
         6   | SHA-512 (since glibc 2.7)
~~~





#### Måter i cracke et passord på 

- Prøve seg fram usannsynlig mange ganger med forskjellige kombinasjoner, også kalt bruteforcing.

  *Smart å gå igjennom de korteste kombinasjonene først* 

- Dictionary attack, hvor man går igjennom en liste med typiske passord-kombinasjoner og bruker disse som input verdier for å finne riktig hash-value.

  *Ved debugging er det lurt å ta et mindre antall passord fra denne listen.*


Filen crypto.c er en C-fil som hasher passord. Ved kompilering må man ha med flagget **l-crypt** ved kompilering for å linke crypto biblioteket.

Manualen for crypt finner man ved å skrive inn **man 3 crypt**. Her finner man ut av hva som må implementeres. Alle instanser av crypt bruker samme minne-lokasjon. Ved bruk av **crypt_r()** kreves det en struktur som du gir den, **struct crypt_data *data**.

Ved multi-threading tar for eksempel én instans alle kombinasjoner som starter med bokstaven 'a', og den andre tar for seg alle andre kombinasjoner som starter med 'b'.