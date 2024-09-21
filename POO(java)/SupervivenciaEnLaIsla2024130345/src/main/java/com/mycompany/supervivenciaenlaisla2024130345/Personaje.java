/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
public abstract class Personaje {
	private String nombre;
	private int nivelEnergia;
	private int nivelSalud;
	//ArrayList<Recurso> inventario;
	//Refugio refugioAsignado
	
	public abstract void accionar();
	public abstract void comer();
	void descansar(){
		
	}
	
	public void reducirEnergia(int cantidad){
		
	}
	
	public void reducirSalud(int cantidad){
		
	}
	
	public void recuperarEnergia(int cantidad){
		
	}
	
	public void recuperarSalud(int cantidad){
		
	}
	
	//compartirRecurso(Personaje receptor, Recurso recurso){}
}
