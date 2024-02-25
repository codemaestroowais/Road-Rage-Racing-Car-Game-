#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
void hideCursor();
void hideCursor();
void printmaize();
void printplayer();
void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerDown();
void menu(char &input);
void printenemy();
void printenemy1();
void printenemy2();
void printenemy3();
void eraseenemy();
void eraseenemy1();
void eraseenemy2();
void moveenemy();
void moveenemy1();
void erasebullet(int x, int y);
void moveenemy2();
void moveenemy3();
void bullettank();
void friing();
void printbullet(int x, int y);
void interface__();
void gamemenu();
void instruction();
void move();
char getCharAtxy(short int x, short int y);
bool collision();
void clear();
void bullettank();
void bulletMove();
void bullettank1();
void bulletMove1();
void bullettank2();
void bulletmove2();
void Score();
void healthplayer();
void gotoxy(int x, int y);
void gamecollision();

int tx = 53;
int ty = 33;
int tx1 = 17;
int ty1 = 20;
int tx2 = 53;
int ty2 = 7;
int px = 15;
int py = 15;
int ex = 20;
int ey = 1;
int enemy[3];
int ex1 = 47;
int ey1 = 1;
int ex2 = 29;
int ey2 = 1;
int ex3 = 38;
int ey3 = 1;
int bx = 54;
int by = 90;
int bulletx = 0;
int bullety = 0;
int score = 0;
int score1 = 0;
int score2=0;
int score3=0;
int score4=0;
int health1=30;
int health =30;
const int limit =100000;
int arrx1[limit];
int arry1[limit];
int arrx2[limit];
int arry2[limit];
int arrx[limit];
int arry[limit];
bool active[limit];
bool active1[limit];
bool active2[limit];
int bulletCount= 0;
int bulletCount1= 0;
int bulletCount2= 0;
int bulletIndex=0;
int bulletIndex1=0;
int bulletIndex2=0;
int firelimit =0;
bool isactive[1000];

using namespace std;

char star[38][94] = {
    {"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++ ___________________ +"},
    {"+++++++++++++++++                                     ++  _________  ++      CAR  GAME      +"},
    {"+++++++++++++++++                                     ++ /  ARMY   \\ ++     -----------     +"},
    {"+++++++++++++++++                                     ==|    TANK   |++       SCORE:        +"},
    {"+++++++++++++++++                                     ++ \\_________/ ++     -----------     +"},
    {"+++++++++++++++++                                     +++++++++++++++++ ___________________ +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++ ___________________ +"},
    {"+++++++++++++++++                                     +++++++++++++++++     -----------     +"},
    {"+++++++++++++++++                                     +++++++++++++++++      HEALTH:        +"},
    {"+++++++++++++++++                                     +++++++++++++++++     -----------     +"},
    {"++  _________  ++                                     +++++++++++++++++ ___________________ +"},
    {"++ /  ARMY   \\ ++                                     +++++++++++++++++                     +"},
    {"++|    TANK   |==                                     +++++++++++++++++                     +"},
    {"++ \\_________/ ++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++ ___________________ +"},
    {"+++++++++++++++++                                     +++++++++++++++++     Control-Key     +"},
    {"+++++++++++++++++                                     +++++++++++++++++ ___________________ +"},
    {"+++++++++++++++++                                     +++++++++++++++++ Right-Right Arrow   +"},
    {"+++++++++++++++++                                     +++++++++++++++++ Key                 +"},
    {"+++++++++++++++++                                     +++++++++++++++++ Up-Up Arrow Key     +"},
    {"+++++++++++++++++                                     +++++++++++++++++ Down-Down Arrow Key +"},
    {"+++++++++++++++++                                     +++++++++++++++++ Left-Left Arrow Key +"},
    {"+++++++++++++++++                  p                  ++  _________  ++ ___________________ +"},
    {"+++++++++++++++++                                     ++ /  ARMY   \\ ++                     +"},
    {"+++++++++++++++++                                     ==|    TANK   |++                     +"},
    {"+++++++++++++++++                                     ++ \\_________/ ++                     +"},
    {"+++++++++++++++++                                     +++++++++++++++++                     +"},
    {"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"}};
char player[5][5] = {{" && "},
                     {"&&&&"},
                     {" && "},
                     {"&&&&"}};

char enemycar[5][5] = {{"####"},
                       {" ## "},
                       {"####"},
                       {" ## "}};

