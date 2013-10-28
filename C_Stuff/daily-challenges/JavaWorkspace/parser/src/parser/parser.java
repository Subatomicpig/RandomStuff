package parser;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Hashtable;




//this is a example of how to read text files very very quickly
public class parser {

	static FileChannel inChannel = null;
	static MappedByteBuffer buffer = null;
	static Hashtable table = null;
	
	//the main class of this program
	public static void main(String [] args) throws IOException
	{
		int readings = 0;
		table = new Hashtable();
		final long startTime = System.currentTimeMillis();
		
		inChannel = new FileInputStream("test2.txt").getChannel();
		buffer = inChannel.map(FileChannel.MapMode.READ_ONLY, 0, inChannel.size());
		
		byte [] buff = new byte[(int) inChannel.size()];
		buffer.get(buff);
		
		BufferedReader in = new BufferedReader(new InputStreamReader(new ByteArrayInputStream(buff)));
		
		
		for(String line = in.readLine(); line != null; line = in.readLine())
		{
			//check if there is a error on this line of the file
			//pulls out the information for the mac address
			int start,stop = 0;
		
			start = line.indexOf("'");
			stop = line.indexOf("'", start + 1);
			String mac = line.substring(start + 1, stop);
			
			//this will get the v integer add these to a data structure to use to count
			System.out.println(line.substring(70,74));
		}
		
		System.out.println(readings);
		in.close();
		final long endTime = System.currentTimeMillis();
		
		System.out.println("Total Processing time:"  + (endTime - startTime) + "ms");
	}
}
	
	

