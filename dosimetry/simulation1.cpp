/*
 * SIMULATION OF A PARTICLE ENTERING A MEDIUM
 */

#include <math.h>
#include <stdio.h>

int main(void) {
  int n;
  double m, q, E, ro, Z, A, I, thickness, step;
  double SP, L;

  void enterData(double *m, double *q, double *E, double *ro, double *Z, double *A, double *I, double *thickness, double *step);
  double stoppingPower(double m, double q, double E, double ro, double Z, double A, double I);

  enterData(&m, &q, &E, &ro, &Z, &A, &I, &thickness, &step);
  SP = stoppingPower(m, q, E, ro, Z, A, I);

  /*
    We exit the loop when the particle is stopped in the material (E <= 0) or
    when it leaves the material (L <= 0)
  */
  for(n = 0, L = thickness; L > 0 && E > 0; n++) {
    E = E - SP*step;
    L = thickness - n*step;
  }

  if (E <= 0) {
    printf("\n-------------------------------------------------------------------------------------------");
    printf("\n The particle is stopped inside the material, at %lf m from the exit, in %d steps.\n", L, n);
    printf("\n-------------------------------------------------------------------------------------------");
  }

  if (L <= 0) {
    printf("\n-----------------------------------------------------------------------------");
    printf("\nThe particle exits the material with an energy of %lf MeV in %d steps.", E, n);
    printf("\n-----------------------------------------------------------------------------");
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

double stoppingPower(double m, double q, double E, double ro, double Z, double A, double I) {

  double k = 0.307075;
  double g, b2, T, SP;

  printf("\n|******** Stopping-Power values for this material ********|\n");

  g = 1 + (E/m);
  printf("\n Gamma  =  %lf", g);

  b2 = 1 - (1/(g*g));
  printf("\n Beta squared  =  %lf", b2);

  T = (1.022*b2*g*g) / (1 + 2*g*(0.511/m) + pow(0.511/m,2) );
  printf("\n Maximum kinetic energy transferred  =  %lf MeV ", T);

  SP = ((ro*k*q*q*Z)/(A*b2))*(0.5*log( (1.022*b2*g*g*T) / (I*I) ) - b2);
  printf("\n Stopping Power  =  %lf MeV/cm \n", SP);

  return SP;
}
