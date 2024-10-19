#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <assert.h>

#define MAX 10240
#define MAX_WORD_COUNT 60000                //we have less than 60000 words
#define MAX_WORD_LENGTH 80                //each word is less than 80 letters

//Using these two global variables can be justified :)
char words[MAX_WORD_COUNT][MAX_WORD_LENGTH];        //2-d array to hold all the words
int word_count = 0;                    //number of words, initilized to 0

//Note the words in the dictionary file are sorted
//This fact could be useful
void read_file_to_array(char *filename)
{
    FILE *fp;

    //open the file for reading
    fp = fopen(filename, "r");
    if(fp==NULL)
    {
        printf("Cannot open file %s.\n", filename);
        exit(-1);
    }
    //make sure when each word is saved in the array words,
    //it does not ends with a '\n'
    //see how this is done using fscanf 
    while(!feof(fp))
        fscanf(fp, "%s\n", words[word_count++]);
    fclose(fp);
}

//TODO
//Test whether a string word is in the dictionary
//Return 1 if word is in the dictionary
//Return 0 otherwise
//Be efficient in implementing this function
//Efficiency is needed to pass test cases in limited time
int in_dict(char *word)
{
    int left = 0;
    int right = word_count;
    while(left <= right)
    {
        int mid = (left + right) / 2; //finds the "middle" word in alphabetical order
        int comparison = strcmp(words[mid], word); //compares the word at middle index to desried word

        if(comparison == 0)
            return 1; //strings are equal, the word is in the dictionary
        else if(comparison < 0)
            left = mid + 1; //the string in the dictionary is lower in alphabet, move bounds up
        else
            right = mid - 1; //the string in the dictionary is higher in alphabet, move bounds down

    }

    return 0;

}

//TODO
//Use key and shift to decrypt the encrypted message
//len is the length of the encrypted message
//Note the encrypted message is stored as an array of integers (not chars)
//The result is in decrypted

void decryption(unsigned char key, unsigned char shift, const int *encrypted, int len, char *decrypted)
{

    for(int i = 0; i < len; i++)
    {
        decrypted[i] = (encrypted[i] ^ key) >> shift; //apply opposite operation to each integer in message
    }

    decrypted[len] = '\0'; //make the last element the NULL character

}

//TODO
//calculate a score for a message msg
//the score is used to determine whether msg is the original message
int message_score(const char *msg)
{

    int score = 0; //the number of words that are in the dictionary

    char *word, *str;

    str = malloc(strlen(msg)+1); //allocate memory for duplicate message
    strcpy(str, msg); //copy the message into the string

    word = strtok(str, " "); //splits str into characters
    while(word != NULL) //loop through words in message
    {
        //printf("Checking word: %s\n", word);  // Debugging print

        for(int i = 0; i <strlen(word); i++) //loop through each character
        {
            if(!isalpha(word[i])) //make sure character is in alphabet
            {
                continue; //keep going if it isn't
            }
            word[i] = tolower(word[i]); //convert to lowercase
        }
        if(in_dict(word))
        {
            score++; //increment score if the word is in dictionary
            //printf("Valid word found: %s, Current score: %d\n", word, score);  // Debugging print
        }
        //printf("%d\n", score);
        word = strtok(NULL, " "); //get the next character
    }
    free(str);
    return score;
}

//search using all the (key, shift) combinations
//to find the original message
//result is saved in message
void search(const int *encrypted, int len, char *message)
{
	char decrypted[MAX];

    int max_score = 0;
    strcpy(message, "");
    for(unsigned char k = 0; k < 255; k++)
    {
        for(unsigned char shift = 0; shift <= 24; shift++)
        {
            decryption(k, shift, encrypted, len, decrypted);
			int score = message_score(decrypted);
			if(score > max_score)
			{	
				max_score = score;
				strcpy(message, decrypted);
			}
        }
    }
}

//TODO
//read the encrypted message from the file to encrypted
//return number of bytes read
int read_encrypted(char *filename, int *encrypted)
{

    FILE *fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Can't open file %s.\n", filename);
        exit(-1);
    }

    int bytes = fread(encrypted, sizeof(int), MAX, fp); //get size of encrypted file in bytes
    fclose(fp);
    return bytes; //the number of bytes
}

//Do not change the main() function
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("%s encrypted-message\n", argv[0]);
		return 0;
	}

	read_file_to_array("dict.txt");

	int encrypted[MAX];
	int len = read_encrypted(argv[1], encrypted);
	
	char message[MAX];
	strcpy(message, "");
	search(encrypted, len, message);
	printf("%s\n", message);
	return 0;
}
