#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include "pokedex.h"
#include "gotoxy.h" 

using namespace std;

Pokedex::Pokedex(){
	
}

Pokedex::~Pokedex(){
	
}

int Pokedex::login(int x, int y){
	int passwordLoop, verificationLoop,userType;
	string user,temp;
	char getchCatch, pass[5];
	bool userFound,passCorrect;
	gotoxy(x,y);	cout<<"================================";
	gotoxy(x,y+1);	cout<<"|";	gotoxy(x+31,y+1);	cout<<"|";
	gotoxy(x,y+2);	cout<<"|";	gotoxy(x+31,y+2);	cout<<"|";
	gotoxy(x,y+3);	cout<<"|";	gotoxy(x+31,y+3);	cout<<"|";
	gotoxy(x,y+4);	cout<<"|";	gotoxy(x+31,y+4);	cout<<"|";
	gotoxy(x,y+5);	cout<<"|";	gotoxy(x+31,y+5);	cout<<"|";
	gotoxy(x,y+6);	cout<<"================================";
	
	gotoxy(x+4,y+2);	cout<<"Username: ";
	gotoxy(x+4,y+3);	cout<<"Password: ";
	gotoxy(x+14,y+2);	getline(cin, user);
	gotoxy(x+14,y+3);
	
	for(passwordLoop=0; passwordLoop<5; passwordLoop++){
		do{
			getchCatch = getch();
		}
		while(getchCatch<48 || getchCatch>57);
		pass[passwordLoop] = getchCatch;
		cout<<"*";
	}
	
	
	gotoxy(0, y+7);
	
	ifstream vault;
	vault.open("registry.txt");
	getline(vault,temp);
	for(int i=0, j=0; i<temp.length();i++){
		if(temp[i]==user[j] && j<user.length()){
			userFound = true;
			if(j==user.length()-1){
				verificationLoop = i+2;
				break;
			}
			j++;
		}
		else{
			j=0;
			userFound = false;
		}
	}
	
	if (userFound){
		cout<<"Trainer found!"<<endl;
		for(int i=verificationLoop, j=0; j<5 ;i+=1){
			if(pass[j] == temp[i]){
				passCorrect = true;
				if(j==4){
					if(temp[i+2]=='1'){
						userType = 1;
					}
					else if(temp[i+2]=='2'){
						userType = 2;
					}
				}
			}
			else{
				passCorrect = false;
			}
			j++;
		}
		if(passCorrect){
			if(userType == 1){
				cout<<"Welcome Pokemon Master "<<user;
			}
			else if (userType == 2){
				cout<<"Welcome Pokemon Trainer "<<user;	
			}
		}
		else{
			cout<<"Incorrect password!";
		}
	}
	else{
		cout<<"Trainer not found!";
	}
		
	vault.close();
}
