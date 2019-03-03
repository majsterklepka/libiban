/*
 * iban.h
 *
 * Created on: 31 październik, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/libiban.git
 *    Company: mgr inż. Paweł Sobótka, self-employed
 *    Address: POLAND, mazovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
 *
 */

#ifndef IBAN_H_
#define IBAN_H_

#define RETURN_CODE_VALID	0
#define RETURN_CODE_INVALID	1

int iban_validation_test(const char *iban);



#endif /* IBAN_H_ */
