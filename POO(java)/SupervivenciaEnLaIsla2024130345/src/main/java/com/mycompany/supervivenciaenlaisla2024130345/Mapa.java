/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
public class Mapa {
    private Casilla[][] mapa;

    public Mapa(int filas, int columnas) {
        mapa = new Casilla[filas][columnas];
        inicializarMapa();
    }

    private void inicializarMapa() {
        for (int i = 0; i < mapa.length; i++) {
            for (int j = 0; j < mapa[i].length; j++) {
                mapa[i][j] = new Casilla();
            }
        }
    }

    public Casilla getCasilla(int fila, int columna) {
        return mapa[fila][columna];
    }

	public Casilla[][] getMapa() {
		return mapa;
	}
	
	
}

