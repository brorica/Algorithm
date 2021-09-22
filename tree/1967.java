import java.io.*;
import java.util.*;

class Node {
    private int number;
    private int cost;

    public Node(int number, int cost) {
        this.number = number;
        this.cost = cost;
    }

    public int getNumber() {
        return number;
    }

    public int getCost() {
        return cost;
    }
}

public class Main {

    private static int v, max = 0, maxNode = 1;
    private static boolean[] visit;
    private static ArrayList<Node>[] tree;

    public static void main(String[] args) throws Exception {
        input();
        visit = new boolean[v + 1];
        dfs(1, 0);
        visit = new boolean[v + 1];
        dfs(maxNode, 0);
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        v = Integer.parseInt(br.readLine());
        tree = new ArrayList[v + 1];

        for (int i = 1; i <= v; i++)
            tree[i] = new ArrayList<>();

        for (int i = 0; i < v - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken());
            int number = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            tree[index].add(new Node(number, cost));
            tree[number].add(new Node(index, cost));
        }
    }

    private static void dfs(int current, int totalCost) {
        if(visit[current]) {
            return ;
        }
        if(totalCost > max) {
            max = totalCost;
            maxNode = current;
        }
        visit[current] = true;
        int len = tree[current].size();
        for (int i = 0; i < len; i++) {
            int thereNum = tree[current].get(i).getNumber();
            int thereCost = tree[current].get(i).getCost();
            dfs(thereNum, totalCost + thereCost);
        }
    }


    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(max));
        bw.flush();
    }
}