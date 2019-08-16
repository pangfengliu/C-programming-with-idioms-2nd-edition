#include <stdio.h>
int match(int key, int keys[], int n)
{
  for (int i = 0; i < n; i++)
    if (key == keys[i])
	return i;
  return -1;
}
int main()
{
  int keys[] = {3, 4, 6, 2, 8, 10};
  int arraySize = sizeof(keys) / sizeof(int);
  int key;
  scanf("%d", &key);
  printf("%d\n", match(key, keys, arraySize));
  return 0;
}
