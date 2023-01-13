#include <stdio.h>
int main() {
    char c;
  int flag=0;
    int lowercase_vowel, uppercase_vowel;
    printf("Enter an alphabet: ");
    scanf("%c", &c);

    // evaluates to 1 if variable c is a lowercase vowel
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c==     'u')
    {
      flag=1;      
    }

    // evaluates to 1 if variable c is a uppercase vowel
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
      flag=1;
    }

    // evaluates to 1 (true) if c is a vowel
    if (flag==1)
        printf("%c is a vowel.", c);
    else
        printf("%c is a consonant.", c);
    return 0;
}