char erase[5][5] = {{"    "},
                    {"    "},
                    {"    "},
                    {"    "}};

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    system("cls");
    interface__();
    system("cls");
    gamemenu();
    // printmenu();
    while (true)
    {
        char input;
        menu(input);
        if (input=='1')
        {    
            system("cls");
            string check;
            int count=0;
            //Sleep(1000);
            hideCursor();
            system("cls");
            printmaize();
            //printmaize();
            printplayer();
            printenemy();
            printenemy1();
            printenemy2();
            printenemy3();
            //Sleep(100);
            while (true)
            {
                bulletMove();
                bulletMove1();
                bulletmove2();
                if (GetAsyncKeyState(VK_LEFT))
                {
                    movePlayerLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    movePlayerRight();
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    movePlayerUp();
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movePlayerDown();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    friing();
                }
                // move();
                // bullettank();
                moveenemy();
                        Score();
                        healthplayer();
                if (count > 5)
                    moveenemy1();
                if (count > 10)
                    moveenemy2();
                if (count > 15)
                    moveenemy3();
                // if(collision)
                //     return 0;
                Sleep(50);
                count++;
                if(score1+score2+score3+score4==50)
                {cout<<"You win";
                    getch();
                    getch();
                    getch();
                    break;
                    //system("cls");
                }
                else if(score1+score2+score3+score4==70)
                {
                    system("cls");
                    cout<<"You Lose."<<endl;
                    getch();
                    return 1;
                } 
                else if(collision==0)
                {
                    system("cls");
                    cout<<"a";
                    getch();
                }  
            }
        }
        else if (input == '2')
        {
            instruction();
            getch();
        }
        else if (input == '3')
        {
            system("cls");getch();
            break;
        }
        else
        {
            cout<<"Invalid Input."<<endl;
        }
    }
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void printmaize()
{
    clear();
    for (int row = 0; row < 38; row++)
    {
        for (int col = 0; col < 94; col++)
        {
            if (star[row][col] == 'p')
            {
                px = row;
                py = col;
                printplayer();
            }
            else
            {
                gotoxy(col, row);
                SetConsoleTextAttribute(h, 6);
                cout << star[row][col];
            }
        }
    }
}
void printplayer()
{
    clear();
    //SetConsoleTextAttribute(h, 15);
    //SetConsoleTextAttribute(h, 2);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            SetConsoleTextAttribute(h, 15);
            SetConsoleTextAttribute(h, 2);
            gotoxy(py + j, px + i);
            cout << player[i][j];
        }
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void clear()
{
    COORD cursorPos;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}
