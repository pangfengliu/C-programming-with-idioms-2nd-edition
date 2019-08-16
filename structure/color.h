struct color {
  int r;
  int g;
  int b;
};
typedef struct color Color;

void initColor(Color *c, int r, int g, int b); 
Color averageColor(Color c[], int n); 
double brightness(Color *c);
void printColor(Color *c); 
