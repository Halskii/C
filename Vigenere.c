// James Hall
// Spring 2018
// Vigenere Cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void encrypt_FUNC(const char *input_MES, const char *final_KEY, const int key_L, const int mes_L);
void decrypt_FUNC(const char *input_MES, const char *final_KEY, const int key_L, const int mes_L);


int main(void) {

    bool c_CRYPT;
    char ans, key_STOR[64], final_KEY[64], input_MES[128];
	 int i, j, key_L, mes_L;

	 while(1) {

// Determines Which Function Will Be Used Later
		printf("Will We Be Encrypting Or Decrypting? 0 To Exit\n");
		ans = getchar();

		switch(ans) {

        case 'e':
        c_CRYPT = 1;
        break;

        case 'E':
        c_CRYPT = 1;
        break;

        case 'd':
        c_CRYPT = 0;
        break;

        case 'D':
        c_CRYPT = 0;
        break;

        default:
        printf("Program Exited");
        return 0;

       }

// Grabs Text To Process
    printf("Please Enter A Sentence To Be Processed\n");
        getchar();
        fgets( input_MES, 128, stdin );
        mes_L = strlen(input_MES);

// Grabs User Key
    printf("Please Enter A Encryption Key\n");
        fgets( key_STOR, 64, stdin );
        key_L = strlen(key_STOR);


    for(i = 0, j = 0; i < mes_L - 1; i++, j++) {
        if(j == key_L -1 )
            j = 0;
        final_KEY[i] = key_STOR[j];
    }
// Updates Key Length
    key_L = strlen(final_KEY);

// Determines Which Function To Enter
    if(c_CRYPT == 1)
        encrypt_FUNC(input_MES, final_KEY, key_L, mes_L);
    else
        decrypt_FUNC(input_MES, final_KEY, key_L, mes_L);

    printf("\n\n");

}

return 0;

}

void encrypt_FUNC(const char *input_MES, const char *final_KEY, const int key_L, const int mes_L) {

   int i, j;
   char encrypted_MES[128];

// Encrypts Message
    for( i = 0, j = 0; i < mes_L, j < mes_L - 1; i++, j++) {
        if( j == key_L )
            j = 0;
        encrypted_MES[i] = (((input_MES[i] - 32 ) + ((final_KEY[j] - 32 ))) % 95) + 32;

    }

    printf("Your Encrypted Message Is As Follows:\n");
    for( i = 0; i < mes_L-1; i++)
        printf("%c", encrypted_MES[i]);

}

void decrypt_FUNC(const char *input_MES, const char *final_KEY, const int key_L, const int mes_L) {


   int i, j;
   char decrypted_MES[128];

// Decrypts Message
    for( i = 0, j = 0; i < mes_L, j < mes_L; i++, j++) {
        decrypted_MES[i] = (((input_MES[i]) - (final_KEY[j])+95) % 95)+32;
    }

    printf("Your Decrypted Message Is As Follows:\n");
    for( i = 0; i < mes_L - 1; i++)
        printf("%c", decrypted_MES[i]);

}
