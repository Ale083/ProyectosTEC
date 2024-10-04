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
    private ArrayList<Recurso> recursos;
    private Animal animal;
//    private Evento eventoActual; 

    public Casilla() {
        this.descubierta = false;
		this.refugio = null;
		this.personajes = new ArrayList<Personaje>();
		this.recursos = new ArrayList<Recurso>();
		this.animal = null;
		//TODO: Cuando se genera la casilla, ponerle un 20% chance maybe de que genere materiales, luego otro rng para ver cuantos y asi.
    }

    public boolean isDescubierta() {
        return descubierta;
    }

    public void descubrir() {
        this.descubierta = true;
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

	public ArrayList<Recurso> getRecursos() {
		return recursos;
	}

	public void setRecursos(ArrayList<Recurso> recursos) {
		this.recursos = recursos;
	}

	public Animal getAnimal() {
		return animal;
	}

	public void setAnimal(Animal animal) {
		this.animal = animal;
	}

    
}
