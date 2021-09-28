import java.io.*;
import java.util.*;

public class Main {

    static int n, k;
    static long ans = 0;
    static String[] texts;

    public static void main(String[] args) throws Exception {
        input();
        slidingWindow();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        texts = new String[n];
        for (int i = 0; i < n; i++)
            texts[i] = br.readLine();
    }

    private static void slidingWindow() {
        int left = 0, right = 1;
        int[] textLenMark = new int[32];
        Queue<String> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            int len = texts[i].length();
            q.add(texts[i]);
            if(textLenMark[len] > 0)
                ans+=textLenMark[len];
            textLenMark[len]++;
            if(q.size() > k) {
                int tempLen = q.poll().length();
                textLenMark[tempLen]--;
            }
        }
    }


    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}