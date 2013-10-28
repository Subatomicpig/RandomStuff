

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class JButton_example2 implements ActionListener 
{
	//--------------------------------------------------------------------
	public void actionPerformed(ActionEvent e)
	{
		if(e.getActionCommand().equals("Top Left"))
		{
			Text.setHorizontalAlignment(JLabel.LEFT);
			Text.setVerticalAlignment(JLabel.TOP); 
			TextPosition.setText("TOP LEFT");
		}
		else if(e.getActionCommand().equals("Top"))
		{
			Text.setHorizontalAlignment(JLabel.CENTER);
			Text.setVerticalAlignment(JLabel.TOP);
			TextPosition.setText("TOP");
		}
		else if(e.getActionCommand().equals("Top Right"))
		{
			Text.setHorizontalAlignment(JLabel.RIGHT);
			Text.setVerticalAlignment(JLabel.TOP);
			TextPosition.setText("TOP RIGHT");
		}
		else if(e.getActionCommand().equals("Left"))
		{
			Text.setHorizontalAlignment(JLabel.LEFT);
			Text.setVerticalAlignment(JLabel.CENTER); 
			TextPosition.setText("LEFT");
		}
		else if(e.getActionCommand().equals("Center"))
		{
			Text.setHorizontalAlignment(JLabel.CENTER);
			Text.setVerticalAlignment(JLabel.CENTER);
			TextPosition.setText("CENTER");
		}
		else if(e.getActionCommand().equals("Right"))
		{
			Text.setHorizontalAlignment(JLabel.RIGHT);
			Text.setVerticalAlignment(JLabel.CENTER);
			TextPosition.setText("RIGHT");
		}
		else if(e.getActionCommand().equals("Bottom Left"))
		{
			Text.setHorizontalAlignment(JLabel.LEFT);
			Text.setVerticalAlignment(JLabel.BOTTOM); 
			TextPosition.setText("BOTTOM LEFT");
		}
		else if(e.getActionCommand().equals("Bottom"))
		{
			Text.setHorizontalAlignment(JLabel.CENTER);
			Text.setVerticalAlignment(JLabel.BOTTOM);
			TextPosition.setText("BOTTOM");
		}
		else if(e.getActionCommand().equals("Bottom Right"))
		{
			Text.setHorizontalAlignment(JLabel.RIGHT);
			Text.setVerticalAlignment(JLabel.BOTTOM);
			TextPosition.setText("BOTTOM RIGHT");
		}
		else if(e.getActionCommand().equals("Close"))
			System.exit(0);


	}

	//--------------------------------------------------------------------
	public JButton_example2()
	{
		mainWindow = new JFrame("JButton example");
		setUpWindow();
	}
	//--------------------------------------------------------------------
	private void setUpWindow()
	{



		JButton b;

		Container con = mainWindow.getContentPane();
		con.setLayout( new GridLayout(1,2,5,5) );

		JPanel Display = new JPanel(new BorderLayout() );   
		Display.add(Text, BorderLayout.CENTER );

		JPanel Textpos =new JPanel( new GridLayout(1,1) );
		Textpos.setBorder( BorderFactory.createTitledBorder("Text Position") );
		Textpos.add(TextPosition);
		Display.add(Textpos, BorderLayout.SOUTH);


		con.add(Display);


		// set up the buttons
		JPanel Mainbuttons =new JPanel( new BorderLayout() );
		Mainbuttons.setBorder( BorderFactory.createTitledBorder("Buttons") );


		JPanel buttons =new JPanel( new GridLayout(3,3,3,3) );
		b =new JButton("Top Left"); b.addActionListener(this); buttons.add(b);
		b =new JButton("Top"); b.addActionListener(this); buttons.add(b);
		b =new JButton("Top Right"); b.addActionListener(this); buttons.add(b);


		b =new JButton("Left"); b.addActionListener(this); buttons.add(b);
		b =new JButton("Center"); b.addActionListener(this); buttons.add(b);
		b =new JButton("Right"); b.addActionListener(this); buttons.add(b);

		b =new JButton("Bottom Left"); b.addActionListener(this); buttons.add(b);
		b =new JButton("Bottom"); b.addActionListener(this); buttons.add(b);
		b =new JButton("Bottom Right"); b.addActionListener(this); buttons.add(b);

		Mainbuttons.add(buttons,BorderLayout.CENTER);

		b =new JButton("Exit Window");
		b.setActionCommand("Close");
		b.addActionListener(this);
		Mainbuttons.add(b,BorderLayout.SOUTH);

		con.add(Mainbuttons);


		// setlocation of the window
		mainWindow.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		mainWindow.setSize(750,300);


		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		int x = (screen.width-750)/2;
		int y = (screen.height-300)/2; 

		mainWindow.setLocation(x,y);

	}
	//--------------------------------------------------------------------
	public void show()
	{
		mainWindow.setVisible(true);
	}
	//--------------------------------------------------------------------
	private JFrame mainWindow;
	private JLabel Text  = new JLabel("Text", JLabel.CENTER);
	private JLabel TextPosition  = new JLabel("CENTER", JLabel.CENTER);

	//--------------------------------------------------------------------
	public static void main(String[] args)
	{
		JButton_example2 ex = new JButton_example2();
		ex.show();
	}
}
