import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class VentanaCine {
    private JPanel principal;
    private JTextArea txtInformacion;
    private JButton btnComprar;
    private JComboBox<String> comboPeliculas;
    private JTextField txtNombre;
    private JSpinner spinnerEntradas;
    private JRadioButton rbFIFO;
    private JRadioButton rbLIFO;

    private Sala xmen = new Sala("XMEN");
    private Sala mario = new Sala("MARIO");
    private Sala batman = new Sala("BATMAN");

    public VentanaCine() {
        // Configuración inicial de componentes
        comboPeliculas.setModel(new DefaultComboBoxModel<>(new String[]{"XMEN", "MARIO", "BATMAN"}));
        spinnerEntradas.setModel(new SpinnerNumberModel(1, 1, 4, 1));

        // Agrupar radio buttons
        ButtonGroup grupoEstrategia = new ButtonGroup();
        grupoEstrategia.add(rbFIFO);
        grupoEstrategia.add(rbLIFO);
        rbFIFO.setSelected(true);

        btnComprar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String nombre = txtNombre.getText().trim();
                String pelicula = comboPeliculas.getSelectedItem().toString();
                int cantidad = (int) spinnerEntradas.getValue();
                boolean usarFIFO = rbFIFO.isSelected();

                if (nombre.isEmpty()) {
                    JOptionPane.showMessageDialog(principal, "Ingrese el nombre del cliente.");
                    return;
                }

                Sala salaSeleccionada = null;
                switch (pelicula) {
                    case "XMEN":
                        salaSeleccionada = xmen;
                        break;
                    case "MARIO":
                        salaSeleccionada = mario;
                        break;
                    case "BATMAN":
                        salaSeleccionada = batman;
                        break;
                }

                if (salaSeleccionada != null && salaSeleccionada.hayEspacio(cantidad)) {
                    Cliente cliente = new Cliente(nombre, pelicula, cantidad);
                    salaSeleccionada.venderEntradas(cantidad, cliente, usarFIFO);
                    actualizarInformacion(salaSeleccionada, usarFIFO);
                    txtNombre.setText("");
                } else {
                    JOptionPane.showMessageDialog(principal, "No hay suficientes espacios disponibles.");
                }
            }
        });
    }

    private void actualizarInformacion(Sala sala, boolean usarFIFO) {
        txtInformacion.setText("");
        txtInformacion.append("Estado actual:\n");
        txtInformacion.append("----------------\n");
        txtInformacion.append("XMEN - Vendidas: " + xmen.getVendidas() + ", Disponibles: " + xmen.getDisponibles() + "\n");
        txtInformacion.append("MARIO - Vendidas: " + mario.getVendidas() + ", Disponibles: " + mario.getDisponibles() + "\n");
        txtInformacion.append("BATMAN - Vendidas: " + batman.getVendidas() + ", Disponibles: " + batman.getDisponibles() + "\n");
        txtInformacion.append("----------------\n");
        txtInformacion.append("Últimas compras para " + sala.getNombre() + ":\n");

        if (usarFIFO) {
            for (Cliente c : sala.getColaFIFO()) {
                txtInformacion.append(c + "\n");
            }
        } else {
            for (Cliente c : sala.getPilaLIFO()) {
                txtInformacion.append(c + "\n");
            }
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Sistema de Cine");
        frame.setContentPane(new VentanaCine().principal);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 600);
        frame.setVisible(true);
    }
}
