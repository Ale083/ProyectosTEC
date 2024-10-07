/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.ArrayList;
import javax.swing.ImageIcon;

/**
 *
 * @author Proyecto Diseño
 */
public abstract class Personaje {
	private String nombre;
	private int nivelEnergia;
	private int nivelSalud;
	private ArrayList<Recurso> inventario;
	private Refugio refugioAsignado;
	private ImageIcon personajeIcon;

	public Personaje(String nombre, ImageIcon personajeIcon) {
		this.nombre = nombre;
		nivelEnergia = 100;
		nivelSalud = 100;
		inventario = new ArrayList<Recurso>();
		refugioAsignado = null;
		this.personajeIcon = personajeIcon;
	}
	
	
	
	public abstract void accionar();
	public abstract void comer();
	public abstract void descansar();
	
	public void reducirEnergia(int cantidad){
		if(nivelEnergia-cantidad<0){
			nivelEnergia=0;
		} else{
			nivelEnergia-=cantidad;
		}
	}
	
	public void reducirSalud(int cantidad){
		if(nivelSalud-cantidad<0){
			nivelSalud=0;
		} else{
			nivelSalud-=cantidad;
		}
	}
	
	public void recuperarEnergia(int cantidad){
		if(nivelEnergia+cantidad>100){
			nivelEnergia=100;
		} else{
			nivelEnergia+=cantidad;
		}
	}
	
	public void recuperarSalud(int cantidad){
		if(nivelSalud+cantidad>100){
			nivelSalud=100;
		} else{
			nivelSalud+=cantidad;
		}
	}
	
	public void compartirRecurso(Personaje receptor, Recurso recurso){
		
	}

	public String getNombre() {
		return nombre;
	}

	public int getNivelEnergia() {
		return nivelEnergia;
	}

	public int getNivelSalud() {
		return nivelSalud;
	}

	public ArrayList<Recurso> getInventario() {
		return inventario;
	}

	public Refugio getRefugioAsignado() {
		return refugioAsignado;
	}

	public ImageIcon getPersonajeIcon() {
		return personajeIcon;
	}

	public void entrarARefugio(Refugio refugioAsignado) {
		this.refugioAsignado = refugioAsignado;
	}
	
	public void salirDeRefugio(){
		this.refugioAsignado = null;
	}
	
	
	
}
