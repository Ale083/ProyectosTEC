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
	private Recurso[] inventario = new Recurso[4];
	private Refugio refugioAsignado;
	private ImageIcon personajeIcon;
	private int xActual;
	private int yActual;
	private int xDestino;
	private int yDestino;
	private Mapa mapa;

	public Personaje(String nombre, ImageIcon personajeIcon,int x, int y, Mapa mapa) {
		this.nombre = nombre;
		nivelEnergia = 100;
		nivelSalud = 100;
		refugioAsignado = null;
		this.personajeIcon = personajeIcon;
		xDestino = -1;
		yDestino = -1;
		xActual = x;
		yActual = y;
		this.mapa = mapa;
		inventario[0] = new Recurso("Carne");
		inventario[1] = new Recurso("Frutas");
		inventario[2] = new Recurso("Plantas");
		inventario[3] = new Recurso("Madera");
	}
	
	
	
	public abstract void accionar();
	public abstract void descansar();
	
	public void comer(int posEnInv){
		if(inventario[posEnInv].getCantidad() > 0){
			inventario[posEnInv].usarRecurso(1);
			if (posEnInv == 0){
				recuperarEnergia(20);
			} else if(posEnInv == 1){
				recuperarEnergia(10);
			}
		}
	}
	public boolean isMoving(){
		return xDestino != -1 && yDestino != -1;
	}
	
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

	public Recurso[] getInventario(){
		return inventario;
	}
	
	public void añadirAInventario(Recurso recurso){
		for (int i = 0; i < 3; i++) {
			if(inventario[i].getTipo().equals(recurso.getTipo())){ 
				inventario[i].agregarRecurso(recurso.getCantidad());
				break; //Si ya lo encontró, entonces ya no hace falta que revise otros tipos.
			}
		}
	}

	public Refugio getRefugioAsignado() {
		return refugioAsignado;
	}

	public ImageIcon getPersonajeIcon() {
		return personajeIcon;
	}

	public void setRefugio(Refugio refugioAsignado) {
		this.refugioAsignado = refugioAsignado;
	}
	
	

	public int getxDestino() {
		return xDestino;
	}

	public void setxDestino(int xDestino) {
		this.xDestino = xDestino;
	}

	public int getyDestino() {
		return yDestino;
	}

	public void setyDestino(int yDestino) {
		this.yDestino = yDestino;
	}

	public int getxActual() {
		return xActual;
	}

	public void setxActual(int xActual) {
		this.xActual = xActual;
	}

	public int getyActual() {
		return yActual;
	}

	public void setyActual(int yActual) {
		this.yActual = yActual;
	}
	
	public Casilla getCasillaActual(){
		return mapa.getCasilla(yActual, xActual);
	}
	
	public void setDestino(int x, int y){
		this.xDestino = x;
		this.yDestino = y;
	}

	public Mapa getMapa() {
		return mapa;
	}
	
	public boolean tieneCarne(){
		if(inventario[0].getCantidad() != 0){
			return true;
		}
		return false;
	}
	
	public boolean tieneFrutas(){
		if(inventario[1].getCantidad() != 0){
			return true;
		}
		return false;
	}
	
	public boolean tienePlantas(){
		if(inventario[2].getCantidad() != 0){
			return true;
		}
		return false;
	}
	
	public boolean tieneMadera(){
		if(inventario[3].getCantidad() != 0){
			return true;
		}
		return false;
	}

	@Override
	public String toString() {
		return nombre;
	}
	
	
	
}
