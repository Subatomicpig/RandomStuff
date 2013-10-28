import java.awt.Paint;
import java.awt.Shape;
import java.awt.geom.Rectangle2D;

import edu.umd.cs.piccolo.nodes.PPath;
import edu.umd.cs.piccolo.nodes.PText;
import edu.umd.cs.piccolo.util.PBounds;

public class TextBoxNode extends PPath {
	private static final long serialVersionUID = 1L;

	private PText nodeLabel;

	public TextBoxNode (Shape aShape, String newText) {
		super (aShape);

		nodeLabel = new PText (newText);
		nodeLabel.setPickable (false);

		this.addChild (nodeLabel);
		
		centerText();
	}

	public TextBoxNode (double x, double y, double width, double height, String text) {
		this (new Rectangle2D.Double (x, y, width, height), text);
	}

	public Paint getTextPaint () {
		return nodeLabel.getTextPaint ();
	}

	public void setTextPaint (Paint textPaint) {
		nodeLabel.setTextPaint (textPaint);
	}

	public String getText () {
		return nodeLabel.getText ();
	}

	public void setText (String newText) {
		nodeLabel.setText (newText);
		centerText ();
	}

	private void centerText () {
		PBounds ourBounds = this.getBounds ();
		nodeLabel.centerBoundsOnPoint (ourBounds.getCenterX (), ourBounds.getCenterY ());
	}
}
