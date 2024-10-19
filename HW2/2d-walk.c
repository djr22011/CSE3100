#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.

	int grid = 2 * n+1; //number of spots on the grid
	int visited[grid][grid]; //array that keeps track of visitied spots

	//makes every space unvisited
	for(int i = 0; i < grid; i++)
		for(int j = 0; j < grid; j++)
			visited[i][j] = 0;

	int x = n;
	int y = n;
	visited[x][y] = 1; //starts at the origin
	int spaces_visited = 1; //counts how many spaces we have visited

	while(x > 0 && x < grid - 1 && y > 0 && y < grid - 1) //keeps the walk between the edges
	{
		int r = rand() % 4; //random number to determine direction
		if(r == 0)
			y++;
		else if(r == 1)
			x++;
		else if(r == 2)
			y--;
		else
			x--;

		//marks the space as visited if it is still in bounds
		if(x > 0 && x < grid - 1 && y > 0 && y < grid - 1)
		{
			if(visited[x][y] == 0)
			{
				visited[x][y] = 1;
				spaces_visited += 1;
			}	
		}
	}

	int spaces = (grid - 2) * (grid - 2); //number of spaces on the grid
	return (double) spaces_visited / spaces; //gives the fraction of spaces visited
	
}

//Do not change the code below
int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}