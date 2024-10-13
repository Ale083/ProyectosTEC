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
public class Cientifico extends Personaje{
	private int habilidadCiencia;
	
	public Cientifico(int x, int y, Mapa mapa) {
		super("Cientifico", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Cientifico.png"),x,y, mapa,"C:\\Users\\Proyecto Diseño\\Desktop\\ArchivostxtIslandSurvivors\\Cientifico.txt");
	}

	@Override
	public void accionar() {
		
	}

	@Override
	public void descansar() {
		
	}
	
	public void prepararRemedio(Personaje enfermo){
		if (getNivelEnergia() == 0){
			return;
		}
		reducirEnergia(15);
		enfermo.setEstaEnfermo(false);
		meterABitacora("El cientifico preparó un remedio para " + enfermo.getNombre() + " en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
}
