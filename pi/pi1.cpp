/* ------------------------------------
 * PI 1
 * RAND_MAX = 32767
 * The area of a circle is A = PI x r^2
 * If r = 1 --->  A = PI
 * ------------------------------------ */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void) {

	int ntot, nin, n;
	double r, x, y, xc, yc, PI;

	ntot = 1e8; /* Square area A =  1 x 1 = 1  */
	nin  = 0;   /* Circle area A = PI x r = PI */

	for(n = 0; n <= ntot; n++) {

		// Random number generation (0 <= rand < 1)
		// with a uniform probability distribution
		x = (double)rand() / (RAND_MAX + 1.0);
		y = (double)rand() / (RAND_MAX + 1.0);

		// Center the circle in the origin of coordinates
		xc = (2*x) - 1;
		yc = (2*y) - 1;

		r = sqrt( (xc*xc) + (yc*yc) );

		if (r <= 1)
			nin++;
	}

	PI = 4*( (double)nin / (double)ntot );
	printf("\nPI = %lf\n\n", PI);

	return 0;
}
