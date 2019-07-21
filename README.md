# Project libiban
Smart library designed for test iban number

The libiban library was prepared to verify the IBAN bank account number. Verification is done by calculating the check sum. In order to carry out the verification, the library uses the operation of great precision on huge numbers. For this purpose, the gmp library is used.

Initially, the library was an integral part of the Bank Cash Deposit application, and this repository isolates this library from the BaCaDe project.

to build run first: 

```
./bootstrap
```
next
```
./configure
```
next
```
make
```
to install run:
```
sudo make install
```

Package delivery pkg-config definition file too.

## Usage

To configure your source with library, use pkg-config
```
gcc main.c -o main `pkg-config --cflags --libs Libiban`
```

_mgr inż. Paweł Sobótka_

