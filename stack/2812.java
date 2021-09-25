import java.io.*;
import java.util.*;

/**
 * 스택이 비어있지 않을 때
 * 스택의 top과 현재 index의 수 중
 * index가 더 크다면 스택을 pop 시킴
 * 매 루프마다 현재 index를 push
 */

public class Main {

    static int n, k;
    static String text;
    static Stack<Integer> answer = new Stack<>();

    public static void main(String[] args) throws Exception {
        input();
        solve();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        text = br.readLine();
    }

    private static void solve() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num = text.charAt(i) - '0';
            for(;count<k && !answer.isEmpty();count++) {
                int peek = answer.peek();
                if (peek < num)
                    answer.pop();
                else
                    break;
            }
            answer.push(num);
        }
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n - k; i++)
            sb.append(answer.get(i));
        bw.write(sb.toString());
        bw.flush();
    }
}