#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//es como clientes que quieren comprar monstruos.
//Los tipos son solo para darle algo agradable a la progra, no van a hacer nada malo
//se fabrican con energía, materia y maldad.
//Si alguna combinación no existe, se crea un monstruo defectuoso
/*
Tipos de energía:
	Oscura
	Cosmica
	Elemental
	
Tipos de material:
	Orgánico
	Metálico
	Radioactivo

Tipos de maldad:
	Despiadada
	Astuta
	Caótica

La fabrica:
Va a haber cola de pedido de clientes. 
Cada semaforo tiene un numero que dice los segundos que tarda el componente.
Debe tener un control de play para iniciar, pausa y detener para terminar.
Las colas deben tener un n de m, que sería cuantos elementos tiene del máximo. por ejemplo 5 de 20. y el m debe ser configurable.
Algunos componentes tienen una bitacora de historial de lo que paso por ellos.
Se coloca un archivo txt con los pedidos.
La fabrica empiez aen las fuentes, las fuentes son aleatorias, cada una tiene un semaforo con x segundos.
Cada fuente tiene una cola. 

Cuando se combinan si no hace ninguna combinación, hace un monstruo defectuoso.
Los monstruos defectuosos tienen que tener la combinación que se hizo, la hora/fecha que se hizo, y tiene que ser lista ordenada.

Si van por el camino bueno, se pone en la cola de monstruos, que debe llevar historial.
Luego el horno debe consumir de la cola de monstruos, tiene un tiempo de horneado y 4 bandejas, cada bandeja puede tener una capacidad de x.
El horno empieza a hornear cuando está lleno. El tiempo de horneado es general para todas las bandejas. Debe tener historial
Una vez están los monstruos se ponen en una cola para la calidad. 
En la calidad hay 2 robots que ven su calidad, debe ser random. Si lo descarta, se va al basurero de monstruos. 
El robot 2 solo ve lo que el robot 1 aceptó. Debe tener historial.
Luego se va al almacén, que es una lista de monstruos disponibles para ser entregados, no se puede borrar de ahí, sino como tener un atributo entregado o no. 
Luego se va a la entrega, cada x segudos va a la cola de pedidos de clientes, y entrega el pedido primero o con mayor prioridad.

Mientras no se le quite monstruos al primero, se puede entregar a otros.
Por ejemplo el primer escoge un inteligente, seundo inteligente y veneno y tercero teconologia.
No podemos quitarle el inteligente al primer para darselo al segundo, pero si tenemos uno de tecnologia, podemos darselo a él.

Info del monstruo:
Todos deben llevar una bitácora con todo lo que ha pasado con ellos:
	Consecutivo: numero único
	Combinación que lo creo
	Timestamp de creación (cuando se puso en cola).
	Tipo
	Timestamp de inicio y final de horneado
	Bandeja donde se horneó.
	Inspector que los revisó
	Si es bueno, debe indicar por combinación o rechazo.
	Si está en almacén o entregado.
	Si está entregado a cual pedido del cliente y el timestamp de la entrega.
	
	Fuentes de materia prima:
	Cada n segundos producen un bien aleatoriamente, los n segundos son configurables en tiempo real.
	Cada fuentes deposita lo fabricado en una cola que tienen. Esa cola tiene capacidad, si se llena para.
	
	Combinación:
	Coge el frente de las 3 colas.
	El componente de combinación tiene controles de play y pausa, además debe tener tiempo que tarda en crear en segundos.
	La combinación coloca los monstruos en la cola de monstruos por fabricar.
	
	Basurero de defectuosos:
	Es una lista. Representarlos como una lista doble.
	Debe tener consecutivo, combinación, timestamp y si fue por inspección.
	Debe ser posible ver el basurero, ordenado de mas reciente a mas antiguo.
	
	Cola de monstruos:
	El horno tomará de esta cola los monstruos que debe procesar.
	Debe tener un histórico de los monstruos que pasaron por ella y los que están en ella....
	
	Horno:
	Tiene un tiempo de horneado general para todos.
	Tiene 4 bandejas, cada una con capacidad independiente y configurable.
	Cada una se puede detener de manera independiente.
	Solo puede iniciar cuando las bandejas están llenar.
	Debe llevar una bitacora que debe poder consultarse.
	Debe poder verse que tiene el horno y sus bandejas en tiempo real.
	
	Calidad:
	Es una cola con los monstruos horneados.
	Se revisaran de uno en uno, dos veces.
	Cada supervisor tiene probabilidad entre 0 y 100 de rechazo, configurable para cada inspetor en tiempo real.
	Los rechazados van al basurero, indicando motivo por que son buenos (inspección), el inspector que lo descalificó y el tiempo que se dio el descarte.
	Cada inspector debe llevar una bitacora.
	Ls inseptores tiene controles de play y pausa.
	
	Almacén:
	Un deposito con capacidad ilimitada.
	Una lista de libre acceso, sin orden.
	El almacen tiene bitacora, debe reflejar que entro al almacen y si está aun en el deposito o si fue entregado. Es decir no se debe elminiar.
	
	Entregas:
	Salidas del almacén. Tiene un semáfoto pero no configuración de tiempos, se entrega inmediatamente. La unica forma que se entregue es porque existen pedidos pendientes por suplir y en el almacén entro el monstruo que s epued eentregar.
	Las entregas deben atender una cola de pedidos de os clietes, que se va llenando conforma se coloca un pedido (archivo en la carpeta).
	Es posible que deba atender pedidos con prioridad, no solo la cola común.
	Las entrega afectan la info de los monstruos y el almacen, pued generan más info: salen del almacen, se asocian a un pedido y cliente y tienen hora de entrega.
	
	Pedidos:
	Debe habilitar una carpeta donde se coloque un txt con la información de los monstruos que se desean comprar, además de la indetificación del cliente y si es de prioridad.
	Formato:
	Linea 1: nombre del cliente
	Linea 2: clave de prioridad, si dice 1st progra, debe considerar el pedido como de prioridad.
	linea 3: numero de pedido, cualquiera, puede repetirse.
	Lineas 4+: Cada linea a partir de la 4, debe tener el nombre de un tipo de monstruo, no hay limite y puede repetir.
	Otra prioridad es que si el primer pedido de la cola o prioridad no puede ser completado aún, podrá ir a los siguientes pedidos para entregarlos, siempre que no le quiten al pedido inicial.
	Los pedidos tienen bitacora, que indiquen la info del pedido, si está pendiente o si se entregó y a que hora y fecha.
	
	Profe a mi no me quedó claro, la entrega espera para que digamos si un cliente quiere 3 de diferentes tipos, espera a que el almacén tenga esos 3 tipos para entregarlo, o puede ir entregando uno por uno?
	

*/
int main(int argc, char** argv) {
	return 0;
}
