/*
 * SIMULATION OF A PARTICLE ENTERING A MEDIUM
 */

#include <math.h> 
#include <stdio.h> 

int main(void) {
	int n;
	double m, q, E, ro, Z, A, I, thickness, step;
	double G, B, t, SP, sp = 0, spa = 0, range = 0, L;

	/* Stopping-Power values for air */
	double  SPa,
			roa = 0.001205,
			Za = 7.2838,
			Aa = 14.5911,
			Ia = 0.0000857;

	void enterData(double *m, double *q, double *E, double *ro, double *Z, double *A, double *I, double *thickness, double *step);
	double stoppingPower(double m, double q, double E, double ro, double Z, double A, double I, double *G, double *B, double *t);
	void writeData(double G, double B, double t, double sp);

	enterData(&m, &q, &E, &ro, &Z, &A, &I, &thickness, &step);

	/* We exit the loop when the particle is stopped in the material (E <= 0) or when it leaves the material (range >= thickness) */
	for(n = 0; range < thickness && E > 0; n++) {
		SP = stoppingPower(m, q, E, ro, Z, A, I, &G, &B, &t);
		sp += SP;
		E = E - SP*step;
		range += step;
	}

	printf("\n|******** Stopping-Power values for this material ********|\n");

	if (E <= 0) {
		writeData(G, B, t, sp);			
		printf("\n--------------------------------------------------------------");
		printf("\n The particle is stopped inside the material, in %d steps.", n);
		printf("\n Range in the medium  =  %lf cm. ", range);
		printf("\n--------------------------------------------------------------");
	}

	if (range >= thickness) {
		writeData(G, B, t, SP); 
		printf("\n-----------------------------------------------------------------------------");
		printf("\nThe particle exits the material with an energy of %lf MeV in %d steps.", E, n);
		printf("\n-----------------------------------------------------------------------------");
				  
		printf("\n\n|******** Stopping-Power data for air ********|\n");
		while(E > 0.04) {
			SPa = stoppingPower(m, q, E, roa, Za, Aa, Ia, &G, &B, &t);
			spa += SPa;
			E = E - SPa*step;
			range += step;
			n++;	/* We keep the number of steps in the material and add the new ones */
		}	 
			
		writeData(G, B, t, spa); 
		printf("\n-----------------------------------------------------------------------------------");
		printf("\nThe particle is stopped in air with a total range of %lf cm in %d steps.", range, n);
		printf("\n-----------------------------------------------------------------------------------");
	}		
		
	printf("\n** If more precision is needed, introduce a shorter step size.\n\n\n");
	
	return 0;
}

void enterData(double *m, double *q, double *E, double *ro, double *Z, double *A, double *I, double *thickness, double *step) {

	double a, b, c, d, e, f, g, h, i;
	
	printf("\nSIMULATION OF A PARTICLE ENTERING A MEDIUM \n");
	printf("\n\n|******** PARTICLE DATA ********| \n");
	
	printf("\n Mass (MeV/c2): ");
	scanf("%lf", &a);
	*m = a;
	
	printf("\n Charge (in units of e): ");
	scanf("%lf", &b);
	*q = b;
	
	printf("\n Initial kinetic energy (MeV): ");
	scanf("%lf", &c);
	*E = c;
	
	printf("\n\n|********* MEDIUM DATA *********| \n");
	
	printf("\n Density (g/cm3): ");
	scanf("%lf", &d);
	*ro = d;
	
	printf("\n Atomic number: ");
	scanf("%lf", &e);
	*Z = e;
	
	printf("\n Mass number: ");
	scanf("%lf", &f);
	*A = f;
	
	printf("\n Ionization Potential (MeV): ");
	scanf("%lf", &g);
	*I = g;
	
	printf("\n Medium thickness (cm): ");
	scanf("%lf", &h);
	*thickness = h;
	
	printf("\n Step size (cm): ");
	scanf("%lf", &i);
	*step = i;
}

double stoppingPower(double m, double q, double E, double ro, double Z, double A, double I, double *G, double *B, double *t) {

	double k = 0.307075;
	double g, b2, T, SP;

	g = 1 + (E/m);
	*G = g; 

	b2 = 1 - (1/(g*g));
	*B = b2;

	T = (1.022*b2*g*g) / (1 + 2*g*(0.511/m) + pow(0.511/m,2) );
	*t = T;

	SP = ((ro*k*q*q*Z)/(A*b2))*(0.5*log( (1.022*b2*g*g*T) / (I*I) ) - b2);

	return SP;
}
	
void writeData(double G, double B, double t, double sp) {
	printf("\n Gamma  =  %lf", G);
	printf("\n Beta squared  =  %lf", B);
	printf("\n Maximum kinetic energy transferred  =  %lf MeV ", t);
	printf("\n Stopping Power  =  %lf MeV/cm \n", sp);
}
