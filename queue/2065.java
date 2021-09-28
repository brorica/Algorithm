import java.io.*;
import java.util.*;

class TimeTable {
    int order;      // 입력된 순서
    int arriveTime; // 도착한 시간

    public TimeTable(int order, int arriveTime) {
        this.order = order;
        this.arriveTime = arriveTime;
    }

    public int getOrder() {
        return order;
    }

    public int getArriveTime() {
        return arriveTime;
    }
}

class Main {
    static int M, t, N;
    static int currentTime = 0;
    static int currentPosition = 0;     // 0 : left, 1 : right
    static Queue<TimeTable>[] timeQ = new LinkedList[2];
    static Queue<TimeTable> ship = new LinkedList<>();
    static int[] answer;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        answer = new int[N + 1];

        for (int i = 0; i < 2; i++)
            timeQ[i] = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int arriveTime = Integer.parseInt(st.nextToken());
            String position = st.nextToken();
            // 배가 처음 움직이는 시간은 첫 입력에서 받는 도착 시간
            if(i == 0)
                currentTime = arriveTime;
            // 왼쪽, 오른쪽 타임테이블 큐 만듬
            if (position.equals("left"))
                timeQ[0].add(new TimeTable(i, arriveTime));
            else
                timeQ[1].add(new TimeTable(i, arriveTime));
        }
    }

    private static void solve() {
        while (!(timeQ[0].isEmpty() && timeQ[1].isEmpty())) {
            if (!tryLoad()) {
                waitPassenger();
                tryLoad();
            }
            moveShip();
        }
    }

    // 현재 방향에서 도착한 승객 싣음
    private static boolean tryLoad() {
        if(timeQ[currentPosition].isEmpty())
            return false;

        while (!timeQ[currentPosition].isEmpty()) {
            TimeTable timeTable = timeQ[currentPosition].peek();
            // 아직 도착하지 않았으면 태우지 않음
            if (timeTable.getArriveTime() > currentTime)
                break;
            ship.add(timeTable);
            timeQ[currentPosition].remove();
            // 최대 인원 수용시 승객 그만 싣음
            if(ship.size() == M)
                return true;
        }
        return !ship.isEmpty();
    }

    // 배를 반대쪽으로 움직임
    private static void moveShip() {
        currentTime += t;
        while (!ship.isEmpty()) {
            TimeTable timeTable = ship.poll();
            answer[timeTable.getOrder()] = currentTime;
        }
        currentPosition ^= 1;
    }

    private static void waitPassenger() {
        // 왼쪽 방향엔 더이상 승객이 없을 때
        if (timeQ[0].isEmpty()) {
            currentTime = refreshTime(timeQ[1].peek().getArriveTime());
            return;
        }
        // 오른쪽 방향엔 더이상 승객이 없을 때
        else if (timeQ[1].isEmpty()) {
            currentTime = refreshTime(timeQ[0].peek().getArriveTime());
            return;
        }
        // 양방향에서 웨이팅이 있을 경우 가장 빠른 쪽으로 감
        TimeTable current = timeQ[currentPosition].peek();
        TimeTable opposite = timeQ[currentPosition ^ 1].peek();
        if (current.getArriveTime() <= opposite.arriveTime)
            currentTime = refreshTime(current.getArriveTime());
        else
            currentTime = refreshTime(opposite.getArriveTime());
    }

    // 만약 웨이팅 시간이 현재 시간보다 길다면 웨이팅 시간으로 갱신
    private static int refreshTime(int arriveTime) {
        if(currentTime > arriveTime)
            return currentTime;
        return arriveTime;
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < N; i++)
            bw.write(answer[i] + "\n");
        bw.flush();
    }
}
