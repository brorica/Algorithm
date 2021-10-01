import java.io.*;
import java.util.*;

class Customer implements Comparable<Customer> {
    int id;
    int taskTime;
    int arriveTime;

    public Customer(int id, int taskTime, int arriveTime) {
        this.id = id;
        this.taskTime = taskTime;
        this.arriveTime = arriveTime;
    }

    public void decreaseTask(int time) {
        this.taskTime -= time;
    }

    public int getId() {
        return id;
    }

    public int getTaskTime() {
        return taskTime;
    }

    public int getArriveTime() {
        return arriveTime;
    }

    @Override
    public int compareTo(Customer c) {
        return this.arriveTime - c.getArriveTime();
    }
}

class Main {

    static int N, T, W, M; // 초기 은행 손님 수 , 필요 시간, 전체 경과 시간, 그 외 손님 수
    static int processTime = 0; // 전체 진행 시간
    static List<Integer> answer = new ArrayList<>();
    static Queue<Customer> readyQ = new LinkedList<>();  // 은행 줄
    static PriorityQueue<Customer> outQ = new PriorityQueue<>(); // 은행에 도착하지 않은 고객
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        input();
        loop();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        int id, requireTime, arriveTime;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            id = Integer.parseInt(st.nextToken());
            requireTime = Integer.parseInt(st.nextToken());
            readyQ.add(new Customer(id, requireTime, 0));
        }

        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            id = Integer.parseInt(st.nextToken());
            requireTime = Integer.parseInt(st.nextToken());
            arriveTime = Integer.parseInt(st.nextToken());
            outQ.add(new Customer(id, requireTime, arriveTime));
        }
    }

    private static void loop() {
        while (!readyQ.isEmpty()) {
            process(readyQ.peek());
        }
    }

    private static void process(Customer customer) {

        // T 내에 처리할 수 있던 거였을 때
        if (customer.getTaskTime() <= T) {
            writeAnswer(customer.getId(), customer.getTaskTime());
            processTime += customer.getTaskTime();
            searchOutQ();
            readyQ.remove();

        }
        // 그렇지 않다면 T만큼 처리하고 뒤로 보냄
        // 단, 처리 완료 시점에 이미 온 손님이 있다면 그 손님을 앞에 세움
        else {
            writeAnswer(customer.getId(), T);
            customer.decreaseTask(T);
            processTime += T;
            searchOutQ();
            readyQ.add(customer);
            readyQ.remove();
        }
    }

    private static void writeAnswer(int id, int taskTime) {
        for(int i=0;i<taskTime;i++)
            answer.add(id);
    }

    private static void searchOutQ() {
        if(outQ.isEmpty())
            return;
        while(!outQ.isEmpty()) {
            Customer customer = outQ.peek();
            if (processTime >= customer.getArriveTime())
                readyQ.add(outQ.poll());
            else
                break;
        }
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < W; i++)
            bw.write(answer.get(i) + "\n");
        bw.flush();
    }
}
