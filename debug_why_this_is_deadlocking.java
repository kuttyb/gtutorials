public class Main2 {
    public static void main(String args[]){
        Counter c = new Counter();
        Messager m = new Messager (c);
        Printer p1 = new Printer (c,"Interval 7 Message!",7);
        Printer p2 = new Printer (c,"Interval 15 message!",15);

        m.start();
        p1.start();
        p2.start();
    }
}

class Messager extends Thread {
    private Counter c;
    Messager ( Counter c ){
        this.c = c;
    }

    @Override
    public void run() {
        while(true){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) { return; }
        
            c.countOnce();
            System.out.print(c.getCount() + " "); // [kutty] This is the problem, now all 3 threads are waiting !!
	    // Get countOnce to return a value and cache it locally for printing
        }
    }
}

class Printer extends Thread {
    private Counter c;
    public String message;
    public int interval;
    Printer ( Counter c, String m, int i ){
        this.c = c;
        this.message = m;
        this.interval = i;
    }

    @Override
    public void run() {
        while(true){
            int t = c.getCount();
            if(t%this.interval == 0){
                System.out.println("\n" + this.message);
            }
        }
    }
}

class Counter {
    private int count;
    private boolean locked = false;

    synchronized void countOnce () {
        while(locked){
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        this.count += 1;
        this.locked = true;
        notify();
    }

    synchronized int getCount() {
        while(!locked){
            try {
                wait();
            } catch (InterruptedException e) { }
        }
        locked = false;
        notify();
        return count;
    }
}

