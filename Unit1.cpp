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
int player1Points;
int player2Points;
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

   if(ball->Left <= paddleLeft->Left-20)
   {
      TimerBall->Enabled=false;
      ball->Visible=false;
      player2Points++;
   }
   if(ball->Left+ball->Width >= paddleRight->Left+20)
   {
      TimerBall->Enabled=false;
      ball->Visible=false;
      player1Points++;
   }
   if(ball->Top+ball->Height/2 > paddleRight->Top &&
   ball->Top < paddleRight->Top+paddleRight->Height && ball->Left+ball->Width > paddleRight->Left)
   {
       if(x > 0)
       {
         x = - x;
         //faster bounce
         if(ball->Top+ball->Height/2 > paddleRight->Top+paddleLeft->Height/2-30 &&
         ball->Top < paddleRight->Top+paddleLeft->Height/2+30)
         { x *= 1.1; y *= 1.1;   }
       }

   }
   else if(ball->Top+ball->Height/2 > paddleLeft->Top && ball->Top < paddleLeft->Top+paddleLeft->Height &&
   ball->Left < paddleLeft->Left+paddleLeft->Width)
   {
       if(x < 0)
       {
         x = - x;
         //faster bounce
         if(ball->Top+ball->Height/2 > paddleLeft->Top+paddleLeft->Height/2-30 &&
         ball->Top < paddleLeft->Top+paddleLeft->Height/2+30) {x *= 1.1; y *= 1.1;}
       }

   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftUpTimer(TObject *Sender)
{
if( paddleLeft->Top > 5)   paddleLeft->Top-=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftDownTimer(TObject *Sender)
{
  if( paddleLeft->Top + paddleLeft->Height < background->Height-5)
        paddleLeft->Top+=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightUpTimer(TObject *Sender)
{
    if( paddleRight->Top > 5)   paddleRight->Top-=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightDownTimer(TObject *Sender)
{
   if( paddleRight->Top + paddleRight->Height < background->Height-5)
        paddleRight->Top+=5;
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
