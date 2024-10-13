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
import java.util.ArrayList;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class RefrescarMapaThread extends Thread {
    private Mapa mapa;
    private JPanel[][] panelesMapa;
    private JPanel jPanel1;
	private JLabel[][] labelsImagenes;  
    private JLabel[][] labelsTexto;
	private JLabel[][] labelsPersonajes;
	private	ArrayList<Personaje> personajes;
	private final ImageIcon refugioIcon;
	private final ImageIcon carneIcon;
	private final ImageIcon frutasIcon;
	private final ImageIcon plantasIcon;
	private final ImageIcon maderaIcon;
	private Juego juego;
	

    public RefrescarMapaThread(Mapa mapa, JPanel[][] panelesMapa, JPanel jPanel1, JLabel[][] labelsImagenes, JLabel[][] labelsTexto, JLabel[][] labelsPersonajes, ArrayList<Personaje> personajes, Juego juego) {
        this.mapa = mapa;
        this.panelesMapa = panelesMapa;
        this.jPanel1 = jPanel1;
		this.labelsImagenes = labelsImagenes;
        this.labelsTexto = labelsTexto;
		this.labelsPersonajes = labelsPersonajes;
		this.personajes = personajes;
		this.refugioIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Refugio.png");
		this.carneIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Carne.png");
		this.frutasIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Frutas.png");
		this.plantasIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Plantas.png");
		this.maderaIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Madera.png");
		this.juego = juego;
    }

    @Override
    public void run() {
        try {
            while (true) {  
                refrescarMapa();  
				cambiarVidaYEnergia();
				cambiarClima();
				personajeEnfermo();
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
				Casilla casilla = mapa.getCasilla(fila, columna);
				JLabel labelImagen = labelsImagenes[fila][columna];
				JLabel labelTexto = labelsTexto[fila][columna];
				
                if (casilla.isDescubierta()) {
                    panelCasilla.setBackground(Color.decode("#369649"));
					if(casilla.getRefugio() != null){
						labelImagen.setIcon(refugioIcon);
						labelTexto.setText(" " + casilla.getPersonajes().size() + "|" + casilla.getRefugio().getEstabilidad());
						continue;
					} else {
						labelImagen.setIcon(null);
						labelTexto.setIcon(null);
					}
					
					if(casilla.getAnimal() != null){
						labelImagen.setIcon(casilla.getAnimal().getAnimalIcon());
					} else if(!casilla.getPersonajes().isEmpty()){
						labelImagen.setIcon(casilla.getPersonajes().get(0).getPersonajeIcon());
					} else if(casilla.getRecurso() != null){
						if(casilla.getRecurso().getTipo().equals("Carne")){
							labelImagen.setIcon(carneIcon);
						} else if(casilla.getRecurso().getTipo().equals("Frutas")){
							labelImagen.setIcon(frutasIcon);
						} else if(casilla.getRecurso().getTipo().equals("Plantas")){
							labelImagen.setIcon(plantasIcon);
						} else if(casilla.getRecurso().getTipo().equals("Madera")){
							labelImagen.setIcon(maderaIcon);
						}
					}	
				}else {
                    panelCasilla.setBackground(Color.gray); 
					if(!casilla.getPersonajes().isEmpty()){
						labelImagen.setIcon(casilla.getPersonajes().get(0).getPersonajeIcon());
					} else{
						labelImagen.setIcon(null);
					}
                }
            }
        }
        
        jPanel1.revalidate();
        jPanel1.repaint();
    }
	
	private void cambiarVidaYEnergia(){
		for (int i = 0; i < 6; i++) {
			labelsPersonajes[i][0].setText(Integer.toString(personajes.get(i).getNivelSalud()));
			labelsPersonajes[i][1].setText(Integer.toString(personajes.get(i).getNivelEnergia()));
		}
	}
	
	private void cambiarClima(){
		if(!juego.isTormenta()){
			juego.getLblClima().setText("Clima: Despejado");
		} else {
			juego.getLblClima().setText("Clima: Tormentoso");
		}
	}
	
	private void personajeEnfermo(){
		if (personajes.get(0).isEnfermo()) {
			juego.getLblExploradorIcon().setBackground(Color.GREEN);
		} else {
			juego.getLblExploradorIcon().setBackground(Color.WHITE);
		}

		if (personajes.get(1).isEnfermo()) {
			juego.getLblCazadorIcon().setBackground(Color.GREEN);
		} else {
			juego.getLblCazadorIcon().setBackground(Color.WHITE);
		}

		if (personajes.get(2).isEnfermo()) {
			juego.getLblRecolectorIcon().setBackground(Color.GREEN);
		} else {
			juego.getLblRecolectorIcon().setBackground(Color.WHITE);
		}

		if (personajes.get(3).isEnfermo()) {
			juego.getLblConstructorIcon().setBackground(Color.GREEN);
		} else {
			juego.getLblConstructorIcon().setBackground(Color.WHITE);
		}

		if (personajes.get(4).isEnfermo()) {
			juego.getLblCuranderoIcon().setBackground(Color.GREEN);
		} else {
			juego.getLblCuranderoIcon().setBackground(Color.WHITE);
		}

		if (personajes.get(5).isEnfermo()) {
			juego.getLblCientificoIcon().setBackground(Color.GREEN);
		} else {
			juego.getLblCientificoIcon().setBackground(Color.WHITE);
		}

	}
	
}
