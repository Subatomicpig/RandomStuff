import java.awt.*;
import javax.swing.*;

public class Layout_Examples
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
		Container con = window.getContentPane();

		//set layout manager
		/* GridLayout(int rows, int cols, int hgap, int vgap)
	       rows - the rows, with the value zero meaning any number of rows
               cols - the columns, with the value zero meaning any number of columns
               hgap - the horizontal gap
               vgap - the vertical gap*/

		con.setLayout(new GridLayout(2,2,10,10));

		con.add( makeContent("1","(0,0)") );
		con.add( makeContent("2","(0,1)") );
		con.add( makeContent("3","(1,0)") );
		con.add( makeContent("4","(1,1)") );

	}
	//--------------------------------------------------------------------
	public static void setupWindow2(JFrame window)
	{
		Container con = window.getContentPane();

		//set layout manager
		con.setLayout( new BorderLayout() );

		con.add( makeContent("1","EAST"), BorderLayout.EAST );
		con.add( makeContent("2","CENTER"), BorderLayout.CENTER );
		con.add( makeContent("3","NORTH"), BorderLayout.NORTH );
		con.add( makeContent("4","WEST)"), BorderLayout.WEST );
		con.add( makeContent("5","SOUTH"), BorderLayout.SOUTH );
	}

	//--------------------------------------------------------------------
	public static void setupWindow3(JFrame window)
	{
		Container con = window.getContentPane();

		//set layout manager
		con.setLayout( new BorderLayout() );


		JPanel east = new JPanel(new GridLayout(0,1));
		east.setBorder( BorderFactory.createTitledBorder("East") );

		for(int i = 0;i < 10; i++)
			east.add( makeContent(""+(i+1),"("+i+",0)") );
		con.add( east , BorderLayout.EAST );


		JPanel center = new JPanel(new GridLayout(2,2));
		center.setBorder( BorderFactory.createTitledBorder("Center") );
		center.add( makeContent("1","(0,0)") );
		center.add( makeContent("2","(0,1)") );
		center.add( makeContent("3","(1,0)") );
		center.add( makeContent("4","(1,1)") );
		con.add( center , BorderLayout.CENTER );


		con.add( makeContent("3","NORTH"), BorderLayout.NORTH );
		con.add( makeContent("4","WEST)"), BorderLayout.WEST );
		con.add( makeContent("5","SOUTH"), BorderLayout.SOUTH );
	}
	//--------------------------------------------------------------------
	public static void setupWindow4(JFrame window)
	{
		Container con = window.getContentPane();

		//set layout manager
		/* GridLayout(int rows, int cols, int hgap, int vgap)
	       rows - the rows, with the value zero meaning any number of rows
               cols - the columns, with the value zero meaning any number of columns
               hgap - the horizontal gap
               vgap - the vertical gap*/

		con.setLayout(new GridLayout(2,2,10,10));

		con.add( makeContent("1","(0,0)") );
		con.add( makeContent("2","(0,1)") );
		con.add( makeContent("3","(1,0)") );

	}
	//--------------------------------------------------------------------
	public static void setupWindow5(JFrame window)
	{
		Container con = window.getContentPane();

		//set layout manager
		con.setLayout( new BorderLayout() );

		con.add( makeContent("1","EAST"), BorderLayout.EAST );
		con.add( makeContent("2","CENTER"), BorderLayout.CENTER );
		con.add( makeContent("3","SOUTH"), BorderLayout.SOUTH );
	}

	//--------------------------------------------------------------------
	public static void setupWindow6(JFrame window)
	{
		Container con = window.getContentPane();

		//set layout manager
		/* GridLayout(int rows, int cols, int hgap, int vgap)
	       rows - the rows, with the value zero meaning any number of rows
               cols - the columns, with the value zero meaning any number of columns
               hgap - the horizontal gap
               vgap - the vertical gap*/

		con.setLayout(new GridLayout(2,2,10,10));

		con.add( makeContent("1","(0,0)") );


		JPanel panel= new JPanel( new BorderLayout() ); 
		panel.setBorder( BorderFactory.createTitledBorder("2") );
		panel.add( makeContent("1","EAST"), BorderLayout.EAST );
		panel.add( makeContent("2","CENTER"), BorderLayout.CENTER );
		panel.add( makeContent("3","NORTH"), BorderLayout.NORTH );
		panel.add( makeContent("4","WEST)"), BorderLayout.WEST );
		panel.add( makeContent("5","SOUTH"), BorderLayout.SOUTH );

		con.add( panel );


		con.add( makeContent("3","(1,0)") );
		con.add( makeContent("4","(1,1)") );
	}

	//--------------------------------------------------------------------
	public static void main(String[]args)
	{
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		int size= 300;
		int x = ((screen.width-(2*size)))/2;
		int y = ((screen.height-(2*size)))/2; 


		JFrame window1 = new JFrame("Grid Layout");
		JFrame window2 = new JFrame("BorderLayout");
		JFrame window3 = new JFrame("Combined Border and Grid");

		JFrame window4 = new JFrame("Grid Layout 2");
		JFrame window5 = new JFrame("BorderLayout 2");
		JFrame window6 = new JFrame("Combined Border and Grid 2");



		window1.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		window2.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		window3.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );

		window4.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		window5.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );
		window6.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE  );


		window1.setSize(size, size);
		window2.setSize(size, size);
		window3.setSize(size, size);
		window4.setSize(size, size);
		window5.setSize(size, size);
		window6.setSize(size, size);



		window1.setLocation(x-(size+10),y);
		window2.setLocation(x,y);
		window3.setLocation(x+(size+10),y);

		window4.setLocation(x-(size+10),y+(size+10));
		window5.setLocation(x,y+(size+10));
		window6.setLocation(x+(size+10),y+(size+10));


		setupWindow1(window1);
		setupWindow2(window2);
		setupWindow3(window3);

		setupWindow4(window4);
		setupWindow5(window5);
		setupWindow6(window6);


		window1.setVisible(true);
		window2.setVisible(true);
		window3.setVisible(true);

		window4.setVisible(true);
		window5.setVisible(true);
		window6.setVisible(true);
	}

}
