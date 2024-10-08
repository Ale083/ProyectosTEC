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
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public class RefrescarMapaThread extends Thread {
    private Mapa mapa;
    private JPanel[][] panelesMapa;
    private JPanel jPanel1;
	private JLabel[][] labelsImagenes;  
    private JLabel[][] labelsTexto;
	private ImageIcon refugioIcon;
	private ImageIcon materialIcon;

    public RefrescarMapaThread(Mapa mapa, JPanel[][] panelesMapa, JPanel jPanel1, JLabel[][] labelsImagenes, JLabel[][] labelsTexto) {
        this.mapa = mapa;
        this.panelesMapa = panelesMapa;
        this.jPanel1 = jPanel1;
		this.labelsImagenes = labelsImagenes;
        this.labelsTexto = labelsTexto;
		this.refugioIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Refugio.png");
		this.materialIcon = new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Recurso.png");
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
//	this.descubierta = false;
//	this.refugio = null;
//	this.personajes = new ArrayList<Personaje>();
//	this.recursos = new ArrayList<Recurso>();
//	this.animal = null;
    private void refrescarMapa() {
        for (int fila = 0; fila < mapa.getMapa().length; fila++) {
            for (int columna = 0; columna < mapa.getMapa()[0].length; columna++) {
                JPanel panelCasilla = panelesMapa[fila][columna];
				Casilla casilla = mapa.getCasilla(fila, columna);
				JLabel labelImagen = labelsImagenes[fila][columna];
				JLabel labelTexto = labelsTexto[fila][columna];
				
                //TODO: todo lo que puede cambiar o hay que enseñar en gui
                if (casilla.isDescubierta()) {
                    panelCasilla.setBackground(Color.decode("#369649"));
					if(casilla.getRefugio() != null){
						labelImagen.setIcon(refugioIcon);
						labelTexto.setText("" + casilla.getPersonajes().size());
						continue;
					} else {
						labelImagen.setIcon(null);
						labelTexto.setIcon(null);
					}
					
					if(casilla.getAnimal() != null){
						labelImagen.setIcon(casilla.getAnimal().getAnimalIcon());
					} else if(!casilla.getPersonajes().isEmpty()){
						labelImagen.setIcon(casilla.getPersonajes().get(0).getPersonajeIcon());
					} else if(!casilla.getRecursos().isEmpty()){
						if(casilla.getRecursos().get(0).getTipo() == "Carne"){
							labelImagen.setIcon(null);//TODO
						} else{
							labelImagen.setIcon(materialIcon);
						}
					}	
					}else {
                    panelCasilla.setBackground(Color.gray); //TODO: Podría quitarlo.
                }
            }
        }
        
        jPanel1.revalidate();
        jPanel1.repaint();
    }
}
