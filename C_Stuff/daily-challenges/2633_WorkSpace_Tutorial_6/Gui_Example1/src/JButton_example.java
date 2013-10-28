

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JButton_example implements ActionListener 
{
	//--------------------------------------------------------------------
	public void actionPerformed(ActionEvent e)
	{
		pressCount++;
		ButtonPressed.setText( e.getActionCommand() );
		PressedCount.setText(""+pressCount);
	}

	//--------------------------------------------------------------------
	public JButton_example()
	{
		setUpWindow();
	}
	//--------------------------------------------------------------------
	private void setUpWindow()
	{
		JButton b;

		Container con = mainWindow.getContentPane();
		con.setLayout( new BorderLayout() );

		JPanel Display = new JPanel(new GridLayout(0,2,5,5) );
		Display.setBorder( BorderFactory.createTitledBorder("Display") );    
		Display.add(new JLabel("Button Pressed:",JLabel.RIGHT) );
		Display.add(ButtonPressed);
		Display.add(new JLabel("Pressed Count:",JLabel.RIGHT) );
		Display.add(PressedCount);
		con.add(Display,BorderLayout.CENTER);


		// set up the buttons
		JPanel buttons =new JPanel( new GridLayout(0,1,3,3) );
		buttons.setBorder( BorderFactory.createTitledBorder("Buttons") );
		for(int i = 0; i< 5;i++)
		{
			b =new JButton("BLARG " + (i+1));
			b.addActionListener(this);
			buttons.add(b);
		}

		b =new JButton("Exit Window");
		b.setActionCommand("Close");
		b.addActionListener(this);
		buttons.add(b);

		con.add(buttons, BorderLayout.EAST);


		// setlocation of the window
		mainWindow.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		mainWindow.pack();

		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		int x = screen.width/2;
		int y = screen.height/2; 

		mainWindow.setLocation(x,y);


	}
	//--------------------------------------------------------------------
	public void show()
	{
		mainWindow.setVisible(true);
	}
	//--------------------------------------------------------------------
	private JFrame mainWindow = new JFrame("JButton example");
	private JLabel ButtonPressed  = new JLabel("None", JLabel.LEFT);
	private JLabel PressedCount  = new JLabel("0", JLabel.LEFT);
	private int pressCount = 0;

	//--------------------------------------------------------------------
	public static void main(String[] args)
	{
		JButton_example ex = new JButton_example();
		ex.show();
	}
}
