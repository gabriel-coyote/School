//Gabriel Coyote
//CS 2365-001

class MessageBuffer_Response {
	String messageBuffer; int messageNum;
	int responseBuffer;

	boolean messageBufferFull = false;
	boolean responseBufferFull = false;

	/* SEND */
	synchronized int send(String message, int num) {
		//place message in buffer
		messageBuffer = message; messageNum = num;
		messageBufferFull = true;
		notify();

		while(responseBufferFull == false) {
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		}

		responseBufferFull = false;
		return responseBuffer;
	}


	/* RECIEVE */
	synchronized String recieve() {
		while(messageBufferFull == false) {
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("InterruptedException caught");
			}
		}

		messageBufferFull = false;
		return messageBuffer;
	}


	/*REPLY */
	synchronized void reply(int response) {
		//place response in response buffer
		responseBuffer = response;
		responseBufferFull = true;
		notify();
	}
}

/* PRODUCER THREAD */
class Producer implements Runnable{
	MessageBuffer_Response q;

	Producer(MessageBuffer_Response C){
		this.q = C;
		new Thread(this, "Producer").start();
	}

	public void run() {
		//Functionality code goes here
		System.out.println("Producer sent: (add, 5)");
		System.out.println("Consumer returned: "+q.send("add", 5) );
		System.out.println();

		System.out.println("Producer sent: (multiply, 9)");
		System.out.println("Consumer returned: "+q.send("multiply", 9) );
		System.out.println();

		System.out.println("Producer sent: (multiply, 4)");
		System.out.println("Consumer returned: "+q.send("multiply", 4) );
		System.out.println();

		System.out.println("Producer sent: (add, 3)");
		System.out.println("Consumer returned: "+q.send("add", 3) );
		System.out.println();

		System.out.println("Producer sent: (add, 10)");
		System.out.println("Consumer returned: "+q.send("add", 10) );
		System.out.println();

		System.out.println("Producer sent: (add, 30)");
		System.out.println("Consumer returned: "+q.send("add", 30) );
		System.out.println();

		System.out.println("Producer sent: (multiply, 7)");
		System.out.println("Consumer returned: "+q.send("multiply", 7) );
		System.out.println();
	}
}

/* CONSUMER THREAD */
class Consumer implements Runnable{
	MessageBuffer_Response q;

	Consumer(MessageBuffer_Response C){
		this.q = C;
		new Thread(this, "Consumer").start();
	}

	public void run() {
		//Functionality code goes here
		class SimpleCalculation{
			public int add(int num) {
				num += 10;
				return num;
			}

			public int multiply(int num) {
				num *= 10;
				return num;
			}
		}

		SimpleCalculation calc = new SimpleCalculation();

		/* Seven messages are being receive */
		for(int i = 0; i < 7; i++) {
			if(q.recieve().equals("add")) {
				q.reply(calc.add(q.messageNum));

			}else {
				q.reply(calc.multiply(q.messageNum));
			}
		}
	}
}









public class MultiThread_v1 {
	public static void main(String[] args) {
		MessageBuffer_Response via = new MessageBuffer_Response();

		new Producer(via);
		new Consumer(via);

	}

}
