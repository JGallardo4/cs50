// Uses Caesar's cypher to encript a string of text
#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool check_key(string s);
void rotate(int key, string plaintext);

int main(int argc, string argv[])
{
    if (argc != 2 || (argc == 2 && (!check_key(argv[1]))))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    string plaintext = get_string("plaintext: ");
    
    int key = atoi(argv[1]);
    
    printf("ciphertext: ");
    
    rotate(key, plaintext);
    
    printf("\n");
}

// Checks that the key contains only numbers
bool check_key(string s)
{
    bool result = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            result = false;
        }
    }
    return result;
}

// Prints the ciphertext one character at a time
void rotate(int key, string plaintext)
{
    key = key % 26;
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
            } 
            else if (isupper(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
            }           
        } 
        else
        {
            printf("%c", plaintext[i]);
        } 
    }
}
