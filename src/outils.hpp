#ifndef OUTILS_ALGOS
#define OUTILS_ALGOS



double static const eps = 0.000001;  // constante représente la valeur d'erreur.


double     df                     (double (*f)(double), double X);
double     ddf                    (double (*f)(double), double X);

double     X_MaxFunc              (double (*f)(double), double a, double b);
double     X_i_Max                (double (*f)(double), double a, double b);
double     Fx_i_Max               (double (*f)(double), double a, double b);

double  *  Div_Intervalle         (double a, double b, int n);

double  *  Z_i_Max                (double (*f)(double), double *x_i, int n);




#endif