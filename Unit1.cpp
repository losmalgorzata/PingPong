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
     if (b->Top + b->Height >= tlo->Top + tlo->Height) y=-y;

     if (b->Left-5 <= tlo->Left) x = -x;
     if (b->Left+ b-> Width+5 >= tlo->Width) x = -x;

     //skucha
     //if (b->Top >= p->Top + p->Height + 15)
     //{
     //   Timer_pilka->Enabled = false;
     //   b->Visible = false;
        //Button1->Caption = "Pora�ka! Jeszcze raz?";
        //Button1->Visible = true;
     //} else if ((b->Left > p->Left - b->Width/2) &&
      //          (b->Left < p->Left + p->Width) &&
        //        (b->Top + b->Height > p->Top))
     //{
       // if (y > 0) y = -y;
     //}
}
//---------------------------------------------------------------------------





void __fastcall TForm1::pr_w_dolTimer(TObject *Sender)
{
        if (pr->Top + pr->Height < tlo->Top + tlo->Height - 20) pr->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pr_w_goreTimer(TObject *Sender)
{
        if (pr->Top > 10) pr->Top -= 10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
        if (Key == VK_UP) pr_w_gore->Enabled = true;
        if (Key == VK_DOWN) pr_w_dol->Enabled = true;
        if (Key == 'A') pl_w_gore->Enabled = true;
        if (Key == 'Z') pl_w_dol->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
     TShiftState Shift)
{
       if (Key == VK_UP) pr_w_gore->Enabled = false;
       if (Key == VK_DOWN) pr_w_dol->Enabled = false;
       if (Key == 'A') pl_w_gore->Enabled = false;
       if (Key == 'Z') pl_w_dol->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pl_w_goreTimer(TObject *Sender)
{
       if (pl->Top > 10) pl->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pl_w_dolTimer(TObject *Sender)
{
       if (pl->Top + pl->Height < tlo->Top + tlo->Height - 20) pl->Top += 10;
}
//---------------------------------------------------------------------------

