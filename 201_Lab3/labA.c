/* Giselle Northy
 * Lab 3 - Part A
 * You can write your
 * answers to Part A
 * questions here or
 * in a separate text
 * file.
 * 
 * 1. Note that the for loop ends when the long and float values diverge. Explain why they diverge by answering
 *  the following:
 * 
 * a) What is the last value that they match.
 * 
 * Answer: 16777216 -> 16777216.000000
 * 
 * b) What would be the next value.
 * 
 * Answer: 16777217 -> 16777216.000000
 * 
 * c) Work out floating point bit pattern for the last and next values.
 * 
 * Answer: First look at whether the number is positive or negative. 
 * If it's negative then the first digit is 1, and 0 for positive
 * Then get exponent bits by taking the bias and add to the exponent. 127 + exponent. In this case 127+24 = 151
 * Then get the significand from a calculator.
 *  
 * Answer 1
 * 
 * 16777216 -> 16777216.000000 = 01001011100000000000000000000000
 * 
 * Answer 2
 * 
 * 16777217 -> 16777216.000000 = 01001011100000000000000000000000
 * 
 * Why are they the same? Because this is 2^24+1 which needs 24 bits in the significand, but we only have 23.
 * This means the least significant bit was rounded to the nearest even. Therefore, we cannot properly represent
 * 16777217 in the floating point bit pattern.
 * 
 * 2. Situation: you're working on a project that needs to generate a large amount of unique ID numbers. 
 * These numbers are positive integers. In order to maintain uniqueness, they are generated by incrementing a nextID variable.
 * A programmer working on a project says the following:
 * 
 * "If we use an int we can only get 2 x 10^9 positive integers. But if we use a float we can get up to 3 x 10^38 ID's! 
 * So why don't we just use a float for the ID values."
 * How do you explain that this is not a good idea. Also, offer a better solution.
 *
 * ANSWER: 
 * 
 * This is not a good idea because floating point numbers have gaps and some integer's won't be represented. 
 * We saw this in the first part of this lab - when numbers went to 16777217 -> 16777216.000000, there was a rounding
 * issue and the new float didn't match the int. In other words, you get less unique numbers when using floating points
 * than with integers.
 * 
 * A better solution would be to use something like an Unsigned long because it will increase the number to 1x10^19. 
 * You will also get the full range of possible integers and won't have gaps like with float.
 */


#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

void lastInt()
{
	float fi = 15000000.0;
	unsigned int i = 15000000; 
	
	for(; fi < 1e32; fi+=1, i+=1)
	{
		printf("%u -> %f\n", i, fi);
		if(i != (int) fi)
		{
		   break;
	    }
	}
}



int main()
{
	
    lastInt();
	
    return 0;
}
