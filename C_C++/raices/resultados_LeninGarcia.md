---------------------------------------------
Resultados 1° función
---------------------------------------------
Método | raíz | iteraciones | Observaciones |

Bisección | 0.20164 | 29 | Convergencia estable. La raíz se encuentra dentro del intervalo inicial [0, 1.0]. A partir de la iteración 21, los límites del intervalo y la raíz coinciden debido a la precisión numérica de la impresión en consola. La raíz converge hasta 0.20164.

Falsa posición | 0.20164 | 8 | Convergencia rápida hacia la raíz. Mantiene el intervalo acotado y alcanza la solución en muchas menos iteraciones que bisección.

Brent | 0.20164 | 6 | Convergencia muy rápida y estable. Encontró la raíz en solo 6 iteraciones, manteniendo la solución acotada en el intervalo. Fue más rápido a comparación de falsa posición y bisección.

Newton | 0.20164 | 4 | Convergencia muy rápida, alcanza la raíz con pocas iteraciones. Más rápido que los 3 métodos anteriores

Secante | 0.20164 | 5 | Convergencia rápida, 1 iteración más lento a comparación de Newton

Steffenson | 0.20164 | 4 | Convergencia muy rápida, alcanza la raíz con pocas iteraciones. Igual de rápido que Newton


---------------------------------------------
Resultados 2° función
---------------------------------------------
Método | raíz | iteraciones | Observaciones |

Bisección | 0.567143 | 28 | Convergencia lenta. Mantiene la raíz acotada dentro del intervalo inicial [0, 1.0].

Falsa posición | 0.567143 | 7 | Convergencia rápida. Mantiene la raíz acotada dentro del intervalo inicial y requiere menos iteraciones que la bisección.

Brent | 0.567143 | 6 | Convergencia rápida. Mantiene la raíz acotada, requiere menos iteraciones que la bisección, 1 iteración más rápido que falsa posición.

Newton | 0.567143 | 5 | Convergencia rápida para el valor inicial utilizado (x_inicial = 0.0). Más rápido que los métodos anteriores.

Secante | 0.567143 | 6 | Convergencia rápida. Tomó 1 iteración más a comparación de Newton.

Steffenson | 0.567143 | 5 | Convergencia rápida. Tomó la misma cantidad de iteraciones que Newton.


---------------------------------------------
Resultados 2° función con valores iniciales lejanos (intervalo -5 a 5 y valor inicial 5)
---------------------------------------------
Método | raíz | iteraciones | Observaciones |

Bisección | 0.567143 | 31 | Convergencia lenta. Mantiene la raíz acotada dentro del intervalo inicial [-5.0, 5.0].

Falsa posición | 0.567143 | 10 | Convergencia rápida. Mantiene la raíz acotada dentro del intervalo inicial y requiere menos iteraciones que la bisección.

Brent | 0.567143 | 9 | Convergencia rápida. Mantiene la raíz acotada, requiere menos iteraciones que la bisección, 1 iteración más rápido que falsa posición.

Newton | 0.567143 | 6 | Convergencia rápida para el valor inicial utilizado (x_inicial = 5.0). Más rápido que los métodos anteriores.

Secante | 0.567143 | 7 | Convergencia rápida. Tomó 1 iteración más a comparación de Newton.

Steffenson | 0.567143 | 6 | Convergencia rápida. Tomó la misma cantidad de iteraciones que Newton.
