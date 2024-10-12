/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import javax.swing.JLabel;

/**
 *
 * @author Proyecto Diseño
 */
public class GUIInventarioThread extends Thread{
	private Personaje personaje;
	private JLabel lblCantidadCarne;
    private JLabel lblCantidadFrutas;
    private JLabel lblCantidadPlantas;
	private JLabel lblCantidadMadera;

	public GUIInventarioThread(Personaje personaje, JLabel lblCantidadCarne, JLabel lblCantidadFrutas, JLabel lblCantidadPlantas, JLabel lblCantidadMadera) {
		this.personaje = personaje;
		this.lblCantidadCarne = lblCantidadCarne;
		this.lblCantidadFrutas = lblCantidadFrutas;
		this.lblCantidadPlantas = lblCantidadPlantas;
		this.lblCantidadMadera = lblCantidadMadera;
	}
	
	public void run() {
        try {
            while (true) {  
                lblCantidadCarne.setText(Integer.toString(personaje.getInventario()[0].getCantidad()));
				lblCantidadFrutas.setText(Integer.toString(personaje.getInventario()[1].getCantidad()));
				lblCantidadPlantas.setText(Integer.toString(personaje.getInventario()[2].getCantidad()));
				lblCantidadMadera.setText(Integer.toString(personaje.getInventario()[3].getCantidad()));
                Thread.sleep(1000);  
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
	
	
}
