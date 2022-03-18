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
int odbicia_wszystkie = 0;
int rundy_lewego = 0;
int rundy_prawego = 0;

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
        b->Visible = false;
        odbicia_wszystkie = odbicia_lewego + odbicia_prawego;

        //liczenie rund
        if (odbicia_lewego > odbicia_prawego)
        {
                rundy_lewego++;
                Label2->Caption = "<- punkt dla gracza lewego";
        } else if (odbicia_lewego < odbicia_prawego) {
                rundy_prawego++;
                Label2->Caption = "punkt dla gracza prawego ->";
        } else {
                Label2->Caption = "Remis";
        }

        Label2->Visible = true;
        Label3->Caption = "Wynik: " + IntToStr(rundy_lewego) + ":" + IntToStr(rundy_prawego);
        Label3->Visible = true;
        Label4->Caption = "Liczba odbic: " + IntToStr(odbicia_wszystkie);
        Label4->Visible = true;
        Button1->Visible = true;
        Button2->Visible = true;
        Button3->Visible = true;

        if (dzwiek == true) sndPlaySound("snd/koniec.wav", SND_ASYNC);

     } else if ((b->Top > pl->Top - b->Height/2) &&
                (b->Top < pl->Top + pl->Height) &&
                (b->Left < pl->Left + pl->Width))
        {
               if (x < 0) x = -x;
               if (dzwiek == true) sndPlaySound("snd/d2.wav", SND_ASYNC);
               //liczenie punktow gracza lewego
               odbicia_lewego++;
        } else if ((b->Top > pr->Top - b->Height/2) &&
                   (b->Top < pr->Top + pr->Height) &&
                   (b->Left + b->Width > pr->Left))
        {
               if (x > 0) x = -x;
               if (dzwiek == true) sndPlaySound("snd/d2.wav", SND_ASYNC);
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
        int odbicia_lewego = 0;
        int odbicia_prawego = 0;
        int rundy_lewego = 0;
        int rundy_prawego = 0;
        bool dzwiek = true;

        Button1->Visible = false;
        Button2->Visible = false;
        Button3->Visible = false;
        Label1->Visible = false;
        Label2->Visible = false;
        Label3->Visible = false;
        Label4->Visible = false;

        b->Visible = true;
        b->Left = 411;
        b->Top = 214;
        pl->Left = 40;
        pl->Top = 180;
        pr->Left = 794;
        pr->Top = 180;
        Timer_pilka->Enabled = true;
        if (dzwiek == true) sndPlaySound("snd/d1.wav", SND_ASYNC);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
        dzwiek = false;
        Button3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int odbicia_lewego = 0;
        int odbicia_prawego = 0;
        bool dzwiek = true;

        Button1->Visible = false;
        Button2->Visible = false;
        Button3->Visible = false;
        Label1->Visible = false;
        Label2->Visible = false;
        Label3->Visible = false;
        Label4->Visible = false;

        b->Visible = true;
        b->Left = 411;
        b->Top = 214;
        pl->Left = 40;
        pl->Top = 180;
        pr->Left = 794;
        pr->Top = 180;
        Timer_pilka->Enabled = true;
        if (dzwiek == true) sndPlaySound("snd/d1.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------

