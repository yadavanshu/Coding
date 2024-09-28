package Projects.AutoTyper;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Robot;
import java.awt.event.KeyEvent;

public class AutoTyper {
    private static JTextArea textArea;
    private static JTextField speedField;

    public static void main(String[] args) {
        JFrame frame = new JFrame("Auto Typer - Java Version");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());

        textArea = new JTextArea(10, 30);
        speedField = new JTextField("100");

        JButton startButton = new JButton("Start Auto Typer");
        startButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Thread(() -> {
                    try {
                        autoType(textArea.getText(), Integer.parseInt(speedField.getText()));
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }).start();
            }
        });

        JPanel panel = new JPanel();
        panel.add(new JLabel("Enter Text:"));
        panel.add(new JScrollPane(textArea));
        panel.add(new JLabel("Typing Speed (ms per character):"));
        panel.add(speedField);
        panel.add(startButton);

        frame.add(panel, BorderLayout.CENTER);
        frame.setVisible(true);
    }

    private static void autoType(String text, int delay) throws Exception {
        Robot robot = new Robot();
        robot.setAutoDelay(delay);
        Thread.sleep(3000); // Give user time to focus on target window

        for (char ch : text.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                robot.keyPress(KeyEvent.VK_SHIFT);
            }
            robot.keyPress(Character.toUpperCase(ch));
            robot.keyRelease(Character.toUpperCase(ch));

            if (Character.isUpperCase(ch)) {
                robot.keyRelease(KeyEvent.VK_SHIFT);
            }
        }
    }
}
