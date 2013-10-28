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
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client 
{
	private Hello server = null;

	public Client(String host) throws Exception
	{
		getRemoteRefToServer(host);
	}

	private void printMessage(String msg)
	{
		System.err.println("HELLO CLIENT: " + msg);
	}

	private void getRemoteRefToServer(String host) throws Exception
	{
		try {
			Registry registry = LocateRegistry.getRegistry(host);
			server = (Hello) registry.lookup(Hello.SERVER_REMOVE_NAME);
		} catch (Exception e) {
			printMessage("Client exception: " + e.toString());
			e.printStackTrace();
			throw e;
		}
	}


	public void runHelloExample() throws RemoteException
	{
		System.out.println( server.sayHello() );	
	}


	public void addMessageToServer(String message) throws RemoteException
	{
		server.addMessage(message);
	}

	public void  printAllMessages()
	{
		try
		{
			Messages box = server.getAllMessages();
			box.printAllMessages();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}


	public static void main(String[] args) {

		String host = (args.length < 1) ? null : args[0];

	
		
		try
		{
			InetAddress addr = InetAddress.getLocalHost();
			String localHosthostname = addr.getHostName();
			
			Client helloClient = new Client(host);
			helloClient.runHelloExample();
			helloClient.addMessageToServer("hello from " + localHosthostname);
			helloClient.printAllMessages();
		}
		catch(Exception e)
		{
		}
	}
}

