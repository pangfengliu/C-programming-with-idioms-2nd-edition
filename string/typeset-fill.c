#include <stdio.h>
#include <string.h>
#include <assert.h>

void flush_line(char words_in_line[20][80], int width, int word_count, 
		int total_word_length)
{
  int space = width - total_word_length;
  int nhole = word_count - 1;
  assert(nhole > 0);
  int extra_space = space % nhole;
  int i, j;
  
  printf("%s", words_in_line[0]); // The first word
  for (i = 1; i < word_count; i++) {
    for (j = 0; j < space / nhole; j++)
      printf(" ");
    if (extra_space > 0 && i - 1 < extra_space)
      printf(" ");
    printf("%s", words_in_line[i]);
  }
  printf("\n");
}

int main(void)
{
  char word[80];
  char words_in_line[20][80];
  int current_char_count = 0;
  int word_count = 0;
  int width;

  scanf("%d", &width);
  while (scanf("%s", word) != EOF) {
    if ((current_char_count + word_count - 1) + (strlen(word) + 1) > width) {
      flush_line(words_in_line, width, word_count, current_char_count);
      word_count = 0;
      current_char_count = 0;
    }
    strcpy(words_in_line[word_count++], word);
    current_char_count += strlen(word);
  }
  if (word_count > 0)
    flush_line(words_in_line, width, word_count, current_char_count);
  return 0;
}

