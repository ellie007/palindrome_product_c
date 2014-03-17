#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void reverse_string(char *str) {
	// find the length of the string
	int string_len = strlen(str);
	int counter;
	char *begin, *end, temp;
	begin = str;

	// initialize end pointer - points to the end of the string
	end = str;
	for (counter = 0; counter < (string_len - 1); counter++){
		end++;}

	// do the reversion character by character
	for (counter = 0; counter < string_len/2; counter++){
		temp = *end;
		*end = *begin;
		*begin = temp;

		begin++;
		end--;
	}
	return;
}


bool is_palindrome(int x, int y){
	int product = x * y;

	// convert product into a string
	char product_str[20];
	sprintf(product_str, "%d", product);

	// reverse the string
	// printf("Original string: %s\n", product_str);
	reverse_string(product_str);
	// printf("Reversed string: %s\n\n", product_str);

	// convert reversed string back to integer
	int reversed_product = atoi(product_str);

	return (reversed_product == product);
}


int main(){
	int i, j, highest_answer = 0;

	for (i=100; i <= 999; i++){
		for (j=100; j <= 999; j++){
			if (is_palindrome(i, j)){
				if (i * j > highest_answer) {highest_answer = i * j;}
			}
		}
	}
	printf("%d\n", highest_answer);
	return highest_answer;
}


