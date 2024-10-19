#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
	int x = 0, y = 0, z = 0; //start at the origin
	for(int i = 0; i < n; i++)
	{
		int move = rand()%6;

		if(move == 0)
			x--; //left
		else if (move == 1)
			x++; //right
		else if (move ==2)
			y++; //forward
		else if(move == 3)
			y--; //backwards
		else if( move == 4)
			z++; //up
		else if (move == 5)
			z--; //down
	}

	grid[(x + n) * (2 * n + 1) * (2 * n + 1) + (y + n) * (2 * n + 1) + (z + n)]++;
	//Each x value has a corresponding y and z pair. Each y has a corresponding z.
	//Z has already been assigned an x and y by the end

}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
	//count = particles in radius, total = all particles
	int count = 0, total = 0;
	double radius = r*n;
	int size = 2 * n + 1;

	//go through grid
    for (int x = -n; x <= n; x++)
	{
		for (int y = -n; y <= n; y++) 
		{
			for (int z = -n; z <= n; z++)
			{
				int index = (x + n) * size * size + (y + n) * size + (z + n); //give each space an index
				total += grid[index]; //adds particles to total
			}
		}
	}

	//find the particles within the radius (-radius to positive)
	for (int x = -radius; x <= radius; x++)
	{
		for (int y = -radius; y <= radius; y++) 
		{
			for (int z = -radius; z <= radius; z++)
			{
				int index = (x + n) * size * size + (y + n) * size + (z + n);
				if(x*x + y*y + z*z <= radius*radius)
					count += grid[index]; //adds points that are within the radius to our count
			}
		}
	}
            
    return count / total;
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
	int size = 2 * n + 1;
	int *grid = (int*)calloc(size * size * size, sizeof(int)); //enough memory for integer at x y and z

	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
	//fill in some code below

	free(grid);
	
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}