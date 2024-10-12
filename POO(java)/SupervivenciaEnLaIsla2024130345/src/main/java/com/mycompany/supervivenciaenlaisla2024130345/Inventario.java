/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.supervivenciaenlaisla2024130345;

import java.util.ArrayList;
import javax.swing.ImageIcon;

/**
 *
 * @author Proyecto Diseño
 */
public class Inventario extends javax.swing.JFrame {
	private GUIInventarioThread threadInventario;
	private Personaje personaje;
	private ArrayList<Personaje> personajes;
	
	public Inventario(Personaje personaje, ArrayList<Personaje> personajes) {
		initComponents();
		this.personaje = personaje;
		this.personajes = personajes;
		this.setTitle(personaje.getNombre());
		ponerPersonajesEnCbx(personaje, personajes);
		threadInventario = new GUIInventarioThread(personaje,lblCantidadCarne,lblCantidadFrutas,lblCantidadPlantas,lblCantidadMadera);
		threadInventario.start();
		disableComida(personaje,personajes);
	}

	/**
	 * This method is called from within the constructor to initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is always
	 * regenerated by the Form Editor.
	 */
	@SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        pnlCarne = new javax.swing.JPanel();
        lblCantidadCarne = new javax.swing.JLabel();
        lblCarneIcon = new javax.swing.JLabel();
        pnlFrutas = new javax.swing.JPanel();
        lblCantidadFrutas = new javax.swing.JLabel();
        lblFrutasIcon = new javax.swing.JLabel();
        pnlPlantas = new javax.swing.JPanel();
        lblCantidadPlantas = new javax.swing.JLabel();
        lblPlantasIcon = new javax.swing.JLabel();
        pnlMadera = new javax.swing.JPanel();
        lblCantidadMadera = new javax.swing.JLabel();
        lblMaderaIcon = new javax.swing.JLabel();
        cbxPersonajeACompartir = new javax.swing.JComboBox<>();
        btnCompartirCarne = new javax.swing.JButton();
        btnCompartirFrutas = new javax.swing.JButton();
        btnCompartirPlantas = new javax.swing.JButton();
        btnCompartirMadera = new javax.swing.JButton();
        btnComerCarne = new javax.swing.JButton();
        btnComerFrutas = new javax.swing.JButton();
        lblACompartir = new javax.swing.JLabel();
        btnSalir = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        pnlCarne.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        lblCantidadCarne.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblCantidadCarne.setText("0");
        lblCantidadCarne.setMaximumSize(new java.awt.Dimension(50, 16));
        lblCantidadCarne.setMinimumSize(new java.awt.Dimension(50, 16));
        lblCantidadCarne.setPreferredSize(new java.awt.Dimension(50, 16));

