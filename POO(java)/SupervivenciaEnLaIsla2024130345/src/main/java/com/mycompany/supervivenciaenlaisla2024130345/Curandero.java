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
public class Curandero extends Personaje{
	private int habilidadCurar;
	
	
	
	public Curandero(int x, int y, Mapa mapa) {
		super("Curandero", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Curandero.png"),x,y, mapa,"C:\\Users\\Proyecto Diseño\\Desktop\\ArchivostxtIslandSurvivors\\Curandero.txt");
		habilidadCurar = Random.randomInt(15, 20);
	}

	@Override
	public void accionar() {
		
	}


	@Override
	public void descansar() {
		
	}
	
	public void curar(Personaje personaje){
		if (getInventario()[2].getCantidad()< 5 || getNivelEnergia() == 0){
			return;
		}
		getInventario()[2].usarRecurso(5);
		reducirEnergia(10);
		personaje.recuperarSalud(habilidadCurar);
		meterABitacora("El curandero curó a " + personaje.getNombre() + " en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
	
	public void prepararRemedio(Personaje enfermo){
		if (getInventario()[2].getCantidad()< 10 || getNivelEnergia() == 0){
			return;
		}
		getInventario()[2].usarRecurso(10);
		reducirEnergia(10);
		enfermo.setEstaEnfermo(false);
		meterABitacora("El curandero preparó un remedio para " + enfermo.getNombre() + " en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
	
	public void recolectar(){
		if(getNivelEnergia() == 0 || getCasillaActual().getRecurso() == null || !getCasillaActual().getRecurso().getTipo().equals("Plantas")){
			return;
		}
		reducirEnergia(10);
		añadirAInventario(getCasillaActual().getRecurso());
		getCasillaActual().setRecurso(null);
		meterABitacora("El curandero recolectó en" + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
}
