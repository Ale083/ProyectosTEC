/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
public class SupervivenciaEnLaIsla2024130345 {

    public static void main(String[] args) {
        /*
		Refugio puede ser una lista con personajes
		Recursos puede ser una clase.
		
		Explorador:
		Ir a terreno cubierto, puede encontrar recursos ocultos, etc. Donde vaya el explorador es donde se explora poco a poco.
		Explorar(): descubrir nuevas áreas y recursos. La energía disminuye en función de distancia recorrida. de 15 a 30 puntos por exploración exitosa.
		recolectar durante exploración; además de explorar, el explorador puede recolectar recursos que encuente en nuevas áreas. 5 puntos por cada recurso recolectado. Comparte función con recolector.
		Explorar y recolectar son separadas.
		
		Área de juego como una matriz. capacidad de exploración es el radio de celdas que puede explorar.
		
		Cazador:
		Caza animales y defiende al grupo.
		Acciones:
			Cazar animales:Tiene costo energetico y puede afecta la salud del cazador si el aimal es grande o peligroso. Si el animal es agresivo, puede perder entre 10 y 20 puntos de salud.
			Defenderse de ataques: El cazador es encargado de defender a los personajes si son atacados. 25 puntos de energia, entre 15 y 30 puntos de salud dependiendo del tipo de animal. GRANDE O PEQUEÑO.
		
		...
		
		Constructor:
		Su habilidad para utilizar los materiales recolectados determina la estabilidad de los refugios.
		NO CREAR HERRAMIENTA.
		
		Curandero:
		Responsable de curar a los personajes heridos o enfermos, usando planas medicinales recolectadas por el o el recolector.
		él tambien puede recolectar.
		
		Cientifico:
		Crear medicamentos. Si los perosnajes se enferman, e lcientifico puede investigar y desarrollar medicamentos que curan enfermedades más graves que los remedios del curandero.
		
		Refugio: 
		La estructura donde los personajes pueden descansar y protegerse de eventos climaticos o ataques.
		Materiales puede haber una sola necesario, depende de uno.
		
		Recurso:
		tipo (comida, agua, material, medicina).
		Cantidad.
		
		Animal:
		Representa animales que cazador puede atrapar o los que atacan personajes.
		
		
		Eventos climaticos:
		durante tormentas, los personajes en refugio seguro pierden menos energia y salud.
		
		Si un animal salvaje ataca, el cazador defiende el grupo. Si falla o no tiene suficiente energia, otros personajes pueden ser heridos.
		
		
		Enfermedades y lesiones:
		Los personajes puede enfermarse por exposicion a climas extremos. El curandero debe intervenir para evitar que la enfermedad se agrave. El cientifica puede desarrollar medicamentos.
		las lesiones provocadas por ataques de animales o accidentes, deben ser tratadas rápidamente por el curandero para evitar que afecten la capacidad de trabajo del personaje herido. Si no se tratan adecuadamente, la salud del personaje seguirá disminuyendo.
		
		Sistema de enrgia:
		
		Acciones que consumen energia: recolectar, cazar, explorar ... (ver la tabla más facil).
		
		Salud: lo mismo, ver la tabla.
		
		//CADA DIA SI NO ESTAN EN REGUGIO PIERDEN 15 DE ENERGIA Y 10 DE SALUD.
		
		Nosotros controlamos a los personajes como al entorno. Jugamos de ambos bandos, nosotros somos dios.
		
		Los animales, después de atacar, se mueren.
		
		No hay random, hay que hacer como un dashboard para que digamos la gente se enferme, se accidente, etc. 
		LO ÚNICO RANDOM ES QUE CUANDO SE DESCUBRE UNA ZONA, LO QUE HAY AHÍ. además que el dios puede poner cosas ahí.
		
		
		Dios:
		En general el dios puede:
			Enviar tormentas
			Enviar animales a atacar el refugio.
			Hacer aparecer recursos especificos en algun lugar del plano.
			Hacer aparecer animales en algún lugar para ser cazados.
			Pasar de día (llevar contador de los días).
		
		
		En la clase personajes, debe tener un arraylist de evento.
		Tiene un timestamp, y un string de que les pasó.
		
		
		
		
		
		*/
    }
}
