/*
* Dinesh P. Weerapurage 
* Department of Electrical Engineering and Computer Science
* University of Tennessee - Knoxville
* 203 Claxton Complex, 1122 Volunteer Boulevard
* Knoxville, TN 37996-3450 USA 
*
*/

#ifndef __KURUTU_BITOP_H__
#define __KURUTU_BITOP_H__
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long *ULong;
#define BITS_IN_BYTE 8L
#define U_CHAR_L sizeof(unsigned long *)

/* Bit mask for long */  
#define BitMask(bit)                           \
(1L << (((bit) % (BITS_IN_BYTE * U_CHAR_L))))

/* offset to get a bit */   
#define ByteInArray(array, bit)                 \
    (((ULong)(array))[(bit/(U_CHAR_L * BITS_IN_BYTE))])

/* checks whether bit is true */
#define BitIsTrue(array, bit)                   \
    (ByteInArray(array, bit) & BitMask(bit))

/* check whether bit is false */
#define BitIsFalse(array, bit)                  \
    (!(BitIsTrue(array, bit)))

/* set bit to true - 1 */
#define BitTrue(array,bit)                      \
    ((ByteInArray(array,bit) |= BitMask(bit)))

/* set bit to false - 0 */
#define BitFalse(array,bit)                     \
    ((ByteInArray(array,bit) &= ~BitMask(bit)))

/* toggle bit */
#define BitToggle(array,bit)                    \
    ((ByteInArray(array,bit) ^= BitMask(bit)))

/* return 1 if bit is set else 0 */
#define BitValue(array,bit)                     \
    ((BitIsTrue(array,bit) ? 1:0))

/* swapping two values:
   caution: make sure to duplicate variables as they can be changed in 
   this macro. 
*/
#define SWAP(a,b)                               \
    ((a)^=(b), (b)^=(a), (a)^=(b))

/* Find position in bit array. */
#define BITPOS(a,b,n)                           \
    ((b > a ? : SWAP(a,b)),                     \
     a*(2*n-a-1)/2 + (b-a))

#endif  /* __KURUTU_BITOP_H__ */
