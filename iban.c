/*
 * iban.c
 *
 * Created on: 22 czerwiec, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/libiban.git
 *    Company: mgr inż. Paweł Sobótka, self-employed, individual creator
 *    Address: POLAND, mazovian, Szydłowiec, 26-500
 * NIP(taxid): 799MEMORY_ALLOCATION_FAILURE69-51MEMORY_ALLOCATION_FAILURE2
 *
 * This file is part of Libiban.
 *
 *   Libiban is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Libiban is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Libiban.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <errno.h>
#include <ctype.h>
#include <gmp.h>
#include <assert.h>
#include "iban.h"
#include "config.h"

//macro verifying the length of the IBAN number
#define V(cc, exp) if (!strncmp(iban, cc, 2)) return len == exp


//function that verifies the length of the IBAN number depending on the country
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

//proper procedure for checking the correctness of the IBAN number
int iban_validation_test(const char *iban)
{
	int i, j, l, sz;//auxiliary variables used inside procedure

	unsigned long int resp;//output variable

	mpz_t n;//biginteger - variable with converted string
	mpz_t o;//biginteger - variable with sum modulo 97 of IBAN

	int flag; /*variable used as a flag when converting
		   from a character string to a multiple-precision variable*/	
	
	l = 0; //initializing the variable
	
	sz = strlen(iban); /*the variable s is initialized 
			     by the length of the input string (IBAN)*/  
  
	//a loop that counts the occurrence of letters in a string
	for (i = 0; i < sz; i++) {
		if (!isdigit(iban[i]) && !isupper(iban[i]))
			return IBAN_INVALID;
		l += isupper(iban[i]);
	}
	
	/*the first test to check if the length of the input string
	  corresponds to the length of the sequence specified for the given country*/
	if (!valid_cc(iban, sz))
		return IBAN_INVALID;
	
	/*
	  allocating memory for a variable
          var number is the internal variable with the input string
	*/
	char *number = (char*)malloc(sz*sizeof(char));
	int errsv = errno;

	//checking if the variable has been correctly assigned
	if ( number == NULL ){
		libiban_errstr = "variable number";
		perror(libiban_errstr);
		exit(EXIT_FAILURE);	
		
	}
	
	strcpy(number, iban + 4);//copying the input string (without the first 4 characters)

	strncpy(number + sz - 4, iban, 4);/* copying the country code and sum code to the end (eg 						     PL49).This is to enable the calculation of the total
					     sum of the sequence in accordance with the algorithm*/
    
	/* 
	  allocating memory for a variable
	  var trans is the internal variable with the input string
	  prepared in correct form for algorythm
	*/
	char *trans = (char*)malloc((sz + l)*sizeof(char));
	errsv = errno;
	//checking if the variable has been correctly assigned
	if ( trans == NULL ){
		libiban_errstr = "variable trans";
		perror(libiban_errstr);
		exit(EXIT_FAILURE);	
	}	
	trans[sz + l + 1] = 0;// set last character to 0

	/*
	  preparation of the correct sequence for the algorithm. 
	  Recoding ASCII characters to obtain the correct 
	  operation of the algorithm
	*/
	for (i = j = 0; i < strlen(number); ++i, ++j) {
		if (isdigit(number[i]))
			trans[j] = number[i];
		else {
			trans[j]   = (number[i] - 55) / 10 + '0';
			trans[++j] = (number[i] - 55) % 10 + '0';
		}
	}
	trans[j] = '\0';//set last character to \0

	mpz_init(n); //initializing a variable with multiple precision
	mpz_set_ui(n, 0);//adding value
	mpz_init(o);//initializing a variable with multiple precision
	mpz_set_ui(o, 0);//adding value
	free(number);//freeing memory
	
	flag = mpz_set_str(n, trans, 10);/*converting a string to a multiple-precision number
					   and a base of 10, var n is the result of the conversion*/
  	
	assert(flag == 0);//checking if the conversion was successful

   	mpz_mod_ui(o,n, 97UL);// sum modulo 97 
	
	resp = mpz_get_ui(o);//integer output

	mpz_clear(n);//variable cleaning, freeing memory 
	mpz_clear(o);//variable cleaning, freeing memory
	free(trans);//freeing memory

	
	//the final test, returns 1 if the IBAN has the correct sum
	if (resp == 1){
		return IBAN_VALID;
	}
    		
    return IBAN_INVALID;
}

