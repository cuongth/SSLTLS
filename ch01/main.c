#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base64.h"

int main( int argc, char *argv[] ) {
  int len, decode_len, nopad;
  len = strlen( argv[1] );
  nopad = (len*4)/3;
  if (nopad & 0x03) {
    decode_len = nopad + (4 - (nopad % 4));
  } else {
    decode_len = nopad;
  }
  char *output = (char *) malloc( decode_len );
  base64_encode(argv[1], len, output);
  printf( "encode: %s\n", output );
  
  char *decode = (char *) malloc( len + 1 );
  base64_decode( output, decode_len, decode );
  printf("decode: %s\n", decode );

  free( output );
  free( decode );

  return 0;
}

/*
 * ./main cuong:1234
 * encode: Y3Vvbmc6MTIzNA==
 * decode: cuong:1234
 *
 */
