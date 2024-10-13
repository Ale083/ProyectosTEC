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
		super("Explorador", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Explorador.png"),x,y, mapa,"C:\\Users\\Proyecto Diseño\\Desktop\\ArchivostxtIslandSurvivors\\Explorador.txt");
		this.nivelExploracion = Random.randomInt(3, 4); 
	}

	public void recolectar(){
		if(getNivelEnergia() == 0){
			return;
		}
		if(getCasillaActual().getRecurso() == null){
			return;
		}
		reducirEnergia(5);
		añadirAInventario(getCasillaActual().getRecurso());
		getCasillaActual().setRecurso(null);
		meterABitacora("El explorador recolectó en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
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
		meterABitacora("El explorador exploró en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
	                                     
	@Override
	public void accionar() {
		
	}

	@Override
	public void descansar() {
		throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
	}
	
}
