import java.io.*;
import java.net.*;
public class Client{

	public static void main(String args[])
	{
	/*Socket s1 = new Socket("127.0.0.1",1154);
	
	try
	{

		
		BufferedReader input;
		PrintStream out;
		Console console = System.console();
		while(true)
		{	
		
			out = new PrintStream(s1.getOutputStream());
			System.out.println("Enter First Number");
			String num1 = console.readLine();
			out.println(num1);
			System.out.println("Enter Second Number");
			String num2 = console.readLine();
			out.println(num2);
			input = new BufferedReader(new InputStreamReader(s1.getInputStream()));
			System.out.println("Addition is : "+input.readLine());
			//input.close();
			
		}
	}
	catch(SocketException e)
	{
		System.out.println("Server Closed Connection!");
		
		s1.close();
	}*/
		
	int numC;
	
	Console console = System.console();
	
	System.out.println("Number of Clients: ");	
	numC = Integer.parseInt(console.readLine());
	
	MultiThred mrt = new MultiThred();

	
	

	try
	{
		
		Thread t[] = new Thread[numC];
		for(int i=0;i<numC;i++)
		{
			t[i] = new Thread(mrt);
			t[i].start();
		}
		for(int i=0;i<numC;i++)
			t[i].join();
		
	}
	catch(Exception e)
	{
		System.out.println("Interrupted");
	}

	System.out.println("Exit");

	}

	
	
}

class MultiThred implements Runnable
{

	public static int Count = 0;
	BufferedReader input;
	PrintStream out;
	Console console = System.console();
	

	 public synchronized void run()
	{
		
	
		try
		{
		
			Socket s1 = new Socket("127.0.0.1",11154);
			
		
				System.out.println("Thread : "+Count++);
				out = new PrintStream(s1.getOutputStream());
				System.out.println("Enter First Number");
				String num1 = console.readLine();
				
				out.println(num1);
				out.flush();
				System.out.println("Enter Second Number");
				String num2 = console.readLine();
				out.println(num2);
				out.flush();				
				input = new BufferedReader(new InputStreamReader(s1.getInputStream()));
				System.out.println("Addition is : "+input.readLine());
				//input.close();
				out.close();
				//s1.close();
			//Thread.sleep(100);
		
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.out.println("Server Closed Connection!");
		

			//s1.close();
		}

		
		
	}
}
