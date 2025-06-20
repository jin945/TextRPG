#include <iostream>
#include <Windows.h>
#include <conio.h>


#define UP 0
#define DOWN 1
#define SUBMIT 2

using namespace std;

int keyControl();
void init();
void title();
int menuDraw();
void gotoxy(int, int);
void infoDraw();
void gameStart();

int main()
{
	init();
	while (1) {
		title();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// ���� ����
			gameStart();
		}
		else if (menuCode == 1) {
			infoDraw();
		}
		else if (menuCode == 2) {
			return 0;
		}
		system("cls");
	}
	return 0;
}

void gameStart() {
	string name;
	system("cls");
	while (1) {
		cout << "    ������ �̸��� �Է����ּ��� : " ;
		cin >> name;
		cout << "ȯ���մϴ� " << name << "��!";
		
		// �ؿ� �ڵ� �ۼ�
	}
	
}
void title() {
	printf("\n");
	printf("\n");
	printf("=======================================================================================================================\n");
	printf("=        ===============================        ===============================      ========  ====  =====  ==        =\n");
	printf("====  ==================================  ====================================   ==   ======   ====   ===   ==  =======\n");
	printf("====  ==================================  ====================================  ====  =====    ====  =   =  ==  =======\n");
	printf("====  ======   ====   ===  =  = ========  =========   ===  =  ==  =   ========  ==========  =  ====  == ==  ==  =======\n");
	printf("====  =====  =  ==  =  ==        =======      ====     ==  =  ==    =  =======  =========  ==  ====  =====  ==      ===\n");
	printf("====  =====     =====  ==  =  =  =======  ========  =  ==  =  ==  ============  ===   ==  ===  ====  =====  ==  =======\n");
	printf("====  =====  ======    ==  =  =  =======  ========  =  ==  =  ==  ============  ====  ==         ==  =====  ==  =======\n");
	printf("====  =====  =  ==  =  ==  =  =  =======  ========  =  ==  =  ==  ============   ==   =======  ====  =====  ==  =======\n");
	printf("====  ======   ====    ==  =  =  =======  =========   ====    ==  =============      ========  ====  =====  ==        =\n");
	printf("=======================================================================================================================\n");
	printf("\n");
	printf("\n");
}

void init () {
	system("mode con cols=200 lines 50 | title Team Four G4ME");
}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("               Team : 4��       \n\n");
	printf("         �迬��  ���¿�  ������ \n");
	printf("            ������     �̼���   \n");
	printf("\n\n");
	printf("       ���Ϲ��ķ�� TextRPG ���� \n");
	printf("�����̽� �ٸ� ������ ����ȭ������ �̵��մϴ�.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}
void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int keyControl(){
	char temp = _getch();
	
	if(temp == 'w' || temp =='W'){
		return UP;
	} else if (temp == 's' || temp == 'S') {
		return DOWN;
	} else if (temp == 32) {
		return SUBMIT;
	}
}


int menuDraw(){
	int x = 50;
	int y = 15;
	gotoxy(x-2, y);
	printf("> GAME START");
	gotoxy(x, y+1);
	printf("GAME INFO");
	gotoxy(x, y+2);
	printf("  QUIT");
	
	while (1) {
		int n = keyControl();
		switch(n){
			case UP: {
				if (y>15) { // y�� 15~17������ �̵� 
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				} 
				break;
			}
			case DOWN: {
				if(y<17){
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2,++y);
					printf(">");
				}
				break;
			}
			
			case SUBMIT: {
				return y-15;
			}
		}
	}
	
}
