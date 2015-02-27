/* ------------------------------------
 * PI 3
 * RAND_MAX = 32767
 * The area of a circle is A = PI x r^2
 * If r = 1 --->  A = PI
 * ------------------------------------ */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE *fp;
	char name[40];
	int ntot, nin, n;
	double r, x, y, xc, yc, PI;

	printf("\nName of output file: ");
	scanf("%s", name);
	fp = fopen(name, "w");

	for (ntot = 1e4; ntot <= 2e5; ntot = ntot + 1e4) {

		nin = 0;

		for(n = 0; n <= ntot; n++ ) {
			x = (double)rand() / (RAND_MAX + 1.0);
			y = (double)rand() / (RAND_MAX + 1.0);

			xc = (2*x) - 1;
			yc = (2*y) - 1;

			r = sqrt( (xc*xc) + (yc*yc) );

			if (r <= 1)
				nin++;
		}

		PI = 4*( (double)nin / (double)ntot );
		printf("\nPI for %d points: %lf", ntot, PI);
		fprintf(fp, "%d %lf\n", ntot, PI);
	}

	printf("\n");
	fclose(fp);

	return 0;
}
