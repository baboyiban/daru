#include <iostream>

using namespace std;

void ins(bool &se, string k[][10], string k2[][10]);

void screen(bool &se, string k[][10], string k2[][10], int bomb[])
{
    string s;

    if (se == false)
    {
        for (int i = 0; i < 10; i++)
        {
            string s2 = to_string(bomb[i]);
            char ch, ch2;
            ch = s2[0];
            ch2 = s2[1];
            string s3(1, ch);
            string s4(1, ch2);
            k2[atoi(s3.c_str())][atoi(s4.c_str())] = "@";
        }
    }

    cout.flags(ios::left);
    for (int i = 0; i < 11; i++)
    {
        cout << " ";
        cout.width(2);
        cout << i;
    }
    cout << " ";
    cout << endl;
    cout << "   -------------------------------" << endl;
    for (int i = 1, x = 0; i < 11; i++, x++)
    {
        cout << " ";
        cout.width(2);
        cout << i;
        for (int j = 0; j < 10; j++)
        {
            cout << "|";
            cout.width(2);
            cout << k2[x][j];
        }
        cout << "|";
        cout << endl;
        cout << "   -------------------------------";
        cout << endl;
    }

    ins(se, k, k2);
}

void input(bool &se, int &n, int &n2, string k[][10], string k2[][10])
{
    int nn, nn2;
    cout << "->";
    cin >> nn;
    cin >> nn2;
    if (nn > 0 && nn < 11 && nn2 > 0 && nn < 11)
    {
        n = --nn;
        n2 = --nn2;

        k2[n][n2] = k[n][n2];
        if (k2[n][n2] == "@")
        {
            se = false;
        }

        int count = 0;

        while (true)
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (k2[i][j] == " ")
                    {
                        if (i < 1 && j < 1 && (k2[i][j + 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (i < 1 && j > 8 && (k2[i][j - 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (i < 1 && j > 0 && j < 9 && (k2[i][j - 1] == "0" || k2[i][j + 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (i > 8 && j < 1 && (k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j + 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (i > 8 && j > 8 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i][j - 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (i > 8 && j > 0 && j < 9 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j - 1] == "0" || k2[i][j + 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (j < 1 && i > 0 && i < 9 && (k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j + 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (j > 8 && i > 0 && i < 9 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i][j - 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                        if (i > 0 && i < 9 && j > 0 && j < 9 && (k2[i - 1][j - 1] == "0" || k2[i - 1][j] == "0" || k2[i - 1][j + 1] == "0" || k2[i][j - 1] == "0" || k2[i][j + 1] == "0" || k2[i + 1][j - 1] == "0" || k2[i + 1][j] == "0" || k2[i + 1][j + 1] == "0"))
                        {
                            k2[i][j] = k[i][j];
                            count++;
                        }
                    }
                }
            }

            if (count == 0)
                break;
            count = 0;
        }
    }
}

void setting(int *bomb, string k[][10], string k2[][10])
{
    srand((unsigned int)time(0));
    int c = 0;
    bomb[c++] = rand() % 100;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            k2[i][j] = " ";
        }
    }

    bool tof = true;
    while (c < 10)
    {
        bomb[c] = rand() % 100;
        tof = false;
        for (int i = c - 1; i >= 0; i--)
        {
            if (bomb[c] == bomb[i])
            {
                tof = true;
            }
        }
        if (tof == false)
        {
            c++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        string s = to_string(bomb[i]);
        char ch = s[0];
        char ch2 = s[1];
        string s2(1, ch);
        string s3(1, ch2);
        k[atoi(s2.c_str())][atoi(s3.c_str())] = "@";
    }

    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (k[i][j] != "@")
            {
                if (i > 0)
                {
                    if (j > 0)
                    {
                        if (k[i - 1][j - 1] == "@")
                            count++;
                    }
                    if (k[i - 1][j] == "@")
                        count++;
                    if (j < 9)
                        if (k[i - 1][j + 1] == "@")
                            count++;
                }
                if (j > 0)
                    if (k[i][j - 1] == "@")
                        count++;
                if (j < 9)
                    if (k[i][j + 1] == "@")
                        count++;
                if (i < 9)
                {
                    if (j > 0)
                        if (k[i + 1][j - 1] == "@")
                            count++;
                    if (k[i + 1][j] == "@")
                        count++;
                    if (j < 9)
                        if (k[i + 1][j + 1] == "@")
                            count++;
                }
                k[i][j] = to_string(count);
                count = 0;
            }
        }
    }
}

void ins(bool &se, string k[][10], string k2[][10])
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (k2[i][j] == " ")
            {
                count++;
            }
        }
    }

    if (se == false)
    {
        cout << "폭탄을 밟았습니다 ... 끝!" << endl;
    }
    else if (count == 10)
    {
        cout << "폭탄을 모두 다 찾으셨습니다 !!!" << endl;
        se = false;
    }
    else
    {
        cout << "숫자를 입력해 주세요 ... " << endl;
    }
}

int main()
{
    int bomb[10];
    string k[10][10], k2[10][10];
    int n, n2 = 0;
    bool se = true;

    setting(bomb, k, k2);

    screen(se, k, k2, bomb);
    while (true)
    {
        screen(se, k, k2, bomb);
        if (se == false)
            break;
        input(se, n, n2, k, k2);
    }
}