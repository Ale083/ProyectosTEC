/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.ArrayList;

/**
 *
 * @author Proyecto Diseño
 */
public class Refugio {
	private int estabilidad;
	
	public Refugio(){
		estabilidad = 100;
	}
	
	public void reparar(Constructor constructor){
		if(estabilidad + 20 >100){
			estabilidad = 100;
		} else {
			estabilidad += 20;
		}
	}
	
	public int getEstabilidad(){
		return estabilidad;
	}
}
