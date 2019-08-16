int main(void)
{
  int i = 0;
  if (!(i == 1)) { printf("Assertion failed: %s, " "file %s, line %d\n", "i == 1", "assert-inf.c", 18); exit(0);};
  return 0;
}
