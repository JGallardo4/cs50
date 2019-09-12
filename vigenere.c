#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_alpha_string(string s);
void get_ciphertext(string plaintext, string keyword);
int get_shift_val(char c);
char shift(char c, int shift_val);

int main(int argc, string argv[])
{
    // Check for single alphabetical string as input
    if (argc != 2 || !is_alpha_string(argv[1]))
    {
        printf("Usage: ./vignere keyword\n");
        return 1;
    }
    
    string plaintext = get_string("plaintext: ");    
    
    printf("ciphertext: ");
    
    get_ciphertext(plaintext, argv[1]);
}

// Check that a string is alphabetical
bool is_alpha_string(string s)
{    
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    
    return true;
}

// Convert plaintext to ciphertext using a keyword and Vignere's cipher
void get_ciphertext(string plaintext, string keyword)
{
    int keyword_pointer = 0;
    
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            printf("%c", shift(plaintext[i], keyword[keyword_pointer]));
            
            if (keyword_pointer + 1 >= strlen(keyword))
            {
                keyword_pointer = 0;
            }
            else
            {
                keyword_pointer++;
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }        
    }
    
    printf("\n");
}

// Returns the shift value based on char c
// Example: x -> 23
int get_shift_val(char c)
{
    if (c > 96 && c < 123)
    {
        return c - 97;
    }
    else if (c > 64 && c < 124)
    {
        return c - 65;
    }
    else
    {
        return -1;
    }
}

char shift(char c, int shift_val)
{
    shift_val = get_shift_val(shift_val);
    int final_shift = shift_val + c;
    
    char result = -1; 
    
    if (c > 64 && c < 91)
    {
        if (final_shift > 90)
        {
            result = (final_shift - 90) + 64;
        }
        else
        {
            result = final_shift;
        }
    }
    else if (c > 96 && c < 123)
    {
        if (final_shift > 122)
        {
            result = (final_shift - 122) + 96;
        }
        else
        {
            result = final_shift;
        }
    }
    
    return result;
}
