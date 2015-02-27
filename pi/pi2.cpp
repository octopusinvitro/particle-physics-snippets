/* ------------------------------------
 * PI 2
 * RAND_MAX = 32767
 * The area of a circle is A = PI x r^2
 * If r = 1 --->  A = PI
 * ------------------------------------ */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int ntot, nin, n;
	double r, x, y, xc, yc, PI;

	for(ntot = 1000; ntot <= 1e10; ntot = ntot*10) {

		nin = 0;

		for(n = 0; n <= ntot; n++) {
			x = (double)rand() / (RAND_MAX + 1.0);
			y = (double)rand() / (RAND_MAX + 1.0);

			xc = (2*x) - 1;
			yc = (2*y) - 1;

			r = sqrt( (xc*xc) + (yc*yc) );

			if (r <= 1)
				nin++;
		}

		PI = 4*( (double)nin / (double)ntot );
		printf("\nPI for %d points = %lf\n\n", ntot, PI);

	}

	return 0;
}
