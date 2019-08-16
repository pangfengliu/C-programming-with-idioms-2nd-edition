/* complex */
#include <stdio.h>
struct complex {
  int real;
  int imag;
};  
typedef struct complex Complex;
/* add */
void addComplex(const Complex *a,
		const Complex *b, Complex *c)
{
  c->real = a->real + b->real;
  c->imag = a->imag + b->imag;
  return;
}
void mulComplex(const Complex *a,
		const Complex *b, Complex *c)
{
  c->real =
    a->real * b->real - a->imag * b->imag;
  c->imag =
    a->real * b->imag + a->imag * b->real;
  return;
}
void printComplex(const Complex *a)
{
  printf("%d+%di\n", a->real, a->imag);
  return;
}
/* main */
int main(void)
{
  Complex a, b, c;

  scanf("%d", &(a.real));
  scanf("%d", &(a.imag));
  scanf("%d", &(b.real));
  scanf("%d", &(b.imag));

  addComplex(&a, &b, &c);
  printComplex(&c);
  mulComplex(&a, &b, &c);
  printComplex(&c);
  return 0;
}
/* end */
