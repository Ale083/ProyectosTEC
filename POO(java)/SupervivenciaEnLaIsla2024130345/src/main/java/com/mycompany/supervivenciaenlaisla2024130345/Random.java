/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
public class Random {
	
	public static int randomInt(int min, int max){
		return (min + (int)(Math.random() * ((max - min) + 1)));
	}
}
