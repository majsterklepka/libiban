/*
 * iban.h
 *
 * Created on: 31 październik, 2018
 *    License: GPLv3 or later
 *     Author: Paweł Sobótka <48721262935pl@gmail.com>
 *  Copyright: © Paweł Sobótka, 2017-2019, all rights reserved
 *        URL: https://github.com/majsterklepka/libiban.git
 *    Company: mgr inż. Paweł Sobótka, self-employed, individual creator
 *    Address: POLAND, mazovian, Szydłowiec, 26-500
 * NIP(taxid): 799-169-51-12
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

#ifndef IBAN_H_
#define IBAN_H_

#define IBAN_VALID			0
#define IBAN_INVALID			1

char *libiban_errstr;

int iban_validation_test(const char *iban);



#endif /* IBAN_H_ */
