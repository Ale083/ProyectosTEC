/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
public class Recurso {
	private String tipo;
	private int cantidad;

	public Recurso(String tipo) {
		this.tipo = tipo;
		this.cantidad = 0;
	}

	public Recurso(String tipo, int cantidad) {
		this.tipo = tipo;
		this.cantidad = cantidad;
	}
	
	
	void usarRecurso(int cantidadUsada){
		if(cantidad > 0){
			cantidad-=cantidadUsada;
		}
	}
	
	void agregarRecurso(int cantidadAgregada){
		cantidad += cantidadAgregada;
	}

	public String getTipo() {
		return tipo;
	}

	public int getCantidad() {
		return cantidad;
	}
	
	
}
