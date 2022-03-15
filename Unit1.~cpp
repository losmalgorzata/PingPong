//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x = -8;
int y = -8;

int odbicia_lewego = 0;
int odbicia_prawego = 0;

bool dzwiek = true;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
     b->Left += x;
     b->Top += y;

     //odbij od gornej sciany
     if (b->Top-5 <= tlo->Top) y = -y;
     //odbij od dolnej sciany
     if (b->Top + b->Height >= tlo->Top + tlo->Height) y=-y;

     //skucha
     if ((b->Left <= pl->Left) || (b->Left + b->Width > pr->Left + pr->Width))
     {
        Timer_pilka->Enabled = false;
        b->Visible = false; Button1->Caption = "Wynik: " + IntToStr(odbicia_lewego) + ":" + IntToStr(odbicia_prawego);
        Button1->Visible = true;

        if (dzwiek == true) sndPlaySound("snd/koniec.wav", SND_ASYNC);

     } else if ((b->Top > pl->Top - b->Height/2) &&
                (b->Top < pl->Top + pl->Height) &&
                (b->Left < pl->Left + pl->Width))
        {
               if (x < 0) x = -x;
               if (dzwiek == true) sndPlaySound("snd/d3.wav", SND_ASYNC);
               //liczenie punktow gracza lewego
               odbicia_lewego++;
        } else if ((b->Top > pr->Top - b->Height/2) &&
                   (b->Top < pr->Top + pr->Height) &&
                   (b->Left + b->Width > pr->Left))
        {
               if (x > 0) x = -x;
               if (dzwiek == true) sndPlaySound("snd/d4.wav", SND_ASYNC);
               //liczenie punktow gracza prawego
               odbicia_prawego++;
        }
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Button2->Visible = false;
        Label1->Visible = false;
        Timer_pilka->Enabled = true;
        if (dzwiek == true) sndPlaySound("snd/start.wav", SND_ASYNC);
        Button3->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
        dzwiek = false;
}
//---------------------------------------------------------------------------

