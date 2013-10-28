package example;

import java.util.ArrayList;

public class Messages implements java.io.Serializable
{
   private ArrayList<String> messages = new ArrayList<String>();
	
   
   public void addMessage(String data)
   {
	   messages.add(data);
   }
  
   
   public void printAllMessages()
   {
	   for(String msg : messages)
	   {
		   System.out.println(msg);
	   }
   }
	
}
