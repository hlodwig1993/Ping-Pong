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
        TImage *paddleLeft;
        TImage *paddleRight;
        TTimer *TimerLeftUp;
        TTimer *TimerLeftDown;
        TTimer *TimerRightUp;
        TTimer *TimerRightDown;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall TimerLeftUpTimer(TObject *Sender);
        void __fastcall TimerLeftDownTimer(TObject *Sender);
        void __fastcall TimerRightUpTimer(TObject *Sender);
        void __fastcall TimerRightDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
