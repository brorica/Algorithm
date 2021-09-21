import java.io.*;
import java.util.*;

// 배열 크기 45000 ^ 45000는 1,000,000,000 * 2 하고 비슷
public class Main {

    private static int n = 45000, k, ans = 1; // 1부터 시작
    private static int[] primes;
    public static void main(String[] args) throws Exception {
        input();
        mobius();
        binary();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.parseInt(br.readLine());
        primes = new int[n + 1];
    }

    // -1 ^ (소수 개수)
    private static void mobius() {
        primes[1] = 1;
        for(int i=1; i <= n; i++) {
            for(int j= 2 * i; j<=n; j+=i) {
                primes[j] -= primes[i];
            }
        }
    }

    private static void binary() {
        int left = 1, mid, right = k * 2;
        while(left < right) {
            mid = (left >> 1) + (right >> 1);
            if(calcK(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        ans = left;
    }

    private static int calcK(int mid) {
        int count = 0;
        for(int i=1; i*i<=mid; i++) {
            count += primes[i] * mid / (i * i);
        }
        return count;
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}