void erasePlayerLeft()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            gotoxy(py + j, px + i);
            cout << "    ";
        }
    }
}
void erasePlayerRight()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            gotoxy(py, px + i);
            cout << "    ";
        }
    }
}
void movePlayerLeft()
{
    if (star[px][py - 1] == ' ')
    {
        erasePlayerRight();
        star[px][py] = ' ';
        py = py - 1;
        star[px][py] = 'p';
        clear();
        printplayer();
    }
}
void menu(char &input)
{
    system("cls");
    gamemenu();
    gotoxy(65, 23);
        SetConsoleTextAttribute(h, 2);
    cout << "1. Start." << endl;
    gotoxy(65, 24);
    cout << "2. Instruction." << endl;
    gotoxy(65, 25);
    cout << "3. Exit." << endl;
    gotoxy(65, 26);
    cout << "Enter you Option...";
    cin >> input;
}
void movePlayerRight()
{
    if (star[px][py + 4] == ' ')
    {
        erasePlayerRight();
        star[px][py] = ' ';
        py = py + 1;
        star[px][py] = 'p';
        clear();
        printplayer();
    }
}
void movePlayerUp()
{
    if (star[px - 1][py] == ' ')
    {
        erasePlayerRight();
        star[px][py] = ' ';
        px = px - 1;
        star[px][py] = 'p';
        clear();
        printplayer();
    }
}
void movePlayerDown()
{
    if (star[px + 5][py] == ' ')
    {
        erasePlayerRight();
        star[px][py] = ' ';
        px = px + 1;
        star[px][py] = 'p';
        clear();
        printplayer();
    }
}
void printenemy()
{
    SetConsoleTextAttribute(h, 15);
    SetConsoleTextAttribute(h, 4);
    gotoxy(ex, ey);
    cout << "####" << endl;
    gotoxy(ex, ey + 1);
    cout << " ## " << endl;
    gotoxy(ex, ey + 2);
    cout << "####" << endl;
    gotoxy(ex, ey + 3);
    cout << " ## " << endl;
}
void printenemy1()
{
    gotoxy(ex1, ey1);
    cout << "####" << endl;
    gotoxy(ex1, ey1 + 1);
    cout << " ## " << endl;
    gotoxy(ex1, ey1 + 2);
    cout << "####" << endl;
    gotoxy(ex1, ey1 + 3);
    cout << " ## " << endl;
}
void printenemy2()
{
    gotoxy(ex2, ey2);
    cout << "####" << endl;
    gotoxy(ex2, ey2 + 1);
    cout << " ## " << endl;
    gotoxy(ex2, ey2 + 2);
    cout << "####" << endl;
    gotoxy(ex2, ey2 + 3);
    cout << " ## " << endl;
}
void printenemy3()
{
    gotoxy(ex3, ey3);
    cout << "####" << endl;
    gotoxy(ex3, ey3 + 1);
    cout << " ## " << endl;
    gotoxy(ex3, ey3 + 2);
    cout << "####" << endl;
    gotoxy(ex3, ey3 + 3);
    cout << " ## " << endl;
}
void eraseenemy()
{
    gotoxy(ex, ey);
    cout << "    " << endl;
    gotoxy(ex, ey + 1);
    cout << "    " << endl;
    gotoxy(ex, ey + 2);
    cout << "    " << endl;
    gotoxy(ex, ey + 3);
    cout << "    " << endl;
}
void eraseenemy1()
{
    gotoxy(ex1, ey1);
    cout << "    " << endl;
    gotoxy(ex1, ey1 + 1);
    cout << "    " << endl;
    gotoxy(ex1, ey1 + 2);
    cout << "    " << endl;
    gotoxy(ex1, ey1 + 3);
    cout << "    " << endl;
}
void eraseenemy2()
{
    gotoxy(ex2, ey2);
    cout << "    " << endl;
    gotoxy(ex2, ey2 + 1);
    cout << "    " << endl;
    gotoxy(ex2, ey2 + 2);
    cout << "    " << endl;
    gotoxy(ex2, ey2 + 3);
    cout << "    " << endl;
}
void eraseenemy3()
{
    gotoxy(ex3, ey3);
    cout << "    " << endl;
    gotoxy(ex3, ey3 + 1);
    cout << "    " << endl;
    gotoxy(ex3, ey3 + 2);
    cout << "    " << endl;
    gotoxy(ex3, ey3 + 3);
    cout << "    " << endl;
}
void moveenemy()
{
    eraseenemy();
    ey = ey + 1;
    printenemy();
    if (ey == 31)
    {
        eraseenemy();
        moveenemy1();
        // Sleep(300);
        score1=score1+1;
        ey = 1;
    if(ex=='&' || ey=='&')
    {
        system("cls");
        cout<<"a";
        getch();
    }
    }
}
void moveenemy1()
{
    eraseenemy1();
    ey1 = ey1 + 1;
    printenemy1();
    if (ey1 == 31)
    {
        eraseenemy1();
        // Sleep(500);
        score2=score2+1;
        ey1 = 1;
    }
}
void moveenemy2()
{
    eraseenemy2();
    ey2 = ey2 + 1;
    printenemy2();
    if (ey2 == 31)
    {
        eraseenemy2();
        // Sleep(1000);
        score3=score3+1;
        ey2 = 1;
    }
}
void moveenemy3()
{
    eraseenemy3();
    ey3 = ey3 + 1;
    printenemy3();
    if (ey3 == 31)
    {
        eraseenemy3();
        // Sleep(1000);
        score4=score4+1;
        ey3 = 1;
    }
}
void healthplayer()
{
    gotoxy(77, 16);
    cout<<"Health: "<<health;
}
void Score()
{
    gotoxy(78, 7);
    cout<<"Score: "<<score1+score2+score3+score4;
}
bool collision()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (player[i - 1][j] == '#')
            {
                return false;
            }
        }
    }
    return true;
}
void friing()
{
    if (getCharAtxy(px - 1, py + 2) != '+')
    {
        arrx[bulletCount] = px - 1;
        arry[bulletCount] = py + 2;
        isactive[bulletCount] = true;
        // gotoxy(px, py - 1);
        printbullet(px - 1, py + 2);
        bulletCount++;
    }
}
void erasebullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printbullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void move()
{
    for (int i = 0; i < bulletCount; i++)
    {
        if (isactive[i] == true)
        {
            if (getCharAtxy(arrx[i] - 1, arry[i]) != ' ')
            {
                erasebullet(arrx[i], arry[i]);
                isactive[i] = false;
            }
            else
            {
                erasebullet(arrx[i], arry[i]);
                arrx[i] = arrx[i] - 1;
                printbullet(arrx[i], arry[i]);
            }
        }
    }
}
void bullettank()
{
  int tbx = tx;
  int tby = ty;
  gotoxy(tbx, tby);
  cout<<"*";
  arrx[bulletIndex] = tbx;
  arry[bulletIndex] = tby;
  active[bulletIndex] = true;
  bulletCount++;
  bulletIndex++;
}
void bulletMove()
{
    for(int i=0; i<bulletCount ;i++)
    {
        if(active[i] == true)
        {
            if(getCharAtxy(arrx[i] - 1, arry[i]) == ' ')
            {
                gotoxy(arrx[i], arry[i]);
                cout<<" ";
                arrx[i] = arrx[i] - 1;
                gotoxy(arrx[i], arry[i]);
                cout<<"*";
            }
            else if(getCharAtxy(arrx[i] - 1, arry[i]) != ' ')
            {
                gotoxy(arrx[i], arry[i]);
                cout<<" ";
            }
            if(getCharAtxy(arrx[i] - 1, arry[i]) == '&')
            {
                health=health1-1;
            }
        }
    }
    if(firelimit > 15)
    {
         bullettank();
         firelimit=0;
    }
    else
    {
        firelimit++;
    }
}

