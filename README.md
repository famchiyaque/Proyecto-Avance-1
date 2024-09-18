# Proyecto-Avance-1

## Simulación **Bingo Americano**!

Qué es un domingo viendo la NFL sin una apuesta?! 
Este proyecto require de un archivo que contiene los guesses de puntajes del usuario, es decir los 5 valores númericos que 
el usuario cree que van a ser puntajes finales de todos los partidos de football americano de la semana, y también uno que contiene los puntajes finales reales de los partidos de esa semana. 
El programa evalúa si al menos 3 de los 5 guesses por el usuario sí fueron puntajes finales reales, para determinar si el usuario ganó o no.

-------------------------------------------------------------
## Lectura
El programa utiliza ifstream para checar la existencia y leer los contenidos del archivo, y los guarda en un vector. 
Se hace esto para ambos archivos, para terminar con un vector de los guesses y de los puntajes reales.

## Ordenamiento
Para este programa, el método de ordenamiento elegido es el merge sort, debido a que entre selection sort, insertion sort, y merge sort, es el más rápido de los 3 en promedio, y en su peor caso (caso que más le puede costar al algoritmo en términos de tiempo). 
Tiene un tiempo de complejidad fijo de **O(n log(n))** siempre, solo al costo de ocupar doble el espacio de memoria que los otros 2, que, para este proyecto, **no es un problema**. 
Los otros dos tienen como promedio un tiempo de complejidad de **O(n^2)**, que para este caso podría funcionar como el dataset es pequeño pero para las buenas prácticas, utilizaremos el método más rapido.

##### Resultado
Al aplicar este sort a ambos vectores, se quedan ordenados y listos para el siguiente fase.

## Evaluación de los Guesses/Búsqueda
Ya que los vectores están ordenados, el programa itera por los valores del vector de guesses del usuario, y para cada valor utiliza el método de **búsqueda binaria** en el vector de los puntajes finales reales para ver si el guess del usuario fue correcto y determinar el score total del usuario. Necesita 3/5 mínimo para ganar. 

También es importante mencionar que la evaluación es sin reemplazo, es decir, si el usuario adivina el puntaje *21* 5 veces, y en un partido sí hubo en equipo que terminó con 21 puntos, ese resultado se quita del vector de puntajes al econtrarse la primer vez. El usuario en ese caso necesitaría que haya 2 equipos más que terminaron con ese valor de puntos para ganar.

Igual que antes, este método de búsqueda es para optimizar el programa en términos del tiempo. La búsqueda secuencial normal tiene un a complejidad de tiempo de **O(n)** (n siendo el número de elementos del vector), mientras que la búsqueda binaria tiene una complejidad de tiempo de **O(log(n))**. 

Si el usuario sí tuvo 3 o más guesses correctos, se imprime a la consola: **"Felicidades! Has ganado!"**.
Si no, le sale un mensaje que le indica las noticias malas.

## Análisis Completo de Tiempo de Complejidad
Tomando en cuenta la lectura del archivo de guesses:
    - despreciable
    
- La lectura de los puntajes:
    - n (cantidad de datos)
    
- El Ordenamiento:
    - n * log(n)
    
- Y la Búsqueda:
    - log(n)

- El programa tiene un tiempo de complejidad de **n * log(n) + log(n)**, que realmente no está tan mal. Esto será cierto aunque los archivos de datos fueran mucho más largos. 
