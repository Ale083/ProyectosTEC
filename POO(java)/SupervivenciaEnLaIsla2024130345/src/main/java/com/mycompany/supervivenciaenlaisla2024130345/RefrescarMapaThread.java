/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

/**
 *
 * @author Proyecto Diseño
 */
import javax.swing.JPanel;
import java.awt.Color;

public class RefrescarMapaThread extends Thread {
    private Mapa mapa;
    private JPanel[][] panelesMapa;
    private JPanel jPanel1;

    public RefrescarMapaThread(Mapa mapa, JPanel[][] panelesMapa, JPanel jPanel1) {
        this.mapa = mapa;
        this.panelesMapa = panelesMapa;
        this.jPanel1 = jPanel1;
    }

    @Override
    public void run() {
        try {
            while (true) {  
                refrescarMapa();  
                Thread.sleep(1000);  
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    private void refrescarMapa() {
        for (int fila = 0; fila < mapa.getMapa().length; fila++) {
            for (int columna = 0; columna < mapa.getMapa()[0].length; columna++) {
                JPanel panelCasilla = panelesMapa[fila][columna];

                //TODO: todo lo que puede cambiar o hay que enseñar en gui
                if (mapa.getCasilla(fila, columna).isDescubierta()) {
                    panelCasilla.setBackground(Color.decode("#369649"));
                } else {
                    panelCasilla.setBackground(Color.gray); 
                }
            }
        }
        
        jPanel1.revalidate();
        jPanel1.repaint();
    }
}
