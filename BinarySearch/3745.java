import java.io.*;
import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static StringBuilder sb = new StringBuilder();
    static List<Integer> lis;
    static int[] report;
    static int n;

    public static void main(String[] args) throws Exception {
        while (sc.hasNext()) {
            n = sc.nextInt();
            input();
            solve();
            System.out.println(lis.size());
        }
    }

    private static void input() throws IOException {
        report = new int[n];
        lis = new ArrayList<>();
        for (int i = 0; i < n; i++)
            report[i] = sc.nextInt();
        lis.add(report[0]);
    }

    private static void solve() {
        for (int i = 1; i < n; i++) {
            int top = lis.get(lis.size() - 1);
            if (top < report[i])
                lis.add(report[i]);
            else
                binary(report[i]);
        }
    }

    private static void binary(int num) {
        int left = 0, mid, right = lis.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (num > lis.get(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        lis.set(left, num);
    }
}