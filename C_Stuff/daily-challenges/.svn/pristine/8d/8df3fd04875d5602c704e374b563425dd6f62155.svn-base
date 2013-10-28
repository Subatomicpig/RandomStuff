/*
 * Copyright (c) 2004, Oracle and/or its affiliates. All rights reserved.
 *  
 * Redistribution and use in source and binary forms, with or 
 * without modification, are permitted provided that the following 
 * conditions are met:
 * 
 * -Redistributions of source code must retain the above copyright  
 *  notice, this list of conditions and the following disclaimer.
 * 
 * -Redistribution in binary form must reproduce the above copyright 
 *  notice, this list of conditions and the following disclaimer in 
 *  the documentation and/or other materials provided with the 
 *  distribution.
 *  
 * Neither the name of Oracle or the names of 
 * contributors may be used to endorse or promote products derived 
 * from this software without specific prior written permission.
 * 
 * This software is provided "AS IS," without a warranty of any
 * kind. ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND
 * WARRANTIES, INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY
 * EXCLUDED. SUN MICROSYSTEMS, INC. ("SUN") AND ITS LICENSORS SHALL
 * NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF
 * USING, MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS
 * DERIVATIVES. IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE FOR
 * ANY LOST REVENUE, PROFIT OR DATA, OR FOR DIRECT, INDIRECT,
 * SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER
 * CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING OUT OF
 * THE USE OF OR INABILITY TO USE THIS SOFTWARE, EVEN IF SUN HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *  
 * You acknowledge that Software is not designed, licensed or 
 * intended for use in the design, construction, operation or 
 * maintenance of any nuclear facility.
 */
package example;

import java.net.InetAddress;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class Server implements Hello {

	private Messages systemMessages = new Messages();

	public Server() {}

	/**
	 * 
	 */
	public String sayHello() throws RemoteException
	{
		printMessage("Got hello Request");
		return "Hello, world!";
	}

	public void addMessage(String msg)  throws RemoteException
	{
		systemMessages.addMessage(msg);  
	}

	public Messages getAllMessages() throws RemoteException
	{
		return systemMessages;
	}

	/**
	 * 
	 * @param msg
	 */
	private void printMessage(String msg)
	{
		System.err.println("HELLO SERVER: " + msg);
	}

	/**
	 * 
	 */
	public void run()
	{
		try {
			printMessage("Starting up");
			Hello stub = (Hello) UnicastRemoteObject.exportObject(this, 0);

			// Bind the remote object's stub in the registry
			Registry registry = LocateRegistry.getRegistry();

			registry.bind(SERVER_REMOVE_NAME, stub);

			printMessage("Ready");
			
			InetAddress addr = InetAddress.getLocalHost();
			String hostname = addr.getHostName();
			
			printMessage("Running on: " + hostname );

			runCommandPromt();

		} catch (Exception e) {
			printMessage("Server exception: " + e.toString());
			e.printStackTrace();
		}


	}


	/**
	 * 
	 */
	private void shutDown()
	{
		try
		{
			printMessage("Shutting down");

			Registry registry = LocateRegistry.getRegistry();
			registry.unbind(SERVER_REMOVE_NAME);

		}
		catch(Exception e){}

		System.exit(1);
	}

	/**
	 * 
	 */
	public void runCommandPromt()
	{
		boolean end = false;
		Scanner input = new Scanner( System.in );

		while(!end)
		{
			printMessage(">");
			String command =  input.nextLine().trim();

			if(command.compareToIgnoreCase("help") == 0)
			{
				printMessage( String.format("%10s %s", "Help", "List all commands") );
				printMessage( String.format("%10s %s", "Quit", "Shutdown the server") );
			}
			else if(command.compareToIgnoreCase("quit") == 0)
			{
				end = true;
				shutDown();
			}
		}
	}

	/**
	 * 
	 * @param args
	 */
	public static void main(String args[]) 
	{
		Server s = new Server();
		s.run();
	}
}