import java.awt.*;
import javax.swing.*;

public class JFrame_examples
{

	//--------------------------------------------------------------------
	public static JPanel makeContent(String title, String label_text)
	{
		JPanel panel = new JPanel(new GridLayout(1,1) );

		panel.setBorder( BorderFactory.createTitledBorder(title) );
		panel.add( new JLabel(label_text, JLabel.CENTER) );

		return panel;
	}
	//--------------------------------------------------------------------
	public static void setupWindow1(JFrame window)
	{
		// add some other components to the window
		Container con = window.getContentPane();

		//settlayout manager
		con.setLayout(new GridLayout(0,1));

		//add some content

		JPanel random = new JPanel();
		JPanel Display = new JPanel();
		Display.setLayout(new GridLayout(0,1));
		random.setLayout(new GridLayout(0,1));
		
		//set a border
		Display.setBorder(
				BorderFactory.createCompoundBorder(
						BorderFactory.createTitledBorder("Display"),
						BorderFactory.createEmptyBorder(5,5,5,5))
				);

		Display.add( new JLabel("Hello World") );
	
		

		con.add( new JLabel("***",JLabel.CENTER) );
		con.add(Display);
		con.add( new JLabel("***",JLabel.CENTER) );


	}
	//--------------------------------------------------------------------
	public static void setupWindow2(JFrame window)
	{
		// add some other components to the window
		Container con = window.getContentPane();

		//settlayout manager
		con.setLayout(new GridLayout(0,1));

		//add some content

		JPanel Display = new JPanel();
		Display.setLayout(new GridLayout(0,1));

		//set a border
		Display.setBorder(
				BorderFactory.createCompoundBorder(
						BorderFactory.createTitledBorder("Display"),
						BorderFactory.createEmptyBorder(5,5,5,5))
				);

		Display.add( new JLabel("Hello World") );


		con.add( new JLabel("***",JLabel.CENTER) );
		con.add(Display);
		con.add( new JLabel("***",JLabel.CENTER) );

	}
	//--------------------------------------------------------------------
	public static void main(String[]args)
	{
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		int x = screen.width/2;
		int y = screen.height/2; 

		/*

	 setDefaultLookAndFeelDecorated(boolean defaultLookAndFeelDecorated)
          Provides a hint as to whether or not newly created JFrames should have 
	  their Window decorations (such as borders, widgets to close the window,
	  title...) provided by the current look and feel.
		 */

		JFrame.setDefaultLookAndFeelDecorated(false);


		JFrame window1 = new JFrame("Window 1");
		JFrame window2 = new JFrame("Window 2");


		window1.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		window2.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );


		window1.setSize(200, 200);


		window1.setLocation(x-210,y);
		window2.setLocation(x,y);



		setupWindow1(window1);
		setupWindow2(window2);


		window1.setVisible(true);

		window2.pack(); /* set the size of the window based upon added content */
		window2.setVisible(true);

	}


}
