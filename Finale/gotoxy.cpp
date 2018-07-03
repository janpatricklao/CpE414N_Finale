#include "gotoxy.h"
#include <windows.h>

void gotoxy(int x, int y){
  static HANDLE h = NULL;  
  CONSOLE_CURSOR_INFO CursoInfo;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
  CursoInfo.dwSize = 1;         /* The size of caret */
  CursoInfo.bVisible = false;   /* Caret is visible? */
  SetConsoleCursorInfo(h, &CursoInfo);
}