void bullettank1()
{
  int tbx1 = tx1;
  int tby1 = ty1;
  gotoxy(tbx1, tby1);
  cout<<"*";
  arrx1[bulletIndex1] = tbx1;
  arry1[bulletIndex1] = tby1;
  active1[bulletIndex1] = true;
  bulletCount1++;
  bulletIndex1++;
}
void bulletMove1()
{
    for(int i=0; i<bulletCount1 ;i++)
    {
        if(active1[i] == true)
        {
            if(getCharAtxy(arrx1[i] + 1, arry1[i]) == ' ')
            {
                gotoxy(arrx1[i], arry1[i]);
                cout<<" ";
                arrx1[i] = arrx1[i] + 1;
                gotoxy(arrx1[i], arry1[i]);
                cout<<"*";
            }
            else if(getCharAtxy(arrx1[i] + 1, arry1[i]) != ' ')
            {
                gotoxy(arrx1[i], arry1[i]);
                cout<<" ";
            }
            if(getCharAtxy(arrx1[i] + 1, arry1[i]) == '&')
            {
                health=health1-1;
            }
        }
    }
    if(firelimit > 15)
    {
         bullettank1();
         firelimit=0;
    }
    else
    {
        firelimit++;
    }
}

void bullettank2()
{
  int tbx2 = tx2;
  int tby2 = ty2;
  gotoxy(tbx2, tby2);
  cout<<"*";
  arrx2[bulletIndex2] = tbx2;
  arry2[bulletIndex2] = tby2;
  active2[bulletIndex2] = true;
  bulletCount2++;
  bulletIndex2++;
}
void bulletmove2()
{
    for(int i=0; i<bulletCount2 ;i++)
    {
        if(active2[i] == true)
        {
            if(getCharAtxy(arrx2[i] - 1, arry2[i]) == ' ')
            {
                gotoxy(arrx2[i], arry2[i]);
                cout<<" ";
                arrx2[i] = arrx2[i] - 1;
                gotoxy(arrx2[i], arry2[i]);
                cout<<"*";
            }
            else if(getCharAtxy(arrx2[i] - 1, arry2[i]) != ' ')
            {
                gotoxy(arrx2[i], arry2[i]);
                cout<<" ";
            }
            if(getCharAtxy(arrx2[i] - 1, arry2[i]) == '&')
            {
                health=health1-1;
                break;
            }
        }
    }
    if(firelimit > 15)
    {
         bullettank2();
         firelimit=0;
    }
    else
    {
        firelimit++;
    }
}
void gamecollision()
{
    
}