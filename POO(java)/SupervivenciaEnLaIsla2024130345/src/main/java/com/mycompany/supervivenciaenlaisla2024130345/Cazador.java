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
public class Cazador extends Personaje{
	
	public Cazador(int x, int y, Mapa mapa) {
		super("Cazador", new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Cazador.png"),x, y, mapa,"C:\\Users\\Proyecto Diseño\\Desktop\\ArchivostxtIslandSurvivors\\Cazador.txt");
	}

	@Override
	public void accionar() {
		throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
	}

	@Override
	public void descansar() {
		throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
	}
	
	public void cazar(Animal animal){
		if (animal == null || getNivelEnergia() <=0){
			return;
		}
		reducirEnergia(Random.randomInt(20, 30));
		if(animal.getTipoAnimal() == "Grande"){
			reducirSalud(Random.randomInt(10,20));
		}
		animal.serCazado(this);
		meterABitacora("El cazador cazó un animal en " + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
	
	public void defender(Animal animal){
		if (animal == null || getNivelEnergia() <=0){
			return;
		}
		reducirEnergia(25);
		if(animal.getTipoAnimal() == "Grande"){
			reducirSalud(Random.randomInt(15,20));
		} else{
			reducirSalud(10);
		}
		animal.serCazado(this);
		meterABitacora("El cazador defendió de un animal en" + java.time.LocalDateTime.now().format(java.time.format.DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
	}
		

}
