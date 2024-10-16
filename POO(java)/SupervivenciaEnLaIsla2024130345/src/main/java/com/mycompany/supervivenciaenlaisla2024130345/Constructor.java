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
		super("Constructor", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Constructor.png"),x,y, mapa,"C:\\Users\\Proyecto Diseño\\Desktop\\ArchivostxtIslandSurvivors\\Constructor.txt");
	}

	@Override
	public void accionar() {
		
	}


	@Override
	public void descansar() {
		
	}
	
	public void construirRefugio(Casilla casilla){
		if(casilla.getRefugio() != null || getInventario()[3].getCantidad() < 10 || getNivelEnergia() <10){
			return;
		}
		reducirEnergia(20);
		getInventario()[3].usarRecurso(20);
		casilla.setRefugio(new Refugio());
		meterABitacora("El constructor construyó un refugio en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
	
	public void repararRefugio(Refugio refugio){
		if(refugio == null || getInventario()[3].getCantidad() < 10 || getNivelEnergia() <10){
			return;
		}
		reducirEnergia(10);
		getInventario()[3].usarRecurso(10);
		refugio.reparar(this);
		meterABitacora("El constructor reparó un refugio en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
}
