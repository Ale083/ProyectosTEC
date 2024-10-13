/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.ArrayList;
import javax.swing.JOptionPane;

/**
 *
 * @author Proyecto Diseño
 */
public class ControlesDios extends javax.swing.JFrame {
	private Mapa mapa;
	private ArrayList<Personaje> personajes;
	private Juego juego;
	/**
	 * Creates new form ControlesDios
	 */
	public ControlesDios(Mapa mapa, ArrayList<Personaje> personajes, Juego juego) {
		initComponents();
		this.mapa = mapa;
		this.personajes = personajes;
		this.juego = juego;
	}

	/**
	 * This method is called from within the constructor to initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is always
	 * regenerated by the Form Editor.
	 */
	@SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton7 = new javax.swing.JButton();
        cbxPersonaje = new javax.swing.JComboBox<>();
        btnEnfermar = new javax.swing.JButton();
        btnAccidentar = new javax.swing.JButton();
        btnTormenta = new javax.swing.JButton();
        btnPasarDia = new javax.swing.JButton();
        lblX = new java.awt.Label();
        lblY = new java.awt.Label();
        lblCantidad = new javax.swing.JLabel();
        cbxRecurso = new javax.swing.JComboBox<>();
        btnAparecerRecurso = new javax.swing.JButton();
        btnAparecerAnimalPequeno = new javax.swing.JButton();
        btnAparecerAnimalGrande = new javax.swing.JButton();
        txfX = new javax.swing.JTextField();
        txfY = new javax.swing.JTextField();
        txfCantidad = new javax.swing.JTextField();
        btnSalir = new javax.swing.JButton();

