import java.io.*;
import java.util.*;

public class Main {

    private static int[] nums;
    private static List<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        input();
        solve();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        nums = new int[n];
        for(int i=0; i<n; i++)
            nums[i] = (Integer.parseInt(st.nextToken()));
        answer.add(-1111111111);
    }

    private static void solve() {
        int len = nums.length;
        for(int i=0; i<len; i++) {
            int top = answer.get(answer.size() - 1);
            if(nums[i] > top) {
                answer.add(nums[i]);
            }
            else if(nums[i] < top) {
                binary(nums[i]);
            }
        }
    }

    private static void binary(int num) {
        int left = 1, mid, right = answer.size() - 1;
        while (left < right) {
            mid = (left + right) >> 1;
            if(answer.get(mid) >= num)
                right = mid;
            else
                left = mid + 1;
        }
        answer.set(left, num);
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(answer.size() - 1));
        bw.flush();
    }
}