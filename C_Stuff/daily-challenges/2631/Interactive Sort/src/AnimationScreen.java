import java.awt.Paint;

import edu.umd.cs.piccolo.PNode;
import edu.umd.cs.piccolo.nodes.PPath;
import edu.umd.cs.piccolo.nodes.PText;
import edu.umd.cs.piccolox.PFrame;

public abstract class AnimationScreen extends PFrame {
	private static final long serialVersionUID = 1L;

	private boolean isInitialized;

	public AnimationScreen () {
		super ();

		isInitialized = false;
	}

	public final void initialize () {
		// Remove the default pan and zoom event handlers
		getCanvas ().setPanEventHandler (null);
		getCanvas ().setZoomEventHandler (null);

		addInitialNodes ();
		
		isInitialized = true;
	}

	public abstract void addInitialNodes ();

	public void waitForInitialization () {
		while (!isInitialized) {
			try {
				Thread.sleep (100);
			} catch (InterruptedException e) {
				// Whatever, I do what I want.
			}
		}
	}
	
	private void addAt (PNode node, double x, double y) {
		// position item at location
		node.translate (x, y);
		
		// add text box to canvas (screen)
		getCanvas ().getLayer ().addChild (node);
	}

	public TextBoxNode addTextBox (double x, double y, double width, double height, String text) {
		TextBoxNode newNode = new TextBoxNode (0, 0, width, height, text);
		
		addAt (newNode, x, y);

		return newNode;
	}

	public PText addText (double x, double y, String text) {
		PText newNode = new PText (text);

		addAt (newNode, x, y);

		return newNode;
	}

	public PNode addColouredBox (double x, double y, double width, double height, Paint colour) {
		PNode newNode = new PNode ();
		// A node will not be visible until its bounds and paint are set.
		newNode.setBounds (0, 0, width, height);
		newNode.setPaint (colour);

		addAt (newNode, x, y);

		return newNode;
	}
	
	public PPath addElipse (double x, double y, double width, double height) {
		PPath newNode = PPath.createEllipse (0, 0, (float) width, (float) height);

		addAt (newNode, x, y);
		
		return newNode;
	}
	
	public PPath addRectangle (double x, double y, double width, double height) {
		PPath newNode = PPath.createRectangle (0, 0, (float) width, (float) height);

		addAt (newNode, x, y);
		
		return newNode;
	}
	
	// lines are difficult to animate...
	public PPath addLine (double x1, double y1, double x2, double y2) {
		PPath newNode = PPath.createLine ((float) x1, (float) y1, (float) x2, (float) y2);

		// add text box to canvas (screen)
		getCanvas ().getLayer ().addChild (newNode);
		
		return newNode;
	}
	
	// polynomials are difficult to animate...
	public PPath addPolynomial (float[] xs, float[] ys) {
		PPath newNode = PPath.createPolyline (xs, ys);

		// add text box to canvas (screen)
		getCanvas ().getLayer ().addChild (newNode);
		
		return newNode;
	}
}