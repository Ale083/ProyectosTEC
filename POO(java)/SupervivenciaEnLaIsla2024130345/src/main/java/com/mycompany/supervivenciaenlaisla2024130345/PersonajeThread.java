/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Proyecto Diseño
 */
public class PersonajeThread extends Thread{
	private boolean running = true;
	private boolean paused = false;
	private Mapa mapa;
	private Personaje refPersonaje;

	public PersonajeThread(Mapa mapa, Personaje refPersonaje) {
		this.mapa = mapa;
		this.refPersonaje = refPersonaje;
	}
	
	public void run(){
		while(running){
			if(refPersonaje.isMoving()){
				try {
					sleep(1000);
					int xPersonaje = refPersonaje.getxActual();
					int yPersonaje = refPersonaje.getyActual();
					if(xPersonaje != refPersonaje.getxDestino()){
						if(xPersonaje < refPersonaje.getxDestino()){
							mapa.moverPersonajeHorizontal(refPersonaje,1);
						} else {
							mapa.moverPersonajeHorizontal(refPersonaje,-1);
						}
					} 
					else if(yPersonaje != refPersonaje.getyDestino()){
						if(yPersonaje < refPersonaje.getyDestino()){
							mapa.moverPersonajeVertical(refPersonaje,1);
						} else {
							mapa.moverPersonajeVertical(refPersonaje,-1);
						}
					}
					else{
						refPersonaje.setxDestino(-1);
						refPersonaje.setyDestino(-1);
						
					}
					
					
				} catch (InterruptedException ex) {}
				
				
				
				
			} else {
				try {
					sleep(1000);
						
					} catch (InterruptedException ex) {}	
			}
		}
	}
	
	
	
	
}
