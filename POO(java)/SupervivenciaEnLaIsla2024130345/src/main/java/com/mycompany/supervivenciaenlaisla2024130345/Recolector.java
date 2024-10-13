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
public class Recolector extends Personaje{
	private int habilidadRecoleccion;
	
	
	public Recolector(int x, int y, Mapa mapa) {
		super("Recolector", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Recolector.png"),x,y, mapa,"C:\\Users\\Proyecto Diseño\\Desktop\\ArchivostxtIslandSurvivors\\Recolector.txt");
	}

	@Override
	public void accionar() {
		
	}

	@Override
	public void descansar() {
		
	}
	
	public void recolectar(){
		if(getNivelEnergia() == 0 || getCasillaActual().getRecurso() == null || getCasillaActual().getRecurso().getTipo().equals("Carne")){
			return;
		}
		reducirEnergia(5);
		añadirAInventario(getCasillaActual().getRecurso());
		getCasillaActual().setRecurso(null);
		meterABitacora("Recolector recolectó en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
	
}
