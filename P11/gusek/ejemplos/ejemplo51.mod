/*Parametros */
param n;             # Numero de items
param p;             # de los cuales seleccionamos p
set items:={1..n};   # Conjunto enumeracion de items, numerados del 1 al n
param coste{items};  # Coste los items

/*Variables*/
var x{items}, binary;

/*Funcion objetivo*/

minimize Coste_Total: sum{i in items} coste[i]*x[i];

/*Restricciones*/

s.t. justo_p_items: sum{i in items} x[i] = p;

/*Resolver*/
solve;

/* Mostrando resultados*/

display{i in items: x[i]=1 }: x[i]; /*Los x[i] con valor 1*/
display Coste_Total;

/*Datos*/
data;
param n:=10;
param p:=6;
param coste:=
1 3 
2 2 
3 6 
4 3 
5 9 
6 5 
7 8 
8 1 
9 2 
10 6;
end;