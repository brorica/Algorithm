import java.io.*;
import java.util.*;

/**
 * 충돌 판정
 * 석순 : 라인 <= 석순 높이
 * 종유석 : 라인 > 동굴 높이 - 종유석
 * 
 * 정렬 후, 첫번째 라인부터 시작한다.
 * 단, 동굴 시작 위치는 처음부타 하지 말고 부수게 되는 길이가 어디인지를 구함
 * 길이의 최소값을 찾으면 길이 - 최소값
 */

public class Main {

    private static int n, h, min = 0x7FFFFFFF, count = 0;
    private static int[] up, down;

    public static void main(String[] args) throws Exception {
        input();
        solve();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());
        down = new int[h + 1];
        up = new int[h + 1];
        for(int i=0;i<n;i++) {
            int height = Integer.parseInt(br.readLine());
            if(i % 2 == 0)
                down[height]++;
            else
                up[height]++;
        }
    }

    private static void solve() {
        for(int height = h-1; height >= 0; height--) {
            down[height] += down[height + 1];
            up[height] += up[height + 1];
        }

        for(int line=1; line<=h; line++) {
            int total = down[line] + up[h - line + 1];
            if(total < min) {
                count = 1;
                min = total;
            }
            else if(total == min) {
                count++;
            }
        }
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(min));
        bw.write(" ");
        bw.write(String.valueOf(count));
        bw.flush();
    }
}