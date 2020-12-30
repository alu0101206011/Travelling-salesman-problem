# El-viajante-de-comercio
El objetivo principal de esta práctica consiste en desarrollar un ejemplo de Algoritmo Voraz (Greedy) como es el viajante de comer. Para ello, se detalla a continuación las clases STL necesarias, los requisitos funcionales mínimos y opcionales, ejemplo de prueba, y los criterios de evaluación.

Clases STL necesarias

Para poder desarrollar más fácilmente el algoritmo del viajante de comer, se puede hacer uso de las siguientes clases de la STL (Standard Template Library):

#include <vector>
#include <list>

std::vector<T>
std::list<T>
También se puede hacer uso de cualquier otra clase STL que suponga una mejora significativa en el desarrollo del algoritmo. Para más información de dichas clases, se puede consultar la siguiente web: cppreference.com. Asimismo, se pueden usar las nuevas características del estándar c++11 del compilador g++, que se activan con la orden de compilación:

$ g++ -std=c++11 ...
Requisitos funcionales mínimos

Para superar la práctica, los requisitos funcionales mínimos exigidos son:

Dada una cierta cantidad n de ciudades (numero real), el algoritmo debe visitar el conjunto de ciudades correcto haciendo que la solución sea mínima.
Dentro del esquema de estrategia voraz, el mejor candidato será el valor más cercano factible que queda en el conjunto de candidatos. Es decir, se deberá explorar el conjunto de candidatos desde la posición de la última ciudad seleccionada, y no desde el principio.
Requisitos funcionales opcionales

Dentro de la evaluación global de la práctica, se valorarán positivamente los siguientes requisitos optativos:

Devolver el camino mínimo. Por ejemplo, si n = 6 ciudades. La solución será devuelta como 7,98 kms, el camino devuelto será S = {1, 4, 6, 2, 3, 5, 1}.
Considerar tanto grafos dirigidos como no dirigidos. ¿Cambia en algo el esquema del algoritmo original al incluir los grafos dirigidos en la solución?
Diseñar un nuevo algoritmo más eficiente.
Evaluación

Se evaluará positivamente los siguientes aspectos:

Presentación en el laboratorio: el grado de funcionamiento de la práctica, y si desarrolla requisitos opcionales o mejoras significativas.
Código subido en la tarea correspondiente a la práctica: buen diseño y limpieza.
Teniendo superados los aspectos anteriormente descritos, una evaluación orientativa sería la siguiente:

Si se desarrolla el algoritmo y se muestra la solución grafos no dirigidos: 5 puntos.
Si se desarrolla un solución y se muestra la solución grafos dirigidos: 7 puntos.
Si se desarrolla un algoritmo más eficiente, valorándose la sencillez (en longitud y comprensión) del diseño propuesto: 10 puntos.

NOTA: Se realizará una sesión explicativa de la práctica el próximo día 7 de enero de 10:00 a 12:00. 

Sesión de explicativa: https://meet.google.com/izk-qhew-fox
