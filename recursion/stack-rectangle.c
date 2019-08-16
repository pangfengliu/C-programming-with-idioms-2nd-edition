#include <stdio.h>
#include <stdbool.h>
/* paper */
typedef struct paper {
  int width;
  int height;
} Paper;
/* onTop */
bool onTop(Paper a, Paper b)
{
  return
    (a.width <= b.width && a.height <= b.height
     ||
     a.width <= b.height && a.height <= b.width);
}
/* solution */
typedef struct solution {
  int layer;
  int sum;
} Solution;
/* better */
Solution better(Solution a, Solution b)
{
  return
    (a.layer > b.layer ||
     (a.layer == b.layer && a.sum > b.sum)?
     a : b);
}
/* best */
Solution best
(int index, int n, Paper top, Paper papers[],
 Solution solution) 
{
  if (index >= n)
    return solution;
 
  if (onTop(papers[index], top)) {
    Solution placed = {solution.layer + 1,
		       solution.sum + index};
    return better(best(index + 1, n, papers[index],
		       papers, placed),
		  best(index + 1, n, top,
		       papers, solution));
  } else
    return (best(index + 1, n, top,
		 papers, solution));
} 
/* bestEnd */ 
#define BOTTOM 100000
 
void printSolution(Solution solution)
{
  printf("%d %d\n",solution.layer,solution.sum);
}
 
int main()
{
  int n;
  scanf("%d", &n);
  Paper papers[n];
  for (int i = 0; i < n; i++)
    scanf("%d%d", &(papers[i].width),
	  &(papers[i].height));
 
  Paper bottom = {BOTTOM, BOTTOM}; 
  Solution zero = {0, 0}; 
  printSolution(best(0, n, bottom,
		     papers, zero));
  return 0;
}
