import java.io.*;

public class Main {

    private static long k, ans = 1;
    private static int n = 200000;
    private static long[] primes;
    public static void main(String[] args) throws Exception {
        input();
        mobius();
        binary();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Long.parseLong(br.readLine());
        primes = new long[n + 1];
    }

    private static void mobius() {
        primes[1] = -1;
        for(int i=1; i <= n; i++) {
            for(int j= 2 * i; j<=n; j+=i) {
                primes[j] -= primes[i];
            }
        }
    }

    private static void binary() {
        long left = 1, mid, right = k * 4;
        while(left < right) {
            mid = (left >> 1) + (right >> 1);
            if(calcK(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        ans = left;
    }

    private static long calcK(long mid) {
        long count = 0;
        for(long i=2; i*i<=mid; i++) {
            count += primes[(int)i] * mid / (i * i);
        }
        return count;
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}