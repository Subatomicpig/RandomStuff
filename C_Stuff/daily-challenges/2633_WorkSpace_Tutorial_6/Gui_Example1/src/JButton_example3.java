

import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

import java.awt.event.*;
import javax.swing.event.*;

public class JButton_example3 implements ActionListener,ChangeListener
{
	//--------------------------------------------------------------------
	public void  stateChanged(ChangeEvent e) 
	{
		Font f =new Font( (String)fontlist.getSelectedItem()  , 
				Font.BOLD , 
				fontsize.getValue() );
		Text.setFont(f);
	}
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
		else if(e.getActionCommand().equals("Font"))
		{
			Font f =new Font( (String)fontlist.getSelectedItem()  , 
					Font.BOLD , 
					fontsize.getValue() );
			Text.setFont(f);

		}
		else if(e.getActionCommand().equals("Close"))
			System.exit(0);


	}

	//--------------------------------------------------------------------
	public JButton_example3()
	{
		mainWindow = new JFrame("JButton example");
		setUpWindow();
	}
	//--------------------------------------------------------------------
	public JPanel makeNavButtons()
	{
		JButton b;
		PictureButton bp;


		JPanel buttons =new JPanel( new GridLayout(3,3,3,3) );
		buttons.setBackground(Color.BLACK);
		buttons.setBorder( BorderFactory.createLineBorder(Color.RED, 5) );

		bp =new PictureButton("images/Arrows/TopL",".png"); 
		bp.setActionCommand("Top Left");
		bp.addActionListener(this); 
		buttons.add(bp);

		bp =new PictureButton("images/Arrows/Top",".png"); 
		bp.setActionCommand("Top");
		bp.addActionListener(this); 
		buttons.add(bp);

		bp =new PictureButton("images/Arrows/TopR",".png"); 
		bp.setActionCommand("Top Right");
		bp.addActionListener(this); 
		buttons.add(bp);


		bp =new PictureButton("images/Arrows/L",".png"); 
		bp.setActionCommand("Left");
		bp.addActionListener(this); 
		buttons.add(bp);


		bp =new PictureButton("images/Arrows/Center",".png"); 
		bp.setActionCommand("Center");
		bp.addActionListener(this); 
		buttons.add(bp);

		bp =new PictureButton("images/Arrows/R",".png"); 
		bp.setActionCommand("Right");
		bp.addActionListener(this); 
		buttons.add(bp);

		bp =new PictureButton("images/Arrows/BottomL",".png"); 
		bp.setActionCommand("Bottom Left");
		bp.addActionListener(this); 
		buttons.add(bp);

		bp =new PictureButton("images/Arrows/Bottom",".png"); 
		bp.setActionCommand("Bottom");
		bp.addActionListener(this); 
		buttons.add(bp);

		bp =new PictureButton("images/Arrows/BottomR",".png"); 
		bp.setActionCommand("Bottom Right");
		bp.addActionListener(this); 
		buttons.add(bp);

		return buttons;
	}
	//--------------------------------------------------------------------
	private void setUpWindow()
	{
		JButton b;

		Container con = mainWindow.getContentPane();
		con.setLayout( new GridLayout(1,2,5,5) );

		JPanel Display = new JPanel(new BorderLayout() );
		Display.setBorder( BorderFactory.createTitledBorder("Display") );
		Display.add(Text, BorderLayout.CENTER );

		JPanel Textpos =new JPanel( new GridLayout(1,1) );
		Textpos.setBorder( BorderFactory.createTitledBorder("Text Position") );
		Textpos.add(TextPosition);
		Display.add(Textpos, BorderLayout.SOUTH);


		con.add(Display);


		// set up the buttons
		JPanel Textpanel =new JPanel(new BorderLayout() );

		JPanel TextProperties = new JPanel( new GridLayout(0,2));
		TextProperties.setBorder( BorderFactory.createTitledBorder("Text Properties") );	
		Textpanel.add(TextProperties, BorderLayout.NORTH );


		// font selection
		TextProperties.add( new JLabel("Font:",JLabel.RIGHT));

		fontlist = new JComboBox(fonts);
		fontlist.addActionListener(this);
		fontlist.setActionCommand("Font");
		TextProperties.add( fontlist );

		TextProperties.add( new JLabel("Font size:",JLabel.RIGHT));

		fontsize = new JSlider(15,80,15);
		fontsize.addChangeListener(this);

		TextProperties.add( fontsize );

		JPanel Mainbuttons =new JPanel( new BorderLayout() );
		Textpanel.add(Mainbuttons,BorderLayout.CENTER);




		Mainbuttons.setBorder( BorderFactory.createTitledBorder("Text Placement") );
		Mainbuttons.add( makeNavButtons() ,BorderLayout.CENTER);

		b =new JButton("Exit Window");
		b.setActionCommand("Close");
		b.addActionListener(this);
		Mainbuttons.add(b,BorderLayout.SOUTH);

		con.add(Textpanel);


		// set beginning text properties
		Font f =new Font( (String)fontlist.getItemAt(0)  , 
				Font.BOLD , 
				fontsize.getValue() );
		Text.setFont(f);

		// setlocation of the window
		mainWindow.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		mainWindow.setSize(750,400);


		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		int x = (screen.width-750)/2;
		int y = (screen.height-400)/2; 

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
	private JComboBox fontlist;
	private JSlider fontsize;
	private String[] fonts = {"Courier", "Dialog", "Helvetica", "TimesRoman" };

	//--------------------------------------------------------------------
	public static void main(String[] args)
	{
		JButton_example3 ex = new JButton_example3();
		ex.show();
	}
}
