package Lab11;
import java.awt.GridLayout;
import javax.swing.*;        

public class Lab11 {
    
   public static void main(String[] args) {
        createAndShowGUI();
   }
   
   private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(100,100);//width, height);
        frame.setLocation(200,200);//x, y);
        frame.setLayout(new GridLayout(1,2));

        JTextArea textArea = new JTextArea(5, 20);
        textArea.setEditable(false);
        
        JScrollPane scrollPane = new JScrollPane(textArea);
        frame.getContentPane().add(scrollPane);
        
        JLabel label = new JLabel("The sum of the numbers in the matrix is: ");
        frame.getContentPane().add(label);

        textArea.setText("The matrix should print here");
        
        //Display the window.
        frame.pack();
        frame.setVisible(true);
        
        readAndDisplayMatrix(frame, textArea, label);
    }
   
   private static void readAndDisplayMatrix(JFrame myFrame, JTextArea myText,
                                            JLabel myLabel) {
	   myFrame.setTitle("Lab 11");
	   int[][] myMatrix = {{1,2,3,4},{4,5,6,7},{7,8,9,10}};
	   String matrix = "";
	   int sum = 0;
	   
	   for(int i = 0; i < myMatrix.length; i++) {
		   for(int j = 0; j < myMatrix[0].length; j++) {
			   sum += myMatrix[i][j];
			   matrix += myMatrix[i][j] + " ";
		   }
		   matrix += "\n";
	   }
	   
	   myFrame.setSize(350,200);
	   myFrame.setLayout(new GridLayout(2,1));
	   myText.setText(matrix);
	   myLabel.setText("The sum of the numbers in the matrix is: " + sum);
	   myFrame.setVisible(true);
   }    
}