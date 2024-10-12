/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;
import javax.swing.ImageIcon;
/**
 *
 * @author Proyecto Diseño
 */
public class Animal {
	private String tipoAnimal;
	private int fuerza;
	private int comidaProporcionada;
	private ImageIcon animalIcon;

	public Animal(String tipoAnimal) {
		this.tipoAnimal = tipoAnimal;
		if(tipoAnimal == "Grande"){
			fuerza = 10;
			comidaProporcionada = 10;
			animalIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\AnimalGrande.png");
		} else {
			fuerza = 5;
			comidaProporcionada = 5;
			animalIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\AnimalPequeno.png");
		}
	}
	
	
	public void atacarPersonaje(Personaje personaje){
		personaje.reducirSalud(fuerza);
	}
	
	public void serCazado(Cazador cazador){
		cazador.añadirAInventario(new Recurso("Carne",comidaProporcionada));
		cazador.getCasillaActual().setAnimal(null);
	}

	public String getTipoAnimal() {
		return tipoAnimal;
	}

	public int getFuerza() {
		return fuerza;
	}

	public int getComidaProporcionada() {
		return comidaProporcionada;
	}

	public ImageIcon getAnimalIcon() {
		return animalIcon;
	}
	
	
	
	
}
