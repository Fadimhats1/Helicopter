#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

void Hide(){
	printf("\e[?25l");
	COORD Curp;
	Curp.X = 0;
	Curp.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Curp);
}

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

int speed = 5, propSpeed = speed * 2;

//void hide(){
//	for(int i = 0; i <6; i++){
//		cout << "\n";
//	}
//}

//struct node{
//	char temp;
//	node *next;
//};
//
//struct node *createNodes(char value){
//    node *temp = (node*)malloc(sizeof(node));
//	temp->temp = value;
//    temp->next = NULL;
//    return temp;
//}
//
//void push(struct node **headref, char value){
//	node *temp = createNodes(value);
//	if(!(*headref)){
//		*headref = temp;
//	}else{
//		temp->next = *headref;
//		*headref = temp;
//	}
//}
//
//char pop(struct node **headref){
//	char temp;
//    if(*headref){
//        node *curr = *headref;
//        while(curr){
//            if(curr->next->next == NULL){
//            	temp = curr->next->temp;
//                curr->next = NULL;
//                free(curr->next);
//            }
//            curr = curr->next; // 17->15->16->14->NULL
//        }
//    }
//    return temp;
//}
void play(){
	
	vector<char> v[10], temp;
	char heli[100][205] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','L','O','L','O','L','O','L','O','L','O','L','|','|','L','O','L','O','L','O','L','O','L','O','L'},
	{'|','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_','_','_','_','_','_','|','|','_','_','_','_','_','_'},
	{'|',' ','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','_',' ',' ','\\'},
	{'|','[',']','\\',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','/',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','[','_',']',' ',' ','\\'},
	{'|',' ',' ',' ','\\','-','-','-','-','-','-','-','-','-','-',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\'},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|',' ',' ',' ',' ','|','|'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\\','_','_','_','_','_','_','|','|','_','_','_','_','|','|','_','_','_','_','_','_','/'}
	}, props[5][55] = {{'L','O','L','O','L','O','L','O','L','O','L','|','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','|','L','O','L','O','L','O','L','O','L','O','L'}};

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 181; j++){
			if(!heli[i][j]){
				heli[i][j] = ' ';
			}
		}
	}

	for(int i = 0; i < 9; i++){
		int len = strlen(heli[i]);
		for(int j = len - 1; j >= 0; j--){
			v[i].insert(v[i].begin(), heli[i][j]);
		}
	}

	int prop = 12;
	system("CLS");
	while (true)
	{
		/* code */
		Hide();
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < speed; j++){
				char temp = v[i].back();
				v[i].pop_back();
				v[i].insert(v[i].begin(), temp);
			}
		}
		prop += speed % 181;
		
		for(int a = 0; a < propSpeed; a++){
			puts("");
			puts("");
			puts("");
			puts("");
			puts("");
			puts("");
			for(int i = 0; i < 9; i++){
				if(!i){
					for(int j = 0; j < 24; j++){
						v[i][(prop + j) % 181] = props[a % speed][j];
					}
				}
				for(int j = 0; j < v[i].size(); j++){
					cout << v[i][j];
				}
				cout << "\n";
			}
			usleep(10000);
			if(a != propSpeed - 1){
				Hide();
			}
		}
	}
}
void home(){
	system("CLS");
	while(true){
		Hide();
		gotoxy(35, 4);
		cout << " /$$   /$$ /$$$$$$$$ /$$       /$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$  /$$ /$$" ;
		gotoxy(35, 5);
		cout << "| $$  | $$| $$_____/| $$      |_  $$_/ /$$__  $$ /$$__  $$| $$__  $$|__  $$__/| $$_____/| $$__  $$| $$| $$";
		gotoxy(35, 6);
		cout << "| $$  | $$| $$      | $$        | $$  | $$  \\__/| $$  \\ $$| $$  \\ $$   | $$   | $$      | $$  \\ $$| $$| $$";
		gotoxy(35, 7);
		cout << "| $$$$$$$$| $$$$$   | $$        | $$  | $$      | $$  | $$| $$$$$$$/   | $$   | $$$$$   | $$$$$$$/| $$| $$";
		gotoxy(35, 8);
		cout << "| $$__  $$| $$__/   | $$        | $$  | $$      | $$  | $$| $$____/    | $$   | $$__/   | $$__  $$|__/|__/";
		gotoxy(35, 9);
		cout << "| $$  | $$| $$      | $$        | $$  | $$    $$| $$  | $$| $$         | $$   | $$      | $$  \\ $$        ";
		gotoxy(35, 10);
		cout << "| $$  | $$| $$$$$$$$| $$$$$$$$ /$$$$$$|  $$$$$$/|  $$$$$$/| $$         | $$   | $$$$$$$$| $$  | $$ /$$ /$$";
		gotoxy(35, 11);
		cout << "|__/  |__/|________/|________/|______/ \\______/  \\______/ |__/         |__/   |________/|__/  |__/|__/|__/";

		gotoxy(80, 15);
		cout << "How fast (2 - 5)? _\b";
		if(kbhit()){
			char temp = getch();
			if(temp >= '2' && temp <= '9'){
				speed = temp - '0';
				cout << speed;
				gotoxy(78, 17);
				cout << "press enter to continue!";
				getchar();
				play();
			}
		}
	}
	                                                      
}

int main(){
//	struct node *head[10] = {NULL};
	home();
}
