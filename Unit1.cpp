//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = 10;
int y = 10;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
    ball->Left+= x;// ballHorizontalMovement;
    ball->Top+= y ;// ballVerticalMovement;

   //bounce from the top
   if(ball->Top-5 <= background->Top) y = - y;
   //bounce from the bottom
   if(ball->Top+ball->Height+5 >= background->Height) y = -y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftUpTimer(TObject *Sender)
{
if(paddleLeft->Top >= background->Top+10)
   {
     if(GetKeyState(VK_SPACE) & 0x8000) {}
     else paddleLeft->Top -= 10;
   }        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftDownTimer(TObject *Sender)
{
  if(paddleLeft->Top+paddleLeft->Height <= background->Height-10)
   {
     if(GetKeyState(VK_SPACE) & 0x8000) {}
     else paddleLeft->Top += 10;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightUpTimer(TObject *Sender)
{
    if(paddleRight->Top >= background->Top+10)
   {
        paddleRight->Top -= 10;
   }    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightDownTimer(TObject *Sender)
{
    if(paddleRight->Top+paddleRight->Height <= background->Height-10)
   {
   paddleRight->Top += 10;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_UP) TimerRightUp->Enabled = true;
   if(Key == VK_DOWN) TimerRightDown->Enabled = true;
   if(Key == 65) TimerLeftUp->Enabled = true;
   if(Key == 90) TimerLeftDown->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) TimerRightUp->Enabled = false;
   if(Key == VK_DOWN) TimerRightDown->Enabled = false;
   if(Key == 65) TimerLeftUp->Enabled = false;
   if(Key == 90) TimerLeftDown->Enabled = false;
}
//---------------------------------------------------------------------------
