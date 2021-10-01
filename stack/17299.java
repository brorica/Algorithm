import java.io.*;
import java.util.*;

class Main {

    static int n;
    static int[] count;
    static Stack<Integer> left, right;
    static Stack<Integer> ans;

    public static void main(String[] args) throws Exception {
        input();
        for (int i = 0; i < n; i++)
            solve();
        print();
    }

    private static void solve() {
        int leftTop = left.pop();
        rightPop(leftTop);
    }

    private static void rightPop(int leftTop) {
        int rightTop;
        while(!right.isEmpty()) {
            rightTop = right.peek();
            if(count[leftTop] < count[rightTop]) {
                ans.push(rightTop);
                break;
            }
            else
                right.pop();
        }
        if(right.isEmpty())
            ans.push(-1);
        right.push(leftTop);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        count = new int[1000001];

        ans = new Stack<>();
        left = new Stack<>();
        right = new Stack<>();

        int num;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            num = Integer.parseInt(st.nextToken());
            count[num]++;
            left.push(num);
        }
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (!ans.isEmpty()) {
            bw.write(ans.pop() + " ");
        }
        bw.flush();
    }
}