        jButton7.setText("jButton7");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(550, 400));

        cbxPersonaje.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Explorador", "Cazador", "Recolector", "Constructor", "Curandero", "Cientifico" }));

        btnEnfermar.setText("Enfermar");
        btnEnfermar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEnfermarActionPerformed(evt);
            }
        });

        btnAccidentar.setText("Accidentar");
        btnAccidentar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAccidentarActionPerformed(evt);
            }
        });

        btnTormenta.setText("Aparecer Tormenta");
        btnTormenta.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnTormentaActionPerformed(evt);
            }
        });

        btnPasarDia.setText("Pasar dia");
        btnPasarDia.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnPasarDiaActionPerformed(evt);
            }
        });

        lblX.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        lblX.setText("x:");

        lblY.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        lblY.setText("y:");

        lblCantidad.setText("Cantidad");

        cbxRecurso.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Carne", "Frutas", "Plantas", "Madera" }));

        btnAparecerRecurso.setText("Aparecer Recurso");
        btnAparecerRecurso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAparecerRecursoActionPerformed(evt);
            }
        });

        btnAparecerAnimalPequeno.setText("Aparecer Animal Pequeño");
        btnAparecerAnimalPequeno.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAparecerAnimalPequenoActionPerformed(evt);
            }
        });

        btnAparecerAnimalGrande.setText("Aparecer Animal Grande");
        btnAparecerAnimalGrande.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAparecerAnimalGrandeActionPerformed(evt);
            }
        });

        txfX.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N

        txfY.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N

        txfCantidad.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N

        btnSalir.setText("SALIR");
        btnSalir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnSalirActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addComponent(cbxPersonaje, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(btnAccidentar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnEnfermar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(btnTormenta, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnPasarDia, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(106, 106, 106))
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(btnSalir, javax.swing.GroupLayout.PREFERRED_SIZE, 480, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(lblX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(lblY, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(txfX, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(txfY, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(8, 8, 8)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(btnAparecerAnimalPequeno)
                                .addGap(45, 45, 45)
                                .addComponent(btnAparecerAnimalGrande))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(4, 4, 4)
                                .addComponent(cbxRecurso, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(14, 14, 14)
                                .addComponent(lblCantidad)
                                .addGap(26, 26, 26)
                                .addComponent(txfCantidad, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(btnAparecerRecurso)))))
                .addContainerGap(44, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(56, 56, 56)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(btnEnfermar)
                            .addComponent(btnTormenta))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(btnAccidentar)
                            .addComponent(btnPasarDia)))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(72, 72, 72)
                        .addComponent(cbxPersonaje, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(34, 34, 34)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addComponent(lblX, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(txfX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(btnAparecerRecurso)
                            .addComponent(txfCantidad, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(lblCantidad)
                            .addComponent(cbxRecurso, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(3, 3, 3)))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lblY, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(txfY, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(btnAparecerAnimalPequeno)
                        .addComponent(btnAparecerAnimalGrande)))
                .addGap(29, 29, 29)
                .addComponent(btnSalir, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(30, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnEnfermarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEnfermarActionPerformed
        personajes.get(cbxPersonaje.getSelectedIndex()).setEstaEnfermo(true);
    }//GEN-LAST:event_btnEnfermarActionPerformed

	private boolean esSoloNumeros(String str) {
		return str.matches("\\d+");  
	}
	
    private void btnTormentaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnTormentaActionPerformed
        juego.setTormenta(true);
    }//GEN-LAST:event_btnTormentaActionPerformed

    private void btnAparecerRecursoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAparecerRecursoActionPerformed
        String strX = txfX.getText();
		String strY = txfY.getText();
		String strCantidad = txfCantidad.getText();
		if(!esSoloNumeros(strX) || !esSoloNumeros(strY) || !esSoloNumeros(strCantidad)){ //si alguno no es numero
			JOptionPane.showMessageDialog(this,"Error, solo pueden haber números en x,y","Error", JOptionPane.ERROR_MESSAGE);
			return;
		}
		int x = Integer.parseInt(strX);
		int y = Integer.parseInt(strY);
		int cant = Integer.parseInt(strCantidad);
		if(x<0 || x>25 || y<0 || y>25 || cant<1 || cant > 1000){
			JOptionPane.showMessageDialog(this,"Error, uno o más números se sale del rango","Error", JOptionPane.ERROR_MESSAGE);
			return;
		}
		Casilla casilla = mapa.getCasilla(y, x);
		if(casilla.getAnimal() == null && casilla.getRecurso() == null && casilla.getRefugio() == null){
			casilla.setRecurso(new Recurso((String)cbxRecurso.getSelectedItem(),cant));
		}
    }//GEN-LAST:event_btnAparecerRecursoActionPerformed

    private void btnAparecerAnimalPequenoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAparecerAnimalPequenoActionPerformed
        String strX = txfX.getText();
		String strY = txfY.getText();
		String strCantidad = txfCantidad.getText();
		if(!esSoloNumeros(strX) || !esSoloNumeros(strY) || !esSoloNumeros(strCantidad)){ //si alguno no es numero
			JOptionPane.showMessageDialog(this,"Error, solo pueden haber números en x,y","Error", JOptionPane.ERROR_MESSAGE);
			return;
		}
		int x = Integer.parseInt(strX);
		int y = Integer.parseInt(strY);
		int cant = Integer.parseInt(strCantidad);
		if(x<0 || x>25 || y<0 || y>25 || cant<1 || cant > 1000){
			JOptionPane.showMessageDialog(this,"Error, uno o más números se sale del rango","Error", JOptionPane.ERROR_MESSAGE);
			return;
		}
		Casilla casilla = mapa.getCasilla(y, x);
		if(casilla.getAnimal() == null && casilla.getRecurso() == null && casilla.getRefugio() == null){
			casilla.setAnimal(new Animal("Pequeño"));
		}
    }//GEN-LAST:event_btnAparecerAnimalPequenoActionPerformed

    private void btnAparecerAnimalGrandeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAparecerAnimalGrandeActionPerformed
        String strX = txfX.getText();
		String strY = txfY.getText();
		String strCantidad = txfCantidad.getText();
		if(!esSoloNumeros(strX) || !esSoloNumeros(strY) || !esSoloNumeros(strCantidad)){ //si alguno no es numero
			JOptionPane.showMessageDialog(this,"Error, solo pueden haber números en x,y","Error", JOptionPane.ERROR_MESSAGE);
			return;
		}
		int x = Integer.parseInt(strX);
		int y = Integer.parseInt(strY);
		int cant = Integer.parseInt(strCantidad);
		if(x<0 || x>25 || y<0 || y>25 || cant<1 || cant > 1000){
			JOptionPane.showMessageDialog(this,"Error, uno o más números se sale del rango","Error", JOptionPane.ERROR_MESSAGE);
			return;
		}
		Casilla casilla = mapa.getCasilla(y, x);
		if(casilla.getAnimal() == null && casilla.getRecurso() == null && casilla.getRefugio() == null){
			casilla.setAnimal(new Animal("Grande"));
		}
    }//GEN-LAST:event_btnAparecerAnimalGrandeActionPerformed

    private void btnSalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSalirActionPerformed
        this.setVisible(false);
    }//GEN-LAST:event_btnSalirActionPerformed

    private void btnPasarDiaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnPasarDiaActionPerformed
        juego.pasarDia();
    }//GEN-LAST:event_btnPasarDiaActionPerformed

    private void btnAccidentarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAccidentarActionPerformed
        personajes.get(cbxPersonaje.getSelectedIndex()).accidentar();
    }//GEN-LAST:event_btnAccidentarActionPerformed

	
	
	
	
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAccidentar;
    private javax.swing.JButton btnAparecerAnimalGrande;
    private javax.swing.JButton btnAparecerAnimalPequeno;
    private javax.swing.JButton btnAparecerRecurso;
    private javax.swing.JButton btnEnfermar;
    private javax.swing.JButton btnPasarDia;
    private javax.swing.JButton btnSalir;
    private javax.swing.JButton btnTormenta;
    private javax.swing.JComboBox<String> cbxPersonaje;
    private javax.swing.JComboBox<String> cbxRecurso;
    private javax.swing.JButton jButton7;
    private javax.swing.JLabel lblCantidad;
    private java.awt.Label lblX;
    private java.awt.Label lblY;
    private javax.swing.JTextField txfCantidad;
    private javax.swing.JTextField txfX;
    private javax.swing.JTextField txfY;
    // End of variables declaration//GEN-END:variables
}
