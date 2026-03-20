#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./ substitution key\n");
        return 1;
    }
    if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", toupper(key[plaintext[i] - 'A']));
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", tolower(key[plaintext[i] - 'a']));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
bool is_valid_key(string s)
{
    if (strlen(s) != 26)
        return false;
    int counts[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(s[i]))
            return false;
        int index = toupper(s[i]) - 'A';
        if (counts[index] > 0)
            return false;
        counts[index]++;
    }
    return true;
}
