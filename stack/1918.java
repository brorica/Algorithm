import java.io.*;
import java.util.*;

/**
 * 문자는 바로 출력
 * 부호는 stack에 push
 * 괄호 시작시 재귀 발생, 새로운 stack 변수를 만들어 사용한다.
 * 함수 종료시 남아있는 stack을 모두 pop
 *
 * 부호가 *, /일 시, 스택이 비지 않은 선에서 우선순위가 같은 기호 pop
 * +, -일시 스택이 비지 않은 선에서 모두 pop
 */

public class Main {

    private static int textLength;
    private static String text;
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        input();
        solve(0);
        print();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        text = br.readLine();
        textLength = text.length();
    }

    private static int solve(int index) {
        Stack<Character> operand = new Stack<>();
        for (int i = index; i < textLength; i++, index++) {
            char letter = text.charAt(i);
            if (letter == '(') {
                index = solve(index + 1);
                i = index;
            }

            else if (letter == ')')
                break;
            else if ('A' <= letter && letter <= 'Z')
                sb.append(letter);
            else {
                if(operand.isEmpty())
                    operand.push(letter);
                else {
                    printOperand(operand, letter);
                }
            }
        }
        while(!operand.isEmpty()) {
            sb.append(operand.peek());
            operand.pop();
        }
        return index;
    }

    private static void printOperand(Stack<Character> operand, char letter) {
        if (letter == '*' || letter == '/') {
            while (!operand.isEmpty()) {
                char peek = operand.peek();
                if (peek == '+' || peek == '-')
                    break;
                sb.append(peek);
                operand.pop();
            }
        }
        else {
            while (!operand.isEmpty()) {
                sb.append(operand.peek());
                operand.pop();
            }
        }
        operand.push(letter);
    }

    private static void print() throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(sb.toString());
        bw.flush();
    }
}