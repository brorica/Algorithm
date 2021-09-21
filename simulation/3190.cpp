#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef struct
{
    int y, x;
}Dir;

typedef struct
{
    int y, x, d;
}SNAKE;

typedef struct
{
    int t;
    char c;
}COMMAND;

#define MAX 128
int N, K, L;
// ������ ����� index 1�� ���������ְ� ������ 1�� ����
Dir dir[4] = { {0, 1}, {1, 0}, {0, -1},{-1,0} };
deque< SNAKE> snake;
vector<COMMAND> command;
int map[MAX][MAX] = { 0, };

int play();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int x, y, t;
    char c;
    snake.push_back({ 1, 1, 0 });
    map[1][1] = 1;
    // ��� ����
    for (int i = 0; i < K; i++)
    {
        cin >> y >> x;
        map[y][x] = 2;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> t >> c;
        command.push_back({ t, c });
    }
    cout << play();
    return 0;
}

int play()
{
    int timer = 0, commandIndex = 0;
    int headX, headY, headD;
    int tailX, tailY;
    while (++timer)
    {
        // �Ӹ� �ø���
        headD = snake.back().d;
        headX = snake.back().x + dir[headD].x;
        headY = snake.back().y + dir[headD].y;
        // ���� ����
        if (!(1 <= headX && headX <= N && 1 <= headY && headY <= N))
            break;
        // ���뿡 ����
        if (map[headY][headX] == 1)
            break;
        // ������ �ƴѵ� ����� ����
        else if (map[headY][headX] != 2)
        {
            // ���� ���
            tailY = snake.front().y;
            tailX = snake.front().x;
            map[tailY][tailX] = 0;
            snake.pop_front();
        }
        // Ÿ�̸� üũ
        if (commandIndex < command.size() && timer == command[commandIndex].t)
        {
            // ������
            if (command[commandIndex].c == 'D')
            {
                headD = (headD + 1) % 4;
            }
            // ����
            else
            {
                headD--;
                if (headD == -1)
                    headD = 3;
            }
            commandIndex++;
        }
        // �Ӹ� ��ġ ����
        map[headY][headX] = 1;
        snake.push_back({ headY, headX, headD });
    }
    return timer;
}