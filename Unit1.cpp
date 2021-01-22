//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = 10;
int y = 10;
int player1Points = 0;
int player2Points = 0;

void Option()
{
 if(Form2->RadioGroup1->ItemIndex==0)
     {
        Form1->ball->Left+= 0.8*x;
        Form1->ball->Top+= 0.8*y;
     }
     else if(Form2->RadioGroup1->ItemIndex==1)
     {
        x = x;
        y = y;
     }
     else if(Form2->RadioGroup1->ItemIndex==2)
     {
        Form1->ball->Left+= 1.2*x;
        Form1->ball->Top+= 1.2*y;
     }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
    Option();
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
      Label1->Caption="Point for the right player >";
      Label1->Visible=true;
      sndPlaySound("snd/brawa.wav",SND_ASYNC);

      scoreboard->Caption="Result : " + IntToStr(player1Points)+ ":" + IntToStr(player2Points);
      scoreboard->Visible=true;
      Button1->Visible=true;
      Button2->Visible=true;

      if(player2Points ==15)
      {
      Label1->Visible=false;
      scoreboard->Visible=false;
      Button1->Visible=false;
      Button2->Visible=false;
      Label2->Visible=true;
   Label2->Caption="Player on the right site win!!";
   Button2->Visible=true;
   }
   }
   if(ball->Left+ball->Width >= paddleRight->Left+20)
   {
      TimerBall->Enabled=false;
      ball->Visible=false;
      player1Points++;
      Label1->Caption="< Point for the left player";
      Label1->Visible=true;
      sndPlaySound("snd/brawa.wav",SND_ASYNC);

      scoreboard->Caption="Result : " + IntToStr(player1Points)+ ":" + IntToStr(player2Points);
      scoreboard->Visible=true;
      Button1->Visible=true;
      Button2->Visible=true;
   if(player1Points ==15)
   {
      Label1->Visible=false;
      scoreboard->Visible=false;
      Button1->Visible=false;
      Button2->Visible=false;
      Label2->Visible=true;
      Label2->Caption="Player on the left site win!!" ;
      Button2->Visible=true;


   }
   }
  else if ((ball->Left < paddleLeft->Left + paddleLeft->Width &&
           ball->Top + ball->Height/2 <= paddleLeft->Top + paddleLeft->Height &&
           ball->Top + ball->Height/2 >= paddleLeft->Top))
       {
                x = -1.1 * x;
                if(x < 0)
                {

                        if ((ball->Left <= paddleLeft->Left + paddleLeft->Width &&
                        ball->Top + ball->Height/2 < paddleLeft->Top + paddleLeft->Height/3 &&
                        ball->Top + ball->Height/2 >= paddleLeft->Top))
                        {
                                x = -  0.9 * x;
                                y = 0.9 * y;
                        }


                        else if ((ball->Left <= paddleLeft->Left + paddleLeft->Width &&
                        ball->Top + ball->Height/2 <= paddleLeft->Top + 2 * paddleLeft->Height/3 &&
                        ball->Top + ball->Height/2 >= paddleLeft->Top + paddleLeft->Height/3))
                        {
                                x = - x;
                        }

                        else if ((ball->Left <= paddleLeft->Left + paddleLeft->Width &&
                        ball->Top + ball->Height/2 <= paddleLeft->Top +  paddleLeft->Height &&
                        ball->Top + ball->Height/2 > paddleLeft->Top + 2/3 * paddleLeft->Height))
                        {
                                x = -1.2 * x;
                                y = 1.2 * y;
                        }
                }
       }

   else if ((ball->Left + ball->Width >= paddleRight->Left  &&
           ball->Top + ball->Height/2 <= paddleRight->Top + paddleRight->Height &&
           ball->Top + ball->Height/2 >= paddleRight->Top))
            {
                x =  -1.1 * x;

                if(x > 0)
                {
                        if ((ball->Left + ball->Width >= paddleRight->Left &&
                        ball->Top + ball->Height/2 < paddleRight->Top + paddleRight->Height/3 &&
                        ball->Top + ball->Height/2 >= paddleRight->Top))
                        {
                                x = -  0.9 * x;
                                y = 0.9 * y;
                        }

                        else if ((ball->Left <= paddleRight->Left + paddleRight->Width &&
                        ball->Top + ball->Height/2 <= paddleRight->Top + 2 * paddleRight->Height/3 &&
                        ball->Top + ball->Height/2 >= paddleRight->Top + paddleRight->Height/3))
                        {
                                x = - x;
                        }
                        else if ((ball->Left <= paddleRight->Left + paddleRight->Width &&
                        ball->Top + ball->Height/2 <= paddleRight->Top +  paddleRight->Height &&
                        ball->Top + ball->Height/2 > paddleRight->Top + 2/3 * paddleRight->Height))
                        {
                                x = -1.2 * x;
                                y = 1.2 * y;
                        }
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
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   if(player1Points!=0 || player2Points!=0)
  {
    if(Application->MessageBox(
    "Are you sure? You want to start again?","Confirm",MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        TimerBall->Enabled=true;
        paddleLeft->Enabled=true;
        paddleRight->Enabled=true;
        Button1->Visible=false;
        Button2->Visible=false;
        Label1->Visible=false;
        scoreboard->Visible=false;
        player1Points=0;
        player2Points=0;
        ball->Top=224;
        ball->Left=(paddleLeft->Left+paddleRight->Left)/2;
        ball->Visible=true;
        x = -10;
        y = -10;
        paddleLeft->Top = background->Height/2 - paddleLeft->Height/2;
        paddleRight->Top = background->Height/2 - paddleRight->Height/2;
        paddleLeft->Left = background->Left+30;
        paddleRight->Left = background->Width-50;

    }
  }
  else
  {
    TimerBall->Enabled=true;
    paddleLeft->Enabled=true;
    paddleRight->Enabled=true;
    Button1->Visible=false;
    Button2->Visible=false;
    Label1->Visible=false;
    paddleLeft->Top = background->Height/2 - paddleLeft->Height/2;
    paddleRight->Top = background->Height/2 - paddleRight->Height/2;
    paddleLeft->Left = background->Left+30;
    paddleRight->Left = background->Width-50;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  TimerBall->Enabled=true;
  paddleLeft->Enabled=true;
  paddleRight->Enabled=true;
  Button1->Visible=false;
  Button2->Visible=false;
  Label1->Visible=false;
  scoreboard->Visible=false;
  ball->Top=224;
  ball->Left=(paddleLeft->Left+paddleRight->Left)/2;
  ball->Visible=true;
  x = 10;
  y = 10;
  paddleLeft->Top = background->Height/2 - paddleLeft->Height/2;
  paddleRight->Top = background->Height/2 - paddleRight->Height/2;
  paddleLeft->Left = background->Left+30;
  paddleRight->Left = background->Width-50;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
     if(Application->MessageBox(
    "Do you want close a program?","Confirm",MB_YESNO | MB_ICONQUESTION) == IDNO)
    {
      Action = caNone;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form2->ShowModal();

}
//---------------------------------------------------------------------------

