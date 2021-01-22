//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *TimerBall;
        TTimer *TimerLeftUp;
        TTimer *TimerLeftDown;
        TTimer *TimerRightUp;
        TTimer *TimerRightDown;
        TLabel *scoreboard;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TImage *paddleRight;
        TImage *paddleLeft;
        TButton *Button3;
        TLabel *Label2;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall TimerLeftUpTimer(TObject *Sender);
        void __fastcall TimerLeftDownTimer(TObject *Sender);
        void __fastcall TimerRightUpTimer(TObject *Sender);
        void __fastcall TimerRightDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
