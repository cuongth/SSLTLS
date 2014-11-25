#ifndef DES_H
#define DES_H

#define DES_BLOCK_SIZE 8 // 64 bits, defined in the standard
#define DES_KEY_SIZE 8 // 56 bits used, but must supply 64 (8 are ignored)
#define EXPANSION_BLOCK_SIZE 6
#define PC1_KEY_SIZE 7
#define SUBKEY_SIZE 6

void des_encrypt( const unsigned char *plaintext,
    const int plaintext_len, unsigned char *ciphertext,
    unsigned char *iv,
    const unsigned char *key );


void des_decrypt( const unsigned char *ciphertext,
    const int ciphertext_len, unsigned char *plaintext,
    unsigned char *iv,
    const unsigned char *key );

#endif
