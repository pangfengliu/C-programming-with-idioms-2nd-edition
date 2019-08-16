#include <stdio.h>
#include <assert.h>

#define N 80
#define M 1024

int main(void)
{
  char infilename[N];
  char outfilename[N];
  FILE *infp, *outfp;
  char buffer[M];
  int count = 1;
  int k, n;
  
  scanf("%s", infilename);
  scanf("%d", &k);
  infp = fopen(infilename, "rb");

  assert(infp != NULL && k <= M);

  while ((n = fread(buffer, 1, k, infp)) > 0) {
    sprintf(outfilename, "%s.%d", infilename, count);
    outfp =  fopen(outfilename, "wb");
    assert(outfp != NULL);
    fwrite(buffer, 1, n, outfp);
    fclose(outfp);
    count++;
  } 
  return 0;
}
