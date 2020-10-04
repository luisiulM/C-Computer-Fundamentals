#include <stdio.h>
#include <math.h>

struct circle {
	int x;
	int y;
	int radius;
};

// Return 1 if the two circles overlap
int overlap(struct circle *a, struct circle *b)
{
	float dx = a->x - b->x;
	float dy = a->y - b->y;
	float squaredistance = dx*dx + dy*dy;
	float d = sqrtf(squaredistance);
	if (d < a->radius + b->radius) {
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int i, j;
	struct circle c[] = {
		{ x: 2, y: 4, radius: 3 },
		{ x: 6, y: 9, radius: 3 },
		{ x: 5, y: 7, radius: 3 },
		{ x: 2, y: 4, radius: 3 },
		{ x: 2, y: 8, radius: 1 },
		{ x: 7, y: 6, radius: 4 },	
	};
	int numc = sizeof(c) / sizeof(c[0]);
	
	printf("There are %d circles.\n", numc);
	for (i = 0; i < numc; i++) {
		for (j = i+1; j < numc; j++) {
			if (overlap(&c[i], &c[j]))
				printf("Circles %d and %d overlap!\n", i, j);
			else 
				printf("Circles %d and %d do not overlap!\n", i, j);
		}			
	}
	return 0;
}
