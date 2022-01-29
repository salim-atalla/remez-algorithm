#ifndef MATRICE_ALGOS
#define MATRICE_ALGOS



double  *  creer_Matrice_Vide     (int n, int m);
double  *  construire_Martrice_A  (int n, int m, double *x_i);
double  *  creer_Vecteur_Vide     (int n);
double  *  construire_Vecteur_C   (double (*f)(double), double *z_i, int n);

double  *  mult_Matrice           (double *A, double *B, int n, int m);
double  *  sub_Matrice            (double *A, double *B, int n, int m);

double  *  gauss                  (double *A, double *V, int n);


#endif