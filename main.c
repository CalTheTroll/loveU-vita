#include <stdio.h>
#include <psp2/ctrl.h>
#include "debugScreen.h"

#define printf psvDebugScreenPrintf

int main(int argc, char *argv[]) {

SceCtrlData pad;
uint32_t old_buttons, current_buttons, pressed_buttons;
int enter_button;
int sel;

psvDebugScreenInit();
psvDebugScreenSetFgColor(COLOR_WHITE);

sel = 0;
old_buttons = 0, current_buttons = 0, pressed_buttons = 0;


printf("Heres a handy guide!\n"); 
printf("Pressing CROSS will say 'Love you.'\n"); 
printf("Pressing R TRIGGER will say 'Your the best.'\n");
printf("Pressing L TRIGGER will say 'Beleve in yourself.'\n");
printf("Pressing TRIANGLE will say 'You can do it.'\n");
printf("Pressing SQUARE will say 'Someone will love you soon.'\n");
  //v2 additions
printf("Pressing LEFT will say 'You have the most beautiful smile'\n");
printf("Pressing RIGHT will say 'Your kindness shines like the sun'\n");
printf("Pressing UP will say 'Love makes life worth living'\n");
printf("Pressing DOWN will say 'The light of hope is born within oneself'\n");

printf("Pressing CIRCLE will clear the screen (including this guide)\n");
  while (1) {
    sceCtrlPeekBufferPositive(0, &pad, 1);

    old_buttons = current_buttons;
    current_buttons = pad.buttons;
    pressed_buttons = current_buttons & ~old_buttons;

   if (pressed_buttons & SCE_CTRL_CROSS) { printf("Love you.\n"); }
   if (pressed_buttons & SCE_CTRL_LTRIGGER) { printf("Your the best.\n"); }
   if (pressed_buttons & SCE_CTRL_RTRIGGER) { printf("Beleve in yourself.\n"); }
   if (pressed_buttons & SCE_CTRL_TRIANGLE) { printf("You can do it.\n"); }
   if (pressed_buttons & SCE_CTRL_SQUARE) { printf("Someone will love you soon.\n"); }
   //v2 additions
   if (pressed_buttons & SCE_CTRL_LEFT ) { printf("You have the most beautiful smile.\n"); }
   if (pressed_buttons & SCE_CTRL_RIGHT ) { printf("Your kindness shines like the sun.\n"); }
   if (pressed_buttons & SCE_CTRL_UP ) { printf("Love makes life worth living.\n"); }
   if (pressed_buttons & SCE_CTRL_DOWN ) { printf("The light of hope is born within oneself.\n"); }
   
   if (pressed_buttons & SCE_CTRL_CIRCLE) { psvDebugScreenClear(0x00000000); }

   sel = 0;
   sceKernelDelayThread(10 * 1000);
  }

}


