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
public class Explorador extends Personaje{
	private int nivelExploracion;
	
	public Explorador(int x, int y, Mapa mapa) {
		super("Explorador", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Explorador.png"),x,y, mapa);
		this.nivelExploracion = 3; //TODO, maybe que sea random.
	}

	public void recolectar(){
		if(getNivelEnergia() == 0){
			return;
		}
		reducirEnergia(5);
		if(getCasillaActual().getRecurso() == null){
			return;
		}
		añadirAInventario(getCasillaActual().getRecurso());
		getCasillaActual().setRecurso(null);
	}
	
	public void explorar(){
		if(getNivelEnergia() == 0){
			return;
		}
		reducirEnergia(Random.randomInt(15, 30));
		for (int fila = -1 * nivelExploracion; fila <= nivelExploracion; fila++) {
			if (fila + getyActual() > 25 || fila + getyActual() < 0 ){
				continue;
			}
			
			for (int columna = -1 * nivelExploracion; columna <= nivelExploracion; columna++) {
				if (columna + getxActual() > 25 || columna + getxActual() < 0 ){
					continue;
				}
				getMapa().getCasilla(fila + getyActual(), columna + getxActual()).descubrirSalvaje();
			}
		}
	}
	                                     
	@Override
	public void accionar() {
		
	}

	@Override
	public void comer() {
		
	}

	@Override
	public void descansar() {
		throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
	}
	
}
