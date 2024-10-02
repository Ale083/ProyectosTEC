/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
public class Casilla {
    private boolean descubierta; 

    public Casilla() {
        this.descubierta = false; 
		//TODO: Cuando se genera la casilla, ponerle un 20% chance maybe de que genere materiales, luego otro rng para ver cuantos y asi.
    }

    public boolean isDescubierta() {
        return descubierta;
    }

    public void setDescubierta(boolean descubierta) {
        this.descubierta = descubierta;
    }

    // Otros métodos como getters y setters
}
