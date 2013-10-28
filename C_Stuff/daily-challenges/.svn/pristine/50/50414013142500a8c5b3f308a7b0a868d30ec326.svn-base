import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


public class PictureButton extends JButton
{

	//filename = path to file,with not file extension
	public PictureButton(String filename, String file_tag)
	{
		super();

		setRolloverEnabled(true);

		ImageIcon normal 
		= new ImageIcon(Toolkit.getDefaultToolkit().getImage(filename+file_tag));
		ImageIcon mouse 
		= new ImageIcon(Toolkit.getDefaultToolkit().getImage(filename+"M"+file_tag));
		ImageIcon click 
		= new ImageIcon(Toolkit.getDefaultToolkit().getImage(filename+"D"+file_tag));


		setPressedIcon(click);
		setRolloverIcon(mouse);
		setRolloverSelectedIcon(click);
		setIcon(normal);

		//setSize( mouse.getIconWidth() , mouse.getIconHeight() );
		setPreferredSize( new Dimension( mouse.getIconWidth() , mouse.getIconHeight() ) );

		setMinimumSize( new Dimension( mouse.getIconWidth() , mouse.getIconHeight() ) );

		setContentAreaFilled(false);
		setBorderPainted(false);
		setFocusPainted(false);
	}

}
