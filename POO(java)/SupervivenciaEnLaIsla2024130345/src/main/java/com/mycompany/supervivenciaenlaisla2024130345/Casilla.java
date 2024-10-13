/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.ArrayList;

/**
 *
 * @author Proyecto Diseño
 */
public class Casilla {
    private boolean descubierta;
    private Refugio refugio;
    private ArrayList<Personaje> personajes;
	private Recurso recurso;
    private Animal animal;

    public Casilla() {
        this.descubierta = false;
		this.refugio = null;
		this.personajes = new ArrayList<Personaje>();
		this.recurso = null;
		this.animal = null;
    }

    public boolean isDescubierta() {
        return descubierta;
    }

    public void descubrir() {
        this.descubierta = true;
    }
	public void descubrirSalvaje(){
		if(!this.descubierta){
			this.descubierta = true;
			//Aqui poner para generar materiales, animal, etc, cuando se descubre. TODO
			if(Random.probabilidad(5)){
				if(Random.probabilidad(30)){
					setAnimal(new Animal("Grande"));
				} else {
					setAnimal(new Animal("Pequeño"));
				}
			} else if(Random.probabilidad(15)){
				int num = Random.randomInt(1, 3);
				int cant = Random.randomInt(5, 20);
				if(num == 1){
					setRecurso(new Recurso("Frutas",cant));
				} else if(num == 2){
					setRecurso(new Recurso("Plantas",cant));
				} else{
					setRecurso(new Recurso("Madera",cant));
				}
			}
		}
	}

	public Refugio getRefugio() {
		return refugio;
	}

	public void setRefugio(Refugio refugio) {
		this.refugio = refugio;
	}

	public ArrayList<Personaje> getPersonajes() {
		return personajes;
	}

	public void añadirPersonaje (Personaje personaje){
		personajes.add(personaje);
	}

	public Recurso getRecurso() {
		return recurso;
	}

	public void setRecurso(Recurso recurso) {
		this.recurso = recurso;
	} 

	public Animal getAnimal() {
		return animal;
	}

	public void setAnimal(Animal animal) {
		this.animal = animal;
	}

    
}
