/*
 * myBank.h
 *
 *  Created on: 19 Nov 2019
 *      Author: ofir
 */

#ifndef MYBANK_H_
#define MYBANK_H_

#define arrayLength 2
#define arrayWidth 50
#define firstArraySlot 0
#define lastArraySlot 49
#define NineHunderedAndOne 901 //this is the first account number. I use this to make the numbers I check more easy to understand, as the array slots are from 0 to 49.

void Open();

void Biror();

void Deposit();

void Withdrawal();

void Close();

void Interest();

void Printing();

void Exiting();

void changeNextAccount();


#endif /* MYBANK_H_ */
