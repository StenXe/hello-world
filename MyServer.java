import java.io.*;
import java.net.*;
import java.util.concurrent.*;
public class MyServer {

    private static MyServer server; 
    private ServerSocket serverSocket;

    /**
     * This executor service has 10 threads. 
     * So it means your server can process max 10 concurrent requests.
     */
    private ExecutorService executorService = Executors.newFixedThreadPool(10);        

    public static void main(String[] args) throws IOException {
        server = new MyServer();
        server.runServer();
    }

    private void runServer() {        
        int serverPort = 11154;
        try {
            System.out.println("Starting Server");
            serverSocket = new ServerSocket(serverPort); 

            while(true) {
                System.out.println("Waiting for request");
                try {
                    Socket s = serverSocket.accept();
                    System.out.println("Processing request");
                    executorService.submit(new ServiceRequest(s));
                } catch(IOException ioe) {
                    System.out.println("Error accepting connection");
                    ioe.printStackTrace();
                }
            }
        }catch(IOException e) {
            System.out.println("Error starting Server on "+serverPort);
            e.printStackTrace();
        }
    }

    //Call the method when you want to stop your server
    private void stopServer() {
        //Stop the executor service.
        executorService.shutdownNow();
        try {
            //Stop accepting requests.
            serverSocket.close();
        } catch (IOException e) {
            System.out.println("Error in server shutdown");
            e.printStackTrace();
        }
        System.exit(0);
    }

    class ServiceRequest implements Runnable {

        private Socket socket;

        public ServiceRequest(Socket connection) {
            this.socket = connection;
        }

        public void run() {

            //Do your logic here. You have the `socket` available to read/write data.

            //Make sure to close

		PrintStream out;
		BufferedReader input;
			
		//System.out.println("Connected by "+s1.getInetAddress());

	try	
	{
		input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	
		String num1 = input.readLine();
		System.out.println("Num recieved");				
		System.out.println(num1);
	
		String num2 = input.readLine();		
		System.out.println(num2);
	
		out = new PrintStream(socket.getOutputStream());

		out.println(Integer.parseInt(num1)+Integer.parseInt(num2));

	}
	catch(Exception e)
	{
		e.printStackTrace();
	}

            try {
                socket.close();
            }catch(IOException ioe) {
                System.out.println("Error closing client connection");
            }
        }        
    }
}
