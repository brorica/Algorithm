import java.io.*;
import java.util.*;

public class Main {

    private static int n, m, l, ans = 0;
    private static int[] stations;

    public static void main(String[] args) throws Exception {
        input();
        binary();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        stations = new int[n + 2];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++)
            stations[i] = Integer.parseInt(st.nextToken());
        stations[n] = 0;
        stations[n+1] =l;
        Arrays.sort(stations);
    }


    private static void binary() {
        int left = 1, mid, right = l - 1;
        while(left <= right) {
            mid = (left + right) / 2;
            if(checkDistance(mid))
                left = mid + 1;
            else {
                right = mid - 1;
            }
        }
        System.out.println(left);
    }

    private static boolean checkDistance(int mid) {
        int count = 0 ;
        for (int i = 1; i < stations.length; i++) {
            // 홀수, 짝수로 떨어지는거 방지
            count += (stations[i] - stations[i - 1] - 1) / mid;
        }
        return count > m;
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.flush();
    }
}