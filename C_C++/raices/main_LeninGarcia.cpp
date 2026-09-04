// Lenin Enrique García Caraballo
// Para cambiar de método, se debe pasar el parámetro por consola al llamar el ejecutable (por ejemplo ./raices 2)

#include <iostream>
#include <iomanip> 
#include <cmath> 
#include <cstdlib>   // Para usar std::atoi 
#include <gsl/gsl_roots.h> 
#include <gsl/gsl_errno.h> 

// Función f(x) = x^3 - 5x + 1 
// Si se desea cambiar por la segunda función, se cambia por: exp(-x) - x;
double f(double x, void *params) {
    return x*x*x - 5.0*x + 1.0;     // exp(-x) - x;
}

// Derivada de la función (requerida para métodos abiertos)
// Si se desea cambiar por la segunda función, se cambia por: -exp(-x) - 1;
double df(double x, void *params) { 
    return 3.0 * x * x - 5.0;     // -exp(-x) - 1;
}

// Combinación de ambas (requerida para métodos abiertos)
void fdf(double x, void *params, double *y, double *dy) { 
    *y = f(x, params); 
    *dy = df(x, params); 
}

int main(int argc, char *argv[]) {

    // Variable para seleccionar el método a ejecutar por la terminal.

    // Cerrados (del 1 al 3): 1) Bisección, 2) Posición falsa, 3) Brent
    // Abiertos (del 4 al 6): 4) Newton, 5) Secante, 6) Steffenson

    int metodo = 1; // Bisección por defecto si no se pasa argumento

    // Se lee el parámetro pasado por consola (por ejemplo ./raices 2)
    if (argc > 1) {
        metodo = std::atoi(argv[1]); // Convierte el argumento de texto a número entero
    }

    // Código para métodos cerrados (Bisección, Posición falsa y Brent)
    // Requieren un intervalo [x_lo, x_hi] que encierre a la raíz
    if (metodo >= 1 && metodo <= 3) {
        const gsl_root_fsolver_type *T; // Guarda el tipo de algoritmo de GSL a utilizar
        gsl_root_fsolver *s;            // Instancia del solver de métodos cerrados
        gsl_function F;                 // Estructura GSL que contiene la función f(x)
        
        F.function = &f;
        F.params = nullptr;             
        
        // Intervalo inicial de búsqueda [0.0, 1.0]
        double x_lo = 0.0;
        double x_hi = 1.0;

        // Selección del algoritmo en GSL según la variable 'metodo'
        if (metodo == 1) {
            T = gsl_root_fsolver_bisection;
            std::cout << "Método Cerrado: Bisección\n";
        }
        else if (metodo == 2) {
            T = gsl_root_fsolver_falsepos;
            std::cout << "Método Cerrado: Posición falsa\n";
        }
        else if (metodo == 3) {
            T = gsl_root_fsolver_brent;
            std::cout << "Método Cerrado: Brent\n";
        }

        s = gsl_root_fsolver_alloc(T);           // Asigna memoria en GSL para el solver
        gsl_root_fsolver_set(s, &F, x_lo, x_hi); // Inicializa el solver con la función y el intervalo
        
        std::cout << "iter\t" << "inf\t" << "sup\t" << "raíz\n";

        int status;
        int iter = 0;
        int max_iter = 100; // Límite de iteraciones para que el programa no se quede en un bucle infinito
        double r;

        // Bucle de iteración para encontrar la raíz
        do {
            iter++;
            status = gsl_root_fsolver_iterate(s); // Calcula el siguiente paso del algoritmo
            r = gsl_root_fsolver_root(s);        // Extrae la aproximación de la raíz
            x_lo = gsl_root_fsolver_x_lower(s);  // Obtiene el nuevo límite inferior
            x_hi = gsl_root_fsolver_x_upper(s);  // Obtiene el nuevo límite superior
            
            std::cout << iter << "\t" << x_lo << "\t" << x_hi << "\t" << r << "\n"; 
            
            // Criterio de parada: comprueba si el intervalo es menor a la tolerancia (1e-8)
            status = gsl_root_test_interval(x_lo, x_hi, 0.0, 1e-8);
        } while(status == GSL_CONTINUE && iter < max_iter); // Repite mientras no haya convergido

        std::cout << "\nRaiz encontrada = " << r << std::endl; 
        gsl_root_fsolver_free(s); // Libera la memoria utilizada por el solver
    }

    // Código para métodos abiertos (Newton, Secante y Steffenson)
    // Parten de un único valor inicial usando derivadas
    else if (metodo >= 4 && metodo <= 6) {
        const gsl_root_fdfsolver_type *T; // Tipo de algoritmo GSL que usa derivadas (fdf)
        gsl_root_fdfsolver *s;             // Instancia del solver de métodos abiertos
        gsl_function_fdf F;                // Estructura que envuelve f(x), f'(x) y fdf(x)
        
        F.f = &f;
        F.df = &df;
        F.fdf = &fdf;
        F.params = nullptr;

        double x_inicial = 0.0; // Valor inicial para arrancar la búsqueda

        // Selección del algoritmo en GSL según la variable 'metodo'
        if (metodo == 4) {
            T = gsl_root_fdfsolver_newton;
            std::cout << "Método Abierto: Newton\n";
        }

        else if (metodo == 5) {
            T = gsl_root_fdfsolver_secant;
            std::cout << "Método Abierto: Secante\n";
        }

        else if (metodo == 6) {
            T = gsl_root_fdfsolver_steffenson;
            std::cout << "Método Abierto: Steffenson\n";
        }

        s = gsl_root_fdfsolver_alloc(T);           // Asigna memoria en GSL para el solver

        gsl_root_fdfsolver_set(s, &F, x_inicial);   // Inicializa el solver con la función y el valor inicial

        std::cout << "iter\t" << "raiz\n";

        int status;
        int iter = 0;
        int max_iter = 100; // Límite de iteraciones para que el programa no se quede en un bucle infinito
        double r0; 
        double r = x_inicial; 

        // Bucle de iteración para encontrar la raíz
        do {
            iter++;
            status = gsl_root_fdfsolver_iterate(s); // Calcula la siguiente aproximación
            r0 = r;                                 // Guarda la estimación de la iteración anterior
            r = gsl_root_fdfsolver_root(s);         // Obtiene la nueva aproximación calculada
            
            std::cout << iter << "\t" << r << "\n";
            
            // Criterio de parada: comprueba si la diferencia entre |r - r0| es menor a 1e-8
            status = gsl_root_test_delta(r, r0, 0.0, 1e-8);
        } while(status == GSL_CONTINUE && iter < max_iter); // Repite mientras no haya convergido

        std::cout << "\nRaiz encontrada = " << r << std::endl; 
        gsl_root_fdfsolver_free(s); // Libera la memoria utilizada por el solver
    } 
    else {
        std::cout << "Error: Ingresa un método válido (1-6)." << std::endl;
    }

    return 0;
}