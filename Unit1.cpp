//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = -8;
int y = -8;



int do_wygranej = 12;

//bool kolizja(TImage * pilka, TImage * cegla)
//{
 //       if ((pilka->Left >= cegla->Left - pilka->Width) &&
   //         (pilka->Left <= cegla->Left + cegla->Width) &&
     //       (pilka->Top >= cegla->Top - pilka->Height) &&
       //     (pilka->Top <= cegla->Top + cegla->Height))
         //   {
           //     return true;
            //} else {
              //  return false;
            //}
//}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//TO DOBRZE
void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
     b->Left += x;
     b->Top += y;

     //odbij od gornej sciany
     if (b->Top-5 <= tlo->Top) y = -y;
     //odbij od dolnej sciany
     if (b->Height+5 >= tlo->Height) y=-y;

     //skucha
     if (b->Top >= p->Top + p->Height + 15)
     {
        Timer_pilka->Enabled = false;
        b->Visible = false;
        //Button1->Caption = "Pora�ka! Jeszcze raz?";
        //Button1->Visible = true;
     } else if ((b->Left > p->Left - b->Width/2) &&
                (b->Left < p->Left + p->Width) &&
                (b->Top + b->Height > p->Top))
     {
        if (y > 0) y = -y;
     }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::lewoTimer(TObject *Sender)
{
        if (p->Left > 10) p->Left -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::prawoTimer(TObject *Sender)
{
        if (p->Left  + p->Width < tlo->Width - 10) p->Left += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
        if (Key == VK_LEFT) lewo->Enabled = true;
        if (Key == VK_RIGHT) prawo->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
       if (Key == VK_LEFT) lewo->Enabled = false;
       if (Key == VK_RIGHT) prawo->Enabled = false;
}
//---------------------------------------------------------------------------

