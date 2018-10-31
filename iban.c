/*
 * iban.c
 *
 *  Created on: 22 Jun 2018
 *      Author: Paweł Sobótka
 *     License: GPL-3.0 
 *   Copyright: ©2017-2018 Paweł Sobótka all rights reserved	
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gmp.h>
#include <assert.h>
#include "iban.h"
#include "config.h"

#define V(cc, exp) if (!strncmp(iban, cc, 2)) return len == exp
 
int valid_cc(const char *iban, int len)
{
    V("AL", 28); V("AD", 24); V("AT", 20); V("AZ", 28); V("BE", 16); V("BH", 22); V("BA", 20); V("BR", 29);
    V("BG", 22); V("CR", 21); V("HR", 21); V("CY", 28); V("CZ", 24); V("DK", 18); V("DO", 28); V("EE", 20);
    V("FO", 18); V("FI", 18); V("FR", 27); V("GE", 22); V("DE", 22); V("GI", 23); V("GR", 27); V("GL", 18);
    V("GT", 28); V("HU", 28); V("IS", 26); V("IE", 22); V("IL", 23); V("IT", 27); V("KZ", 20); V("KW", 30);
    V("LV", 21); V("LB", 28); V("LI", 21); V("LT", 20); V("LU", 20); V("MK", 19); V("MT", 31); V("MR", 27);
    V("MU", 30); V("MC", 27); V("MD", 24); V("ME", 22); V("NL", 18); V("NO", 15); V("PK", 24); V("PS", 29);
    V("PL", 28); V("PT", 25); V("RO", 24); V("SM", 27); V("SA", 24); V("RS", 22); V("SK", 24); V("SI", 19);
    V("ES", 24); V("SE", 24); V("CH", 21); V("TN", 24); V("TR", 26); V("AE", 23); V("GB", 22); V("VG", 24);
 
    return 0;
}


int iban_validation_test(const char *iban)
{
	int i, j, l, sz;
	unsigned long int resp;
	mpz_t n;//biginteger
	mpz_t o;//biginteger
	int flag;
	l = 0;
	
	sz = strlen(iban);   
  
	for (i = 0; i < sz; i++) {
		if (!isdigit(iban[i]) && !isupper(iban[i]))
			return 0;
		l += isupper(iban[i]);
	}

	if (!valid_cc(iban, sz))
		return 0;

	char *number = (char*)malloc(sz*sizeof(char));
	if ( number == 0 ){
		fprintf(stderr, "virtual memory exceeded!\n");
		return -1;
	}	
	strcpy(number, iban + 4);
	strncpy(number + sz - 4, iban, 4);
    
	char *trans = (char*)malloc((sz + l)*sizeof(char));
	if ( trans == 0 ){
		fprintf(stderr, "virtual memory exceeded!\n");
		return -1;	
	}	
	trans[sz + l + 1] = 0;

	for (i = j = 0; i <strlen(number); ++i, ++j) {
		if (isdigit(number[i]))
			trans[j] = number[i];
		else {
			trans[j]   = (number[i] - 55) / 10 + '0';
			trans[++j] = (number[i] - 55) % 10 + '0';
		}
	}
	trans[j] = '\0';

	mpz_init(n);
	mpz_set_ui(n, 0);
	mpz_init(o);
	mpz_set_ui(o, 0);
	free(number);
	
	flag = mpz_set_str(n, trans, 10);
  	assert(flag == 0);

   	mpz_mod_ui(o,n, 97UL);// sum modulus
	
	resp = mpz_get_ui(o);//integer output

	mpz_clear(n);
	mpz_clear(o);
	free(trans);

	if (resp == 1){
		return 1;
	}
    		
    return 0;
}

