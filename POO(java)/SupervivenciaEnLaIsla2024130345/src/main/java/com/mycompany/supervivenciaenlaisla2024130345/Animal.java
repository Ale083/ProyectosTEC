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
	private int dificultadCaza;
	private int comidaProporcionada;
	private ImageIcon animalIcon;

	public Animal(String tipoAnimal) {
		this.tipoAnimal = tipoAnimal;
		
	}
	
	
	public void atacarPersonaje(Personaje personaje){
		
	}
	
	public void serCazado(Cazador cazador){
		
	}

	private int setFuerza(String tipoAnimal) {
		return 10; //TODO:
	}

	private int setDificultadCaza(String tipoAnimal) {
		return 10;
	}

	private int setComidaProporcionada(String tipoAnimal) {
		return 10;
	}

	private ImageIcon setAnimalIcon(String tipoAnimal) {
		return new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\AnimalGrande.png");
	}

	public String getTipoAnimal() {
		return tipoAnimal;
	}

	public int getFuerza() {
		return fuerza;
	}

	public int getDificultadCaza() {
		return dificultadCaza;
	}

	public int getComidaProporcionada() {
		return comidaProporcionada;
	}

	public ImageIcon getAnimalIcon() {
		return animalIcon;
	}
	
	
	
	
}
