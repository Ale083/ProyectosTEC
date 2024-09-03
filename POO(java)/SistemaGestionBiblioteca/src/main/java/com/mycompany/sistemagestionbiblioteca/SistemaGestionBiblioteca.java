/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.sistemagestionbiblioteca;

/**
 *
 * @author Proyecto Diseño
 */
public class SistemaGestionBiblioteca {
    public static void main(String[] args) {
		//Lo hice todo en ingles (también el menu traducido) 
		//porque sino me confundo pasar de ingles a español y viceversa.
        Library library = new Library();
		Menu menu = new Menu(library);
		menu.init();
		menu.showMenu();
    }
}
