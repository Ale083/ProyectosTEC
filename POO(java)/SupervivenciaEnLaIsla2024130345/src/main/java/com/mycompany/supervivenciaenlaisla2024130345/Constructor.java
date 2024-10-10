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
public class Constructor extends Personaje{
	private int habilidadConstruccion;
	
	public Constructor(int x, int y, Mapa mapa) {
		super("Constructor", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Constructor.png"),x,y, mapa);
	}

	@Override
	public void accionar() {
		
	}

	@Override
	public void comer() {
		
	}

	@Override
	public void descansar() {
		
	}
	
	public void construirRefugio(Refugio refugio){
		
	}
	
	public void repararRefugio(Refugio refugio){
		
	}
}