        lblCarneIcon.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        lblCarneIcon.setMaximumSize(new java.awt.Dimension(32, 32));
        lblCarneIcon.setMinimumSize(new java.awt.Dimension(32, 32));
        lblCarneIcon.setPreferredSize(new java.awt.Dimension(32, 32));
        lblCarneIcon.setIcon(new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Carne.png"));

        javax.swing.GroupLayout pnlCarneLayout = new javax.swing.GroupLayout(pnlCarne);
        pnlCarne.setLayout(pnlCarneLayout);
        pnlCarneLayout.setHorizontalGroup(
            pnlCarneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(pnlCarneLayout.createSequentialGroup()
                .addGroup(pnlCarneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(pnlCarneLayout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addComponent(lblCantidadCarne, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(pnlCarneLayout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addComponent(lblCarneIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        pnlCarneLayout.setVerticalGroup(
            pnlCarneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, pnlCarneLayout.createSequentialGroup()
                .addContainerGap(23, Short.MAX_VALUE)
                .addComponent(lblCarneIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(lblCantidadCarne, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(23, 23, 23))
        );

        pnlFrutas.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        lblCantidadFrutas.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblCantidadFrutas.setText("0");
        lblCantidadFrutas.setMaximumSize(new java.awt.Dimension(50, 16));
        lblCantidadFrutas.setMinimumSize(new java.awt.Dimension(50, 16));
        lblCantidadFrutas.setPreferredSize(new java.awt.Dimension(50, 16));

        lblFrutasIcon.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        lblFrutasIcon.setMaximumSize(new java.awt.Dimension(32, 32));
        lblFrutasIcon.setMinimumSize(new java.awt.Dimension(32, 32));
        lblFrutasIcon.setPreferredSize(new java.awt.Dimension(32, 32));
        lblFrutasIcon.setIcon(new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Frutas.png"));

        javax.swing.GroupLayout pnlFrutasLayout = new javax.swing.GroupLayout(pnlFrutas);
        pnlFrutas.setLayout(pnlFrutasLayout);
        pnlFrutasLayout.setHorizontalGroup(
            pnlFrutasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(pnlFrutasLayout.createSequentialGroup()
                .addGroup(pnlFrutasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(pnlFrutasLayout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addComponent(lblCantidadFrutas, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(pnlFrutasLayout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addComponent(lblFrutasIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        pnlFrutasLayout.setVerticalGroup(
            pnlFrutasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, pnlFrutasLayout.createSequentialGroup()
                .addContainerGap(23, Short.MAX_VALUE)
                .addComponent(lblFrutasIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(lblCantidadFrutas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(23, 23, 23))
        );

        pnlPlantas.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        lblCantidadPlantas.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblCantidadPlantas.setText("0");
        lblCantidadPlantas.setMaximumSize(new java.awt.Dimension(50, 16));
        lblCantidadPlantas.setMinimumSize(new java.awt.Dimension(50, 16));
        lblCantidadPlantas.setPreferredSize(new java.awt.Dimension(50, 16));

        lblPlantasIcon.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        lblPlantasIcon.setMaximumSize(new java.awt.Dimension(32, 32));
        lblPlantasIcon.setMinimumSize(new java.awt.Dimension(32, 32));
        lblPlantasIcon.setPreferredSize(new java.awt.Dimension(32, 32));
        lblPlantasIcon.setIcon(new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Plantas.png"));

        javax.swing.GroupLayout pnlPlantasLayout = new javax.swing.GroupLayout(pnlPlantas);
        pnlPlantas.setLayout(pnlPlantasLayout);
        pnlPlantasLayout.setHorizontalGroup(
            pnlPlantasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(pnlPlantasLayout.createSequentialGroup()
                .addGroup(pnlPlantasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(pnlPlantasLayout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addComponent(lblCantidadPlantas, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(pnlPlantasLayout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addComponent(lblPlantasIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        pnlPlantasLayout.setVerticalGroup(
            pnlPlantasLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, pnlPlantasLayout.createSequentialGroup()
                .addContainerGap(23, Short.MAX_VALUE)
                .addComponent(lblPlantasIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(lblCantidadPlantas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(23, 23, 23))
        );

        pnlMadera.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        lblCantidadMadera.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblCantidadMadera.setText("0");
        lblCantidadMadera.setMaximumSize(new java.awt.Dimension(50, 16));
        lblCantidadMadera.setMinimumSize(new java.awt.Dimension(50, 16));
        lblCantidadMadera.setPreferredSize(new java.awt.Dimension(50, 16));

        lblMaderaIcon.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));
        lblMaderaIcon.setMaximumSize(new java.awt.Dimension(32, 32));
        lblMaderaIcon.setMinimumSize(new java.awt.Dimension(32, 32));
        lblMaderaIcon.setPreferredSize(new java.awt.Dimension(32, 32));
        lblMaderaIcon.setIcon(new ImageIcon("C:\\Users\\Proyecto Diseño\\Desktop\\imagenesIslandSurvivors\\Madera.png"));

        javax.swing.GroupLayout pnlMaderaLayout = new javax.swing.GroupLayout(pnlMadera);
        pnlMadera.setLayout(pnlMaderaLayout);
        pnlMaderaLayout.setHorizontalGroup(
            pnlMaderaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(pnlMaderaLayout.createSequentialGroup()
                .addGroup(pnlMaderaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(pnlMaderaLayout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addComponent(lblCantidadMadera, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(pnlMaderaLayout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addComponent(lblMaderaIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        pnlMaderaLayout.setVerticalGroup(
            pnlMaderaLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, pnlMaderaLayout.createSequentialGroup()
                .addContainerGap(23, Short.MAX_VALUE)
                .addComponent(lblMaderaIcon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(lblCantidadMadera, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(23, 23, 23))
        );

        cbxPersonajeACompartir.setMaximumSize(new java.awt.Dimension(72, 22));

        btnCompartirCarne.setText("Compartir");
        btnCompartirCarne.setMaximumSize(new java.awt.Dimension(102, 23));
        btnCompartirCarne.setMinimumSize(new java.awt.Dimension(102, 23));
        btnCompartirCarne.setPreferredSize(new java.awt.Dimension(102, 23));
        btnCompartirCarne.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCompartirCarneActionPerformed(evt);
            }
        });

        btnCompartirFrutas.setText("Compartir");
        btnCompartirFrutas.setMaximumSize(new java.awt.Dimension(102, 23));
        btnCompartirFrutas.setMinimumSize(new java.awt.Dimension(102, 23));
        btnCompartirFrutas.setPreferredSize(new java.awt.Dimension(102, 23));
        btnCompartirFrutas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCompartirFrutasActionPerformed(evt);
            }
        });

        btnCompartirPlantas.setText("Compartir");
        btnCompartirPlantas.setMaximumSize(new java.awt.Dimension(102, 23));
        btnCompartirPlantas.setMinimumSize(new java.awt.Dimension(102, 23));
        btnCompartirPlantas.setPreferredSize(new java.awt.Dimension(102, 23));
        btnCompartirPlantas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCompartirPlantasActionPerformed(evt);
            }
        });

        btnCompartirMadera.setText("Compartir");
        btnCompartirMadera.setMaximumSize(new java.awt.Dimension(102, 23));
        btnCompartirMadera.setMinimumSize(new java.awt.Dimension(102, 23));
        btnCompartirMadera.setPreferredSize(new java.awt.Dimension(102, 23));
        btnCompartirMadera.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCompartirMaderaActionPerformed(evt);
            }
        });

        btnComerCarne.setText("Comer");
        btnComerCarne.setMaximumSize(new java.awt.Dimension(102, 23));
        btnComerCarne.setMinimumSize(new java.awt.Dimension(102, 23));
        btnComerCarne.setPreferredSize(new java.awt.Dimension(102, 23));
        btnComerCarne.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnComerCarneActionPerformed(evt);
            }
        });

        btnComerFrutas.setText("Comer");
        btnComerFrutas.setMaximumSize(new java.awt.Dimension(102, 23));
        btnComerFrutas.setMinimumSize(new java.awt.Dimension(102, 23));
        btnComerFrutas.setPreferredSize(new java.awt.Dimension(102, 23));
        btnComerFrutas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnComerFrutasActionPerformed(evt);
            }
        });

        lblACompartir.setText("Personaje a compartir:");

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
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btnComerCarne, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(pnlCarne, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnCompartirCarne, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(pnlFrutas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnCompartirFrutas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnComerFrutas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                    .addComponent(lblACompartir))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(pnlPlantas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnCompartirPlantas, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(pnlMadera, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnCompartirMadera, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(62, 62, 62)
                        .addComponent(btnSalir, javax.swing.GroupLayout.PREFERRED_SIZE, 107, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(cbxPersonajeACompartir, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(54, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(pnlMadera, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(pnlPlantas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(pnlFrutas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(pnlCarne, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(btnCompartirCarne, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnCompartirFrutas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnCompartirPlantas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnCompartirMadera, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(41, 41, 41)
                        .addComponent(btnSalir, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnComerCarne, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnComerFrutas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(lblACompartir)
                    .addComponent(cbxPersonajeACompartir, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(31, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnCompartirCarneActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCompartirCarneActionPerformed
		if(personaje.tieneCarne()){
			compartir("Carne", 0);
		}
    }//GEN-LAST:event_btnCompartirCarneActionPerformed

    private void btnCompartirFrutasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCompartirFrutasActionPerformed
        if(personaje.tieneFrutas()){
			compartir("Frutas", 1);
		}
    }//GEN-LAST:event_btnCompartirFrutasActionPerformed

    private void btnCompartirPlantasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCompartirPlantasActionPerformed
        if(personaje.tienePlantas()){
			compartir("Plantas", 2);
		}
    }//GEN-LAST:event_btnCompartirPlantasActionPerformed

    private void btnCompartirMaderaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCompartirMaderaActionPerformed
        if(personaje.tieneMadera()){
			compartir("Madera", 3);
		}
    }//GEN-LAST:event_btnCompartirMaderaActionPerformed

    private void btnComerCarneActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnComerCarneActionPerformed
        personaje.comer(0);
    }//GEN-LAST:event_btnComerCarneActionPerformed

    private void btnComerFrutasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnComerFrutasActionPerformed
        personaje.comer(1);
    }//GEN-LAST:event_btnComerFrutasActionPerformed

    private void btnSalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnSalirActionPerformed
        this.setVisible(false);
    }//GEN-LAST:event_btnSalirActionPerformed

	
	private void ponerPersonajesEnCbx(Personaje personaje, ArrayList<Personaje> personajes){
		for (Personaje personajeEnArrayList : personajes) {
			if(!personajeEnArrayList.equals(personaje)){
				cbxPersonajeACompartir.addItem(personajeEnArrayList.getNombre());
			}
		}
	}
	private void disableComida(Personaje personaje, ArrayList<Personaje> personajes){
		if(personaje.equals(personajes.get(1))){
			btnComerFrutas.setEnabled(false);
		} else if(personaje.equals(personajes.get(2))){
			btnComerCarne.setEnabled(false);
		}
	}
	
	private void compartir(String objeto, int posEnInv){
		personaje.getInventario()[posEnInv].usarRecurso(1);
		String strPersonajeACompartir = (String)cbxPersonajeACompartir.getSelectedItem();
		for (Personaje personajeEnArray : personajes) {
			if(personajeEnArray.getNombre().equals(strPersonajeACompartir)){
				personajeEnArray.añadirAInventario(new Recurso(objeto,1));
			}
		}
	}
	
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnComerCarne;
    private javax.swing.JButton btnComerFrutas;
    private javax.swing.JButton btnCompartirCarne;
    private javax.swing.JButton btnCompartirFrutas;
    private javax.swing.JButton btnCompartirMadera;
    private javax.swing.JButton btnCompartirPlantas;
    private javax.swing.JButton btnSalir;
    private javax.swing.JComboBox<String> cbxPersonajeACompartir;
    private javax.swing.JLabel lblACompartir;
    private javax.swing.JLabel lblCantidadCarne;
    private javax.swing.JLabel lblCantidadFrutas;
    private javax.swing.JLabel lblCantidadMadera;
    private javax.swing.JLabel lblCantidadPlantas;
    private javax.swing.JLabel lblCarneIcon;
    private javax.swing.JLabel lblFrutasIcon;
    private javax.swing.JLabel lblMaderaIcon;
    private javax.swing.JLabel lblPlantasIcon;
    private javax.swing.JPanel pnlCarne;
    private javax.swing.JPanel pnlFrutas;
    private javax.swing.JPanel pnlMadera;
    private javax.swing.JPanel pnlPlantas;
    // End of variables declaration//GEN-END:variables
}
