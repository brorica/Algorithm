import java.io.*;
import java.util.*;

public class Main {

    static int l, ml, mk, c;
    static boolean gameOver = false;
    static Queue<Integer> zombies = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        input();
        solve();
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        l = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ml = Integer.parseInt(st.nextToken());
        mk = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(br.readLine());

        for (int i = 0; i < l; i++)
            zombies.add(Integer.parseInt(br.readLine()));
    }

    private static void solve() {
        int zombieHP;
        int maxDamage = mk * ml, totalDamage;
        int bombCount = ml - 1; // 처음 주는 데미지는 mk 만큼
        boolean[] bomb = new boolean[l + 1];
        // 슬라이딩 윈도우 + 큐
        for (int left = -ml + 1, right = 0;
             !zombies.isEmpty();
             left++, right++) {
            zombieHP = zombies.poll();
            totalDamage = maxDamage - bombCount * mk;

            // 크레모어 폭발
            if(zombieHP > totalDamage) {
                if(c == 0) {
                    gameOver = true;
                    break;
                }
                c--;
                bombCount++;
                bomb[right] = true;
            }

            if (left < 0 || bomb[left])
                bombCount--;
        }
    }


    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        if (gameOver)
            bw.write("NO");
        else
            bw.write("YES");
        bw.flush();
    }
}