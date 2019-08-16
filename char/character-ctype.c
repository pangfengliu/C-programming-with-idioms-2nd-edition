#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;
  int digit = 0;
  int vowel = 0;
  int consonant = 0;

  while (scanf("%c", &c) != EOF) {
    if (isdigit(c))
      digit++;
    else if (isalpha(c)) {
      switch (toupper(c)) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
	vowel++;
	break;
      default:
	consonant++;
      }
    }
  };

  printf("%d\n", digit);
  printf("%d\n", vowel + consonant);  
  printf("%d\n", vowel);  
  printf("%d\n", consonant);
  return 0;
}
