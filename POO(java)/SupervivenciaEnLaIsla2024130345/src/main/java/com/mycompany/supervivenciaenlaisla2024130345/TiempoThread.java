/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;

/**
 *
 * @author Proyecto Diseño
 */
public class TiempoThread extends Thread{
	private JLabel tiempo;
	private int segundos;
	private int minutos;
	private Juego juego;

	public TiempoThread(JLabel tiempo, Juego juego) {
		this.tiempo = tiempo;
		this.juego = juego;
		segundos = 0;
		minutos = 0;
	}
	
	public void run(){
		try {
			while (true){
				sleep(1000);
				tiempo();
				cambiarLabel();
			}
		} catch (InterruptedException ex) {
			Logger.getLogger(TiempoThread.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
	
	private void tiempo(){
		segundos++;
		if(segundos>=60){
			minutos++;
			if(minutos >= 5){
				minutos = 0;
				juego.pasarDia();
			}
			segundos = 0;
		}
	}
	
	private void cambiarLabel(){
		String strSegundos = Integer.toString(segundos);
		if(segundos < 10){
			strSegundos = "0" + strSegundos;
		}
		tiempo.setText(Integer.toString(minutos)+ ":" + strSegundos);
	}
	
	public int getSegundos() {
		return segundos;
	}

	public void setSegundos(int segundos) {
		this.segundos = segundos;
	}

	public int getMinutos() {
		return minutos;
	}

	public void setMinutos(int minutos) {
		this.minutos = minutos;
	}
	
	
	
	
	
}
