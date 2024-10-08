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
	public Explorador(int x, int y) {
		super("Explorador", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Explorador.png"),x,y);
		this.nivelExploracion = 5; //TODO, maybe que sea random.
	}

	public void recolectar(){
		
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
