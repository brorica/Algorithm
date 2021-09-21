import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    private static int n;
    private static long[] primes;
    private static long m, ans = 0;

    public static void main(String[] args) throws Exception {
        input();
        // prime 인덱스, 소수 곱, -1 ^ 소수 개수
        recur(0, 1, -1);
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        primes = new long[n];
        for(int i=0;i<n;i++)
            primes[i] = Long.parseLong(st.nextToken());
    }

    private static void recur(int index, long primeMul, int plus) {
        if(index == primes.length) {
            ans += plus * (m / primeMul);
            return;
        }

        if(primeMul * primes[index] > m) {
            ans += plus * (m / primeMul);
            return;
        }
        recur(index + 1, primeMul * primes[index], -plus);
        recur(index + 1, primeMul, plus);
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(m + ans));
        bw.flush();
    }
}