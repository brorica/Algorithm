import java.io.*;
import java.util.*;
/*

첫 원소는 그냥 추가시킴
그 다음 원소는 이분 탐색을 통해 몇 번째 인덱스인지 찾음

만약 현재 lis 배열의 크기와 같다면 추가.
이게 아니라면 현 lis 배열에 해당 원소를 넣음.
모든 nums에는 position이 따라붙음
*/

public class Main {

    private static int[] nums;
    private static List<Integer> lis = new ArrayList<>();
    private static List<Integer> ans = new ArrayList<>();
    private static int[] positions;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        getAnswer();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        nums = new int[n];
        positions = new int[n];
        for(int i=0; i<n; i++)
            nums[i] = (Integer.parseInt(st.nextToken()));
        lis.add(nums[0]);
        positions[0] = 1;
    }

    private static void solve() {
        int len = nums.length;
        for (int i = 1; i < len; i++) {
            int newIndex = binary(nums[i]);
            if (newIndex < lis.size()) {
                lis.set(newIndex, nums[i]);
                positions[i] = newIndex + 1;
            }
            else {
                lis.add(nums[i]);
                positions[i] = lis.size();
            }

        }
    }

    private static int binary(int num) {
        int left = 0, mid, right = lis.size() - 1;
        if(num > lis.get(right))
            return lis.size();
        while(left <= right) {
            mid = (left + right) / 2;
            if(lis.get(mid) < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    private static void getAnswer() {
        int max = lis.size();
        for (int i = positions.length - 1; i >= 0; i--) {
            if (max == positions[i]) {
                max--;
                ans.add(nums[i]);
            }
        }
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(ans.size() + "\n");
        for (int i = ans.size() - 1; i >= 0; i--) {
            bw.write(ans.get(i) + " ");
        }
        bw.flush();
    }
}